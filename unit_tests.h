#include <cassert>
#include <iostream>
#include <math.h>
#include <algorithm>
#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "complex.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Sort.h"

 /// testing LinkedList and DynamicArray

void test_getter() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    LinkedList<int> list(arr, 10);
    DynamicArray<int> array(arr, 10);
    int a;
    for (size_t i = 0; i < 10; i++) {
        /// testing Get
        a = list.Get(i);
        assert(a == i);
        a = array.Get(i);
        assert(a == i);
    }
    // testing GetFirst
    a = list.GetFirst();
    assert(a == 0);
    a = array.GetFirst();
    assert(a == 0);
    // testing GetLast
    a = list.GetLast();
    assert(a == 9);
    a = array.GetLast();
    assert(a == 9);
    // testing GetLength
    a = list.GetLength();
    assert(a == 10);
    a = array.GetSize();
    assert(a == 10);
    delete [] arr;
}

void test_setting() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    LinkedList<int> list(arr, 10);
    DynamicArray<int> array(arr, 10);
    int a;
    // testing Set first
    list.Set(0, 15);
    array.Set(0, 25);
    a = list.GetFirst();
    assert(a == 15);
    a = array.GetFirst();
    assert(a == 25);
    // testing Set last
    list.Set(9, -2);
    array.Set(9, 0);
    a = list.GetLast();
    assert(a == -2);
    a = array.GetLast();
    assert(a == 0);
    // testing Set random number
    list.Set(9, -2);
    array.Set(9, 0);
    a = list.GetLast();
    assert(a == -2);
    a = array.GetLast();
    assert(a == 0);
    delete [] arr;
}

void test_adding() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    LinkedList<int> list(arr, 10);
    DynamicArray<int> array(arr, 10);
    int a;
    // testing Append
    list.Append(-2);
    array.Append(0);
    a = list.GetLast();
    assert(a == -2);
    a = array.GetLast();
    assert(a == 0);
    // testing Prepend
    list.Prepend(-3);
    array.Prepend(117);
    a = list.GetFirst();
    assert(a == -3);
    a = array.GetFirst();
    assert(a == 117);
    // testing InsertAt
    list.InsertAt(221, 2);
    array.InsertAt(-23, 5);
    a = list.Get(2);
    assert(a == 221);
    a = array.Get(5);
    assert(a == -23);
    delete [] arr;
}

void test_getting_new_list() {
    int* arr = new int[10];
    int* arr3 = new int[16];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
        arr3[i] = i;
    }
    int* arr2 = new int[6];
    for (int i = 0; i < 6; i++) {
        arr2[i] = i + 2;
        arr3[i + 10] = i + 10;
    }
    assert(arr3[9] == 9);
    LinkedList<int> list(arr, 10);
    DynamicArray<int> array(arr, 10);
    LinkedList<int> list2(arr2, 6);
    DynamicArray<int> array2(arr2, 6);
    LinkedList<int> list3(arr3, 16);
    DynamicArray<int> array3(arr3, 16);
    int a;
    // testing GetSubArray and GetSubList
    DynamicArray<int>* arrayPtr = array.GetSubArray(2, 7);
    LinkedList<int>* listPtr = list.GetSubList(2, 7);
    assert(*(arrayPtr) == array2);
    assert(*(listPtr) == list2);
    delete arrayPtr;
    delete listPtr;
    // testing Concat
    for (int i = 0; i < 6; i++) {
        arr2[i] = i + 10;
    }
    LinkedList<int> list5(arr2, 6);
    DynamicArray<int> array5(arr2, 6);
    DynamicArray<int>* arrayPtr2 = array.Concat(&array5);
    LinkedList<int>* listPtr2 = list.Concat(&list5);
    assert(*(arrayPtr2) == array3);
    assert(*(listPtr2) == list3);
    delete arrayPtr2;
    delete listPtr2;

    delete [] arr;
    delete [] arr2;
    delete [] arr3;
}

void test_creating() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    int* arr2 = new int[10];
    for (int i = 0; i < 10; i++) {
        arr2[i] = i;
    }
    LinkedList<int> list(arr, 10);
    DynamicArray<int> array(arr, 10);
    LinkedList<int> list2(arr2, 10);
    DynamicArray<int> array2(arr2, 10);
    LinkedList<int> list3(list);
    DynamicArray<int> array3(array);
    assert(array3 == array2);
    assert(list3 == list2);
    list.Set(2, 14);
    array.Set(2, 14);
    assert(!(array3 == array));
    assert(!(list3 == list));
    delete [] arr;
    delete [] arr2;
}

 /// testing ListSequence and ArraySequence

