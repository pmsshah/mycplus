#include "stdafx.h"
// constructing unordered_maps
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

typedef std::unordered_map<std::string,std::string> stringmap;

stringmap merge (stringmap a,stringmap b) {
	stringmap temp(a); temp.insert(b.begin(),b.end()); return temp;
}

void printmap(stringmap &mymap, char *label)
{
	std::cout << label << " contains:"; //print it.
	for (auto& x: mymap) std::cout << " " << x.first << ":" << x.second <<",";
	std::cout << std::endl;
}

int main ()
{
	stringmap first; //empty map
	first.insert(std::pair<std::string,std::string>("a","a10"));
	first.insert(std::pair<std::string,std::string>("c","c30"));
	first.insert(std::pair<std::string,std::string>("a","a10"));
	first.insert(std::pair<std::string,std::string>("e","e50"));
	first.insert(std::pair<std::string,std::string>("g","g70"));
	first.insert(std::pair<std::string,std::string>("h","h10"));
	first.insert(std::pair<std::string,std::string>("f","f30"));
	first.insert(std::pair<std::string,std::string>("d","d50"));
	first.insert(std::pair<std::string,std::string>("b","b70"));
	first.insert(std::pair<std::string,std::string>("f","f30"));

	std::cout << "First contains:"; //print it.
	for (auto& x: first) std::cout << " " << x.first << ":" << x.second <<",";
	std::cout << std::endl;

	stringmap second (first.begin(),first.end()); //put all elements.
	printmap(second, "Second");

	stringmap  third (second); //construct from second.
	third.insert(std::pair<std::string,std::string>("bb","bb70"));
	third.insert(std::pair<std::string,std::string>("ff","ff30"));
	printmap(third, "Third");

	//simple key,val map intiated,copyed from other map.
	stringmap fourth (merge(first,third));
	printmap(fourth, "Fourth");

	return 0;
}