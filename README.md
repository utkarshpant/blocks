# Telemetry

## A Data Structures and Algorithms library

<br>
A Data Structures and Algorithms library intended to replicate the major functionality of the STL, in a simplified form. 

**Implemented by Utkarsh Pant. www.linkedin.com/in/utkarshpant**

**I write about the process at www.medium.com/@Utkarsh.pant**

<br>

## Features

Telemetry implements **Linked Lists** and **Stacks (so far)** along with the major operations supported by each of them. 

<br>

## Instructions

To use the header files in the current directory structure, first, fork the repository.

1. Now, ensure that you are in the workspace directory, `telemetry`. Inside the subdirectory named `telemetry` is where the code and examples reside. Whenever we're compiling new code, it's easiest to compile while `cd`'d into this directory so we can track where we are.

2. Now, ensure that the source .cpp files to compile are in the `examples` subdirectory. 

3. Then, run the following command: <br> `g++ -I include examples\example_name.cpp -o examples\example_name`

The `-I include` option specifies that the header files to include are in the `include` folder. `examples\example_name.cpp` specifies that the file to be compiled, `example_name.cpp`, is inside `examples`. 

**Note:**
There could be some compatibility issues at this stage. Please ensure that your C++ compiler supports C++ 11 features. It is recommended that you run the following command to set the compiler flags correctly.

`g++ -std=c++11 -I include examples\example_name.cpp -o examples\example_name`

If all else fails then the latest version of MinGW that is compatible with C++ 11 will have to installed. 

## TODO's

1. ~~Implement **Queues**.~~
2. Start working on Algorithms (Start with the List::Sort algorithm).
3. read about and implement testing methods. 
4. Implement a way to _time_ execution, for comparison with STL functions.

_fin._
