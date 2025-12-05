                                           # Chronos Time Stabilizer V1.0.......
---
---

# 📋 Project Overview
Chronos Time Stabilizer V1.0 is a C++ program that implements a Binary Search Tree (BST) to manage historical events organized by year. The system uses time-travel themed terminology to provide an interactive interface for inserting, deleting, searching, and reporting on timeline events.

# 🏗️ Data Structure
TimeCapsule Node Structure
Each node in the BST contains:
This graph shows how events are organized in the Binary Search Tree

### Explanation: The BST organizes events by year, where:

Each node contains a year and event description

Years less than current node go to LEFT subtree

Years greater than current node go to RIGHT subtree

The tree automatically maintains chronological order

Root (2000) is highlighted in green, showing it's the first inserted year

```mermaid
graph TB
    ROOT[Year: 2000<br/>Millennium Celebration]
    
    LEFT1[Year: 1995<br/>Internet Boom]
    RIGHT1[Year: 2005<br/>Social Media Rise]
    
    LEFT2[Year: 1990<br/>World Wide Web]
    LEFT3[Year: 1998<br/>Google Founded]
    RIGHT2[Year: 2010<br/>Smartphone Era]
    RIGHT3[Year: 2020<br/>AI Revolution]
    
    ROOT --> LEFT1
    ROOT --> RIGHT1
    LEFT1 --> LEFT2
    LEFT1 --> LEFT3
    RIGHT1 --> RIGHT2
    RIGHT1 --> RIGHT3
    
    style ROOT fill:#4CAF50,stroke:#333,stroke-width:2px,color:#fff
    style LEFT1 fill:#2196F3,stroke:#333,stroke-width:1px,color:#fff
    style RIGHT1 fill:#2196F3,stroke:#333,stroke-width:1px,color:#fff
    style LEFT2 fill:#FF9800,stroke:#333,stroke-width:1px,color:#fff
    style LEFT3 fill:#FF9800,stroke:#333,stroke-width:1px,color:#fff
    style RIGHT2 fill:#9C27B0,stroke:#333,stroke-width:1px,color:#fff
    style RIGHT3 fill:#9C27B0,stroke:#333,stroke-width:1px,color:#fff
```

# 📋 2. Complete Program Flowchart
## BST Structure Visualization
This shows the entire program flow from start to end

Explanation: The program follows this sequence:

Starts and initializes the TimeTree

Enters command loop waiting for user input

Processes 6 different commands (INJECT, PARADOX, SEARCH, REPORT, TIMESPAN, EXIT)

Each command triggers specific BST operations

Returns to command loop after each operation

EXIT command cleans memory and ends program

