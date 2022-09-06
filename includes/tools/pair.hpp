/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:51:25 by bmangin           #+#    #+#             */
/*   Updated: 2022/09/05 23:08:02 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/tools.hpp"

namespace ft {
	template <typename K, typename V>
	class pair {
		public:
			K	first;
			V	second;

		//CONSTRUCTEUR
		pair() : first(), second() {}
		pair(K p_key, V p_value) : first(p_key), second(p_value) {}
		pair(ft::pair<K, V> const& cpy) : first(cpy.first), second(cpy.second) {}
		
		//DESTRUCTEUR
		~pair() {}
		
		//OPERATEUR
		pair<K, V>	&operator=(ft::pair<K, V> const& rhs) {
			first = rhs.first;
			second = rhs.second;
			return *this;
		}
		bool	operator==(ft::pair<K, V> const& rhs) {
			return first == rhs.first && second == rhs.second;
		}
		bool	operator!=(ft::pair<K, V> const& rhs) {
			return first != rhs.first || second != rhs.second;
		}
		bool	operator<(ft::pair<K, V> const& rhs) {
			return first < rhs.first ||
				   (first == rhs.first && second < rhs.second);
		}
		bool	operator<=(ft::pair<K, V> const& rhs) {
			return first < rhs.first ||
				   (first == rhs.first && second < rhs.second) ||
				   (first == rhs.first && second == rhs.second);
		}
		bool	operator>(ft::pair<K, V> const& rhs) {
			return first > rhs.first ||
				   (first == rhs.first && second > rhs.second);
		}
		bool	operator>=(ft::pair<K, V> const& rhs) {
			return first > rhs.first ||
				   (first == rhs.first && second > rhs.second) ||
				   (first == rhs.first && second == rhs.second);
		}
		bool	compare(ft::pair<K, V> const& lhs, ft::pair<K, V> const& rhs) {
			return lhs == rhs;
		}
		void	print(void) {
			std::cout << "Key: " << first << " Value: " << second << std::endl;
		}
	};
	
	template< class T1, class T2 >
	pair<T1,T2> make_pair(T1 t, T2 u) { return(pair<T1, T2>(t, u)); }
}