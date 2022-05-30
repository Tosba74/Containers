/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:35:31 by bmangin           #+#    #+#             */
/*   Updated: 2022/05/23 14:36:17 by bmangin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/iterator_traits.hpp"

template < class Category, class T, class Distance, class Pointer, class Reference >
struct ft::base_iterator
{
	typedef T			value_type;
	typedef Distance 	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category 	iterator_category;
};