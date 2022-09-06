/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:47:11 by bmangin           #+#    #+#             */
/*   Updated: 2022/09/01 14:00:56 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/pair.hpp"

// #define RED "\e[31m"
// #define BLACK "\e[30m"
// #define DEFAULT "\e[39m"

enum e_color {
	black,
	red
};

# define LEFT 0
# define RIGHT 1
# define BLACK 0
# define RED 1

namespace ft {

/*
	template <typename K, typename V>
	class node {
		public:
			ft::pair<const K, V>	pair;
			e_color					color;
			node*					parent;
			node*					child[2];
		
		//CONSTRUCTEUR
			node(ft::pair<const K, V>& n_pair) : pair(n_pair), color(black),
				parent(NULL), child(NULL) {}

		//DESTRUCTEUR
			~node(){}
		
		//GETTER
			node*	get_child(bool dir) const { return child[dir]; }
			node*	get_parent() const { return parent; }
			
		//OPERATEUR
			node*	operator=(node const& cpy){
				pair = cpy.pair;
				color = cpy.color;
				parent = cpy.parent;
				child[0] = cpy.child[0];
				child[1] = cpy.child[1];
				return *this;
			}
		
			bool	operator==(node const& rhs) {
				return (pair == rhs.pair);
			}
			bool	operator!=(node const& rhs) {
				return (pair != rhs.pair);
			}
			bool	operator>=(const node& other) const {
				return (pair >= other.pair);
			}
			bool	operator<=(const node& other) const {
				return (pair <= other.pair);
			}
			bool	operator>(const node& other) const {
				return (pair > other.pair);
			}
			bool	operator<(const node& other) const {
				return (pair < other.pair);
			}
	};
*/
	template<class T>
	class	node {
		public :
			typedef T		value_type;
			typedef T*		pointer;
			
		private:
			pointer		_value;
			node*		_child[2];
			node*		_parent;
			bool		_color;
		
		public :
			node() : _value(0), _parent(0), _color(BLACK) {
				_child[LEFT] = 0;
				_child[RIGHT] = 0;
			}
			node(pointer value) : _value(value), _parent(0), _color(RED) {
				_child[LEFT] = new node();
				_child[LEFT]->set_parent(this);
				_child[RIGHT] = new node();
				_child[RIGHT]->set_parent(this);
			}
			node(const node &	rhs) {
				*this = rhs;
			}
			virtual ~node() {
				if (_child[LEFT] && !_child[LEFT]->get_value())
					delete _child[LEFT];
				if (_child[RIGHT] && !_child[RIGHT]->get_value())
					delete _child[RIGHT];
			}
			node & operator=(const node & rhs) {
					_value = rhs._value;
					_child[LEFT] = rhs._child[LEFT];
					_child[RIGHT] = rhs._child[RIGHT];
					_parent = rhs._parent;
					_color = rhs._color;
					return *this;
			}
			node	*get_child(bool dir) const { return _child[dir]; }
			node	*get_parent() const { return _parent; }
			node	*get_grand_parent() const {
				if (_parent)
					return (_parent->get_parent());
				return (0);
			}
			node	*get_brother() const {
				if (!_parent)
					return (0);
				return (_parent->get_child(!get_side()));
			}
			node	*get_uncle() const {
				node * tmp = get_parent();
				if (!tmp)
					return (0);
				return (tmp->get_brother());
			}
			pointer	get_value() const { return _value; }
			bool	get_color() const { return _color; }
			bool	get_side() const {
				if (!_parent)
					return (0);
				if (_parent->get_child(RIGHT) == this)
					return(RIGHT);
				return (LEFT);
			}
			void	set_child(node *rhs, bool dir) { _child[dir] = rhs; }
			void	set_brother(node *rhs) { get_brother() = rhs; }
			void	set_parent(node *rhs) { _parent = rhs; }
			void	set_grand_parent(node *rhs) { get_grand_parent() = rhs; }
			void	set_uncle(node *rhs) { get_uncle() = rhs; }
			void	set_color(bool rhs) { _color = rhs; }
	
	};
	
}