#include<iostream>
using namespace std;
int checkPalindrome(string s){
    int n = s.length();
    if(!(n%2)){
        for (int i=0; i<=n/2-1; i++){
            if(s[i]!=s[n-1-i]){
                return 0;
            }
        }
    }
    if(n%2){
        for (int i=0; i<n/2; i++){
            if(s[i]!=s[n-1-i]){
                return 0;
            }
        }
    }
    return 1;
}
string longestPalindrome1(string s) {
    int l = s.length(); int n = l; string k;
        while(n){
            for(int i = 0; i+n<=l;i++){
               if(checkPalindrome(s.substr(i, n))){
                   return s.substr(i, n);
               }
            } 
            n--;
        }
    }
//Dynamic programming
string longestPalindrome2(string s){
    int a[100][100], l = s.length(),len, lmax = 1, istart = 0;
    for(int i = 0; i<l-1; i++){
        a[i][i] = 1;
       
        a[i][i+1] = (a[i]==a[i+1]);
        
        if(a[i][i+1] && lmax ==1){
            lmax = 2;
            istart = i;
        }
    }
    a[l-1][l-1] = 1;
    for(int i = 2; i<l; i++){
        int k = 0, j = i;
        while(k<(l-j) && j<l){
            a[k][j] = (a[k+1][j-1] && s[k] == s[j]);
            
            len = j-k+1;
            if(a[k][j] && len>lmax){
            
                lmax = len; istart = k;
            }
        j++; k++;
        }
    }
    
    return s.substr(istart, lmax);
}

int main(){
    //cout<<checkPalindrome("bb");
    cout<<longestPalindrome2("babab");
}