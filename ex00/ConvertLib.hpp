/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertLib.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:01:00 by kammi             #+#    #+#             */
/*   Updated: 2024/12/07 16:37:55 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTLIB_HPP
# define CONVERTLIB_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <iomanip>

class ConvertLib
{
	private :
		ConvertLib();
		ConvertLib(const ConvertLib &src);
		~ConvertLib();

		ConvertLib &operator=(const ConvertLib &src);

	public:
		static int		ft_stoi(const std::string &input);
		static float	ft_stof(const std::string &input);
		static double	ft_stod(const std::string &input);
};

#endif
