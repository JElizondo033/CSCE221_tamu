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
    int insertItem(const int k, const ElemType& e, Locator<ElemType>& loc){
        Item<ElemType> i(k, e);
        int cnt = T.insertItem(i,loc);
        return cnt;
    }
//    void createPriorityQueueHeap(string filename, Locator<ElemType> locArray[]){ T.createPriorityQueue(filename,locArray);}
    
    const ElemType& minElement(){ return T.findMin().getElem();}
    
    const int minKey(){
        cout<<"minKey = "<<T.findMin().getKey()<<" Element = "<<T.findMin().getElem()<<endl<<endl;
        return T.findMin().getKey();
    }
    int removeKey(){ return T.removeKey();}
    int decreaseKey( Locator<ElemType>& loc,int k){ return T.decreaseKey(loc,k);}
//    void printPQHeap(){ T.printPQHeap();}
};
