/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:53:38 by bmangin           #+#    #+#             */
/*   Updated: 2022/10/05 13:49:09 by bmangin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class allocFail : public std::exception {
   public:
	virtual const char* what() const throw() {
		return ("Memory allocation failed");
	}
};

class OutOfRangeException : public std::exception {
   public:
	const char* what() const throw() {
		return "Request is out of bounds";
	}
};