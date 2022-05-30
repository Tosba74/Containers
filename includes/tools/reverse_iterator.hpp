/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:56:07 by bmangin           #+#    #+#             */
/*   Updated: 2022/05/30 16:12:30 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "tools/iterator_traits.hpp"

namespace ft
{
	template < class Iterator>
	class reverse_iterator
	{
//  ---------------------------    TYPEDEF   ------------------------------ ##
        public:
        	typedef Iterator												iterator_type;
    		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iterator>::reference       reference;
			typedef typename ft::iterator_traits<Iterator>::pointer         pointer;
    
//  ---------------------------   PROTECTED   ----------------------------- ##
		protected:
        	Iterator	current;
			
//  ---------------------------   CONSTUCTOR   ---------------------------- ##
        public:
			reverse_iterator() : current() {};
			explicit reverse_iterator(iterator_type it) : current(it) {};
			reverse_iterator(const reverse_iterator<Iterator>& rev_it) : current(rev_it.current){};
			
//  ---------------------------   DESTUCTOR   ----------------------------- ##

			~reverse_iterator() {}
		
//  ---------------------------   FUNCTION   ------------------------------ ##

			iterator_type base() const { return current; }	

	};
}