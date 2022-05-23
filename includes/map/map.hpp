/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:17:49 by bmangin           #+#    #+#             */
/*   Updated: 2022/03/25 22:19:57 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	class map
	{
		// key_type						The first template parameter (Key)	
		// mapped_type					The second template parameter (T)	
		// value_type					pair<const key_type,mapped_type>	
		// key_compare					The third template parameter (Compare)	defaults to: less<key_type>
		// value_compare				Nested function class to compare elements	see value_comp
		// allocator_type				The fourth template parameter (Alloc)	defaults to: allocator<value_type>
		// reference					allocator_type::reference	for the default allocator: value_type&
		// const_reference				allocator_type::const_reference	for the default allocator: const value_type&
		// pointer						allocator_type::pointer	for the default allocator: value_type*
		// const_pointer				allocator_type::const_pointer	for the default allocator: const value_type*
		// iterator						a bidirectional iterator to value_type	convertible to const_iterator
		// const_iterator				a bidirectional iterator to const value_type	
		// reverse_iterator				reverse_iterator<iterator>	
		// const_reverse_iterator		reverse_iterator<const_iterator>	
		// difference_type				a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
		// size_type					an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t
	};
	
}