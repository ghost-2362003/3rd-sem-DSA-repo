#include<iostream>
using namespace std;

int q[6];
int front = -1, rear = -1;

int isEmpty(){
    if(front == -1)
        return 1;
    
    return 0;
}

int isFull(){
    if((front == 0 && rear == 5)||(front == rear+1))
        return 1;
    
    return 0;
}

void enqueue(int val){
    if(isFull()){
        cout<<"queue is full"<<endl;
        return;
    }
    
    else if(isEmpty()){
        front = 0;
        rear = 0;
    }
    
    else if(rear == 5)
        rear = 0;
    
    else
        rear++;
    
    q[rear] = val;
}

void dequeue(){
    if(isEmpty()){
        cout<<"underflow"<<endl;
        return;
    }
    
    cout<<"popped element: "<<q[front]<<endl;
    if(front == 5)
        front = 0;
    
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    
    else
        front++;
}

void display(){
    if(isEmpty()){
        cout<<"underflow"<<endl;
        return;
    }
    
    if(front <= rear){
        for(int i = front; i<=rear; i++)
            cout<<q[i]<<" ";
        
        cout<<endl;
    }
    
    else{
        for(int i = front; i<=5; i++)
            cout<<q[i]<<" ";
        
        for(int i = 0; i<= rear; i++)
            cout<<q[i]<<" ";
        
        cout<<endl;
    }
}

int main(){
    int ch, val;
    do{
        cout<<"1. enqueue"<<endl;
        cout<<"2. dequeue"<<endl;
        cout<<"3. display"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"enter choice"<<endl;
        cin>>ch;
        
        switch(ch){
            case 1:
                cout<<"enter the value: "<<endl;
                cin>>val;
                enqueue(val);
                break;
                
            case 2:
                dequeue();
                break;
            
            case 3:
                display();
                break;
                
            case 0:
                exit(1);
            
            default:
                cout<<"invalid"<<endl;
        }
    }while(ch != 0);
    
    return 0;
}
