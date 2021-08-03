#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
  int data;
  Node* next;  
};

class rotatelinkedlist
{
    private:
        Node* head, *tail;
        int count = 0;
    public:
    rotatelinkedlist()
    {
        head = NULL;
    }

    void insertback(int new_data) 
    {
        Node* new_node = new Node();
        new_node -> data = new_data;
        new_node -> next = NULL;

        if(!head)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail -> next = new_node;
            tail = tail -> next;
        }
        count++;
        return;
    }
    void printlinklist()
    {
        if(head == NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        auto temp = head;
        while(temp)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    void rotate(int k)
    {
        k = k % count;
        if(k==0 || head == NULL)
        {
            return;
        }
        Node* p1 = head;
        Node* kth = head;
        while(k)
        {
            kth = kth -> next;
            k--;
        }
        while(kth -> next)
        {
            p1 = p1 -> next;
            kth = kth -> next;
        }
        Node* temp = p1 -> next;
        p1 -> next = NULL;
        tail = p1;
        kth -> next = head;
        head = temp;
    }
};

int main()
{
    rotatelinkedlist r1;
    int n,operation,data,k;
    cin>>n;
    while(n)
    {
        cin>>operation;
        switch(operation)
        {
            case 1:
            cin>>data;
            r1.insertback(data);
            break;

            case 2:
            r1.printlinklist();
            break;

            case 3:
            cin>>k;
            r1.rotate(k);
            break;

            default:
            break;
        }
        n--;
    }
    return 0;
}
