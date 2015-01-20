#include<iostream>
#include<vector>
#include<string>
#include"PQList.h"

using namespace std;

int main(){
    cout << "<<<========================================>>>" <<endl;
    cout << "             Test the PQ list:" <<endl;
    cout << "<<<========================================>>>" <<endl;

    vector<PQList<Item>::Locator> locVec(60); // for bonus
    PQList<Item> pq;
    pq.createPriorityQueueList("inputdata",locVec); // create a new pqlist
    pq.minKey();        // get the first element
    for (int i=0; i<5; i++) {// remove 5 entries
        pq.removeKey();
        pq.printPQList();
    }
    pq.minKey();        // get the first element
}
