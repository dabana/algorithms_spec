#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <array>

enum Pivot_choice{
    FIRST,
    LAST,
    MEDIANOF3
};

int median_of_3(int A, int B, int C){
    if A 
}

void swap(int*A, int j, int i){
    int temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

void partition(int* A, int l, int r, Pivot_choice Pivot){
    int p;
    switch (Pivot){
        case FIRST:
            p = A[l];
            break;
        case LAST:
            p = A[r];
        case MEDIANOF3:
            A[l + r / 2]

    }
    
    i = l + 1;
    for (int j = i; j < r; ++j) {
        if (A[j] < pivot) {
            swap(A, j, i);
            i++;
        }
    }
}



int main()
{
	using namespace std;

	ifstream file("QuickSort.txt");
	if (file.is_open())
	{
		const int n = 10000;
		int myArray[n];
		int* mySortedArray = new int[n];
		for (int i = 0; i < n; ++i) {
			mySortedArray[i] = -1;
		}
		
		for (int i = 0; i < n; ++i)
		{
		file >> myArray[i];
		}
		
        //Part 1: Pivot is the first element
		long long comparaisons = QuickSortComparaisons(myArray, n, mySortedArray);
		cout << "Part 1 : There were " << comparaisons << " during the execution of QuickSort." << endl;
		delete[] mySortedArray;
 	}

	return 0;
}
