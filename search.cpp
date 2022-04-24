#include<iostream>
using namespace std;
int binarySearch(int a[], int first, int last, int target){
    int mid = (first+last)/2;
    if(a[mid]==target){
        return mid; 
    }
    else{
        if(a[mid]<target){
            return binarySearch(a, mid+1, last, target);
        }
        else{
            return binarySearch(a, first, mid-1, target);
        }
    }
    return -1;
}
int main(){
    int a[10], n;
    //check
    cout<<"Enter array:"<<endl;
    for(int i = 0; i<6; i++){
        cout<<"Enter number"<<i+1<<": ";
        cin>>a[i];
    }
    cout<<"Emter the number that you want to search:";
    cin>>n;
    cout<<"The position of number you entered: "<<endl;
    cout<<binarySearch(a, 0, 6, n);
}