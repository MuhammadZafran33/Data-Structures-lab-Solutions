

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

```mermaid
graph TD
    A0[Index 0] --> A1[Index 1]
    A1 --> A2[Index 2]
    A2 --> A3[Index 3]
    A3 --> A0
    style A3 fill:#ffdddd
    style A0 fill:#ddffdd
```
