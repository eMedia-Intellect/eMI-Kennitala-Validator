/*
Copyright © 2019 eMedia Intellect.

This file is part of eMI Kennitala Validator.

eMI Kennitala Validator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

eMI Kennitala Validator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with eMI Kennitala Validator. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <string>
#include "KennitalaValidator/Kennitala.hpp"

int main(int argc, char **argv)
{
	if (argc < 0)
	{
		std::cerr << "The number of arguments passed to the program was a negative number." << std::endl;

		return EXIT_FAILURE;
	}
	else if (argc == 0)
	{
		std::cerr << "No argument was passed to the program, not even its name." << std::endl;

		return EXIT_FAILURE;
	}
	else if (argc == 1)
	{
		std::cerr << "No argument was passed to the program." << std::endl;

		return EXIT_FAILURE;
	}
	else
	{
		switch (KennitalaValidator::Kennitala::Validate(*(argv + 1)))
		{
			case KennitalaValidator::Kennitala::Type::Invalid:
				std::cout << "Invalid" << std::endl;

				break;
			case KennitalaValidator::Kennitala::Type::Individual:
				std::cout << "Individual" << std::endl;

				break;
			case KennitalaValidator::Kennitala::Type::Organisation:
				std::cout << "Organisation" << std::endl;

				break;
		}

		return EXIT_SUCCESS;
	}
}