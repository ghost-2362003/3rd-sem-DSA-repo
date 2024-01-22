#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int val;
    struct node *next;
};
typedef struct node tnode;
tnode *front = NULL;
tnode *rear = NULL;

tnode * create(int key){
    tnode *newnode = (tnode *)malloc(sizeof(tnode));
    
    newnode->val = key;
    newnode->next = NULL;
    
    return newnode;
}

void enqueue(int key){
    tnode *node = create(key);
    if(rear == NULL){
        rear = node;
        front = node;
        return;
    }
    
    rear->next = node;
    rear = node;
}

void dequeue(){
    if(front == NULL){
        cout<<"empty queue"<<endl;
        return;
    }
    
    tnode *temp = front;
    front = temp->next;
    cout<<"deleted value: "<<temp->val<<endl;
    if(front == NULL)
        rear = NULL;
    free(temp);
}

void display(tnode *front){
    if(rear == NULL){
        cout<<"empty queue"<<endl;
        return;
    }
    
    tnode *temp = front;
    while(temp != NULL){
         cout<<temp->val<<" ";
         temp = temp->next;
    }
    
}

int main(){
    int ch, val;
    do{
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"enter the node value: ";
                cin>>val;
                enqueue(val);
                break;
            
            case 2:
                dequeue();
                break;
            
            case 3:
                display(front);
                break;
            
            case 0:
                exit(1);
        }
    }while(ch != 0);
    
    return 0;
}
