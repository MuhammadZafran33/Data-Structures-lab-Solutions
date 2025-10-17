# 🔗 IP Address Doubly Linked List Manager

## 📖 Overview
A robust C++ implementation of a **doubly linked list** specifically designed to handle IP address management. This program efficiently reads IP addresses from a file and organizes them in a bidirectional linked list structure, allowing seamless traversal in both forward and reverse directions.

---
## 🎯 Problem Statement
**Challenge:** How to efficiently store and manage a collection of IP addresses while maintaining the ability to traverse them in both chronological and reverse order?

**Solution:** Implement a doubly linked list where each node contains an IP address and pointers to both previous and next nodes, creating a flexible data structure that supports bidirectional traversal.

---

# 🏗️ Architecture
## Core Components
### 1. Node Class 🧩
<img width="587" height="82" alt="image" src="https://github.com/user-attachments/assets/886ad676-c5c3-41b0-921d-d22dd7f73ed6" />


**Each node acts as a container holding:**

**. An IP address (as string)
. Reference to the previous node in sequence
. Reference to the next node in sequence**

### 2. Doubly Linked List Class �
<img width="292" height="53" alt="image" src="https://github.com/user-attachments/assets/2af8f499-9330-4484-a2b7-560672b521a9" />

**. Manages the entire chain of nodes with capabilities to:**

**. Insert new IP addresses at the beginning
 . Display all IPs from start to end
. Display all IPs from end to start**

# 🎮 How It Works
## Data Flow Process
### File Reading Phase 📖

. Program opens ips.txt

. Reads entire line of comma-separated IP addresses

. Safely closes the file after reading

### Data Processing Phase ⚙️

. Splits the input string into individual IP addresses

. Creates new nodes for each IP

. Inserts nodes at the beginning of the linked list

### Display Phase 🖥️

**. Forward Traversal: Starts from head, follows next pointers**

**. Backward Traversal: Starts from tail, follows previous pointers**

# 💡 Technical Features
## 🛡️ Error Handling
. File existence validation

. Empty list detection

. Memory allocation safety

## 🔄 Bidirectional Navigation
**. Forward Display:** Head to Tail (reverse insertion order)

**. Backward Display:** Tail to Head (original file order)

## 💾 Memory Efficiency
. Dynamic memory allocation

. Proper node linking

. No memory leaks

## 📊 Sample Execution

---
<img width="856" height="235" alt="image" src="https://github.com/user-attachments/assets/e8a2b81e-1a05-4843-bf94-fd8422149b4d" />

### Explanation
**> Forward:** Shows IPs in reverse order of file reading (LIFO - Last In First Out)

**> Backward:** Shows IPs in exact order they appeared in file (FIFO - First In First Out)

---

## 🎯 Learning Outcomes
### Computer Science Concepts
**->Data Structures:** Doubly Linked List implementation

**->Memory Management:** Dynamic allocation and pointers

**->File I/O:** Reading and parsing text files

**->Algorithms:** List traversal and manipulation

## Practical Skills
### C++ object-oriented programming

. Pointer manipulation

. String processing

. Error handling in file operations

## 🔧 Customization Options
### Easy Modifications
. Change separator from comma to semicolon or space

. Modify display format (add timestamps, indexes)

. Implement additional operations (delete, search, sort)

. Extend to handle IPv6 addresses

## 📈 Potential Enhancements
> IP address validation

> Duplicate detection

> Sorting capabilities

> Network range calculations

> Export to different formats

## 🐛 Troubleshooting
### Common Issues
**-> File Not Found:** Ensure ips.txt exists in same directory

**-> Empty Output:** Check if file contains valid comma-separated IPs

**-> Compilation Errors:** Verify C++ compiler installation

## Debugging Tips
. Add print statements to trace execution flow

. Check file permissions

. Validate IP address format in input file

## 🤝 Contributing
**-> This project serves as an excellent foundation for learning data structures. Feel free to:**

> Add new features 

> Improve error handling

> Optimize performance

> Enhance documentation

## 📄 License
Open for educational and learning purposes. Perfect for computer science students and programming enthusiasts.

**⭐ Star this repository if you found it helpful for understanding doubly linked lists and file handling in C++!**

---


