// #include <bits/stdc++.h>
// using namespace std;

// int a[3005][3005];

// int main(){
// 	int l1,l2;
// 	char c1[3005],c2[3005];
//     scanf("%s%s",c1,c2);
//     l1 = strlen(c1);
//     l2 = strlen(c2);
//     for( int i=1; i<=l1; i++ )
//         for( int j=1; j<=l2; j++ )
//         {
//             if( c1[i-1] == c2[j-1] ){
//                 a[i][j] = a[i-1][j-1]+1;
//             }else{
//                 a[i][j] = max(a[i-1][j],a[i][j-1]);
//             }
//         }
//     cout<<a[l1][l2];
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int a[3005],f[3005];

int main(){
    int top=0,n,pos;
    cin>>n;
    for (int i=1;i<=n;++i){
    	scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;++i){
        if(a[i]>f[top]){
            top++;
            f[top]=a[i];
        }else{
	        pos=lower_bound(f,f+top,a[i])-f;
	        if(f[pos]>a[i]) f[pos]=a[i];
		}
    }
    cout<<top<<endl;
    return 0;
}