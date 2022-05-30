/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:36:13 by bmangin           #+#    #+#             */
/*   Updated: 2022/05/23 17:06:20 by bmangin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft
{
	
/* ----------------------------   ITERATOR   ------------------------------ */

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		template < class T >
		class vector_iterator_const
		{
			public:
				typedef typename std::ptrdiff_t		difference_type;
				typedef T							value_type;
				typedef const T						*pointer;
				typedef const T						&reference;
				typedef random_access_iterator_tag	iterator_category;

			protected:
				value_type	*current;

			private:
		};
		
		template < class T >
		class vector_iterator_const
		{
			public:
			private:
		};
		
/* --------------------------   CONSTRUCTEUR   ---------------------------- */

			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(),
		        const allocator_type& alloc = allocator_type());
			template <class InputIterator>
		    vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type());
			vector (const vector& x);
			vector&		operator= (const vector& x) {c = x.c; return *this;};

/* --------------------------   DESTRUCTEUR   ----------------------------- */

			~vector() {};

/* ------------------------   MEMBER FUNCTIONS   -------------------------- */

			Container::size_type			size() const {return c.size();};
			size_type			max_size() const {return c.max_size();};
			void				resize(size_type n, value_type val = value_type()) {c.resize(n, val);}; //hien?
			size_type			capacity() const {return c.capacity();};
			bool				empty() const {return c.empty();};
			void				reserve (size_type n) {c.reserve(n);}; //  aure!

/* -------------------------   ELEMENT ACCESS   --------------------------- */

			reference			operator[](size_type n) {return c[n];};
			const_reference		operator[](size_type n) const {return c[n];};
			reference			at(size_type n) {return c.at(n);};
			const_reference		at(size_type n) const {return c.at(n);};
			reference			front() {return c.front();};
			const_reference		front() const {return c.front();};
			reference			back() {return c.back();};
			const_reference		back() const {return c.back();};

/* ---------------------------   MODIFIERS   ------------------------------ */

			template < class InputIterator >
			void			assign(InputIterator first, InputIterator last){c.assign(first, last);};
			void			assign(size_type n, const value_type& val) {c.assign(n, val);};
			
/*
	Iterators:
	Capacity:
	Element access:
	Modifiers:
	
	assign
	Assign vector content (public member function )
	push_back
	Add element at the end (public member function )
	pop_back
	Delete last element (public member function )
	insert
	Insert elements (public member function )
	erase
	Erase elements (public member function )
	swap
	Swap content (public member function )
	clear
	Clear content (public member function )
	emplace 
	Construct and insert element (public member function )
	emplace_back 
	Construct and insert element at the end (public member function )
*/

/* ---------------------------   ALLOCATOR   ------------------------------ */

	Allocator:
	get_allocator
	Get allocator (public member function )

	};
}
