#include <iostream>
#include <vector>

using namespace std;

struct  Node
    {
        int data;
        Node* next;
    };

class linkedlist
{
    private:
    Node* head;
    public:
    linkedlist()
    {
        head=NULL;
    }
    void printlinklist()
{
    if(head == NULL)
    {
        cout<<"empty"<<endl;
        return;
    }
    auto ptrnode = head;
    while(ptrnode != NULL)
    {
        cout<< ptrnode -> data<<" ";
        ptrnode = ptrnode -> next;
    }
    cout<<endl;
}

    void pushstart(int new_data)
{
    Node* new_node = new Node();
    new_node -> data = new_data;
    new_node -> next = head;
    head = new_node;
}

    void pushend(int new_data)
{
    Node* new_node = new Node();
    new_node -> data = new_data;
    new_node -> next = NULL;

    if(!head)
    {
        head = new_node;
        return;
    }
    else
    {
        Node* temp = head;
        while(temp -> next != NULL)
        {
            temp = temp ->next;
        }
        temp -> next = new_node;
    }
     return;
}
 
     void pullend()
     {
        auto temp = head;
        if (head == NULL)
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
        }
        temp -> next = NULL;
        return;
        
        
     }

     void pullstart()
     {
       auto temp = head;
       if(head == NULL)
       {
           cout<<"empty"<<endl;
           return;
       }
       head = temp -> next;
       return;
     }

};



int main()
{
    linkedlist l1;
    int n,operation,data; 
    
    cin>>n;
    while(n)
    {
        cin>>operation;
        switch (operation)
        {
        case 1:
            cin>>data;
            l1.pushend(data);
            break;
        
        case 2:
            cin>>data;
            l1.pushstart(data);
            break;

        case 3:
            l1.pullend();
            break;

        case 4:
            l1.pullstart();
            break;

        case 5:
            l1.printlinklist();
            break;
        default:
            break;
        }
        n--;
    }
    return 0;
}