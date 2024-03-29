/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:20:06 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/21 17:08:45y bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/nodes.hpp"
#include "tools/exceptions.hpp"
#include "iterator/iterator.hpp"
#include <list>
#include <memory>

namespace ft {

	template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
			typedef Key										key_type;
			typedef T										mapped_type;

			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef ft::node<value_type>*					nodePtr;
			typedef ft::node<value_type>&					nodeRef;
			typedef ft::node<value_type>					nodeType;
			// typedef ft::pair<const value_type>&			pairRef;
			// typedef ft::pair<const value_type>*			pairPtr;

			typedef typename Alloc::pointer					pointer;
			typedef typename Alloc::const_pointer			const_pointer;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef Alloc									allocator_type;

			class value_compare {
				public:
					value_compare(Compare comp) : comp(comp) {}
					bool operator()(const value_type& lhs, const value_type& rhs) const {
						return comp(lhs.first, rhs.first);
					}

				private:
					Compare comp;
			};
// class value_compare : public std::binary_function<value_type, value_type, bool>
		// {
			// friend class map;
			// public :
				// typedef bool							result_type;
				// typedef value_type						first_argument_type;
				// typedef value_type						second_argument_type;
// 
				// bool operator()(const value_type& lhs, const value_type& rhs) const {
					// return _comp(lhs.first, rhs.first);
				// }
			// protected :
// 
				// value_compare(Compare c) : _comp(c) {}
				// Compare _comp;
		// };
			class MapIterator : public ft::iterator<bidirectional_iterator_tag, T>
			{
				public :
					typedef std::ptrdiff_t						difference_type;
					// typedef T									value_type;
					typedef value_type*							pointer;
					typedef value_type&							reference;
					typedef bidirectional_iterator_tag			iterator_category;

					MapIterator(void) : _ptr(0) {}
					MapIterator(nodePtr node) : _ptr(node) {}
					MapIterator(const MapIterator& rhs) : _ptr(rhs._ptr) {}
					virtual ~MapIterator(void) {}

					MapIterator&		operator=(node<value_type> * rhs) {
						_ptr = rhs;
						return *this;
					}
					MapIterator&		operator=(const MapIterator& rhs) {
						_ptr = rhs._ptr;
						return *this;
					}

					bool				operator==(const MapIterator& rhs) const { return (_ptr == rhs._ptr); }
					bool				operator!=(const MapIterator& rhs) const { return (_ptr != rhs._ptr); }

					reference			operator*(void) { return *(_ptr->get_value()); }
					value_type*			operator->(void) const { return (_ptr->get_value()); }

					MapIterator&		operator++(void) {
						_ptr = _neighbor(RIGHT);
						return *this;
					}
					MapIterator		operator++(int) {
						MapIterator tmp = *this;
						++(*this);
						return (tmp);
					}
					MapIterator&		operator--(void) {
						_ptr = _neighbor(LEFT);
						return *this;
					}
					MapIterator		operator--(int) {
						MapIterator tmp = *this;
						--(*this);
						return (tmp);
					}


				protected :
					nodePtr _ptr;

				private :
					nodePtr			_neighbor(bool dir) const {
						nodePtr	tmp = _ptr;

						if (!tmp)
							return 0;
						if (tmp->get_child(dir) && tmp->get_child(dir)->get_value()) {
							tmp = tmp->get_child(dir);
							while (tmp->get_child(!dir) && tmp->get_child(!dir)->get_value())
								tmp = tmp->get_child(!dir);
							return tmp;
						} else if (tmp->get_parent()) {
							if (tmp->get_side() != dir)
								return (tmp->get_parent());
							else {
								while (tmp->get_parent() && tmp->get_side() == dir)
									tmp = tmp->get_parent();
								if (!tmp->get_parent())
									return(_ptr->get_child(dir));
								return(tmp->get_parent());
							}
						} else
							return _ptr->get_child(dir);
					}
			};

			typedef Compare				key_compare;

			typedef MapIterator								iterator;
			typedef MapIterator								const_iterator;
			typedef ft::reverse_iterator< iterator >		reverse_iterator;
			typedef ft::reverse_iterator< const_iterator >	const_reverse_iterator;

		private:
			nodePtr				_root;
			size_type			_size;
			allocator_type		_alloc;
			key_compare			_comp;

