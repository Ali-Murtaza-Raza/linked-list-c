# Linked List in C

This is a simple implementation of a **singly linked list** in C.  
The program allows the user to insert integers into a linked list until they enter **0**, at which point the list is printed and all allocated memory is freed.

---

## 🚀 Features
- Dynamically allocates memory for each new node.  
- Allows continuous input until the user enters **0**.  
- Prints the entire linked list after insertion.  
- Frees all allocated memory to prevent memory leaks.  
- Handles invalid input gracefully.

---

## 📂 Files
- `linkedlist.c` → Main source code file.  
- `README.md` → This documentation file.  

---

## 🖥️ How It Works
1. The program asks the user to enter numbers one by one.  
2. Each number (except `0`) is added as a new node at the end of the linked list.  
3. When the user enters `0`, input stops.  
4. The program prints the list of numbers in the order they were entered.  
5. Finally, it frees all the allocated memory.  

---

## 🔧 Example Usage
Enter 0 to end the insertion.
Enter a number: 5
Enter a number: 10
Enter a number: 15
Enter a number: 0
Your linked list is:
5
10
15

---

## 📌 Notes
- Entering `0` stops the input process.  
- If you enter a non-integer value, the program exits with an error message.  
- Memory management is handled properly by freeing all nodes at the end. 
