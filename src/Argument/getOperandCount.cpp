/*
Copyright 2013 Kevin Robert Stravers

This file is part of Arg++.

Arg++ is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Arg++ is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Arg++.  If not, see <http://www.gnu.org/licenses/>.
*/


// Headers
#include "Argument.hpp"
#include <cstring>
#include <stack>
#include <iostream>
#include <sstream>


////////////////////////////////////////////////////////////
int Argument::getOperandCount() const
{
    return m_operands.size();
}
