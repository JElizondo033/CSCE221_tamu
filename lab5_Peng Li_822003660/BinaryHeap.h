#include<cstdio>
#include<iomanip>
#include<iostream>
#include<cstring>
#include<fstream>
#include<cstring>

using namespace std;
template<typename ElemType>
class Item;
/******************************************************************/
//class Locator
template<typename ElemType>
class Locator{
private:
    Item<ElemType>* item;
public:
    void setItem(Item<ElemType>* i){item=i;}
    Locator(Item<ElemType>* i =NULL): item(i){}
    Item<ElemType>* getItem(){return item;}
};

/******************************************************************/
//class Item
template<typename ElemType>
class Item{
private:
    int key;
    ElemType elem;
    // locator
    Locator<ElemType>* loc;
public:
    Item( const int k=0,const ElemType& e=ElemType(), Locator<ElemType>* l=NULL): key(k), elem(e), loc(l) {}
    const int getKey()	const { return key; }
    const ElemType& getElem() const { return elem; }
    void setKey( int k) { key = k; }
    void setElem(ElemType& e) { elem = e; }
    // locator
    void setLocator(Locator<ElemType>* l){loc=l;}
    Locator<ElemType>* getLocator(){return loc;}
};

/******************************************************************/
//Class PQComp
template<typename ElemType>
class PQComp {
public:
    int operator()(	const Item<ElemType>& e1,const Item<ElemType>& e2) {
        return e1.getKey() - e2.getKey();
    }
};

/******************************************************************/
//Class Binary Heap
template<typename ElemType, typename Comp, typename L>
class BinaryHeap {
private:
    Comp comp;
    int curSize;
    ElemType *array;
    int length;
    static const int DEF_SIZE = 8;
    void getNewArray(int newSize) {
        array = new ElemType[newSize];
        length = newSize;
    }
public:
    BinaryHeap(int size = DEF_SIZE) { //constructor
        curSize = 0;
        getNewArray(size);
    }
    ElemType& findMin() { return array[0];}
    bool isEmpty( )	const { return curSize == 0; }
    void createPriorityQueue(string file, Locator<L> locArray[]);
    void insertItem(const ElemType& x,Locator<L>& loc);
    void removeKey();
    void walkUp(int hole, int& count);
    void walkDown(int hole, int& count);
    void decreaseKey( Locator<L>& loc , int k);
    void printPQHeap();
};

/******************************************************************/
// createPriorityQueue function
template<typename ElemType, typename Comp, typename L>
void BinaryHeap<ElemType, Comp, L>::createPriorityQueue(string filename, Locator<L> loc[]){
    std::cout<< "Create MPQ List:"<<std::endl;
    std::ifstream ist(filename);
    std::string line;
    int id;
    int key;
    char elem[20];
    while(getline (ist,line)){
        char *cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        sscanf(cstr,"%i,%i,%19s",&id, &key,elem);
        ElemType e(key, elem);
        insertItem(e,loc[id]);
        std::cout<<"Key = " << key << std::setw(10)<<"\tElem = " <<elem<<setw(10)<<"\tid = "<<id<<std::endl;
    }
    cout<<endl;
}

/******************************************************************/
//insertItem function
template<typename ElemType, typename Comp, typename L>
void BinaryHeap<ElemType, Comp, L>::insertItem(const ElemType& x,Locator<L>& loc) {
    int count=0;
    if (curSize == 0) {
        array[0]=x;
        curSize++;
        loc.setItem(&array[0]);
        array[0].setLocator(&loc);
        return;
    }
    else{
        //walk up (establish heap order now)
        curSize++;
        int hole = curSize-1;
        for ( ; hole > 0 && (count++,comp(array[(hole-1)/2], x))> 0; hole = (hole-1)/2){
            array[hole] = array[(hole-1)/2];
            array[hole].getLocator()->setItem(&array[hole]);
            array[(hole-1)/2]=x;
        }
        array[hole] = x;
        //locator
        loc.setItem(&array[hole]);
        array[hole].setLocator(&loc);
    }
}

/******************************************************************/
//removeKey()
template<typename ElemType, typename Comp, typename L>
void BinaryHeap<ElemType, Comp, L>::removeKey()  {
    int count=0;
    array[0] = array[ --curSize ];	//decrease size
    array[0].getLocator()->setItem(&array[0]);
    walkDown(0,count);
    cout<< "# comparisons performed by removeKey: " << count << endl << endl ;
}

/******************************************************************/
// decreaseKey
template<typename ElemType, typename Comp, typename L>
void BinaryHeap<ElemType, Comp, L>::decreaseKey(Locator<L>& loc , int key){
    int cnt = 0;
    loc.getItem()->setKey(key);
    int get=0;
    for(int i=0; i< curSize-1; i++){
        if( (loc.getItem())==(&array[i]) ) {
            get=i;
            break;
        }
    }
    walkUp(get,cnt);
    cout<< "# comparisons performed by decreaseKey: " << cnt << endl << endl ;
}

/******************************************************************/
//walkUp function
template<typename ElemType, typename Comp, typename L>
void BinaryHeap<ElemType, Comp, L>::walkUp(int hole, int& count){
    ElemType x = array[hole];
    for ( ; hole > 0 && (count++,comp(array[(hole-1)/2], x))> 0; hole = (hole-1)/2)
    {
        array[hole] = array[(hole-1)/2];
        array[hole].getLocator()->setItem(&array[hole]);
    }
    array[hole] = x;
    array[hole].getLocator()->setItem(&array[hole]);
}
/******************************************************************/
//walkdown function
template<typename ElemType, typename Comp, typename L>
void BinaryHeap<ElemType, Comp, L>::walkDown(int hole, int& count) {
    int child;
    ElemType key = array[hole];
    for ( ; 2*hole+1 < curSize; hole = child) {
        child = 2*hole+1;
        if ((count++,(child != curSize-1)) && (count++,comp(array[child], array[child+1])) > 0)
            child++;// right child = 2*hole+2
        if (comp(key, array[child]) > 0){
            array[hole]=array[child];
            array[hole].getLocator()->setItem(&array[hole]);
        }
        else break;
    }
    array[hole] = key;
    array[hole].getLocator()->setItem(&array[hole]);
}

/******************************************************************/
// print function
template<typename ElemType, typename Comp, typename L>
void BinaryHeap<ElemType, Comp, L>::printPQHeap() {
    for (int i=0; i<curSize; i++){
        cout<<"Key = "<< array[i].getKey()<<setw(10)<<"\tElement = "<<array[i].getElem()<<endl;
    }
    cout<<endl;
}