/* Name: Amanda Lawrence
 * Date: April 22, 2017
 * Assignment 2
 * Class: CS 261
 * File: stackapp.c
 */


/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:  returns 1 if the string is balanced and 0 if it is not balanced
*/
int isBalanced(char* s) {	

	DynArr *myStack;
	myStack = newDynArr(50);

	char newChar = nextChar(s);

	//while there are still char's that are not escape characters
	while (newChar != '\0'){
		//push the opening brackets onto the stack. When we reach a closing bracket, check that it has a matching opening bracket on the top of myStack.
		switch(newChar){
			case '(':
			case '{':
			case '[':
				pushDynArr(myStack, newChar);
				break;

			case ')':
				if(topDynArr(myStack) == '('){
					popDynArr(myStack);
					break;
				} else {
					return 0;
				}

			case '}':
				if(topDynArr(myStack) == '{'){
					popDynArr(myStack);
					break;
				} else {
					return 0;
				}

			case ']':
				if(topDynArr(myStack) == '['){
					popDynArr(myStack);
					break;
				} else {
					return 0;
				}
		}
	}

	//If the string is balanced, delete the stack and return 1.
	deleteDynArr(myStack);
	return 1;

}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

