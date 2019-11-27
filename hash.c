#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hash.h"

typedef struct hash_{
	char native_word[MAX_WORD];
	char foreign_word[MAX_WORD];
}Hash;

struct hash_table{
	Hash * table;
	int capacity;
};

/** \brief allocates memory for the table and initialize its values as EMPTY constant.
 *
 *	\returns a pointer for the new table.
 */
HashTable * createHashTable(){
	HashTable * h = (HashTable *) malloc(sizeof(HashTable));
	if(h!=NULL){
		h->table = (Hash *) malloc(sizeof(Hash)*M);
		for(int i=0;i<M;i++){
			strcpy(h->table[i].native_word,EMPTY);
			strcpy(h->table[i].foreign_word,EMPTY);
		}
		h->capacity=M;
	}
	return h;
}

/** \brief calculates the "weight" of a string define as the sum of the chars
 *
 * \param key the string to be evaluate
 * 
 * \return the code of the string key
 *
 */

int get_string_code(const char * key){
	int code=0;
	for(int i=0;i<strlen(key);i++)
		code+=(key[i]);
	return code;
}
/** \brief computes the index of a string in a hash table, even if theres a collision
 * 
 *  \param table[] the hash table itself
 *  \param key the string used as a key
 *
 *  \return the index of the key in the table
 *
 */
int hash_code(Hash table[], const char * key){
	int integer_key=get_string_code(key);
	int code=integer_key%M;
	while(strcmp(table[code].native_word,EMPTY)!=0 && strcmp(table[code].native_word,ERASED)!=0 && strcmp(table[code].foreign_word,key) != 0)
		code=(code+1)%M;
	return code;
}

/** \brief stores a set of two string in the hash table
 *	
 *	\param h the hash table complex structure containing the table and its capacity
 *	\param native_word a string wich is stored in the table
 *	\param foreign_word
 *
 *  \returns the void of existence	 
 *
 */

void addInTable(HashTable * h, const char * native_word, const char * foreign_word){
	if(h->capacity>0){
		int index = hash_code(h->table,foreign_word);
		strcpy(h->table[index].native_word,native_word);
		strcpy(h->table[index].foreign_word,foreign_word);
		h->capacity--;
		return;
	}
	printf("Cannot insert!Full table!\n");
}

int find_ht(Hash table[],const char * key){
	int integer_key=get_string_code(key);
	int code=integer_key%M;
	while( strcmp(table[code].foreign_word,key)!=0 && strcmp(table[code].foreign_word, EMPTY)!=0)
		code=(code+1)%M;
	if(strcmp(table[code].foreign_word,EMPTY)==0)
		return -1;
	return code;
	
}

void removeFromTable(HashTable * h, const char * foreign_word){
	if(h->capacity < M){
		int index = find_ht(h->table,foreign_word);
		if(index != -1){
			strcpy(h->table[index].native_word,ERASED);
			strcpy(h->table[index].foreign_word,ERASED);
			h->capacity++;
		}		
		return;
	}
	printf("Empty Table !!");
}

char * getsInTable(HashTable * h, const char * foreign_word){
	if(h->capacity < M){
		int index = find_ht(h->table,foreign_word);
		if(index != -1){
			return h->table[index].native_word;
		}		
	}
	return "hein?";
}

/** \brief deallocates the space from the table
 *
 * 	\param h a pointer for the table itself
 *
 */
void eraseHashTable(HashTable ** h){
	if((*h)!=NULL){
		free((*h)->table);
		free((*h));
		h=NULL;
	}
}
