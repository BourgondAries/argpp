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
#include <cstring>


////////////////////////////////////////////////////////////
void Argument::pass(const int argc, char *argv[])
{
    m_path = argv[0];

    std::pair<decltype(m_flags_and_parameters)::iterator, bool> last_flag;

    int i = 1;

    for (; i < argc; ++i)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == '-')
            {
                if (argv[i][2] == '\0') // An end of flags flag
                {
                    break;
                }
                else // A multi-char flag
                {
                    {last_flag = m_flags_and_parameters.insert(std::make_pair(argv[i], ""));}
                }
            }
            else // A single-char flag
            {
                for (int x = 1, y = std::strlen(argv[i]); x < y; ++x) {last_flag = m_flags_and_parameters.insert(std::make_pair(std::string("-") + argv[i][x], ""));}
            }
        }
        else // A normal argument
        {
            if (last_flag.first->second == "") {last_flag.first->second = argv[i];}
        }
    } // Loop that counts flags

    for (; i < argc; ++i)
    {
        m_unflagged_parameters.emplace_back(argv[i]);
    } // Loop that accumulates all other arguments
}

////////////////////////////////////////////////////////////
void Argument::pass(const std::string &argument)
{

}
