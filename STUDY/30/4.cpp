#include <bits/stdc++.h>
using namespace std;
struct node{
	long long num,val;
}tree[100005],a[100005],tmp,tmp2;

int cnt,size;

bool cmp(node dd,node ee){
	return dd.num<ee.num;
}

void up(int m){
	while (m/2>0){
	if (tree[m].val<tree[m/2].val){
			swap(tree[m],tree[m/2]);
		}else if(tree[m].val==tree[m/2].val){
			if (tree[m].num<tree[m/2].num){
				swap(tree[m],tree[m/2]);
			}
		}
	m/=2;
	}
}

inline void down(int m){
	if (m*2+1>cnt) return;
	if (tree[m*2].val<tree[m*2+1].val||(tree[m*2].val==tree[m*2+1].val&&tree[m*2].num<tree[m*2+1].num)){
		if (tree[m].val>tree[m*2].val||(tree[m].val==tree[m*2].val&&tree[m].num>tree[m*2].num))
		{
			swap(tree[m],tree[m*2]);
			down(m*2);
		}
	}else{
		if (tree[m].val>tree[m*2+1].val||(tree[m].val==tree[m*2+1].val&&tree[m].num>tree[m*2+1].num))
		{
			swap(tree[m],tree[m*2+1]);
			down(m*2+1);
		}
	}
}

void add(int x,int n){
	cnt++;
	tree[cnt].num=n;
	tree[cnt].val=x;
	up(cnt);
}

void get(){
	tmp=tree[1];
	swap(tree[1],tree[cnt]);
	cnt--;
	down(1);
}

void get2(){
	tmp2=tree[1];
	swap(tree[1],tree[cnt]);
	cnt--;
	down(1);
}

int main(){
	int n,tt;
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%d",&tt);
		add(tt,i);
	}
	for (int i=1;i<=n;++i){
		get();
		get2();
		if (i==n){
			size++;
			a[size]=tmp;
			break;
		}
		// cout<<tmp.val<<' '<<tmp2.val<<endl;
		if (tmp.val==tmp2.val) add(tmp2.val*2,tmp2.num);
		else{
			size++;
			a[size]=tmp;
			add(tmp2.val,tmp2.num);
		}
	}
	// while (1){
	// 	get();
	// 	if (tmp.num==0) break;
	// 	size++;
	// 	a[size]=tmp;
	// }
	sort(a+1,a+size+1,cmp);
	cout<<size<<endl;
	for (int i=1;i<=size;++i)
		printf("%lld ",a[i].val);
	return 0;
}