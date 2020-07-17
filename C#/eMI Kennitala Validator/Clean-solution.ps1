# Copyright © 2019 eMedia Intellect.

# This file is part of eMI Kennitala Validator.

# eMI Kennitala Validator is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# eMI Kennitala Validator is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with eMI Kennitala Validator. If not, see http://www.gnu.org/licenses/.

#################################################
# Solution cleaning for eMI Kennitala Validator #
#################################################

Write-Host '┌───────────────────────────────────────────────┐'
Write-Host '│ Solution cleaning for eMI Kennitala Validator │'
Write-Host '└───────────────────────────────────────────────┘'
Write-Host

Write-Host 'Removing the Visual Studio solution user options directory.'
Write-Host

Remove-Item -ErrorAction 'Ignore' -Force -Path '.\.vs' -Recurse

Write-Host 'Removing the builds.'
Write-Host

Remove-Item -ErrorAction 'Ignore' -Force -Path '.\KennitalaValidator\Build' -Recurse
Remove-Item -ErrorAction 'Ignore' -Force -Path '.\KennitalaValidatorWindowsApplicationTesting\Build' -Recurse