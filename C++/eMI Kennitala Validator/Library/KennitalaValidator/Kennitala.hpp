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

#ifndef KENNITALA
#define KENNITALA

#include <string>

namespace KennitalaValidator
{
	class Kennitala
	{
		public:
			enum Type
			{
				Invalid,
				Individual,
				Organisation
			};

			static Type Validate(std::string const &kennitala);

		private:
			Kennitala();
	};
}

#endif