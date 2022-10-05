/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:41:26 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/17 18:45:27by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>

#include "iterator/iterator.hpp"
#include "tools/exceptions.hpp"
#include "tools/tools.hpp"

namespace ft {
	template < typename T, class alloc = std::allocator<T> >
	class vector {
		public:
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef const T* const_pointer;
			typedef const T& const_reference;
			typedef size_t size_type;
			typedef ptrdiff_t difference_type;
			typedef alloc allocator_type;
		
			class VectorIterator : public ft::iterator<std::bidirectional_iterator_tag, value_type> {
				public:
					typedef typename ft::iterator_traits<vector<T, alloc> >::difference_type	difference_type;
					typedef typename ft::iterator_traits<vector<T, alloc> >::value_type			value_type;
					typedef typename ft::iterator_traits<vector<T, alloc> >::pointer			pointer;
					typedef typename ft::iterator_traits<vector<T, alloc> >::reference			reference;
					typedef typename ft::iterator_traits<vector<T, alloc> >::iterator_category	iterator_category;
				protected:
					pointer _array;
		
				public:
					VectorIterator(void) : _array(NULL) {}
					VectorIterator(pointer array) : _array(array) {}
					VectorIterator(const VectorIterator& it) : _array(it.base()) {}
			
					pointer		base() const { return _array; }
					reference operator*() const {
						return *_array;
					}
					pointer operator->() const {
						return _array;
					}
					VectorIterator& operator++() {
						_array++;
						return *this;
					}
					VectorIterator operator++(int) {
						VectorIterator tmp = *this;
						++(*this);
						return tmp;
					}
					VectorIterator& operator--() {
						_array--;
						return *this;
					}
					VectorIterator operator--(int) {
						VectorIterator tmp = *this;
						--(*this);
						return tmp;
					}
					VectorIterator& operator+=(difference_type n) {
						_array += n;
						return *this;
					}
					VectorIterator operator+(difference_type n) const {
						return VectorIterator(_array + n);
					}
					VectorIterator& operator-=(difference_type n) {
						_array -= n;
						return *this;
					}
					VectorIterator operator-(difference_type n) const {
						return VectorIterator(_array - n);
					}
					difference_type operator-(const VectorIterator& it) const { return _array - it._array; }
					reference operator[](difference_type n) const { return _array[n]; }
					bool operator==(const VectorIterator& it) const { 
						return _array == it._array; }
					bool operator!=(const VectorIterator& it) const { return _array != it._array; }
					bool operator<(const VectorIterator& it) const { return _array < it._array; }
					bool operator>(const VectorIterator& it) const { return _array > it._array; }
					bool operator<=(const VectorIterator& it) const { return _array <= it._array; }
					bool operator>=(const VectorIterator& it) const { return _array >= it._array; }
			};
			
			class VectorReverseIterator : public ft::iterator<std::bidirectional_iterator_tag, value_type> {
				public:
					typedef typename ft::iterator_traits<vector<T, alloc> >::difference_type difference_type;
					typedef typename ft::iterator_traits<vector<T, alloc> >::value_type value_type;
					typedef typename ft::iterator_traits<vector<T, alloc> >::pointer pointer;
					typedef typename ft::iterator_traits<vector<T, alloc> >::reference reference;
					typedef typename ft::iterator_traits<vector<T, alloc> >::iterator_category iterator_category;

				protected:
					pointer _array;
			
				public:
					VectorReverseIterator(void) : _array(NULL) {}
					VectorReverseIterator(pointer array) : _array(array) {}
					VectorReverseIterator(const VectorReverseIterator& it) : _array(it.base()) {}
			
					pointer		base() const { 
						return _array; }
					reference operator*() const {
						pointer		tmp = _array;
						return (*(--tmp));
					}
					pointer operator->() const {
						pointer		tmp = _array;
						return (&(*(--tmp)));
					}
			
					VectorReverseIterator& operator++() {
						_array--;
						return *this;
					}
					VectorReverseIterator operator++(int) {
						VectorReverseIterator tmp = *this;
						++*this;
						return tmp;
					}
					VectorReverseIterator& operator--() {
						_array++;
						return *this;
					}
					VectorReverseIterator operator--(int) {
						VectorReverseIterator tmp = *this;
						--*this;
						return tmp;
					}
					VectorReverseIterator& operator+=(difference_type n) {
						_array -= n;
						return *this;
					}
					VectorReverseIterator operator+(difference_type n) const {
						VectorReverseIterator tmp = *this;
						tmp += n;
						return tmp;
					}
					VectorReverseIterator& operator-=(difference_type n) {
						_array += n;
						return *this;
					}
					VectorReverseIterator operator-(difference_type n) const {
						VectorReverseIterator tmp = *this;
						tmp -= n;
						return tmp;
					}
					difference_type operator-(const VectorReverseIterator& it) const { return _array - it._array; }
					reference operator[](difference_type n) const { return _array[-n - 1]; }
					bool operator==(const VectorReverseIterator& it) const {
						return _array == it._array; }
					bool operator!=(const VectorReverseIterator& it) const { return _array != it._array; }
					bool operator<(const VectorReverseIterator& it) const { return _array < it._array; }
					bool operator>(const VectorReverseIterator& it) const { return _array > it._array; }
					bool operator<=(const VectorReverseIterator& it) const { return _array <= it._array; }
					bool operator>=(const VectorReverseIterator& it) const { return _array >= it._array; }
			};

