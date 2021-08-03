#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};


class linkedlist
{
    private:
        int count = 0;
        Node* head;
        Node* tail;
    public:
        linkedlist()
        {
            head = NULL;
        }

        Node* newNode(int key)
{
        Node* temp = new Node;
        temp->data = key;
        temp->next = NULL;
        return temp;
}
 

        void insertback(int new_data)
        {
            Node* new_node = new Node();
            new_node -> data = new_data;
            new_node -> next = NULL;

            if(head == NULL)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                tail -> next = new_node;
                tail = new_node;
            }
            count++;
        }

        void printlinklist()
        {
            Node* temp = head;
            while(temp != NULL)
            {
                cout<< temp -> data <<" ";
                temp = temp -> next;
            }
            cout<<endl;
        }

        void rearrange()
        {
             Node* slow = head;
             Node* fast = slow -> next;
             while(fast && fast -> next)
             {
                 slow = slow -> next;
                 fast = fast -> next -> next;
             }

             Node* head1 = head;
             Node* head2 = slow -> next;
             slow -> next = NULL;

             reverselist(head2);

             head = newNode(0);

             Node* curr = head;
             while( head1 || head2)
             {
                 if(head1)
                 {
                     curr -> next = head1;
                     curr = curr -> next;
                     head1 = head1 -> next;
                 }

                 if(head2)
                 {
                     curr -> next = head2;
                     curr = curr -> next;
                     head2 = head2 -> next;
                 }

             head = head -> next;
             }
        }

        void reverselist(Node* head)
        {
            Node* prev = NULL;
            Node* curr = head;
            Node* next;
            
            while(curr)
            {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
        }
};

int main()
{
    int q, x, data;
    linkedlist l1;
    cin>>q;
    while(q)
    {
        cin>>x;
        switch(x)
        {
            case 1:
                cin>>data;
                l1.insertback(data);
                break;

            case 2:
                l1.rearrange();
                break;

            case 3:
                l1.printlinklist();
                break;

            default:
                break;
        }
        q--;
    }
}