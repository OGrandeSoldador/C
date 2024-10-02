//
// Created by marco on 22/09/2024.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Definition of a Node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new Node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int value)
{
    // Create a new node with the given value
    struct Node* new_node = newNode(value);

    // If the list is empty, make the new node the head
    if (head == NULL)
        return new_node;

    // Traverse the list until the last node is reached
    struct Node* curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    // Link the new node to the current last node
    curr->next = new_node;

    return head;
}

// Função para imprimir a lista ligada
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverseLinkedList(struct Node* head)
{
    // Start from the head of the linked list
    struct Node* current = head;

    // Traverse the linked list until reaching the end (NULL)
    while (current != NULL) {

        printf("%d ", current->data);

        // Move to the next node
        current = current->next;
    }

    printf("\n");
}

// Function to search for a value in the Linked List
bool search_linked_list(struct Node* head,int target)
{
    // Start from the head of the linked list
    struct Node* current = head;

    // Traverse the linked list until reaching the end (NULL)
    while (current != NULL)
    {
        if (current->data != target)
            // Move to the next node, if target is not found.
            current = current->next;
        else
            //Otherwise, if a match is found, return true.
            return true;
    }
    //If the of the list is reached without finding a match, return false.
    return false;
}

int findlength(struct Node* head)
{
    int length = 0;

    // Start from the head of the linked list
    struct Node* current = head;

    while (current != NULL) {

        //Increment length for each node.
        length++;

        // Move to the next node
        current = current->next;
    }
    return length;
}

// Function to insert a new node at the beginning of the linked list
struct Node* insert_at_beginning(struct Node* head,int value)
{
    // Create a new node with the given value
    struct Node* new_node = newNode(value);

    // Set the next pointer of the new node to the current head
    new_node->next = head;

    // Move the head to point to the new node
    head = new_node;

    // Return the new head of the linked list
    return head;
}

struct Node* insert_at_spec_posi(struct Node* head,int pos,int data)
{
    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }

    if (pos == 1)
    {
        struct Node* temp = newNode(data);
        temp->next = head;
        return temp;
    }

    struct Node* prev = head;
    int count = 1;
    while (count < pos - 1 && prev != NULL)
    {
        prev = prev->next;
        count++;
    }

    if (prev == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    struct Node* temp = newNode(data);
    temp->next = prev->next;
    prev->next = temp;

    return head;
}

struct Node* remove_first_node(struct Node* head)
{
    if (head == NULL)
        return NULL;

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* remove_last_node(struct Node* head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* second_last = head;
    while(second_last->next->next != NULL)
        second_last = second_last->next;

    free(second_last->next);
    second_last->next = NULL;
    return head;
}

struct Node* remove_at_spec_posi(struct Node* head,int posi)
{
    if (head == NULL || posi < 1)
        return head;

    if (posi == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    for (int i = 1; i < posi - 1 && curr != NULL;i++)
        curr = curr->next;

    if (curr == NULL || curr->next == NULL)
        return head;

    struct Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

struct Node* remove_from_key(struct Node* head,int key)
{
    if (head == NULL)
        return NULL;

    if (head->data == key)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int x = 0;
    struct Node* temp = head;
    while (x == 0)
    {
        if (temp->next == NULL)
        {
            printf("it's not valid key\n");
            return head;
        }

        struct Node* curr= temp;
        temp = temp->next;

        if (temp->data == key)
        {
            curr->next = curr->next->next;
            x = 1;
        }
    }

    free(temp);
    return head;
}

int main(void)
{
    struct Node* Head = NULL;
    Head = insertAtEnd(Head,1);
    Head = insertAtEnd(Head,2);
    Head = insertAtEnd(Head,3);
    Head = insertAtEnd(Head,4);
    Head = insertAtEnd(Head,5);
   /* printList(Head);
    search_linked_list(Head,1);
    Head = insert_at_beginning(Head,0);
    printList(Head);
    Head = insert_at_spec_posi(Head ,5,4);
    printList(Head);
    Head = remove_first_node(Head);
    printList(Head);
    Head = remove_last_node(Head);
    printList(Head);
    Head = remove_at_spec_posi(Head,2);*/
    printList(Head);
    Head = remove_from_key(Head,5);
    printList(Head);

    free(Head);
    return 0;
}
