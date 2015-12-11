#include "lllstr.hpp"
using namespace std;

str::lllstr::lllstr() : lllstr("") {
}

str::lllstr::lllstr(const char *str) {
	head = nullptr;
	set(str);
}

int str::lllstr::len() const {
	return length;
}

const char* str::lllstr::cstr() const {
	node *current = head;
	int l = len();
	char *str = new char[l + 1];

	for (int i = 0; i < l; i++) {
		str[i] = current->data;
		current = current->next;
	}
	str[l] = '\0';

	return str;
}

str::lllstr& str::lllstr::operator=(const lllstr &str) {
	set(str);
	return *this;
}

str::lllstr& str::lllstr::operator=(const char *str) {
	set(str);
	return *this;
}

void str::lllstr::set(const lllstr &str) {
	set(str.cstr());
}

void str::lllstr::set(const char *str) {
	char ch;
	int i = 0;
	node *current;
	node *last = nullptr;

	clean(head);
	while ((ch = str[i++]) != '\0') {
		current = new node;
		current->data = ch;
		current->next = nullptr;
		if (last) {
			last->next = current;
		} else {
			head = current;
		}
		last = current;
	}
	length = i - 1;
}

void str::lllstr::clean(node *n) {
	if (n) {
		clean(n->next);
		delete n;
	}
}

char str::lllstr::at(int index) {
	return at(index);
}

const char str::lllstr::at(int index) const {
	//TODO: Fix function from apparently looping forever...
	node *current = head;
	int i = 0;

	while (i++ < index) {
		current = current->next;
	}

	return current->data;
}

char str::lllstr::operator[](int index) {
	return at(index);
}

const char str::lllstr::operator[](int index) const {
	return at(index);
}

str::lllstr::~lllstr() {
	clean(head);
}

ostream& str::operator<<(ostream &out, const str::lllstr &str) {
	out << str.cstr();
	return out;
}

istream& str::operator>>(istream &in, str::lllstr &str) {
	char ch;
	str.clean(str.head);
	node *current;
	node *last = nullptr;

	while ((ch = in.get()) != '\n' && !in.eof()) {
		current = new node;
		current->data = ch;
		current->next = nullptr;
		if (last) {
			last->next = current;
		} else {
			str.head = current;
		}
		last = current;
	}
	in.unget();

	return in;
}
