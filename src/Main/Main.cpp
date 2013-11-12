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


#include "Main.hpp"
#include <thread>
#include <cstring>


Main::Main(int argc, char **argv)
:
    argument_count(argc),
    argument_array(argv),
    sleep_time(0)
{
    setSettings();
}


Main::~Main()
{

}


void Main::setSettings()
{
    for (int i = 1; i < argument_count; ++i)
    {
        if (argument_array[i][0] == '-' && args_to_process == 0)
        {
            this->setActiveParameter(i);
        }
        else if (args_to_process > 0)
        {
            args_to_process--;
            std::cout << "Processing parameter...\n";
            this->setParameter(i);
        }
    }
}

void Main::setActiveParameter(const int i)
{
    if (argument_array[i][1] == '-')
    {
        std::cout << "Long arg --\n";
        args_to_process = 1;
    }
    else // We have short arguments
    {
        args_to_process = std::strlen(argument_array[i]) - 1;
        if (args_to_process > 1)
        {
            std::cout << "Multi-arg -\n";
            // Here we would put stuff like -sm
            // The argument would be:
            // schdl -sm 30 1
            // Which means sleep 1 min and 30 sec, or schdl -ms 1 30
        }
        else
        {
            std::cout << "Single arg -\n";
            if (argument_array[i] == "-s")
            {
                activeparam = Parameter::seconds;
            }
            else if (argument_array[i] == "-m")
            {
                activeparam = Parameter::minutes;
            }
            else if (argument_array[i] == "-h")
            {
                activeparam = Parameter::hours;
            }
            else if (argument_array[i] == "-d")
            {
                activeparam = Parameter::days;
            }
            else if (argument_array[i] == "-w")
            {
                activeparam = Parameter::weeks;
            }
            else if (argument_array[i] == "-n")
            {
                activeparam = Parameter::months;
            }
            else if (argument_array[i] == "-y")
            {
                activeparam = Parameter::years;
            }
        }
    }
}

void Main::setParameter(const int i)
{

}
