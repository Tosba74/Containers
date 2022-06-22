/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:55:17 by bmangin           #+#    #+#             */
/*   Updated: 2022/06/11 03:34:51 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
#pragma once

#include <exception>
#include <cstddef>
#include <memory>
#include <stdexcept>
*/

/*
namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag{};
	struct random_access_iterator_tag : public bidirectional_iterator_tag{};
	
## -----------------------------   TEMPLATE   ----------------------------- ##

	template < class Category, class T, class Distance =long, class Pointer = T*, class Reference =T&> struct	base_iterator;
	template < class iterator > class				reverse_iterator;

## ------------------------   STRUCT_ITERATOR_T   ------------------------- ##

	template < typename Iter >
    struct iterator_traits
	{
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
	};

	template < typename Iter_type >
    struct iterator_traits < Iter_type* >
    {
        typedef random_access_iterator_tag			iterator_category;
        typedef Iter_type							value_type;
        typedef std::ptrdiff_t						difference_type;
        typedef Iter_type*							pointer;
        typedef Iter_type&							reference;
    };
    
    template < typename Iter_type >
    struct iterator_traits< const Iter_type* >
    {
        typedef random_access_iterator_tag			iterator_category;
        typedef Iter_type							value_type;
        typedef std::ptrdiff_t						difference_type;
        typedef Iter_type*							pointer;
        typedef Iter_type&							reference;
    };
	
    template < class T >
	struct		iterator_traits< base_iterator< bidirectional_iterator_tag, T > >;
}
*/

// #include "tools/iterator.hpp"
// #include "tools/reverse_iterator.hpp"
/*
namespace ft
{

    struct input_iterator_tag  {};
    struct output_iterator_tag {};
    struct forward_iterator_tag       : public input_iterator_tag         {};
    struct bidirectional_iterator_tag : public forward_iterator_tag       {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};
    
    template < class Iterator >
    struct iterator_traits
    {
        typedef typename Iterator::difference_type          difference_type;
        typedef typename Iterator::value_type               value_type;
        typedef typename Iterator::pointer                  pointer;
        typedef typename Iterator::reference                reference;
        typedef typename Iterator::iterator_category        iterator_category;
    };
    
    template < class T >
    struct iterator_traits < T* >
    {
        typedef ptrdiff_t                   difference_type;
        typedef T                           value_type;
        typedef value_type*                 pointer;
        typedef value_type&                 reference;
        typedef random_access_iterator_tag  iterator_category;
    };
    
    template < class Category, class T, class Distance = ptrdiff_t,
             class Pointer = T*, class Reference = T& >
    struct iterator
    {
        typedef T                           value_type;
        typedef Distance                    difference_type;
        typedef Pointer                     pointer;
        typedef Reference                   reference;
        typedef Category                    iterator_category;
    };
}
*/