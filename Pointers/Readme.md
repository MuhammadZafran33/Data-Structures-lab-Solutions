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
