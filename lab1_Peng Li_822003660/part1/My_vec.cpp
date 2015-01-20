#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include "My_vec.h"

My_vec::My_vec(): size(0), capacity(10),
					ptr(new char[capacity]){}

My_vec::~My_vec(){
	delete[] ptr;
}
 
My_vec::My_vec(const My_vec& vec):size(vec.size),capacity(vec.capacity),ptr(new char[vec.capacity])
{ // this is for My_vec v2 = v1;
	for(auto i=0; i<size ; i++ )
		ptr[i] = vec.ptr[i];
}


My_vec& My_vec::operator=(const My_vec& vec){ // this one is for v2 = v1
    delete[] ptr;  // deallocate old vector
    size = vec.size;
	capacity = vec.capacity;
	ptr = new char[vec.capacity];
	for(int i=0; i<size ; i++ )
		ptr[i] = vec.ptr[i];

    return *this; // return reference
}

int My_vec::get_size() const{
	return size;
}

int My_vec::get_capacity() const{
	return capacity;
}
char& My_vec::operator[](int i) const{
    if(i<0 || i>=size){
        cerr<< "Out of range"<<endl;
        exit(EXIT_FAILURE);
    }
	return ptr[i];
}

char& My_vec::operator[](int i){
    if(i<0 || i>=size){
        cerr<< "Out of range"<<endl;
    }
	return ptr[i];
}

bool My_vec::is_empty() const{
	return size == 0;
}

char& My_vec::elem_at_rank(int r) const{ // add range limit
	if(r<0 || r >= size){
		cerr << "Out of range"<<endl;
        exit(EXIT_FAILURE);
    }
    return ptr[r];
}
void My_vec::insert_at_rank(int r, const char& elem){// if the element is beyond the range
    int initial_size = size;
    if(r<0){
		cerr << "Out of range"<<endl;
        exit(EXIT_FAILURE);
    }
    else if (r<=size) {
        size++;
    }
    else
        size = r+1;
    
    if (size>capacity) {
        char* new_ptr = new char[capacity*2];
        for (int i =0; i<capacity; i++) {
            new_ptr[i] = ptr[i];
        }
        capacity *= 2;
        delete[] ptr;
        ptr = new_ptr;
        free(new_ptr);
    }
    
    for(int i=size-1; i>r; i--){
        ptr[i] = ptr[i-1];
    }
    for (int i=initial_size; i<r; i++) {
        ptr[i] = '0';
    }
    ptr[r] = elem;
    
}
void My_vec::replace_at_rank(int r, const char& elem){
    if (r<0 || r >=size) {
        cerr<< "Out of range"<<endl;
        exit(EXIT_FAILURE);
    }
    else    ptr[r] = elem;
}



void My_vec::remove_at_rank(int r){
    if (r<0 || r >=size) {
        cerr<< "Out of range"<<endl;
        exit(EXIT_FAILURE);
    }
    else{
        size--;
        for (int i = r; i<size; ++i) {
            ptr[i] = ptr[i+1];
        }
    }
	
}

ostream& operator<<(ostream& out, const My_vec& vec){
    for (int i=0; i<vec.get_size(); i++) {
        out<< vec.elem_at_rank(i)<<" ";  // write vec elem to out stream
    }
    return out;
}


int find_max_index(const My_vec& v,int size){
    if(v.is_empty()){
        cerr<<"empty vector"<<endl;
        exit(EXIT_FAILURE);
    }
    else{
        int current_max_index = 0;
        char current_char = v[0];
        for(int i=1;i<size;i++){
            if (v[i]>current_char){
                current_max_index = i;
                current_char = v[i];
            }
        }
        return current_max_index;
    }

}

void sort_max(My_vec& vec){
    My_vec v1 = vec;
    int index;
    int i = 0;
    while(!vec.is_empty()){
        index = find_max_index(vec,vec.get_size());
        v1[i]=vec[index];
        vec.remove_at_rank(index);
        i++;
    }
    vec = v1;
    v1.~My_vec();
}




