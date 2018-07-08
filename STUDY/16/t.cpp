#include<bits/stdc++.h>
using namespace std;
int ml,k,tmp,j;
string s;
 
int main(){
    cin>>s;  cin>>k;
    for (int i=0;i<=s.length()-1;++i){
        tmp=0;
        for (j=0;i-j>=0&&i+j<=s.length()-1;++j){
            if (s[i-j]!=s[i+j]) {
                tmp++;
                if(tmp>k) break;
            }
            ml=max(ml, j*2+1);
        }
    }
    for (int i=0;i<=s.length()-2;++i){
        tmp=0;
        for (j=0;i-j>=0&&i+1+j<=s.length()-1;++j){
            if (s[i-j]!=s[i+1+j]){
                tmp++;
                if (tmp>k) break;
            }
            ml=max(ml, 2*j+2);
        }
    }
    cout<<ml;
    return 0;
}