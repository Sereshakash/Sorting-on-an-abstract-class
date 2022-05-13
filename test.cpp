#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "complex.h"
#include "Vector.h"
using namespace std;

int main() 
{ 
    try {
        Complex c(1, 2.2);
        Complex d, e;
        d.SetRe(4);
        d.SetIm(0);
        e.SetRe(-111);
        e.SetIm(11);
        d.Print();
    /// std::cout << c << "\n";
        int* x = new int[3];
        ///x = (0, 3, 4);
        x[0] = 0;
        x[1] = -3;
        x[2] = 4;
        Complex* cq = new Complex[2];
        cq[0] = c;
        cq[1] = d;
        Vector <Complex> com1(cq, 2);
        Vector <Complex> com2(com1);
    /// com1.Print();
         com1.Set(e, 1);
        std::cout << "Int\n";
        Vector <int> vect(x, 3);
        Vector <int> vect2(vect);
        vect2.Set(17, 2);
        std::cout << vect.Norma() << "\n";
        (vect + vect2).Print();
        /*try {
            com1.Set(e, 7);
        }
        catch(...) {
            std::cout << "ERROR!!!\n";
        }*/
        com1.Print();
        std::cout << com1.Norma() << "\n";
        com2.Print();
        (com1 + com2).Print();
        std::cout << "QQQ " << (com1 * com2) << "\n";
        com1.Print();
        std::cout << c << "\n";
        com1.MultiplicationNumber(0).Print();
        int r = 5;
        Complex t = r;
        std::cout << t << "\n";
        std::cout << t.GetAbs() << "\n";
        vect2.Print();
        vect.Print();
        vect2.MultiplicationNumber(-2).Print();
        (vect2 * -2).Print();
        (-2 * vect2).Print();
        std::cout << "SSS \n";
        std::cout << "SSS " << (vect2 * vect) << "\n";
        std::cout << "SSS " << vect2.ScalarProduct(vect) << "\n";
        delete []cq;
        delete [] x;
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
    catch(...) {std::cout << "\n";}
}