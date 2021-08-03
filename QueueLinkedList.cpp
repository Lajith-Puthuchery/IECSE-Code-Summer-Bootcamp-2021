#include <iostream>
#include <bits/stdc++.h>



struct Node {
    int data;
    Node* next;
};

class queue
{
    private:
    Node* front;
    Node* rear;

    public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void printqueue()
    {
        auto temp = front;
        if(front ==NULL)
        {
            std::cout<<"empty"<<std::endl;
            return;
        }
        else
        {
            std::cout<< temp -> data<<std::endl;
            return;
        }
    }

    void enqueue(int new_data)
    {
        Node* new_node = new Node();
        new_node -> data = new_data;
        new_node -> next = NULL;
        if(front==NULL)
        {
            front = rear = new_node;
        }
        else
        {
            rear -> next = new_node;
            rear = new_node;
        }
    }

    void dequeue()
    {
        auto temp = front;
        if(front == NULL)
        {
            std::cout<<"empty"<<std::endl;
            return;
        }
        else
        {
            auto temp = front;
            front = front -> next;
            temp = NULL;

        }
    }
};

int main()
{
    queue q1;
    int q,operation,data;
    std::cin>>q;
    while(q)
    {
        std::cin>>operation;
        switch(operation)
        {
            case 1:
            std::cin>>data;
            q1.enqueue(data);
            break;

            case 2:
            q1.dequeue();
            break;

            case 3:
            q1.printqueue();
            break;

            default:
            break;
        }
        q--;
    }

}