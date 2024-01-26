#include<iostream>
using namespace std;

struct node{
    int val;
    struct node *next;
};
typedef struct node snode; 
snode *front = NULL;
snode *rear = NULL;

snode * create(){
    snode *newnode = (snode *)malloc(sizeof(snode));
    cout<<"enter the value: ";
    cin>>newnode->val;
    newnode->next = NULL;
    
    return newnode;
}

void enqueue(){
    snode *newnode = create();
    if(rear == NULL){
        front = newnode;
        rear = newnode;
        rear->next = front;
        return;
    }
    
    newnode->next = front;
    rear->next = newnode;
    rear = newnode;
}

void dequeue(){
    if((front == NULL) && (rear == NULL)){
        cout<<"queue underflow"<<endl;
        return;
    }
    
    snode *temp = front;
    front = front->next;
    rear->next = front;
    cout<<"deleted value: "<<temp->val<<endl;
    free(temp);
    if(front == rear)
        front = rear = NULL;
}

void display(){
    if(front == NULL){
        cout<<"queue underflow"<<endl;
        return;
    }
    
    snode *temp = front;
    do{
        cout<<temp->val<<" ";
        temp = temp->next;
    }while(temp != front);
    cout<<endl;
}

int main(){
    int ch;
    do{
        cout<<"1. enqueue into queue"<<endl;
        cout<<"2. dequeue into queue"<<endl;
        cout<<"3. display queue"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"enter the choice"<<endl;
        cin>>ch;
        
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                exit(1);
        }
    }while(ch != 0);
    
    return 0;
}
