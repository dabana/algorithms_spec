// Week1_assignement.cpp : Defines the entry polong long for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

std::string zero_padding(int pad, std::string num) {
	for (long long i = 0; i < pad; ++i) {
		num.push_back('0');
	}
	return num;
}

std::string integerAdd(std::string lrgint, std::string smlint) {
	int hold = 0;
	std::string result = "";
	int pad = lrgint.size() - smlint.size();
	smlint.insert(0, pad, '0');
	for (int i = lrgint.size() - 1; i >= 0; --i) {
		int A = lrgint[i] - '0';
		int B = smlint[i] - '0';
		int C = A + B + hold;
		std::string temp = std::to_string(C);
		if (i > 0) { //check if we are at the end the string
			if (temp.size() > 1) { //hold is different then zero
				hold = temp[0] - '0';
				result = temp[1] + result;
			}
			else { 
				hold = 0;
				result = temp[0] + result;
			}
		}
		else { //end of string
			result = temp + result;
		}

	}
	return result;
}

std::string compute_product(std::string int1, std::string int2) {
	int n = int1.size();

	std::string A = int1.substr(0, n / 2);
	std::string B = int1.substr(n / 2);
	std::string C = int2.substr(0, n / 2);
	std::string D = int2.substr(n / 2);

	if (n / 2 > 3) {
		std::string AC = compute_product(A, C);
		std::string BD = compute_product(B, D);
		//This is with 4 recursive calls
		std::string AD = compute_product(A, D);
		std::string BC = compute_product(B, C);
		std::string zpAC = zero_padding(n, AC);
		std::string zpAD = zero_padding(n / 2, AD);
		std::string zpBC = zero_padding(n / 2, BC);
		//Compute product and send it back as string
		std::string product_str;
		if (zpAD.size() > zpBC.size()) {
			product_str = integerAdd(zpAD, zpBC); //compute term 2
		}
		else {
			product_str = integerAdd(zpBC, zpAD); //compute term 2
		}


		//This is with 3 recursice calls (Karatsuba)
		/*
		std::string AplusB = integerAdd(A, B);
		std::string CplusD = integerAdd(C, D);
		std::string AplusBtimesCplusD = compute_product(AplusB, CplusD);
		//TODO: implement a subtraction algo
		std::string sndterm = integerSub(integerSub(AplusBtimesCplusD, AD), BD);
		std::string product_str = zero_padding(n / 2, sndterm);
		*/

		product_str = integerAdd(zpAC, product_str); //add term 1
		product_str = integerAdd(product_str, BD); //add term 3
		return product_str;
	}
	else{//This is the end case of the recursion

		//compute term 1
		std::string zpA1 = zero_padding(n, A);
		long long intzpA1 = std::stoi(zpA1, nullptr);
		long long intC = std::stoi(C, nullptr);
		long long term1 = intzpA1 * intC;

		//compute term 2
		std::string zpA2 = zero_padding(n / 2, A);
		long long intzpA2 = std::stoi(zpA2, nullptr);
		std::string zpC = zero_padding(n / 2, C);
		long long intzpC = std::stoi(zpC, nullptr);
		long long intB = std::stoi(B, nullptr);
		long long intD = std::stoi(D, nullptr);
		long long term2 = (intzpA2 * intD) + (intB * intzpC);

		//Compute term 3
		long long term3 = intB * intD;

		//Compute product and send it back as string
		long long product = term1 + term2 + term3;
		std::string product_str = std::to_string(product);
		return product_str;
	}

}

int main()
{
	std::string num1 = "3141592653589793238462643383279502884197169399375105820974944592";
	std::string num2 = "2718281828459045235360287471352662497757247093699959574966967627";
	
	//test case
	//std::string num1 = "7878064237045606";
	//std::string num2 = "7349065192669285";
	//THE answer : 57896407670084570194037420411710
	//my answer:   57896406670084570194037420411710

	std::string added = integerAdd(num1, num2);
	std::cout << num1 << " plus " << num2 << " equal " << added << "\n";

	std::string product_str = compute_product(num1, num2);
	std::cout << num1 << " times " << num2 << " equal " << product_str << "\n";

	return 0;
}

