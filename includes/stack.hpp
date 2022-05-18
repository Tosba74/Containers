/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:20:16 by bmangin           #+#    #+#             */
/*   Updated: 2022/05/15 17:31:49 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include "vector.hpp"


namespace ft {
	// template <class T, class Container = ft::vector<T> >
	template <class T, class Container = std::vector<T>>
	class stack
	{

		protected:
			Container			c;
		
		public:

/* -----------------------------   TYPEDEF   ------------------------------- */

			typedef typename container_type::value_type			value_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::const_reference	const_reference;
			typedef typename container_type::reference			reference;


/* --------------------------   CONSTRUCTEUR   ---------------------------- */

			explicit stack (const container_type& ctnr = container_type()) : Container(ctnr) {};
			// stack(){};

/* --------------------------   DESTRUCTEUR   ----------------------------- */

			~stack(){};
			
/* ------------------------   MEMBER FUNCTIONS   -------------------------- */

			bool				empty() const {return c.empty();};
			size_type			size() const {return c.size();};
			value_type &		top() {return c.back();};
			const value_type &	top() const {return c.back();};
			void 				push(const value_type & val) {this->c.push_back(val);};
			void				pop() {this->c.pop_back();};

/* -----------------------   OPERATOR FUNCTIONS   ------------------------- */

			friend bool operator==(const stack<T, container_type> & lhs, const stack<T, container_type> & rhs)
			{
				return (lhs.c == rhs.c);
			}
			friend bool operator!=(const stack<T, container_type>& lhs, const stack<T, container_type>& rhs)
			{
				return (lhs.c != rhs.c);
			}
			friend bool operator<(const stack<T, container_type>& lhs, const stack<T, container_type>& rhs)
			{
				return (lhs.c < rhs.c);
			}

			friend bool operator<=(const stack<T, container_type>& lhs, const stack<T, container_type>& rhs)
			{
				return (lhs.c <= rhs.c);
			}

			friend bool operator>(const stack<T, container_type>& lhs, const stack<T, container_type>& rhs)
			{
				return (lhs.c > rhs.c);
			}

			friend bool operator>=(const stack<T, container_type>& lhs, const stack<T, container_type>& rhs)	
			{
				return (lhs.c >= rhs.c);
			}
	};
}
