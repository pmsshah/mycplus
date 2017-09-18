#include "stdafx.h"
//list constructors
#include <iostream>
#include <list>
#include <array>

//list constructors
//give constent time insert/erase anywhere.
//double link list. next, prev two pointer maintned.
//forward link list iterate forward only. List can itrate both direction.
//better in performance for inset, extract, moving compare to arrey, vector, deque.
//but worse in accessing direct access. It take liner time from known position to access. 

using namespace std;

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

void myprint(list<int> ls, char *label)
{
	std::cout << "Printing " << label << " : ";
	for (auto x:ls) std::cout << ' ' << x; //print using auto iterator.
	cout << endl;
}


int main ()
{
	// constructors used in the same order as described above:

	std::list<int> first;                      // default: empty
	myprint(first,"First"); //print nothing.

	std::list<int> second (3,77);              // fill: 3 seventy-sevens
	myprint(second,"Second"); //print 77,77,77

	std::list<int> third (second.begin(), second.end()); // range initialization
	myprint(third,"Third"); //print 77,77,77

	std::list<int> fourth (third);            // copy constructor
	myprint(fourth,"Fourth"); //print 77,77,77

	std::list<int> fifth (std::move(fourth));  // move ctor. (fourth wasted)
	myprint(fifth,"Fifth"); //print 77,77,77
	myprint(fourth,"Fourth"); //nothing to proint. 

	//int myints[] = {16,2,77,29};
	//std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) ); //from arrays.
	std::list<int> sixth (3,77);              // fill: 3 seventy-sevens
	sixth.push_front(3);
	sixth.push_front(52);
	sixth.push_back(25);
	sixth.push_back(90);
	//check sixth
	myprint(sixth,"Sixth"); //check sixth

	//use insert.
	std::list<int>::iterator it6;
	it6 = sixth.insert ( sixth.begin(), 10 ); //begin the first
	it6 = sixth.insert ( sixth.begin(), 2, 20 ); //beging the first.
	sixth.front() = 10; //replease first with 10.
	myprint(sixth,"Sixth"); //check sixth
	cout << "Six max size: " << sixth.max_size() << " Size: " << sixth.size() << endl;

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
	std::list< std::pair<int,char> > mylist;
	auto it = mylist.begin();

	it = mylist.emplace ( it, 100, 'x' );
	it = mylist.emplace ( it, 200, 'y' );
	it = mylist.emplace ( it, 300, 'z' );
	mylist.emplace_front(10,'a');
	mylist.emplace_front(20,'b');
	mylist.emplace_front(30,'c');

	std::cout << "mylist contains:";
	for (auto& x: mylist)
	std::cout << " (" << x.first << "," << x.second << ")";

	std::cout << '\n';
	return 0;
}