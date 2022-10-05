/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:08:16 by bmangin           #+#    #+#             */
/*   Updated: 2022/10/05 22:50:40 by bmangin          ###   ########lyon.fr   */
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
#define T3 char

typedef ft::map<T1, T2>::value_type	T4;
typedef ft::map<T1, T2>::iterator	iterator;
typedef ft::pair<const T1, T2>		T5;
typedef ft::pair<const T3, T1>		T6;

// static int g_index = 0;
/*
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
*/
template <typename T>
std::string		printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout) {
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1) {
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
/*

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
*/

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param) {
	ft::pair<iterator, bool> tmp;

	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2) {
	iterator tmp;

	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}
template <typename MAP, typename U>
void	ft_insert2(MAP &mp, U param, U param2) {
	mp.insert(param, param2);
	printSize(mp);
}
template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param) {
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2) {
	mp.erase(param, param2);
	printSize(mp);
}
template <typename MAP, typename U>
void	ft_erase2(MAP &mp, U param)
{
	std::cout << "ret: " << mp.erase(param) << std::endl;
	printSize(mp);
}
template <class T>
void	is_empty(T const &mp) {
	std::cout << "is_empty: " << mp.empty() << std::endl;
}

int		main(void)
{

	// INSERT

	ft::map<T1, T2>			mp;
	ft::map<T1, T2>			mp2;
	std::list<T4>			lst;
	std::list<T4>::iterator itlst;

	ft_insert(mp, T4(42, "lol"));
	ft_insert(mp, T4(42, "mdr"));

	ft_insert(mp, T4(50, "mdr"));
	ft_insert(mp, T4(35, "funny"));

	ft_insert(mp, T4(45, "bunny"));
	ft_insert(mp, T4(21, "fizz"));
	ft_insert(mp, T4(38, "buzz"));
	
	ft_insert(mp, mp.begin(), T4(55, "fuzzy"));

	ft_insert(mp2, mp2.begin(), T4(1337, "beauty"));
	ft_insert(mp2, mp2.end(), T4(1000, "Hello"));
	ft_insert(mp2, mp2.end(), T4(1500, "World"));

	std::list<T4> 			lst2;
	std::list<T4>::iterator itlst2;

	lst2.push_back(T4(42, "lol"));

	lst2.push_back(T4(50, "mdr"));
	lst2.push_back(T4(35, "funny"));

	lst2.push_back(T4(45, "bunny"));
	lst2.push_back(T4(21, "fizz"));
	lst2.push_back(T4(38, "buzz"));
	lst2.push_back(T4(55, "fuzzy"));

	std::cout << "List contains:" << std::endl;
	for (itlst2 = lst2.begin(); itlst2 != lst2.end(); ++itlst2)
		printPair(itlst2);

	ft::map<T1, T2> mp3;
	ft_insert2(mp3, lst2.begin(), lst2.end());

	lst2.clear();

	lst2.push_back(T4(87, "hey"));
	lst2.push_back(T4(47, "eqweqweq"));
	lst2.push_back(T4(35, "this key is already inside"));
	lst2.push_back(T4(23, "but not that one"));
	lst2.push_back(T4(1, "surprising isnt it?"));
	lst2.push_back(T4(100, "is it enough??"));
	lst2.push_back(T4(55, "inside map too"));

	std::cout << "List contains:" << std::endl;
	for (itlst2 = lst2.begin(); itlst2 != lst2.end(); ++itlst2)
		printPair(itlst2);

	ft_insert2(mp3, lst2.begin(), lst2.begin());
	ft_insert2(mp3, lst2.begin(), lst2.end());

	// ERASE
	std::list<T5>	lst3;

	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
	
		lst3.push_back(T4(i, std::string((lst_size - i), i + 65)));

	ft::map<T1, T2>	mp4(lst3.begin(), lst3.end());
	
	printSize(mp4);

	ft_erase(mp4, ++mp4.begin());
	ft_erase(mp4, mp4.begin());
	ft_erase(mp4, --mp4.end());
	ft_erase(mp4, mp4.begin(), ++(++(++mp4.begin())));
	ft_erase(mp4, --(--(--mp4.end())), --mp4.end());

	mp4[10] = "Hello";
	mp4[11] = "Hi there";
	printSize(mp4);
	ft_erase(mp4, --(--(--mp4.end())), mp4.end());

	mp4[12] = "ONE";
	mp4[13] = "TWO";
	mp4[14] = "THREE";
	mp4[15] = "FOUR";
	printSize(mp4);
	ft_erase(mp4, mp4.begin(), mp4.end());

	std::list<T5>	lst4;

	lst_size = 6;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst4.push_back(T5(i, std::string((lst_size - i), i + 65)));

	ft::map<T1, T2> mp5(lst4.begin(), lst4.end());

	printSize(mp5);

	for (int i = 2; i < 4; ++i)
		ft_erase(mp5, i);
	ft_erase(mp5, mp5.begin()->first);
	ft_erase(mp5, (--mp5.end())->first);
	mp5[-1] = "Hello";
	mp5[10] = "Hi there";
	mp5[10] = "Hi there";
	printSize(mp5);
	ft_erase(mp5, 0);
	ft_erase(mp5, 1);

	// EMPTY
	std::list<T6> lst5;

	lst_size = 15;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst5.push_back(T6('a' + i, lst_size - i));

	ft::map<T3, T1>				mp6(lst5.begin(), lst5.end());
	ft::map<T3, T1>				mp7;
	ft::map<T3, T1>::iterator	it;

	lst5.clear();
	is_empty(mp6);
	printSize(mp6);
	is_empty(mp7);
	mp7 = mp6;
	is_empty(mp7);
	it = mp6.begin();
	for (unsigned long int i = 3; i < mp6.size(); ++i)
		it++->second = i * 7;
	std::cout << "\e[31m" << "Woueshhh!" << "\e[0m" << std::endl;
	printSize(mp6);
	std::cout << "\e[31m" << "Arthoun!" << "\e[0m" << std::endl;
	printSize(mp7);	
	std::cout << "\e[31m" << "Arthoun!" << "\e[0m" << std::endl;

	if (CHOICE)
		std::cout << "std (C0)" << std::endl;
	else
		std::cout << "ft (C1)" << std::endl;

	return 0;
}