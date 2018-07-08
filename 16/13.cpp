
#include <stdio.h>

#include <string.h>

int num[100000];

int main (){

    int n,t,x;

    while (scanf("%d%d%d",&n,&t,&x)!=EOF){

        for (int i=0;i<n;i++){

            scanf ("%d",&num[i]);

        }

        if (x>t){

            printf ("-1\n");

            continue;

        }

        int ans=x;

        int time=num[0];

        for (int i=0;i<n;i++){

            while (time<num[i]){

                time++;

                ans++;

            }

        }   

        printf ("%d\n",ans);

    }

    return 0;

} 
