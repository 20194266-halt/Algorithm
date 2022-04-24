#include<iostream>
#include<math.h>
using namespace std;

int method1(int n, int a[]){
    int max = a[0], sum;
    for (int i=0; i<n; i++)
    {   
        sum = 0;
        for(int j=i; j<n; j++){
            sum+=a[j];
            if(sum>max){
            max = sum;
            }
        }
    }
    return max;
}
//Recursion
int Maxleft(int a[], int low, int mid){
    int max = -1000000, maxSum = 0;
    for (int i = mid; i>=low; i--){
        maxSum += a[i];
        if(maxSum>max){
            max = maxSum;
        }
    }
    return max;
}

int Maxright(int a[], int mid, int high){
    int max = -1000000, maxSum = 0;
    for (int i = mid; i<=high; i++){
        maxSum += maxSum + a[i];
        if(maxSum>max){
            max = maxSum;
        }
    }
    return max;
}

int method2(int a[], int low, int high){
    int mid, wL, wR, wM;
    if(low == high){
        return a[low]; 
    }
    else{
        mid = (low + high)/2;
        wL = method2(a, low, mid);
        wR = method2(a, mid+1, high);
        wM = Maxleft(a, low, mid) + Maxright(a, mid+1, high);
        return max(max(wL, wR), wM);
    }
}
//Dynamic Programming
int method3(int a[], int n){
    int smax = a[0], imax =0, ei = a[0], u = 0, v;
    for(int i = 1; i<n; i++){
        u = a[i]+ei;
        v = a[i];
        if(u>v){
            ei = u;
        }
        else{
            ei = v;
        }
        if(ei>smax)
        {
            smax = ei;
            imax = i;
        }
        return smax;
    }
}

int main(){
    int n, sum , a[100];

    cout<<"Enter the number of element in array a: "<<endl;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter number"<<i+1<<endl;
        cin>>a[i];
    }
    /*
    Check three functions above by deleting '//' 
    */

    //cout<<method1(a, n);
    //cout<<method2(a, 0, n-1);
    //cout<<method3(a, n);
    
}