#include<iostream>
using namespace std;

int stk[100], top = -1;

void push(int val){
    if(top >= 99){
        cout<<"overflow"<<endl;
        return;
    }
    
    stk[++top] = val;
}

void pop(){
    if(top == -1){
        cout<<"underflow"<<endl;
        return;
    }
    
    cout<<"popped element: "<<stk[top]<<endl;
    top--;
}

void display(){
    if(top == -1){
        cout<<"underflow"<<endl;
        return;
    }
    
    int ptr = 0;
    while(ptr <= top){
        cout<<stk[ptr]<<" ";
        ptr++;
    }
    
    cout<<endl;
}

int main(){
    int ch, val;
    do{
        cout<<"1. push into stack"<<endl;
        cout<<"2. pop from stack"<<endl;
        cout<<"3. display stack"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"enter choice: ";
        cin>>ch;
        
        switch(ch){
            case 1:
                cout<<"enter value: ";
                cin>>val;
                push(val);
                break;
                
            case 2:
                pop();
                break;
            
            case 3:
                display();
                break;
            
            case 0:
                exit(4);
            
            default:
                cout<<"invalid"<<endl;
        }
    }while(ch != 0);
    
    return 0;
}
