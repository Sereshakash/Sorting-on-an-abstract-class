#include <iostream>
#include "Sequence.h"
#include "ListSequence.h"
#include "ArraySequence.h"
#include "complex.h"
#include "Sort.h"
using namespace std;

int main() 
{ 
    int* x = new int[8];
    x[0] = 4;
    x[1] = 2;
    x[2] = 3;
    x[3] = 11;
    x[4] = 4;
    x[5] = 2;
    x[6] = 0;
    x[7] = 7;
    ArraySequence <int> dynamicArray(x, 8);
    InsertionSort <int> a;
    QuickSort <int> b;
    ShellSort <int> c;
    SelectionSort <int> d;
    dynamicArray.Print();
    Sequence <int>* sortingArrIn = a.Sort(&dynamicArray, comparison);
    sortingArrIn->Print();
    delete sortingArrIn;
    Sequence <int>* sortingArrQ = b.Sort(&dynamicArray, comparison);
    sortingArrQ->Print();
    delete sortingArrQ;
    Sequence <int>* sortingArrSh = c.Sort(&dynamicArray, comparison);
    sortingArrSh->Print();
    delete sortingArrSh;
    Sequence <int>* sortingArrSel = d.Sort(&dynamicArray, comparison);
    sortingArrSel->Print();
    delete sortingArrSel;
    dynamicArray.Print();
    std::cout << "\n";
    ListSequence <int> list(x, 8);
    list.Print();
    Sequence <int>* sortingListIn = a.Sort(&list, comparison);
    sortingListIn->Print();
    delete sortingListIn;
    Sequence <int>* sortingListQ = b.Sort(&list, comparison);
    sortingListQ->Print();
    delete sortingListQ;
    Sequence <int>* sortingListSh = c.Sort(&list, comparison);
    sortingListSh->Print();
    delete sortingListSh;
    Sequence <int>* sortingListSel = d.Sort(&list, comparison);
    sortingListSel->Print();
    delete sortingListSel;
    list.Print();
    delete x;
        ///com1.Print();
    /// std::cout << com1.Norma() << "\n";
    /// vect.Set(7, 1);
    ///  vect2.Print();
    ///  vect.Print();

    /*    int* x = new int[3];
        x[0] = 1;
        x[1] = 2;
        x[2] = 3;
    DynamicArray <int> dinamicArray(x, 3);
        DynamicArray <int> dinamicArray3(dinamicArray);
        cout << dinamicArray.Get(0);
        cout << dinamicArray.GetSize();
        dinamicArray.Set(0, 5);
        cout << dinamicArray.Get(0);
    /// cout << dinamicArray.Get(4);
        dinamicArray.Resize(5);
        dinamicArray.Set(15, 19);
        cout << dinamicArray.Get(4) << "\n";
        dinamicArray.Print();
        (*dinamicArray.GetSubArray(0, 3)).Print();
        cout << dinamicArray.GetFirst() << " " << dinamicArray.GetLast() << "\n";
        cout << "rAAAAAAA: \n";
        dinamicArray3.Print();
        dinamicArray.Print();
        dinamicArray.Append(29);
        dinamicArray.Prepend(1001);
        dinamicArray.Print();
        dinamicArray.InsertAt(123, 7);
        dinamicArray.Print();
        dinamicArray3.Print();
        (*dinamicArray.Concat(&dinamicArray3)).Print();
        LinkedList <int> linkedList(x, 3);
        linkedList.Print();
        LinkedList <int> linkedList1(linkedList);
        linkedList.Append(7);
        linkedList.Prepend(1999);
        linkedList.InsertAt(21, 1);
        cout << "res: \n";
        linkedList.Print();
        cout << linkedList.GetLength();
        
        cout << "res: \n";
        linkedList1.Print();
        (*linkedList.GetSubList(0, 2)).Print();
        (*linkedList1.Concat(&linkedList)).Print();
    */
        return 0;
    
}