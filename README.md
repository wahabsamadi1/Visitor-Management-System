# Visitor Management System

### Overview
This project implements a simple Visitor Management System using C++ with a linked list to track visitor check-ins and check-outs. It allows users to store visitor data (ID, name, check-in, and check-out time) in memory and persist it to a file.

### Features
+ **Check-In Visitor:** Add new visitors by entering their ID, name, and check-in time.  
+ **Check-Out Visitor:** Record the check-out time for a visitor using their ID.  
+ **Display All Visitors:** Display a list of all visitors currently checked in or out.  
+ **Data Persistence:** Visitor data is saved to a text file (visitors.txt) and loaded from it upon startup.  

### File Structure
+ **visitors.txt:** Stores the visitor information. Each visitor's data is stored in the following format:    
ID  
Name  
CheckInTime  
CheckOutTime  

### How to Use
1. Clone the repository:  
   git clone https://github.com/your-username/Visitor-Management-System.git
   cd Visitor-Management-System    
2. Compile the C++ code:
   g++ -o visitor_management main.cpp  
3. Run the program:  
   ./visitor_management

### Options
+ Check-In Visitor: Adds a new visitor to the system.
+ Check-Out Visitor: Allows you to mark a visitor as checked out.
+ Display All Visitors: Lists all visitors along with their check-in and check-out times.
+ Exit: Saves the visitor data to the file and exits the program.

### Sample Output
Visitor Management System  
1. Check-In Visitor  
2. Check-Out Visitor  
3. Display All Visitors  
4. Exit  
Enter your choice: 1  
Enter Visitor ID: 101  
Enter Visitor Name: John Doe  
Enter Check-In Time (HH:MM): 10:00  

Visitor checked in successfully!  

Visitor Management System  
1. Check-In Visitor  
2. Check-Out Visitor  
3. Display All Visitors  
4. Exit  
Enter your choice: 3  
ID: 101, Name: John Doe, Check-In: 10:00, Check-Out:  

### Code Overview

1. Visitor Structure: Contains fields for visitor ID, name, check-in time, check-out time, and a pointer to the next visitor (used for linked list implementation).
2. Linked List: Each visitor is stored as a node in the linked list, allowing for efficient insertion and deletion of visitor records.
3. File Handling: Visitor data is read from and written to visitors.txt, enabling data persistence.
4. Memory Management: Dynamic memory is allocated for each visitor, and memory is freed after the program exits.

### How It Works
1. Loading Data: When the program starts, visitor data is loaded from visitors.txt.  
2. Managing Visitors: Visitors can be checked in and out, with their data stored in a linked list.  
3. Saving Data: When the program exits, all visitor data is saved to visitors.txt.  
4. Memory Cleanup: All dynamically allocated memory is freed before exiting the program.  

### Requirements
+ C++11 or later.
+ A C++ compiler (e.g., GCC, Clang, or MSVC).

### Files
+ Main.cpp: The main program file that contains the code for the visitor management system.
+ README.md: This file, providing an overview of the project, how it works, and how to run it.
  
### License
This project is licensed under the MIT License. Feel free to use, modify, and distribute this code.
