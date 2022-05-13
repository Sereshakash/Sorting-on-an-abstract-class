#pragma once

template<typename T>
class Sequence
{
public:
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual int GetLength() = 0;
    virtual void Set(T item , int index) = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item , int index) = 0;
    virtual void Print() = 0;
    virtual Sequence<T>* GetSubSequence(int startIndex , int endIndex) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
    virtual ~Sequence() = 0;
};

template <class T> Sequence<T>::~Sequence() {}