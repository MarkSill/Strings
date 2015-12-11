#pragma once
#ifndef LLLSTR_LLLSTR_HPP
#define LLLSTR_LLLSTR_HPP
#include <iostream>
#include <cstring>

namespace str {
	struct node {
		node *next;
		char data;
	};

	class lllstr {
	public:
		lllstr();
		lllstr(const char *str);
		~lllstr();
		int len() const;
		const char* cstr() const;
		lllstr& operator=(const lllstr &str);
		lllstr& operator=(const char *str);
		void set(const lllstr &str);
		void set(const char *str);
		void clean(node *n);

		friend std::istream& operator>>(std::istream &in, lllstr &str);
	protected:
		node *head;
		int length;
	};

	std::ostream& operator<<(std::ostream &out, const lllstr &str);
	std::istream& operator>>(std::istream &in, lllstr &str);
}

#endif
