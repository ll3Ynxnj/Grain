// Copyright (c) 2023. CLAYWORK Inc. All rights reserved.

//
// Created by Kentaro Kawai on 2023/08/31.
//

#ifndef ANHR_GRAPRMBIDIRECTIONALARRAY_HPP
#define ANHR_GRAPRMBIDIRECTIONALARRAY_HPP


#include <iostream>
#include <vector>

template <typename T> class GRAPRMBidirectionalArray
{
private:
  std::vector<T> positiveData;
  std::vector<T> negativeData;

public:
  // インデックスで要素を取得
  T& operator[](int index) {
    if (index >= 0) {
      if (index >= positiveData.size()) {
        positiveData.resize(index + 1);
      }
      return positiveData[index];
    } else {
      int absIndex = -index - 1;
      if (absIndex >= negativeData.size()) {
        negativeData.resize(absIndex + 1);
      }
      return negativeData[absIndex];
    }
  }

  // 両方のデータを表示（デバッグ用）
  void print() {
    for (int i = negativeData.size() - 1; i >= 0; --i) {
      std::cout << -i-1 << ": " << negativeData[i] << std::endl;
    }
    for (size_t i = 0; i < positiveData.size(); ++i) {
      std::cout << i << ": " << positiveData[i] << std::endl;
    }
  }
};


#endif //ANHR_GRAPRMBIDIRECTIONALARRAY_HPP
