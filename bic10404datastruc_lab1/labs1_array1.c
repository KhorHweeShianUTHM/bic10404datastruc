#include <stdio.h>

int main(void)
{ 
double mylist[5]={1.9,1.2,2.4,1.5,4.4};
int i;
for (i=0;i<=4;i++)
{
printf("Enter Value\n");
scanf("%d",&mylist[i]);	
}

for (i=0;i<=4;i++)
{
printf("Array Value: %d",mylist[i]);
printf("\n");
}

return 0; /*end here */
}