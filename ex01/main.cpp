/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:19:06 by kammi             #+#    #+#             */
/*   Updated: 2024/12/26 11:26:24 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	// Création d'un objet Data
	Data originalData;
	originalData.content = "Ceci est un test";

	// Affichage de l'adresse de l'objet original
	std::cout << "Address of the original object: " << &originalData << std::endl;

	// Sérialisation de l'objet Data
	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

	// Désérialisation de la valeur sérialisée
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Address of the deserialized object: " << deserializedData << std::endl;

	// Vérification que l'adresse de l'objet désérialisé est la même que celle de l'objet original
	if (deserializedData == &originalData)
	{
		std::cout << "Success: The address of the deserialized object is the same as the original object." << std::endl;
		std::cout << "Content of the deserialized object: " << deserializedData->content << std::endl;
	}
	else
	{
		std::cout << "Error: The address of the deserialized object is different from the original object." << std::endl;
	}

	return 0;
}
