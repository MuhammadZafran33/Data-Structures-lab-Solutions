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

## 🧪 Testing Scenarios
### Normal Flow
Students join queue in arrival order

First student gets served first

Queue maintains proper order

### Edge Cases
Empty Queue: Proper error messages.

Student Not Found: Informative feedback.

Memory Management: No leaks on multiple operations.

Large Queues: Handles growing queue sizes.

## 🔍 Why Linked List?
### Advantages for This Use Case
✅ Dynamic Size: No fixed capacity limitations

✅ Efficient Insertion/Deletion: O(1) for queue operations

✅ Flexible Removal: Remove from middle without shifting

✅ Memory Efficiency: Allocates only needed nodes

# 🛠️ Technical Implementation
## Memory Management
Automatic node allocation with new

Proper deallocation with delete

No memory leaks during operations

Handles large number of students efficiently

## Error Handling
Empty queue detection

Invalid input handling

Student not found scenarios

Memory allocation failures

## 📈 Performance Metrics
Operation Efficiency
Best Case: O(1) for primary operations

Worst Case: O(n) only for specific searches

Memory: O(n) proportional to queue size

Scalability: Handles 1 to 1000+ students

## Real-world Performance
Instant response for queue operations

Minimal memory footprint

Suitable for event-scale usage

Robust under continuous operation

## 🔮 Future Enhancements
### Potential Improvements
File persistence for queue data

Graphical user interface

Network capability for multiple stations

SMS notifications for queue position

Analytics and reporting features

Priority queue for special cases

Database integration

## Advanced Features
Real-time web dashboard

Mobile app companion

Automated notifications

Performance analytics

Multi-event support

## 👥 Development Team
Created For: University Code-a-Thon Event
Purpose: Educational demonstration of data structures
Technology: C++ with Linked Lists
Focus: Practical algorithm implementation

## 📄 License
This project is open for educational purposes. Feel free to modify and enhance for learning data structures and algorithm implementation.

## 🤝 Contributing
This is an educational project. Suggestions for improvements are welcome, especially regarding:

Code optimization

Additional features

Better error handling

Enhanced user interface

## 📞 Support
For questions about implementation or to discuss enhancements, please refer to the code comments or contact the development team.

### Happy Coding! 🎉



