/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:20:16 by bmangin           #+#    #+#             */
/*   Updated: 2022/03/25 22:23:18 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

namespace ft {
	class stack {
		public:
			stack();
			~stack();
			int top();
			void push(int);
			int pop();
			bool empty();
			void clear();
		private:
			int *_stack;
			int _size;
			int _top;
	};
}