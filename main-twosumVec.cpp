// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

void twoSum(vector<int>& a, int target) {
    vector<int>::const_iterator j,i=a.begin();
	vector<int> reminderArr;
	reminderArr.push_back(*i);
	for(; i!=a.end(); i++)
	{
		for(j=reminderArr.begin(); j!=reminderArr.end(); j++)
		{
			if(target == *i+*j)
			{
				cout<< "Target:" << target << ", " << *j << ", " << *i << endl;
				return;
			}
		}
		reminderArr.push_back(*i);
	}
	/*
    for(i=a.begin(); i!=a.end(); ++i){
        cout<<(*i)<<std::endl;
    }
	*/
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
//Find target of Two sum. https://leetcode.com/problems/two-sum/description/
//Solution with Vector
	int arr[5] = {2,7,11,15,20};
	vector<int> a(arr,arr+5);
 	twoSum(a,27);
	return 0;
}

