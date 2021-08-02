#ifndef GRAIN_PLABINDER_HPP
#define GRAIN_PLABINDER_HPP

#include <vector>
#include <stack>
#include <map>
#include "Grain.h"

//-- Templated to prevent conflicts when multiple inheritance is done.
template <typename T> class GRABinder
{
public:
  enum class Error : GRAInt
  {
    OverwriteItem,

    //RegisterUndefinedKeyToMap,
    RegisterExistingKeyToMap,

    NotExistInItems,
    NotExistInMap,

    kNumberOfItems,
    None = kGRAIntMin
  };

  class Item
  {
    size_t _id = kGRASizeUndefined;
    std::string _name = kGRAStrUndefined;
    GRABinder *_binder = nullptr;

  protected:
    Item(const std::string &aName, GRABinder<T> *aBinder) :
    _name(aName), _binder(aBinder) {}
    explicit Item(GRABinder<T> *aBinder) : _binder(aBinder) {}

  public:
    Item() {};
    virtual ~Item() {};

    size_t GetId() const { return _id; };
    const std::string &GetName() const { return _name; };

    void SetId(size_t aId) { _id = aId; };
    void SetName(const std::string &aName, Error *aError) {
      if (_name != kPLAStrUndefined) { _binder->UpdateMap(_name, aName); }
      _name = aName;
    }
  };
private:
  std::vector<Item *> _items = std::vector<Item *>();
  std::map<std::string, GRAInt> _itemMap = std::map<std::string, GRAInt>();
  std::stack<size_t> _emptyIndices = std::stack<size_t>();

public:
  GRABinder() {};
  virtual ~GRABinder() {};

  void Init(Error *aError) {};

  void Bind(Item *aItem, Error *aError)
  {
    if (_emptyIndices.size()) {
      size_t id = _emptyIndices.top();
      aItem->SetId(id);
      if (_items[id] != nullptr)
      //{ PLA_ERROR_ISSUE(PLAErrorType::Assert, "Overwrite pointer not nullptr."); }
      { *aError = Error::OverwriteItem; }
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
    _itemMap[aItem->GetName()];
  };

  const std::vector<Item *> &GetItems() const { return _items; }

  const Item *GetItem(const std::string &aName, Error *aError) const
  {
    return RefItem(aName, aError);
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

  void RegisterToMap(Item *aItem, Error *aError)
  {
    /*
    if (aItem->GetName() == kGRAStrUndefined) {
      //*aError = Error::RegisterUndefinedKeyToMap;
      return;
    }
     */
    if (_itemMap.find(aItem->GetName()) != _itemMap.end()) {
      *aError = Error::RegisterExistingKeyToMap;
      return;
    }
    if (aItem->GetName() == kGRAStrUndefined) {
      aItem->SetName(grautil::format("PLAObject-%d", aItem->GetId()), aError);
    }
    _itemMap[aItem->GetName()] = aItem->GetId();
  }

  void UpdateMap(const std::string &aFrom, const std::string&aTo)
  {
    _itemMap[aTo] = _itemMap[aFrom];
    _itemMap.erase(aFrom);
  }
};

#endif //GRAIN_PLABINDER_HPP
