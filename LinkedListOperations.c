#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(struct Node** head, int val)
{
    struct Node* n = createNode(val);
    n->next = *head;
    *head = n;
}

void insertAtEnd(struct Node** head, int val)
{
    struct Node* n = createNode(val);
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtPosition(struct Node** head, int val, int pos)
{
    struct Node* n = createNode(val);
    int i = 1;
    struct Node* temp = *head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletionAtHead(struct Node** head)
{
    if (*head == NULL)
        return;

    struct Node* r = *head;
    *head = (*head)->next;
    free(r);
}

void deletionAtEnd(struct Node** head, int val)
{
    if (*head == NULL)
        return;

    if ((*head)->data == val)
    {
        struct Node* r = *head;
        *head = (*head)->next;
        free(r);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
        return;
    struct Node* todel = temp->next;
    temp->next = temp->next->next;
    free(todel);
}

int search(struct Node* head, int key)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void display(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtHead(&head, 3);
    display(head);
    insertAtPosition(&head, 4,2);
    printf("%d\n", search(head, 2);
    deletionAtEnd(&head, 2);
    deletionAtHead(&head);
    display(head);

    return 0;
}