void test_getter_sequence() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    ListSequence<int> list(arr, 10);
    ArraySequence<int> array(arr, 10);
    int a;
    for (size_t i = 0; i < 10; i++) {
        /// testing Get
        a = list.Get(i);
        assert(a == i);
        a = array.Get(i);
        assert(a == i);
    }
    // testing GetFirst
    a = list.GetFirst();
    assert(a == 0);
    a = array.GetFirst();
    assert(a == 0);
    // testing GetLast
    a = list.GetLast();
    assert(a == 9);
    a = array.GetLast();
    assert(a == 9);
    // testing GetLength
    a = list.GetLength();
    assert(a == 10);
    a = array.GetLength();
    assert(a == 10);
    delete [] arr;
}

void test_setting_Sequence() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    ListSequence<int> list(arr, 10);
    ArraySequence<int> array(arr, 10);
    int a;
    // testing Set first
    list.Set(15, 0);
    array.Set(25, 0);
    a = list.GetFirst();
    assert(a == 15);
    a = array.GetFirst();
    assert(a == 25);
    // testing Set last
    list.Set(-2, 9);
    array.Set(0, 9);
    a = list.GetLast();
    assert(a == -2);
    a = array.GetLast();
    assert(a == 0);
    // testing Set random number
    list.Set(-2, 9);
    array.Set(0, 9);
    a = list.GetLast();
    assert(a == -2);
    a = array.GetLast();
    assert(a == 0);
    delete [] arr;
}

void test_adding_sequence() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    ListSequence<int> list(arr, 10);
    ArraySequence<int> array(arr, 10);
    int a;
    // testing Append
    list.Append(-2);
    array.Append(0);
    a = list.GetLast();
    assert(a == -2);
    a = array.GetLast();
    assert(a == 0);
    // testing Prepend
    list.Prepend(-3);
    array.Prepend(117);
    a = list.GetFirst();
    assert(a == -3);
    a = array.GetFirst();
    assert(a == 117);
    // testing InsertAt
    list.InsertAt(221, 2);
    array.InsertAt(-23, 5);
    a = list.Get(2);
    assert(a == 221);
    a = array.Get(5);
    assert(a == -23);
    delete [] arr;
}

void test_creating_sequence() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    int* arr2 = new int[10];
    for (int i = 0; i < 10; i++) {
        arr2[i] = i;
    }
    ListSequence<int> list(arr, 10);
    ArraySequence<int> array(arr, 10);
    ListSequence<int> list2(arr2, 10);
    ArraySequence<int> array2(arr2, 10);
    ListSequence<int> list3(list);
    ArraySequence<int> array3(array);
    assert(array3 == array2);
    assert(list3 == list2);
    list.Set(14, 2);
    array.Set(14, 2);
    assert(!(array3 == array));
    assert(!(list3 == list));
    delete [] arr;
    delete [] arr2;
}



void test_sorting() {
    InsertionSort <int> ex1;
    SelectionSort <int> ex2;
    QuickSort <int> ex3;
    ShellSort <int> ex4;
    int* arr = new int[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = rand();
    }
    ArraySequence<int> array(arr, 1000);

    ArraySequence<int>* arrayInsS = (ArraySequence<int>*) (ex1.Sort(&array, comparison));
    ArraySequence<int>* arraySelS = (ArraySequence<int>*) (ex1.Sort(&array, comparison));
    ArraySequence<int>* arrayQS = (ArraySequence<int>*) (ex1.Sort(&array, comparison));
    ArraySequence<int>* arrayShS = (ArraySequence<int>*) (ex1.Sort(&array, comparison));
    assert(*arrayInsS == *arraySelS);
    assert(*arraySelS == *arrayQS);
    assert(*arrayQS == *arrayShS);
    assert(*arrayShS == *arrayInsS);
    qsort(arr, 1000, sizeof(int), comp1);
    ArraySequence<int> array1(arr, 1000);
    assert(array1 == *arraySelS);
    delete [] arr;
    delete arrayInsS;
    delete arraySelS;
    delete arrayQS;
    delete arrayShS;
}
