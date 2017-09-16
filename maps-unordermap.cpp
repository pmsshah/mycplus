#include "stdafx.h"
// constructing unordered_maps
#include <iostream>
#include <string>
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
	first["a"]="a10"; //start adding values.
	first["c"]="c30";
	first["e"]="e50";
	first["g"]="g70";
	first["h"]="h10";
	first["f"]="f30";
	first["d"]="d50";
	first["b"]="b70";

	std::cout << "First contains:"; //print it.
	for (auto& x: first) std::cout << " " << x.first << ":" << x.second <<",";
	std::cout << std::endl;

	stringmap second (first.begin(),first.end()); //put all elements.
	printmap(second, "Second");

	stringmap  third (second); //construct from second.
	printmap(third, "Third");

	//simple key,val map intiated,copyed from other map.
	stringmap fourth (merge(first,third));
	printmap(fourth, "Fourth");

	return 0;
}