#ifndef GRAIN_PLABINDER_HPP
#define GRAIN_PLABINDER_HPP

#include <vector>
#include <stack>
#include <map>

#include "Grain/Grain.h"
#include "Grain/Primitive/GRAPRMType.hpp"

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

    //RegisterUndefinedKeyToMap,
    RegisterExistingKeyToMap,

    NotExistInItems,
    NotExistInMap,

    OutOfRange,

    kNumberOfItems,
    None = kGRAIntMin
  };

  class Item
  {
    size_t _id = kGRASizeUndefined;
    std::string _name = kGRAStrUndefined;
    GRAOBJBinder *_binder = nullptr;

  protected:
    Item(const std::string &aName, GRAOBJBinder<T> *aBinder) :
    _name(aName), _binder(aBinder) {}
    explicit Item(GRAOBJBinder<T> *aBinder) : _binder(aBinder) {}

  public:
    Item() {};
    virtual ~Item() {};

    GRASize GetId() const { return _id; };
    const GRAString &GetName() const { return _name; };
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
      if (newName == "StageContext") {
        GRA_TRACE("");
      }
      _name = newName;
    }
  };
private:
  std::vector<Item *> _items = std::vector<Item *>();
  std::map<std::string, GRASize> _itemMap = std::map<std::string, GRASize>();
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
      if (_items[id] != nullptr)
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
    const Item *item = this->GetItem(aName, &error);
    return item;
  }

  const std::vector<Item *> &GetItems() const { return _items; }

  const Item *GetItem(const std::string &aName, Error *aError) const
  {
    return RefItem(aName, aError);
  };

  const Item *GetItem(GRASize aId, Error *aError)
  {
    return RefItem(aId, aError);
  };

  Item *RefItem(const std::string &aName, Error *aError) const
  {
    try {
      return _items[_itemMap.at(aName)];
    } catch(std::out_of_range) {
      *aError = Error::NotExistInMap;
      return nullptr;
    };
  }

  Item *RefItem(GRASize aId, Error *aError)
  {
    if (aId < _items.size()) {
      return _items[aId];
    } else {
      *aError = Error::OutOfRange;
      return nullptr;
    };
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

  void UpdateMap(const std::string &aFrom, const std::string&aTo)
  {
    _itemMap[aTo] = _itemMap[aFrom];
    _itemMap.erase(aFrom);
  }
};

#endif //GRAIN_PLABINDER_HPP
