/*
Copyright 2013 Kevin Robert Stravers

This file is part of schdl.

schdl is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

schdl is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with schdl.  If not, see <http://www.gnu.org/licenses/>.
*/


// Headers
#include "Argument.hpp"


////////////////////////////////////////////////////////////
const std::string &Argument::getArgument(const std::string &argument) const
{
    return m_flags_and_parameters.find(argument)->second;
}

////////////////////////////////////////////////////////////
const std::string &Argument::getArgument(const char argument) const
{
    std::string tmp;
    tmp.push_back(argument);
    return this->getArgument(tmp);
}
