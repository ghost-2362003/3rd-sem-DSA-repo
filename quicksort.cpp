// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int partition(int a[], int l,int h){
    int i, j, t, p;
    p = a[h];
    i = l-1;
    for(j = l; j<h; j++)
        if(a[j]<p){
            i++;
            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    
    t = a[i+1];
    a[i+1] = a[h];
    a[h] = t;
    
    return i+1;
}

void quick_sort(int a[], int l, int h){
    if(l<h){
        int p = partition(a,l,h);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,h);
    }
}

int main() {
    int a[] = {3,23,89,76,123,156,234234};
    quick_sort(a,0,6); //give inputs as the array then the strating index(0), and the ending index(in this case 6 ince length 7)
    
    for(int i = 0; i<7; i++)
        cout<<a[i]<<" ";
    
    return 0;
}
