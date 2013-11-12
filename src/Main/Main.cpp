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
        std::cout << "Slept..." << std::endl;
        std::this_thread::sleep_for(sleep_time);
    }
}


void Main::setSettings()
{
    for (int i = 1; i < argument_count; ++i)
    {
        std::cout << "Parameter list size: " << activeparam.size() << std::endl;
        if (argument_array[i][0] == '-' && activeparam.size() == 0)
        {
            this->setActiveParameter(i);
        }
        else if (activeparam.size() > 0)
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
        args_to_process = std::strlen(argument_array[i]) - 1; // Also depends on the argument
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
            std::cout << argument_array[i] << std::endl;
            std::cout << "Single arg -\n";
            if (argument_array[i] == std::string("-s\0"))
            {
                activeparam.push_back(Parameter::seconds);
                std::cout << "Require minutes" << std::endl;
            }
            else if (argument_array[i] == std::string("-m\0"))
            {
                activeparam.push_back(Parameter::minutes);
            }
            else if (argument_array[i] == std::string("-h\0"))
            {
                activeparam.push_back(Parameter::hours);
            }
            else if (argument_array[i] == std::string("-d\0"))
            {
                activeparam.push_back(Parameter::days);
            }
            else if (argument_array[i] == std::string("-w\0"))
            {
                activeparam.push_back(Parameter::weeks);
            }
            else if (argument_array[i] == std::string("-n\0"))
            {
                activeparam.push_back(Parameter::months);
            }
            else if (argument_array[i] == std::string("-y\0"))
            {
                activeparam.push_back(Parameter::years);
            }
        }
    }
}

void Main::setParameter(const int i)
{
    while (!activeparam.empty())
    {
        std::cout << "Parameter list size from setParameter:" << activeparam.size() << std::endl;
        switch (activeparam.front())
        {
            case Parameter::seconds:
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
            case Parameter::months:
                sleep_time += std::chrono::hours(30 * 24 * std::atoi(argument_array[i]));
                break;
            case Parameter::years:
                sleep_time += std::chrono::hours(365 * 24 * std::atoi(argument_array[i]));
                break;
            default:
                break;
        }
        activeparam.erase(activeparam.begin());
    }
}


std::size_t Main::getParametersRequired(const int i)
{
    std::size_t ssize = std::strlen(argument_array[i]);
    for (std::size_t z = 0; z < ssize; ++z)
    {

    }
}










