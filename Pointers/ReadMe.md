# PROJECT 01...

# Coffee Shop Bill Calculator
Description
This C++ program calculates the total bill for coffee orders at a coffee shop. It uses pointers to manage prices and quantities for three types of coffee: Espresso, Latte, and Cappuccino.

## Features
Calculates total bill based on coffee quantities and prices

Demonstrates pointer usage in C++

Handles three coffee types with fixed prices:

Espresso: 500 units

Latte: 300 units

Cappuccino: 250 units

Using Visual Studio (Windows):
Compile and run through the IDE or use Developer Command Prompt.

## How to Use
Run the program

Enter the quantity for Espresso when prompted

Enter the quantity for Latte when prompted

Enter the quantity for Cappuccino when prompted

The program will display the total bill amount

Code Structure
Variables: Stores prices and quantities for each coffee type

Pointers: Points to price and quantity variables

Input: Takes quantity inputs from user

Calculation: Computes total = (Espresso Qty × Price) + (Latte Qty × Price) + (Cappuccino Qty × Price)

Output: Displays the final total bill
## Learning Objectives
This program demonstrates:

Pointer declarations and assignments

Pointer dereferencing

Basic arithmetic operations with pointers

User input handling

Variable memory addressing

## Notes
Prices are fixed in the code

Program uses integer arithmetic for calculations

Error handling for invalid input is not implemented in this basic version


---
---
---

# PROJECT 02...

#  secret code machine

this project is a simple c++ program that generates a secret code for a spy agency.  
the code is calculated by multiplying all numbers from the given input down to 1 (just like factorial).  

---

# features
- multiplies numbers from n down to 1
- uses a function pointer instead of calling the function directly
- handles base case: if input is 0 → returns 1
- prints the result in a user-friendly format

---

## how it works
1. the agent enters a number  
2. the program calls the function **only via function pointer**  
3. the product is returned as the secret code    

---
---
---

# PROJECT 03...

# custom score tracker

this project is a simple c++ program that tracks players' scores in a local tournament.  
the program demonstrates how to use **malloc** for dynamic memory allocation in c++.  

---

## features
- asks the user how many players are participating
- allocates memory dynamically using malloc
- takes input for each player's score
- displays the scores back to the user
- releases memory using free

---

## how it works
1. user enters the number of players  
2. memory is allocated at runtime with malloc  
3. user inputs scores for all players  
4. scores are displayed neatly  
5. memory is freed at the end  

---
---
---
# PROJECT 04...
---
# clean attendance register

this project is a c++ program that simulates an attendance register for a workshop.  
it shows how to use **calloc** for dynamic memory allocation, where all values start at zero automatically.  
this makes it perfect for keeping attendance clean: everyone begins as **absent (0)**, and then the program marks selected participants as **present (1)**.  

---

## problem statement
scenario: "clean attendance register"  

you are designing an attendance register for a workshop. the program should:  
1. ask the user for the number of participants.  
2. dynamically allocate memory for their attendance status (1 = present, 0 = absent).  
3. initially, all participants should be marked absent by default.  
4. allow the user to mark selected participants as present.  
5. display the final attendance list at the end.  

hint to students: the attendance must be clean (all zeros) before marking anyone present, so **calloc** is used instead of malloc.  

---

## features
- asks the user for the total number of participants  
- uses **calloc** to allocate memory dynamically  
- calloc ensures all values are initialized to `0` (absent)  
- user can mark specific participants as `1` (present)  
- program displays a neat attendance register at the end  
- memory is freed properly to avoid leaks  

---

## concept explanation
- **why calloc?**  
  - `malloc` only allocates memory but does not initialize it.  
  - `calloc` allocates memory **and** sets all values to `0`.  
  - since "0 = absent" is required at the start, calloc is the best choice.  

- **attendance logic**  
  - each participant has an index in the array.  
  - if the value is `0` → absent.  
  - if the value is `1` → present.  
  - the user marks present participants by entering their numbers.  

---





