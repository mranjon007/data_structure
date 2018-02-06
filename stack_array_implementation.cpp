#include<cstdio>
#include<iostream>
using namespace std;

// this stack can only store 5 elements
int stack_arr[5];
int top = -1;


void push(int val)
{
    if(top == 4)
    {
        cout << "the stack is full" << endl;
        return;
    }
    top += 1;
    stack_arr[top] = val;
}


void pop()
{
    if(top == -1)
    {
        cout<< "stack is empty" << endl;
        return;
    }
    top -= 1;
}


int Top()
{
    return stack_arr[top];
}


void print_stack()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack_arr[i];
        cout << " ";
    }
    cout << endl;
}

int main()
{
    pop();
    push(1);
    push(3);
    push(5);
    push(7);
    push(9);
    print_stack();
    push(11);
    push(13);
    pop();
    print_stack();

    return 0;
}