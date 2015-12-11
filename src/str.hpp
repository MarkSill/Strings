#pragma once
#ifndef STR_STR_HPP
#define STR_STR_HPP
#include <iostream>
#include <cstring>

namespace str {
	class cstr {
	public:
		cstr();
		cstr(const char *s);
		~cstr();
		void set(const char *s);
		int len() const;
		const char* c_str() const;
		char at(int index);
		const char at(int index) const;
		std::ostream& operator<<(std::ostream &out);
		char operator[](int index);
		const char operator[](int index) const;
		void clear();
		void clean();

		friend std::ostream& operator<<(std::ostream &out, const cstr &str);
	protected:
		const char *cs;
		int length;
	};

	std::ostream& operator<<(std::ostream &out, const cstr &str);
}

#endif
