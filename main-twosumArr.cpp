// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//{2,7,11,15,20};
void twoSum(int *arr, int target)
{
	int i=0;
	int reminderArr[5]={0,0,0,0,0};
	reminderArr[i] = i;
	for(i=1;i<5;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(target == arr[i]+arr[reminderArr[j]])
			{
				cout<< "Target:" << target << ", " << reminderArr[j] << ", " << i << endl;
				return;
			}
		}
		reminderArr[i]=i;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
//Find target of Two sum. https://leetcode.com/problems/two-sum/description/
//Solution with Array

	int arr[5] = {2,7,11,15,20};
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<endl;
	}
	twoSum(arr, 27);
	return 0;
}

