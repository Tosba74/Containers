/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:20:06 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/21 17:08:45y bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/nodes.hpp"
#include "tools/exception.hpp"
#include "iterator/iterator.hpp"

namespace ft {

	template <class Key, class T, class Compare = ft::less<K>, class Allocator = std::allocator<ft::pair<const K, V> > >
	class map {
		public:
			typedef Key							key_type;
			typedef T							mapped_type;

			typedef std::pair<const Key, T>		value_type;
			typedef value_type&					reference
			typedef const value_type&			const_reference
			typedef value_type*					pointer
			typedef const value_type*			const_pointer
			typedef std::size_t					size_type;
			typedef std::ptrdiff_t				difference_type;
			typedef alloc						allocator_type;

			class MapIterator : public ft::iterator<std::bidirectional_iterator_tag, value_type> {
				public:
			}
			class MapReverseIterator : public ft::iterator<std::bidirectional_iterator_tag, value_type> {
				public:
			}
			typedef Compare						key_compare;
			typedef MapIterator					iterator;
			typedef const MapIterator			const_iterator;
			typedef MapReverseIterator			reverse_iterator;
			typedef const MapReverseIterator	const_reverse_iterator;

		// CONSTRUCTEUR
			map() {}
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ) {}
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) {}
			map( const map& other ) {}
		// DESTRUCTEUR
			~map();
	
	
	   
	};
}