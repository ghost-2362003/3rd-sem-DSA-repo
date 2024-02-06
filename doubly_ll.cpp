#include<iostream>
using namespace std;

struct Node{
    int val;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;
node *head = NULL;

node * create_node(int val){
    node *newnode = (node *)malloc(sizeof(node));
    
    newnode->val = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    
    return newnode;
}

void addBeg(int val){
    node *newnode = create_node(val);
    if(head == NULL){
        head = newnode;
        head->next = NULL;
        head->prev = NULL;
        return;
    }
    
    newnode->next = head;
    head->prev = newnode;
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
    newnode->prev = ptr;
    newnode->next = NULL;
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

void deleteLast(){
    if(head == NULL){
        cout<<"list does not exist"<<endl;
        return;
    }
    
    else if(head->next == NULL){
        cout<<"deleted: "<<head->val;
        head = NULL;
        return;
    }
    
    node *ptr = head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->prev->next = ptr->next;
    ptr->prev = NULL;
    cout<<"deleted: "<<ptr->val<<endl;
    free(ptr);
}

void displayhead(){
     if(head == NULL){
        cout<<"list does not exist"<<endl;
        return;
    }
    
    node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    
    cout<<"NULL"<<endl;
}

void displaytail(){
     if(head == NULL){
        cout<<"list does not exist"<<endl;
        return;
    }
    
    node *ptr = head;
     while(ptr->next != NULL)
        ptr = ptr->next;
    
     while(ptr != NULL){
        cout<<ptr->val<<" ";
        ptr = ptr->prev;
    }
    
    cout<<endl;
}

int main(){
    int ch, val;
    do{
        cout<<"1. insert at begin"<<endl;
        cout<<"2. insert at end"<<endl;
        cout<<"3. delete from begin"<<endl;
        cout<<"4. delete from end"<<endl;
        cout<<"5. traverse from head"<<endl;
        cout<<"6. traverse from end"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"enter choice: ";
        cin>>ch;
        
        switch(ch){
            case 1:
                cout<<"enter the value: ";
                cin>>val;
                addBeg(val);
                break;
            case 2:
                cout<<"enter the value: ";
                cin>>val;
                addLast(val);
                break;
            case 3:
                deleteBeg();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                displayhead();
                break;
            case 6:
                displaytail();
                break;
            case 0:
                exit(1);
            default:
                cout<<"invalid"<<endl;
        }
    }while(ch != 0);
    
    return 0;
}
