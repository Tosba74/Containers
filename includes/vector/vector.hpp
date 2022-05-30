/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:36:13 by bmangin           #+#    #+#             */
/*   Updated: 2022/05/30 20:45:57 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include "tools/reverse_iterator.hpp"
#include "tools/iterator_traits.hpp"

namespace ft
{	
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
//  ----------------------------   TYPEDEF   ------------------------------ ##

			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
		    typedef typename allocator_type::size_type			size_type;
		    typedef typename allocator_type::difference_type	difference_type;
		    typedef typename allocator_type::pointer			pointer;
		    typedef typename allocator_type::const_pointer		const_pointer;
		    // typedef pointer										iterator;
		    // typedef const_pointer								const_iterator;
		    // typedef ft::reverse_iterator<iterator>				reverse_iterator;
		    // typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			
//  -------------------------   CLASS ITERATOR   -------------------------- ##

			class iterator
			{
				public:
					//TYPEDEF
					typedef T									value_type;
					typedef value_type*							pointer;
					typedef value_type&							reference;
					typedef ptrdiff_t							difference_type;
					typedef ft::random_access_iterator_tag		iterator_category;
	
				protected:
					value_type 		*_value;
					
				public:
					//ITERATOR CONSTRUCTOR
					iterator() : _value(nullptr) {}
					iterator(value_type* value) : _value(value) {}
					iterator(const iterator& src) : _value(src._value) {};
	
					//ITERATOR DESTRUCTOR
					~iterator() {}
	
					//ITERATOR OPERATOR
					iterator					&operator=(const iterator &rhs) {
						if ( this != &rhs)
							_value = rhs._value;
						return *this;
					}
					reference					operator*(void) const { return *_value; }
					pointer						operator->(void) const { return _value; }
					iterator::difference_type	operator+(const iterator &rhs) { return (_value + rhs._value); }
					iterator::difference_type	operator-(const iterator &rhs) { return (_value - rhs._value); }
					iterator					operator+(difference_type n) { return iterator(_value + n); }
					iterator					operator-(difference_type n) { return iterator(_value - n); }
					iterator					&operator+=(difference_type n) {
						_value += n;
						return *this;
					}
					iterator					&operator-=(difference_type n) {
						_value -= n;
						return *this;
					}
					bool						operator!=(const iterator &rhs) const { return (_value != rhs._value); }
					bool						operator==(const iterator &rhs) const { return (_value == rhs._value); }
					iterator					&operator++(void) {
						++_value;
						return *this;
					}
	
					iterator					operator++(int) {
						iterator	cpy(*this);
						++_value;
						return cpy;
					}
					iterator					&operator--(void) {
						--_value;
						return *this;
					}
	
					iterator					operator--(int) {
						iterator	cpy(*this);
						--_value;
						return cpy;
					}
					bool						operator<(const iterator& rhs) { return (_value < rhs._value); }
					bool						operator>(const iterator& rhs) { return (_value > rhs._value); }
					bool						operator<=(const iterator& rhs) { return (_value <= rhs._value); }
					bool						operator>=(const iterator& rhs) { return (_value >= rhs._value); }
			};

//  -----------------------   CLASS CONST_ITERATOR   ---------------------- ##

			class const_iterator
			{
				public:
					typedef ptrdiff_t							difference_type;
					typedef T									value_type;
					typedef value_type*							pointer;
					typedef value_type&							reference;
					typedef ft::random_access_iterator_tag		iterator_category;
	
				protected:
					value_type 		*_value;
					
				public:
					//ITERATOR CONSTRUCTOR
					const_iterator() : _value(nullptr) {}
					const_iterator(value_type* value) : _value(value) {}
					const_iterator(const const_iterator& src) : _value(src._value) {};
	
					//CONST_ITERATOR DESTRUCTOR
					~const_iterator() {}
	
					//CONST_ITERATOR OPERATOR
					const_iterator					&operator=(const const_iterator &rhs) {
						if ( this != &rhs)
							_value = rhs._value;
						return *this;
					}
					reference						operator*(void) const { return *_value; }
					pointer							operator->(void) const { return _value; }
					const_iterator::difference_type	operator+(const const_iterator &rhs) { return (_value + rhs._value); }
					const_iterator::difference_type	operator-(const const_iterator &rhs) { return (_value - rhs._value); }
					const_iterator					operator+(difference_type n) { return const_iterator(_value + n); }
					const_iterator					operator-(difference_type n) { return const_iterator(_value - n); }
					const_iterator					&operator+=(difference_type n) {
						_value += n;
						return *this;
					}
					const_iterator					&operator-=(difference_type n) {
						_value -= n;
						return *this;
					}
					bool							operator!=(const const_iterator &rhs) const { return (_value != rhs._value); }
					bool							operator==(const const_iterator &rhs) const { return (_value == rhs._value); }
					const_iterator					&operator++(void) {
						++_value;
						return *this;
					}
					const_iterator					operator++(int) {
						const_iterator cpy(*this);
						++_value;
						return cpy;
					}
					const_iterator					&operator--(void) {
						--_value;
						return *this;
					}
					const_iterator					operator--(int) {
						const_iterator cpy(*this);
						--_value;
						return cpy;
					}
					bool							operator<(const const_iterator& rhs) { return (_value < rhs._value); }
					bool							operator>(const const_iterator& rhs) { return (_value > rhs._value); }
					bool							operator<=(const const_iterator& rhs) { return (_value <= rhs._value); }
					bool							operator>=(const const_iterator& rhs) { return (_value >= rhs._value); }
			};
				
//  ----------------------------   PROTECTED   ----------------------------- ##

		private:
			size_type		_capacity;
			size_type		_size;
			allocator_type	_alloc;
			value_type		*_array;
			
			template < typename F >
			void swap(F& a, F& b) {
				F tmp;
				tmp = a;
				a = b;
				b = tmp;
			}
			
//  ---------------------------   CONSTUCTOR   ---------------------------- ##

		public:
			explicit vector(const allocator_type& alloc = allocator_type()) :
				_capacity(0), _size(0), _alloc(alloc), _array(NULL) {};
			
			template < class InputIterator >
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
				_capacity(0), _size(0), _alloc(alloc), _array(NULL) {
				assign(first, last);
			};

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				_capacity(0), _size(n), _alloc(alloc), _array(NULL) {
				while (_capacity <= _size)
					_capacity <<= 1;
				_array = _alloc.allocate(_capacity, _array);
				assign(n, val);
			};
				
			vector(const vector& x) {
				if (this != x) {
					_capacity = x._capacity;
					_size = x._size;
					_alloc = x._alloc;
					_array = _alloc.allocate(_capacity, _array);
					for (int i = 0; i < _size; i++)
						_array[i] = x._array[i];
				}
			};

//  ---------------------------   DESTUCTOR   ----------------------------- ##

			~vector() {
				if (_array) {
					clear();
					_alloc.deallocate(_array, _capacity);
					_capacity = 0;
				}
			};

//  ----------------------------   OPERATOR   ----------------------------- ##

			vector& operator= (const vector& x) {
				if (this != x) {
					_capacity = x._capacity;
					_size = x._size;
					_alloc = x._alloc;
					_array = _alloc.allocate(_capacity, _array);
					for (int i = 0; i < _size; i++)
						_array[i] = x._array[i];
				}
				return *this;
			}
	
//  ----------------------------   CAPACITY   ----------------------------- ##

			size_type	size() const { return _size; }
			size_type	max_size() const {
				size_type	max_size = 0;
				try
				{
					max_size = _alloc.max_size();
				}
				catch (std::exception &e)
				{
					std::cout << "Error in vector.max_size() :" << e.what() << std::endl;
				}
				return (max_size);
			}
			void		resize(size_type n, value_type val = value_type()) {
				while (n > _size)
					push_back(val);
				if (n < _size)
					while (_size != n)
						pop_back();
			}
			size_type	capacity() const { return _capacity; }
			bool		empty() const { return (_size == 0); }
			void		reserve(size_type n) {
				if (n) {
					if (n > capacity())
					{
						if (!_capacity) {
							_alloc.allocate(n, _array);
							_capacity = n;
						}
						else
						{
							value_type	*tmp = _alloc.allocate(n, _array);
							for (size_type i = 0; i < _size; i++)
								tmp[i] = _array[i];
							_alloc.deallocate(_array, _capacity);
							_array = tmp;
							_capacity = n;
						}
					}
				}
			}
			
//  --------------------------   ITERATOR_FUNC   -------------------------- ##

			iterator				begin() { return iterator(_array); }
			const_iterator			begin() const { return const_iterator(_array); }
			iterator				end() { return iterator(&_array[_size]); }
			const_iterator			end() const  { return const_iterator(&_array[_size]); }
			// reverse_iterator		rbegin() { return reverse_iterator(end()); }
			// const_reverse_iterator	rbegin() const  { return const_reverse_iterator(end()); }
			// reverse_iterator		rend() { return reverse_iterator(begin()); }
			// const_reverse_iterator	rend() const  { return const_reverse_iterator(begin()); }

//  -------------------------   ELEMENT ACCESS   -------------------------- ##

			reference operator[] (size_type n) { return (_array[n]); }
			const_reference operator[] (size_type n) const { return(_array[n]); }
			reference front() { return(_array[0]); }
			const_reference front() const { return(_array[0]); }
			reference back() { return(_array[_size - 1]); }
			const_reference back() const { return(_array[_size - 1]); }

//  ---------------------------   MODIFIERS   ----------------------------- ##

			template <class InputIterator>
			void		assign (InputIterator first, InputIterator last) {
				clear();
				insert(begin(), first, last);
			}
			void		assign (size_type n, const value_type& val) {
				clear();
				resize(n, val);
			}
			void		push_back (const value_type& val) {
				if((_size + 1) > capacity())
					reserve(_size + 1);
				_alloc.construct(_array + _size, val);
				_size++;
			}
			void		pop_back() {
				if (_size > 0)
				{
					_alloc.destroy(_array + (_size - 1));
					_size--;
				}
			}
			iterator	insert (iterator position, const value_type& val) {
				size_t	dist = position - begin();
				insert(position, 1, val);
				return (&_array[dist]);
			}
    		void insert (iterator position, size_type n, const value_type& val) {
				if (n)
				{
					vector		tmp;
					tmp.reserve(n + _size);
					int			i = 0;
					iterator	it = begin();	
					while (it != position)
					{
						tmp.push_back(*it);
						it++;
						i++;
					}
					while (n--)
					{
						tmp.push_back(val);
						i++;
					}
					while (it != end())
					{
						tmp.push_back(*it);
						it++;
						i++;
					}
					swap(tmp);
				}
			}
			template < class InputIterator >
			void insert (iterator position, enable_if < is_iterator < InputIterator >::value >::type first, enable_if < is_iterator < InputIterator >::value >::type last) {
				vector tmp;
				iterator it = begin();
				if(begin() != NULL)
				{
					while (it != position)
					{
						tmp.push_back(*it);
						it++;
					}
				}
				while (first != last)
				{
					tmp.push_back(*first);
					first++;
				}
				while (it != end())
				{
					tmp.push_back(*it);
					it++;
				}
				swap(tmp);
			}
			iterator erase (iterator position) {
				iterator it = position;

                _alloc.destroy(position);     
                for (pointer tmp = position; tmp != end(); tmp++) 
                {
                    _alloc.construct(tmp, *(tmp + 1));
                }
                _size--;
                return it;
			}
			iterator erase (iterator first, iterator last) {
				for (; first != last; --last)
					first = erase(first);
				return last;
			}
			void swap (vector& x) {
				if (this != &x) {
					swap(_capacity, x._capacity);
					swap(_size, x._size);
					swap(_alloc, x._alloc);
					swap(_array, x._array);
				}
			}
			void	clear() {
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(&_array[i]);
				_size = 0;
			}
			
//  ---------------------------   ALLOCATOR   ----------------------------- ##

			allocator_type	get_allocator() const { return (_alloc); }
	};
//  -----------------------   NON-MEMBER FUNC   --------------------------- ##
	template < class T, class Alloc >
	bool	operator!=(const vector < T, Alloc >& lhs, const vector < T, Alloc >& rhs) { return (!(lhs == rhs)); }
	template < class T, class Alloc >
	bool	operator==(const vector < T, Alloc >& lhs, const vector < T, Alloc >& rhs) {
		if (lhs == rhs)
			return false;
		for (typename ft::vector < T, Alloc >::size_type i = 0; i != lhs.size(); ++i)
			if (lhs[i] != lhs[i])
				return false;
		return true;
	}
}