			typedef VectorIterator			iterator;
			typedef VectorIterator			const_iterator;
			typedef VectorReverseIterator	reverse_iterator;
			typedef VectorReverseIterator	const_reverse_iterator;

		protected:
			alloc		_alloc;
			pointer		_array;
			size_type	_size;
			size_type	_capa;

		public:
			//CONSTRUCT
			explicit vector(const allocator_type& alloct = allocator_type())
				: _alloc(alloct), _array(NULL), _size(0), _capa(0) {}
				
			explicit vector(size_type n, const T& value = T(), const allocator_type& alloct = allocator_type())
				: _alloc(alloct), _size(n), _capa(n) {
				_array = _alloc.allocate(_capa);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], value);
			}

			template <class InputIt>
			vector(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt >::type first, InputIt last, const allocator_type& alloct = allocator_type())
				: _alloc(alloct) {
				if (first > last)
					throw std::out_of_range("ft::vector::vector : first > last");
				if (first == last) {
					_array = NULL;
					_size = 0;
					_capa = 0;
				} else {
					_size = last - first;
					_capa = _size;
					_array = _alloc.allocate(_capa);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(&_array[i], *first);
						first++;
					}
				}
			}
			
			vector(const vector& other) {
				_size = other._size;
				_capa = _size;
				_array = _alloc.allocate(_capa);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], other._array[i]);
			}
			
			vector(const vector& other, const allocator_type& alloct)
				: _alloc(alloct) {
				_size = other._size;
				_capa = _size;
				_array = _alloc.allocate(_capa);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], other._array[i]);
			}
			
			//DESTRUCT
			virtual ~vector() {
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(&_array[i]);
				}
				_alloc.deallocate(_array, _capa);
			}
			
			// COPY
			vector&			operator=(const vector& rhs) {
				if (this != &rhs) {
					clear();
					_alloc.deallocate(_array, _capa);
					_alloc = rhs._alloc;
					_size = rhs._size;
					if (_capa < _size)
						_capa = _size;
					_array = _alloc.allocate(_capa);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(&_array[i], rhs._array[i]);
					}
				}
				return *this;
			}
			
			void			assign(size_type count, const T& value) {
				clear();
				if (count > _capa) {
					_alloc.deallocate(_array, _capa);
					_capa = count << 1;
					_array = _alloc.allocate(_capa);
				}
				_size = count;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], value);
			}
			
			template <class InputIt>
			void			assign(typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt >::type first, InputIt last) {
				if (first > last)
					throw std::out_of_range("ft::vector::assign : first > last");
				clear();
				if (first == last) {
					clear();
					return;
				}
				size_type delta = last - first;
				if (delta > _capa) {
					reserve(delta);
				}
				_size = delta;
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(&_array[i], *first);
					first++;
				}
			}
			
			allocator_type	get_allocator() const { return _alloc; }
			
			//ELEMENT ACCESS
			reference		at(size_type n) {
				if (n >= _size) {
					throw OutOfRangeException();
				}
				return _array[n];
			}
			const_reference		at(size_type n) const {
				if (n >= _size) {
					throw OutOfRangeException();
				}
				return _array[n];
			}
			reference		operator[](size_type n) { return _array[n]; }
			const_reference		operator[](size_type n) const { return _array[n]; }
			reference front() { return _array[0]; }
			const_reference	front() const { return _array[0]; }
			reference back() { return _array[_size - 1]; }
			const_reference	back() const { return _array[_size - 1]; }
			T*				data() { return _array; }
			
			//ITERATOR
			iterator begin(void) { return _array; };
			iterator end(void) { return _array + _size; };
			const_iterator begin(void) const { return _array; };
			const_iterator end(void) const { return _array + _size; };
			reverse_iterator rbegin(void) { return _array + _size; };
			reverse_iterator rend(void) { return _array; };
			const_reverse_iterator rbegin(void) const { return _array + _size; };
			const_reverse_iterator rend(void) const { return _array; };
		
			//CAPACITY
			bool			empty(void) const { return _size == 0; }
			size_type		size(void) const { return _size; }
			size_type		max_size(void) { return _alloc.max_size(); }
			size_type		capacity(void) const { return _capa; }
			void			reserve(size_type n) {
				if (n == 0) {
					n = 1;
				}
				if (n > _capa) {
					_capa = n;
					T* tmp = _alloc.allocate(_capa);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(&tmp[i], _array[i]);
						_alloc.destroy(&_array[i]);
					}
					_alloc.deallocate(_array, _capa);
					_array = tmp;
				}
			}
			void			clear() {
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(&_array[i]);
				}
				_size = 0;
			}
			
			//MODIFIERS
			iterator		insert(iterator pos, const T& val) {
				difference_type delta = pos - this->begin();
				if (_size >= _capa) {
					reserve(_capa << 1);
				}
				for (size_type i = _size; i > size_type(delta); i--) {
					_alloc.construct(&_array[i], _array[i - 1]);
					_alloc.destroy(&_array[i - 1]);
				}
				_alloc.construct(&_array[delta], val);
				_size++;
				return pos;
			}
			void			insert(iterator pos, size_type count, const T& value) {
				difference_type delta = pos - this->begin();
		        if (_size + count > _capa) {
					reserve(_capa << 1);
				}
				for (difference_type i = _size; i > delta; i--) {
					_alloc.construct(&_array[i + count - 1], _array[i - 1]);
					_alloc.destroy(&_array[i - 1]);
				}
				for (size_type i = 0; i < count; i++) {
					_alloc.construct(&_array[delta + i], value);
				}
				_size += count;
			}
			template <class InputIt>
			void			insert(iterator pos, InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt >::type last) {
				if (first == last) {
					return;
				} else if (first > last) {
					throw std::out_of_range("ft::Vector::insert : first > last");
				}
				if (pos < this->begin()) {
					throw std::out_of_range("ft::Vector::insert : pos < this->begin()");
				} else if (pos > this->end()) {
					throw std::out_of_range("ft::Vector::insert : pos > this->end()");
				}

				difference_type count = pos - this->begin();
				difference_type delta = last - first;

				if (_size + delta > _capa) {
					reserve(_size << 1);
				}
				for (difference_type i = _size; i > count; i--) {
					_alloc.construct(&_array[i + delta - 1], _array[i - 1]);
					_alloc.destroy(&_array[i - 1]);
				}
				for (difference_type i = 0; i < delta; i++) {
					_alloc.construct(&_array[count + i], *(first + i));
				}
				_size += delta;
			}
			iterator		erase(iterator pos) {
				if (size_type(pos - this->begin()) >= _size) {
					throw OutOfRangeException();
				}
				for (size_type i = pos - this->begin(); i < _size - 1; i++) {
					_alloc.construct(&_array[i], _array[i + 1]);
				}
				_alloc.destroy(&_array[_size - 1]);
				_size--;
				return _array + size_type(pos - this->begin());
			}
			iterator		erase(iterator first, iterator last) {
				if (first > last) {
					throw std::out_of_range("ft::Vector::erase : first > last");
				}
				size_type delta = last - first;
				if (size_type(first - this->begin()) >= _size || size_type(last - this->begin()) >= _size) {
					throw OutOfRangeException();
				}
				for (size_type i = (size_type(first - this->begin())); i < _size - delta; i++) {
					_alloc.construct(&_array[i], _array[i + delta]);
				}
				for (size_type i = 0; i < delta; i++) {
					_alloc.destroy(&_array[_size - 1 - i]);
				}
				_size -= delta;
				return _array + size_type(first - this->begin());
			}
			void			push_back(const T& val) {
				if (_size >= _capa) {
					reserve(_capa << 1);
				}
				_alloc.construct(&_array[_size], val);
				_size++;
			}
			void			pop_back() {
				_alloc.destroy(&_array[_size - 1]);
				_size--;
			}
			void			resize(size_type n, T val = T()) {
				if (n > _capa) {
					if (n < (_capa << 1))
						_capa <<= 1;
					else
						_capa = n;
					T* tmp = _alloc.allocate(_capa);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(&tmp[i], _array[i]);
						_alloc.destroy(&_array[i]);
					}
					_alloc.deallocate(_array, _capa);
					_array = tmp;
				}
				if (n > _size) {
					for (size_type i = _size; i < n; i++) {
						_alloc.construct(&_array[i], val);
					}
				}
				_size = n;
			}
			void			swap(vector& v) {
				std::swap(_alloc, v._alloc);
				std::swap(_array, v._array);
				std::swap(_size, v._size);
				std::swap(_capa, v._capa);
			}
	};
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs || lhs < rhs));
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}
}