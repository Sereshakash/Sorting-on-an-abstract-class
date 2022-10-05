#pragma once
#include<iostream>
#include "Sequence.h"

template<typename T>
bool comparison(T x,T y) {
    return (x <= y);
}

template<typename T>
class ISorter
{
public:
    virtual Sequence<T>* Sort(Sequence<T>* seq, bool (*cmp)(T, T)) = 0;
    virtual ~ISorter() = 0;
};

template <class T> ISorter<T>::~ISorter() {}

template<typename T>
class QuickSort : public ISorter<T>
{
private:
    void QuickSorting(Sequence<T>* seq, int l, int r, bool (*cmp)(T, T)) {
        if (l < r) {
            T middle = seq->Get((l + r) / 2);
            int i = l;
            int j = r;
            while (i <= j) {
                while (!cmp(middle, seq->Get(i))) {
                    i++;
                }
                while (!cmp(seq->Get(j), middle)) {
                    j--;
                }
                if (i <= j) {
                    T elem = seq->Get(i);
                    seq->Set(seq->Get(j), i);
                    seq->Set(elem, j);
                    i++;
                    j--;
                }
                QuickSorting(seq, l, j, cmp);
                QuickSorting(seq, i, r, cmp);
            }
        }
    }
public:
    Sequence<T>* Sort(Sequence<T>* seq, bool (*cmp)(T, T)) override {
        Sequence<T>* seqSort = seq->CopySequence();
        this->QuickSorting(seqSort, 0, seqSort->GetLength() - 1, cmp);
        return seqSort;
    }
    ~QuickSort() override {}  
};

template<typename T>
class InsertionSort : public ISorter<T>
{
private:
    void InsEl(int number, Sequence<T>* seq, bool (*cmp)(T, T)) {
        T elem = seq->Get(number);
        int i = number - 1;
        while ((i >= 0) && (!cmp(seq->Get(i), elem))) {
            seq->Set(seq->Get(i), i + 1);
            i--;
        }
        seq->Set(elem, i + 1);        
    }
public:
    Sequence<T>* Sort(Sequence<T>* seq, bool (*cmp)(T, T)) override {
        Sequence<T>* seqSort = seq->CopySequence();
        for (int i = 1; i < seqSort->GetLength(); i++) {
            this->InsEl(i, seqSort, cmp);
        }
        return seqSort;
    }
    ~InsertionSort() override {}  
};

template<typename T>
class ShellSort : public ISorter<T>
{
private:
    void ShellSorting(Sequence<T>* seq, bool (*cmp)(T, T)) {
        int len = seq->GetLength();
        int step = len / 2, j;
        while (step) {
            for (int i = 0; i < len - step; i++) {
                j = i;
                while ((j >= 0) && !(cmp(seq->Get(j), seq->Get(j + step)))) {
                    T elem = seq->Get(j);
                    seq->Set(seq->Get(j + step), j);
                    seq->Set(elem, j + step);
                    j--;
                }
            }
        step /= 2;
        }
    }
public:
    Sequence<T>* Sort(Sequence<T>* seq, bool (*cmp)(T, T)) override {
        Sequence<T>* seqSort = seq->CopySequence();
        this->ShellSorting(seqSort, cmp);
        return seqSort;
    }
    ~ShellSort() override {}  
};

template<typename T>
class SelectionSort : public ISorter<T>
{
private:
    void SelectionSorting(Sequence<T>* seq, bool (*cmp)(T, T)) {
        int iMin;
        for (int j = 0; j < seq->GetLength(); j++) {
            iMin = j;
            for (int i = j; i < seq->GetLength(); i++) {
                if (!cmp(seq->Get(iMin), seq->Get(i))) {
                    iMin = i;
                }
            }
            T elem = seq->Get(j);
            seq->Set(seq->Get(iMin), j);
            seq->Set(elem, iMin);
        }
    }
public:
    Sequence<T>* Sort(Sequence<T>* seq, bool (*cmp)(T, T)) override {
        Sequence<T>* seqSort = seq->CopySequence();
        this->SelectionSorting(seqSort, cmp);
        return seqSort;
    }
    ~SelectionSort() override {}  
};