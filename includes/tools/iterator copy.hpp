/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:35:31 by bmangin           #+#    #+#             */
/*   Updated: 2022/06/15 23:03:42 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

namespace ft {

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class Iterator>
    class iterator_traits {
    	public:
    	    typedef typename Iterator::difference_type							difference_type;
    	    typedef typename Iterator::value_type								value_type;
    	    typedef typename Iterator::pointer									pointer;
    	    typedef typename Iterator::reference								reference;
    	    typedef typename Iterator::iterator_category						iterator_category;
    };

    template <class T>
    class iterator_traits<T *> {
    	public:
    	    typedef ptrdiff_t													difference_type;
    	    typedef T															value_type;
    	    typedef T 															*pointer;
    	    typedef T&															reference;
    	    typedef random_access_iterator_tag									iterator_category;
    };

    template <class T>
    class iterator_traits<const T *> {
    	public:
    	    typedef ptrdiff_t 													difference_type;
    	    typedef T 															value_type;
    	    typedef const T														*pointer;
    	    typedef const T& 													reference;
    	    typedef random_access_iterator_tag									iterator_category;
    };

    template <class Iterator>
    class std_iterator {
    	public:
    	    typedef Iterator													iterator_type;
    	    typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
    	    typedef typename iterator_traits<iterator_type>::value_type			value_type;
    	    typedef typename iterator_traits<iterator_type>::pointer			pointer;
    	    typedef typename iterator_traits<iterator_type>::reference			reference;
    	    typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
	
    	private:
    	    iterator_type		curr;
			
    	public:
	        std_iterator() {}
	        std_iterator(pointer ptr) : curr(ptr) {}
	        template <typename _Iter>
	        std_iterator(const std_iterator<_Iter>& ptr) : curr(ptr.base()) {}
	
	        virtual ~std_iterator() {}
	
	        std_iterator&		operator=(const std_iterator& rhs) {
	            this->curr = rhs.curr;
	            return *this;
	        }
	
	        reference			operator*() const { return *curr; }
	
	        pointer				operator->() const { return curr; }
	
	        std_iterator&		operator++() {
	            ++curr;
	            return *this;
	        }
	
	        std_iterator		operator++(int) {
	            std_iterator __tmp(*this);
	            this-		operator++();
	            return __tmp;
	        }
	
	        std_iterator&		operator--() {
	            --curr;
	            return *this;
	        }
	
	        std_iterator		operator--(int) {
	            std_iterator __tmp(*this);
	            this-		operator--();
	            return __tmp;
	        }
	
	        std_iterator		operator+(difference_type __n) const {
	            std_iterator __w(*this);
	            __w += __n;
	            return __w;
	        }
	
	        std_iterator&		operator+=(difference_type __n) {
	            curr += __n;
	            return *this;
	        }
	
	        std_iterator		operator-(difference_type __n) const {
	            std_iterator __w(*this);
	            __w -= __n;
	            return __w;
	        }
	
	        std_iterator&		operator-=(difference_type __n) {
	            curr -= __n;
	            return *this;
	        }
	
	        reference			operator[](difference_type __n) const { return curr[__n]; }
	
	        Iterator			base() const { return curr; }
	    };
	
	    template <class Iterator>
	    bool					operator==(const std_iterator < Iterator >& lhs, const std_iterator < Iterator >& rhs) { return lhs.base() == rhs.base(); }
	    template <class Iterator>
	    bool					operator!=(const std_iterator < Iterator >& lhs, const std_iterator < Iterator >& rhs) { return lhs.base() != rhs.base(); }
	    template <class Iterator>
	    bool					operator< (const std_iterator < Iterator >& lhs, const std_iterator < Iterator >& rhs) { return lhs.base() < rhs.base(); }
	    template <class Iterator>
	    bool					operator<=(const std_iterator < Iterator >& lhs, const std_iterator < Iterator >& rhs) { return lhs.base() <= rhs.base(); }
	    template <class Iterator>
	    bool					operator> (const std_iterator < Iterator >& lhs, const std_iterator < Iterator >& rhs) { return lhs.base() > rhs.base(); }
   		template <class Iterator>
   		bool					operator>=(const std_iterator < Iterator >& lhs, const std_iterator < Iterator >& rhs) { return lhs.base() >= rhs.base(); }
	
		template <class _Iter1, class _Iter2>
		typename std_iterator<_Iter1>::difference_type operator-(const std_iterator<_Iter1>& lhs, const std_iterator<_Iter2>& rhs) {
		       return lhs.base() - rhs.base();
		}
	
		template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T& >
		struct iterator {
		    typedef T 											value_type;
		    typedef Distance 									difference_type;
		    typedef Pointer 									pointer;
		    typedef Reference 									reference;
		    typedef Category 									iterator_category;
		};

	    template <class T>
	    class reverse_iterator : public iterator<typename iterator_traits<T>::iterator_category,
			typename iterator_traits<T>::value_type, typename iterator_traits<T>::difference_type,
	        typename iterator_traits<T>::pointer, typename iterator_traits<T>::reference> {
				
	    	public:
				typedef T												iterator_type;
				typedef typename iterator_traits<T>::difference_type	difference_type;
				typedef typename iterator_traits<T>::pointer			pointer;
				typedef typename iterator_traits<T>::reference			reference;
	
		    protected:
		        iterator_type										current;
		        typedef iterator_traits<T>                          __traits_type;
	
			public:
		        reverse_iterator() : current() {}	
		        explicit reverse_iterator(iterator_type ptr) : current(ptr) {}
				template <typename _Iter>
				reverse_iterator(const reverse_iterator<_Iter>& ptr) : current(ptr.base()) {}

		        virtual ~reverse_iterator() {}
	
		        reverse_iterator& operator=(const reverse_iterator<T>& rhs) {
		            this->current = rhs.current;
		            return *this;
		        }
		
		        reference operator*() const {
		            T __tmp = current;
		            return *--__tmp;
		        }
		
		        pointer operator->() const {
		            return &this->operator*();
		        }
		
		        reverse_iterator& operator++() {
		            --current;
		            return *this;
		        }
		
		        reverse_iterator operator++(int) {
		            reverse_iterator __tmp(*this);
		            this->operator++();
		            return __tmp;
		        }
		
		        reverse_iterator& operator--() {
		            ++current;
		            return *this;
		        }
		
		        reverse_iterator	operator--(int) {
		            reverse_iterator __tmp(*this);
		            this->operator--();
		            return __tmp;
		        }
		        reverse_iterator	operator+(difference_type __n) const { return reverse_iterator(current - __n); }
		        reverse_iterator&	operator+=(difference_type __n) {
		            current -= __n;
		            return *this;
		        }
		        reverse_iterator	operator-(difference_type __n) const { return reverse_iterator(current + __n); }
		
		        reverse_iterator&	operator-=(difference_type __n) {
		            current += __n;
		            return *this;
		        }
		
		        reference operator[](difference_type __n) const { return current[-__n - 1]; }
		
		        iterator_type base() const { return current; }
		};

	    template <class Iterator>
	    bool			operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() == rhs.base(); }
	    template <class Iterator>
	    bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() != rhs.base(); }
	    template <class Iterator>
	    bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() > rhs.base(); }
	    template <class Iterator>
	    bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() >= rhs.base(); }
	    template <class Iterator>
	    bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() < rhs.base(); }
	    template <class Iterator>
	    bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return lhs.base() <= rhs.base(); }
	
	    template <class _Iter1, class _Iter2>
	    typename reverse_iterator<_Iter1>::difference_type operator-(const reverse_iterator<_Iter1>& lhs, const reverse_iterator<_Iter2>& rhs) {
	        return rhs.base() - lhs.base();
	    }
}
/*
#pragma once

#include <iterator>
#include <cstddef>
#include "tools/iterator_traits.hpp"

namespace ft {
	template < class Category, class T, class Distance, class Pointer, class Reference >
	struct base_iterator
	{
		typedef T			value_type;
		typedef Distance 	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category 	iterator_category;
	};
}
*/
/*
namespace ft {
	template < class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T& >
	class iterator {
	   public:
		typedef Category										iterator_category;
		typedef T												value_type;
		typedef Distance										difference_type;
		typedef Pointer											pointer_it;
		typedef Reference										reference;
	};

	template <class T>
	class iterator_traits {
		public:
			typedef typename T::iterator::difference_type		difference_type;
			typedef typename T::iterator::value_type			value_type;
			typedef typename T::iterator::pointer_it			pointer;
			typedef typename T::iterator::reference				reference;
			typedef typename T::iterator::iterator_category		iterator_category;
	};
*/

/*
#pragma once

#include <iterator>
#include <cstddef>
	
namespace ft {
	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
	
	template < class Iterator >
	struct iterator_traits {
	    typedef typename Iterator::difference_type				difference_type;
	    typedef typename Iterator::value_type					value_type;
	    typedef typename Iterator::pointer						pointer;
	    typedef typename Iterator::reference					reference;
	    typedef typename Iterator::iterator_category			iterator_category;
	};
	
	template < class T >
	struct iterator_traits < T* > {
	    typedef ptrdiff_t										difference_type;
	    typedef T												value_type;
	    typedef T*												pointer;
	    typedef T&												reference;
	    typedef random_access_iterator_tag						iterator_category;
	};
	
	template<class Category, class T, class Distance = ptrdiff_t,
	         class Pointer = T*, class Reference = T&>
	struct iterator	{
	    typedef T												value_type;
	    typedef Distance										difference_type;
	    typedef Pointer											pointer;
	    typedef Reference										reference;
	    typedef Category										iterator_category;
	};
}
*/

