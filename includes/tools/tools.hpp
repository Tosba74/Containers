/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:32:41 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/27 18:31:30 by bmangin          ###   ########lyon.fr   */
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