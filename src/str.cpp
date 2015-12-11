#include "str.hpp"
using namespace std;

str::cstr::cstr() : cstr("") {
}

str::cstr::cstr(const char *s) {
	set(s);
}

void str::cstr::set(const char *s) {
	int i = -1;
	char ch;
	while ((ch = s[++i]) != '\0');
	length = i;
	cs = s;
}

int str::cstr::len() const {
	return length;
}

const char* str::cstr::c_str() const {
	return cs;
}

char str::cstr::at(int index) {
	return cs[index];
}

const char str::cstr::at(int index) const {
	return cs[index];
}

ostream& str::operator<<(ostream &out, const cstr &str) {
	out.write(str.c_str(), str.len());
	return out;
}

char str::cstr::operator[](int index) {
	return at(index);
}

const char str::cstr::operator[](int index) const {
	return at(index);
}

void str::cstr::clear() {
	set("");
}

void str::cstr::clean() {
	//Following line causes SEGFAULT (supposedly in lllstr?):
	//delete[] cs;
	cs = nullptr;
}

str::cstr::~cstr() {
	clean();
}
