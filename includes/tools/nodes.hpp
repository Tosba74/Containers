/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:47:11 by bmangin           #+#    #+#             */
/*   Updated: 2022/10/05 22:41:42 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tools/pair.hpp"

# define LEFT 0
# define RIGHT 1
# define BLACK 0
# define RED 1

namespace ft {

	template<class T>
	class	node {
		public :
			typedef T			value_type;
			typedef value_type*	pointer;
			
		private :
			pointer				_value;
			node*				_child[2];
			node*				_parent;
			bool				_color;
		
		//CONSTRUCTEUR
		public :
			node() : _value(0), _parent(0), _color(BLACK) {
				_child[LEFT] = 0;
				_child[RIGHT] = 0;
			}
			node(pointer value) : _value(value), _parent(0), _color(RED) {
				_child[LEFT] = new node();
				_child[RIGHT] = new node();
				_child[LEFT]->set_parent(this);
				_child[RIGHT]->set_parent(this);
			}
			node(const node & rhs) {
				*this = rhs;
			}

		//DESTRUCTEUR
			virtual ~node() {
				if (_child[LEFT] && !_child[LEFT]->get_value())
					delete _child[LEFT];
				if (_child[RIGHT] && !_child[RIGHT]->get_value())
					delete _child[RIGHT];
			}

		//OPERATOR
			node& operator=(const node & rhs) {
					_value = rhs._value;
					_child[LEFT] = rhs._child[LEFT];
					_child[RIGHT] = rhs._child[RIGHT];
					_parent = rhs._parent;
					_color = rhs._color;
					return *this;
			}
			
		//GETTEUR
			pointer	get_value() const { return _value; }
			bool	get_color() const { return _color; }
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
			bool	get_side() const {
				if (!_parent)
					return (0);
				if (_parent->get_child(RIGHT) == this)
					return(RIGHT);
				return (LEFT);
			}
			
		//SETTEUR
			void	set_child(node *rhs, bool dir) { _child[dir] = rhs; }
			void	set_brother(node *rhs) { get_brother() = rhs; }
			void	set_parent(node *rhs) { _parent = rhs; }
			void	set_grand_parent(node *rhs) { get_grand_parent() = rhs; }
			void	set_uncle(node *rhs) { get_uncle() = rhs; }
			void	set_color(bool rhs) { _color = rhs; }
	
	};
	
	template<class T>
	std::ostream& operator<<(std::ostream& o, const node<T> &n) {
  		if (n.get_color())
       		o << "\e[34m";
		if (n.get_value()->first)
    		o << n.get_value()->first << "\e[0m";
		else
			o << "\e[31m" << "X";
    	return o;
	}

	
}