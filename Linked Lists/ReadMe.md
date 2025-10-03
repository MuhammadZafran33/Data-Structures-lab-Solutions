# 🚌 BRT Peshawar Passenger Queue Management System
A C++ implementation of a linked list-based queue management system for BRT Peshawar, simulating passenger boarding operations with different priority levels.

## 📋 Overview
This project demonstrates a real-world application of linked lists in managing passenger queues for bus rapid transit systems. It handles different types of passengers with varying boarding priorities:

Normal Passengers: Join at the end of the queue

Emergency Passengers: VIP/medical cases that join at the front

Special Booking Passengers: Join at specific positions in the queue

# 🏗️ Data Structures
## Node Structure
<img width="641" height="274" alt="image" src="https://github.com/user-attachments/assets/c886694d-8353-45a4-aa5d-d15ef5385994" />

---

## LinkedList Class
### Implements all queue operations with the following methods:

insertAtBeginning(int value) - Emergency boarding

insertAtEnd(int value) - Normal boarding

insertAtPosition(int value, int pos) - Special booking

deleteFromBeginning() - Passenger boards the bus

display() - Show current queue status

## 🚀 Features
Efficient Operations: O(1) for insertion at beginning/end, O(n) for position-based insertion

Memory Management: Proper dynamic memory allocation and deallocation

Error Handling: Graceful handling of edge cases and invalid positions

Real-time Simulation: Step-by-step queue management simulation

## 📊 Simulation Scenario
The program demonstrates a complete BRT queue scenario:

Initial Queue: 3 normal passengers join at the end (101, 102, 103)

Emergency Case: VIP passenger (999) joins at the front

Special Booking: Passenger (555) joins at position 2

Boarding: First passenger boards the bus

---

# 🎯 Key Algorithms
### Insertion at Beginning

<img width="528" height="574" alt="image" src="https://github.com/user-attachments/assets/af98589a-102b-46ca-91fa-54afbc8bab8d" />



Position-based Insertion
Traverse to position-1

Update pointers to insert between nodes

Handle edge cases (position 0, out-of-range)

## 💡 Time Complexity

<img width="879" height="468" alt="image" src="https://github.com/user-attachments/assets/392d9e74-64a6-4df8-9ceb-9dc16954149d" />


## 🧪 Testing
The code includes built-in test scenarios that demonstrate:

Empty queue handling

Multiple insertion types

Position validation

Memory cleanup

## 📝 License
This project is open source and available under the MIT License.

## 🤝 Contributing
Contributions are welcome! Please feel free to submit pull requests or open issues for:

Additional queue operations

Enhanced error handling

Performance optimizations

Extended simulation scenarios

---
# 👨‍💻 Author
BRT Peshawar Simulation Team

Data Structures and Algorithms Project


