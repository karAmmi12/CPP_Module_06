/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:59:54 by kammi             #+#    #+#             */
/*   Updated: 2024/12/11 10:51:33 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <cfloat>
# include <cmath>

# include "ConvertLib.hpp"

# define CHAR_MIN_STR "-128"
# define CHAR_MAX_STR "127"
# define INT_MIN_STR "-2147483648"
# define INT_MAX_STR "2147483647"

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


