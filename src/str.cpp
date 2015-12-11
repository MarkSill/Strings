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
	//char *s = new char[length];
	//strcpy(s, cs);
	return cs;
}

char str::cstr::at(int index) {
	return cs[index];
}

const char str::cstr::at(int index) const {
	return cs[index];
}

ostream& str::operator<<(ostream &out, const cstr &str) {
	out << str.cs;
	return out;
}

char str::cstr::operator[](int index) {
	return at(index);
}

const char str::cstr::operator[](int index) const {
	return at(index);
}

void str::cstr::clean() {
	delete[] cs;
}

str::cstr::~cstr() {
	clean();
}
