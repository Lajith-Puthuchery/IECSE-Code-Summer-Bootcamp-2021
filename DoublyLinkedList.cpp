#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class linkedlist
{
    private:
    Node* head;
    public:
    linkedlist()
    {
        head = NULL;
    }

    void printlinklist()
    {
        if(head == NULL)
        {
            cout<<"empty"<<endl;
            return;
        }

        auto temp = head;
        while(temp != NULL)
        {
            cout<< temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    void sort()
    {
        if(head == NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        if(head -> next == NULL)
        {
            return;
        }
        auto current = head;
        auto index = head -> next;
        while(current -> next != NULL)
        {
            index = current -> next;
            while(index != NULL)
            {
                if(current -> data > index -> data)
                {
                    auto temp = current -> data;
                    current -> data = index -> data;
                    index -> data = temp;
                }
                index = index -> next;
            }
            current = current -> next;
            
        }
        return;
    }

    void reverse()
    {
        if(head == NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        Node* temp = NULL;
        auto current = head;

        while(current != NULL)
        {
            temp = current -> prev;
            current -> prev = current -> next;
            current -> next = temp;
            current = current -> prev;
        }
        if(temp != NULL)
        {
            head = temp -> prev;
        }
    }

    void insertend(int new_data)
    {
        Node* new_node = new Node();
        new_node -> data = new_data;
        new_node -> next = NULL;

        if(!head)
        {
            head = new_node;
            new_node -> prev = NULL;
            return;
        }
        else
        {
            auto temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = new_node;
            new_node -> prev = temp;
        }
        return;

    }

    void deleteend()
    {
        auto temp = head;
        if ( head == NULL)
        {
            cout<<"empty"<<endl;
            return;
        }
        if(temp -> next)
        {
            while(temp -> next -> next)
            {
                temp = temp -> next;
            }
        }
        else
        {
            head = NULL;
            temp -> prev = NULL;
        }
        temp -> next = NULL;
    }
};

int main()
{
    linkedlist l1;
    int q,x,data; 
    
    cin>>q;
    while(q)
    {
        cin>>x;
        switch (x)
        {
        case 1:
            cin>>data;
            l1.insertend(data);
            break;
        
        case 2:
            l1.deleteend();
            break;

        case 3:
            l1.sort();
            break;

        case 4:
            l1.reverse();
            break;

        case 5:
            l1.printlinklist();
            break;
        default:
            break;
        }
        q--;
    }
    return 0;
}