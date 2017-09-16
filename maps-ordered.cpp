#include "stdafx.h"
// constructing maps
#include <iostream>
#include <map>
// map- impmented as binarey search tree. Sorted by key. All map are sorted.
// Slower then unordered_map.

bool fncomp (char lhs, char rhs) {return lhs>rhs;}

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{return lhs>rhs;}
};

void printmap(std::map<char,int,bool(*)(char,char)> &mymap, char *label)
{
	std::map<char,int,bool(*)(char,char)>::iterator it;
	std::cout << "Printing " << label << std::endl;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	    std::cout << it->first << " => " << it->second << '\n';
}

void printmap(std::map<char,int,classcomp> &mymap, char *label)
{
	std::map<char,int,classcomp>::iterator it;
	std::cout << "Printing " << label << std::endl;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	    std::cout << it->first << " => " << it->second << '\n';
}

void printmap(std::map<char,int> &mymap, char *label)
{
	std::map<char,int>::iterator it;
	std::cout << "Printing " << label << std::endl;
	for (it=mymap.begin(); it!=mymap.end(); ++it)
	    std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
	std::map<char,int> first;	//simple key,val map.

	//add values in diffrent order.
	first['a']=10;
	first['c']=30;
	first['e']=50;
	first['g']=70;
	first['h']=10;
	first['f']=30;
	first['d']=50;
	first['b']=70;

	//see result in ordered format.
	printmap(first, "First");

	//simple ket, val map, intiated from other map.
	std::map<char,int> second (first.begin(),first.end());
	printmap(second, "Second");

	//simple key,val map intiated,copyed from other map.
	std::map<char,int> third (second);
	printmap(third, "Third");

	//pass the compare functions. This will store in decending order.
	std::map<char,int,classcomp> fourth;                 // class as Compare
	fourth['a']=10;
	fourth['c']=30;
	fourth['e']=50;
	fourth['g']=70;
	fourth['h']=10;
	fourth['f']=30;
	fourth['d']=50;
	fourth['b']=70;
	printmap(fourth, "Fourth");

	//pass the compare as pointer to functions. This will store in decending order too.
	bool(*fn_pt)(char,char) = fncomp;
	std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
	fifth['a']=10;
	fifth['c']=30;
	fifth['e']=50;
	fifth['g']=70;
	fifth['h']=10;
	fifth['f']=30;
	fifth['d']=50;
	fifth['b']=70;
	printmap(fifth, "Fifth");

	return 0;
}
