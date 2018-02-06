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


//this code only works on valid position
void insert_in_a_position(int data, int position)
{
    // creating the inserting node
    Node* inserting_node = new Node();
    inserting_node->data = data;
    inserting_node->next = NULL;

    if(position == 1)
    {
        //same logic as inserting in the beginning
        inserting_node->next = head;
        head = inserting_node;
    }
    else
    {
        Node* temp_node = head;
        for(int i = 0; i < position-2; i++)       // why position-2 ?? -> in the beginning head is pointing the first position
        {                                         // and so if the position is 3 then the loop run only one iteration but reach
            temp_node = temp_node->next;          // n-1 which is second position.
        }
        inserting_node->next = temp_node->next;
        temp_node->next = inserting_node;
    }
}


void delete_in_a_position(int position)
{
    Node* temp_node = head;
    if(position == 1)
    {
        head = temp_node->next;
        //free(temp_node);
    }
    else
    {
        for(int i=0; i<position-2; i++)
        {
            temp_node = temp_node->next;
        }
        Node* deleting_node = temp_node->next;
        temp_node->next = deleting_node->next;
        //free(deleting_node)
    }
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


void print_linked_list_using_recursion(Node* current_node)
{
    if(current_node == NULL)
    {
        return;
    }
    cout<< current_node->data << " ";
    print_linked_list_using_recursion(current_node->next);
}


void reverse_linked_list()
{
    Node* previous_node = NULL;
    Node* next_node = NULL;
    Node* current_node = head;

    while(current_node!=NULL)
    {
        next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    head = previous_node;
}


// reverse list using recursion
void reverse_link_list_using_recursion(Node* temp_node)
{
    if(temp_node->next == NULL)
    {
        head = temp_node;
        return;
    }
    reverse_link_list_using_recursion(temp_node->next);
    Node* previous_node = temp_node->next;
    previous_node->next = temp_node;
    temp_node->next = NULL;
}



int main()
{
    return 0;
}