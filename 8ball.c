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
	// if no .txt file is provided use this default answers
	char answerList[MAXWORDS][MAXCHARS] = {
		"It is Certain.",
		"It is decidedly so.",
		"Without a doubt.",
		"Yes definitely.",
		"You may rely on it.",
		"As I see it, yes.",
		"Most likely.",
		"Outlook good.",
		"Yes.",
		"Signs point to yes.",
		"Reply hazy, try again.",
		"Ask again later.",
		"Better not tell you now.",
		"Cannot predict now.",
		"Concentrate and ask again",
		"Don't count on it.",
		"My reply is no.",
		"My sources say no.",
		"Outlook not so good.", 
		"Very doubtful."
	};
	
	if(argc < 2){
		printf("You must provide a question for Scott to Answer!\n");
		exit(EXIT_FAILURE);
	}
	else if(argc == 3){
		FILE *ansFile = fopen(argv[1], "r");
		if(ansFile == NULL){
			printf("Could not open the file %s\n", argv[1]);
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

