#include <iostream>
#include <string>
#include <time.h>
#include "lllstr.hpp"
using namespace std;
using namespace str;

const int N_OPS = 1000;

int main(int argc, char *argv[]) {
	lllstr str;
	string sstr;
	int start1, end1, start2, end2;
	double r1, r2;

	//cin >> str;
	//cin.get();
	str = "this is a test of a quite large string";
	sstr = str.cstr();

	cout << "Test 1 (cstr and c_str):";
	cin.get();
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		str.cstr();
	}
	end1 = clock();
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		sstr.c_str();
	}
	end2 = clock();
	r1 = double(end1 - start1) / CLOCKS_PER_SEC;
	r2 = double(end2 - start2) / CLOCKS_PER_SEC;
	cout << "\nResults: lllstr: " << r1 << " seconds, string: " << r2 << " seconds.\n";
	cout << "Test 2 (outputting strings):";
	cin.get();
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		cout << str;
	}
	end1 = clock();
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		cout << sstr;
	}
	end2 = clock();
	r1 = double(end1 - start1) / CLOCKS_PER_SEC;
	r2 = double(end2 - start2) / CLOCKS_PER_SEC;
	cout << "\nResults: lllstr: " << r1 << " seconds, string: " << r2 << " seconds.\n";
	cout << "Test 3 (length):";
	cin.get();
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		str.len();
	}
	end1 = clock();
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		sstr.size();
	}
	end2 = clock();
	r1 = double(end1 - start1) / CLOCKS_PER_SEC;
	r2 = double(end2 - start2) / CLOCKS_PER_SEC;
	cout << "\nResults: lllstr: " << r1 << " seconds, string: " << r2 << " seconds.\n";

	return 0;
}
