/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:47:11 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/20 03:20:56 by bmangin          ###   ########lyon.fr   */
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
			node() : pair(), color(black), parent(), left(), right() {}
		//DESTRUCTEUR
			~node(){}
	};
}