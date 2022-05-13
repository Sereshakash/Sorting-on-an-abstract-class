#pragma once
#include<iostream>
#include "Excepsion.h"

template <class T> 
class LinkedList {
    private:
        struct Item{
            T data;
            Item* next = nullptr;
        };
        Item* head = nullptr;
        Item* tail = nullptr;
    public:
        LinkedList(T* items, int count);
        LinkedList();
        LinkedList(const LinkedList <T> & listCopy);
        T GetFirst();
        T GetLast();
        T Get(int index);
        int GetLength();
        LinkedList<T>* GetSubList(int startIndex, int endIndex);
        void Print();
        void Append(T item);
        void Prepend(T item);
        void InsertAt(T item, int index);
        void Set(int index, T value);
        LinkedList<T>* Concat(LinkedList<T> *list);
        bool operator==(LinkedList<T> & list2);
        ~LinkedList();
};

template<class T> LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

template<class T> LinkedList<T>::LinkedList(T* items, int count) {
    Item* newItem = new Item;
    newItem->data = items[0];
    newItem->next = nullptr;
    head = newItem;
    tail = newItem;
    for(int i = 1; i < count ; i++) {
        Item* newItem = new Item;
        newItem->data = items[i];
        newItem->next = nullptr;
        tail->next = newItem;
        tail = newItem;
    }
}

template<class T> LinkedList<T>::LinkedList(const LinkedList<T> &listCopy) {
    Item* elemCopy = listCopy.head;
    Item* newItem = new Item;
    newItem->data = elemCopy->data;
    newItem->next = nullptr;
    head = newItem;
    tail = newItem;
    elemCopy = elemCopy->next;
    while(elemCopy){
        Item* newItem = new Item;
        newItem->data = elemCopy->data;
        newItem->next = nullptr;
        tail->next = newItem;
        tail = newItem;
        elemCopy = elemCopy->next;
    }
}

template<class T> T LinkedList<T>::GetFirst() {
    if(head == nullptr)
        throw ExceptionError(1);
    return head->data;
}

template<class T> T LinkedList<T>::GetLast() {
    if(head == nullptr){
        throw ExceptionError(1);
    }
    return tail->data;
}

template<class T> int LinkedList<T>::GetLength() {
    if (head == nullptr)
        return 0;
    int length = 0;
    Item* item = head;
    while (item)
    {
        length++;
        item = item->next;
    }
    return length;
}

template<class T> T LinkedList<T>::Get(int index) {
    int size = GetLength();
    if (index < 0 || index >= size)
        throw ExceptionError(1);
    Item* item = head;
    for(int i = 0; i < index; i++) {
        item = item->next;
    }
    return item->data;
}

template<class T> void LinkedList<T>::Print() {
    Item* item = head;
    while(item) {
        std::cout << item->data << " ";
        item = item->next;
    }
    std::cout << "\n";
}

template<class T> LinkedList<T>::~LinkedList() {
    Item* item1 = head;
    Item* item2 = nullptr;
    while(item1) {
        item2 = item1;
        item1 = item1->next;
        delete item2;
    }
}

template<class T> LinkedList<T>* LinkedList<T>::GetSubList(int startIndex , int endIndex) {
    int size = GetLength();
    if (startIndex < 0 || endIndex >= size || startIndex > endIndex)
        throw ExceptionError(1);
    LinkedList<T>* resList = new LinkedList<T>;
    Item* oldItem = head;
    for (int i = 0; i < startIndex; i++) {
        oldItem = oldItem->next;
    }
    for (int j = startIndex; j < endIndex + 1; j++)
    {
        Item* newItem = new Item;
        newItem->data = oldItem->data;
        newItem->next = nullptr;
        if(resList->head == nullptr) {
            resList->head  = newItem;
            resList->tail = newItem;
        } else {
            resList->tail->next = newItem;
            resList->tail = newItem;
        }
        oldItem = oldItem->next;
    }
    return resList;
}

template<class T> void LinkedList<T>::Append(T item) {
    Item* newItem = new Item;
    newItem->data = item;
    newItem->next = nullptr;
    if(head == nullptr) { 
        head = newItem;
        tail = newItem;
    } else {
        tail->next = newItem;
        tail = newItem;
    }
}

template<class T> void LinkedList<T>::Prepend(T item) {
    Item* newItem = new Item;
    newItem->data = item;
    newItem->next = nullptr;
    if(head == nullptr) { 
        head = newItem;
        tail = newItem;
    } else {
        newItem->next = head;
        head = newItem;
    }
}

template<class T> void LinkedList<T>::InsertAt(T item , int index) {
    int size = GetLength();
    if (index < 0 || index >= size)
        throw ExceptionError(1);
    Item* newItem = new Item;
    newItem->data = item;
    Item* itemLeft = head;
    for(int i = 0; i < index - 1; i++) {
        itemLeft = itemLeft->next;
    }
    Item* itemRight = itemLeft->next;
    itemLeft->next = newItem;
    newItem->next = itemRight;
}

template<class T> void LinkedList<T>::Set(int index, T value) {
    int size = GetLength();
    if (index < 0 || index >= size)
        throw ExceptionError(1);
    Item* item = head;
    for(int i = 0; i < index; i++) {
        item = item->next;
    }
    item->data = value;
}

template<class T> LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list) {
	LinkedList<T>* resList = new LinkedList(*this);
	for (int i = 0; i < list->GetLength(); i++) {
		resList->Append(list->Get(i));
	}
	return resList;
}

template<class T> bool LinkedList<T>::operator==(LinkedList<T> &list2) {
    if (this->GetLength() != list2.GetLength()) {
        return false;
    } else {
        Item* item = head;
        Item* item2 = list2.head;
        while (item) {
            if (!(item->data == item2->data)) {
                return false;
            }
            item = item->next;
            item2 = item2->next;
        }
        return true;
    }
}