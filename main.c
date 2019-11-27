#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hash.h"
/**
 * \brief This function reads  and process an add instruction.
 *	
 */
void add_word(){
	char trash[10],native_word[512],foreign_word[512];
	scanf(" %s %s %s",trash,native_word,foreign_word);
	printf("|%s| |%s| |%s|\n",trash,native_word,foreign_word);
}

/**
 * \brief Auxiliar function to reads remove and find instructions.
 *
 */
char * read_one_word(){
	char trash[10];
	char * foreign_word;
		scanf(" %s %ms",trash,&(foreign_word));
	return foreign_word;
}
/**
 * \brief This function reads  and process a remove instruction.
 *
 */

void remove_word(){
	char * foreign_word = read_one_word();
	printf("|%s|\n",foreign_word);
	free(foreign_word);
}
/**
 * \brief This function reads  and process a fin instruction.
 */
void find(){
	char * foreign_word = read_one_word();
	printf("|%s|\n",foreign_word);
	free(foreign_word);
}
int main(void){
	HashTable * teste=createHashTable();
	char operation;
	while(scanf(" %c",&operation) != EOF){
		if     (operation=='a'||operation=='A')
			add_word();
		else if(operation=='r'||operation=='R')
			remove_word();
		else if(operation=='f'||operation=='F')
			find();
		else
			printf("Invalid Operation!\n");
	}	
	eraseHashTable(&(teste));
	return 0;
}
