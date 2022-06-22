/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:36:13 by bmangin           #+#    #+#             */
/*   Updated: 2022/06/12 00:31:49 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
// #include "tools/iterator_traits.hpp"
#include "tools/iterator.hpp"
#include "tools/enable_if.hpp"
#include "tools/is_integral.hpp"

namespace ft
{	
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
//  ----------------------------   TYPEDEF   ------------------------------ ##

			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename ft::std_iterator<pointer>				iterator;
			typedef typename ft::std_iterator<const_pointer>		const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;
			// typedef Alloc				allocator_type;
			// typedef T					value_type;
			// typedef T*					pointer;
			// typedef T&					reference;
			// typedef const T*			const_pointer;
			// typedef const T&			const_reference;
			// typedef size_t				size_type;
			// typedef ptrdiff_t			difference_type;
	/*
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
	*/

//  -------------------------   CLASS ITERATOR   -------------------------- ##
/*
		class VectorIterator : public iterator < bidirectional_iterator_tag, value_type > {
			public:
				typedef typename iterator_traits<vector<T, allocator_type> >::difference_type		difference_type;
				typedef typename iterator_traits<vector<T, allocator_type> >::value_type			value_type;
				typedef typename iterator_traits<vector<T, allocator_type> >::pointer				pointer;
				typedef typename iterator_traits<vector<T, allocator_type> >::reference			reference;
				typedef typename iterator_traits<vector<T, allocator_type> >::iterator_category	iterator_category;
			protected:
				pointer _array;

			public:
			
				VectorIterator(void) : _array(NULL) {}
				VectorIterator(pointer array) : _array(array) {}
				VectorIterator(const VectorIterator& it) : _array(it._array) {}
		
				reference operator*() const { return *_array; }
				pointer operator->() const { return _array; }
				VectorIterator& operator++() {
					_array++;
					return *this;
				}
				VectorIterator operator++(int) {
					VectorIterator tmp = *this;
					++*this;
					return tmp;
				}
				VectorIterator& operator--() {
					_array--;
					return *this;
				}
				VectorIterator operator--(int) {
					VectorIterator tmp = *this;
					--*this;
					return tmp;
				}
				VectorIterator&		operator+=(difference_type n) {
					_array += n;
					return *this;
				}
				VectorIterator		operator+(difference_type n) const {
					VectorIterator tmp = *this;
					tmp += n;
					return tmp;
				}
				VectorIterator&		operator-=(difference_type n) {
					_array -= n;
					return *this;
				}
				VectorIterator		operator-(difference_type n) const {
					VectorIterator tmp = *this;
					tmp -= n;
					return tmp;
				}
				difference_type		operator-(const VectorIterator& it) const { return _array - it._array; }
				reference			operator[](difference_type n) const { return _array[n]; }
				bool				operator==(const VectorIterator& it) const { return _array == it._array; }
				bool				operator!=(const VectorIterator& it) const { return _array != it._array; }
				bool				operator<(const VectorIterator& it) const { return _array < it._array; }
				bool				operator>(const VectorIterator& it) const { return _array > it._array; }
				bool				operator<=(const VectorIterator& it) const { return _array <= it._array; }
				bool				operator>=(const VectorIterator& it) const { return _array >= it._array; }
			};

//  ------------------------   CLASS REV_ITERATOR   ----------------------- ##

			class VectorReverseIterator  : public iterator < bidirectional_iterator_tag, value_type > {
				public:
					typedef typename iterator_traits < vector < T, allocator_type > >::difference_type		difference_type;
					typedef typename iterator_traits < vector < T, allocator_type > >::value_type			value_type;
					typedef typename iterator_traits < vector < T, allocator_type > >::pointer				pointer;
					typedef typename iterator_traits < vector < T, allocator_type > >::reference			reference;
					typedef typename iterator_traits < vector < T, allocator_type > >::iterator_category	iterator_category;
					
				protected:
					pointer _array;
		
				public:

					VectorReverseIterator(void) : _array(NULL) {}
					VectorReverseIterator(pointer array) : _array(array) {}
					VectorReverseIterator(const VectorReverseIterator& it) : _array(it._array) {}
		
					reference				operator*() const { return *_array; }
					pointer					operator->() const { return _array; }
		
					VectorReverseIterator&	operator++() {
						_array--;
						return *this;
					}
					VectorReverseIterator	operator++(int) {
						VectorReverseIterator tmp = *this;
						++*this;
						return tmp;
					}
					VectorReverseIterator&	operator--() {
						_array++;
						return *this;
					}
					VectorReverseIterator	operator--(int) {
						VectorReverseIterator tmp = *this;
						--*this;
						return tmp;
					}
					VectorReverseIterator&	operator+=(difference_type n) {
						_array -= n;
						return *this;
					}
					VectorReverseIterator	operator+(difference_type n) const {
						VectorReverseIterator tmp = *this;
						tmp += n;
						return tmp;
					}
					VectorReverseIterator&	operator-=(difference_type n) {
						_array += n;
						return *this;
					}
					VectorReverseIterator	operator-(difference_type n) const {
						VectorReverseIterator tmp = *this;
						tmp -= n;
						return tmp;
					}
					difference_type			operator-(const VectorReverseIterator& it) const { return _array - it._array; }
					reference				operator[](difference_type n) const { return _array[n]; }
					bool					operator==(const VectorReverseIterator& it) const { return _array == it._array; }
					bool					operator!=(const VectorReverseIterator& it) const { return _array != it._array; }
					bool					operator<(const VectorReverseIterator& it) const { return _array < it._array; }
					bool					operator>(const VectorReverseIterator& it) const { return _array > it._array; }
					bool					operator<=(const VectorReverseIterator& it) const { return _array <= it._array; }
					bool					operator>=(const VectorReverseIterator& it) const { return _array >= it._array; }
				};
			
				typedef VectorIterator			iterator;
				typedef VectorReverseIterator 	reverse_iterator;
				typedef VectorIterator			const_iterator;
				typedef VectorReverseIterator	const_reverse_iterator;
				
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
						if (this != &rhs)
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
*/
//  -----------------------   CLASS CONST_ITERATOR   ---------------------- ##
/*
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
						if (this != &rhs)
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
*/				
//  -----------------------------   PRIVATE   ------------------------------ ##

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
			
			// explicit vector(size_type n, const allocator_type& alloc) :
				// _capacity(n), _size(n), _alloc(alloc), _array(NULL) {
					// _array = _alloc.allocate(_capacity);
					// assign(n, value_type());
			// };
			
			// explicit vector(size_type n) : _capacity(n), _size(n), _alloc(), _array(NULL) {
				// _array = _alloc.allocate(_capacity, _array);
				// assign(n, value_type());
			// };

			// explicit vector(size_type n, const value_type& val, const allocator_type& alloc = allocator_type()) :
				// _capacity(n), _size(n), _alloc(alloc), _array(NULL) {
				// _array = _alloc.allocate(_capacity, _array);
				// assign(n, val);
			// };
			
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				_capacity(n), _size(n), _alloc(alloc), _array(NULL) {
				_array = _alloc.allocate(_capacity, _array);
				assign(n, val);
			};
				
				
			// vector(InputIterator first, typename enable_if < is_iterator < InputIterator >::value>::type last, const allocator_type& alloc = allocator_type()) :
			template < class InputIterator >
			vector(InputIterator first, typename ft::enable_if < !is_integral < InputIterator >::value, InputIterator >::type last, const allocator_type& alloc = allocator_type()) :
				_capacity(0), _size(0), _alloc(alloc), _array(NULL) {
				assign(first, last);
			};

			vector (const vector& x) :
				_capacity(x._size), _size(x._size), _alloc(x._alloc), _array(x._array) {
				_array = _alloc.allocate(_capacity);
                
				const_iterator it = x.begin();
				int i = 0;
				while (it!=x.end())
				{
					_alloc.construct(&_array[i], *it);
					i++;
					it++;
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

			vector& operator=(const vector& x) {
				if (this != &x) {
					_capacity = x._size;
					_size = x._size;
					_alloc = x._alloc;
					_array = _alloc.allocate(_capacity, _array);
					for (size_type i = 0; i < _size; i++)
						_array[i] = x._array[i];
				}
				return *this;
			};
	
//  ----------------------------   CAPACITY   ----------------------------- ##

			size_type	size() const { return _size; };

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
			};

			void		resize(size_type n, value_type val = value_type()) {
				/*
				// WPERU
				if (n <= _size)
		        {
		            while (_size > n)
		            {
		                --_size;
		                _alloc.destroy(&(_array[_size]));
		            }
		            return ;
		        }
		        reserve(n);
		        while(_size < n)
		        {
		            _alloc.destroy(&(_array[_size]));
		            _alloc.construct(&(_array[_size]),val);
		            _size++;
		        }
		        return ;	
				*/
				// /*
				// LUSEHAIR
				// std::cout << "resize(" << n << ", " << val << ")" << std::endl;
				while (n > _size)
				{
					std::cout << "pushback" << std::endl;
					push_back(val);
				}	
				if (n < _size)
				{
					std::cout << "popback" << std::endl;
					while (_size != n)
						pop_back();
					// std::cout << "size: " << _size << " n: "  << n << std::endl;
				}
				// */
			};

			size_type	capacity() const { return _capacity; };

			bool		empty() const { return (_size == 0); };

			void		reserve(size_type n) {
				/*
				size_type i = 0;
				std::cout << "capa: " << _capacity << std::endl;
		
				if (n <= _capacity)
        		    return;
        		if (n > max_size())
        		    n = max_size();
				size_type old_cap = _capacity;
				if (_capacity == 0)
        		    _capacity = n;
				// while(_capacity < n)
					// _capacity *= 2;
				// std::cout << "capa=>" << _capacity << "n=>" << n << std::endl;
				// if (_capacity < n + 1)
					// _capacity = n;
					// _capacity <<= 1;
				T *tmp = _alloc.allocate(_capacity);
        		while(i < _size)
				{
					_alloc.construct(&tmp[i], _array[i]);
					i++;
				}
				destroy_data();
        		_alloc.deallocate(_array, old_cap);
				_array = tmp;
				*/
				if (n) {
					int to_allocate;
					// if (n <= _capacity)
						// to_allocate = _capacity << 1 ;
					// else
						// to_allocate = n;		
					if (n <= _size * 2)
						to_allocate = _size << 1;
					else
						to_allocate = n;		
					if (n > max_size())
						throw (std::length_error("the size requested is greater than the maximum size"));
					if (n > capacity())
					{
						std::cout << "reserve(" << n << ")" << std::endl;
						std::cout << "capa(" << _capacity << "), " << "size(" << _size << ")" << std::endl;
						if (!_capacity) {
							std::cout << "#CAP1" << std::endl;
							_array =_alloc.allocate(to_allocate);
							_capacity = to_allocate;
						}
						else
						{
							std::cout << "#CAP2" << std::endl;
							value_type	*tmp = _alloc.allocate(to_allocate);
							for (size_type i = 0; i < _size; i++)
								tmp[i] = _array[i];
							_alloc.destroy(_array);
							_alloc.deallocate(_array, _capacity);
							_array = tmp;
							_capacity = to_allocate;
						}
					}
				}
			};
			
//  --------------------------   ITERATOR_FUNC   -------------------------- ##

			iterator				begin() { return iterator(_array); }
			const_iterator			begin() const { return const_iterator(_array); }
			iterator				end() { return iterator(&_array[_size]); }
			const_iterator			end() const  { return const_iterator(&_array[_size]); }

//  -------------------------   ELEMENT ACCESS   -------------------------- ##

			reference				operator[] (size_type n) { return (_array[n]); }
			const_reference			operator[] (size_type n) const { return(_array[n]); }
			reference				at(size_type n) {
				if (n >= _size)
					throw (std::out_of_range("vector"));
				return (_array[n]);
			}
			const_reference			at(size_type n) const {
				if (n >= _size)
					throw (std::out_of_range("vector"));
				return (_array[n]);
			}
			reference				front() { return(_array[0]); }
			const_reference			front() const { return(_array[0]); }
			reference				back() { return(_array[_size - 1]); }
			const_reference			back() const { return(_array[_size - 1]); }

//  ---------------------------   MODIFIERS   ----------------------------- ##

			template < class InputIterator >
			void		assign (InputIterator first, typename ft::enable_if < !is_integral < InputIterator >::value, InputIterator >::type last) {
				clear();
				// std::cout << "ok et apres ... " << std::endl;
				insert(begin(), first, last);
			};
			
			void		assign(size_type n, const value_type& val) {
				clear();
				// std::cout << "ok et apres ... " << std::endl;
				resize(n, val);
			};
			
			void		push_back (const value_type& val) {
				value_type	*tmp;
				
				if (_size == _capacity)
				{
					if (!_capacity)
						_capacity = 1;
					else
						_capacity *= 2;
					tmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _array[i]);
					_alloc.construct(&tmp[_size], val);
					destroy_data();
					_size++;
					_array = tmp;
				}
				else
				{
					_alloc.construct(&_array[_size], val);
					_size++;
				}				
				/*
				value_type	*new_data;
				size_type	i = 0;;

				if (_size == _capacity)
				{
					if (!_capacity)
						_capacity++;
					while (_size > capacity())
						_capacity <<= 1;
					new_data = _alloc.allocate(_capacity);
					while (i < _size)
					{
						new_data[i] = _array[i];
						i++;
					}
					_alloc.deallocate(_array, _size);
					_array = new_data;
				}
				value_type *tmp = _array + _size;
				tmp = new (tmp) value_type(val);
				_size++;	
				*/					
				// if ((_size + 1) > capacity())
					// reserve(_size + 1);
				// _alloc.construct(_array + _size, val);
				// _size++;
			};
			
			void		pop_back() {
				if (_size > 0) {
					_alloc.destroy(&_array[_size]);
    			    reserve(_size - 1);
    			    _size--;
				/*
				if (_size > 0)
				{
					_alloc.destroy(_array + (_size - 1));
					_size--;
				*/
				}
			};
			
			iterator	insert(iterator position, const value_type& val) {
				size_t	dist = position - begin();
				insert(position, 1, val);
				return (&_array[dist]);
			};
			
    		void		insert(iterator position, size_type n, const value_type& val) {
				std::cout << "insert(iterator," << n << ","<< val << ")" <<std::endl;
				//i think it's ok
				if (n)
				{
					// size_type	capa = 1;
					iterator	it = begin();	
					// vector		tmp(*this);
					vector		tmp;
					
					// while (capa <= _size)
					// 	capa <<= 1;
					// std::cout << "capa: " << capa << std::endl;
					// tmp.reserve(capa);
					// tmp._capacity = capa;
					
					if (_capacity && 1 + _size <= n)
						_capacity <<= 1;
					else
						_capacity = _size + n;
					std::cout << "this(capa:" << _capacity << ", size:" << _size << ", n:" << n << ")"<< std::endl;
					// tmp.reserve(n + _size);
					tmp.reserve(_capacity);
					while (it != position)
					{
						tmp.push_back(*it);
						it++;
					}
					while (n--)
					{
						tmp.push_back(val);
					}
					while (it != end())
					{
						tmp.push_back(*it);
						it++;
					} 
					swap(tmp);
				}
			};
			
			template < class InputIterator >
			void		insert(iterator position, InputIterator first,typename ft::enable_if < !is_integral < InputIterator >::value, InputIterator >::type last) {
				vector tmp;
				iterator it = begin();
				// std::cout << "insert with iterator" <<std::endl;
				if (it != NULL)
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
			};
			
			iterator	erase(iterator position) {
				iterator it = position;

                _alloc.destroy(position);     
                for (pointer tmp = position; tmp != end(); tmp++) 
                {
                    _alloc.construct(tmp, *(tmp + 1));
                }
                _size--;
                return it;
			};
			
			iterator	erase(iterator first, iterator last) {
				for (; first != last; --last)
					first = erase(first);
				return last;
			};
			
			void		swap(vector& x) {
				if (this != &x) {
					swap(_capacity, x._capacity);
					swap(_size, x._size);
					swap(_alloc, x._alloc);
					swap(_array, x._array);
				}
			};
			
			void		clear() {
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(&_array[i]);
				_size = 0;
			};
			
