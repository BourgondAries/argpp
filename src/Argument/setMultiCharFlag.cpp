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
#include "Argument.hpp"


////////////////////////////////////////////////////////////
void Argument::setMultiCharFlag
(
    const std::string &argument,
    TheUnset &unset_flags
)
{
    std::string tmp("--");
    for (std::size_t x = 2u; x < argument.size(); ++x)
    {
        if (argument[x] == '=')
        {
            {
                InsertReturn it = m_flags_and_parameters.insert
                (
                    std::make_pair
                    (
                        tmp, ""
                    )
                );
                if (!isInert(tmp))
                {
                    unset_flags.push
                    (
                        it
                    );
                }
            }
            setArgumentOfUnsetUninertFlag
            (
                parseEqualArgument(argument, x),
                unset_flags
            );
            return;
        }
        tmp.push_back(argument[x]);
    }
    {
        InsertReturn it = m_flags_and_parameters.insert
        (
            std::make_pair
            (
                tmp, ""
            )
        );
        if (!isInert(tmp))
        {
            unset_flags.push
            (
                it
            );
        }
    }
}
