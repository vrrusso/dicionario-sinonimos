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

HashTable * createHashTable(){
	HashTable * h = (HashTable *) malloc(sizeof(HashTable));
	if(h!=NULL){
		h->table = (Hash *) malloc(sizeof(Hash)*M);
		for(int i=0;i<M;i++){
			strcpy(h->table->native_word,EMPTY);
			strcpy(h->table->foreign_word,EMPTY);
		}
		h->capacity=M;
	}
	return h;
}

void eraseHashTable(HashTable ** h){
	if((*h)!=NULL){
		free((*h)->table);
		free((*h));
		h=NULL;
	}
}
