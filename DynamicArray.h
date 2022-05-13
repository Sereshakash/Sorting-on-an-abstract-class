#pragma once
#include<iostream>
#include "Excepsion.h"

template <class T> 
class DynamicArray {
    private:
        T* array;
        int size = 0;
    public:
        DynamicArray(T* items , int count);
        DynamicArray(int size);
        DynamicArray();
        DynamicArray(const DynamicArray<T> & dynamicArray);
        int GetSize();
        T Get(int index);
        T GetFirst();
        T GetLast();
        void Set(int index, T value);
        void Resize(int newSize);
        void Print();
        void Append(T value);
        void Prepend(T value);
        void InsertAt(T item , int index);
        DynamicArray<T>* Concat(DynamicArray<T>* array);
        DynamicArray<T>* GetSubArray(int startIndex , int endIndex);
        bool operator==(const DynamicArray<T> & array);
        ~DynamicArray();
};

template<class T> DynamicArray<T>::DynamicArray() {
    this->size = 0;
}

template<class T> DynamicArray<T>::DynamicArray(int size) {
    this->array = new T[size];
    this->size = size;
}

template<class T> DynamicArray<T>::DynamicArray(T* items , int count) {
    this->array = new T[count];
    this->size = count;
    for (int i = 0; i < count; i++)
        this->array[i] = items[i];
}

template<class T> DynamicArray<T>::DynamicArray(const DynamicArray<T> & dynamicArray) {
    this->size = dynamicArray.size;
    this->array = new T[this->size];
    for (int i = 0; i < size; i++)
        this->array[i] = dynamicArray.array[i];
}

template<class T> int DynamicArray<T>::GetSize() {
    if(!size)
        return 0;
    else
        return size;
}

template<class T> T DynamicArray<T>::Get(int index) {
    if(size <= index || index < 0)
        throw ExceptionError(1);
    return array[index];
}

template<class T> T DynamicArray<T>::GetFirst() {
    if(!size)
        throw ExceptionError(1);
    return array[0];
}

template<class T> T DynamicArray<T>::GetLast() {
    if(!size)
        throw ExceptionError(1);
    return array[this->GetSize() - 1];
}

template<class T> void DynamicArray<T>::Set(int index, T value) {
    if(size <= index || index < 0)
        throw ExceptionError(1);
    else
        array[index] = value;
}

template<class T> void DynamicArray<T>::Resize(int newSize) {
    if(newSize < 0)
        throw ExceptionError(1);
    int minSize;
    if(newSize < size) 
        minSize = newSize;
    else
        minSize = size;
    T* newArray = new T[newSize];
    for (int i = 0; i < minSize; i++)
        newArray[i] = array[i];
    delete [] array;
    size = newSize;
    array = newArray;
}

template<class T> void DynamicArray<T>::Append(T value) {
    this->Resize(this->size + 1);
    this->Set(this->size - 1, value);
}

template<class T> void DynamicArray<T>::Prepend(T value) {
    this->Resize(this->size + 1);
    for (int i = size - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }
    array[0] = value;
}

template<class T> void DynamicArray<T>::InsertAt(T item , int index) {
    if (index < 0 || index > size)
        throw ExceptionError(1);
    this->Resize(this->size + 1);
    for (int i = size - 1; i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = item;
}

template<class T> DynamicArray<T>::~DynamicArray() {
    delete [] array;
}

template<class T> void DynamicArray<T>::Print() {
    for(int i = 0 ; i < size; i++){
        std::cout << array[i] << ' ';
    }
    std::cout << "\n";
}

template<class T> DynamicArray<T>* DynamicArray<T>::GetSubArray(int startIndex , int endIndex) {
    if(startIndex < 0 || endIndex >= size || startIndex > endIndex) 
        throw ExceptionError(1);
    DynamicArray<T>* resArrayPtr = new DynamicArray<T>(endIndex - startIndex + 1);
    int newSize = endIndex - startIndex + 1;
    for (int i = startIndex; i < endIndex + 1; i++) {
        resArrayPtr->array[i - startIndex] = this->array[i];
    }
    return resArrayPtr;
}

template<class T> DynamicArray<T>* DynamicArray<T>::Concat(DynamicArray<T>* plusArray) {
    int newSize = size + plusArray->size;
    DynamicArray* resArrayPtr = new DynamicArray(*this);
    resArrayPtr->Resize(newSize);
    for (int i = 0; i < plusArray->size; i++)
    {
        resArrayPtr->array[i + size] = plusArray->array[i];
    }
    return resArrayPtr;
}

template<class T> bool DynamicArray<T>::operator==(const DynamicArray<T> &array2) {
    if (this->size != array2.size) {
        return false;
    } else {
        for(int i = 0; i < size; i++) {
            if (!(this->array[i] == array2.array[i])) {
                return false;
            }
        }
        return true;
    }
}