```mermaid
flowchart TD
    START([Start Chronos Time Stabilizer]) --> INIT[Initialize TimeTree]
    INIT --> DISPLAY[Display Welcome Banner]
    DISPLAY --> CMD{Wait for Command Input}
    
    CMD --> INJECT[INJECT<br/>Add Event]
    CMD --> PARADOX[PARADOX<br/>Remove Event]
    CMD --> SEARCH[SEARCH<br/>Find Event]
    CMD --> REPORT[REPORT<br/>Display Timeline]
    CMD --> TIMESPAN[TIMESPAN<br/>Calculate Range]
    CMD --> EXIT[EXIT<br/>Quit Program]
    
    INJECT --> I1[Read Year & Event]
    I1 --> I2{Duplicate Year?}
    I2 -->|No| I3[Insert New Node]
    I2 -->|Yes| I4[Skip - Display Error]
    I3 --> I5[Display: Timeline Stable]
    I4 --> I6[Display: Year Exists]
    
    PARADOX --> P1[Read Year to Delete]
    P1 --> P2{Year Found in Tree?}
    P2 -->|Yes| P3[Delete Node]
    P3 --> P4[Display: Timeline Stabilized]
    P2 -->|No| P5[Display: Year Not Found]
    
    SEARCH --> S1[Read Search Year]
    S1 --> S2{Search BST}
    S2 -->|Found| S3[Display Event Details]
    S2 -->|Not Found| S4[Display: Not in Timeline]
    
    REPORT --> R1[Start In-Order Traversal]
    R1 --> R2[Print All Years in Order]
    R2 --> R3[Display Separator Lines]
    
    TIMESPAN --> T1[Find Minimum Year]
    T1 --> T2[Find Maximum Year]
    T2 --> T3[Calculate Difference]
    T3 --> T4[Display Time Span]
    
    I5 --> CMD
    I6 --> CMD
    P4 --> CMD
    P5 --> CMD
    S3 --> CMD
    S4 --> CMD
    R3 --> CMD
    T4 --> CMD
    
    EXIT --> CLEAN[Clean Memory<br/>Delete All Nodes]
    CLEAN --> STOP([Program End])
    
    style START fill:#4CAF50,stroke:#333,stroke-width:3px,color:#fff
    style STOP fill:#F44336,stroke:#333,stroke-width:3px,color:#fff
    style CMD fill:#FF9800,stroke:#333,stroke-width:2px,color:#000
    style INJECT fill:#2196F3,stroke:#333,stroke-width:1px,color:#fff
    style PARADOX fill:#E91E63,stroke:#333,stroke-width:1px,color:#fff
    style SEARCH fill:#009688,stroke:#333,stroke-width:1px,color:#fff
    style REPORT fill:#9C27B0,stroke:#333,stroke-width:1px,color:#fff
    style TIMESPAN fill:#FF5722,stroke:#333,stroke-width:1px,color:#fff
    style EXIT fill:#F44336,stroke:#333,stroke-width:1px,color:#fff
```

# ➕ 3. Insertion Process:
Shows the recursive algorithm for inserting a new event

### Explanation: The insertNode function works recursively:

If current position is NULL, create new node (base case)

If year < current node's year, go LEFT (recursive call)

If year > current node's year, go RIGHT (recursive call)

If year = current node's year, it's a duplicate (skip)

Returns updated tree structure after insertion

```mermaid
flowchart TD
    A[Start Insertion Process] --> B{Current Node = NULL?}
    
    B -->|YES| C[Create New TimeCapsule Node]
    C --> D[Set: year, event]
    D --> E[left = NULL, right = NULL]
    E --> F[Return New Node]
    
    B -->|NO| G{Compare Year with Current Node}
    G -->|year < node.year| H[Go to Left Subtree<br/>node.left = insertNode<br/>node.left, year, event]
    G -->|year > node.year| I[Go to Right Subtree<br/>node.right = insertNode<br/>node.right, year, event]
    G -->|year = node.year| J[Duplicate Detected<br/>Set inserted = false]
    
    H --> K[Return Updated Node]
    I --> K
    J --> L[Return Original Node]
    
    F --> M[Insertion Complete]
    K --> M
    L --> M
    
    style A fill:#4CAF50,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#2196F3,stroke:#333,stroke-width:2px,color:#fff
    style J fill:#FF9800,stroke:#333,stroke-width:2px,color:#000
    style M fill:#009688,stroke:#333,stroke-width:2px,color:#fff
```


# 4. ❌  Deletion Scenarios
Illustrates the 3 cases handled when deleting a node

### Explanation: The deleteNode function handles 3 scenarios:

Leaf Node: Direct deletion (no children)

One Child: Bypass node, connect child to parent

Two Children: Find in-order successor, replace data, delete successor

In-order successor = smallest node in right subtree

