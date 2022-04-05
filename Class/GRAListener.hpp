//
// Created by Kentaro Kawai on 2021/02/04.
//

#ifndef GRAIN_PLALISTENER_HPP
#define GRAIN_PLALISTENER_HPP

#include "Grain/Class/GRAFunctor.hpp"

template <typename Context, typename Key> class GRAListener
{
  GRAFunctor<Context, Key> _functor = GRAFunctor<Context, Key>();

public:
  void RunListener(Key aKey, Context *aContext)
  { _functor.RunFunction(aKey, aContext); }

  void SetListener(Key aKey,
                   const std::function<void(Context *)> &aFunc)
  { _functor.SetFunction(aKey, aFunc); }
};

#endif //GRAIN_PLALISTENER_HPP
