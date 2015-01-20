#include<iostream>
#include<iomanip>
#include<list>
#include<vector>
#include<fstream>
#include<cstring>
//using namespace std;

class Locator;

template <typename E>
class PQList { // priority queue list
protected:
    typedef std::list<E> ElementList; // list for the element

public:
    class Locator{ // Locator
        friend class PQList;
        private:
            typename ElementList::iterator iterator;
        public:
            const E& operator*() { return *iterator; } // content
    };
    
    Locator insertItem( E& e); // insert element
    void removeKey();
    void printPQList();
    void minKey();
    void createPriorityQueueList(std::string filename,std::vector<Locator>& r);
    void decreaseKey(const Locator& p, const int& k, std::vector<Locator>& r);

private:
    ElementList L; // priority queue contents
};

/******************************************************************/
// Item class
class Item {
private:
    int key;
    std::string element;
    PQList<Item>::Locator* p;
public:
    Item(int k, std::string elem):key(k),element(elem){}
    int getKey() const{ return key;}
    std::string getElem() const{return element;}
    PQList<Item>::Locator* getItem(){return p;}
    void setKey(const int& k){key=k;}
    void setElem(std::string& elem){element=elem;}
    void setLocator(PQList<Item>::Locator* pos){p=pos;}
    // less than
    bool operator()(const Item& kep) {return key < kep.key;}
};

/******************************************************************/
template <typename E> // insert item
typename PQList<E>::Locator
PQList<E>::insertItem( E& e) {
    typename ElementList::iterator iterator = L.begin();
    while (iterator != L.end() && !e(*iterator))
        ++iterator; // find largest element
    Locator position;
    position.iterator =L.insert(iterator, e); // insert after the largest
    e.setLocator(&position);
    return position; // inserted position returned to the vector
}

/******************************************************************/
template <typename E>
void PQList<E>::createPriorityQueueList(std::string filename, std::vector<Locator>& r){
    std::cout<< "Create MPQ:"<<std::endl;
    std::ifstream ist(filename);
    std::string line;
    int id;
    int key;
    char elem[20];
    
    while(getline (ist,line)){
        char *cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());
        sscanf(cstr,"%i,%i,%19s",&id, &key,elem);
        E e(key, elem);
        r[id]=insertItem(e);
        std::cout<<"Key = " << key << std::setw(10)<<"\tElem = " <<elem<<std::endl;
    }
    std::cout<<std::endl;
}
/******************************************************************/
template <typename E>
void PQList<E>::minKey(){
    std::cout << "First element: " <<L.begin()->getElem() << "\tKey: "<< L.begin()->getKey()<<std::endl<<std::endl;
}

/******************************************************************/
template <typename E>
void PQList<E>::removeKey(){
    std::cout << L.begin()->getElem() << " has been removed.\n"<<std::endl;
    L.erase(L.begin());
}

/******************************************************************/
template <typename E> // print list
void PQList<E>::printPQList(){
    for(auto tmp = L.begin(); tmp != L.end(); tmp++){
        std::cout<<"Key = " << tmp->getKey() << std::setw(10)<<"\tElem = " <<tmp->getElem()<<std::endl;
    }
    std::cout<<std::endl;
}

/******************************************************************/
template <typename E> // decreaseKey
void PQList<E>::decreaseKey(const Locator& p, const int& k, std::vector<Locator>& r) {
    int cnt=0;
    std::string elem=p.q->getElem();
    L.erase(p.q); // remove the old entry
    E e(k,elem);
    for(int i=0; i<r.size(); i++){
        if((cnt++,r[i].q==p.q)){r[i]=insertItem(e);break;}
    }  // insert replacement
    std::cout<< "# comparisons performed by decreaseKey: " << cnt <<std::endl<<std::endl;
}