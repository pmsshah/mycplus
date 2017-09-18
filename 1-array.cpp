#include "stdafx.h"
// constructing arrays
//fixed size sequence container.
//it is as efficent as array []
//fixed size, dynamicalley do not change size.
//zero size valid, but do not use front, back etc.
//it is tuple object, n-tuple is sequence of n elements.
//how to use iterator?? What is auto??

#include <iostream>
#include <array>
using namespace std;

// default initialization (non-local = static storage):
std::array<int,3> global;               // zero-initialized: {0,0,0}

void myprint(array<int,3> arr, char *label)
{
	std::cout << "Printing " << label << " : ";
	for (auto x:arr) std::cout << ' ' << x;
	cout << endl;
}


int main ()
{
	// default initialization (local = automatic storage):
	std::array<int,3> first;              // uninitialized:    {?,?,?}
	first.fill(0);	//fill not used, compiler will give error.
	myprint(first,"First");
	myprint(global,"Global"); //gloabl alway intialized with defaul value 0.

	std::array<int,3> second = {10,20};   // initialized as:   {10,20,0}
	myprint(second,"Second");
	std::array<int,3> third = {1,2,3};    // initialized as:   {1,2,3}
	myprint(third,"Third");

	std::array<int,3> fourth = third;     // copy third:             {1,2,3}
	std::cout << "Fourth print auto it:";
	for ( auto it = fourth.begin(); it != fourth.end(); ++it )
	std::cout << ' ' << *it;
	std::cout << '\n';

	//print data function.
	std::cout << "Fourth print data function:";
	std::cout << fourth.data(); //for char array it print string, here INT so some junk. 
	std::cout << '\n';

	//print using iterator. 
	std::cout << "Fourth print using iterator:";
	std::array<int,3>::iterator it1;
	for ( it1 = fourth.begin(); it1 != fourth.end(); ++it1 )
	std::cout << ' ' << *it1;
	std::cout << '\n';

	std::array<int,10> myarray;
	unsigned int i;

	// assign some values, i can be used same like array.
	// brecause [] can be used same like array.
	for (i=0; i<10; i++) myarray[i]=i;

	// print content
	std::cout << "myarray contains:";
	for (i=0; i<10; i++)
	std::cout << ' ' << myarray[i];
	std::cout << '\n';

	std::cout << "size of myarray: " << myarray.size() << std::endl; //2nd elements during intialization.
	std::cout << "maxsize of myarray: " << myarray.max_size() << std::endl; //same as size.
	std::cout << "sizeof(myarray): " << sizeof(myarray) << std::endl; //sizof memory. 4*10

  return 0;
}