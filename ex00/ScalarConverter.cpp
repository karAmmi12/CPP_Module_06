/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:59:50 by kammi             #+#    #+#             */
/*   Updated: 2024/12/11 12:55:25 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}


// checker functions

static bool	isLitteral(const std::string &input)
{
	if (!input.compare("nan") || !input.compare("nanf") || !input.compare("inf") || !input.compare("inff") || !input.compare("+inf") || !input.compare("+inff") || !input.compare("-inf") || !input.compare("-inff"))
		return true;
	return false;
}

static bool	isChar(const std::string &input)
{
	if (input.length() == 1 && !std::isdigit(input.at(0)))
		return true;
	return false;
}

static bool	isInt(const std::string &input)
{
	int i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;
	for (size_t j = i; j < input.length(); j++)
	{
		if (!std::isdigit(input[j]))
			return false;
	}
	return true;
}

static bool	isFloat(const std::string &input)
{
	int i = 0;
	int dot = 0;

	if (!input.compare("nanf") || !input.compare("inff") || !input.compare("+inff") || !input.compare("-inff"))
		return true;

	if (input.at(input.length() - 1) != 'f')
		return false;

	if (input[i] == '+' || input[i] == '-')
		i++;
	for (size_t j = i; j < input.length(); j++)
	{
		if (input[j] == '.')
			dot++;
		else if (!std::isdigit(input[j]) && j != input.size() - 1)
			return false;
	}
	if (dot == 1)
		return true;
	return false;
}

static bool	isDouble(const std::string &input)
{
	int i = 0;
	int dot = 0;

	if (!input.compare("nan") || !input.compare("inf") || !input.compare("+inf") || !input.compare("-inf"))
		return true;

	if (input[i] == '+' || input[i] == '-')
		i++;
	for (size_t j = i; j < input.length(); j++)
	{
		if (input[j] == '.')
			dot++;
		else if (!std::isdigit(input[j]))
			return false;
	}
	if (dot == 1)
		return true;
	return false;
}

// conversion functions

static char	convertChar(const std::string &input)
{
	return static_cast<char>(ConvertLib::ft_stoi(input));
}
static int	convertInt(const std::string &input)
{
	return static_cast<int>(ConvertLib::ft_stoi(input));
}

static float	convertFloat(const std::string &input)
{
	return static_cast<float>(ConvertLib::ft_stof(input));
}

static double	convertDouble(const std::string &input)
{
	return static_cast<double>(ConvertLib::ft_stod(input));
}
// print functions

static void	printChar(std::string input)
{
	char c;
	double d;

	try
	{
		if (isLitteral(input))
		{
			throw std::exception();
		}


		c = convertChar(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
		d = convertDouble(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
	}
	catch(std::exception& e)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

}

static void	printInt(std::string input)
{
	int i;
	double d;

	try
	{
		if (isLitteral(input))
			throw std::exception();
		i = convertInt(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
		d = convertDouble(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
	}
	catch(std::exception& e)
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;

	else
	std::cout << "int: " << i << std::endl;
}

static void	printFloat(std::string input)
{
	float f;
	double d;

	if (isLitteral(input))
	{
		if (!input.compare("+inf") || !input.compare("-inf"))
			std::cout << "float: " << input << "f" << std::endl;
		else if (input[input.size() - 1] == 'f')
			std::cout << "float: " << input << std::endl;
		else
			std::cout << "float: " << input << "f" << std::endl;
		return;

	}
	// if (isFloat(input))
	// {
	// 	std::cout << "float: " << input << std::endl;
	// 	return;
	// }


	try
	{
		f = convertFloat(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
		d = convertDouble(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));

	}
	catch(std::exception& e)
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
	{
		std::cout << "float: impossible" << std::endl;
		return;
	}
	if (f - static_cast<int>(f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

static void	printDouble(std::string input)
{
	double d;

	if (isLitteral(input))
	{
		if (!input.compare("+inf") || !input.compare("-inf"))
			std::cout << "double: " << input << std::endl;
		else if (input.substr(input.size() - 1).compare("f"))
			std::cout << "double: " << input << std::endl;
		else
			std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
		return;
	}
	// if (isDouble(input))
	// {
	// 	std::cout << "double: " << input << std::endl;
	// 	return;
	// }


	try
	{
		d = convertDouble(input.at(input.size() - 1) != 'f' ? input : input.substr(0, input.size() - 1));
	}
	catch(std::exception& e)
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (d < -std::numeric_limits<double>::max() || d > std::numeric_limits<double>::max())
	{
		std::cout << "double: impossible" << std::endl;
		return;
	}
	if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}


void	ScalarConverter::convert(const std::string &input)
{
	std::string inputType;

	if (input.size() == 0)
	{
		std::cout << "Error: empty input" << std::endl;
		return;
	}

	if (isChar(input))
		inputType = "char";
	else if (isInt(input))
		inputType = "int";
	else if (isFloat(input))
		inputType = "float";
	else if (isDouble(input))
		inputType = "double";
	else
	{
		std::cout << "Error: invalid input" << std::endl;
		return;
	}

	if (inputType == "char")
	{
		if (!std::isprint(static_cast<int>(input.at(0))))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << input.at(0) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(input.at(0)) << std::endl;
		std::cout << "float: " << static_cast<float>(input.at(0)) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input.at(0)) << ".0" << std::endl;
		return;
	}
	printChar(input);
	printInt(input);
	printFloat(input);
	printDouble(input);
}






