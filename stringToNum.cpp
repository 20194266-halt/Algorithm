#include<iostream>
using namespace std;
int main(){
    char a = 'b';
    switch (a)
    {
    case '1': {cout<<1;} break;   
    case '2': {cout<<2;} break;
    
    
    default:
        cout<<(int ) a; break;
    }
}