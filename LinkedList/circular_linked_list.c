// ii. Delete a node (first node, last node, node after a given node) Display all the nodes

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at end to create the linked list
void insertEnd()
{
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

// Delete first node
void deleteFirst()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted node: %d\n", temp->data);

    free(temp);
}

// Delete last node
void deleteLast()
{
    struct Node *temp, *prev;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if(head->next == NULL)
    {
        printf("Deleted node: %d\n", head->data);

        free(head);
        head = NULL;

        return;
    }

    temp = head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    printf("Deleted node: %d\n", temp->data);

    free(temp);
}

// Delete node after a given node
void deleteAfter()
{
    int key;
    struct Node *temp, *deleteNode;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter node value after which to delete: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Given node not found.\n");
        return;
    }

    if(temp->next == NULL)
    {
        printf("No node exists after the given node.\n");
        return;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    printf("Deleted node: %d\n", deleteNode->data);

    free(deleteNode);
}

// Display all nodes
void display()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert Node\n");
        printf("2. Delete First Node\n");
        printf("3. Delete Last Node\n");
        printf("4. Delete Node After Given Node\n");
        printf("5. Display All Nodes\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertEnd();
                break;

            case 2:
                deleteFirst();
                break;

            case 3:
                deleteLast();
                break;

            case 4:
                deleteAfter();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}


