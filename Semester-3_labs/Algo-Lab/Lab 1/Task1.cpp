#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m2 = l + (r - l) / 2;
        int m1 = l + (m2-l)/2;
        int m3 = m2+1 + (r-m2-1)/2;
        
        mergeSort(a, l, m1);
        mergeSort(a, m1+ 1, m2);
        merge(a, l, m1, m2);
        
        mergeSort(a, m2+1, m3);
        mergeSort(a, m3+1, r);
        merge(a, m2+1, m3, r);
        
        merge(a, l, m2, r);
        
    }
}
 
void display(int a[], int n){
    for (int i = 0; i < n; i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
 
int main()
{
    cout<<"Enter size of array"<<endl;
    int n;
    cin>>n;
    
    int a[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    cout<<"Original Array"<<endl;
    display(a, n);
    
    mergeSort(a, 0, n-1);
    cout<<"Sorted Array"<<endl;
    display(a, n);
    
    return 0;
}
