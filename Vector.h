#pragma once
#include<iostream>
#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "complex.h"

template<typename T>
class Vector {
private:
    Sequence<T>* ptrSequence; 
    int variants;
public:
    Vector();
    Vector(int var);
    Vector(T* items, int count);
    Vector(T* items, int count, int var);
    Vector(const Vector <T> & vectorCopy);
    T GetFirst();
    T GetLast();
    T Get(int index);
    int GetLength();
    void Set(T item, int index);
    void Append(T item);
    void Print();
    double Norma(); 
    T ScalarProduct(Vector);
    Vector MultiplicationNumber(T);
    Vector Summ(Vector);
	void operator +=(Vector);
	void operator -=(Vector);
    bool operator==(Vector<T> & vec2);
    ~Vector();
};

int Variants() {
    int x;
    std::cout << "Выберите организацию данных\n1.DynamicArray.\n2.LinkedList.\n";
    std::cin >> x;
    return x;
}

template<class T> T Vector<T>::ScalarProduct(Vector<T> vect) {
    return (*this * vect);
}

template<class T> Vector<T>::Vector() {
    int var = Variants();
    switch(var) {
        case 1:
            ptrSequence = new ArraySequence<T>;
            break;
        case 2:
            ptrSequence = new ListSequence<T>;
            break;
    }
    this->variants = var;
}

template<class T> Vector<T> Vector<T>::MultiplicationNumber(T value) {
    Vector resVector(*this);
    int size = ptrSequence->GetLength();
    for (int i = 0; i < size; i++) {
        resVector.ptrSequence->Set(value * ptrSequence->Get(i), i);
    }
    return resVector;
}

template<class T> Vector<T>::Vector(int var) {
    switch(var) {
        case 1:
            ptrSequence = new ArraySequence<T>;
            break;
        case 2:
            ptrSequence = new ListSequence<T>;
            break;
    }
    this->variants = var;
}

template<class T> Vector<T>::Vector(T* items, int count) {
    int var = Variants();
    switch(var) {
        case 1:
            ptrSequence = new ArraySequence<T>(items, count);
            break;
        case 2:
            ptrSequence = new ListSequence<T>(items, count);
            break;
    }
    this->variants = var;
}

template<class T> Vector<T>::Vector(T* items, int count, int var) {
    switch(var) {
        case 1:
            ptrSequence = new ArraySequence<T>(items, count);
            break;
        case 2:
            ptrSequence = new ListSequence<T>(items, count);
            break;
    }
    this->variants = var;
}

template<class T> Vector<T>::Vector(const Vector<T> &vectorCopy) {
    this->variants = vectorCopy.variants;
    switch(vectorCopy.variants) {
        case 1:
            ptrSequence = new ArraySequence<T>(*((ArraySequence<T>*) (vectorCopy.ptrSequence)));
            break;
        case 2:
            ptrSequence = new ListSequence<T>(*((ListSequence<T>*) (vectorCopy.ptrSequence)));
            break;
    }
}

template<class T> void Vector<T>::Print() {
    ptrSequence->Print();
}

template<class T> void Vector<T>::Set(T item, int index) {
        this->ptrSequence->Set(item, index);
}

template<class T> void Vector<T>::Append(T item) {
        this->ptrSequence->Append(item);
}

template<class T> T Vector<T>::GetFirst() {
        return this->ptrSequence->GetFirst();
}

template<class T> T Vector<T>::GetLast() {
        return this->ptrSequence->GetLast();
}

template<class T> T Vector<T>::Get(int index) {
        return this->ptrSequence->Get(index);
}

template<class T> int Vector<T>::GetLength() {
        return this->ptrSequence->GetLength();
}

template<class T> double Vector<T>::Norma() {
    int size = ptrSequence->GetLength();
    double res = 0; 
    for (int i = 0; i < size; i++) {
        T item = ptrSequence->Get(i);
        Complex itemCompl = item;
        res += itemCompl.GetAbs(); 
    }
    return res;
}

template<class T> Vector<T> Vector<T>::Summ(Vector<T> vector2) {
    Vector resVector(*this);
    int size = this->GetLength();
    if (size != vector2.GetLength() || size == 0) {
        throw ExceptionError(2);
    }
    for (int i = 0; i < size; i++) {
        resVector.Set(this->Get(i) + vector2.Get(i), i);
    }
    return resVector;
}

template<class T> void Vector<T>::operator+=(Vector<T> vector2) {
    *this = *this + vector2;
}

template<class T> void Vector<T>::operator-=(Vector<T> vector2) {
    *this = *this - vector2;
}

template<class T> Vector<T>::~Vector() {
    delete ptrSequence;
}


template<class T>
Vector<T> operator+(Vector<T> vector1, Vector<T> vector2) {
    return vector1.Summ(vector2);
}

template<class T>
Vector<T> operator-(Vector<T> vector1, Vector<T> vector2) {
    return vector1.Summ(vector2.MultiplicationNumber(-1));
}

template<typename T>
T operator*(Vector<T> vector1, Vector<T> vector2) {
    int size = vector1.GetLength();
    if (size != vector2.GetLength() || size == 0) {
        throw ExceptionError(2);
    }
    T res = (vector1.GetFirst()) * (vector2.GetFirst());
    for (int i = 1; i < size; i++) {
        res += vector1.Get(i) * vector2.Get(i);
    }
    return res;
}

template<class T>
Vector<T> operator*(Vector<T> vector1, T value) {
    return vector1.MultiplicationNumber(value);
}

template<class T>
Vector<T> operator*(T value, Vector<T> vector1) {
    return vector1.MultiplicationNumber(value);
}

template<class T> bool Vector<T>::operator==(Vector<T> &vec2) {
    switch(this->variants) {
        case 1: {
            if (*((ArraySequence<T>*)(this->ptrSequence)) == *((ArraySequence<T>*)(vec2.ptrSequence))) {
                return true;
             } else {
                return false;
             }
            break;
        }
        case 2: {
            if (*((ListSequence<T>*)(this->ptrSequence)) == *((ListSequence<T>*)(vec2.ptrSequence))) {
                return true;
             } else {
                return false;
             }
            break;
        }
    }
    
    
}