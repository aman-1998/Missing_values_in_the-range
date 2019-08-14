#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *p,const void *q);
int binarySearch(int A[],int n,int target);
int main()
{
    int *A=NULL;
    int x,n=0,ch,i,count,start,end;
    do
    {
        A=(int*)realloc(A,(n+1)*sizeof(int));
        printf("Enter input: ");
        scanf("%d",&A[n++]);
        printf("Enter \'0\' to continue and any other key to quit: ");
        scanf("%d",&ch);
    }
    while(ch==0);
    for(i=0;i<=n-1;i++)
        printf("%d ",A[i]);
    printf("\nEnter range: ");
    scanf("%d %d",&start,&end);
    qsort(A,n,sizeof(int),cmpfunc);
    int s=binarySearch(A,n,start);
    int e=binarySearch(A,n,end);
    printf("\nMissing elements: ");
    for(i=s+1;i<=e;i++)
    {
        count=A[i]-A[i-1]-1;
        x=A[i-1]+1;
        while(count!=0)
        {
            printf("%d ",x++);
            count--;
        }
    }
    return 0;
}
int cmpfunc(const void *p,const void *q)
{
    int x=*(int*)p;
    int y=*(int*)q;
    if(x<y)
        return -1;
    else
        return 1;
}
int binarySearch(int A[],int n,int target)
{
    int p=0,q,r=n-1;
    while(p<=r)
    {
        q=(p+r)/2;
        if(A[q]==target)
            return q;
        else if(A[q]<target)
        {
            p=q+1;
            r=n-1;
        }
        else
        {
            p=0;
            r=q-1;
        }
    }
    return -1;
}
