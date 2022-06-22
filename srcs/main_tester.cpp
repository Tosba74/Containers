#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <stack>
#include <vector>
#include "map/map.hpp"
#include "stack/stack.hpp"
#include "vector/vector.hpp"
#include <stdlib.h>

void	sommaire() {
	std::cout << "*---+---+---*" << std::endl;
	std::cout << "| E | C | S |" << std::endl;
	std::cout << "| M | A | I |" << std::endl;
	std::cout << "| P | P | Z |		VECTOR		|" << std::endl;
	std::cout << "| T | A | E |" << std::endl;
	std::cout << "| Y | C |   |" << std::endl;
	std::cout << "*---+---+---*" << std::endl;
}

void	check(bool success)
{
	if (success)
		std::cout << "\e[32m[√] \e[0m" << std::endl;
	else {
		std::cout << "\e[31m[X]\e[0m" << std::endl;
		sommaire();
		std::cout << ret_std << std::endl << ret_ft << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& o, const ft::vector<int>& v)
{
	o << "| " << v.empty() << " | " << v.capacity() << " | " << v.size() << " |	";
	o << "[ ";
	for (ft::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		o << *it << " ";
	o << "]" << std::endl;
	return o;
}

bool	fttostd(const std::ostringstream& ret_ft, const std::ostream& ret_std) {
	// ret_ft = ft::func();
	ret_ft << "oui";
	ret_std << "oui";
	// ret_std = std::func();
	if (ret_ft == ret_std)
		return true;
	return false;
}


int main(void)
{
	std::ostream	ret_std;
	std::ostream	ret_ft;

	check(!fttostd(ret_ft, ret_std));
	return 0;
}