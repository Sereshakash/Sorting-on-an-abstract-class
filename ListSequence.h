#pragma once
#include <stdlib.h>
#include "LinkedList.h"
#include "Sequence.h"

template<typename T>
class ListSequence : public Sequence<T>
{
protected:
	LinkedList<T>* list;
public:
    ListSequence() {
        list = new LinkedList<T>;
    }
    ListSequence(T* items, int count) {
        list = new LinkedList<T>(items, count);
    }
    ListSequence(const ListSequence<T> & LinkedListCopy) {
        list = new LinkedList<T>(*(LinkedListCopy.list));
    }
    T GetFirst() override {
        return this->list->GetFirst();
    }
    T GetLast() override {
        return this->list->GetLast();
    }
    T Get(int index) override {
        return this->list->Get(index);
    }
    int GetLength() override {
        return this->list->GetLength();
    }
    void Append(T item) override {
        this->list->Append(item);
    }
    void Prepend(T item) override {
        this->list->Prepend(item);
    }
    void InsertAt(T item, int index) override {
        this->list->InsertAt(item, index);
    }
    void Set(T item, int index) override {
        this->list->Set(index, item);
    }
    void Print() override {
        this->list->Print();
    }
    void Random() override {
        for (int i = 0; i < this->GetLength(); i++) {
            this->Set(rand(), i);
        }
    }
    ListSequence<T>* GetSubSequence(int startIndex , int endIndex) override {
        ListSequence<T>* newListSequence = new ListSequence<T>;
        delete newListSequence->list;
        newListSequence->list = this->list->GetSubList(startIndex, endIndex);
        return newListSequence;
    }

    ListSequence<T>* CopySequence() override {
        ListSequence<T>* CopySequence = new ListSequence<T>(*this);
        return CopySequence;
    }

    ListSequence<T>* Concat(Sequence<T>* plusList) override {
        ListSequence<T>* newListSequence = new ListSequence<T>;
        delete newListSequence->list;
        newListSequence->list = this->list->Concat(((ListSequence<T>*) plusList)->list);
        return newListSequence;
    }
    bool operator==(ListSequence<T> & list2);
	~ListSequence() override {
        delete list;
    }
};

template<class T> bool ListSequence<T>::operator==(ListSequence<T> &listSeq2) {
    if (*(this->list) == *(listSeq2.list)) {
        return true;
    } else {
        return false;
    }
}