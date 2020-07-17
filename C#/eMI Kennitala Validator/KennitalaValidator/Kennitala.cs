// <author>Stefán Örvar Sigmundsson</author>
// <copyright company="eMedia Intellect" file="Kennitala.cs">
//    Copyright © 2019 eMedia Intellect.
// </copyright>
// <licence>
//    This file is part of eMI Kennitala Validator.
//
//    eMI Kennitala Validator is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    eMI Kennitala Validator is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with eMI Kennitala Validator. If not, see http://www.gnu.org/licenses/.
// </licence>

namespace Emi.KennitalaValidator
{
	using System;
	using System.Globalization;

	public static class Kennitala
	{
		public static KennitalaType Validate(string kennitala)
		{
			if (kennitala == null)
			{
				throw new ArgumentNullException("kennitala");
			}

			// The national identification number is 10 digits long.
			if (kennitala.Length == 10)
			{
				int digit1; // Birth/Founding day
				int digit2; // Birth/Founding day
				int digit3; // Birth/Founding month
				int digit4; // Birth/Founding month
				int digit5; // Birth/Founding year
				int digit6; // Birth/Founding year
				int digit7; // Random digit
				int digit8; // Random digit
				int digit9; // Check digit
				int digit10; // Century: 8 (1800–1899), 9 (1900–1999), 0 (2000–2099)

				// All digits must be integers.
				if (int.TryParse(kennitala[0].ToString(), out digit1) && int.TryParse(kennitala[1].ToString(), out digit2) && int.TryParse(kennitala[2].ToString(), out digit3) && int.TryParse(kennitala[3].ToString(), out digit4) && int.TryParse(kennitala[4].ToString(), out digit5) && int.TryParse(kennitala[5].ToString(), out digit6) && int.TryParse(kennitala[6].ToString(), out digit7) && int.TryParse(kennitala[7].ToString(), out digit8) && int.TryParse(kennitala[8].ToString(), out digit9) && int.TryParse(kennitala[9].ToString(), out digit10))
				{
					// All digits must be within their respective ranges.
					if ((digit1 >= 0 && digit1 <= 7) && (digit2 >= 0 && digit2 <= 9) && (digit3 == 0 || digit3 == 1) && (digit4 >= 0 && digit4 <= 9) && (digit5 >= 0 && digit5 <= 9) && (digit6 >= 0 && digit6 <= 9) && (digit7 >= 0 && digit7 <= 9) && (digit8 >= 0 && digit8 <= 9) && (digit9 >= 0 && digit9 <= 9) && (digit10 == 0 || digit10 == 8 || digit10 == 9))
					{
						// A date string is constructed from the national identification number for validation.
						int temporaryDigit1 = digit1;

						if (digit1 > 3)
						{
							temporaryDigit1 = temporaryDigit1 - 4;
						}

						string date = digit5.ToString(CultureInfo.InvariantCulture) + digit6.ToString(CultureInfo.InvariantCulture) + "-" + digit3.ToString(CultureInfo.InvariantCulture) + digit4.ToString(CultureInfo.InvariantCulture) + "-" + temporaryDigit1.ToString(CultureInfo.InvariantCulture) + digit2.ToString(CultureInfo.InvariantCulture);

						switch (digit10)
						{
							case 8:
								date = "18" + date;

								break;
							case 9:
								date = "19" + date;

								break;
							case 0:
								date = "20" + date;

								break;
						}

						DateTime dateTime;

						// The date of birth/founding should be valid.
						if (!DateTime.TryParse(date, out dateTime))
						{
							return KennitalaType.Invalid;
						}

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
								return KennitalaType.Organisation;
							}

							return KennitalaType.Individual;
						}
					}
				}
			}

			return KennitalaType.Invalid;
		}
	}
}