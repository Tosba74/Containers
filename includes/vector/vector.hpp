/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:36:13 by bmangin           #+#    #+#             */
/*   Updated: 2022/06/22 19:33:07 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <limits>
#include <typeinfo>
// #include "utils.hpp"
#include "tools/iterator_traits.hpp"
#include "tools/reverse_iterator.hpp"
#include "tools/is_integral.hpp"
#include "tools/enable_if.hpp"

namespace ft
{
    template < class T, class alloc = std::allocator <T> >
	class vector
	{
        public:
			typedef T                                                       value_type;
        	typedef alloc                                                   allocator_type;
        	typedef typename allocator_type::reference                      reference;
        	typedef typename allocator_type::const_reference                const_reference;
        	typedef typename allocator_type::pointer                        pointer;
        	typedef typename allocator_type::const_pointer                  const_pointer;
        	typedef std::ptrdiff_t 											difference_type;
        	typedef typename allocator_type::size_type                     	size_type;

        private:
            value_type *_array;
            size_type  _capacity;
            size_type  _size;
            allocator_type _alloc;

			void init_data(size_type n, const value_type val) {
				_array = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)	
					_alloc.construct(&_array[i],val);
				_size = n;
				_capacity = n;
			}
			
			void destroy_data() {
				for (size_type i = 0; i < _size; i++)	
					_alloc.destroy(&(_array[i]));
			}

        public:
		
			class iterator
			{
				public:
					typedef ptrdiff_t							difference_type;
					typedef T									value_type;
					typedef value_type*							pointer;
					typedef value_type&							reference;
					typedef ft::random_access_iterator_tag		iterator_category;

				protected:
					value_type 		*_curr;
					
				public:
					iterator() { _curr = nullptr; }
					iterator(value_type* value) { _curr = value; }
					iterator(const iterator& src) { _curr = src._curr; }
					~iterator() {}

					iterator							&operator=(const iterator &rhs){
						if ( this != &rhs) {
							_curr = rhs._curr;
						}
						return *this;
					}
					
					reference							operator*(void) const { return *(_curr); }
					pointer								operator->(void) const { return _curr; }					
					iterator::difference_type			operator+(const iterator & rhs) { return (_curr + rhs._curr); }					
					iterator::difference_type			operator-(const iterator & rhs) { return (_curr - rhs._curr); }					
					iterator							operator+(difference_type n) { return iterator(_curr + n); }					
					iterator							operator-(difference_type n) { return iterator(_curr - n); }
					
					iterator							&operator+=(difference_type n) {
						_curr += n;
						return *this;
					}

					iterator							&operator-=(difference_type n) {
						_curr -= n;
						return *this;
					}

					bool								operator!=(const iterator &rhs) const {
						return (_curr != rhs._curr);
					}

					bool								operator==(const iterator &rhs) const {
						return (_curr == rhs._curr);
					}
					
					iterator							&operator++(void) {
						
						++_curr;
						return *this;
					}

					iterator							operator++(int) {
						iterator cpy(*this);
						++_curr;
						return cpy;
					}

					iterator							&operator--(void) {
						--_curr;
						return *this;
					}

					iterator							operator--(int) {
						iterator cpy(*this);
						--_curr;
						return cpy;
					}
					bool								operator<(const iterator& rhs) {
						return (_curr < rhs._curr);
					}
					
					bool								operator>(const iterator& rhs) {
						return (_curr > rhs._curr);
					}
					
					bool								operator<=(const iterator& rhs) {
						return (_curr <= rhs._curr);
					}
					
					bool								operator>=(const iterator& rhs) {
						return (_curr >= rhs._curr);
					}

			};

			class const_iterator
			{
				public:
					typedef const T							value_type;
					typedef value_type&						reference;
					typedef value_type*						pointer;
					typedef ptrdiff_t						difference_type;
					typedef ft::random_access_iterator_tag	iterator_category;

				protected:
					value_type 		*_curr;
					
				public:
					const_iterator() { _curr = nullptr; }
					const_iterator(value_type* value) { _curr = value; }
					const_iterator(const const_iterator& src) { _curr = src._curr; }
					~const_iterator() {}

					const_iterator							&operator=(const const_iterator &rhs) {
						if ( this != &rhs)
						{
							_curr = rhs._curr;
						}
						return *this;
					}

					reference								operator*(void) const {
						return *(_curr);
					}

					pointer									operator->(void) const {
						return (_curr);
					}
					
					const_iterator::difference_type			operator+(const const_iterator & rhs) {
						return (_curr + rhs._curr);
					}
					
					const_iterator::difference_type			operator-(const const_iterator & rhs) {
						return (_curr - rhs._curr);
					}
					
					const_iterator							operator+(difference_type n) {
						return const_iterator(_curr + n);
					}
					
					const_iterator							operator-(difference_type n) {
						return const_iterator(_curr - n);
					}
					
					const_iterator							&operator+=(difference_type n) {
						_curr += n;
						return *this;
					}

					const_iterator							&operator-=(difference_type n) {
						_curr -= n;
						return *this;
					}

					bool									operator!=(const const_iterator &rhs) const {
						return (_curr != rhs._curr);
					}
					
					bool									operator==(const const_iterator &rhs) const {
						return (_curr == rhs._curr);
					}
					const_iterator							&operator++(void) {
						++_curr;
						return *this;
					}

					const_iterator							operator++(int) {
						const_iterator cpy(*this);
						++_curr;
						return cpy;
					}

					const_iterator							&operator--(void) {
						--_curr;
						return *this;
					}

					const_iterator							operator--(int) {
						const_iterator cpy(*this);
						--_curr;
						return cpy;
					}

					bool									operator<(const const_iterator& rhs) {
						return (_curr < rhs._curr);
					}
					
					bool									operator>(const const_iterator& rhs) {
						return (_curr > rhs._curr);
					}
					
					bool									operator<=(const const_iterator& rhs) {
						return (_curr <= rhs._curr);
					}
					
					bool									operator>=(const const_iterator& rhs) {
						return (_curr >= rhs._curr);
					}

			};
		
			typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>     		const_reverse_iterator;
		
			//constructor
			
			vector(const allocator_type& allocator = allocator_type()) : _array(0), _capacity(0), _size(0), _alloc(allocator) {}
			
	        vector(size_type n, const value_type& val = value_type(), const allocator_type &allocator = allocator_type()): _array(0), _capacity(n), _size(n), _alloc(allocator) {
	    	    init_data(n,val);
	    	}
	
	        template <class InputIterator>
	        vector(InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& allocator = allocator_type()) : _alloc(allocator) {
				size_type	i = 0;
				
				_size = last - first;
				_capacity = _size << 1;
				_array = allocator_type(_alloc).allocate(_capacity, 0);
				while (i < _size)
					_array[i++] = *(first++);
			}
	
	        vector (const vector& src) : _capacity(src._capacity),_size(src._size), _alloc(allocator_type(src._alloc)) {
				size_type	i = 0;
	
				_array = _alloc.allocate(_capacity);
				while (i < _size)
				{
					_array[i] = src._array[i];
					i++;
				}
			}
			
	        ~vector() {
				destroy_data();
	        	_alloc.deallocate(_array, _capacity);
			}
			
			vector& operator= (const vector& x) {
				_array = _alloc.allocate(x._capacity);
				_capacity = x._capacity;
	        	assign(x.begin(),x.end());
	  			return *this;
			}
	
			//Iterators
	
			iterator				begin() { return iterator(_array); }
			const_iterator			begin() const { return const_iterator(_array); }
	
			iterator				end() { return iterator(&_array[_size]); }
			const_iterator			end() const { return const_iterator(&_array[_size]); }
			
			reverse_iterator 		rbegin() { return reverse_iterator(end()); }
			const_reverse_iterator 	rbegin() const { return const_reverse_iterator(end()); }
	
			reverse_iterator		rend() { return reverse_iterator(begin()); }
			const_reverse_iterator	rend() const { return const_reverse_iterator(begin()); }
			
			//Capacity
	
			size_type size() const { return _size; }
			size_type max_size() const {
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
			
			void resize (size_type n, value_type val = value_type()) {
	        	if (n <= _size)
	        	{
	        	    while(_size > n)
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
			}
			
			size_type capacity(void) const { return _capacity; }
			bool empty() const { return (_size == 0); }
			void reserve (size_type n) {
				if(n <= _capacity)
		            return;
		        if(n > max_size())
		            n = max_size();
				size_type	oldcapacity = _capacity;
				if(_capacity == 0)
		            _capacity++;
				while(_capacity < n)
					_capacity *= 2;
				T *tmp = _alloc.allocate(_capacity);
		        size_type i = 0;
		        while(i < _size)
				{
					_alloc.construct(&tmp[i],_array[i]);
					i++;
				}
				destroy_data();
		        _alloc.deallocate(_array,oldcapacity);
				_array = tmp;
		    }
	
			//Element access
			
			reference operator[] (size_type n) { return _array[n]; }
			const_reference operator[] (size_type n) const { return _array[n]; }
	
			reference at (size_type n) { return _array[n]; }
			const_reference at (size_type n) const { return _array[n]; }
	
			reference front() { return _array[0]; }
			const_reference front() const { return _array[0]; }
			
			reference back() { return _array[_size - 1]; }
			const_reference back() const { return _array[_size - 1]; }
	
			//Modifiers
			
			template < class InputIterator >
	  		void assign (InputIterator first, typename ft::enable_if < !is_integral < InputIterator >::value, InputIterator >::type last) {
				for (size_type i = 0; i < _size; i++)
					_array[i].~value_type();
				_size = last - first;
				if (_size > _capacity)
				{
					_alloc.deallocate(_array, _capacity);
					_capacity = _size * 2;
					_array = _alloc.allocate(_capacity);
				}
		        size_type	i = 0;
				while (first != last)
				{
					_array[i++] = *first;
					first++;
				}
			}
			
			void assign (size_type n, const value_type& val) {
	        	reserve(n);
	        	resize(n);
				for (size_type i = 0; i != n; i++)
	        	    _alloc.construct(&_array[i],val);
			}
			
			void push_back (const value_type& val) {
				value_type	*new_array;
		
				if (_size == _capacity)
				{
					_capacity = (_size + 1) * 2;
					new_array = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						new_array[i] = _array[i];
					_alloc.deallocate(_array, _size);
					_array = new_array;
				}
				value_type *tmp = _array + _size;
				tmp = new (tmp) value_type(val);
				_size++;
	    	}
	
			void pop_back() {
				_alloc.destroy(&_array[_size]);
				reserve(_size - 1);
				_size--;
			}
			
			iterator insert (iterator position, const value_type& val) {
		        value_type	*new_array;
				iterator	it;
				iterator	it_end;
				size_type	i;
				size_type	location;
		
				if (_size + 1 == _capacity)
				{
					_capacity = _size << 1;
					new_array = _alloc.allocate(_capacity);
					i = 0;
					it = begin();
					it_end = end();
					while (it != position)
						new_array[i++] = *(it++);
					location = i;
					new_array[i++] = val;
					while (it != it_end)
						new_array[i++] = *(it++);
					_alloc.deallocate(_array, _size);
					_array = new_array;
				}
				else
				{
					it = end();
					while (it != position)
					{
						*it = *(it - 1);
						it--;
					}
					location = position - begin();
					*it = val;
				}
				_size++;
				return (iterator(_array + location));
			}
			
	    	void insert (iterator position, size_type n, const value_type& val) {
				value_type	*new_array;
				iterator	it;
				iterator	it_end;
				size_type	i;
				size_type	new_capacity;
	
				if (_capacity < _size + n)
				{
					_size += n;
					new_capacity = _size * 2;
					new_array = _alloc.allocate(new_capacity);
					i = 0;
					it = begin();
					it_end = end();
					while (it != position)
					new_array[i++] = *(it++);
					n += i;
					while (i < n)
						new_array[i++] = val;
					new_array[i++] = val;
					while (it != it_end)
						new_array[i++] = *(it++);
					_alloc.deallocate(_array, _capacity);
					_capacity = new_capacity;
					_array = new_array;
				}
				else
				{
					_size += n;
					it = end() + (n - 1);
					while (it != position + (n - 1))
					{
						*it = *(it - n);
						it--;
					}
					while (it != position - 1)
						*(it--) = val;
				}
			}
			
			template <class InputIterator>
	   		void insert (iterator position, InputIterator first,typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
				value_type	*new_array;
				size_type	insert_size;
				iterator	it;
				iterator	it_end;
				size_type	i;
				insert_size = last - first;
				if (_capacity < _size + insert_size) {
					_capacity = (_size + insert_size) << 1;
					new_array = _alloc.allocate(_capacity);
					it = begin();
					i  = 0;
					while(it != position)
						new_array[i++] = *(it++);
					while(first != last)
						new_array[i++] = *(first++);
					it_end = end();
					while(it < it_end)
						new_array[i++] = *(it++);
					_alloc.deallocate(_array,_size);
					_array = new_array;
				} else {
					it = end() +(insert_size - 1);
					while(it != position + (insert_size - 1))
					{
						*it = *(it - insert_size);
						it --;
					}
					while(last != first)
						*(it--) = *(--last);
				}
				_size += insert_size; 
			}
	
			iterator erase (iterator position) {
	       		iterator ret = begin();
				iterator it = ret;
				for (; it != end() && it != position; ++it)
					;
				if (it == end())
					return ret;
				ret = it + 1;
				while (it != end() - 1)
				{
					*it = *(it + 1);
					++it;
				}
				--_size;
				return ret;
			}
			
			iterator erase (iterator first, iterator last) {
				iterator	ret = begin();
				iterator	it_first = ret;
				iterator	it_last = ret;
	
				for (; it_first != end() && it_first != first; ++it_first)
					;
				for (; it_last != end() && it_last != last; ++it_last)
					;
				if (it_first == end() || it_last == end())
					return ret;
				while (it_first != end() && it_last != end())
				{
					*it_first = *it_last;
					++it_first;
					++it_last;
				}
				_size -= std::abs(last - first);
				return it_first;
			}
			void swap (vector& x) {
				size_type	tmpc = _capacity;
				size_type	tmps = _size;
				value_type *tmpd = _array;				
				
				_array = x._array;
				_capacity = x._capacity;
				_size = x._size;
				x._array = tmpd;
				x._capacity = tmpc;
				x._size = tmps; 
			}
			void clear() {
				destroy_data();
				_size = 0;
			}
	
			//Allocator
			allocator_type get_allocator() const { return _alloc; }
	
	};
	
	//No-member
	template < class T, class alloc >
  	void swap (vector < T, alloc >& x, vector < T, alloc >& y) {
		 x.swap(y); 
	}

	template < class T, class alloc >
	bool operator==(const vector<T,alloc>& lhs, const vector<T,alloc>& rhs) {
		// return (ft::equal < const_iterator, const_iterator >(lhs.begin(), lhs.end(), rhs.begin()));
		return (lhs == rhs);
	}

	template < class T, class alloc >
	bool operator!=(const vector<T,alloc>& lhs, const vector<T,alloc>& rhs) {
		return !(lhs == rhs);
	}

	template < class T, class alloc >
	bool operator<(const vector<T,alloc>& lhs, const vector<T,alloc>& rhs) {
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());	
	}

	template < class T, class alloc >
	bool operator<=(const vector<T,alloc>& lhs, const vector<T,alloc>& rhs) {
		return !(rhs < lhs);	
	}

	template < class T, class alloc >
	bool operator>(const vector<T,alloc>& lhs, const vector<T,alloc>& rhs) {
		return (rhs < lhs);	
	}

	template < class T, class alloc >
	bool operator>=(const vector<T,alloc>& lhs, const vector<T,alloc>& rhs) {
		return !(rhs < lhs);	
	}
}
/*	
	  	void swap (vector& x, vector& y) {
			 x.swap(y); 
		}
	
		bool operator==(const vector& lhs, const vector& rhs) {
			return (ft::equal < vector::const_iterator, vector::const_iterator >(lhs.begin(), lhs.end(), rhs.begin()));
		}
	
		bool operator!=(const vector& lhs, const vector& rhs) {
			return !(lhs == rhs);
		}
	
		bool operator<(const vector& lhs, const vector& rhs) {
			return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());	
		}
	
		bool operator<=(const vector& lhs, const vector& rhs) {
			return !(rhs < lhs);	
		}
	
		bool operator>(const vector& lhs, const vector& rhs) {
			return (rhs < lhs);	
		}
	
		bool operator>=(const vector& lhs, const vector& rhs) {
			return !(rhs < lhs);	
		}
	}
	
*/