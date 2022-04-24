#include<iostream>
using namespace std;

struct LinkedList
{
    int data;
    struct Linkedlist* next;
};

Linkedlist createTailNode(LinkedList head, int data){
    LinkedList* node = NULL;
    LinkedList* temp;
    node = new LinkedList();
    node->data = data;
    if(head == NULL){
        head = node;
    }
    else{
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node; 
    }
    return head;
}

LinkedList createHeadNode(LinkedList head, int data){
    LinkedList* node;
    node = new Linkedlist();
    node->data = data;
    if(head == NULL){
        head = node;
    }
    node->next = head;
    head = node;
    return head;
}

LinkedList createMidleNode(LinkedList head, int pos, int data){
    LinkedList* node;
    node = new LinkedList();
    node->data = data;
    LinkedList* temp = head;
    int k=0;
    while ( k!=pos && head != NULL)
    {
        temp = temp->next;k++;
    }
    if(k!=pos){
        cout<<"Can not find position"<<endl;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}

LinkedList DelHead(LinkedList head){
    if(head == NULL){
        cout<<"Linked list is not exist!"<<endl;
    }
    else 
    {
        head = head->next;
    }
    return head;
}

LinkedList DelMidle(LinkedList head, int pos){
    LinkedList* temp;
    temp = head;
    int k = 0;
    while (temp!=NULL && k!=(pos-1))
    {
        temp = temp->next;k++;
    }
    if(k!=pos){
        cout<<"Can not find the position!"<<endl;
    }
    temp->next = temp->next->next;
    return head;
}

LinkedList DelTail(LinkedList head){
    LinkedList* temp;
    temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}


int main(){

}