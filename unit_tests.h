#include <cassert>
#include <iostream>
#include <math.h>
#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "complex.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Vector.h"

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

/// testing Complex

void test_creating_complex() {
    Complex a(1, 0);
    Complex b = 1;
    Complex c;
    c.SetRe(1);
    c.SetIm(0);
    assert(a == b);
    assert(c == b);
}

void test_operations() {
    Complex a(1, 1);
    Complex b(-2, 4);
    Complex d(-1, 5);
    assert((a + b) == d);
    Complex e(3, -3);
    assert((a - b) == e);
    Complex f(-6, 2);
    assert((a * b) == f);
}

/// testing Vector
void test_creating_vector() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    int* arr2 = new int[10];
    for (int i = 0; i < 10; i++) {
        arr2[i] = i;
    }
    Vector<int> v(arr, 10, 1);
    Vector<int> v2(arr2, 10, 1);
    assert(v == v2);
    Vector<int> v3(v);
    v.Set(15, 3);
    assert(!(v == v3));
    Vector<int> vv(arr, 10, 2);
    Vector<int> vv2(arr2, 10, 2);
    assert(vv == vv2);
    Vector<int> vv3(vv);
    vv.Set(15, 3);
    assert(vv.Get(3) == 15);
    assert(!(vv == vv3));
    delete [] arr;
    delete [] arr2;
    Complex a(1, 1);
    Complex b(-2, 4);
    Complex* c = new Complex[2];
    c[0] = a;
    c[1] = b;
    Vector<Complex> v4(c, 2, 1);
    Vector<Complex> v5(v4);
    Vector<Complex> vv4(c, 2, 2);
    Vector<Complex> vv5(v4);
    delete [] c;
}

void test_operations_vector() {
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    int* arr2 = new int[10];
    for (int i = 0; i < 10; i++) {
        arr2[i] = 2 * i;
    }
    int* arr3 = new int[10];
    for (int i = 0; i < 10; i++) {
        arr3[i] = 3 * i;
    }
    Vector<int> v(arr, 10, 2);
    Vector<int> v2(arr2, 10, 2);
    Vector<int> v3(arr3, 10, 2);
    assert((v + v2) == v3);
    assert((3 * v) == v3);
    assert((v * 3) == v3);
    assert((2 * v2 - v) == v3);

    Vector<int> vv(arr, 10, 1);
    Vector<int> vv2(arr2, 10, 1);
    Vector<int> vv3(arr3, 10, 1);
    assert((vv + vv2) == vv3);
    assert((3 * vv) == vv3);
    assert((vv * 3) == vv3);
    assert((2 * vv2 - v) == vv3);
    assert((v * v2) == 570);
    assert((vv * vv2) == 570);
    Complex a(1, 0);
    Complex b(3, 4);
    Complex e(-3, 1);
    Complex* c = new Complex[2];
    c[0] = a;
    c[1] = b;
    Complex* f = new Complex[2];
    f[0] = b;
    f[1] = e;
    Complex* g = new Complex[2];
    g[0] = b + a;
    g[1] = e + b;
    Vector<Complex> v4(c, 2, 1);
    Vector<Complex> v5(f, 2, 1);
    Vector<Complex> v6(g, 2, 1);
    assert(v4.Norma() == 6); /// norma - sum module
    assert((v4 + v5) == v6);
    delete [] c;
    delete [] f;
    delete [] g;
    delete [] arr;
    delete [] arr2;
    delete [] arr3;
}