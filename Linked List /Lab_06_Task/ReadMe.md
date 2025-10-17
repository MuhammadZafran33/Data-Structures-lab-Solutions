# 🔗 IP Address Doubly Linked List Manager
## 📖 Overview
A robust C++ implementation of a **doubly linked list** specifically designed to handle IP address management. This program efficiently reads IP addresses from a file and organizes them in a bidirectional linked list structure, allowing seamless traversal in both forward and reverse directions.

## 🎯 Problem Statement
**Challenge:** How to efficiently store and manage a collection of IP addresses while maintaining the ability to traverse them in both chronological and reverse order?

**Solution:** Implement a doubly linked list where each node contains an IP address and pointers to both previous and next nodes, creating a flexible data structure that supports bidirectional traversal.

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

