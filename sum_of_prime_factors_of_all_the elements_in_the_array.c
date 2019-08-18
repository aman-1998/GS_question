#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,j;
    printf("Enter no. of inputs :");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    for(i=0;i<=n-1;i++)
    {
        printf("Enter a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    int max=-99999999;
    for(i=0;i<=n-1;i++)
    {
        if(max<a[i])
            max=a[i];
    }
    //Sieve of Eratosthenes
    int *prime=(int*)calloc(max+1,sizeof(int));
    prime[0]=1;
    prime[1]=1;
    for(i=2;i<=max;i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=max;j=j+i)
                prime[j]=1;
        }
    }
    int sum=0;
    for(i=0;i<=n-1;i++)
    {
        for(j=2;j<=a[i];j++)
        {
            if(a[i]%j==0)
            {
                if(prime[j]==0)
                    sum+=j;
            }
        }
    }
    printf("sum = %d",sum);
    return 0;
}
