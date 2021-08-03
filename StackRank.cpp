#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 10
int size = 0;

struct stack {
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s) {
    s -> top = -1;
}

int isempty(st *s) {
    if(s->top ==-1)
    return 1;
    else 
    return 0;
}

void push(st *s, int newitem) {
    s -> top++;
    s -> items[s -> top] = newitem;
    size++;
}

void pop(st *s) {
    if(isempty(s)) {
        cout<<"empty"<<endl;
    }
    else {
        s -> top--;
    }
    size--;
}

void printStack(st *s) {
    if(s -> top ==-1)
    {
        cout<<'empty'<<endl;
    }
    else {
        for(int i=0;i<size; i++)
        cout<<s -> items[i] <<" ";
    }
    cout<<endl;
}

int main()
{
    st *s = (st *)malloc(sizeof(st));
    int n,operation,data;

    createEmptyStack(s);

    cin>>n;
    while(n--)
    {
        cin>>operation;
        switch (operation)
        {
        case 1:
            push(s, data);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            printStack(s);
            break;
        default:
            break;
        }

    }
}
