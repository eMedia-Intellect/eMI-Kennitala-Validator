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

#include <stdio.h>
#include "emi_kennitala_validator/KennitalaType.h"
#include "emi_kennitala_validator/validate.h"

int main(int argc, char **argv)
{
	if (argc < 0)
	{
		puts("The number of arguments passed to the program was a negative number.");

		return 0;
	}
	else if (argc == 0)
	{
		puts("No argument was passed to the program, not even its name.");

		return 0;
	}
	else if (argc == 1)
	{
		puts("No argument was passed to the program.");

		return 0;
	}
	else
	{
		switch (validate(*(argv + 1)))
		{
			case INVALID:
				puts("Invalid");

				break;
			case INDIVIDUAL:
				puts("Individual");

				break;
			case ORGANISATION:
				puts("Organisation");

				break;
		}

		return 1;
	}
}