// Simple Linked List in C
// Features: insertion at tail, traversal (print), memory cleanup
// Author: Ali Murtaza
// Compile: gcc linkedlist.c -o linkedlist
// Run: ./linkedlist

#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node
{
    int value;
    struct node *next;
} node;

// Prototyping
void print_list(node *head);
void free_list(node *head);

int main(void)
{
    // head pointer that points to the start of the list
    node *head = NULL;
    node *tail = NULL;
    int input;

    printf("Enter 0 to end the insertion.\n");
    printf("Enter a number: ");
    if (scanf("%i", &input) != 1)
    {
        printf("Invalid input.\n");
        free_list(head);
        return 1;
    }

    // End the program if 0 is entered
    if (input == 0)
    {
        return 0;
    }

    // creating the first node
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        return 1;
    }

    newNode->value = input;
    newNode->next = NULL;

    // setting the head and tail pointers
    head = newNode;
    tail = newNode;

    while (input != 0)
    {
        printf("Enter a number: ");
        if (scanf("%i", &input) != 1)
        {
            printf("Invalid input.\n");
            free_list(head);
            return 1;
        }


        if (input != 0)
        {
            // creating another node and linking
            newNode = malloc(sizeof(node));
            if (newNode == NULL)
            {
                return 1;
            }
            newNode->value = input;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Your linked list is:\n");
    print_list(head);

    free_list(head);
    return 0;
}

// outputting the linked list
void print_list(node *head)
{
    for (node *current = head; current != NULL; current = current->next)
    {
        printf("%i\n", current->value);
    }
}

// frees all nodes
void free_list(node *head)
{
    for (node *current = head, *tmp = NULL; current != NULL; current = tmp)
    {
        tmp = current->next;
        free(current);
    }
}
