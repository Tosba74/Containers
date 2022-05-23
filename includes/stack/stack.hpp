/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:20:16 by bmangin           #+#    #+#             */
/*   Updated: 2022/05/23 16:57:42 by bmangin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include "vector/vector.hpp"


namespace ft {
	// template <class T, class Container = ft::vector<T> >
	template < class T, class Container = std::vector< T > >
	class stack {

		protected:
			Container			c;
		
		public:

/* -----------------------------   TYPEDEF   ------------------------------- */

			typedef typename Container::value_type			value_type;
			typedef typename Container::size_type			size_type;
			typedef typename Container::const_reference	const_reference;
			typedef typename Container::reference			reference;

/* --------------------------   CONSTRUCTEUR   ---------------------------- */

			explicit stack (const Container& ctnr = Container()) : Container(ctnr) {};

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

			friend bool operator==(const stack<T, Container> & lhs, const stack<T, Container> & rhs)
			{
				return (lhs.c == rhs.c);
			}
			friend bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{
				return (lhs.c != rhs.c);
			}
			friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{
				return (lhs.c < rhs.c);
			}

			friend bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{
				return (lhs.c <= rhs.c);
			}

			friend bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
			{
				return (lhs.c > rhs.c);
			}

			friend bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)	
			{
				return (lhs.c >= rhs.c);
			}
	};
}