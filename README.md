# ADT-Digraph

 Task Scheduler and Directed Acyclic Graph
This README provides an overview of the C++ code provided, which is a program for managing and analyzing task dependencies using a directed acyclic graph (DAG). The program allows you to input tasks, their order relations, and perform operations like adding edges, deleting edges, checking for acyclic dependencies, and generating a topological sort order of tasks.

Table of Contents
Overview
Features
Prerequisites
How to Use
Code Structure
Sample Input and Output
License
Overview
The provided C++ code defines a Digraph class representing a directed graph. This class allows you to create a graph of tasks and their order relations. You can then perform various operations to manage and analyze these dependencies. The key features of this program include:

Features
1. Task Management
Input the number of tasks and their descriptions.
Input the order relations between tasks.
2. Graph Operations
Add an edge between tasks to establish a dependency.
Delete an edge to remove a dependency.
3. Dependency Analysis
Check if the graph is acyclic, indicating a valid task order with no circular dependencies.
Generate a topological sort order of tasks, assuming the graph is acyclic.
4. Interactive Menu
A menu-driven interface allows you to select and execute these operations.
Prerequisites
To compile and run this code, you need a C++ compiler such as g++ (GNU Compiler Collection) installed on your system.

How to Use
Compile the Code: Compile the C++ code using a C++ compiler. For example, if you're using g++, open your terminal and navigate to the directory containing the code. Then, compile it with:

```bash
g++ -o task_scheduler task_scheduler.cpp
```
Run the Program: Execute the compiled program:

```bash
./task_scheduler
```
Follow the Menu: The program will display a menu that allows you to input tasks, manage dependencies, check for acyclic dependencies, and generate a topological sort order.

Interact with the Program: Follow the on-screen prompts and make selections based on your desired actions.

Exit the Program: To exit the program, select option 5 in the menu.

Code Structure
The code is structured into two main parts:

Digraph Class: This class defines the directed graph structure and methods for managing and analyzing dependencies.

main() Function: This is the entry point of the program. It provides a user-friendly interface to interact with the Digraph class and perform various operations.

Sample Input and Output
To demonstrate the program's functionality, here are some sample input and output scenarios:

Sample Input:

```mathematica
Copy code
Enter the number of tasks: 4
Enter task 1: Task A
Enter task 2: Task B
Enter task 3: Task C
Enter task 4: Task D
Enter the number of order relations: 3
Enter order relation (e.g., 3 1): 2 1
Enter order relation (e.g., 3 1): 3 2
Enter order relation (e.g., 3 1): 4 3
```
## Sample Output:

```mathematica
Copy code
Menu:
1. Add Edge
2. Delete Edge
3. Check Acyclic
4. Topological Sort
5. Exit
Enter your choice: 3

The graph is acyclic.

Menu:
1. Add Edge
2. Delete Edge
3. Check Acyclic
4. Topological Sort
5. Exit
Enter your choice: 4

Topological Sort Order:
Task D
Task C
Task B
Task A
```
License
This code is provided under an open-source license. You are free to use and modify it as needed. See the LICENSE file for more details.

Feel free to explore, adapt, and extend this code for your task management and dependency analysis needs. Enjoy using the program!
## DEVELOPED BY MABON NINAN
## MOHHAMED FAWWAAZ
## MUHIB KHAN
