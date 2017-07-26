// hb.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
using namespace std;


int IterBiSearch(int data[], const int x, int beg, int last)
{
	int mid;
	mid = (beg + last) / 2;
	if (x == data[mid])
	{
		return mid;
	}
	else if (x < data[mid])
	{
		return IterBiSearch(data, x, beg, mid - 1);
	}
	else if (x > data[mid])
	{
		return IterBiSearch(data, x, mid + 1, last);
	}
	return mid;
}

int _tmain(int argc, char* argv[])
{
	int data1[60] = { 0 };
	int no2search = 45;

	cout << "The array is : " << endl;
	int siz = 60;
	for (int i = 0; i < siz; i++)
	{
		data1[i] = i;
		cout << data1[i] << " ";
	}
	cout << endl;

	int index = -1;
	index = IterBiSearch(data1, no2search, 0, siz);
	cout << "Index of " << no2search << " is " << index << endl;
	getchar();
	return 0;
}
