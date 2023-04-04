#include<stdio.h>
#include<stdbool.h>


int main (void) {
	char grade;
	printf("Enter your grade: \n");
	scanf("%c", &grade);
	switch (grade) {
		case 'A':
			printf("Amazing! A smart person! ");
		case 'B':
			printf("You have met expectations.\n");
			break;
		case 'C':
			printf("You need to study harder!");
		case 'D':
			printf("At least you passed!\n");
			break;
		case 'F':
			printf("Well, they're always hiring in the army.\n");
			break;
		default :
			printf("That's not even a proper grade!\n");
	}
}
