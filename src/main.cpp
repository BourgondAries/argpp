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
#include <iostream>
#include "Argument.hpp"


int main(int argc, char *argv[])
{
    Argument arg(argc, argv);
    if (arg.isPassed("--version"))
    {
        std::cout << "schdl version 0.1 Copyright 2013 Kevin Robert Stravers";
        return 0;
    }
    if (arg.isPassed("--help"))
    {
        std::cout
            << "schdl [options] [argument]";
    }
    std::cout << arg.getPath() << std::endl;
    std::cout << std::boolalpha << arg.isPassed("-f") << std::endl;
    std::cout << std::boolalpha << arg.isPassed("-a") << std::endl;
    std::cout << std::boolalpha << arg.isPassed("-o") << std::endl;
    std::cout << std::boolalpha << arg.isPassed("--que") << std::endl;
    std::cout << std::boolalpha << arg.isPassed("-d") << std::endl;
    std::cout << arg.getArgument("-f") << std::endl;
    std::cout << arg.getArgument("-a") << std::endl;
    std::cout << arg.getArgument("-o") << std::endl;
    std::cout << arg.getArgument("--que") << std::endl;
    std::cout << arg.getArgument("-d") << std::endl;
}











