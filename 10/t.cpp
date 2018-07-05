#include <bits/stdc++.h>
using namespace std;
 
struct big
{
    long long dat[10005];
    long long le=1;
};
void bclean(big &a){
	for (int i = 1; i <= a.le; ++i)
	{
		a.dat[i]=0;
	}
	a.le=1;
}
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
void bw(big &a){
    for (int i = 1; i <= a.le-1; ++i)
    {
        if (a.dat[i]<0){
            a.dat[i]+=10;
            a.dat[i+1]--;
        }
    }
    if (a.dat[a.le]==0) a.le--;
}
void bread(big &a){
    string s1;
    cin>>s1;
    for (int i = 0; i < (int)s1.length(); ++i)
        a.dat[s1.length()-i]=s1[i]-'0';
    a.le=s1.length();
    int i;
    for (i = a.le; (a.dat[i]==0)&&(i>=1); --i);
    a.le=i;
}
void bget(big &p,long long x){
    while (x!=0){
        p.le++;
        p.dat[p.le]=x % 10;
        x/=10;
    }
}
void bout(big a){
    for (int i = a.le; i >=1 ; i--)
    {
        cout<<a.dat[i];
    }
    if (a.dat[a.le]==0) printf("%d",0);
        printf("\n");
}
bool bcmp(big a,big b){
    if (a.le>b.le) return 1;
    else if (a.le<b.le) return 0;
    else
    {
       for (int i = a.le; i >= 1; --i){
        if (a.dat[i]>b.dat[i]) return 1;
        else if (a.dat[i]<b.dat[i]) return 0;
       }
    }
    return 0;
}
void bj(big a,big b,big &c){
    for (int i = 1; i <= max(a.le,b.le); ++i)
    {
        c.dat[i]=a.dat[i]+b.dat[i];
    }
    c.le=max(a.le,b.le);
    jw(c);
}
void bs(big a,big b,big &c){  //a>=b
    for (int i = 1; i <= a.le; ++i)
    {
        c.dat[i]=a.dat[i]-b.dat[i];
    }
    bw(c);
    jw(c);
}
void bc(big &a,long long b){
    for (int i = 1; i <= a.le; ++i)
    {
        a.dat[i]*=b;
    }
    jw(a);
}
void bg(big a,long long b,big &ans){
    long long tmp=0l;
    long long i=1;
    while (i<=a.le){
        tmp=tmp*10+a.dat[a.le-i+1];
        ans.dat[a.le-i+1]=tmp / b;
        tmp %=b;
        i++;
    }
    ans.le=a.le;
    jw(ans);
    for (i = ans.le; ans.dat[i]==0; --i);
    ans.le=i;
}

int main(){
    big a,ans,b;
    bread(a);
    bclean(ans);bclean(b);
    while(a.dat[a.le]!=0){
    	bj(a,b,ans);
    	b=ans;
    	bread(a);
    }
    bout(ans);
    return 0;
}