/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:32:41 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/20 00:35:10 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <sys/types.h>

namespace ft {

template< class InputIt1, class InputIt2 >
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
{
	for (; first1 != last1; first1++)
	{
		if (*first1 != *first2)
			return false;
		first2++;
	}
	return true;
}

template< class InputIt1, class InputIt2, class BinaryPredicate >
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
{
	for ( ; first1 != last1; first1++)
	{
		if (!p(*first1, *first2))
			return false;
		first2++;
	}
	return true;
}

template< class InputIt1, class InputIt2 >
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
	for ( ; first1 != last1; first1++)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		if (*first1 < *first2)
			return true;
		first2++;
	}
	return (first2 != last2);
}

template< class InputIt1, class InputIt2, class Compare >
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
{
	for ( ; first1 != last1; first1++)
	{
		if (first2 == last2 || comp(*first2, *first1))
			return false;
		if (comp(*first1, *first2))
			return true;
		first2++;
	}
	return true;
}
/*
// SECTION equal
template <class InputIterator1, class InputIterator2>
class equality {
   public:
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
};
template <class InputIterator1, class InputIterator2, class BinaryPredicate>
class predicate {
   public:
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
};
// template <class T>
// int				lexicographical_compare(T const &a, T const &b) {
// 	for (size_t i = 0; i < a.size(); i++) {
// 		if (a[i] < b[i])
// 			return 2;
// 		else if (a[i] != b[i])
// 			return 1;
// 	}
// 	return 0;
// }
*/
template <class T>
struct less : std::binary_function<T, T, bool> {
	bool operator()(const T& x, const T& y) const { return x < y; }
};
// SECTION enable_if
template <bool Cond, class T>
struct enable_if {};

template <class T>
struct enable_if<true, T> { typedef T type; };

// SECTION is_integral
template <typename T>
struct is_integral { static const bool value = false; };
template <>
struct is_integral<bool> { static const bool value = true; };
template <>
struct is_integral<char> { static const bool value = true; };
template <>
struct is_integral<wchar_t> { static const bool value = true; };
template <>
struct is_integral<signed char> { static const bool value = true; };
template <>
struct is_integral<short int> { static const bool value = true; };
template <>
struct is_integral<int> { static const bool value = true; };
template <>
struct is_integral<long int> { static const bool value = true; };
template <>
struct is_integral<long long int> { static const bool value = true; };
template <>
struct is_integral<unsigned char> { static const bool value = true; };
template <>
struct is_integral<unsigned short int> { static const bool value = true; };
template <>
struct is_integral<unsigned int> { static const bool value = true; };
template <>
struct is_integral<unsigned long int> { static const bool value = true; };
template <>
struct is_integral<unsigned long long int> { static const bool value = true; };

}