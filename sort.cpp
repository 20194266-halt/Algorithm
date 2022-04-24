#include<iostream>
using namespace std;
void insertionSort(int a[], int n){
    int k, j;
    for (int i=1; i<n; i++){
        k = a[i], j = i;
        while ((j>0) && (k<a[j-1]))
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = k;
    }
}

void selectionSort(int a[], int n){
    int min, imin;
    for(int i=0; i<n; i++){
        imin = i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[i]){
                imin = j;
            }
        }
        swap(a[i], a[imin]);
    }
    
}

void bubbleSort(int a[], int n){
    while(n){
        for(int i = 0; i<n-1; i++){
            if(a[i]>a[i+1]){
                swap(a[i], a[i+1]);
            }
        }
        n--;
    }
}

void merge(int a[], int first, int mid, int last){
    int b[100],first1 = first, mid1 = mid+1;
    while((first1<=mid)&&((mid1)<=last)){
        if (a[first1]>=a[mid1]){
            b[first1] = a[mid1];
        }
        else{
            b[first1] = a[first1];
        }
        first1++; mid1++;
    }
    while(first1<=mid){
        b[first1] = a[first1];
    }
    while(mid1<=last){
        b[mid1] = a[mid1];
    }
    for(int i= first; i<=last; i++){
        a[i] = b[i];
    }
}
void mergeSort(int a[], int first, int last){
    if(first<last){
        int mid = (first+last)/2;
        mergeSort(a, first, mid);
        mergeSort(a, mid+1, last);
        merge(a, first, mid, last);
    }
}
//Quick sort with PivotHead
int Partition(int a[], int first, int last){
    int pivot = a[first];
    int i = first, j = last+1;
    while (i<j)
    {
        ++i;
        while(a[i]<pivot){
            i++;
        }
        j--;
        while(a[j]>pivot){
            j--;
        }
        swap(a[i], a[j]);
    }
    swap(a[j], a[first]);
    return j;
}
void quickSort(int a[], int first, int last){
    int pivotIndex;
    if(first<last){
        pivotIndex = Partition(a, first, last);
        quickSort(a, first, pivotIndex-1);
        quickSort(a, pivotIndex+1, last);
    }
}

void maxHeapify(int a[], int i, int n){
    int l = 2*i, r = 2*i+1, largest;
    if(l<n && a[i]>a[l]){
        largest = i;
    }
    else{
        largest = l;
    }
    if(r<n && a[r]>a[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(a[largest], a[i]);
        maxHeapify(a, largest, n);
    }
}
void buildMaxHeap(int a[], int n){
    for(int i = n/2;i>=0; i++){
        maxHeapify(a, i, n);
    }
}
void heapSort(int a[], int n){
    buildMaxHeap(a, n);
    for(int i = n; i>=2; i++){
        swap(a[i], a[1]);
        maxHeapify(a, 1, i-1);
    }
}

int main(){
    int a[100], n;
    cout<<"Enter n = "<<endl;
    cin>>n;
    for(int i = 0; i<n; i++){
        cout<<"Enter number"<<i+1<<endl;
        cin>>a[i];
    }
    cout<<"Before sorting: ";
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    bubbleSort(a, n);
    cout<<"After sorting: ";
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }

}