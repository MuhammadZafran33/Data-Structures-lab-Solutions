

# 📘 Dynamic Circular Queue – C++ Implementation

A clean, efficient, dynamically resizing Circular Queue implementation in C++.
Supports:
Enqueue
Dequeue
Front
Dynamic Resizing
Circular Indexing
Print

# 📌 Features

✔ FIFO (First In First Out)
✔ Dynamic resizing when full
✔ Circular indexing for fast operations
✔ O(1) average time complexity
✔ Memory-safe (no leaks)
✔ Underflow Handling

```mermaid
classDiagram
    class Queue {
        - int* arr
        - int capacity
        - int frontidx
        - int rearidx
        - int currentSize
        + Queue(int initialCapacity)
        + ~Queue()
        + bool isEmpty()
        + int size()
        + void enqueue(int value)
        + void dequeue()
        + int front()
        + void print()
        - void resize()
    }
```

---

# 🌀 Circular Queue Visualization
## Circular Memory Movement

```mermaid
graph TD
    A0[Index 0] --> A1[Index 1]
    A1 --> A2[Index 2]
    A2 --> A3[Index 3]
    A3 --> A0
    style A3 fill:#ffdddd
    style A0 fill:#ddffdd
```

# 🧱 Queue Example (Front → Rear)
```mermaid
graph LR
    A[Front: 10] --> B[20] --> C[30] --> D[Rear: 40]


```
---

# 🚀 Resize Operation (Capacity Doubles)
## Before Resize (Capacity = 4)
```mermaid
graph LR
    A[10] --> B[20] --> C[30] --> D[40] --> E[ ] --> F[ ] --> G[ ] --> H[ ]

```
---
# 🔄 Enqueue Flowchart (GitHub-Compatible Mermaid)
```mermaid
flowchart TD
    A[enqueue value] --> B{Is Queue Full?}
    B -- Yes --> C[Call resize]
    B -- No --> D[Insert value at rearidx]
    C --> D
    D --> E[rearidx = rearidx + 1 % capacity]
    E --> F[currentSize = currentSize + 1]
    F --> G[Done]
```

# 🔁 Dequeue Flowchart
```mermaid
flowchart TD
    A[dequeue] --> B{Is Queue Empty?}
    B -- Yes --> C[Print Underflow]
    B -- No --> D[frontidx = frontidx + 1 % capacity]
    D --> E[currentSize = currentSize - 1]
    E --> F[Done]
```
---

# 🧠 Core Concepts Explained
## 1️⃣ Circular Indexing

To avoid shifting elements during dequeue:

(frontidx + i) % capacity


### Benefits:

O(1) dequeue

No shifting

Efficient memory usage

## 2️⃣ Dynamic Resizing

### When queue is full:

Capacity doubles

Elements are copied in correct order

New array replaces old

frontidx = 0

rearidx = currentSize

This makes the queue scalable.

## 3️⃣ Memory Management

Uses new[] to allocate

Uses delete[] in destructor

Prevents memory leaks

---

# 🏁 Conclusion

This project demonstrates:

Circular queue logic

Dynamic memory handling

Efficient enqueue/dequeue operations

Proper modular arithmetic

Clean C++ class design

If you want, I can add:

✅ UML Sequence Diagram
✅ Animated Flowchart
✅ More test cases
✅ Separate .h and .cpp files
✅ Better styling for GitHub

Just tell me!
---
---


