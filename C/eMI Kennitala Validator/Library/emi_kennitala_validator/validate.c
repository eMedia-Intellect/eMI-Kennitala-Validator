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

#include <string.h>
#include "KennitalaType.h"
#include "validate.h"

enum KennitalaType validate(char *kennitala)
{
	if (kennitala)
	{
		// The national identification number is 10 digits long.
		if (strlen(kennitala) == 10)
		{
			if (strcmp(kennitala, "0000000000") == 0)
			{
				return INVALID;
			}

			int digit1 = kennitala[0] - '0'; // Birth/Founding day
			int digit2 = kennitala[1] - '0'; // Birth/Founding day
			int digit3 = kennitala[2] - '0'; // Birth/Founding month
			int digit4 = kennitala[3] - '0'; // Birth/Founding month
			int digit5 = kennitala[4] - '0'; // Birth/Founding year
			int digit6 = kennitala[5] - '0'; // Birth/Founding year
			int digit7 = kennitala[6] - '0'; // Random digit
			int digit8 = kennitala[7] - '0'; // Random digit
			int digit9 = kennitala[8] - '0'; // Check digit
			int digit10 = kennitala[9] - '0'; // Century: 8 (1800–1899), 9 (1900–1999), 0 (2000–2099)

			// All digits must be within their respective ranges.
			if ((digit1 >= 0 && digit1 <= 7) && (digit2 >= 0 && digit2 <= 9) && (digit3 == 0 || digit3 == 1) && (digit4 >= 0 && digit4 <= 9) && (digit5 >= 0 && digit5 <= 9) && (digit6 >= 0 && digit6 <= 9) && (digit7 >= 0 && digit7 <= 9) && (digit8 >= 0 && digit8 <= 9) && (digit9 >= 0 && digit9 <= 9) && (digit10 == 0 || digit10 == 8 || digit10 == 9))
			{
				int checkDigit = ((digit1 * 3) + (digit2 * 2) + (digit3 * 7) + (digit4 * 6) + (digit5 * 5) + (digit6 * 4) + (digit7 * 3) + (digit8 * 2)) % 11;

				// The check digit may be 0. Otherwise it is subtracted from 11.
				if (checkDigit > 0)
				{
					checkDigit = 11 - checkDigit;
				}

				// The check digit must equal digit 9.
				if (checkDigit == digit9)
				{
					// Digit 1 of organisations is between 4 and 7.
					if (digit1 == 4 || digit1 == 5 || digit1 == 6 || digit1 == 7)
					{
						return ORGANISATION;
					}

					return INDIVIDUAL;
				}
			}
		}
	}

	return INVALID;
}