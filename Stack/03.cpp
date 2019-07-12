// Implement a Stack using Queue Data Structure
#include<iostream>
#include<cstdlib>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *headQ1 = NULL;
Node *tailQ1 = NULL;
Node *headQ2 = NULL;
Node *tailQ2 = NULL;

void enqueueQ1(int elem)
{
    Node *newNode = new Node;
    newNode->data = elem;
    newNode->next = NULL;
    if (tailQ1 == NULL)
    {
        // If there are no elements in the Queue
        headQ1 = newNode;
        tailQ1 = newNode;
    }
    else
    {
        tailQ1->next = newNode;
        tailQ1 = newNode;
    }
}

int dequeueQ1()
{
    Node *temp = headQ1;
    if (headQ1 == tailQ1 && headQ1 == NULL)
    {
        // if No elements in the Queue
        cout << "No Elements in the Queue";
    }
    else if (headQ1 == tailQ1 && headQ1 != NULL)
    {
        // If only 1 element in the queue
        headQ1 = NULL;
        tailQ1 = NULL;
    }
    else
    {
        headQ1 = headQ1->next;
    }
    return temp->data;
    free(temp);
}

void enqueueQ2(int elem)
{
    Node *newNode = new Node;
    newNode->data = elem;
    newNode->next = NULL;
    if (tailQ2 == NULL)
    {
        // If there are no elements in the Queue
        headQ2 = newNode;
        tailQ2 = newNode;
    }
    else
    {
        tailQ2->next = newNode;
        tailQ2 = newNode;
    }
}
/* 
void dequeueQ2()
{
    Node *temp = headQ2;
    if (headQ2 == tailQ2 && headQ2 == NULL)
    {
        // if No elements in the Queue
        cout << "No Elements in the Queue";
    }
    else if (headQ2 == tailQ2 && headQ2 != NULL)
    {
        // If only 1 element in the queue
        headQ2 = NULL;
        tailQ2 = NULL;
        free(temp);
    }
    else
    {
        headQ2 = headQ2->next;
        free(temp);
    }
}
*/

int main()
{
    int n;
    cout << "Enter the number of elements you want to Push in the stack: ";
    cin >> n;
    cout << "Enter the elements: ";
    int elem;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        enqueueQ1(elem);
    }
    while (headQ1 != NULL)
    {
        while (headQ1 != tailQ1)
        {
            enqueueQ2(dequeueQ1());
        }
        cout << dequeueQ1() << " ";
        Node *temp1 = headQ1;
        Node *temp2 = tailQ1;
        headQ1 = headQ2;
        tailQ1 = tailQ2;
        headQ2 = temp1;
        tailQ2 = temp2;
    }
}