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



