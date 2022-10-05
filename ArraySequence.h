#pragma once
#include "DynamicArray.h"
#include "Sequence.h"

template<typename T>
class ArraySequence : public Sequence<T>
{
protected:
	DynamicArray<T>* arr;
public:
    ArraySequence() {
        arr = new DynamicArray<T>;
    }
    ArraySequence(T* items, int count) {
        arr = new DynamicArray<T>(items, count);
    }
    ArraySequence(const ArraySequence<T> & dynamicArray) {
        arr = new DynamicArray<T>(*(dynamicArray.arr));
    }
    T GetFirst() override {
        return this->arr->GetFirst();
    }
    T GetLast() override {
        return this->arr->GetLast();
    }
    T Get(int index) override {
        return this->arr->Get(index);
    }
    int GetLength() override {
        return this->arr->GetSize();
    }
    void Append(T item) override {
        this->arr->Append(item);
    }
    void Prepend(T item) override {
        this->arr->Prepend(item);
    }
    void InsertAt(T item, int index) override {
        this->arr->InsertAt(item, index);
    }
    void Set(T item, int index) override {
        this->arr->Set(index, item);
    }
    void Print() override {
        this->arr->Print();
    }
    ArraySequence<T>* GetSubSequence(int startIndex , int endIndex) override {
        ArraySequence<T>* newArraySequence = new ArraySequence<T>;
        delete newArraySequence->arr;
        newArraySequence->arr = this->arr->GetSubArray(startIndex, endIndex);
        return newArraySequence;
    }
    ArraySequence<T>* CopySequence() override {
        ArraySequence<T>* CopySequence = new ArraySequence<T>(*this);
        return CopySequence;
    }
    ArraySequence<T>* Concat(Sequence<T>* list) override {
        ArraySequence<T>* newArraySequence = new ArraySequence<T>;
        delete newArraySequence->arr;
        newArraySequence->arr = this->arr->Concat(((ArraySequence<T>*) list)->arr);
        return newArraySequence;
    }
    bool operator==(ArraySequence<T> & list2);
	~ArraySequence() override {
        delete arr;
    }
};

template<class T> bool ArraySequence<T>::operator==(ArraySequence<T> &arr2) {
    if (*(this->arr) == *(arr2.arr)) {
        return true;
    } else {
        return false;
    }
}