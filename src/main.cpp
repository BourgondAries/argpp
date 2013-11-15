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
#include <iostream>
#include "Argument.hpp"


int main(int argc, char *argv[])
{
    Argument arg;

    // Set inert values
    arg.setInert("-nvs");
    arg.setInert("--no-sound");
    arg.setInert("--verbose");
    arg.setInert("--silent");

    // Pass parameters
//    arg.pass(argc, argv);
    arg.pass("/a/location/program -so -v log.txt --method=23 -qre=alpha 2013");

    // Apply settings
    if (arg.isPassed("-o"))
    {
        std::cout << "Outputting to a file\n";
        std::cout << "We will output to: " << arg.getArgument("-o") << "\n";
    }

    if (arg.isPassed("-l"))
    {
        std::cout << "Using long notation\n";
    }

    if (arg.isPassed("--method"))
    {
        std::cout << "Method: " << arg.getArgument("--method") << "\n";
    }

    if (arg.isPassed("-s") || arg.isPassed("--silent"))
    {
        std::cout << "shhh\n";
    }

    // Dump all passed parameters
    std::cout << "\n\n";
    std::cout << arg;
}











