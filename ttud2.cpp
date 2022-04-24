#include<iostream>
using namespace std;
int main(){
    int t, n,max = -100, a[100], x, max = 0;
    cout<<"Nhap so luong test case: "
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        x = a[i];
        for(int j = i+1; j<n; j++){
            if(x == a[j]-1){
                x = a[j];y++;
            }
        if(y>max){
            max = y;
        }
        }
    }
}