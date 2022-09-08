#include <bits/stdc++.h>
using namespace std;

int min_of_four(int a, int b, int c, int d)
{
    int min1 = a < b ? a : b;
    int min2 = c < d ? c : d;
    return min1 < min2 ? min1 : min2;
}

void merge(int array[], int low, int mid1, int mid, int mid2, int high)
{
    int iter1, iter2, iter3, iter4, mergeIter;
    int size1 = mid1 - low + 1;
    int size2 = mid - mid1;
    int size3 = mid2 - mid;
    int size4 = high - mid2;
    int size = size1 + size2 + size3 + size4;
    int array1[size1], array2[size2], array3[size3], array4[size4];
    for (iter1 = 0; iter1 < size1; iter1++)
        array1[iter1] = array[low + iter1];
    for (iter2 = 0; iter2 < size2; iter2++)
        array2[iter2] = array[mid1 + 1 + iter2];
    for (iter3 = 0; iter3 < size3; iter3++)
        array3[iter3] = array[mid + 1 + iter3];
    for (iter4 = 0; iter4 < size4; iter4++)
        array4[iter4] = array[mid2 + 1 + iter4];
    iter1 = 0;
    iter2 = 0;
    iter3 = 0;
    iter4 = 0;
    mergeIter = low;

    while (iter1 < size1 || iter2 < size2 || iter3 < size3 || iter4 < size4)
    {
        
        int min = min_of_four(iter1 < size1 ? array1[iter1] : __INT32_MAX__, iter2 < size2 ? array2[iter2] : __INT32_MAX__, iter3 < size3 ? array3[iter3] : __INT32_MAX__, iter4 < size4 ? array4[iter4] : __INT32_MAX__);
        if (iter1 < size1 && array1[iter1] == min)
        {
            array[mergeIter++] = array1[iter1++];
        }
        else if (iter2 < size2 && array2[iter2] == min)
        {
            array[mergeIter++] = array2[iter2++];
        }
        else if (iter3 < size3 && array3[iter3] == min)
        {
            array[mergeIter++] = array3[iter3++];
        }
        else if (iter4 < size4 && array4[iter4] == min)
        {
            array[mergeIter++] = array4[iter4++];
        }
        else
        {
            break;
        }
    }
}

void mergeSort(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;      // 5
        int q1End = (low + mid - 1) / 2; // 3
        int q3End = (high + mid) / 2;    // 8

        mergeSort(array, low, q1End);
        mergeSort(array, q1End + 1, mid);
        mergeSort(array, mid + 1, q3End);
        mergeSort(array, q3End + 1, high);

        merge(array, low, q1End, mid, q3End, high);
    }
}

void print(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main()
{
    cout<<"Enter the size of array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout << "Enter the elements of array" << endl;

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"The original array is"<<endl;
    print(arr,n);
    mergeSort(arr,0,n-1);
    cout<<"The sorted array is"<<endl;
    print(arr,n);
 
    

    return 0;
}
