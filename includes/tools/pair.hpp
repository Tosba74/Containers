/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:51:25 by bmangin           #+#    #+#             */
/*   Updated: 2022/10/06 23:23:41 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/tools.hpp"
#include <utility>

namespace ft {
	template< class T1, class T2>
	struct pair {
		public :
			typedef T1	first_type;
			typedef T2	second_type;
	
			first_type	first;
			second_type	second;
	
			pair() : first(first_type()), second(second_type()) {}
			pair( const T1& x, const T2& y ) : first(x), second(y) {}
			template< class U1, class U2 >
			pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}
			pair( const pair& p ) : first(p.first), second(p.second) {}
		
			pair&	operator=(const pair& other) {
				// (void)other;
				// std::cout << "\e[31m" << "cest bien la" << std::endl;
				if (*this != other) {
					first = other.first;
					second = other.second;
				}
				return *this;
			}
	};

	template< class T1, class T2 >
	pair<T1,T2>		make_pair(T1 t, T2 u) {
		return (pair<T1, T2>(t, u));
	}
	template< class T1, class T2 >
	bool			operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		if (lhs.first > rhs.first)
			return false;
		if (lhs.first < rhs.first)
			return true;
		if (lhs.second > rhs.second)
			return false;
		if (lhs.second < rhs.second)
			return true;
		return false;
	}
	
	template< class T1, class T2 >
	bool		operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }
	
	template< class T1, class T2 >
	bool		operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs == rhs)); }
	
	template< class T1, class T2 >
	bool		operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs > rhs)); }
	
	template< class T1, class T2 >
	bool		operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs == rhs || lhs < rhs)); }
	
	template< class T1, class T2 >
	bool		operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs < rhs)); }

}
