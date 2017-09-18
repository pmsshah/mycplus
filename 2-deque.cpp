#include "stdafx.h"
//deque - Double ended queue
//seqeunce container
//dynamic size from both ends.
//access through iterator-random access
//it is similar to vector, but efficent inser/delete at front too
//also vector do continues storage of element, deque do not.
//so accessing element of one pointer offset to other do not work.
//vector and deque implemented diffrentley
//vector continues array, for growth it will be reallocated.
//where as deques elements not store seqeuntialley, but access time is constent.
//deque is more complex internelley, but it grow efficentley. 
//insertion/deleten other then front/back will be expensive in dequeye.
//Sequence: order in stirct linear sequence. Element access by their position, direct access.
//Dynamic array: it is dynamic. Front/end more efficent.
//allocator aware: dynamicalley grow based on need.
// constructing deques
#include <iostream>
#include <deque>
using namespace std;

void myprint(std::deque<int> dq, char *label)
{
	std::cout << "Printing " << label << " : ";
	for (auto x:dq) std::cout << ' ' << x; //print using auto iterator.
	cout << endl;
}


int main ()
{
	// constructors used in the same order as described above:
	std::deque<int> first;                                // empty deque of ints
	myprint(first, "First"); //empty print is OK.

	std::deque<int> second (4,100);                       // four ints with value 100
	myprint(second, "Second"); //will print 4 times 100.

	std::deque<int> third (second.begin(),second.end());  // iterating through second
	myprint(third, "Third"); //will print 4 times 100.

	std::deque<int> fourth (third);                       // a copy of third
	myprint(fourth, "Forth"); //will print 4 times 100.

	// the iterator constructor can be used to copy arrays:
	int myints[] = {16,2,77,29}; 
	std::deque<int> fifth (myints, myints + sizeof(myints) / sizeof(int) ); //16,2,77,29
	fifth.push_back(20);	// add 20 at back //16,2,77,29,20
	fifth.push_front(2);	// add 2 at front //2,16,2,77,29,20
	std::deque<int>::iterator it1 = fifth.begin()+2; //2,16,2,77,29,20
	it1 = fifth.insert (it1,10); //2,16,10, 2,77,29,20
	it1 = fifth.insert (it1,5,100); //2,16,100,100,100,100,100, 10, 2,77,29,20
	//verefy it.
	myprint(fifth, "Fifth"); //will print 2,16,100,100,100,100,100, 10, 2,77,29,20
	std::cout << "Size: " << fifth.size() << endl; // print 12
	if(!fifth.empty())
	{
		std::cout << "Front: " << fifth.front() << endl; // print 2
		std::cout << "Back: " << fifth.back() << endl; // print 20
		fifth.pop_back(); // alwasy check not empty.
		fifth.pop_front(); // always check not empty.
	}
	if(!fifth.empty()) //always check not empty before doing front/back.
	{
		std::cout << "Front: " << fifth.front() << endl; // print 16
		std::cout << "Back: " << fifth.back() << endl; // print 29
	}
	std::cout << "Size: " << fifth.size() << endl; // print 10
	fifth.erase (fifth.begin()+5);
	fifth.erase (it1,it1+4);
	std::cout << "Size: " << fifth.size() << endl; // print 5

	std::cout << "The contents of fifth are:";
	for (std::deque<int>::iterator it = fifth.begin(); it!=fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

  return 0;
}