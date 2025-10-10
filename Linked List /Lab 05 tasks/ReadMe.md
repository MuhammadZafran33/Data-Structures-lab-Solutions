# T-Shirt Queue Management System
## 📋 Project Overview
A console-based application developed for a university Code-a-Thon event to efficiently manage the queue of students waiting for limited-edition T-shirts. This system handles dynamic student queues where participants can join, leave unexpectedly, and get served in a fair first-come-first-served manner.

### 🎯 Problem Statement
The first 100 participants to arrive at the Code-a-Thon receive free T-shirts. Managing this queue manually is challenging because:

The number of students is unknown and constantly changing

Students may leave the queue unexpectedly

Order must be maintained for fair distribution

Real-time queue status is essential for organizers

## ✨ Features
### 🎪 Core Operations
Add Student: New students join the end of the queue with name and ID

Serve Student: Front student receives T-shirt and leaves queue

Remove Student: Remove any student by ID (for early departures)

Display Queue: View all students in order from front to back

Count Students: Get real-time count of waiting students

## 🔧 Technical Features
Dynamic Memory Management: No fixed size limitations.

Efficient Operations: O(1) for add/serve, O(n) for removal.

Robust Error Handling: Handles empty queue scenarios gracefully.

User-Friendly Interface: Simple menu-driven console application.

## Example Usage
Adding Students: Input name and ID, automatically joins queue end

Serving Students: Front student gets T-shirt, removed from queue

Removing Students: Enter ID to remove from any position

Monitoring: Real-time queue display and count updates

Key Components
Student Structure: Contains name, ID, and next pointer

StudentQueue Class: Implements all queue operations

Main Function: Handles user interface and menu loop

## Main Classes & Methods

addStudent(string name, int id): Add to queue end

serveStudent() : Remove and serve front student

removeStudentById(int id): Remove specific student

displayQueue(): Show all students in order

countStudents(): Return current queue size



