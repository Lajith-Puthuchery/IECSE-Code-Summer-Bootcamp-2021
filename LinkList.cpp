#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class linkedlist
{
    private:
    Node *head;
    public:
    linkedlist()
    {
        head = NULL;
    }
    void addNode(int data)
    {
        Node* node = new Node();
    }
};