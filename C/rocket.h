#ifndef _ROCKET_H_
#define _ROCKET_H_

#include<stdio.h>

//#pragma once
int Max(int a, int b);
int Min(int a, int b);
void PrintArray(int ar[], int left, int right);

int FindMax(int ar[], int left, int right);
int FindSecMax(int ar[], int left, int right);
void ReverseArray(int ar[], int left, int right);
void Sort(int ar[], int left, int right);
int BinSearch(int ar[], int left, int right, int key);

//////////////////////////////////////////////////
int Max(int a, int b)
{
	return a > b ? a : b;
}

int Min(int a, int b)
{
	return a > b ? b : a;
}

void PrintArray(int ar[], int left, int right)
{
	for(int i=left; i<right; ++i)
	{
		printf("%d ",ar[i]);
	}
	printf("\n");
}


int FindMax(int ar[], int left, int right)
{
	int max_value = ar[left]; //³õÊ¼»¯

	for(int i=left+1; i<right; ++i)   //[   )
	{
		if(ar[i] > max_value)
		{
			max_value = ar[i];
		}
	}
	return max_value;
}

int FindSecMax(int ar[], int left, int right)
{
	int first, second;
	if(ar[left] > ar[left+1])
	{
		first = ar[left];
		second = ar[left+1];
	}
	else
	{
		first = ar[left+1];
		second = ar[left];
	}

	for(int i=left+2; i<right; ++i)
	{
		if(ar[i] > first)
		{
			second = first;
			first = ar[i];
		}
		else if(ar[i] > second)
		{
			second = ar[i];
		}
	}
	return second;
}

void ReverseArray(int ar[], int left, int right)
{
	int low = left;
	int high = right - 1;
	while(low < high)
	{
		int tmp = ar[low];
		ar[low] = ar[high];
		ar[high] = tmp;

		low++;
		high--;
	}
}

int Find(int ar[], int left, int right, int key)
{
	for(int i=left; i<right; ++i)
	{
		if(ar[i] == key)
			return i;
	}
	return -1;
}

void Sort(int ar[], int left, int right)
{
	//Ã°ÅÝÅÅÐò
	for (int i = left; i < right-1; i++)
	{
		for (int j = left; j < right+left-1-i; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				int tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
		}
	}
}

int BinSearch(int ar[], int left, int right, int key)
{
	int low = left;
	int high = right - 1;

	while(low <= high)
	{
		int mid = (low + high) / 2;
		if(key == ar[mid])
			return mid;
		else if(key < ar[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

#endif