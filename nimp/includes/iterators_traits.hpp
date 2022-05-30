/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:55:17 by bmangin           #+#    #+#             */
/*   Updated: 2022/05/19 11:25:46 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <cstddef>
#include <memory>
#include <stdexcept>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag{};
	struct random_access_iterator_tag : public bidirectional_iterator_tag{};
	
/* -----------------------------   TEMPLATE   ----------------------------- */

	template<class Category, class T, class Distance =long, class Pointer = T*,
		class Reference =T&> struct	base_iterator;
	
	template <class iterator> class	reverse_iterator;

/* ------------------------   MEMBER FUNCTIONS   -------------------------- */

	template <typename Iter>
    struct iterator_traits
	{
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
	}

}
