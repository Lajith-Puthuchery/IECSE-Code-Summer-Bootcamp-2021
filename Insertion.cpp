#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{   
    public :
     int data;
     Node* next;
};

void printLinkList(Node* n)
{
    while(n != NULL)
    {
    cout<< n -> data<<endl;
    n = n -> next;
    }
    cout<<endl;
}

void pushstart(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

void pushend(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    Node *last = *head_ref;
    new_node -> data = new_data;
    new_node -> next = NULL;
    
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while(last -> next != NULL)
        last -> next = new_node;

    last -> next = new_node;
    return;
    
}

int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head -> data = 1;
    head -> next = second;

    second -> data = 5;
    second -> next = third;

    third -> data = 6;
    third -> next = NULL;

   

    pushstart(&head, 3);
    pushstart(&head, 5);

    pushend(&head, 6);
    printLinkList(head);
    return 0;

}