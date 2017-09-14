#include "stdafx.h"
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//binarey-search. Based on array
	int arr[] = {0,1,2,3,6,7,8,9,12,53,64,71,84,95};
	int find_val=64;
	int left=0;
	int right=14; //array length
	int loc=-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(arr[mid] == find_val)
		{
			loc=mid;
			break;
		}
		else if(arr[mid]>find_val)
			right = mid-1;
		else
			left=mid+1;
	}
	printf("Location is %d\n",loc);
	return 0;
}