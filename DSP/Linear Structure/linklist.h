#ifndef LINKLIST_H
#define LINKLIST_H

struct Node
{
    int data;
    Node *next;
};
Node* creatList();
void printList(Node *list);
void makeEmpty(Node *list);
bool insert(Node *list, int position, int data);
void remove(Node *list, int data);
bool find(Node *list, int data);
int findKth(Node *list,int position);

#endif // LINKLIST_H
