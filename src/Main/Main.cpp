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


void Main::run()
{
    while (true)
    {
        if (execute_immediately)
            std::system(torun.data());
        else
            execute_immediately = !execute_immediately;

            std::this_thread::sleep_for(sleep_time);
//        std::this_thread::sleep_for(std::chrono::seconds(1000));
    }
}


void Main::setSettings()
{
    for (int i = 1; i < argument_count; ++i)
    {
        std::cout << "Processing: " << argument_array[i] << std::endl;
        std::cout << "Parameter list size: " << activeparam.size() << std::endl;
        if (argument_array[i][0] == '-' && activeparam.size() == 0)
        {
            this->setActiveParameter(i);
        }
        else
        {
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
        args_to_process = 1; // Depends on the argument right?
    }
    else // We have short arguments
    {
        args_to_process = std::strlen(argument_array[i]); // Also depends on the argument
        std::cout << "Multi-arg -\n";
        for (int z = 1; z < args_to_process; ++z)
        {
            if (argument_array[i][z] == 's')
            {
                activeparam.push(Parameter::seconds);
            }
            else if (argument_array[i][z] == 'm')
            {
                activeparam.push(Parameter::minutes);
            }
            else if (argument_array[i][z] == 'h')
            {
                activeparam.push(Parameter::hours);
            }
            else if (argument_array[i][z] == 'd')
            {
                activeparam.push(Parameter::days);
            }
            else if (argument_array[i][z] == 'w')
            {
                activeparam.push(Parameter::weeks);
            }
            else if (argument_array[i][z] == 'e')
            {
                execute_immediately = true;
            }
        }
    }
}

void Main::setParameter(const int i)
{
    if (activeparam.empty())
    {
        std::cout << "Setting the command" << std::endl;
        torun = argument_array[i];
        return;
    }
    std::cout << "Parameter list size from setParameter:" << activeparam.size() << std::endl;
    switch (activeparam.front())
    {
        case Parameter::seconds:
            std::cout << "Adding " << std::atoi(argument_array[i]) << " seconds\n";
            sleep_time += std::chrono::seconds(std::atoi(argument_array[i]));
            break;
        case Parameter::minutes:
            sleep_time += std::chrono::minutes(std::atoi(argument_array[i]));
            break;
        case Parameter::hours:
            sleep_time += std::chrono::hours(std::atoi(argument_array[i]));
            break;
        case Parameter::days:
            sleep_time += std::chrono::hours(24 * std::atoi(argument_array[i]));
            break;
        case Parameter::weeks:
            sleep_time += std::chrono::hours(7 * 24 * std::atoi(argument_array[i]));
            break;
        default:
            break;
    }
    activeparam.pop();
}


std::size_t Main::getParametersRequired(const int i)
{
    std::size_t ssize = std::strlen(argument_array[i]);
    for (std::size_t z = 0; z < ssize; ++z)
    {

    }
}










