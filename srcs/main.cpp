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
	#include <map/map.hpp>
	#include <stack/stack.hpp>
	#include <vector/vector.hpp>
#endif

#include <list>
#include <stdlib.h>

#define T1 int
#define T2 std::string
typedef ft::map<T1, T2>::value_type T3;
typedef ft::map<T1, T2>::iterator iterator;

// static int g_index = 0;

void	legende() {
	std::cout << "*---+---*" << std::endl;
	std::cout << "| E | S |" << std::endl;
	std::cout << "| M | I |" << std::endl;
	std::cout << "| P | Z |		MAP			|" << std::endl;
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
template <typename T>
std::string		printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	// o << "key: " << iterator.first << " | value: " << iterator.second;
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}
template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename Test1, typename Test2>
void	printReverse(ft::map<Test1, Test2> &mp)
{
	typename ft::map<Test1, Test2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	ft::pair<iterator, bool> tmp;

	// std::cout << "\t-- [" << g_index++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	iterator tmp;

	// std::cout << "\t-- [" << g_index++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}


int		main(void)
{

	// INSERT

	ft::map<T1, T2>		mp;
	ft::map<T1, T2>		mp2;
	std::list<T3> lst;
	std::list<T3>::iterator itlst;

	ft_insert(mp, T3(42, "lol"));
	// ft_insert(mp, T3(42, "mdr"));

	// ft_insert(mp, T3(50, "mdr"));
	// ft_insert(mp, T3(35, "funny"));

	// ft_insert(mp, T3(45, "bunny"));
	// ft_insert(mp, T3(21, "fizz"));
	// ft_insert(mp, T3(38, "buzz"));

	// ft_insert(mp, mp.begin(), T3(55, "fuzzy"));

	// ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
	// ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
	// ft_insert(mp2, mp2.end(), T3(1500, "World"));

	if (CHOICE)
		std::cout << "std (C0)" << std::endl;
	else
		std::cout << "ft (C1)" << std::endl;

	return 0;
}