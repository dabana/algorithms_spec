// Week3_assignement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <array>

enum Pivot_choice {
	FIRST,
	LAST,
	MEDIANOF3
};

int median_of_3(int A, int B, int C) {
	if ((A >= B && A <= C) || (A >= C && A <= B)) return A;
	if ((B >= C && B <= A) || (B >= A && B <= C)) return B;
	if ((C >= A && C <= B) || (C >= B && C <= A)) return C;
}

void swap(int*A, int j, int i) {
	int temp = A[j];
	A[j] = A[i];
	A[i] = temp;
}

int ChoosePivot(int* A, int n, Pivot_choice Pivot) {
	switch (Pivot) {
	case FIRST:
		return A[0];
	case LAST:
		return A[n];
	case MEDIANOF3:
		return median_of_3(A[n / 2], A[0], A[n]);
	}
}

int partition(int* A, int l, int r, int p) {
	int i = l + 1;
	for (int j = i; j < r; ++j) {
		if (A[j] < p) {
			swap(A, j, i);
			i++;
		}
	}
	return i;
}

long long QuickSort(int* A, int n, Pivot_choice Pivot) {
	if (n == 1) return 0;
	else {
		int p = ChoosePivot(A, n, Pivot);
		int i = partition(A, A[0], A[n], p);
		long long x = QuickSort(&A[0], 0, Pivot);
	}
	return x + y;
}


int main()
{
	using namespace std;

	ifstream file("QuickSort.txt");
	if (file.is_open())
	{
		const int n = 10000;
		int myArray[n];
		for (int i = 0; i < n; ++i)
		{
			file >> myArray[i];
		}

		//Part 1: Pivot is the first element
		long long comparaisons = QuickSort(myArray, n, FIRST);
		cout << "Part 1 : There were " << comparaisons << " during the execution of QuickSort." << endl;
	}

	return 0;
}
