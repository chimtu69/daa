#include<stdio.h>
#include<conio.h>
int jobsequence(int d[6],int j[6],int n)
{
    int q,i,r,k;
    d[0]=0;
    j[0]=0;
    j[1]=1;
    k=1;
    for(i=2;i<=n;i++)
    {
        r=k;
        while((d[j[r]]>d[i]) &&(d[j[r]]!=r))
            r=r-1;
        if((d[j[r]]<=d[i]) && (d[i]>r))
        {
            for(q=k;q>=r+1;q--) 
            {
                j[q+1]=j[q];
            }
            j[r+1]=i;

            k=k+1;
        }
    }
    return k;
}

void main( )
{
int d[6],j[6],p[6],k,i,max=0;
clrscr( );
printf("Enter the deadlines :");
for(i=1;i<=5;i++)
scanf("%d",&d[i]);
printf("Enter the profits :");
for(i=1;i<=5;i++)
scanf("%d",&p[i]);
for(i=1;i<=5;i++)
j[i]=i;
k=jobsequence(d,j,5);
printf("\nThe solution job sequence is ");
for(i=1;i<=k;i++)
printf("\n%d",j[i]);
for(i=1;i<=k;i++) {
    max += p[j[i]];
}
printf("\nMaximum profit is %d\n",max);
printf("dmax : %d\n",k);

getche( );
}

/*
Enter the deadlines :2 1 3 2 1
Enter the profits :60 100 20 40 20

The solution job sequence is 
2
1
3
Maximum profit is 180
dmax : 3
*/