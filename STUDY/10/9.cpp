#include<bits/stdc++.h>
using namespace std;

struct per
{
	long long l,r;
}a[1005];

struct big
{
	long long dat[5000];
	long long le=0;
};
void jw(big &a){
	for (long long i = 1; i <= a.le-1; ++i)
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
void bget(big &p,long long x){
	while (x!=0){
		p.le++;
		p.dat[p.le]=x % 10;
		x/=10;
	}
}
void bout(big a){
	for (long long i = a.le; i >=1 ; --i)
	{
		cout<<a.dat[i];
	}
		printf("\n");
}
bool bcmp(big a,big b){
	if (a.le>b.le) return 1;
	else if (a.le<b.le) return 0;
	else
	{
	   for (long long i = a.le; i >= 1; --i){
	   	if (a.dat[i]>b.dat[i]) return 1;
	   	else if (a.dat[i]<b.dat[i]) return 0;
	   }
	}
    return 0;
}
void bc(big &a,long long b){
	for (long long i = 1; i <= a.le; ++i)
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

bool cmp(per b,per c){
	// double t1=max(1/(double)b.r,(double)b.l/(double)c.r);
	// double t2=max(1/(double)c.r,(double)c.l/(double)b.r);
	// return t1 < t2;
	return c.l*c.r>b.l*b.r;
}

int main(){
	long long n;
	cin>>n;
	for (long long i = 0; i <=n; ++i){
		cin>>a[i].l>>a[i].r;
	}
	sort(a+1,a+n+1,cmp);
	big ans,tmp,te;
	bget(ans,0);bget(tmp,1);bget(te,0);
	 for (long long i = 1; i <=n; ++i){
	 	bc(tmp,a[i-1].l);
	 	bg(tmp,a[i].r,te);
	 	if (bcmp(te,ans)) ans=te;
	 }
	bout(ans);
	return 0;
}