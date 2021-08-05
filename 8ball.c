/* Simple Magic 8Ball game build in C */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MINWORDSIZE 2 /* set this to mimimum word size - 1 for a question */

void Usage(char* caller){
    fprintf(stderr, "Usage: %s [OPTIONS...] QUESTION\n\n\
Description: Simple Magic 8Ball game build in C.\n\n\
QUESTION                Your question must contain a question mark(?)\n\
                        at the end of it. If your question is multiple\n\
                        words long write it in quotes.\n\n\
Options:\n\
    -f [ FILENAME ]     Tells the program where to read the answers.\n\
                        Default is \"./answers.txt\"\n\n\
    -h                  Show usage\n", caller);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv){

    srandom(time(NULL));
    char *ansFilename = "answers.txt";
    char *question;
    char **answerList;

    int c;
    int idx;

    while((c = getopt(argc, argv, "hf:")) != -1){
        switch(c){
            case 'f':
                ansFilename = optarg;
                break;
            case 'h':
                Usage(argv[0]);
                break;
            default:
                exit(EXIT_FAILURE);
        }	
    }

    idx = optind;
    if(argv[idx] == NULL){
        fprintf(stderr, "%s: You must provide a question for Scott to Answer!\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /* we check the length of the arg with the question mark to be bigger then 3 for a more realistic question to be asked and check for question mark at end of question */
    size_t qSize = strlen(argv[idx]);
    if((qSize <= MINWORDSIZE) || (argv[idx][qSize - 1] != '?')){
        fprintf(stderr, "%s: You must provide a real question for Scott to answer!. Your question must contain a question mark(?) at the end of it. If your question is multiple words long write it in quotes.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    question = argv[idx++];

    for(; idx < argc; idx++){
        fprintf(stderr, "%s: Invalid option %s.\n", argv[0], argv[idx]);
        exit(EXIT_FAILURE);
    }

    FILE *ansFile = fopen(ansFilename, "r");
    if(ansFile == NULL){
        fprintf(stderr, "%s: Could not open the answers file \"%s\".\n", argv[0], ansFilename);
        exit(EXIT_FAILURE);
    }

    int numAns = 0;
    char *dummy;
    ssize_t read;
    size_t len = 0;
    /* Count every line from the answers file */
    while((read = getline(&dummy, &len, ansFile)) != -1)
        numAns++;

    free(dummy);
    
    rewind(ansFile); /* return pointer to begining of file */

    answerList = calloc(numAns, sizeof(char*));
    if(answerList == NULL){
        fprintf(stderr, "%s: Could not allocate memory for answers.\n", argv[0]);
        fclose(ansFile);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while((i < numAns) && (read = getline(&answerList[i++], &len, ansFile) != -1));

    int index = random() % numAns; /* random answer from 0 to (numAns - 1) */
    printf("Your question is: %s\n", question); /* This can be omitted */
    printf("Scott says: %s", answerList[index]);

    fclose(ansFile);
    /* Free resources */
    for(int i = 0; i < numAns; i++){
        free(answerList[i]);
    }
    free(answerList);

    return EXIT_SUCCESS;
}

