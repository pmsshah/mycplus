#include "stdafx.h"
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	//Sort the list. Ask values, and sort the array. 
	int arr[50];
	int i,j;
	int len =10;
	for (i=0;i<len;i++)
		scanf_s("%d", &arr[i]);
	printf("Given List:\n");
	for (i=0;i<len;i++)
		printf("%d ", arr[i]);
	printf("\n");
	for (i=0;i<len;i++)
	{
		for (j=0;j<len-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("Sorted List:\n");
	for (i=0;i<len;i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}