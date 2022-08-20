/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:08:16 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/17 16:16:31by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <deque>
#define CHOICE 0
#if CHOICE //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	// #include <map/map.hpp>
	#include <stack/stack.hpp>
	#include <vector/vector.hpp>
#endif

#include <list>
#include <stdlib.h>

#define t_stack_ ft::stack<int>
typedef t_stack_::container_type container_type;

void	legende() {
	std::cout << "*---+---*" << std::endl;
	std::cout << "| E | S |" << std::endl;
	std::cout << "| M | I |" << std::endl;
	std::cout << "| P | Z |		STACK		|" << std::endl;
	std::cout << "| T | E |" << std::endl;
	std::cout << "| Y |   |" << std::endl;
	std::cout << "*---+---*" << std::endl;
}
std::ostream&	operator<<(std::ostream& o, const ft::vector<int>& v)
{
	o << "[ ";
	for (ft::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		o << *it << " ";
	o << "]" << std::endl;
	return o;
}
void	prepost_incdec(ft::vector<int> &vct)
{
	ft::vector<int>::iterator it = vct.begin();
	ft::vector<int>::iterator it_tmp;

	std::cout << "Pre inc" << std::endl;
	it_tmp = ++it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Pre dec" << std::endl;
	it_tmp = --it;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post inc" << std::endl;
	it_tmp = it++;
	std::cout << *it_tmp << " | " << *it << std::endl;

	std::cout << "Post dec" << std::endl;
	it_tmp = it--;
	std::cout << *it_tmp << " | " << *it << std::endl;
	std::cout << "###############################################" << std::endl;
}

template <class t_stack>
void	cmp(const t_stack &lhs, const t_stack &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}

template <typename t_stack>
void	printSize(t_stack &stck, bool print_content = 1)
{
	std::cout << "size: " << stck.size() << std::endl;
	if (print_content)
	{
		std::cout << std::endl << "Content was:" << std::endl;
		while (stck.size() != 0) {
			std::cout << "- " << stck.top() << std::endl;
			stck.pop();
		}
	}
	std::cout << "###############################################" << std::endl;
}


int		main(void)
{
	return 0;
}