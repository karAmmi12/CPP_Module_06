/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:01:56 by kammi             #+#    #+#             */
/*   Updated: 2024/12/11 13:18:55 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
	(void)src;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data* ptr;

	ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}

