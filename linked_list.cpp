#include<iostream>
#include<cstdio>
using namespace std;


struct Node{
    int data;
    Node* next;
};

Node* head = NULL;    // head should be global


void insert_last(int data)
{
    //creating the new node
    Node* inserting_node = new Node();
    inserting_node->data = data;
    inserting_node->next = NULL;

    //if list is empty
    if(head == NULL)
    {
        head = inserting_node;
    }
    else
    {
        // take head value to temp_node. as we don't want to loose head node value.
        Node* temp_node = head;
        while(temp_node->next != NULL)      // this loop run to the last position of the list
        {
            temp_node = temp_node->next;    // change the temp_node to the next node of the linked list
        }
        temp_node->next = inserting_node;   // change the link value of the last node to address of new inserting_node
    }
}

void insert_begining(int data)
{
    //creating the inserting node
    Node* inserting_node = new Node();
    inserting_node->data = data;
    inserting_node->next = NULL;

    //insert the new node to first position
    inserting_node->next = head;
    head = inserting_node;
}




void print_linked_list()
{
    Node* temp_node = head;
    while(temp_node != NULL)
    {
        cout<< temp_node->data;
        cout << "  ";
        temp_node = temp_node->next;
    }
    cout << endl;
}


int main()
{
    return 0;
}