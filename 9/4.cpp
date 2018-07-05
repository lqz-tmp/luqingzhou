#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
void hx(int row,int col,int a,int b){
    if ( (row<=a) && (col<=b) ){
        for(int i=col;i<b;i++)
            printf("%d\n",arr[row][i]);
        for(int i=row+1;i<a;i++)
            printf("%d\n",arr[i][b]);
        for(int i=b-1;i>=col;i--)
            printf("%d\n",arr[a][i]);
        for(int i=a-1;i>=row+1;i--)
            printf("%d\n",arr[i][col]);
    }
    else return;
    hx(row+1,col+1,a-1,b-1);
}
int main(){
    int a,b;
    int t;
    t=scanf("%d %d\n",&a,&b);
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            t=scanf("%d",&arr[i][j]);
    hx(0,0,a,b);
    return 0;
}  