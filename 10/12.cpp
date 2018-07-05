#include <bits/stdc++.h>
using namespace std;

struct per
{
	int g,f;
}c[105];
int gr[105];
bool cmp(per a,per b){
	return a.g<b.g;
}
int tw(int i,int j){
	int tmp=0;
	for (int k=i;k<=j;k++) tmp+=c[k].g;
	return tmp;
}
int main(){
	int t,g,n,m,tg,ta1,ta2,an1,an2,x,j;
	scanf("%d",&t);
	for (int i = 0; i < t; ++i){
		x=0;
		scanf("%d %d %d",&g,&n,&m);
		 for (int j = 1; j <= n; ++j)
		 	{scanf("%d %d",&c[j].g,&c[j].f);x+=c[j].f;}
		 for (int j = 1; j <= m; ++j)
		 	scanf("%d",&gr[j]);
		  sort(gr+1,gr+m+1);
		  sort(c+1,c+n+1,cmp);
		j=1; ta1=0; ta2=g;
		while ((ta2>=gr[j])&&(j<=m)){
			ta2-=gr[j];
			ta1++;
			j++;
		}
		an1=ta1;an2=ta2;tg=g;
		for (int k = 1; (k <= n)&&(tg>=c[k].g); ++k)
		{
			ta1=n; ta2=g;tg-=c[k].g;
			ta2-=tw(1,k);
			ta1+=min(x-n+k,m);
			j=1;
			while ((ta2>=gr[j])&&(ta1<m+n)){
			  ta2-=gr[j];
			  ta1++;
			  j++;
			}
			if ((ta1>an1)||((ta1==an1)&&(ta2>an2))){
				an1=ta1;an2=ta2;
			}
		}
		printf("Case #%d:\n%d %d\n",i+1,an1,an2);
	}
	return 0;
}