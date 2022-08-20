/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:51:25 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/20 03:06:53 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/tools.hpp"

namespace ft {
	template <typename K, typename V>
	class pair {
		public:
			K	key;
			V	value;
		//CONSTRUCTEUR
		pair() : key(), value() {}
		pair(K p_key, V p_value) : key(p_key), p_value(p_value) {}
		pair(ft::par<K, V> const& cpy) : key(cpy.key), value(cpy.value) {}
		
		//DESTRUCTEUR
		~pair() {}
		
		//OPERATEUR
		pair<K, V> &operator=(ft::pair<K, V> const& rhs) {
			this->key = rhs.key;
			this->value = rhs.value;
			return *this;
		}
		bool operator==(ft::pair<K, V> const& rhs) {
			return this->first == rhs.first && this->second == rhs.second;
		}
		bool operator!=(ft::pair<K, V> const& rhs) {
			return this->first != rhs.first || this->second != rhs.second;
		}
		bool operator<(ft::pair<K, V> const& rhs) {
			return this->first < rhs.first ||
				   (this->first == rhs.first && this->second < rhs.second);
		}
		bool operator<=(ft::pair<K, V> const& rhs) {
			return this->first < rhs.first ||
				   (this->first == rhs.first && this->second < rhs.second) ||
				   (this->first == rhs.first && this->second == rhs.second);
		}
		bool operator>(ft::pair<K, V> const& rhs) {
			return this->first > rhs.first ||
				   (this->first == rhs.first && this->second > rhs.second);
		}
		bool operator>=(ft::pair<K, V> const& rhs) {
			return this->first > rhs.first ||
				   (this->first == rhs.first && this->second > rhs.second) ||
				   (this->first == rhs.first && this->second == rhs.second);
		}
	};
}