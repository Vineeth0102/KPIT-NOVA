# Requirements
 - VS Code
 - Git
 - CxxTest Suite
 - A C++ Compiler

# Execution
This section explains how to run the assignments locally. It is assumed that you already have all your requirements installed.

First clone this repository using the below command.
```
$ git clone https://github.com/Vineeth0102/KPIT-NOVA
$ cd KPIT-NOVA
```
Now go into any one of the Assignment folder that you want to run.
```
$ cd "Name of the dir"
```
Generate the runner file using `cxxtestgen` command.
```
$ cxxtestgen --error-printer -o runner.cpp test.h
```
After this a new `runner.cpp` will be created in the same location.  
  
Now compile the `runner.cpp` file appropriately using any of your preferred C++ compiler. 
```
$ g++ -o runner bitmap.cpp runner.cpp
```
A new executable file named `runner` will be created in the same location.  
  
Now if you execute that file, you should see something like the following.
```
$ ./runner
Running cxxtest tests (1 test).OK!
```
Congratulations! All your tests have passed and you have no error.
