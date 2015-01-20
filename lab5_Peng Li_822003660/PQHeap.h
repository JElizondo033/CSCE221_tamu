#include "BinaryHeap.h"

template<typename ElemType>
class PQHeap {
protected:
    typedef PQComp<ElemType> pqComp;
private:
    static const int DEF_SIZE = 256;
public:
    BinaryHeap< Item<ElemType> , pqComp, ElemType> T;
    PQHeap(int size = DEF_SIZE) : T(size) {}
    bool isEmpty() const{ return T.isEmpty(); }
    void insertItem(const int k, const ElemType& e, Locator<ElemType>& loc){
        Item<ElemType> i(k, e);
        T.insertItem(i,loc);
    }
    void createPriorityQueueHeap(string filename, Locator<ElemType> locArray[]){ T.createPriorityQueue(filename,locArray);}
    const int minKey(){
        cout<<"minKey = "<<T.findMin().getKey()<<" Element = "<<T.findMin().getElem()<<endl<<endl;
        return T.findMin().getKey();
    }
    void removeKey(){ T.removeKey();}
    void decreaseKey( Locator<ElemType>& loc,int k){ T.decreaseKey(loc,k);}
    void printPQHeap(){ T.printPQHeap();}
};