This maintains BST property after deletion
```mermaid
graph TD
    subgraph "BST Node Deletion Cases"
        A[Case 1: Leaf Node] --> A1[Node with No Children]
        A1 --> A2[Direct Deletion<br/>Simply Remove]
        A2 --> A3[Memory Freed]
        
        B[Case 2: Single Child] --> B1[Node with One Child]
        B1 --> B2[Bypass Node]
        B2 --> B3[Child Takes Position]
        B3 --> B4[Delete Original Node]
        
        C[Case 3: Two Children] --> C1[Node with Both Children]
        C1 --> C2[Find In-Order Successor<br/>Minimum of Right Subtree]
        C2 --> C3[Copy Successor Data]
        C3 --> C4[Delete Successor]
        C4 --> C5[Original Node Updated]
    end
    
    style A fill:#4CAF50,stroke:#333,stroke-width:2px,color:#fff
    style B fill:#2196F3,stroke:#333,stroke-width:2px,color:#fff
    style C fill:#9C27B0,stroke:#333,stroke-width:2px,color:#fff
    style A3 fill:#FF9800,stroke:#333,stroke-width:1px,color:#000
    style B4 fill:#FF9800,stroke:#333,stroke-width:1px,color:#000
    style C5 fill:#FF9800,stroke:#333,stroke-width:1px,color:#000

```

# 🔍 5. Search Algorithm Flow:
Shows how the program searches for a specific year

### Explanation: The searchNode function works recursively:

If node is NULL → year not found (return NULL)

If year = node.year → found! (return node pointer)

If year < node.year → search in left subtree

If year > node.year → search in right subtree

Returns pointer to node if found, NULL if not found
```mermaid
flowchart LR
    START([Search Start]) --> NODE{Check Current Node}
    
    NODE -->|Node = NULL| NOTFOUND[Return NULL<br/>Year Not Found]
    
    NODE -->|Node ≠ NULL| COMPARE{Compare Year}
    
    COMPARE -->|year = node.year| FOUND[Return Node<br/>Success!]
    COMPARE -->|year < node.year| LEFT[Search Left Subtree<br/>searchNode node.left, year]
    COMPARE -->|year > node.year| RIGHT[Search Right Subtree<br/>searchNode node.right, year]
    
    LEFT --> NODE
    RIGHT --> NODE
    
    FOUND --> END([Search Complete])
    NOTFOUND --> END
    
    style START fill:#4CAF50,stroke:#333,stroke-width:3px,color:#fff
    style FOUND fill:#2196F3,stroke:#333,stroke-width:2px,color:#fff
    style NOTFOUND fill:#F44336,stroke:#333,stroke-width:2px,color:#fff
    style END fill:#009688,stroke:#333,stroke-width:3px,color:#fff
```


# 🏗️6. Complete System Architecture:

Shows the layered architecture of the entire system

### Explanation: The system has 3 main layers:

### User Interface Layer: Handles command input/output

### Core BST Engine: Implements tree operations

### Data Structure: TimeCapsule nodes

Commands map to specific operations:

INJECT → Insert Node

PARADOX → Delete Node

SEARCH → Search Node

REPORT → In-Order Traversal

TIMESPAN → Find Min/Max

```mermaid
graph LR
    subgraph "CHRONOS TIME STABILIZER V1.0"
        UI[User Interface Layer] --> CORE[Core BST Engine]
        CORE --> DATA[TimeCapsule Data Structure]
        
        subgraph "BST Operations"
            OP1[Insert Node]
            OP2[Delete Node]
            OP3[Search Node]
            OP4[Traverse In-Order]
            OP5[Find Min/Max]
        end
        
        subgraph "Commands"
            CMD1[INJECT - Insert]
            CMD2[PARADOX - Delete]
            CMD3[SEARCH - Find]
            CMD4[REPORT - Display]
            CMD5[TIMESPAN - Range]
        end
        
        UI --> CMD1
        UI --> CMD2
        UI --> CMD3
        UI --> CMD4
        UI --> CMD5
        
        CMD1 --> OP1
        CMD2 --> OP2
        CMD3 --> OP3
        CMD4 --> OP4
        CMD5 --> OP5
        
        OP1 --> DATA
        OP2 --> DATA
        OP3 --> DATA
        OP4 --> DATA
        OP5 --> DATA
    end
    
    style UI fill:#4CAF50,stroke:#333,stroke-width:3px,color:#fff
    style CORE fill:#2196F3,stroke:#333,stroke-width:2px,color:#fff
    style DATA fill:#9C27B0,stroke:#333,stroke-width:2px,color:#fff
    style OP1 fill:#FF9800,stroke:#333,stroke-width:1px,color:#000
    style OP2 fill:#FF9800,stroke:#333,stroke-width:1px,color:#000
    style OP3 fill:#FF9800,stroke:#333,stroke-width:1px,color:#000
    style OP4 fill:#FF9800,stroke:#333,stroke-width:1px,color:#000
    style OP5 fill:#FF9800,stroke:#333,stroke-width:1px,color:#000
```


