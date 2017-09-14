// main.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>

bool splitcompare(char *src)
{
	int j, len=strlen(src);
	//compare loop
	bool lastcompare=true;
	for(j=0;j<len/2;j++)
	{
		lastcompare=lastcompare&&src[j]==src[len/2+j];
		if(!lastcompare) break;
	}
	if(lastcompare) 
	{
		printf("Repeating String:\n");
		for(j=0;j<len/2;j++) printf("%c",src[j]);
		printf("\n");
	}
	return lastcompare;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Find longest substring. https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
	//Given "abcabcbb", the answer is "abc", which the length is 3.
	//Given "bbbbb", the answer is "b", with the length of 1.
	//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
	char src[] = "bbbbb";
	int i=0,j=0,len = strlen(src);
	char *str1=new char[len+1];

	if(len==1) 
	{
		printf("one size string\n");
	}
	for(i=1;i<len-1;i+=2)
	{
		memset(str1,0,len+1);
		for(j=0;j<i;j++) str1[j]=src[j];
		splitcompare(str1);
	}
	delete str1;
	return 0;
}