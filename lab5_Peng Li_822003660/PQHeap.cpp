#include <iostream>
#include <vector>
#include<string>
#include"PQHeap.h"

using namespace std;

int main(){
    cout << "<<<========================================>>>" <<endl;
    cout << "             Test the PQ Heap:" <<endl;
    cout << "<<<========================================>>>" <<endl;
    PQHeap<string> pqHeap;
    Locator<string>* locVec= new Locator<string>[60];
    pqHeap.createPriorityQueueHeap("inputdata", locVec);
    pqHeap.printPQHeap();
    for (int i=0; i<5; i++) { // remove 5 entries
        pqHeap.minKey();
        pqHeap.removeKey();
        pqHeap.printPQHeap();
    }
    int index = 5;
    cout << locVec[index].getItem()->getElem()<<" decreaseKey to 0."<<endl<<endl;
    pqHeap.decreaseKey(locVec[index] , 0);
    pqHeap.printPQHeap();
}

