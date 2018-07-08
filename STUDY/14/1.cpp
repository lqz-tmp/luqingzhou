#include <bits/stdc++.h>
using namespace std;
 
struct big
{
    int dat[205];
    long long le=1;
};
int i;      //to find "0"
string s1;  //to save the tmp
void jw(big &a){
    for (int i = 1; i <= a.le-1; ++i)
    {
        if (a.dat[i]>=10){
            a.dat[i+1]+=a.dat[i]/10;
            a.dat[i]%=10;
        }
    }
    while (a.dat[a.le]>=10){
        a.le++;
        a.dat[a.le]+=a.dat[a.le-1]/10;
        a.dat[a.le-1]%=10;
    }
}
void bclean(big &a){
    for (int i = 1; i <= a.le; ++i)
    {
        a.dat[i]=0;
    }
    a.le=1; //reset
}
void bread(big &a){
    cin>>s1;
    for (int i = 0; i < (int)s1.length(); ++i)
        a.dat[s1.length()-i]=s1[i]-'0';
    a.le=s1.length();  //to read Big
}
void bout(big a){
    for (int i = a.le; i >=1 ; --i)
    {
        cout<<a.dat[i];
    }
        printf("\n");  //to print Big
}
void badd(big a,big b,big &c){
    for (int i = 1; i <= max(a.le,b.le); ++i)
    {
        c.dat[i]=a.dat[i]+b.dat[i];
    }
    c.le=max(a.le,b.le);
    jw(c); //c=a+b
}
int main(){
	big a,b,c;
	bclean(a);bclean(b);bclean(c);
	bread(a);bread(b);
	badd(a,b,c);
	bout(c);
	return 0;
}
