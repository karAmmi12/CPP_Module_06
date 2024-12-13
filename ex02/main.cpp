/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:12:17 by kammi             #+#    #+#             */
/*   Updated: 2024/12/13 13:02:36 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base *generate(void)
{
	// srand(static_cast<unsigned int>(time(NULL)));
	int random = rand() % 3;

	switch (random)
	{
	case 0:
		std::cout << "A generated" << std::endl;
		return new A();
	case 1:
		std::cout << "B generated" << std::endl;
		return new B();
	case 2:
		std::cout << "C generated" << std::endl;
		return new C();
	default:
		return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "this pointer is an A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "this pointer is a B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "this pointer is a C" << std::endl;
	else if (p == NULL)
		std::cout << "this pointer is NULL" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "this reference is an A" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "this reference is a B" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';

	}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "this reference is a C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


}


int main()
{
	srand(static_cast<unsigned int>(time(0)));

	// Générer un objet de type A, B ou C de manière aléatoire
	Base* base = generate();
	Base* base2 = generate();
	Base* base3 = generate();

	// Identifier le type de l'objet pointé par base
	std::cout << "Identifying type using pointer:" << std::endl;
	identify(base);	// srand(static_cast<unsigned int>(time(NULL)));

	identify(base2);
	identify(base3);

	// Identifier le type de l'objet référencé par base
	std::cout << "Identifying type using reference:" << std::endl;
	identify(*base);
	identify(*base2);
	identify(*base3);

	// Libérer la mémoire allouée
	delete base;
	delete base2;
	delete base3;

	return 0;
}
