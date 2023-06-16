#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int value){
     data=value;
     next=NULL;
    }
};

Node *reverse(Node *head)
{
    Node * prev = NULL;
    Node * current = head;
    Node * next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
Node *addUtil(Node *head)
{
    Node* res = head;
    Node *temp, *prev = NULL;
    int sum;
    int carry = 1; 
    while (head != NULL)
    {
        sum = carry + head->data;
        carry = (sum >= 10)? 1 : 0;
        sum = sum % 10;
        head->data = sum;
        temp = head;
        head = head->next;
    }
    if (carry > 0)
        temp->next = new Node(carry);
    return res;
}
Node* addOne(Node *head)
{
    head = reverse(head);
    head = addUtil(head);
    return reverse(head);
}
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout<<endl;
}
int main()
{
    Node *head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);
    cout << "old list is: ";
    printList(head);
    head = addOne(head);
    cout << "resultant linked list: ";
    printList(head);
    return 0;
}