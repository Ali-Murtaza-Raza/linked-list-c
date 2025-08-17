// Simple Linked List in C
// Features: insertion at tail, traversal (print), memory cleanup
// Author: Ali Murtaza
// Compile: gcc linkedlist.c -o linkedlist
// Run: ./linkedlist

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node
{
    int value;
    struct node *next;
} node;

// Prototyping
int insert_node(node **head, node **tail, int value);
void delete_node(node **head, node **tail, int value);
void search_list(node *head, int value);
void print_list(node *head);
void free_list(node **head, node **tail);

int main(void)
{
    // head pointer that points to the start of the list
    node *head = NULL;
    node *tail = NULL;
    int input;

    printf("Enter 0 to end the insertion.\n");

    while (1)
    {
        printf("Enter a number: ");
        if (scanf("%i", &input) != 1)
        {
            printf("Invalid input.\n");
            free_list(&head, &tail);
            return 1;
        }

        if (input == 0)
            break;

        if (insert_node(&head, &tail, input) != 0)
        {
            printf("Memory allocation failed.\n");
            free_list(&head, &tail);
            return 1;
        }
    }


    int choice;
    do
    {
        printf("Choose from the following operations: \n");
        printf("1 -> Add more elements\n");
        printf("2 -> Delete a list item\n");
        printf("3 -> Search for a item\n");
        printf("4 -> Clear the list\n");
        printf("0 -> End the program and print the list\n");
        if (scanf("%i", &choice) != 1)
        {
            printf("Invalid input.\n");
            free_list(&head, &tail);
            return 1;
        }

        switch (choice)
        {
            case 1: // Add more elements
            printf("Enter 0 to end the insertion.\n");
            while (1)
            {
                printf("Enter a number: ");
                if (scanf("%i", &input) != 1)
                {
                    printf("Invalid input.\n");
                    free_list(&head, &tail);
                    return 1;
                }

                if (input == 0)
                {
                    break;
                }

                if (insert_node(&head, &tail, input) != 0)
                {
                    printf("Memory allocation failed.\n");
                    free_list(&head, &tail);
                    return 1;
                }
            }
            print_list(head);
            break;

            case 2: // Delete a list item
            printf("Enter the number to be deleted: ");
            if (scanf("%i", &input) != 1)
            {
                printf("Invalid input.\n");
                free_list(&head, &tail);
                return 1;
            }
            delete_node(&head, &tail, input);
            print_list(head);
            break;

            case 3: // Search for a item
            printf("Enter the number to be searched: ");
            if (scanf("%i", &input) != 1)
            {
                printf("Invalid input.\n");
                free_list(&head, &tail);
                return 1;
            }
            search_list(head, input);
            break;

            case 4: // Clear the list
            free_list(&head, &tail);
            printf("List has been cleared!\n");
            break;

            case 0: // End and print list
            printf("Final linked list:\n");
            print_list(head);
            choice = 0;
            break;

            default:
            printf("Invalid choice, try again. \n");
        }
    } while (choice != 0);


    free_list(&head, &tail);
    return 0;
}

// inserts node at the tail
int insert_node(node **head, node **tail, int value)
{
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        return 1;
    }

    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    return 0;
}

// deleting list items
void delete_node(node **head, node **tail, int value)
{
    for (node *current = *head, *prev = NULL; current != NULL; current = current->next)
    {
        if (current->value == value)
        {
            // Case 1: deleting the head
            if (prev == NULL)
            {
                *head = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            // Case 2: deleting the tail
            if (current->next == NULL)
            {
                *tail = prev;
            }

            free(current);
            printf("Deleted node with value %d\n", value);
            return;
        }
        prev = current;
    }

    printf("Value %d not found!\n", value);
}

void search_list(node *head, int value)
{
    for (node *current = head; current != NULL; current = current->next)
    {
        if (current->value == value)
        {
            printf("Value %d found in the list!\n", value);
            return;
        }
    }
    printf("Value %d not found!\n", value);
}

// outputting the linked list
void print_list(node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    for (node *current = head; current != NULL; current = current->next)
    {
        printf("%d -> ", current->value);
    }
    printf("NULL\n");
}

// frees all nodes
void free_list(node **head, node **tail)
{
    for (node *current = *head, *tmp = NULL; current != NULL; current = tmp)
    {
        tmp = current->next;
        free(current);
    }
    *head = NULL;
    *tail = NULL;
}
