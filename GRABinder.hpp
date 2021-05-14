#ifndef ANHR_GRABINDER_HPP
#define ANHR_GRABINDER_HPP

#include <vector>
#include <stack>

//-- Templated to prevent conflicts when multiple inheritance is done.
template <typename T> class GRABinder
{
public:
  enum class Error : GRAInt
  {
    Overwrite,

    kNumberOfItems,
    None = kGRAIntMin
  };

  class Item
  {
    size_t _id = kGRASizeUndefined;
    std::string _name = kGRACharUndefined;

  protected:
    Item() {};
    explicit Item(const std::string &aName): _name(aName) {}

  public:
    virtual ~Item() {};

    size_t GetId() const { return _id; };
    std::string GetName() const { return _name; };

    void SetId(size_t aId) { _id = aId; };
    void SetName(const std::string &aName) { _name = aName; };
  };

private:
  std::vector<Item *> _items = std::vector<Item *>();
  std::stack<size_t> _emptyIndices = std::stack<size_t>();

protected:
  GRABinder() {};

public:
  virtual ~GRABinder() {};

  void Init(Error *aError) {};
  void Bind(Item *aItem, Error *aError) {
    if (_emptyIndices.size())
    {
      size_t id = _emptyIndices.top();
      aItem->SetId(id);
      if (_items[id] != nullptr)
      //{ PLA_ERROR_ISSUE(PLAErrorType::Assert, "Overwrite pointer not nullptr."); }
      { *aError = Error::Overwrite; }
      _items[id] = aItem;
      _emptyIndices.pop();
    }
    else
    {
      aItem->SetId(_items.size());
      _items.push_back(aItem);
    }
  };
  void Unbind(Item *aItem, Error *aError) {
    size_t id = aItem->GetId();
    _items[id] = nullptr;
  };
  const std::vector<Item *> &GetItems() const { return _items; }
};

#endif //ANHR_GRABINDER_HPP
