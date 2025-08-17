# Linked List in C

[![Language](https://img.shields.io/badge/language-C-blue)](https://www.cprogramming.com/)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)

This is a simple implementation of a **singly linked list** in C.  
The program allows the user to insert integers into a linked list until they enter **0**, at which point the list is printed and all allocated memory is freed.

---

## 🚀 Features
- Dynamically allocates memory for each new node.  
- Insert nodes at the **tail** of the linked list.  
- Delete nodes by value (**first occurrence**).  
- Search nodes by value.  
- Clear the entire list at any time.  
- Prints the current linked list after each operation.  
- Handles invalid input gracefully.  
- Prevents memory leaks by freeing all nodes.

---

## 📂 Files
- `linkedlist.c` → Main source code file.  
- `README.md` → Documentation.    

---

## 🖥️ How It Works
1. The program asks the user to enter numbers one by one.  
2. Each number (except `0`) is added as a new node at the end of the linked list.  
3. When the user enters `0`, input stops.  
4. Users can then choose to:
   - Add more elements
   - Delete a node by value
   - Search for a node by value
   - Clear the entire list
   - Exit the program and display the final list  
5. Finally, all allocated memory is freed.  

---

## 🔧 Example Usage
Enter 0 to end the insertion.
Enter a number: 5
Enter a number: 10
Enter a number: 15
Enter a number: 0

Choose operation:
1 -> Add more elements
2 -> Delete a list item
3 -> Search for a item
4 -> Clear the list
0 -> End and print the list

Enter 2 to delete a number
Enter the number to be deleted: 10
Deleted node with value 10

Current linked list:
5 -> 15 -> NULL

---

## 📌 Notes
- Entering `0` stops the input process.  
- Deletion only removes the **first occurrence** of a value.  
- Search will indicate whether a value exists in the list.  
- Memory is freed properly at the end to prevent leaks.  
- Non-integer input causes the program to exit with an error message. 
