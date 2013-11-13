# Arg++ #
---------

A nice and clean C++ class for handling the work of parsing input arguments.
Sorts the arguments correctly and binds them together with flags.
This allows the programmer to quickly identify and implement different command-line input.
At the same time; all _dirty_ code is abstracted away.

## Tiny Tutorial ##
-------------------

We read the argument string from left to right.

### Path ###
------------

The path that the program is being run from is always fetched and stored separately.  
It is returned by the "getPath()" method, and is always the first string of char *argv[].

### Flag ###
------------

A flag is a program option. Options are defined by:  
* - one dash; single-character option  
* -- two dashes; multiple-character option  

### Argument ###
----------------

An argument is a piece of data that belongs to a flag.  
Method 1: "-o a" would make "a" the argument to option "-o". This method uses a whitespace as separator.  
Method 2: "-o=a" would make "a" the argument to option "-o". This method uses a '=' as separator.  
An argument will always be bound to the last unset, _non-inert_ flag.  
(We get back to that later)

### Flag Chaining ###
---------------------

A single-characted flag can be chained:
  "-a -b -c" becomes "-abc"

### Option-Argument Mirroring ###
---------------------------------

Arguments will be applied to the last unset, _non-inert_ flag such that in:  
  "-q -abc uvw dre xyz nmr"  
uvw will be bound to "-c"  
dre will be bound to "-b"  
xyz will be bound to "-a"  
and nmr will be bound to "-q"

### Inertia ###
---------------

Flags that are inert will not be filled in by arguments:  
  Let flags "-a", "-b", "-c" exist.  
  Let flag "-b" be inert.  
  "-abc some argument"  
Will bind "some" to "-c" and "argument" to "-a".

### Operands ###
----------------

Operands are flagless arguments. They are created when:  
1. There are no more flags to bind to  
or  
2. We have given anything behind "--" (Flag Terminator)

### Flag Termination ###
------------------------

All flag-starters ('-' and "--") will be ignored after issueing a "--" followed by nothing:  
  Let flags "-a", "-b", "-c" exist.  
  Let flag "-b" be inert.  
  "-ab data -- -c dr"  
Will bind "data" to "-a"  
Will add "-c" and "dr" to a collection of operands.


## About ##
-----------

C++ argument parsing utility class.  
Written in pure C++.  
Conforms with the GNU Utility Syntax guidelines. One exception: "-o foo" is NOT "-ofoo" due to "option-argument mirroring".

## Sample ##
------------

See the folder ./src/main.cpp  
This file will contain a complete test