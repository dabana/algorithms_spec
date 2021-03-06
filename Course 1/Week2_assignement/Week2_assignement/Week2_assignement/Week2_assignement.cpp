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
	int k = 0;
	long long splitInversions = 0;
	int* DD = new int[n];
/*
*/	
	if (n == 2) {
		if (B[0] <= C[0]) {
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
		while (i < n / 2 && j < n - n / 2){
			if (B[i] <= C[j]) {
				DD[k] = B[i];
				++i;
				++k;
			}
			else {
				DD[k] = C[j];
				splitInversions += (n / 2) - i;
				++j;
				++k;
			}
		}
		while (k < n) {
			if (i < n / 2) {
				DD[k] = B[i];
				++i;
				++k;
			}
			if(j < n - n / 2) {
				DD[k] = C[j];
				++j;
				++k;
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
	else {
		int* B = new int[n / 2];
		int* C = new int[n - (n / 2)];
		long long x = 0;
		long long y = 0;
		long long z = 0;
		x = SortAndCountInversions(&A[0], n / 2, &B[0]);
		y = SortAndCountInversions(&A[n / 2], n - (n / 2), &C[0]);
		z = MergeAndCountSplitInversions(&B[0], &C[0], n, &D[0]);
		return x + y + z;
		delete[] B;
		delete[] C;
	}

}


int main()
{
	using namespace std;

	ifstream file("integerArray.txt");
	if (file.is_open())
	{
		//const int n = 50;
		//int myArray[n] = { 37, 7, 2, 14, 35, 47, 10, 24, 44, 17, 34, 11, 16, 48, 1, 39, 6, 33, 43, 26, 40, 4, 28, 5, 38, 41, 42, 12, 13, 21, 29, 18, 3, 19, 0, 32, 46, 27, 31, 25, 15, 36, 20, 8, 9, 49, 22, 23, 30, 45 };
		const int n = 100000;
		int myArray[n];
		int* mySortedArray = new int[n];
		for (int i = 0; i < n; ++i) {
			mySortedArray[i] = -1;
		}
		
		for (int i = 0; i < n; ++i)
		{
		file >> myArray[i];
		}
		

		int sum = myArray[0] + myArray[n-1];
		cout << myArray[0] << " + " << myArray[n-1] << " = " << sum << endl;
		long long inversions = SortAndCountInversions(myArray, n, mySortedArray);
		cout << mySortedArray[0] << " + " << mySortedArray[1] << " = " << " ? " << endl;
		/*
		for(int i = 0; i < n; ++i ) {
			cout << mySortedArray[i] << endl;
		}
		*/
		cout << "The array contains " << inversions << " inversions." << endl;
		//862840 no good
		delete[] mySortedArray;
 	}

	return 0;
}
