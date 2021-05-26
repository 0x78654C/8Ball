/*Simple Magic 8Ball game build in C */

/* ToDo:
	1. Remove MAXCHARS and MAXWORDS constants and dynamically
	add the words with malloc/realloc

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXCHARS 100
#define MAXWORDS 1000

void clearAnsArr(char ansList[MAXWORDS][MAXCHARS]);

int main(int argc, char **argv){

	srandom(time(NULL));
	int words = 0;
	char answerList[MAXWORDS][MAXCHARS] = {0};
	
	if(argc < 2){
		printf("You must provide a question for Scott to Answer!\n");
		exit(EXIT_FAILURE);
	}
	else {
		
		if(strlen(argv[argc - 1]) > 2 ){ //we check the length of the arg with the question mark to be bigger then 3 for an more realistic question to be asked
			if(strstr(argv[argc - 1],"?") == NULL){ //check for question mark
				printf("Your question must contain a question mark(?) !\n");
				exit(EXIT_FAILURE);
			}
		}else{
			printf("You must provide a real question for Scott to Answer!\n");
			exit(EXIT_FAILURE);
		}

		FILE *ansFile = fopen("answers.txt", "r");
		if(ansFile == NULL){
			printf("Could not open the file answers.txt");
			exit(EXIT_FAILURE);
		}
		clearAnsArr(answerList); // clear all the previous data in the array
		char str[MAXCHARS];
		int i = 0;
		while(fgets(str, MAXCHARS, ansFile) != NULL){
			sprintf(answerList[i++], "%s", str); // get line by line every word
		}
		fclose(ansFile);
		words = i;
	}
	int index = random() % words; // random word from 0 to (word - 1)
	printf("Scott says: %s", answerList[index]);

	exit(EXIT_SUCCESS);

}

void clearAnsArr(char ansList[MAXWORDS][MAXCHARS]){
	int i;
	for(i = 0; i < MAXWORDS; i++)
		strcpy(ansList[0], "");
}

