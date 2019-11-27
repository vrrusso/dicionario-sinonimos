#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/**
 * \brief This function reads and organizes an add instruction.
 *	
 */
void add_word(){
	char trash[10],original_word[512],foreign_word[512];
	scanf(" %s %s %s",trash,original_word,foreign_word);
	printf("|%s| |%s| |%s|\n",trash,original_word,foreign_word);
}
char * read_one_word(){
	char trash[10];
	char * foreign_word;
		scanf(" %s %ms",trash,&(foreign_word));
	return foreign_word;
}

void remove_word(){
	char * foreign_word = read_one_word();
	printf("|%s|\n",foreign_word);
	free(foreign_word);
}

int main(void){
	char operation;
	while(scanf(" %c",&operation) != EOF){
		if     (operation=='a'||operation=='A')
			add_word();
		else if(operation=='r'||operation=='R')
			remove_word();
		else if(operation=='f'||operation=='F')
			//find();
			printf("a");
		else
			printf("Invalid Operation!\n");
	}	
	return 0;
}
