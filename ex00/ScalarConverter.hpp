/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:59:54 by kammi             #+#    #+#             */
/*   Updated: 2024/12/17 16:37:52 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <cfloat>

# include "ConvertLib.hpp"

enum TypeInput
{
	FLOAT,
	INTEGER,
	DOUBLE,
	CHARACTER,
	SPECIAL,
	WRONG
};

class ScalarConverter
{
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();

		ScalarConverter &operator=(const ScalarConverter &src);

	public:
		static void	convert(const std::string &input);


};
#endif

