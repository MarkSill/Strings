#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "lllstr.hpp"
#include "str.hpp"
using namespace std;
using namespace str;

const int N_OPS = 1000000;

double timeElapsed(int start, int end);
void winner(double str, double cstr);
void winner(double lstr, double str, double cstr);

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
	cout << "lllstr...";
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		lstr.cstr();
	}
	end1 = clock();
	cout << " done!\nstring...";
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		sstr.c_str();
	}
	end2 = clock();
	cout << " done!\ncstr...";
	start3 = clock();
	for (int i = 0; i < N_OPS; i++) {
		str.c_str();
	}
	end3 = clock();
	cout << " done!\n";
	r1 = timeElapsed(start1, end1);
	r2 = timeElapsed(start2, end2);
	r3 = timeElapsed(start3, end3);
	cout << "Results: lllstr: " << r1 << " seconds, string: " << r2 << " seconds, cstr: " << r3 << " seconds.\n";
	winner(r1, r2, r3);

	cout << "\nTest 2 (outputting strings to a stream):";
	cin.get();
	cout << "lllstr...";
	filebuf fb;
	fb.open("outtest", ios::out);
	ostream test(&fb);
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		test << lstr;
	}
	end1 = clock();
	cout << " done!\nstring...";
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		test << sstr;
	}
	end2 = clock();
	cout << " done!\ncstr...";
	start3 = clock();
	for (int i = 0; i < N_OPS; i++) {
		test << str;
	}
	end3 = clock();
	cout << " done!\n";
	fb.close();
	r1 = timeElapsed(start1, end1);
	r2 = timeElapsed(start2, end2);
	r3 = timeElapsed(start3, end3);
	cout << "Results: lllstr: " << r1 << " seconds, string: " << r2 << " seconds, cstr: " << r3 << " seconds.\n";
	winner(r1, r2, r3);

	cout << "\nTest 3 (length):";
	cin.get();
	cout << "lllstr...";
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		lstr.len();
	}
	end1 = clock();
	cout << " done!\nstring...";
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		sstr.length();
	}
	end2 = clock();
	cout << " done!\ncstr...";
	start3 = clock();
	for (int i = 0; i < N_OPS; i++) {
		str.len();
	}
	end3 = clock();
	cout << " done!\n";
	r1 = timeElapsed(start1, end1);
	r2 = timeElapsed(start2, end2);
	r3 = timeElapsed(start3, end3);
	cout << "Results: lllstr: " << r1 << " seconds, string: " << r2 << " seconds, cstr: " << r3 << " seconds.\n";
	winner(r1, r2, r3);

	cout << "\nTest 4 (getting character from string):";
	cin.get();
	cout << "lllstr...";
	char ch;
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		ch = lstr[5];
	}
	end1 = clock();
	cout << " done!\nstring...";
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		ch = sstr[5];
	}
	end2 = clock();
	cout << " done!\ncstr...";
	start3 = clock();
	for (int i = 0; i < N_OPS; i++) {
		ch = str[5];
	}
	end3 = clock();
	cout << " done!\n";
	r1 = timeElapsed(start1, end1);
	r2 = timeElapsed(start2, end2);
	r3 = timeElapsed(start3, end3);
	cout << "Results: lllstr: " << r1 << " seconds, string: " << r2 << " seconds, cstr: " << r3 << " seconds.\n";
	winner(r1, r2, r3);

	cout << "\nTest 5 (size):\n";
	cin.get();
	cout << "Results: lllstr: " << sizeof(lstr) << " bytes, string: " << sizeof(sstr) << " bytes, cstr: " << sizeof(str) << " bytes.\n";

	cout << "\nTest 6 (assigning strings):\n";
	cin.get();
	cout << "lllstr...";
	start1 = clock();
	for (int i = 0; i < N_OPS; i++) {
		lstr = "this is a test of a quite large string";
	}
	end1 = clock();
	cout << " done!\nstring...";
	start2 = clock();
	for (int i = 0; i < N_OPS; i++) {
		sstr = "this is a test of a quite large string";
	}
	end2 = clock();
	cout << " done!\ncstr...";
	start3 = clock();
	for (int i = 0; i < N_OPS; i++) {
		str.set("this is a test of a quite large string");
	}
	end3 = clock();
	cout << " done!\n";
	r1 = timeElapsed(start1, end1);
	r2 = timeElapsed(start2, end2);
	r3 = timeElapsed(start3, end3);
	cout << "Results: lllstr: " << r1 << " seconds, string: " << r2 << " seconds, cstr: " << r3 << " seconds.\n";
	winner(r1, r2, r3);
	cin.get();
	return 0;
}

double timeElapsed(int start, int end) {
	return double(end - start) / CLOCKS_PER_SEC;
}

void winner(double str, double cstr) {
	winner(1000000, str, cstr);
}

void winner(double lstr, double str, double cstr) {
	cout << "The winner is ";
	if (lstr < str && lstr < cstr) {
		cout << "lllstr";
	} else if (str < lstr && str < cstr) {
		cout << "string";
	} else if (cstr < lstr && cstr < str) {
		cout << "cstr";
	} else {
		cout << "a tie";
	}
	cout << "!\n";
}
