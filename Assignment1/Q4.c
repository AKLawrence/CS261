/* CS261- Assignment 1 - Q.4*/
/* Name: Amanda Lawrence
 * Date: April 15, 2017
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/   

    int i, j;
    struct student tmp;
    //struct student minval;
    //minimum student score index
    int minDex = 0; 

    // minimum student score value
    int minVal = 0;
    for ( i = 0; i < n; i++ ) {
        minDex = i;
        minVal = students[i].score;
        /* find minimum of items i to end: */
        for ( j = i+1; j < n; j++ ) {
        if ( students[j].score < minVal ) {
            minVal = students[j].score;
            minDex = j;
        }
      }
      /* swap ith value with smallest if needed: */
        if ( minDex != i ) {
            tmp = students[i];
            students[i] = students[minDex];
            students[minDex] = tmp;
        }
    }

}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;
    
    /*Allocate memory for n students using malloc.*/
    struct student *arrayOfStudents = NULL;
    arrayOfStudents = malloc(n * sizeof(*arrayOfStudents));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    int x;
    for(x = 0; x < n; x++){
        arrayOfStudents[x].id = x;
        arrayOfStudents[x].score = rand() % 100 + 1;
    }
    
    /*Print the contents of the array of n students.*/
    int y;
    for(y = 0; y < n; y++){
        printf("Student ID: %d. Score is: %d\n", arrayOfStudents[y].id, arrayOfStudents[y].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(arrayOfStudents, n);
    
    /*Print the contents of the array of n students.*/
    int z;
    printf("AFTER SORT FUNCTION:  \n");
    for(z = 0; z < n; z++){
        printf("Student ID: %d. Score is: %d\n", arrayOfStudents[z].id, arrayOfStudents[z].score);
    }
    
    return 0;
}
