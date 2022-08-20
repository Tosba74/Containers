/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:47:11 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/20 03:33:21 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/pair.hpp"

#define RED "\e[31m"
#define BLACK "\e[30m"
#define DEFAULT "\e[39m"

enum e_color {
	black,
	red
};

namespace ft {

	template <typename K, typename V>
	class node {
		public:
			ft::pair<const K, V>	pair;
			e_color					color;
			node*					parent;
			node*					left;
			node*					right;
		
		//CONSTRUCTEUR
			node(ft::pair<const K, V>& n_pair) : pair(n_pair), color(black),
				parent(NULL), left(NULL), right(NULL) {}

		//DESTRUCTEUR
			~node(){}
		
		//OPERATEUR
			node*	operator=(node const& cpy){
				pair = cpy.pair
				color = cpy.color
				parent = cpy.parent
				left = cpy.left
				right = cpy.right
				return *this;
			}
		
			bool	operator==(node const& rhs) {
				return (pair == rhs.pair);
			}
			bool	operator!=(node const& rhs) {
				return (pair != rhs.pair);
			}
			bool	operator>=(const node& other) const {
				return (pair >= other.pair);
			}
			bool	operator<=(const node& other) const {
				return (pair <= other.pair);
			}
			bool	operator>(const node& other) const {
				return (pair > other.pair);
			}
			bool	operator<(const node& other) const {
				return (pair < other.pair);
			}
	};
}