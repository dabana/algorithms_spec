#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <array>

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
		long long comparaisons = SortAndCountComparaisons(myArray, n, mySortedArray);
		cout << "Part 1 : There were " << comparaisons << " during the execution of QuickSort." << endl;
		delete[] mySortedArray;
 	}

	return 0;
}
