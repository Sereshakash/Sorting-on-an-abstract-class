#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <ctime>
#include "Sequence.h"
#include "ListSequence.h"
#include "ArraySequence.h"
#include "complex.h"
#include "Sort.h"
#include "graphic.h"
using namespace std;

int main(int argc, char *argv[]) {
    srand(time(0));
    if (argc <= 1) {
        return 0;
    } else {
        int key = 0;
        int numSeq = 0;
        int numberSort = 4;
        int numTime = 0;
        ISorter<int>* executableSort[numberSort];
        InsertionSort <int> ex1;
        SelectionSort <int> ex2;
        QuickSort <int> ex3;
        ShellSort <int> ex4;
        for (int i = 0; i < argc; i++) {
            if ((string(argv[i]) == "-InsertionSort" || string(argv[i]) == "-InS") && key <= numberSort) {
                executableSort[key] = &ex1;
                key++;
            } else if ((string(argv[i]) == "-SelectionSort" || string(argv[i]) == "-SelS") && key <= numberSort) {
                executableSort[key] = &ex2;
                key++;
            } else if ((string(argv[i]) == "-QuickSort" || string(argv[i]) == "-QS") && key <= numberSort) {
                executableSort[key] = &ex3;
                key++;
            } else if ((string(argv[i]) == "-ShellSort" || string(argv[i]) == "-ShS") && key <= numberSort) {
                executableSort[key] = &ex4;
                key++;
            }
            if (string(argv[i]) == "-ArraySequence" || string(argv[i]) == "-ASeq") {
                numSeq = 0;
            } else if (string(argv[i]) == "-ListSequence" || string(argv[i]) == "-LSeq") {
                numSeq = 1;
            }
            
            if (string(argv[i]) == "-Time" || string(argv[i]) == "-T") {
                numTime = 1;
            }
        }
        if (!key) {
            executableSort[key] = &ex3;
            key++;
        }
        if (string(argv[1]) == "-Example" || string(argv[1]) == "-Ex") {
            int lenArr = 20;
            int* arr = new int[lenArr];
            int i = 0;
            while (argv[i][0] > '9' || argv[i][0] < '0') {
                i++;
            }
            int start = i;
            while (argv[i]) {
                if (lenArr <= i) {
                    int* arr1 = new int[lenArr * 2];
                    for (int i = 0; i < lenArr; i++) {
                        arr1[i] = arr[i];
                    }
                    delete [] arr;
                    arr = arr1;
                    lenArr *= 2;
                }
                int num = 0;
                for (int j = 0; argv[i][j]; j++) {
                    num *= 10;
                    num += int(argv[i][j]) - 48;
                }
                arr[i - start] = num;
                i++;
            }
            Sequence <int>* seq;
            if (!numSeq) {
                seq = new ArraySequence <int>(arr, i - start);
            } else {
                seq = new ListSequence <int>(arr, i - start);
            }
            cout << "Example:\n";
            seq->Print();
            delete [] arr;
            for (int i = 0; i < key; i++) {
                unsigned int start_time =  clock();
                Sequence <int>* sortingSeq = (executableSort[i])->Sort(seq, comparison);
                unsigned int end_time = clock(); 
                if (numTime) {
                    unsigned int search_time = (end_time - start_time) / (CLOCKS_PER_SEC / 1000000);
                    cout << "time - " << search_time << " mkc" << endl;
                }
                else {
                    cout << "Sorting number " << i + 1 << "\n";
                    sortingSeq->Print();
                }
                delete sortingSeq;
            }
        } else if (string(argv[1]) == "-Generation" || string(argv[1]) == "-Gen") {
            int i = 0;
            int keyNum = 0;
            while (argv[i] && !keyNum) {
                if (argv[i][0] > '9' || argv[i][0] < '0') {
                    i++;
                } else {
                    keyNum = 1;
                }
            }
            int len = 10;
            if (keyNum) {
                len = 0;
                for (int j = 0; argv[i][j]; j++) {
                    len *= 10;
                    len += int(argv[i][j]) - 48;
                }
            }
            int arr1[len];
            Sequence <int>* seq;
            if (!numSeq) {
                seq = new ArraySequence <int>(arr1, len);
            } else {
                seq = new ListSequence <int>(arr1, len);
            }
            seq->Random();
            for (int i = 0; i < key; i++) {
                unsigned int start_time =  clock();
                Sequence <int>* sortingSeq = (executableSort[i])->Sort(seq, comparison);
                unsigned int end_time = clock(); 
                if (numTime) {
                    cout << "Sorting number " << i + 1 << "\n";
                    unsigned int search_time = (end_time - start_time) / (CLOCKS_PER_SEC / 1000);
                    cout << "time - " << search_time << " mlc" << endl;
                } else {
                    if (!i) {
                        cout << "Example:\n";
                        seq->Print();
                    }
                    cout << "Sorting number " << i + 1 << "\n";
                    sortingSeq->Print();
                }
                delete sortingSeq;
            }
            delete seq;
        } else if (string(argv[1]) == "-Comparison" || string(argv[1]) == "-Com") {
            arr_x[0] = 100;
            arr_x[1] = 500;
            for (int i = 2; i < 15; i++) {
                arr_x[i] = 1000 * (i - 1);
            }
            for (int i = 15; i < 20; i++) {
                arr_x[i] = 2500 * (i - 14) + 15000;
            }
            for (int j = 0; j < key; j++) {
                for (int i = 0; i < 20; i++) {
                    int arr[(int) (arr_x[i])];
                    Sequence <int>* seq;
                    if (!numSeq) {
                        seq = new ArraySequence <int>(arr, (int) (arr_x[i]));
                    } else {
                        seq = new ListSequence <int>(arr, (int) (arr_x[i]));
                    }
                    seq->Random();
                    unsigned int start_time =  clock();
                    Sequence <int>* sortingSeq = (executableSort[j])->Sort(seq, comparison);
                    unsigned int end_time = clock(); 
                    double search_time = ((double)((end_time - start_time)) / (CLOCKS_PER_SEC / 1000000));
                    arr_y[i] = search_time; 
                    delete sortingSeq;
                    delete seq;
                }
            }
            //for (int i = 0; i < 20; i++) {
            //    std::cout << arr_x[i] << " " << arr_y[i] << std::endl;
            //}
            glutInit(&argc, argv);
            init();
    
        } else if (string(argv[1]) == "-Help" || string(argv[1]) == "-H") {
            cout << "Sorting commands:\n-InsertionSort or -InS\n-SelectionSort or -SelS\n-QuickSort or -QS\n-ShellSort or -ShS\nOr nothing\n";
            cout << "-Sequence:\n-ArraySequence or -ASeq\n-ListSequence or -LSeq\nor nothing\n";
            cout << "Sorting the entered data:\n-Example (or -Ex) -Sorting -Sequence -Time(or nothing) data\n";
            cout << "Sorting random data:\n-Generation (or -Gen) -Sorting -Sequence -Time(or nothing) number(or nothing)\n";

        }
    } 
    
    return 0;
    
}