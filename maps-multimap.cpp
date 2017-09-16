#include "stdafx.h"
// constructing multimaps
#include <iostream>
#include <map>

bool fncomp (char lhs, char rhs) {return lhs>rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs>rhs;}
};

void printmap(std::multimap<char,int,bool(*)(char,char)> &mymap, char *label)
{
	std::multimap<char,int,bool(*)(char,char)>::iterator it;
	std::cout << "Printing " << label << std::endl;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	    std::cout << it->first << " => " << it->second << '\n';
}
void printmap(std::multimap<char,int,classcomp> &mymap, char *label)
{
	std::multimap<char,int,classcomp>::iterator it;
	std::cout << "Printing " << label << std::endl;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	    std::cout << it->first << " => " << it->second << '\n';
}
void printmap(std::multimap<char,int> &mymap, char *label)
{
	std::multimap<char,int>::iterator it;
	std::cout << "Printing " << label << std::endl;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	    std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  std::multimap<char,int> first;

  first.insert(std::pair<char,int>('a',10));
  first.insert(std::pair<char,int>('b',15));
  first.insert(std::pair<char,int>('b',20));
  first.insert(std::pair<char,int>('c',25));
  printmap(first,"First");

  std::multimap<char,int> second (first.begin(),first.end());
  printmap(second,"Second");

  std::multimap<char,int> third (second);
  printmap(third,"Third");

  std::multimap<char,int,classcomp> fourth;                 // class as Compare
	fourth.insert(std::pair<char,int>('a',10));
	fourth.insert(std::pair<char,int>('b',15));
	fourth.insert(std::pair<char,int>('b',20));
	fourth.insert(std::pair<char,int>('c',25));
 
  printmap(fourth,"Fourth");

  bool(*fn_pt)(char,char) = fncomp;
  std::multimap<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as comp
	fifth.insert(std::pair<char,int>('a',10));
	fifth.insert(std::pair<char,int>('b',15));
	fifth.insert(std::pair<char,int>('b',20));
	fifth.insert(std::pair<char,int>('c',25));
	printmap(fifth,"Fifth");

  return 0;
}