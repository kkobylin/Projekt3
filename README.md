# Clinic console Application
> C++ console application, which simulate the clinic, using mechanism of inheritance, polymorphism, interfaces, containers of the STL library and exception handling in Code Blocks environment.

## Technologies
* C++ 11
* Code Blocks 16.1
* STL library

## Setup
Download the project from repository, build it using makefile and run it.

### Description
The project simulate working of the clinic by presenting on the console messages about every 
activities in each unit of time. Parameters (like number of specialists, how much time every doctor spend
on one patient etc.) are taking from user (from dane.txt file).
In the clinic there are 3 types of specialists. Every Doctor is available for specified amount of time
for specified amount of time. If the patient want to go to a doctor, which is unavailable or busy
the patient go to a queue. In each unit of time there are 3 random activies doing by random patients.
If chosen patient is now busy, no action is performed.