//  ---------------------------   ALLOCATOR   ----------------------------- ##

			allocator_type	get_allocator() const { return (_alloc); };
			void		init_data(size_type n , const value_type val) {
				for (size_type i = 0; i < n; ++i)
					_alloc.construct(&_array[i], val);
				_size = n;
				_capacity = n;
				// size_type i = 0;
				// _array=_alloc.allocate(n);
			// 
				// while(i < n)
				// {
					// _alloc.construct(&_array[i],val);
					// i++;
				// }
				// _size = n;
				// _capacity = n;
			};
			void		destroy_data() {
				for (size_type i = 0; i < _size; ++i)
					_alloc.destroy(&_array[i]);
				// size_type i = 0;
				// 
				// while(i < _size)
				// {
					// _alloc.destroy(&_array[i]);
					// i++;
				// }	
			};
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
	
	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename ft::vector<T>::const_iterator first1 = lhs.begin();
		typename ft::vector<T>::const_iterator last1 = lhs.end();
		typename ft::vector<T>::const_iterator first2 = rhs.begin();
		typename ft::vector<T>::const_iterator last2 = rhs.end();
		
		while(first1 != last1)
		{
			if (first2==last2 || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return(!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return(!(lhs < rhs));
	}

	/** swap **/
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
}
