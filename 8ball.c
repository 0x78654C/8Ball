/*Simple Magic 8Ball game build in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
void swap(int *a, int *b);
void randomize(int arr[], int n);

int main(int argc, char *argv[]){
	
	if(argc<2){
		printf("You must provide a question for Scott to Answer!\n");
		exit(-1);
	}
	
	char *answerList[]={"It is Certain.",
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
	"Very doubtful."};
	   

    int n= sizeof(arr)/sizeof(arr[0]);
	randomize(arr,n);          

    int s=0;                           
    for(int i= 0; i<n;i++){    
	    int index = arr[i];
   	 	if(s==0){
       		printf("Scott says: %s\n",answerList[index]);
	   		s++;
		}
   }
	   
	return 0;

}


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b= temp;
}

void randomize(int arr[], int n){
	srand(time(NULL));
	int i;
	for(i = n-1; i > 0; i--){
		
		int j= rand() % (i+1);
		swap(&arr[i], &arr[j]);
	}
}


