#include <bits/stdc++.h>
using namespace std;

int a[3][10005];

int main(){
	int l1,l2;
	char c1[10005],c2[10005];
	scanf("%s",c1);
	scanf("%s",c2);
    l1 = strlen(c1);
    l2 = strlen(c2);
    for( int i=1; i<=l1; i++ ){
        for( int j=1; j<=l2; j++ )
        {
            if( c1[i-1] == c2[j-1] ){
                a[2][j] = a[1][j-1]+1;
            }else{
                a[2][j] = max(a[1][j],a[2][j-1]);
            }
        }
        for (int j=1;j<=l2;++j){
        	a[1][j]=a[2][j];
        }
    }
    cout<<a[2][l2];
	return 0;
}