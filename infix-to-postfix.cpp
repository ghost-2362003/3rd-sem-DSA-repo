// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<stdlib.h>
#include<string.h>
char stk[100];
int top = -1;

void push(int ele){
    if(top>=99){
        cout<<"stack full"<<endl;
        return;
    }
    
    stk[++top] = ele;
}

char pop(){
    if(top<0){
        cout<<"stack empty";
        return 0;
    }
    
    return stk[top--];
}

int isoperator(char a){
    if(a == '^' || a == '*' || a == '/' || a == '+' || a == '-')
        return 1;
    return 0;
}

int precedence(char a){
    switch(a){
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '-':
            return 1;
        case '+':
            return 1;
    }
    
    return 0;
}


void inf_pos(char infix[], char postfix[]){
    int i, j;
    char x, item;
    push('(');
    strcat(infix, ")");
    i = 0, j = 0;
    
    item = infix[i];
    while(item != '\0'){
        if(item == '(')
            push(item);
        else if(isdigit(item) || isalpha(item))
            postfix[j++] = item;
        else if(isoperator(item)){
            x = pop();
            while(isoperator(x) && precedence(x)>=precedence(item)){
                postfix[j++] = x;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if(item == ')'){
            x = pop();
            while(x != '('){
                postfix[j++] = x;
                x = pop();
            }
        }
        else{    
            cout<<"invalid";
            exit(1);
        }
        item = infix[++i];
    }
    if(top>0){
        cout<<"invalid";
        exit(1);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100], post[100];
    cin>>infix;
    
    inf_pos(infix,post);
    cout<<post;
    return 0;
}
