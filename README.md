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

# Authors

The project is developed by Othmane Azzouzi and Besma Jabri.

