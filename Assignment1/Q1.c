/* CS261- Assignment 1 - Q.1*/
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

struct student* allocate(){
    /*Allocate memory for ten students*/
    struct student *arrayOfStudents = NULL;
    //int i;
    arrayOfStudents = malloc(10 * sizeof(*arrayOfStudents));


    /*return the pointer*/
    return arrayOfStudents;
}

void generate(struct student* students){
  /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
  int x;
  for(x = 0; x < 10; x++){
    students[x].id = x;
    students[x].score = rand() % 100 + 1;
  }
}

void output(struct student* students){
/*Output information about the ten students in the format:
    ID1 Score1
    ID2 score2
    ID3 score3
    ...
    ID10 score10*/
    int x;
    for(x = 0; x < 10; x++){
      printf("Student ID: %d. Score is: %d\n", students[x].id, students[x].score);
    }
}

void summary(struct student* students){
  /*Compute and print the minimum, maximum and average scores of the ten students*/
  int sum = 0;
  int min = 101;
  int max = -1;
  float avg = 0;
  int i;
  for (i = 0; i < 10; i++){
    int thisScore = students[i].score;
    sum += thisScore;
    if (thisScore > max) max = thisScore;
    if (thisScore < min) min = thisScore;
  }
  avg = sum / (float)10;
     
  fprintf(stderr, "The average of the 10 scores equals: %f\n", avg);
  fprintf(stderr, "The minimum of the 10 scores is: %d\n", min);
  fprintf(stderr, "The maximum of the 10 scores is: %d\n", max);

}

void deallocate(struct student* stud){
  /*Deallocate memory from stud*/
  free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    fprintf(stderr, "yomama 1\n");
    /*call generate*/
    generate(stud);
    fprintf(stderr, "yomama 2\n");
    /*call output*/
    output(stud);
    fprintf(stderr, "yomama 3\n");
    /*call summary*/
    summary(stud);
    fprintf(stderr, "yomama 4\n");
    /*call deallocate*/

    return 0;
}
