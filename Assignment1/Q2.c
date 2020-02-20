/* CS261- Assignment 1 - Q.2*/
/* Name: Amanda Lawrence
 * Date: April 15, 2017
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;
    /*Set b to half its original value*/
    *b = *b / 2;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/
    printf("Value of x is: %d\n", x);
    printf("Value of y is: %d\n", y);
    printf("Value of z is: %d\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    /*Print the value returned by foo*/
    printf ("Value returned by foo function: %d\n", foo(&x, &y, z));
    
    /*Print the values of x, y and z again*/
    printf("Value of x is: %d\n", x);
    printf("Value of y is: %d\n", y);
    printf("Value of z is: %d\n", z);
 
    /*Is the return value different than the value of z?  Why?*/
    /* Z should be different because it was called by value, not by reference.
     * Due to scope, any changes made to z within foo() did not change the variable
     * z outside of the foo() function.
     */
    return 0;
}
    
    
