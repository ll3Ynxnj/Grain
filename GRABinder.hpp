#ifndef ANHR_GRABINDER_HPP
#define ANHR_GRABINDER_HPP

#include <vector>
#include <stack>

class GRABinder final
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
    friend GRABinder;

    size_t _id = kGRASizeUndefined;
    std::string _name = kGRACharUndefined;

  public:
    Item() {};
    virtual ~Item() {};

    size_t GetId() const { return _id; }
    const std::string &GetName() const { return _name; };

    void SetName(const std::string &aName) { _name = aName; };

    void Print() const { GRA_PRINT("%04x : %s\n", _id, _name.c_str()); }

  private:
    void SetId(size_t aId) { _id = aId; };
  };

private:
  std::vector<Item *> _items = std::vector<Item *>();
  std::stack<size_t> _emptyIndices = std::stack<size_t>();

public:
  GRABinder() {};
  ~GRABinder() {};

  void Init(Error *aError) {};
  void Bind(Item *aItem, Error *aError)
  {
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
  }

  void Unbind(Item *aItem, Error *aError)
  {
    size_t id = aItem->GetId();
    _items[id] = nullptr;
  }

  void PrintItems() const
  {
    for (const Item *item : _items) { item->Print(); }
  }
};

/*
PLAObject::Manager PLAObject::Manager::_instance = PLAObject::Manager();

PLAObject::Manager::Manager()
{

}

PLAObject::Manager::~Manager()
{

}

void PLAObject::Manager::Init()
{

}

void PLAObject::Manager::Bind(PLAObject *aObject)

void PLAObject::Manager::Unbind(PLAObject *aObject)
{
}

void PLAObject::Manager::PrintObjects() const
{
  for (const PLAObject *object : _objects) { object->PrintObject(); }
}
*/

#endif //ANHR_GRABINDER_HPP
