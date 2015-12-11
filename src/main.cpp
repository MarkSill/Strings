#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "lllstr.hpp"
#include "str.hpp"
using namespace std;
using namespace str;

const int N_OPS = 10000;

double timeElapsed(int start, int end);

int main(int argc, char *argv[]) {
	lllstr lstr;
	string sstr;
	cstr str;
	int start1, end1, start2, end2, start3, end3;
	double r1, r2, r3;

	//cin >>lstr;
	//cin.get();
	lstr = "this is a test of a quite large string";
	sstr = lstr.cstr();
	str = lstr.cstr();

	cout << "Test 1 (cstr and c_str):";
	cin.get();
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		lstr.cstr();
	}
	end1 = clock();
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		sstr.c_str();
	}
	end2 = clock();
	start3 = clock();
	for (int i = 0; i < N_OPS; i++) {
		str.c_str();
	}
	end3 = clock();
	r1 = timeElapsed(start1, end1);
	r2 = timeElapsed(start2, end2);
	r3 = timeElapsed(start3, end3);
	cout << "Results: lllstr: " << r1 << " seconds, string: " << r2 << " seconds, str: " << r3 << " seconds.\n";

	cout << "Test 2 (outputting strings to a stream):";
	cin.get();
	filebuf fb;
	fb.open("outtest", ios::out);
	ostream test(&fb);
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		test << lstr;
	}
	end1 = clock();
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		test << sstr;
	}
	end2 = clock();
	start3 = clock();
	for (int i = 0; i < N_OPS; i++) {
		test << str;
	}
	end3 = clock();
	fb.close();
	r1 = timeElapsed(start1, end1);
	r2 = timeElapsed(start2, end2);
	r3 = timeElapsed(start3, end3);
	cout << "Results: lllstr: " << r1 << " seconds, string: " << r2 << " seconds, str: " << r3 << " seconds.\n";

	cout << "Test 3 (length):";
	cin.get();
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		lstr.len();
	}
	end1 = clock();
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		sstr.length();
	}
	end2 = clock();
	start3 = clock();
	for (int i = 0; i < N_OPS; i++) {
		str.len();
	}
	end3 = clock();
	r1 = timeElapsed(start1, end1);
	r2 = timeElapsed(start2, end2);
	r3 = timeElapsed(start3, end3);
	cout << "Results: lllstr: " << r1 << " seconds, string: " << r2 << " seconds, str: " << r3 << " seconds.\n";

	cout << "Test 4 (getting character from string):";
	cin.get();
	char ch;
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		//ch = lstr[5];
	}
	end1 = clock();
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		ch = sstr[5];
	}
	end2 = clock();
	start3 = clock();
	for (int i = 0; i < N_OPS; i++) {
		ch = str[5];
	}
	end3 = clock();
	r1 = timeElapsed(start1, end1);
	r2 = timeElapsed(start2, end2);
	r3 = timeElapsed(start3, end3);
	cout << "Results: lllstr: " << r1 << " seconds, string: " << r2 << " seconds, str: " << r3 << " seconds.\n";

	return 0;
}

double timeElapsed(int start, int end) {
	return double(end - start) / CLOCKS_PER_SEC;
}
