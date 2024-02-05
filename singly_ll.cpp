#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node *next;
};
typedef struct Node node; 
node *head = NULL;

node * create_node(int val){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->val = val;
    newnode->next = NULL;
    
    return newnode;
}

void addBeg(int val){
    node *newnode = create_node(val);
    
    if(head == NULL){
        head = newnode;
        return;
    }
    
    newnode->next = head;
    head = newnode;
}

void addLast(int val){
    node *newnode = create_node(val);
    
    if(head == NULL){
        cout<<"list does not exist"<<endl;
        return;
    }
    
    node *ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = newnode;
}

void deleteBeg(){
    if(head == NULL){
        cout<<"list does not exist"<<endl;
        return;
    }
    
    node *ptr = head;
    head = head->next;
    cout<<"deleted: "<<ptr->val<<endl;
    free(ptr);
}

void deleteEnd(){
     if(head == NULL){
        cout<<"list does not exist"<<endl;
        return;
    }
    
    node *ptr1 = head;
    node *ptr2 = head;
    while(ptr1->next != NULL){
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    
    if(head->next == NULL){
        cout<<"deleted element: "<<head->val<<endl;
        free(ptr1);
        head = NULL;
        return;
    }
    ptr2->next = ptr1->next;
    cout<<"deleted: "<<ptr1->val<<endl;
    free(ptr1);
}

void display(){
    if(head == NULL){
        cout<<"list does not exist"<<endl;
        return;
    }
    
    node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->val<<"->";
        ptr = ptr->next;
    }
    
    cout<<"NULL"<<endl;
}

int main() {
    int val, ch;
    do{
        cout<<"1. add at first"<<endl;
        cout<<"2. add at end"<<endl;
        cout<<"3. delete from first"<<endl;
        cout<<"4. delete from end"<<endl;
        cout<<"5. display"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"enter choice: ";
        cin>>ch;
        
        switch(ch){
            case 1:
                cout<<"enter the value of node: ";
                cin>>val;
                addBeg(val);
                break;
                
            case 2:
                cout<<"enter the value of node: ";
                cin>>val;
                addLast(val);
                break;
                
            case 3:
                deleteBeg();
                break;
            
            case 4:
                deleteEnd();
                break;
            
            case 5:
                display();
                break;
            
            case 0:
                exit(1);
            
            default:
                cout<<"invalid";
        }
    }while(ch != 0);
    
    return 0;
}
