/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:16:06 by bmangin           #+#    #+#             */
/*   Updated: 2022/10/06 21:17:43 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iterator>

namespace ft {

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };
	
	template< class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
	class iterator {
		public :
	
			typedef Category	iterator_category;
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
	
	};
	
	template < class Iter >
	class iterator_traits {
		public :
		
			typedef typename Iter::iterator::iterator_category	iterator_category;
			typedef typename Iter::iterator::value_type			value_type;
			typedef typename Iter::iterator::difference_type	difference_type;
			typedef typename Iter::iterator::pointer			pointer;
			typedef typename Iter::iterator::reference			reference;
	
	};
	
	template < class T >
	class iterator_traits<T*> {
		public :
			typedef random_access_iterator_tag			iterator_category;
			typedef T									value_type;
			typedef std::ptrdiff_t						difference_type;
			typedef const T*							pointer;
			typedef const T&							reference;
	};
	
	template < class Iterator>
	class reverse_iterator {
		public :
			typedef Iterator								iterator_type;
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
	
			reverse_iterator(void) {
				_curr = iterator_type();
			}
			explicit reverse_iterator(iterator_type x) {
				_curr = x;
			}
			template< class U >
			reverse_iterator(const reverse_iterator<U> & rhs) {
				*this = rhs;
			}
			virtual ~reverse_iterator(void) {}
	
			template< class U >
			reverse_iterator& operator=( const reverse_iterator<U>& rhs) {
				_curr = rhs.base();
				return *this;
			}
			iterator_type base() const {
				return _curr;
			}
			reference operator*() const {
			  iterator_type tmp = _curr;
			  return(*(--tmp));
			}
			pointer operator->() const {
				iterator_type tmp = _curr;
				return (&(*(--tmp)));
			}
			reference operator[](difference_type n) const {
				return (_curr[-n - 1]);
			}
			reverse_iterator& operator++() {
				_curr--;
				return *this;
			}
			reverse_iterator& operator--() {
				_curr++;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}
			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}
			reverse_iterator operator+( difference_type n ) const {
				return reverse_iterator(_curr - n);
			}
			reverse_iterator operator-( difference_type n ) const {
				return reverse_iterator(_curr + n);
			}
			reverse_iterator& operator+=( difference_type n ) {
				_curr -= n;
				return *this;
			}
			reverse_iterator& operator-=( difference_type n ) {
				_curr += n;
				return *this;
			}
	
		protected :
			iterator_type	_curr;
	};
	
	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() == rhs.base();
	}
	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() != rhs.base();
	}
	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() < rhs.base();
	}
	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() <= rhs.base();
	}
	template< class Iterator1, class Iterator2 >
	bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() > rhs.base();
	}
	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ) {
		return lhs.base() >= rhs.base();
	}
	
	template< class Iter >
	reverse_iterator<Iter>	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it ) {
		return(reverse_iterator<Iter>(it.base() - n));
	}
	
	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type	operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs ) {
		return (rhs.base() - lhs.base());
	}

}