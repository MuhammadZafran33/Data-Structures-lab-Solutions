

# 📘 Dynamic Circular Queue – C++ Implementation

A clean, efficient, dynamically resizing Circular Queue implementation in C++.
Supports:

Enqueue

Dequeue

Front

Dynamic Resizing

Circular Indexing

Print

Underflow Handling
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
