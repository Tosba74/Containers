/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:08:16 by bmangin           #+#    #+#             */
/*   Updated: 2022/10/07 01:16:53 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
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
#define T8 foo<float>

typedef ft::map<T1, T2>::value_type	T4;
typedef ft::map<T1, T2>::iterator	iterator;
typedef ft::pair<const T1, T2>		T5;
typedef ft::pair<const T3, T1>		T6;
typedef ft::pair<const T1, T1>		T7;

struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};

typedef ft::map<T1, T2, ft_more> ft_mp;
typedef ft::map<T1, T2, ft_more>::iterator ft_mp_it;

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs) {
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}
template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };
// 
		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

#define T9 foo<int>
typedef ft::map<T1, T9>::value_type			T10;
typedef ft::map<T1, T9>::iterator			ft_iterator;
typedef ft::map<T1, T9>::const_iterator		ft_const_iterator;

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

template <typename T>
T	inc(T it, int n) {
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n) {
	while (n-- > 0)
		--it;
	return (it);
}

void	ft_comp(const ft::map<T3, T8> &mp, const ft::map<T3, T8>::const_iterator &it1, const ft::map<T3, T8>::const_iterator &it2) {
	bool res[2];

	res[0] = mp.key_comp()(it1->first, it2->first);
	// res[1] = mp.value_comp()(*it1, *it2);
	res[1] = 1;
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}
template <typename T>
std::string		printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout) {
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}
template <typename MAP>
void	ft_bound(MAP &mp, const T1 &param) {
	ft::map<T1, T9>::iterator							ite = mp.end();
	ft::map<T1, T9>::iterator							it[2];
	ft::pair<ft::map<T1, T9>::iterator, ft::map<T1, T9>::iterator>	ft_range;

	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param);
	it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
}
template <typename MAP>
void	ft_const_bound(const MAP &mp, const T1 &param) {
	ft_const_iterator								ite = mp.end();
	ft_const_iterator								it[2];
	ft::pair<ft_const_iterator, ft_const_iterator>	ft_range;

	std::cout << "with key [" << param << "]:" << std::endl;
	it[0] = mp.lower_bound(param);
	it[1] = mp.upper_bound(param);
	ft_range = mp.equal_range(param);
	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
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
template <typename MAP>
void	ft_erase_tricky(MAP &mp, const T1 param)
{
	mp.erase(param);
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
		ft_erase2(mp5, i);
	ft_erase2(mp5, mp5.begin()->first);
	ft_erase2(mp5, (--mp5.end())->first);
	mp5[-1] = "Hello";
	mp5[10] = "Hi there";
	mp5[10] = "Hi there";
	printSize(mp5);
	ft_erase2(mp5, 0);
	ft_erase2(mp5, 1);

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

	// CONSTRUCT COPY
	std::list<T7> lst6;
	lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst6.push_back(T7(lst_size - i, i));

	ft::map<T1, T1>					mp8(lst6.begin(), lst6.end());
	ft::map<T1, T1>::iterator		it2 = mp8.begin();
	ft::map<T1, T1>::iterator		it2e = mp8.end();
	ft::map<T1, T1>				mp8_range(it2, --(--it2e));

	for (int i = 0; it2 != it2e; ++it2)
		it2->second = ++i * 5;

	it2 = mp8.begin();
	it2e = --(--mp8.end());
	
	ft::map<T1, T1> mp8_copy(mp8);
	for (int i = 0; it2 != it2e; ++it2)
		it2->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(mp8);
	printSize(mp8_range);
	printSize(mp8_copy);

	mp8 = mp8_copy;
	mp8_copy = mp8_range;
	mp8_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(mp8);
	printSize(mp8_range);
	printSize(mp8_copy);
	
	// COMP
	ft::map<T3,T8>	mp9;

	mp9['a'] = 2.3;
	mp9['b'] = 1.4;
	mp9['c'] = 0.3;
	mp9['d'] = 4.2;
	printSize(mp9);

	for (ft::map<T3, T8>::const_iterator c_it1 = mp9.begin(); c_it1 != mp9.end(); ++c_it1)
		for (ft::map<T3, T8>::const_iterator c_it2 = mp9.begin(); c_it2 != mp9.end(); ++c_it2)
			ft_comp(mp9, c_it1, c_it2);

	printSize(mp9);
	
	// ITERATOR
	ft::map<T1, int> mp10;
	mp10[1] = 2;

	// ft::map<T1, int>::const_iterator iter = mp10.begin();
	// *iter = 42; // < -- error
	
	ft::map<T1, T2> const mp11;
	// ft::map<T1, T2>::iterator iter2 = mp11.begin(); // <-- error expected

	// ft::map<char, int>::iterator			it_test;
	// ft::map<char, float>::const_iterator	ite_test;
// 
	// std::cout << (it_test != ite_test) << std::endl;
	
	/*
	// MORE
	ft_mp	mp_more;

	mp_more[42] = "fgzgxfn";
	mp_more[25] = "funny";
	mp_more[80] = "hey";
	mp_more[12] = "no";
	mp_more[27] = "bee";
	mp_more[90] = "8";
	printSize(mp_more);
	
	// OPERATOR
	ft::map<T3, foo<T2> > mp_op;

	mp_op['a'] = "an element";
	mp_op['b'] = "another element";
	mp_op['c'] = mp_op['b'];
	mp_op['b'] = "old element";

	printSize(mp_op);
	std::cout << "insert a new element via operator[]: " << mp_op['d'] << std::endl;
	printSize(mp_op);	
	
	ft::map<T3, T1> mp_op1;
	ft::map<T3, T1> mp_op2;

	mp_op1['a'] = 2; mp_op1['b'] = 3; mp_op1['c'] = 4; mp_op1['d'] = 5;
	mp_op2['a'] = 2; mp_op2['b'] = 3; mp_op2['c'] = 4; mp_op2['d'] = 5;

	cmp(mp_op1, mp_op1); // 0
	cmp(mp_op1, mp_op2); // 1

	mp_op2['e'] = 6; mp_op2['f'] = 7; mp_op2['h'] = 8; mp_op2['h'] = 9;

	cmp(mp_op1, mp_op2); // 2
	cmp(mp_op2, mp_op1); // 3

	(++(++mp_op1.begin()))->second = 42;

	cmp(mp_op1, mp_op2); // 4
	cmp(mp_op2, mp_op1); // 5

	swap(mp_op1, mp_op2);

	cmp(mp_op1, mp_op2); // 6
	cmp(mp_op2, mp_op1); // 7	
	
	ft::map<T1, int>							mp_op3;
	ft::map<T1, int>::iterator					it_op = mp_op3.begin();
	ft::map<T1, int>::const_iterator			cit_op = mp_op3.begin();

	ft::map<T1, int>::reverse_iterator			rit_op(it_op);

	ft::map<T1, int>::const_reverse_iterator	crit_op(rit_op);
	ft::map<T1, int>::const_reverse_iterator	crit_op_(it_op);
	ft::map<T1, int>::const_reverse_iterator	crit_op_2(cit_op);
*/
	/* error expected
	ft::map<T1, int>::reverse_iterator			rit_op_(crit_op);
	ft::map<T1, int>::reverse_iterator			rit_op2(cit_op);
	ft::map<T1, int>::iterator					it_op2(rit_op);
	ft::map<T1, int>::const_iterator			cit_op2(crit_op);
	*/
