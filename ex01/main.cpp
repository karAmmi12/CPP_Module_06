/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:19:06 by kammi             #+#    #+#             */
/*   Updated: 2024/12/11 13:32:55 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	// Création d'un objet Data
	Data originalData;
	originalData.content = "Ceci est un test";

	// Affichage de l'adresse de l'objet original
	std::cout << "Adresse de l'objet original: " << &originalData << std::endl;

	// Sérialisation de l'objet Data
	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Valeur sérialisée (uintptr_t): " << raw << std::endl;

	// Désérialisation de la valeur sérialisée
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Adresse de l'objet désérialisé: " << deserializedData << std::endl;

	// Vérification que l'adresse de l'objet désérialisé est la même que celle de l'objet original
	if (deserializedData == &originalData)
	{
		std::cout << "Succès: L'adresse de l'objet désérialisé est identique à celle de l'objet original." << std::endl;
		std::cout << "Contenu de l'objet désérialisé: " << deserializedData->content << std::endl;
	}
	else
	{
		std::cout << "Erreur: L'adresse de l'objet désérialisé est différente de celle de l'objet original." << std::endl;
	}

	return 0;
}
