/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:37:51 by kammi             #+#    #+#             */
/*   Updated: 2024/12/11 12:15:40 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "ConvertLib.hpp"

ConvertLib::ConvertLib()
{
}

ConvertLib::ConvertLib(const ConvertLib &src)
{
	(void)src;
}

ConvertLib::~ConvertLib()
{
}

ConvertLib &ConvertLib::operator=(const ConvertLib &src)
{
	(void)src;
	return *this;
}

int		ConvertLib::ft_stoi(const std::string &input)
{
	int		ret;

	std::istringstream iss(input);


	iss >> ret;
	if (iss.fail())
	{
		throw std::invalid_argument("stoi");
	}

	return ret;
}
float	ConvertLib::ft_stof(const std::string &input)
{
	float		ret;
	std::istringstream iss(input);

	iss >> ret;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("stof");

	return ret;
}

double	ConvertLib::ft_stod(const std::string &input)
{
	double		ret;
	std::istringstream iss(input);

	iss >> ret;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("stod");
	return ret;
}


