#ifndef GRAIN_PLABINDER_HPP
#define GRAIN_PLABINDER_HPP

#include <vector>
#include <stack>
#include <map>

#include "grain/grain.h"
#include "grain/primitive/GRAPRMType.hpp"

//-- Templated to prevent conflicts when multiple inheritance is done.
template <typename T> class GRAOBJBinder
{
public:
  enum class Error : GRAInt
  {
    OverwriteItem,

    NameConvertedBySystem,
    NameOverride,
    NameConflict,

    TagOverride,
    TagConflict,

    //RegisterUndefinedKeyToMap,
    RegisterExistingKeyToMap,

    //RegisterUndefinedTagToMap,
    RegisterExistingTagToMap,

    NotExistInItems,
    NotExistInMap,

    OutOfRange,

    kNumberOfItems,
    None = kGRAIntMin
  };

  class Item
  {
    /// \~english
    /// All BinderItems have IDs. IDs are unique within the Binder.
    /// \~japanese
    /// 全てのBinderItemはIDを持つ。IDはBinder内で一意である。
    size_t _id = kGRASizeUndefined;

    /// \~english
    /// All BinderItems have names. Names are unique within the Binder.
    /// \~japanese
    /// 全てのBinderItemが名前を持つとは限らない。名前はBinder内で一意である。
    std::string _name = kGRAStrUndefined;

    /// \~english
    /// Not all BinderItems have tags. Tags are unique within the Binder.
    /// \~japanese
    /// 全てのBinderItemがタグを持つとは限らない。タグはBinder内で一意である。
    GRASize _tag = kGRASizeUndefined;

    GRAOBJBinder *_binder = nullptr;

  protected:
    Item(const std::string &aName, GRAOBJBinder<T> *aBinder) :
    _name(aName), _binder(aBinder)
    {}

    Item(PLAId aTag, GRAOBJBinder<T> *aBinder) :
    _tag(aTag), _binder(aBinder)
    {}

    explicit Item(GRAOBJBinder<T> *aBinder) : _binder(aBinder) {}

  public:
    Item() = delete;
    virtual ~Item() {};

    GRASize GetId() const { return _id; };
    const GRAString &GetName() const { return _name; };
    GRASize GetTag() const { return _tag; };
    virtual const char *GetBinderItemTypeName() const = 0;

    void SetId(size_t aId) { _id = aId; };
    void SetName(const std::string &aName, Error *aError) {
      std::string newName = aName;
      if (_name != kGRAStrUndefined) {
        if (_name != aName) {
          *aError = Error::NameOverride;
          if (_binder->IsExistItem(aName)) {
            *aError = Error::NameConvertedBySystem;
            newName = aName + "-" + std::to_string(_id);
            if (_binder->IsExistItem(newName))
            {
              *aError = Error::NameConflict;
              return;
            }
          }
        }
        _binder->UpdateMap(_name, newName);
      }
      else
      {
        _binder->InsertMap(_id, newName);
      }
      _name = newName;
    }

    void SetTag(GRASize aTag, Error *aError) {
      GRASize newTag = aTag;
      auto undefined = kGRASizeUndefined;
      if (_tag != undefined) {
        if (_tag != aTag) {
          *aError = Error::TagOverride;
          if (_binder->IsExistItemWithTag(aTag)) {
            *aError = Error::TagConflict;
            return;
          }
        }
        _binder->UpdateTagMap(_tag, newTag);
      }
      else
      {
        _binder->InsertTagMap(_id, newTag);
      }
      _tag = newTag;
    }
  };
private:
  std::vector<Item *> _items = std::vector<Item *>();
  std::map<std::string, GRASize> _itemMap = std::map<std::string, GRASize>();
  std::map<GRASize, GRASize> _tagMap = std::map<GRASize, GRASize>();
  std::stack<size_t> _emptyIndices = std::stack<size_t>();

public:
  GRAOBJBinder() {};
  virtual ~GRAOBJBinder() {};

  void Init(Error *aError = nullptr) {};

  void Bind(Item *aItem, Error *aError)
  {
    if (_emptyIndices.size()) {
      size_t id = _emptyIndices.top();
      aItem->SetId(id);
      if (_items.at(id) != nullptr)
      {
        *aError = Error::OverwriteItem;
      }
      _items[id] = aItem;
      _emptyIndices.pop();
    } else {
      aItem->SetId(_items.size());
      _items.push_back(aItem);
    }
    this->RegisterToMap(aItem, aError);
    this->RegisterToTagMap(aItem, aError);
  };

  void Unbind(Item *aItem, Error *aError)
  {
    _items[aItem->GetId()] = nullptr;
    /*
    if (_itemMap.find(aItem->GetName()) != _itemMap.end()) {
      *aError = Error::NotExistInMap;
      return;
    }
     */
    _emptyIndices.push(aItem->GetId());
    _itemMap.erase(aItem->GetName());
  };

  GRABool IsExistItem(const std::string &aName)
  {
    Error error;
    const Item *item = this->GetItemWithName(aName, &error);
    return item;
  }

  GRABool IsExistItemWithTag(PLAId aTag)
  {
    Error error(Error::None);
    const Item *item = this->GetItemWithTag(aTag, &error);
    return item;
  }

  const std::vector<Item *> &GetItems() const { return _items; }

  [[deprecated("This method is deprecated. Use GetItemWithName() instead.")]]
  const Item *GetItem(const std::string &aName, Error *aError) const
  {
    return GetItemWithName(aName, aError);
  };

  const Item *GetItemWithName(const std::string &aName, Error *aError) const
  {
    return RefItemWithName(aName, aError);
  };

  [[deprecated("This method is deprecated. Use GetItemWithId() instead.")]]
  const Item *GetItem(GRASize aId, Error *aError)
  {
    return GetItemWithId(aId, aError);
  };

  const Item *GetItemWithId(GRASize aId, Error *aError)
  {
    return RefItemWithId(aId, aError);
  };

  const Item *GetItemWithTag(GRASize aTag, Error *aError)
  {
    return RefItemWithTag(aTag, aError);
  }

  [[deprecated("This method is deprecated. Use RefItemWithId() instead.")]]
  Item *RefItem(GRASize aId, Error *aError)
  {
    return this->RefItemWithId(aId, aError);
  }

  Item *RefItemWithId(GRASize aId, Error *aError)
  {
    if (aId < _items.size()) {
      return _items.at(aId);
    } else {
      *aError = Error::OutOfRange;
      return nullptr;
    };
  }

  [[deprecated("This method is deprecated. Use RefItemWithName() instead.")]]
  Item *RefItem(const std::string &aName, Error *aError) const
  {
    return this->RefItemWithName(aName, aError);
  }

  Item *RefItemWithName(const std::string &aName, Error *aError) const
  {
    try {
      return _items.at(_itemMap.at(aName));
    } catch(std::out_of_range) {
      *aError = Error::NotExistInMap;
      return nullptr;
    };
  }

  Item *RefItemWithTag(GRASize aTag, Error *aError)
  {
    try {
      auto id = _tagMap.at(aTag);
      return this->RefItemWithId(id, aError);
    } catch(std::out_of_range) {
      *aError = Error::NotExistInMap;
      return nullptr;
    }
  }

  void RegisterToMap(Item *aItem, Error *aError)
  {
    /*
    if (aItem->GetName() == kGRAStrUndefined) {
      // *aError = Error::RegisterUndefinedKeyToMap;
      return;
    }
     */
    if (_itemMap.find(aItem->GetName()) != _itemMap.end()) {
      *aError = Error::RegisterExistingKeyToMap;
      return;
    }
    if (aItem->GetName() == kGRAStrUndefined) {
      aItem->SetName(grautil::format("%s-%d",
                                     aItem->GetBinderItemTypeName(),
                                     aItem->GetId()), aError);
    }
    else if (_itemMap.contains(aItem->GetName())) {
      aItem->SetName(grautil::format("%s-%d",
                                     aItem->GetName().c_str(),
                                     aItem->GetId()),
                                     aError);
    }
    auto name = aItem->GetName();
    _itemMap[name] = aItem->GetId();
  }

  void RegisterToTagMap(Item *aItem, Error *aError)
  {
    if (aItem->GetTag() == kGRAIdUndefined) {
      //*aError = Error::RegisterUndefinedTagToMap;
      return;
    }
    if (_tagMap.find(aItem->GetTag()) != _tagMap.end()) {
      *aError = Error::RegisterExistingTagToMap;
      return;
    }
    auto tag = aItem->GetTag();
    _tagMap[tag] = aItem->GetId();
  }

  void InsertMap(PLAId aId, const std::string &aKey) { _itemMap[aKey] = aId; }

  void UpdateMap(const std::string &aFrom, const std::string &aTo)
  {
    _itemMap[aTo] = _itemMap.at(aFrom);
    _itemMap.erase(aFrom);
  }

  void InsertTagMap(PLAId aId, GRASize aTag) { _tagMap[aTag] = aId; }

  void UpdateTagMap(GRASize aFrom, GRASize aTo)
  {
    _tagMap[aTo] = _tagMap.at(aFrom);
    _tagMap.erase(aFrom);
  }
};

#endif //GRAIN_PLABINDER_HPP