		public:
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = Alloc())
			: _size(0), _alloc(alloc), _comp(comp) {
			_root = new nodeType();
		}
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = Alloc())
			: _size(0), _alloc(alloc), _comp(comp) {
			_root = new nodeType();
			insert(first, last);
		}
		map(const map& other) : _root(NULL), _size(0), _alloc(other._alloc), _comp(other._comp) {
			_root = new nodeType();
			*this = other;
		}

		// DESTRUCTEUR

		~map(void) {
			// std::cout << _root->get_value()->first << std::endl;
			// printBT(_root);
			if (_size)
				clear();
			if (_root) 
				delete _root;
				
			// std::cout << "\e[34m" << "miracle !" << "\e[0m" << std::endl; 
		}

		// OPERATOR
		map&			operator=(const map& other) {
			if (this != &other) {
				clear();
				if (other.size() > 0) {
					insert(other.begin(), other.end());
					_root->set_color(BLACK);
				}
			}
			return *this;
		}
		// GETTEUR
		allocator_type	get_allocator() const {
			return _alloc;
		}
	
		// ELEMENT ACCESS
		T&				at(const Key& key) {
			nodePtr		tmp = _find(key);

			if (!tmp)
				std::out_of_range("");
			return (tmp->get_value()->second);
		}
		const T&		at(const Key& key) const {
			nodePtr		tmp = _find(key);

			if (!tmp)
				std::out_of_range("");
			return (tmp->get_value()->second);
		}
		T&				operator[](const Key& key) {
			nodePtr		tmp = _find(key);

			if (!tmp) {
				insert(ft::make_pair<key_type, mapped_type>(key, mapped_type()));
				return (at(key));
			}
			return (tmp->get_value()->second);
		}

		// ITERATOR

		iterator				begin() { return iterator(_begin()); }
		const_iterator			begin() const { return const_iterator(reinterpret_cast<nodePtr>(_begin())); }
		iterator				end() { return iterator(_end()); }
		const_iterator			end() const { return const_iterator(reinterpret_cast<nodePtr>(_end())); }
		reverse_iterator		rbegin() { return reverse_iterator(_end()); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(rbegin()); }
		reverse_iterator		rend() { return reverse_iterator(_begin()); }
		const_reverse_iterator	rend() const { return const_reverse_iterator(rend()); }

		// CAPACITY
		bool empty() const { return (!_size); }
		size_type size() const { return _size; }
		size_type max_size() const {
			return _alloc.max_size();
		}

		// MODIFIERS
		void		clear() {
			erase(begin(), end());
		}
		// void clear() {
			// printBT(_root);
			// _clear_tree(_root);
			// _root = NULL;
			// _size = 0;
		// }

		// INSERT
		ft::pair<iterator, bool>	insert(const value_type& value) {
			nodePtr		tmp = _find(value.first);

			if (tmp)
				return (ft::make_pair(iterator(tmp), false));
			pointer new_value = _alloc.allocate(1);
			_alloc.construct(new_value, value_type(value));

			nodePtr		new_ptr = new nodeType(new_value);

			_simple_insert(new_ptr);
			_red_black(new_ptr);
			_size++;
			return (ft::make_pair(iterator(new_ptr), true));
		}
		iterator insert(iterator pos, const value_type& value) {
			(void)pos;
			pair<iterator, bool> res;
			res = insert(value);
			return res.first;
		}
		template<class InputIt>
		void insert(InputIt first, typename ft::enable_if<!is_integral<InputIt>::value, InputIt>::type last) {
			while (first != last) {
				insert(*first);
				first++;
			}
		}
		
		// ERASE && SWAP
		void	erase(iterator pos) {
			if (_size > 1)
				_delete(pos, _find(pos->first));
			else {
				_alloc.destroy(_root->get_value());
				_alloc.deallocate(_root->get_value(), 1);
				delete _root;
				_root = new nodeType();
			}
			_size--;
		}
		void	erase(iterator first, iterator last) {
			iterator	next = first;
			iterator	now;
			
			while (next != last) {
				now = first;
				++first;
				next = first;
				erase(now);
			}
		}
		size_type	erase(const key_type& key) {
			nodePtr		old_node = _find(key);

			if (!old_node)
				return 0;
			if (_size > 1)
				_delete(iterator(old_node), old_node);
			else {
				_alloc.destroy(_root->get_value());
				_alloc.deallocate(_root->get_value(), 1);
				delete _root;
				_root = new nodeType();
			}
			_size--;
			return 1;
		}
		void		swap(map& rhs) {
			nodePtr		tmp_root;
			size_type	tmp_size;

			tmp_root = _root;
			_root = rhs._root;
			rhs._root = tmp_root;
			tmp_size = _size;
			_size = rhs._size;
			rhs._size = tmp_size;
		}

		// LOOK UP
		size_type	count(const Key& key) const {
			if (_find(key))
				return 1;
			return 0;
		}
		iterator	find(const Key& key) {
			nodePtr		tmp = _find(key);

			if (tmp)
				return (iterator(tmp));
			else
				return end();
		}
		const_iterator	find(const Key& key) const {
			nodePtr		tmp = _find(key);
			
			if (tmp)
				return (const_iterator(tmp));
			else
				return end();
		}
		ft::pair<iterator,iterator>				equal_range(const Key& key) {
			return (ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
		}
		ft::pair<const_iterator,const_iterator>	equal_range(const Key& key) const {
			return (ft::make_pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
		}
		iterator		lower_bound(const Key& key) {
			for (iterator it = begin(); it != end(); it++)
				if (!this->key_comp()(it->first, key))
					return (it);
			return (end());
		}
		const_iterator	lower_bound(const Key& key) const {
			for (const_iterator it = begin(); it != end(); it++)
				if (!this->key_comp()(it->first, key))
					return (it);
			return (end());
		}
		iterator		upper_bound(const Key& key) {
			for (iterator it = begin(); it != end(); it++)
				if (this->key_comp()(key, it->first))
					return (it);
			return (end());
		}
		const_iterator	upper_bound(const Key& key) const {
			for (const_iterator it = begin(); it != end(); it++)
				if (this->key_comp()(key, it->first))
					return (it);
			return (end());
		}

		// OBSERVERS
		key_compare		key_comp(void) const {
			return key_compare(_comp);
		}
		value_compare	value_comp(void) const {
			return _comp;
		}

	private:
		void		_clear_tree(nodePtr node) {
			if (!node)
				return;
			_clear_tree(node->get_child(LEFT));
			_clear_tree(node->get_child(RIGHT));
			std::allocator<nodeType>().deallocate(node, 1);
			_size--;
		}
		nodePtr		_end() const {
			nodePtr		tmp = _root;

			while (tmp->get_child(RIGHT))
				tmp = tmp->get_child(RIGHT);
			return tmp;
		}
		nodePtr		_begin() const {
			nodePtr		tmp = _root;

			while (tmp->get_child(LEFT) && tmp->get_child(LEFT)->get_value())
				tmp = tmp->get_child(LEFT);
			return tmp;
		}
		nodePtr		_rend() const {
			nodePtr		tmp = _root;

			while (tmp->get_child(RIGHT) && tmp->get_child(RIGHT)->get_value())
				tmp = tmp->get_child(RIGHT);
			return tmp;
		}
		nodePtr		_rbegin() const {
			nodePtr		tmp = _root;

			while (tmp->get_child(LEFT))
				tmp = tmp->get_child(LEFT);
			return tmp;
		}
		nodePtr		_find(key_type key) const {
			nodePtr		tmp = _root;

			bool					dir;

			while (tmp && tmp->get_value()) {
				if (tmp->get_value()->first == key)
					return (tmp);
				dir = key_compare()(tmp->get_value()->first, key);
				tmp = tmp->get_child(dir);
			}
			return 0;
		}
		
		void	_rotate(nodePtr rhs, bool dir) {
			if (!rhs)
				return ;
			nodePtr		tmp = rhs->get_child(!dir);
			rhs->set_child(tmp->get_child(dir), !dir);
			tmp->get_child(dir)->set_parent(rhs);
			tmp->set_child(rhs, dir);
			tmp->set_parent(rhs->get_parent());
			if (!tmp->get_parent())
				_root = tmp;
			else
				rhs->get_parent()->set_child(tmp, rhs->get_side());
			tmp->set_child(rhs, dir);
			rhs->set_parent(tmp);	
		}
		void	_simple_insert(nodePtr new_ptr) {
			nodePtr		i = _root;
			bool		dir;

			if (!_root || !_root->get_value()) {
				delete _root;
				_root = new_ptr;
				return ;
			}
			while (i->get_value()) {
				dir = value_compare(_comp)(*(i->get_value()), *(new_ptr->get_value()));
				if (i->get_child(dir) && i->get_child(dir)->get_value())
					i = i->get_child(dir);
				else {
					delete i->get_child(dir);
					i->set_child(new_ptr, dir);
					new_ptr->set_parent(i);
					return ;
				}
			}
		}
		void	_red_black(nodePtr node) {
			bool		dir = LEFT;
			nodePtr		uncle;
	
			if (_root == node) {
				node->set_color(BLACK);
				return ;
			}
			while (node != _root && node->get_parent()->get_color() == RED) {
				uncle = node->get_uncle();
				dir = node->get_parent()->get_side();
				if (uncle && uncle->get_color() == RED) {
					node->get_parent()->set_color(BLACK);
					uncle->set_color(BLACK);
					uncle->get_parent()->set_color(RED);
					node = node->get_grand_parent();
				} else if (node->get_side() == !dir) {
					node = node->get_parent();
					_rotate(node, dir);
				} else {
					node->get_parent()->set_color(BLACK);
					node->get_grand_parent()->set_color(RED);
					node = node->get_grand_parent();
					_rotate(node, !dir);
				}
				_root->set_color(BLACK);
			}
		}
		void	_correct(nodePtr x)
		{
			nodePtr w;

			while (x != _root && x->get_color() == BLACK) {
				w = x->get_brother();
				if (w->get_color() == RED) {
					w->set_color(BLACK);
					x->get_parent()->set_color(RED);
					_rotate(x->get_parent(), x->get_side());
				} else if (w->get_value() && w->get_child(x->get_side())->get_color() == BLACK && w->get_child(w->get_side())->get_color() == BLACK) {
					w->set_color(RED);
					x = x->get_parent();
				} else {
					if (w->get_value() && w->get_child(w->get_side())->get_color() == BLACK) {
						w->get_child(x->get_side())->set_color(BLACK);
						w->set_color(RED);
						_rotate(w, w->get_side());
						w = x->get_brother();
					}
					w->set_color(x->get_parent()->get_color());
					x->get_parent()->set_color(BLACK);
					if (w->get_value())
						w->get_child(w->get_side())->set_color(BLACK);
					_rotate(x->get_parent(), x->get_side());
					x = _root;
				}
				w = x->get_brother();
			}
			x->set_color(BLACK);
		}
		void	_transplant(nodePtr del_ptr, nodePtr rep_ptr) {
			if (!del_ptr->get_parent())
				_root = rep_ptr;
			else
				del_ptr->get_parent()->set_child(rep_ptr, del_ptr->get_side());
			rep_ptr->set_parent(del_ptr->get_parent());
		}
		void	_delete(iterator del_it, nodePtr del_node)
		{
			nodePtr					x;
			bool					dir;
			bool					y_original_color = del_node->get_color();

			if (!del_node->get_child(RIGHT)->get_value() || !del_node->get_child(LEFT)->get_value()) {
				if (!del_node->get_child(RIGHT)->get_value())
					dir = LEFT;
				else
					dir = RIGHT;
				x = del_node->get_child(dir);
				_transplant(del_node, x);
				del_node->set_child(0, dir);
			} else {
				del_it++;
				nodePtr	repl_node = _find(del_it->first);
				y_original_color = repl_node->get_color();
				x = repl_node->get_child(RIGHT);
				if (repl_node->get_parent() == del_node)
					x->set_parent(repl_node);
				else {
					_transplant(repl_node, x);
					repl_node->set_child(0, RIGHT);
					repl_node->set_child(del_node->get_child(RIGHT), RIGHT);
					repl_node->get_child(RIGHT)->set_parent(repl_node);
					del_node->set_child(0, RIGHT);
				}
				_transplant(del_node, repl_node);
				if (repl_node->get_child(LEFT) && !repl_node->get_child(LEFT)->get_value())
					delete repl_node->get_child(LEFT);
				repl_node->set_child(del_node->get_child(LEFT), LEFT);
				repl_node->get_child(LEFT)->set_parent(repl_node);
				del_node->set_child(0, LEFT);
				repl_node->set_color(del_node->get_color());
			}
			_alloc.destroy(del_node->get_value());
			_alloc.deallocate(del_node->get_value(), 1);
			delete del_node;
			if (y_original_color == BLACK)
				_correct(x);
		}
		void printBT(const nodePtr n) {
			std::cout << "\e[34m" << "size: " << _size << " | val_root: " << *_root << "\e[0m" << std::endl;
		    printBT("", n, false);
		}
		void    printBT(const std::string& prefix, const nodePtr n, bool isLeft) {
		    if (n && n->get_value()) {
		        std::cout << prefix << (isLeft ? "├──" : "└──" );
		        if (n->get_color())
		            std::cout << "\e[31m";
				if (n)
		        	std::cout << *n << "\e[0m" << std::endl;

		        printBT( prefix + (isLeft ? "│   " : "    "), n->get_child(LEFT), true);
		        printBT( prefix + (isLeft ? "│   " : "    "), n->get_child(RIGHT), false);
		    }
		}
	};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return !(lhs == rhs); }

	template<class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template<class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return (!(lhs > rhs)); }

	template<class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return (!(lhs == rhs || lhs < rhs)); }

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) { return (!(lhs < rhs)); }

	template<class Key, class T, class Compare, class Alloc>
	void swap(map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs) { lhs.swap(rhs); }
}