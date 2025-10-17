# 🔗 IP Address Doubly Linked List Manager
## 📖 Overview
A robust C++ implementation of a **doubly linked list** specifically designed to handle IP address management. This program efficiently reads IP addresses from a file and organizes them in a bidirectional linked list structure, allowing seamless traversal in both forward and reverse directions.

## 🎯 Problem Statement
**Challenge:** How to efficiently store and manage a collection of IP addresses while maintaining the ability to traverse them in both chronological and reverse order?

**Solution:** Implement a doubly linked list where each node contains an IP address and pointers to both previous and next nodes, creating a flexible data structure that supports bidirectional traversal.

# 🏗️ Architecture
## Core Components
### 1. Node Class 🧩
<img width="116" height="141" alt="image" src="https://github.com/user-attachments/assets/60be3e92-e4d6-452e-9854-57ba266f8e69" />
**Each node acts as a container holding:**

. An IP address (as string)

. Reference to the previous node in sequence

. Reference to the next node in sequence

