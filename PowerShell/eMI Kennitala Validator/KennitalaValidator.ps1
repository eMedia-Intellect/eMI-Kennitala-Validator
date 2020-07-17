<#
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
along with eMI Kennitala Validator. If not, see http://www.gnu.org/licenses/.
#>

enum KennitalaType
{
	Invalid = 0
	Individual = 1
	Organisation = 2
}

class Kennitala
{
	[KennitalaType]static Validate($kennitala)
	{
		# The national identification number is 10 digits long.
		if ($kennitala.Length -eq 10)
		{
			[int]$digit1 = [int]$kennitala.Substring(0, 1) # Birth/Founding day
			[int]$digit2 = [int]$kennitala.Substring(1, 1) # Birth/Founding day
			[int]$digit3 = [int]$kennitala.Substring(2, 1) # Birth/Founding month
			[int]$digit4 = [int]$kennitala.Substring(3, 1) # Birth/Founding month
			[int]$digit5 = [int]$kennitala.Substring(4, 1) # Birth/Founding year
			[int]$digit6 = [int]$kennitala.Substring(5, 1) # Birth/Founding year
			[int]$digit7 = [int]$kennitala.Substring(6, 1) # Random digit
			[int]$digit8 = [int]$kennitala.Substring(7, 1) # Random digit
			[int]$digit9 = [int]$kennitala.Substring(8, 1) # Check digit
			[int]$digit10 = [int]$kennitala.Substring(9, 1) # Century: 8 (1800–1899), 9 (1900–1999), 0 (2000–2099)

			# All digits must be within their respective ranges.
			if (($digit1 -ge 0 -AND $digit1 -le 7) -and ($digit2 -ge 0 -and $digit2 -le 9) -and ($digit3 -eq 0 -OR $digit3 -eq 1) -and ($digit4 -ge 0 -and $digit4 -le 9) -and ($digit5 -ge 0 -and $digit5 -le 9) -and ($digit6 -ge 0 -and $digit6 -le 9) -and ($digit7 -ge 0 -and $digit7 -le 9) -and ($digit8 -ge 0 -and $digit8 -le 9) -and ($digit9 -ge 0 -and $digit9 -le 9) -and ($digit10 -eq 0 -or $digit10 -eq 8 -or $digit10 -eq 9))
			{
				# A date string is constructed from the national identification number for validation.
				[int]$temporaryDigit1 = $digit1;

				if ($digit1 -gt 3)
				{
					$temporaryDigit1 = $temporaryDigit1 - 4;
				}

				[string]$date = [string]$digit5 + [string]$digit6 + "-" + [string]$digit3 + [string]$digit4 + "-" + [string]$temporaryDigit1 + [string]$digit2

				switch ($digit10)
				{
					8
					{
						$date = "18" + $date
					}

					9
					{
						$date = "19" + $date
					}

					0
					{
						$date = "20" + $date
					}
				}

				[DateTime]$dateTime = New-Object DateTime

				# The date of birth/founding should be valid.
				if (-not [DateTime]::TryParse($date, [ref][DateTime]$dateTime))
				{
					return [KennitalaType]::Invalid
				}

				[int]$checkDigit = (($digit1 * 3) + ($digit2 * 2) + ($digit3 * 7) + ($digit4 * 6) + ($digit5 * 5) + ($digit6 * 4) + ($digit7 * 3) + ($digit8 * 2)) % 11

				# The check digit may be 0. Otherwise it is subtracted from 11.
				if ($checkDigit -gt 0)
				{
					$checkDigit = 11 - $checkDigit
				}

				# The check digit must equal digit 9.
				if ($checkDigit -eq $digit9)
				{
					# Digit 1 of organisations is between 4 and 7.
					if ($digit1 -eq 4 -or $digit1 -eq 5 -or $digit1 -eq 6 -or $digit1 -eq 7)
					{
						return [KennitalaType]::Organisation
					}

					return [KennitalaType]::Individual
				}
			}
		}

		return [KennitalaType]::Invalid
	}
}