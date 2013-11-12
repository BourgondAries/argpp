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


#ifndef ARGUMENT_HPP_INCLUDED
#define ARGUMENT_HPP_INCLUDED

// Headers
#include <string>
#include <unordered_map>
#include <vector>


class Argument
{
public:

    Argument();
    Argument(const int argc, char **argv);
    Argument(const std::string &argument);
    ~Argument();

    void pass(const int argc, char **argv);
    void pass(const std::string &argument);

    bool isPassed(const std::string &flag) const;
    bool isPassed(const char flag) const;

    const std::string &getArgument(const std::string &flag) const;
    const std::string &getArgument(const char flag) const;

    const std::string &getPath() const;

private:

    std::string m_path;
    std::unordered_map<std::string, std::string> m_flags_and_parameters;
    std::vector<std::string> m_unflagged_parameters;

};

#endif // ARGUMENT_HPP_INCLUDED
