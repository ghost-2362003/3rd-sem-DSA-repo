#include <iostream>
using namespace std;

void addSparse(int rows, int cols, int a[][3], int b[][3], int res[][3]){
    int size1, size2;
    cout<<"enter the number of non zero elements of first matrix: ";
    cin>>size1;
    cout<<"enter the number of non zero elements of second matrix: ";
    cin>>size2;
    
    cout<<"enter the first matrix non zero values(0 index):"<<endl;
    for(int i = 1; i<=size1; i++){
        cout<<"rows: ";
        cin>>a[i][0];
        cout<<"cols: ";
        cin>>a[i][1];
        cout<<"val: ";
        cin>>a[i][2];
        cout<<endl;
    }
    
    cout<<"enter the second matrix non zero values(0 index):"<<endl;
    for(int i = 1; i<=size2; i++){
        cout<<"rows: ";
        cin>>b[i][0];
        cout<<"cols: ";
        cin>>b[i][1];
        cout<<"val: ";
        cin>>b[i][2];
        cout<<endl;
    }
    
    res[0][0] = rows;
    res[0][1] = cols;
    res[0][2] = 0;
    
    int i = 1, j = 1, k = 1;
    while(i<=size1 && j<=size2){
        if(a[i][0] == b[j][0] && a[i][1] == b[j][1]){
            res[k][0] = a[i][0];
            res[k][1] = a[i][1];
            res[k][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }
        
        else if(a[i][0] > b[j][0] || (a[i][0] == b[j][0] && a[i][1] > b[j][1])){
            res[k][0] = b[j][0];
            res[k][1] = b[j][1];
            res[k][2] = b[j][2];
            j++;
        }
        
        else if(a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])){
            res[k][0] = a[i][0];
            res[k][1] = a[i][1];
            res[k][2] = a[i][2];
            i++;
        }
        
        k++;
    }
    
    while(i<=size1){
        res[k][0] = a[i][0];
        res[k][1] = a[i][1];
        res[k][2] = a[i][2];
        i++;
        k++;
    }
    
    while(j<=size2){
        res[k][0] = b[j][0];
        res[k][1] = b[j][1];
        res[k][2] = b[j][2];
        j++;
        k++;
    }
    
    res[0][2] = k-1;
}

int main() {
    int rows, cols;
    cout<<"enter the rows and cols of the matrices: ";
    cin>>rows>>cols;
    
    int a[100][3], b[100][3], res[100][3];
    addSparse(rows, cols, a, b, res);
    
    cout<<"resultant sparse matrix is:"<<endl;
    for(int i = 0; i<=res[0][2]; i++)
        cout<<res[i][0]<<" "<<res[i][1]<<" "<<res[i][2]<<endl;
    
    return 0;
}
