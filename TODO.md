# TODO #
========

[x] - Parse concatenated shorts: "-a -b -c" becomes "-abc"
[x] - Parse long flags: --long_flag
[x] - Bind the subsequent argument to the last flag: "--long_flag arg"
[x] - Bind the subsequent argument to the last _unset_ flag: "-abc crg brg arg", should assign crg to c, brg to b, and arg to a
* [x] - Create a stack of unset flags
* [x] - Pop each flag and assign the arguments
[ ] - Allow setting a certain flag to take no arguments: "Arguments::setPureFlag({const std::string &flag | const char flag})"
[ ] - Ignore stacking inert flags