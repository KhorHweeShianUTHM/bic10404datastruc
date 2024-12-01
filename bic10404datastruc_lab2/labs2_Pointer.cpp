#include <stdio.h>
struct number{
	int a;
	int b;
	int c;
};
#define size 3
typedef struct number Number; // typedef <existing_data_type> <new_data_type_name>;

int main(){

Number arrInt[size];

int i;
for (i=0;i<size;i++)
	{
		printf(" Enter the value-x \n ");
		scanf("%d",&arrInt[i].a);		
		printf(" Enter the value-y \n ");
		scanf("%d",&arrInt[i].b);
    	printf(" Enter the value-z \n ");
		scanf("%d",&arrInt[i].c);
	}
	for (i=0;i<size;i++)
	{
	 printf(" value-x index [%d] : %d ",i,arrInt[i].a);
	 printf(" value-y index [%d] : %d ",i,arrInt[i].b);
     printf(" value-y index [%d] : %d ",i,arrInt[i].c);
	 printf("\n");
	}		
return 0;
}