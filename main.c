#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hash.h"


/**
 * \brief This function reads  and process an add instruction.
 *	
 */
void add_word(HashTable * h){
	char trash[TRASH],native_word[MAX_WORD],foreign_word[MAX_WORD];
	scanf(" %s %s %s",trash,native_word,foreign_word);
	addInTable(h,native_word,foreign_word);
}

/**
 * \brief Auxiliar function to reads remove and find instructions.
 *
 */
char * read_one_word(){
	char trash[TRASH];
	char * foreign_word;
		scanf(" %s %ms",trash,&(foreign_word));
	return foreign_word;
}
/**
 * \brief This function reads  and process a remove instruction.
 *
 */

void remove_word(HashTable * h){
	char * foreign_word = read_one_word();
	removeFromTable(h,foreign_word);
	free(foreign_word);
}
/**
 * \brief This function reads  and process a find instruction.
 */
void find(HashTable * h){
	char * foreign_word = read_one_word();
	printf("%s\n",getsInTable(h,foreign_word));
	free(foreign_word);
}



int main(void){
	HashTable * table = createHashTable();
	char operation;
	while(scanf(" %c",&operation) != EOF){
		if     (operation=='a'||operation=='A')
			add_word(table);
		else if(operation=='r'||operation=='R')
			remove_word(table);
		else if(operation=='f'||operation=='F')
			find(table);
		else
			printf("Invalid Operation!\n");
	}	
	eraseHashTable(&(table));
	return 0;
}
