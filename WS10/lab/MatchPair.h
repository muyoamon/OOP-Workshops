// Name: Thanatorn Wongthanaporn
// Email: twongthanaporn@myseneca.ca 
// id: 161197223
// Date: 3/4/2024

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#ifndef SENECA_MATCHPAIR_H
#define SENECA_MATCHPAIR_H
namespace seneca {
  template<typename T, typename U>
  struct Pair {
    T first;
    U second;
  };

  template<typename T, typename U>
  void addDynamicPairElement(Pair<T, U>*& pArray,const T& first, const U& second, int& size) {
   Pair<T, U>* temp = new Pair<T, U>[size + 1];
   for (int k = 0; pArray && k < size; k++) {
      temp[k] = pArray[k];
   }
   temp[size].first = first;
   temp[size].second = second;
   delete[] pArray;
   pArray = temp;
   size++;
  }

  template<typename T, typename U>
  Pair<T,U>* matches(T* arr1, U* arr2, int arr1Size, int arr2Size, int& retSize) {
    Pair<T,U>* pt = nullptr;
    retSize = 0;
    for (int i=0; i<arr1Size; i++) {
      for (int j=0;j<arr2Size;j++) {
        if (arr1[i] == arr2[j]) {
          addDynamicPairElement(pt , arr1[i], arr2[j], retSize);
        }
      }
    }
  return pt;
  }

  template<typename T>
    void releaseMem(T* arr) {
      if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
      }
    }
}

#endif // !SENECA_MATCHPAIR_H

