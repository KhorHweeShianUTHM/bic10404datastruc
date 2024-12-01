#include <stdio.h>
int count=0;
void get(int n) {
	
     if (n<1)
     	return;
           
     get(n-1); 
	 count++;
	 
     get(n-3); 
	 count++;
 }
 
 int main(){
 	get(6);
 	printf("The total of get(n-1) and get(n-3) function was invoked %d times.", count);
 	return 0;
 }