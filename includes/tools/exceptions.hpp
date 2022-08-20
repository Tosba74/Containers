/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmangin <bmangin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:53:38 by bmangin           #+#    #+#             */
/*   Updated: 2022/08/17 09:54:00 by bmangin          ###   ########lyon.fr   */
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

class duplicateKey : public std::exception {
   public:
	virtual const char* what() const throw() {
		return ("Provided key is a duplicate");
	}
};

class OutOfRangeException : public std::exception {
   public:
	const char* what() const throw() {
		return "Request is out of bounds";
	}
};