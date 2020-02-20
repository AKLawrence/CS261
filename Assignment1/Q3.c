/* CS261- Assignment 1 - Q.3*/
/* Name: Amanda Lawrence
 * Date: April 15, 2017
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void sort(int* number, int n){
    /*Sort the given array number , of length n*/    
   int i, j, tmp;

   //minimum number's index
   int minDex = 0; 

   // minimum number's value
   int minVal = 0;
   for ( i = 0; i < n; i++ ) {
      minDex = i;
      minVal = number[i];
      /* find minimum of items i to end: */
      for ( j = i+1; j < n; j++ ) {
         if ( number[j] < minVal ) {
            minVal = number[j];
            minDex = j;
         }
      }
      /* swap ith value with smallest if needed: */
      if ( minDex != i ) {
         tmp = number[i];
         number[i] = number[minDex];
         number[minDex] = tmp;
      }
   }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *arrayOfInts = NULL;
    arrayOfInts = malloc(n * sizeof(*arrayOfInts));
    
    /*Fill this array with random numbers, using rand().*/
    for(int x = 0; x < 20; x++){
    	arrayOfInts[x] = rand() % 100 + 1;
  	}
    
    /*Print the contents of the array.*/
    for(int y = 0; y < 20; y++){
    	printf("Integer at index %d is: %d\n", y, arrayOfInts[y]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(arrayOfInts, n);
    
    /*Print the contents of the array.*/  
    printf("AFTER THE SORT FUNCTION:  \n");
    for(int z = 0; z < 20; z++){
    	printf("Integer at index %d is: %d\n", z, arrayOfInts[z]);
    }  
    
    return 0;
}
