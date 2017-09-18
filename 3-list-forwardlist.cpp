#include "stdafx.h"
// forward_list constructors
#include <iostream>
#include <forward_list>
#include <array>

//forward_list constructors
//give constent time insert/erase anywhere.
//only iterated forward, only keep next element.
//list keep next, prev two pointers where as this one only next,
//better in performance for inset, extract, moving compare to arrey, vector, deque.
//but worse in accessing direct access
//do not have size function, you can use distance function. it will travel fron beg to end.
//

using namespace std;

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

void myprint(forward_list<int> fl, char *label)
{
	std::cout << "Printing " << label << " : ";
	for (auto x:fl) std::cout << ' ' << x; //print using auto iterator.
	cout << endl;
}


int main ()
{
	// constructors used in the same order as described above:

	std::forward_list<int> first;                      // default: empty
	myprint(first,"First"); //print nothing.

	std::forward_list<int> second (3,77);              // fill: 3 seventy-sevens
	myprint(second,"Second"); //print 77,77,77

	std::forward_list<int> third (second.begin(), second.end()); // range initialization
	myprint(third,"Third"); //print 77,77,77

	std::forward_list<int> fourth (third);            // copy constructor
	myprint(fourth,"Fourth"); //print 77,77,77

	std::forward_list<int> fifth (std::move(fourth));  // move ctor. (fourth wasted)
	myprint(fifth,"Fifth"); //print 77,77,77
	myprint(fourth,"Fourth"); //nothing to proint. 

	//std::forward_list<int> sixth = {3, 52, 25, 90};    // initializer_list constructor
	std::forward_list<int> sixth(3, 33); //3 times 33.
	sixth.push_front(3);
	sixth.push_front(52);
	sixth.push_front(25);
	sixth.push_front(90);
	//check sixth
	myprint(sixth,"Sixth"); //check sixth

	//use insert.
	std::forward_list<int>::iterator it6;
	it6 = sixth.insert_after ( sixth.begin(), 10 ); //begin the first
	it6 = sixth.insert_after ( sixth.before_begin(), 2, 20 ); //beging the 0.
	sixth.front() = 10; //replease first with 10.
	myprint(sixth,"Sixth"); //check sixth
	int maxsize= sixth.max_size();
	cout << "Six max size: " << maxsize << endl;

	//print all.
	std::cout << "first:" ; for (int& x: first)  std::cout << " " << x; std::cout << '\n';
	std::cout << "second:"; for (int& x: second) std::cout << " " << x; std::cout << '\n';
	std::cout << "third:";  for (int& x: third)  std::cout << " " << x; std::cout << '\n';
	std::cout << "fourth:"; for (int& x: fourth) std::cout << " " << x; std::cout << '\n';
	std::cout << "fifth:";  for (int& x: fifth)  std::cout << " " << x; std::cout << '\n';
	std::cout << "sixth:";  for (int& x: sixth)  std::cout << " " << x; std::cout << '\n';

	sixth.sort();
	myprint(sixth,"Sixth sorted"); //print sixth sorted.
	third.sort();
	myprint(third,"Third sorted"); //print sixth sorted.
	sixth.merge(third); //third removed and copied in ordered way in sixth.
	myprint(sixth,"Sixth Merged"); //print sixth sorted, can't print third.
	myprint(third,"Third empty"); //if you merge without order, it will crach.
	sixth.unique();
	myprint(sixth,"Sixth Removed duplicate"); //print sixth sorted, can't print third.
	sixth.reverse();
	myprint(sixth,"Sixth Reversed"); //print sixth sorted, can't print third.
	sixth.remove_if (single_digit); //remove all single digit.
	myprint(sixth,"Sixth without single digit"); //sixth without single digit.

//inserting pairs
	std::forward_list< std::pair<int,char> > mylist;
	auto it = mylist.before_begin();

	it = mylist.emplace_after ( it, 100, 'x' );
	it = mylist.emplace_after ( it, 200, 'y' );
	it = mylist.emplace_after ( it, 300, 'z' );
	mylist.emplace_front(10,'a');
	mylist.emplace_front(20,'b');
	mylist.emplace_front(30,'c');

	std::cout << "mylist contains:";
	for (auto& x: mylist)
	std::cout << " (" << x.first << "," << x.second << ")";

	std::cout << '\n';
	return 0;
}