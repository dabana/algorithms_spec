// Week2_assignement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <array>

int MergeAndCountSplitInversions(const int* B, const int* C, const int n, int* D) {
	int i = 0;
	int j = 0;
	int splitInversions = 0;
	int* DD = new int[n];
	if (n == 2) {
		if (B[i] <= C[j]) {
			DD[0] = B[0];
			DD[1] = C[0];
		}
		else {
			DD[0] = C[0];
			DD[1] = B[0];
			splitInversions++;
		}
	}
	else {
		for (int k = 0; k < n; ++k) {
			if (B[i] <= C[j]) {
				DD[k] = B[i];
				++i;
			}
			else {
				DD[k] = C[j];
				++j;
				splitInversions += (n / 2) - i;
			}
		}
	}
	//Copy the value of DD to D
	for (int l = 0; l < n; ++l) {
		D[l] = DD[l];
	}
	delete[] DD;
	return splitInversions;
}


int SortAndCountInversions(const int* A, const int n, int* D) {
	if (n == 1) {
		D[0] = A[0];
		return 0;
	}
	if (n == 0) {
		return 0;
	}
	else {
		int x = SortAndCountInversions(A, n / 2, D);
		int y = SortAndCountInversions(&A[n / 2], n - (n / 2), &D[n / 2]);
		int z = MergeAndCountSplitInversions(D, &D[n / 2], n, D);
		return x + y + z;
	}
}


int main()
{
	using namespace std;

	ifstream file("integerArray.txt");
	if (file.is_open())
	{
		const int n = 100000;
		int myArray[n];
		int* mySortedArray = new int[n];

		for (int i = 0; i < n; ++i)
		{
			file >> myArray[i];
		}
		int sum = myArray[0] + myArray[n-1];
		cout << myArray[0] << " + " << myArray[n-1] << " = " << sum << endl;
		int inversions = SortAndCountInversions(myArray, n, mySortedArray);
		cout << mySortedArray[0] << " + " << mySortedArray[1] << " = " << " ? " << endl;
		for(int i = 0; i < n / 16; ++i ) {
			cout << mySortedArray[i] << endl;
		}

		cout << "The array contains " << inversions << " inversions." << endl;
		//862840 no good
		delete[] mySortedArray;
 	}

	return 0;
}
