#ifndef GRAIN_PLAFUNCTOR_HPP
#define GRAIN_PLAFUNCTOR_HPP

#include <map>
#include <string>
#include <functional>

template <typename Context, typename Key> class GRAOBJFunctor
{
  std::map<Key, std::function<void(Context)>> _functions =
    std::map<Key, std::function<void(Context)>>();

public:
  GRAOBJFunctor() {};
  ~GRAOBJFunctor() {};

  void RunFunction(const Key &aKey, Context aContext) const
  {
    if (!_functions.contains(aKey)) { return; }
    _functions.at(aKey)(aContext);
  }

  void SetFunction(const Key &aKey,
                   const std::function<void(Context)> &aFunc)
  { _functions[aKey] = aFunc; }
};

#endif //GRAIN_PLAFUNCTOR_HPP
