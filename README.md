# Arg++ #
-------------

## About ##
-----------

C++ argument parsing utility class.

`C++
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
`