#include<iostream>
using namespace std;

void max_heapify(int a[], int n, int m){
    int l = 2*m + 1;
    int r = 2*m + 2;
    int largest = m;
    
    if(l<n && a[largest] < a[l])    
        largest = l;
    if(r<n && a[largest] < a[r])
        largest = r;
    
    if(largest != m){
        swap(a[largest], a[m]);
        max_heapify(a,n,largest);
    }
}

void build_max_heap(int a[], int n){
    for(int i = n/2 - 1; i>=0; i--)
        max_heapify(a, n, i);
}

void heap_sort(int a[], int n){
    build_max_heap(a,n);
    for(int i = n-1; i>=1; i--){
        swap(a[i], a[0]);
        max_heapify(a,i,0);
    }
}

int main(){
    int a[] = {1,2,65,23,56,90,34};
    heap_sort(a,7);
    for(int i = 0; i<7; i++)
        cout<<a[i]<<" ";
    
    return 0;
}
