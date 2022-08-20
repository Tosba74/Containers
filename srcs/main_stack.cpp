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
	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST STACK DEFAULT COPY" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_		stck(ctnr);

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);

	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck.empty() << std::endl;
	printSize(stck);	

	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST STACK DEFAULT" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	ft::stack<int> stck2;

	std::cout << "empty: " << stck2.empty() << std::endl;
	std::cout << "size: " << stck2.size() << std::endl;

	stck2.push(41);
	stck2.push(29);
	stck2.push(10);
	stck2.push(42);
	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck2.empty() << std::endl;
	printSize(stck2);

	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST STACK LIST COPY" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	container_type	ctnr1;

	ctnr1.push_back(21);
	ctnr1.push_back(42);
	ctnr1.push_back(1337);
	ctnr1.push_back(19);
	ctnr1.push_back(0);
	ctnr1.push_back(183792);

	t_stack_		stck1(ctnr1);

	std::cout << "empty: " << stck1.empty() << std::endl;
	std::cout << "size: " << stck1.size() << std::endl;

	stck1.push(1);
	stck1.push(2);
	stck1.push(3);
	stck1.push(4);
	stck1.push(5);
	stck1.push(6);

	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck1.empty() << std::endl;
	printSize(stck1);

	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST STACK LIST OPER" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	container_type	ctnr3;

	ctnr3.push_back(21);
	ctnr3.push_back(42);
	ctnr3.push_back(1337);
	ctnr3.push_back(19);
	ctnr3.push_back(0);
	ctnr3.push_back(183792);

	t_stack_	stack(ctnr3);
	t_stack_	stack2(ctnr3);

	cmp(stack, stack);  // 0
	cmp(stack, stack2); // 1

	stack2.push(60);
	stack2.push(61);
	stack2.push(62);

	cmp(stack, stack2); // 2
	cmp(stack2, stack); // 3

	stack.push(42);

	cmp(stack, stack2); // 4
	cmp(stack2, stack); // 5

	stack.push(100);

	cmp(stack, stack2); // 6
	cmp(stack2, stack); // 7

	std::cout << "----------------------------------" << std::endl;
	std::cout << "TEST STACK OPER RELAT" << std::endl;
	std::cout << "----------------------------------" << std::endl;

container_type	ctnr4;

	ctnr4.push_back(21);
	ctnr4.push_back(42);
	ctnr4.push_back(1337);
	ctnr4.push_back(19);
	ctnr4.push_back(0);
	ctnr4.push_back(183792);

	t_stack_	sstack(ctnr4);
	t_stack_	sstack2(ctnr4);

	cmp(sstack, sstack);  // 0
	cmp(sstack, sstack2); // 1

	sstack2.push(60);
	sstack2.push(61);
	sstack2.push(62);

	cmp(sstack, sstack2); // 2
	cmp(sstack2, sstack); // 3

	sstack.push(42);

	cmp(sstack, sstack2); // 4
	cmp(sstack2, sstack); // 5

	sstack.push(100);

	cmp(sstack, sstack2); // 6
	cmp(sstack2, sstack); // 7

	if (CHOICE)
		std::cout << "std (C0)" << std::endl;
	else
		std::cout << "ft (C1)" << std::endl;

	return 0;
}
