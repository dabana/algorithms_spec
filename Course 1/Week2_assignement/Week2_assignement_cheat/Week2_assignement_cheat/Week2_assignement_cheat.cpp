// Week2_assignement_cheat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>

template <typename T>
long long mergeSortAndCountInversions(T* arr, int size)
{
	int m;

	if (size <= 1)
		return 0;

	m = size / 2;

	long long invCountA = 0, invCountB = 0, invCountC = 0;
	invCountA = mergeSortAndCountInversions(arr, m);
	invCountB = mergeSortAndCountInversions(arr + m, size - m);

	T* arrPartA = new T[m];
	T* arrPartB = new T[size - m];

	memcpy(arrPartA, arr, sizeof(T) * m);
	memcpy(arrPartB, arr + m, sizeof(T) * (size - m));

	int i = 0, j = 0, k = 0;

	while (k < size)
	{
		if (arrPartA[i] < arrPartB[j])
		{
			arr[k] = arrPartA[i];
			i++;

			invCountC += j;
		}
		else
		{
			arr[k] = arrPartB[j];
			j++;

			invCountC += 1;
		}

		k++;

		if (i >= m || j >= (size - m))
			break;
	}

	invCountC -= j;

	while (i < m)
	{
		arr[k] = arrPartA[i];
		k++;
		i++;

		invCountC += j;
	}
	while (j < (size - m))
	{
		arr[k] = arrPartB[j];
		k++;
		j++;
	}

	delete[]arrPartA;
	delete[]arrPartB;

	return (invCountA + invCountB + invCountC);
}

int main()
{
	//const int n = 50;
	//int array[n] = { 37, 7, 2, 14, 35, 47, 10, 24, 44, 17, 34, 11, 16, 48, 1, 39, 6, 33, 43, 26, 40, 4, 28, 5, 38, 41, 42, 12, 13, 21, 29, 18, 3, 19, 0, 32, 46, 27, 31, 25, 15, 36, 20, 8, 9, 49, 22, 23, 30, 45 };

	std::ifstream file("integerArray.txt");
	if (file.is_open())
	{

		//int array[100000];
	/*
	for (int i = 0; i < 100000; ++i)
	{
	scanf_s("%d", &array[i]);
	}
	*/
		const int n = 100000;
		int myArray[n];
		for (int i = 0; i < n; ++i)
		{
			file >> myArray[i];
		}
		long long invCount = mergeSortAndCountInversions(myArray, sizeof(myArray) / sizeof(myArray[0]));
		printf("Inversion count: %lld\n", invCount);
	}

	

	return 0;
}