/*	
	std::list<T6> lst_op;
	unsigned int lst_op_size = 5;
	for (unsigned int i = 0; i < lst_op_size; ++i)
		lst_op.push_back(T6('a' + i, (i + 1) * 7));

	ft::map<T3, T1>						mp_op4(lst_op.begin(), lst_op.end());
	ft::map<T3, T1>::iterator			it_op2_ = mp_op4.begin();
	ft::map<T3, T1>::reverse_iterator	it_op2(it_op2_);
	ft::map<T3, T1>::reverse_iterator	it_op2e;
	printSize(mp_op4);

	std::cout << (it_op2_ == it_op2.base()) << std::endl;
	std::cout << (it_op2_ == dec(it_op2, 3).base()) << std::endl;

	printPair(it_op2.base());
	printPair(inc(it_op2.base(), 1));

	std::cout << "TEST OFFSET" << std::endl;
	--it_op2;
	printPair(it_op2);
	printPair(it_op2.base());

	it_op2 = mp_op4.rbegin(); it_op2e = mp_op4.rend();
	for (;it_op2 != it_op2e; it_op2++)
		std::cout << "[rev] " << printPair(it_op2, false) << std::endl;
	printReverse(mp_op4);

	// SWAP
	std::list<T6>					lst_sw;

	lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst_sw.push_back(T6('a' + i, lst_size - i));
		
	ft::map<T3, T1>					foo_sw(lst_sw.begin(), lst_sw.end());

	lst_sw.clear();
	lst_size = 4;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst_sw.push_back(T6('z' - i, i * 5));

	ft::map<T3, T1>					bar(lst_sw.begin(), lst_sw.end());
	ft::map<T3, T1>::const_iterator it_foo = foo_sw.begin();
	ft::map<T3, T1>::const_iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo_sw);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	foo_sw.swap(bar);

	std::cout << "AFTER SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo_sw);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << (it_bar == foo_sw.begin()) << std::endl;
	
	// BOUNDS
	std::list<T10>		lstb;
	
	lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lstb.push_back(T10(i + 1, (i + 1) * 3));
		
	ft::map<T1, T9>		mpb(lstb.begin(), lstb.end());
	
	printSize(mpb);
	ft_const_bound(mpb, -10);
	ft_const_bound(mpb, 1);
	ft_const_bound(mpb, 5);
	ft_const_bound(mpb, 10);
	ft_const_bound(mpb, 50);
	printSize(mpb);
	mpb.lower_bound(3)->second = 404;
	mpb.upper_bound(7)->second = 842;
	ft_bound(mpb, 5);
	ft_bound(mpb, 7);
	printSize(mpb);

	// TRICKY
	std::list<T4>			lst_tricky;
	std::list<T4>::iterator itlst_tricky;

	lst_tricky.push_back(T4(42, "lol"));
	lst_tricky.push_back(T4(50, "mdr"));
	lst_tricky.push_back(T4(35, "funny"));
	lst_tricky.push_back(T4(45, "bunny"));
	lst_tricky.push_back(T4(21, "fizz"));
	lst_tricky.push_back(T4(35, "this key is already inside"));
	lst_tricky.push_back(T4(55, "fuzzy"));
	lst_tricky.push_back(T4(38, "buzz"));
	lst_tricky.push_back(T4(55, "inside too"));

	std::cout << "List contains: " << lst_tricky.size() << " elements." << std::endl;
	for (itlst_tricky = lst_tricky.begin(); itlst_tricky != lst_tricky.end(); ++itlst_tricky)
		printPair(itlst_tricky);
	std::cout << "---------------------------------------------" << std::endl;

	ft::map<T1, T2>			mp_tricky(lst_tricky.begin(), lst_tricky.end());
	lst_tricky.clear();

	printSize(mp_tricky);
*/
	ft::map<T1, T2> mp_tricky2;

	mp_tricky2[42] = "lol";

	mp_tricky2[50] = "mdr";
	mp_tricky2[25] = "funny";

	mp_tricky2[46] = "bunny";
	mp_tricky2[21] = "fizz";
	mp_tricky2[30] = "buzz";
	mp_tricky2[55] = "fuzzy";

	mp_tricky2[18] = "bee";
	mp_tricky2[23] = "coconut";
	mp_tricky2[28] = "diary";
	mp_tricky2[35] = "fiesta";
	mp_tricky2[44] = "hello";
	mp_tricky2[48] = "world";
	mp_tricky2[53] = "this is a test";
	mp_tricky2[80] = "hey";

	mp_tricky2[12] = "no";
	mp_tricky2[20] = "idea";
	mp_tricky2[22] = "123";
	mp_tricky2[24] = "345";
	mp_tricky2[27] = "27";
	mp_tricky2[29] = "29";
	mp_tricky2[33] = "33";
	mp_tricky2[38] = "38";

	mp_tricky2[43] = "1";
	mp_tricky2[45] = "2";
	mp_tricky2[47] = "3";
	mp_tricky2[49] = "4";
	mp_tricky2[51] = "5";
	mp_tricky2[54] = "6";
	mp_tricky2[60] = "7";
	mp_tricky2[90] = "8";

	printSize(mp_tricky2);

	/* A classic btree should give this:
	 *                                      42
	 *                     /                                            \
	 *                    25                                            50
	 *           /                 \                         /                       \
	 *          21                 30                       46                       55
	 *      /       \           /      \                /       \             /           \
	 *     18       23        28        35            44         48         53             80
	 *   /   \    /    \    /    \     /   \        /   \       /   \     /    \         /     \
	 *  12   20  22    24  27    29  33    38     43    45    47    49   51    54       60      90
	 *
	 * */

	ft_erase(mp_tricky2, 25); // right != NULL; left != NULL
	ft_erase(mp_tricky2, 55); // right != NULL; left != NULL

	/* After deleting 25 and 55, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    24                                            50
	 *           /                 \                         /                      \
	 *          21                 30                       46                      54
	 *      /       \           /      \                /       \             /           \
	 *     18       23        28        35            44         48         53             80
	 *   /   \    /         /    \     /   \        /   \       /   \     /              /     \
	 *  12   20  22        27    29  33    38     43    45    47    49   51             60      90
	 *
	 * */

	ft_erase(mp_tricky2, 24); // right != NULL; left != NULL
	ft_erase(mp_tricky2, 54); // right != NULL; left != NULL

	/* After deleting 24 and 54, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          21                 30                       46                      53
	 *      /       \           /      \                /       \             /           \
	 *     18       22        28        35            44         48         51             80
	 *   /   \              /    \     /   \        /   \       /   \                    /     \
	 *  12   20            27    29  33    38     43    45    47    49                  60      90
	 *
	 * */

	ft_erase(mp_tricky2, 22); // right == NULL; left == NULL
	ft_erase(mp_tricky2, 51); // right == NULL; left == NULL

	ft_erase(mp_tricky2, 21); // right == NULL; left != NULL
	ft_erase(mp_tricky2, 53); // right != NULL; left == NULL

	/* After deleting 22, 51 and then 21, 53, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          20                 30                       46                      80
	 *      /                   /      \                /       \                /        \
	 *     18                 28        35            44         48             60         90
	 *   /                  /    \     /   \        /   \       /   \
	 *  12                 27    29  33    38     43    45    47    49
	 *
	 * */

	ft_erase(mp_tricky2, 20); // right == NULL; left != NULL

	/* After deleting 20, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    23                                            50
	 *           /                 \                         /                      \
	 *          18                 30                       46                      80
	 *      /                   /      \                /       \                /        \
	 *     12                 28        35            44         48             60         90
	 *                      /    \     /   \        /   \       /   \
	 *                     27    29  33    38     43    45    47    49
	 *
	 * */

	ft_erase(mp_tricky2, 23); // right != NULL; left != NULL

	/* After deleting 23, I would get:
	 *                                      42
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        35            44         48             60         90
	 *                      /    \     /   \        /   \       /   \
	 *                     27    29  33    38     43    45    47    49
	 *
	 * */

	ft_erase(mp_tricky2, 42); // right != NULL; left != NULL; parent == NULL

	/* After deleting 42, I would get:
	 *                                      38
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        35            44         48             60         90
	 *                      /    \     /            /   \       /   \
	 *                     27    29  33           43    45    47    49
	 *
	 * */

	ft_erase(mp_tricky2, 38); // right != NULL; left != NULL; parent == NULL

	/* After deleting 38, I would get:
	 *                                      35
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /      \                /       \                /        \
	 *                        28        33            44         48             60         90
	 *                      /    \                  /   \       /   \
	 *                     27    29               43    45    47    49
	 *
	 * */

	ft_erase(mp_tricky2, 35); // right != NULL; left != NULL; parent == NULL

	/* After deleting 35, I would get:
	 *                                      33
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 30                       46                      80
	 *                          /                       /       \                /        \
	 *                        28                      44         48             60         90
	 *                      /    \                  /   \       /   \
	 *                     27    29               43    45    47    49
	 *
	 * */

	ft_erase(mp_tricky2, 33); // right != NULL; left != NULL; parent == NULL

	/* After deleting 33, I would get:
	 *                                      30
	 *                     /                                            \
	 *                    18                                            50
	 *           /                 \                         /                      \
	 *          12                 28                       46                      80
	 *                          /      \                /       \                /        \
	 *                        27       29             44         48             60         90
	 *                                              /   \       /   \
	 *                                            43    45    47    49
	 *
	 * */
	// getwchar();

	if (CHOICE)
		std::cout << "std (C0)" << std::endl;
	else
		std::cout << "ft (C1)" << std::endl;

	return 0;
}