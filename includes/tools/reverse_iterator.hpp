/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:56:07 by bmangin           #+#    #+#             */
/*   Updated: 2022/06/22 19:03:13 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"

namespace ft
{
    template<class Iterator>
    class reverse_iterator
    {
        protected:
        	Iterator curr;
        public:
        	typedef Iterator												iterator_type;
    		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iterator>::reference       reference;
			typedef typename ft::iterator_traits<Iterator>::pointer         pointer;
    
		reverse_iterator(): curr() {}
		explicit reverse_iterator(iterator_type it) : curr(it) {}
		reverse_iterator(const reverse_iterator<Iterator>& rev_it) : curr(rev_it.curr){}
		~reverse_iterator() {}
		
		iterator_type base() const { return curr; }
	
	//operator
	
		reference operator*() const	{
			Iterator tmp = curr;
        	return *--tmp;
		}
		
		pointer operator->() const {
			return &(operator*());
		}


		reverse_iterator &operator++() {
			--curr;
        	return *this;
		}
		
		reverse_iterator operator++(int) {
  			reverse_iterator temp = *this;
  			--curr;
  			return temp;
		}

		reverse_iterator &operator--() {
			++curr;
        	return *this;
		}
		
		reverse_iterator operator--(int) {
  			reverse_iterator temp = *this;
  			++curr;
  			return temp;
		}

		reverse_iterator operator+(difference_type n) const {
			return(reverse_iterator(curr - n));
		}

		reverse_iterator operator+=(difference_type n) {
			curr -= n;
			return *this;
		}

		reverse_iterator operator-(difference_type n) const {
			return(reverse_iterator(curr + n));
		}

		reverse_iterator operator-=(difference_type n) {
			curr += n;
			return *this;
		}

		reference operator[](difference_type n) const {
			return *(*this + n);
		}

	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,	const reverse_iterator<Iterator>& rhs) {
		return (lhs.base()==rhs.base());
	}
		
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base()!=rhs.base());
	}	
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base()<rhs.base());
	}
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base()<=rhs.base());
	}	
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base()>rhs.base());
	}
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base()>=rhs.base());
	}
}