#include "stdafx.h"
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>

int binsearch(int arr[], int find_val, int left, int right)
{
	if(left>right) 
		return -1;
	int mid=(left+right)/2;
	if(arr[mid] == find_val)
		return mid;
	else if (arr[mid] > find_val)
		binsearch(arr, find_val, left, mid-1);
	else
		binsearch(arr, find_val, mid+1, right);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//binarey-search. Based on recursive
	int a[] = {0,1,2,3,6,7,8,9,12,53,64,71,84,95,100};
	int loc = binsearch(a,64,0,15);
	printf("Location is %d\n",loc);
	return 0;
}