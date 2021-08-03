#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class circular
{
    private:
    Node* head;
    Node* tail;
    int count = 0;
    public:
    circular()
    {
        head = NULL;
        tail = NULL;
    }

    void insertend(int new_data)
    {
        if(head == NULL)
        {
            Node* new_node = new Node();
            new_node -> data == new_data;
            new_node -> next = new_node;
            new_node -> prev = new_node;
            head = new_node;
            return;
        }

        Node* tail = head -> prev;
        Node* new_node = new Node();
        new_node -> data = new_data;

        new_node -> next = head;
        head -> prev = new_node;

        new_node -> prev = tail;
        tail -> next = new_node;

        tail = new_node;
        count++;
        return;

    }

    void insertbetween(int new_data, int pos)
    {
         pos = pos % count;
         while(pos)
         {
        
         }
    }

    void deletebetween(int pos)
    {
         pos = pos % count;
         if(head == NULL)
         {
             cout<<"invalid"<<endl;
             return;
         }
         auto temp = head;
         if(pos == 0)
         {
             head = temp -> next;
             free(temp);
             return;
         }
         
         while(pos-1)
         {
             temp = temp -> next;
             pos--;
         }


    }

    void printposele(int pos)
    {
        pos = pos % count;
        if(head == NULL)
        {
            cout<<"invalid"<<endl;
            return;
        }

        auto temp = head;
        while(pos)
        {
            cout<< temp -> data<<endl;
            return;
            pos--;
        }
        return;
    }

    void printlist()
    {
        if(head ==NULL)
        {
            cout<<"invalid"<<endl;
            return;
        }
        while(head != tail)
        {
            cout<< head -> data<<" ";
            head = head -> next;
        }
        cout<< head -> prev<<endl;
        return;
    }
    
};

int main()
{
    int q,pos,data,operation;
    circular c1;
    cin>>q;
    while(q)
    {
        cin>>operation;
        switch(operation)
        {
            case 1:
            cin>>data;
            c1.insertend(data);
            break;

            case 2:
            cin>>data>>pos;
            c1.insertbetween(data,pos);
            break;

            case 3:
            cin>>pos;
            c1.deletebetween(pos);
            break;

            case 4:
            cin>>pos;
            c1.printposele(pos);
            break;

            case 5:
            c1.printlist();
            break;

            default:
            cout<<"invalid"<<endl;;
            break;
        }
    }
}