# 🧹 7. Memory Management Flow:
Shows how the program manages dynamic memory

### Explanation: Memory management follows this pattern:

### Constructor: Initializes root to NULL

### During operations:

new TimeCapsule allocates memory for new nodes

delete node frees memory when nodes are removed

Destructor: Called on EXIT command

clearTree performs post-order traversal

Deletes all nodes from bottom-up

Ensures no memory leaks


```mermaid

flowchart TD
    START([Program Start]) --> CONSTRUCT[TimeTree Constructor<br/>root = NULL]
    
    CONSTRUCT --> OPERATIONS[BST Operations]
    
    OPERATIONS --> INSERT[Node Insertion<br/>new TimeCapsule]
    OPERATIONS --> DELETE[Node Deletion<br/>delete node]
    
    INSERT --> MEM1[Allocate Memory<br/>Heap Storage]
    DELETE --> MEM2[Free Memory<br/>Prevent Leaks]
    
    OPERATIONS --> EXITCMD{EXIT Command?}
    
    EXITCMD -->|Yes| DESTRUCT[TimeTree Destructor]
    DESTRUCT --> CLEARTREE[clearTree root]
    CLEARTREE --> TRAVERSE[Post-Order Traversal]
    TRAVERSE --> DELNODE[Delete Each Node]
    DELNODE --> MEMFREE[All Memory Freed]
    MEMFREE --> END([Safe Exit])
    
    EXITCMD -->|No| OPERATIONS
    
    style START fill:#4CAF50,stroke:#333,stroke-width:3px,color:#fff
    style CONSTRUCT fill:#2196F3,stroke:#333,stroke-width:2px,color:#fff
    style DESTRUCT fill:#F44336,stroke:#333,stroke-width:2px,color:#fff
    style MEMFREE fill:#009688,stroke:#333,stroke-width:2px,color:#fff
    style END fill:#9C27B0,stroke:#333,stroke-width:3px,color:#fff
```


# 📅 8. Timeline Display Process:
Shows how events are displayed in chronological order

### Explanation: The printInOrder function:

Uses in-order traversal (Left-Root-Right)

Recursively visits left subtree first (earlier years)

Processes current node (prints year: event)

Recursively visits right subtree (later years)

Output is automatically sorted chronologically

```mermaid
timeline
    title Chronological Report Process
    section In-Order Traversal
        Step 1 : Visit Left Subtree<br/>Recursively traverse left child
        Step 2 : Process Current Node<br/>Print year: event
        Step 3 : Visit Right Subtree<br/>Recursively traverse right child
    section Output Format
        Header : > COMMAND: CHRONOLOGICAL REPORT<br/>-------------------------------
        Body   : Year-Event pairs<br/>in ascending order
        Footer : -------------------------------
```
---
---
# 🎯 Key Takeaways from the Code Analysis:
### BST Organization: Events are sorted by year automatically

### Recursive Design: All core operations use recursion for elegant tree traversal

### Memory Safety: Proper constructor/destructor pairing prevents leaks

### User-Friendly: Time-travel theme makes technical operations engaging

### Efficiency: BST provides O(log n) operations on average

### Data Integrity: Prevents duplicate years, maintains chronological order

