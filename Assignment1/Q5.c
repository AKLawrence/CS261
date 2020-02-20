/* CS261- Assignment 1 - Q.5*/
/* Name: Amanda Lawrence
 * Date: April 15, 2017
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
	int i;

	for(i=0; i < 10; i++){
		//check that the value at each index is not the terminating character
		if(word[i] != '\0'){

			// If a letter is uppercase, and in an odd numbered index, call toLowerCase()
			if(word[i] >= 'A' && word[i] <= 'Z'){
				if (i % 2 != 0){
					word[i] = toLowerCase(word[i]);
				}
			}

			//If a letter is lowercase and in an even numbered index, call toUpperCase()
			if(word[i] >= 'a' && word[i] <= 'z'){
				if (i % 2 == 0){
					word[i] = toUpperCase(word[i]);
				}
			}
		}
	}
}

int main(){
    /*Read word from the keyboard using scanf*/
    char input[10];
    char *p = input;
    printf("Please enter a word:  ");
    scanf("%s", &input);
    printf("You have entered %s\n", input);

    /*Call sticky*/
    sticky(p);

    /*Print the new word*/
    printf("Your sticky word is %s\n", input);

    return 0;
}
