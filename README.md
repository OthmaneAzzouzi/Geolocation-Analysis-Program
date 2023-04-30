# Geolocation Analysis Program

The goal of this project is to implement a program that simulates the management of tracks (consists of a geographical coordinate in the form of latitude and longitude as well as an integer indicating the time of arrival at this location (in minutes since midnight) in a city, using various data structures and algorithms.

The program reads a list of track from an input file and processes them in the order they are read. Each task represents a situation that requires the city's intervention. The program efficiently manage and process the tasks to minimize waiting times and complete them as quickly as possible.

# Data Structures Used

The Tableau (Array) class implementation provided here was designed specifically for the Geolocation Analysis Program project. This custom implementation was created to optimize the performance of the program by providing efficient and tailored functionality for storing and manipulating data.

Compared to a standard implementation of an array data structure, the Tableau class may provide better performance in certain scenarios. For example, the ajouter(), add() function includes an amortized time complexity of O(1) for adding elements to the array, which is more efficient than a standard implementation's O(n) complexity for resizing the array. Additionally, the sort() function uses a heap sort algorithm, which has a time complexity of O(n log n) and may perform faster than a standard implementation's sorting algorithm.


# Prerequisites

To compile and run the project, you will need:

A C++ compiler compatible with the C++11 standard or higher
The provided source code and input files

# Compilation

To compile the program, navigate to the project folder and run the following command:

```bash

g++ -std=c++11 -o program main.cpp

```

This command will compile the source code and generate an executable named program.

# Usage

To run the program, use the following command:

```bash
./program <input_file>
```

Where <input_file> is the path to the input file containing the list of tasks.

The program will read the input file, process the tasks, and output the results in the following format:

```bash
TaskID: <task_id> | Priority: <priority> | Status: <status> | Time: <time>
```

Where:

* <task_id> is the unique identifier of the task
* <priority> is the priority of the task (1 = high, 2 = medium, 3 = low)
* <status> is the current status of the task (completed or pending)
* <time> is the time spent on the task

# Input File Format

The input file should contain a list of tasks, one per line, in the following format:


```bash
<task_id> <priority> <time_required>
```
Where:

* <task_id> is a unique identifier for the task (a positive integer)
* <priority> is the priority of the task (1 = high, 2 = medium, 3 = low)
* <time_required> is the time required to complete the task (a positive integer)

# Example
Here is an entry example: 


```bash
Marc
(45.509207,-73.568186) 500 ;
(45.509888,-73.570654) 670 ;
(45.508737,-73.572344) 800 ;
(45.508986,-73.568310) 1080 ;
--
Eve
(45.509948,-73.570804) 500 ;
(45.509286,-73.568221) 540 ;
(45.508809,-73.572421) 1080 ;
(45.508380,-73.571314) 1360 ;
--
```

This example visually corresponds to the following map:

[![traces00.png](https://i.postimg.cc/hGfkc8F6/traces00.png)](https://postimg.cc/HJ1Ztyk9)

Marc arrives at position (45.509207,-73.568186) (PK de l'UQAM) at time 500. Ève arrives at position (45.509286,-73.568221) (PK de l'UQAM) a little later at time 540. Since these two positions are 25 meters away or less, Mark and Eve are deemed to be at the same place from time 540. Mark moves at time 670 to his next destination (45.509888,-73.570654). So Mark and Eve have spent 670 - 540 = 130 minutes so far. Please note that 131 minutes should not be counted, because minute 540 is included, but minute 670 is excluded (he is returned to his other place). Mark and Eve are thus acquaintances (they have spent 120 minutes or more together). However, they are not friends. When Eve arrives at her third place at time 1080, Marc has already arrived at his fourth place at time 1080. They therefore did not meet a second time, the minimum condition for being friends. If Marc had moved at minute 1081, that would have been enough for them to be friends, as evidenced by the result with traces01.txt.

# Important Note on Code Conventions

Please be aware that in the source code for this program, variable names, function names, and comments are primarily written in French. We understand that this might pose some challenges for users who are not familiar with the French language. However, We have ensured that the user documentation, such as this README, is written in English for broader accessibility.

# Authors

The project was developed by Othmane Azzouzi and Besma Jabri.

