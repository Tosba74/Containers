/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:26:16 by bmangin           #+#    #+#             */
/*   Updated: 2022/05/30 20:48:27 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/iterator.hpp"
#include "tools/iterator_traits.hpp"
#include "tools/reverse_iterator.hpp"

namespace ft
{
	template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if < true, T >
	{
		typedef T	type;
	};
	
	template < class Iter, class T = void >
	struct	is_iterator {
		static const bool value = false;
	};
	
	template < class Iter >
	struct is_iterator <Iter>
	{
		typedef typename ft::iterator_traits < Iter >::iterator_category category;
		static const bool value = true;
	};
}