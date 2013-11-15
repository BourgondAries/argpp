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
along with schdl.  If not, see <http://www.gnu.org/licenses/>.
*/


// Headers
#include <ostream>
#include <iomanip>
#include "Argument.hpp"


std::ostream &operator<<(std::ostream &out, const Argument &argument)
{
    // Find the longest flag:
    std::size_t longest_flag = 0;
    std::size_t longest_argument = 0;
    for (auto &x : argument.m_flags_and_parameters)
    {
        if (longest_flag < x.first.size())
        {
            longest_flag = x.first.size();
        }
        if (longest_argument < x.second.size())
        {
            longest_argument = x.second.size();
        }
    }

    out << "Path: " << argument.m_path << "\n";
    out
        << std::setw(longest_flag)
        << "Flag"
        << std::setw(8)
        << "Inertia"
        << " "
        << "Argument\n";
    for (auto &x : argument.m_flags_and_parameters)
    {
        out
            << std::setw(longest_flag) << x.first
            << std::setw(3) << (argument.isInert(x.first) ? 'X' : ' ' )
            << "      " << x.second
            << "\n";
    }
    return out;
}
