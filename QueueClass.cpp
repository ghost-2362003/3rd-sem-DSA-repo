// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Queue{
    int front, rear;
    int Q[100];
    
    public:
        Queue(){
            front  = -1;
            rear = -1;
        }
        
        void enqueue(int key){
            if(rear >= 99){
                cout<<"queue overflow"<<endl;
                return;
            }
            
            if(front == -1){
                Q[0] = key;
                rear = 0;
                front = 0;
                return;
            }
            
            Q[++rear] = key;
        }
        
        void dequeue(){
            if(front == -1 || front>rear){
                cout<<"queue underflow"<<endl;
                return;
            }
            
            cout<<"deleted element: "<<Q[front++]<<endl;
        }
        
        void display(){
            if(rear == -1 || front>rear){
                 cout<<"queue underflow"<<endl;
                return;
            }
            
            cout<<"queue element: "<<endl;
            for(int i = front; i<=rear; i++)
                cout<<Q[i]<<" ";
            
            cout<<endl;
        }
};

int main(){
    int ch;
    Queue q;
    do{
        cout<<"enter choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                int v;
                cout<<"enter element: ";
                cin>>v;
                q.enqueue(v);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 0:
                exit(1);
        }
    }while(1);
}
