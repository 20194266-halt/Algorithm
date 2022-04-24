#include<iostream>
using namespace std;
int main(){
    int t, m, n, a[100], b[100];int x = 0;
    cout<<"Nhap so luong test case: "<<endl;
    cin>>t;
    while(t){
        
        cout<<"Nhap so luong phan tu cua day a: "<<endl;
        cin>>m;
        cout<<"Nhap cac phan tu cua day a:"<<endl;
        for(int i = 0; i<m; i++){
            cin>>a[i];
        }
        cout<<"Nhap so phan tu cua day b: "<<endl;
        cin>>n;
        cout<<"Nhap cac phan tu cua day b"<<endl;
        for(int i = 0; i<n; i++){
            cin>>b[i];
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j< n; j++){
                if(a[i]==b[j]){
                    x++; break;
                }
            }
        }
        cout<<x;
      t--;
    }
    
}