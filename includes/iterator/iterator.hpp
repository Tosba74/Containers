/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:16:06 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/17 10:00:32 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iterator>

namespace ft {
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator {
	   public:
		typedef Category		iterator_category;
		typedef T				value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer_it;
		typedef Reference		reference;
	};
	
	template <class T>
	class iterator_traits {
		public:
			typedef typename T::iterator::difference_type		difference_type;
			typedef typename T::iterator::value_type			value_type;
			typedef typename T::iterator::pointer_it			pointer;
			typedef typename T::iterator::reference				reference;
			typedef typename T::iterator::iterator_category		iterator_category;
	};
}