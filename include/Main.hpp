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


#ifndef MAIN_HPP_INCLUDED
#define MAIN_HPP_INCLUDED


// Headers
#include <chrono>
#include <iostream>
#include <vector>


class Main
{
public:

    Main(int argc, char *argv[]);
    ~Main();

    void run();

private:

    const int argument_count;
    char **argument_array;
    std::size_t args_to_process = 0;

    void setSettings();
        void setActiveParameter(const int i);
        void setParameter(const int i);
        std::size_t getParametersRequired(const int i);

    // Options
    std::chrono::seconds sleep_time;
    std::chrono::time_point<std::chrono::system_clock> started;
    bool sleep_since_exit = false;
    std::size_t execution_count = 0;

    enum class Parameter
    {
        seconds,
        minutes,
        hours,
        days,
        weeks,
        months,
        years,
        none
    };
    std::vector<Parameter> activeparam;
};


#endif // MAIN_HPP_INCLUDED
