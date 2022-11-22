SSTF

 
SSTF program:
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,n,TotalHeadMoment=0,initial,count=0;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    
    // logic for sstf disk scheduling
    
        /* loop will execute until all process is completed*/
    while(count!=n)
    {
        int min=1000,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(RQ[i]-initial);
           if(min>d)
           {
               min=d;
               index=i;
           }
           
        }
        TotalHeadMoment=TotalHeadMoment+min;
        initial=RQ[index];
        // 1000 is for max
        // you can use any number
        RQ[index]=1000;
        count++;
    }
    
    printf("Total head movement is %d",TotalHeadMoment);
    return 0;
}





Scan algorithm

#include<conio.h> 
#include<stdio.h> 
int main() 
{ 
 int i,j,sum=0,n; 
 int d[20]; 
 int disk;  //loc of head 
 int temp,max;   
 int dloc;  //loc of disk in array 
 
 printf("enter number of location\t"); 
 scanf("%d",&n); 
 printf("enter position of head\t"); 
 scanf("%d",&disk); 
 printf("enter elements of disk queue\n"); 
 for(i=0;i<n;i++) 
 { 
 scanf("%d",&d[i]); 
 } 
 d[n]=disk; 
 n=n+1; 
 for(i=0;i<n;i++)  // sorting disk locations 
 { 
 for(j=i;j<n;j++) 
 { 
 if(d[i]>d[j]) 
 { 
 temp=d[i]; 
 d[i]=d[j]; 
 d[j]=temp; 
 } 
 } 
 } 
 max=d[n]; 
 for(i=0;i<n;i++)  // to find loc of disc in array 
 { 
 if(disk==d[i]) { dloc=i; break;  } 
 } 
 for(i=dloc;i>=0;i--) 
 { 
 printf("%d -->",d[i]); 
 } 
 printf("0 -->"); 
 for(i=dloc+1;i<n;i++) 
 { 
 printf("%d-->",d[i]); 
 } 
 sum=disk+max; 
 printf("\nmovement of total cylinders %d",sum); 
 getch(); 
 return 0; 
}
