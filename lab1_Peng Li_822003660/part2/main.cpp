// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"

int main(){
try{
    /**************INT******************/

    My_vec<int> v;                       // define an object v of My_vec type
    v.insert_at_rank(0,3);        // insert 'B' at the rank 0 into the vector v
	cout << v << endl;              // use the overloaded operator << to display vector elements
    cout << v.get_size()<< endl;    // display the vector v size
    

	v.insert_at_rank(0,1);        // insert 'A' at the rank 0 into the vector v
	cout << v << endl;              // use the overloaded operator << to display vector elements
	cout << v.get_size()<< endl;    // display the vector v size

	v.insert_at_rank(10,5);        // insert 'D' at the rank 10 into the vector v
	cout << v << endl;              // use the overloaded operator << to display vector elements
	cout << v.get_size()<< endl;    // display the vector v size

	v.remove_at_rank(2);            // remove a character at the rank 2 from the vector v
	cout << v << endl;              // use the overloaded operator << to display vector elements
	cout << v.get_size()<< endl;    // display the vector v size

	v.replace_at_rank(2,4);       // replace a character at the rank 2 by the character 'E'
	cout << v << endl;              // use the overloaded operator << to display vector elements
	cout << v.get_size()<< endl;    // display the vector v size
	
	My_vec<int> v1 = v;                  // create a copy v1 of the vector v using a copy constructor
	cout << v1 << endl;             // use the overloaded operator << to display the vector v1
    v1.replace_at_rank(2,100);      // replace a character at the rank 2 of the vector v1 with the character 'Y'
	cout << v1 << endl;             // use the overloaded operator << to display vector v1 elements

	My_vec<int> v2;                      // define an object v2 of My_vec type
	v2.insert_at_rank(0,50);       // insert 'K' at the rank 0 into the vector v2
	cout << v2 << endl;             // use the overloaded operator << to display vector elements
    cout << v2.get_size() << endl;  // display the vector v2 size

    v2 = v1;                        // test the assignment operator and copy the vector v1 to v2
    cout << v2 << endl;             // use the overloaded operator << to display vector v2
    cout << v2.get_size() << endl;  // display the vector v2 size

    int v2_max = find_max_index(v2,v2.get_size());// test the function find_max_index using v2
    cout << "v2 find max is: v2[" <<v2_max<<"]" << endl;   // ADD BY PENG LI
	sort_max(v2);                   // test the function sort_max using v2
    cout << v2 << endl;             // use the overloaded operator << to display vector v2

    // the next line is comment out because there is no element at rank 14 and the program will exit  
	//v2.replace_at_rank(14,99);     // replace in the vector v2 a character at the rank 14 with 'S'
/*****************DOUBLE**************/
    
    My_vec<double> v3;                       // define an object v of My_vec type
    v.insert_at_rank(0,3.234);        // insert 'B' at the rank 0 into the vector v3
	cout << v3 << endl;              // use the overloaded operator << to display vector elements
    cout << v3.get_size()<< endl;    // display the vector v3 size
    
    
	v3.insert_at_rank(0,1.444);        // insert 'A' at the rank 0 into the vector v3
	cout << v3 << endl;              // use the overloaded operator << to display vector elements
	cout << v3.get_size()<< endl;    // display the vector v3 size
    
	v3.insert_at_rank(10,4.6);        // insert 'D' at the rank 10 into the vector v3
	cout << v3 << endl;              // use the overloaded operator << to display vector elements
	cout << v3.get_size()<< endl;    // display the vector v3 size
    
	v3.remove_at_rank(2);            // remove a character at the rank 2 from the vector v3
	cout << v3 << endl;              // use the overloaded operator << to display vector elements
	cout << v3.get_size()<< endl;    // display the vector v3 size
    
	v3.replace_at_rank(2,4.5);       // replace a character at the rank 2 by the character 'E'
	cout << v3 << endl;              // use the overloaded operator << to display vector elements
	cout << v3.get_size()<< endl;    // display the vector v3 size
	
	My_vec<double> v4 = v3;          // create a copy v4 of the vector v3 using a copy constructor
	cout << v4 << endl;             // use the overloaded operator << to display the vector v4
    v4.replace_at_rank(2,100);      // replace a character at the rank 2 of the vector v4 with the character 'Y'
	cout << v4 << endl;             // use the overloaded operator << to display vector v4 elements
    
	My_vec<double> v5;               // define an object v2 of My_vec type
	v5.insert_at_rank(0,50.44);       // insert 'K' at the rank 0 into the vector v5
	cout << v5 << endl;             // use the overloaded operator << to display vector elements
    cout << v5.get_size() << endl;  // display the vector v5 size
    
    v5 = v4;                        // test the assignment operator and copy the vector v4 to v5
    cout << v5 << endl;             // use the overloaded operator << to display vector v5
    cout << v5.get_size() << endl;  // display the vector v5 size
    
    int v5_max = find_max_index(v5,v5.get_size());// test the function find_max_index using v5
    cout << "v5 find max is: v5[" <<v5_max<<"]" << endl;   // ADD BY PENG LI
	sort_max(v5);                   // test the function sort_max using v5
    cout << v5 << endl;             // use the overloaded operator << to display vector v5
    
     // the next line is comment out because there is no element at rank 14 and the program will exit
//	v5.replace_at_rank(14,99.9);     // replace in the vector v5 a character at the rank 14 with 'S'
    
    
    /*****************CHAR**************/
    
    My_vec<char> v6;               // define an object v6 of My_vec type
    v6.insert_at_rank(0,'d');        // insert 'B' at the rank 0 into the vector v6
	cout << v6 << endl;              // use the overloaded operator << to display vector elements
    cout << v6.get_size()<< endl;    // display the vector v6 size
    
    
	v6.insert_at_rank(0,'e');        // insert 'A' at the rank 0 into the vector v6
	cout << v6 << endl;              // use the overloaded operator << to display vector elements
	cout << v6.get_size()<< endl;    // display the vector v6 size
    
	v6.insert_at_rank(10,'z');        // insert 'D' at the rank 10 into the vector v6
	cout << v6 << endl;              // use the overloaded operator << to display vector elements
	cout << v6.get_size()<< endl;    // display the vector v6 size
    
	v6.remove_at_rank(2);            // remove a character at the rank 2 from the vector v6
	cout << v6 << endl;              // use the overloaded operator << to display vector elements
	cout << v6.get_size()<< endl;    // display the vector v6 size
    
	v6.replace_at_rank(2,'f');       // replace a character at the rank 2 by the character 'E'
	cout << v6 << endl;              // use the overloaded operator << to display vector elements
	cout << v6.get_size()<< endl;    // display the vector v6 size
	
	My_vec<char> v7 = v6;          // create a copy v7 of the vector v using a copy constructor
	cout << v7 << endl;             // use the overloaded operator << to display the vector v7
    v7.replace_at_rank(2,'a');      // replace a character at the rank 2 of the vector v7 with the character 'Y'
	cout << v7 << endl;             // use the overloaded operator << to display vector v7 elements
    
	My_vec<char> v8;                      // define an object v8 of My_vec type
	v8.insert_at_rank(0,'e');       // insert 'K' at the rank 0 into the vector v8
	cout << v8 << endl;             // use the overloaded operator << to display vector elements
    cout << v8.get_size() << endl;  // display the vector v8 size
    
    v8 = v7;                        // test the assignment operator and copy the vector v7 to v8
    cout << v8 << endl;             // use the overloaded operator << to display vector v8
    cout << v8.get_size() << endl;  // display the vector v8 size
    
    int v8_max = find_max_index(v2,v2.get_size());// test the function find_max_index using v8
    cout << "v8 find max is: v8[" <<v2_max<<"]" << endl;   // ADD BY PENG LI
	sort_max(v8);                   // test the function sort_max using v8
    cout << v8 << endl;             // use the overloaded operator << to display vector v8
    
    // the next line is comment out because there is no element at rank 14 and the program will exit
//	v8.replace_at_rank(14,'h');     // replace in the vector v2 a character at the rank 14 with 'S'


}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}
