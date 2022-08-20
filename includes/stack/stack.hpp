/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 01:30:47 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/20 02:40:24 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>
#include <string>

#include "vector/vector.hpp"

namespace ft {
template < class T, class Container = ft::vector<T> >
class stack
{
	public :

		typedef Container								container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;

	protected:
		Container	_c;

	public :
		explicit stack(const Container& container = Container()) : _c(container) {}
		stack(const stack& other) {
			_c = other._c;
		}
		~stack() {}

		stack& operator=( const stack& rhs ) {
			_c = rhs._c;
			return *this;
		}

		reference top() {
			return _c.back();
		}
		const_reference top() const {
			return _c.back();
		}

		bool empty() const {
			return _c.empty();
		}
		size_type size() const {
			return _c.size();
		}
		void push( const value_type& value ) {
			_c.push_back(value);
		}
		void pop() {
			_c.pop_back();
		}

		friend bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
			return (lhs._c == rhs._c);
		}
		friend bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
			return (lhs._c != rhs._c);
		}
		friend bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
			return (lhs._c < rhs._c);
		}
		friend bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
			return (lhs._c <= rhs._c);
		}
		friend bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
			return (lhs._c > rhs._c);
		}
		friend bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
			return (lhs._c >= rhs._c);
		}

};

/*
	template <class T, class container_type = ft::vector<T> >
	class stack {
		protected:
			container_type c;
		public:
			typedef typename container_type::iterator iterator;
			typedef typename container_type::const_iterator const_iterator;
			typedef typename container_type::reverse_iterator reverse_iterator;
			typedef typename container_type::const_reverse_iterator const_reverse_iterator;
			typedef typename container_type::value_type value_type;
			typedef typename container_type::reference reference;
			typedef typename container_type::const_reference const_reference;
			typedef typename container_type::size_type size_type;
			typedef typename container_type::difference_type difference_type;
			typedef typename container_type::pointer pointer;
			typedef typename container_type::const_pointer const_pointer;
			
			explicit stack(const container_type& container = container_type()) : c(container) {}	
			// stack() : c() {};
			stack(const stack& other) : c(other.c) {};
			stack& operator=(const stack& other) {
				c = other.c;
				return *this;
			};
	
			iterator begin() { return c.begin(); };
			iterator end() { return c.end(); };
			const_iterator begin() const { return c.begin(); };
			const_iterator end() const { return c.end(); };
			reverse_iterator rbegin() { return c.rbegin(); };
			reverse_iterator rend() { return c.rend(); };
			const_reverse_iterator rbegin() const { return c.rbegin(); };
			const_reverse_iterator rend() const { return c.rend(); };
	
			bool empty() const { return c.empty(); };
			size_type size()  { return c.size(); };
			size_type max_size() const { return c.max_size(); };
			reference top() { return c.back(); };
			const_reference top() const { return c.back(); };
			void push(const T& value) { c.push_back(value); };
			void pop() { c.pop_back(); };
	
			bool operator==(const stack<T,container_type>& lhs) const { return c == lhs.c; };
			bool operator!=(const stack<T,container_type>& lhs) const { return c != lhs.c; };
			bool operator<(const stack<T,container_type>& lhs) const { return c < lhs.c; };
			bool operator<=(const stack<T,container_type>& lhs) const { return c <= lhs.c; };
			bool operator>(const stack<T,container_type>& lhs) const { return c > lhs.c; };
			bool operator>=(const stack<T,container_type>& lhs) const { return c >= lhs.c; };
	};
	*/
}
