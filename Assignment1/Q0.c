/* CS261 - Assignment 1 - Q. 0*/
/* Name: Amanda Lawrence
 * Date: April 15, 2017
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("value pointed to by iptr: %d\n", *iptr);
     
     /*Print the address pointed to by iptr*/
	printf("address pointed to by iptr: %p\n", (void*)iptr);
     
     /*Print the address of iptr itself*/
	printf("address of iptr itself: %p\n", (void*)&iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 3;

    /*print the address of x*/
    printf("address of x: %p\n", (void*)&x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("value of x: %d\n", x);
    
    return 0;
}
