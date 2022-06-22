/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:56:07 by bmangin           #+#    #+#             */
/*   Updated: 2022/06/22 14:50:32 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/iterator.hpp"
#include "tools/iterator_traits.hpp"

/*
namespace ft
{
	template < class Iterator>
	class reverse_iterator
	{
//  ---------------------------    TYPEDEF   ------------------------------ ##
        public:
        	typedef Iterator												iterator_type;
    		typedef typename iterator_traits<Iterator>::difference_type 	difference_type;
			typedef typename iterator_traits<Iterator>::reference       	reference;
			typedef typename iterator_traits<Iterator>::pointer         	pointer;
    
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

#include <vector>
#include <iostream>
#include "iterator.hpp"

namespace ft {
    template <typename Iterator>
    class reverse_iterator
    {
        public:
//  ----------------------------   TYPEDEF   ------------------------------ ##
		
			typedef typename iterator_traits<Iterator>::value_type		    value_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
            typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::reference			reference;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;

		private:
			Iterator	_curr;

        public:
//  ---------------------------   CONSTUCTOR   ---------------------------- ##

            reverse_iterator() {}
            reverse_iterator(Iterator it) : _curr(it) {}
			template < typename Iter >
            reverse_iterator(const reverse_iterator < Iter > & rev_it) : _curr(rev_it.base()) {}
			template < typename Iter >
			reverse_iterator&		operator=(const reverse_iterator<Iter> &u) {
				_curr = u.base();
				return *this;
			}

//  ----------------------------   DESTUCTOR   ---------------------------- ##
            ~reverse_iterator() {}

//  ----------------------------   DESTUCTOR   ---------------------------- ##

            Iterator				base() const { return (_curr); }
            reference				operator*() const {
				Iterator	tmp = _curr;
				return *(--tmp);
			}
            reverse_iterator		operator+(difference_type n) { return(reverse_iterator(_curr - n)); }
            reverse_iterator&		operator++() {
                this->_curr--;
				return(*this);
            }
            reverse_iterator		operator++(int) {
                reverse_iterator	tmp(*this);
				operator++();
				return tmp;
			}
            reverse_iterator&		operator+=(difference_type n) {
                _curr -= n;
				return *this;
            }
            reverse_iterator		operator-(difference_type n) {
				return(reverse_iterator(_curr + n));
            }
            reverse_iterator &		operator--() {
                this->_curr++;
				return(*this);
            }            
            reverse_iterator		operator--(int) {
                reverse_iterator tmp = *this;
				this->_curr++;
				return(tmp);
            }
            reverse_iterator&		operator-=(difference_type n) {
                _curr += n;
				return *this;
            }
            pointer					operator->() const { return &(operator*()); }
            reference				operator[](difference_type n) const { return this->_curr[-n - 1];}

    };

	template < typename U, typename V >
	bool	operator==(const reverse_iterator < U >& lhs, const reverse_iterator < V > & rhs) {
		return lhs.base() == rhs.base();
	}

	template < typename U, typename V >
	bool	operator!=(const reverse_iterator < U >& lhs, const reverse_iterator < V > & rhs) {
		return lhs.base() != rhs.base();
	}

	template < typename U, typename V >
	bool		operator>(const reverse_iterator < U >& lhs, const reverse_iterator < V > & rhs) {
		return lhs.base() < rhs.base();
	}

	template < typename U, typename V >
	bool		operator<(const reverse_iterator < U >& lhs, const reverse_iterator < V > & rhs) {
		return lhs.base() > rhs.base();
	}

	template < typename U, typename V >
	bool		operator>=(const reverse_iterator<U>& lhs, const reverse_iterator<V>& rhs) {
		return lhs.base() <= rhs.base();
	}

	template < typename U, typename V >
	bool		operator<=(const reverse_iterator<U>& lhs, const reverse_iterator<V>& rhs) {
		return lhs.base() >= rhs.base();
	}

	template < typename U, typename V >
	ptrdiff_t		operator-(const reverse_iterator<U>& lhs, const reverse_iterator<V>& rhs) {
		return rhs.base() - lhs.base();
	}

	template < typename U >
	reverse_iterator < U >			operator+(typename reverse_iterator<U>::difference_type n, const reverse_iterator<U>& rhs) {
		return (reverse_iterator<U>)(rhs.base() - n);
	}
}
*/

/*

namespace ft {
	template <class Iterator>
	class reverse_iterator : public iterator < 
		typename iterator_traits<Iterator>::iterator_category,
		typename iterator_traits<Iterator>::value_type,
		typename iterator_traits<Iterator>::difference_type,
		typename iterator_traits<Iterator>::pointer,
		typename iterator_traits<Iterator>::reference > {
			
	protected:
	    Iterator curr;
		
	public:
	    typedef Iterator                                            iterator_type;
	    typedef typename iterator_traits<Iterator>::difference_type difference_type;
	    typedef typename iterator_traits<Iterator>::reference       reference;
	    typedef typename iterator_traits<Iterator>::pointer         pointer;
	
		reverse_iterator() {};
		explicit reverse_iterator(Iterator x) {};
	    template < class U >
		constexpr reverse_iterator(const reverse_iterator<U>& u) {};
	    template < class U >
		constexpr reverse_iterator& operator=(const reverse_iterator<U>& u) {};
	    Iterator base() const;
	    reference operator*() const;
	    pointer   operator->() const;
	    reverse_iterator& operator++();
	    reverse_iterator  operator++(int);
	    reverse_iterator& operator--();
	    reverse_iterator  operator--(int);
	    reverse_iterator  operator+ (difference_type n) const;
	    reverse_iterator& operator+=(difference_type n);
	    reverse_iterator  operator- (difference_type n) const;
	    reverse_iterator& operator-=(difference_type n);
	    reference         operator[](difference_type n) const;
	};
}
*/