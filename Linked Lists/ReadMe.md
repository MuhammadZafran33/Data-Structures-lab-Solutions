# 🚌 BRT Peshawar Passenger Queue Management System
A C++ implementation of a linked list-based queue management system for BRT Peshawar, simulating passenger boarding operations with different priority levels.

## 📋 Overview
This project demonstrates a real-world application of linked lists in managing passenger queues for bus rapid transit systems. It handles different types of passengers with varying boarding priorities:

Normal Passengers: Join at the end of the queue

Emergency Passengers: VIP/medical cases that join at the front

Special Booking Passengers: Join at specific positions in the queue

# 🏗️ Data Structures
## Node Structure
-
struct Node {
    int data;       // Passenger ID
    Node* next;     // Pointer to next passenger
    Node(int d);    // Constructor
};
-
