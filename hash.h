#ifndef HASH_H
#define HASH_H
#define M 10000
#define MAX_WORD 512
#define TRASH 10
#define EMPTY "empty"
#define ERASED "#####"

typedef struct hash_table HashTable;//!<struct containing the table and the capacity

HashTable * createHashTable();//!<allocates memory for the table

void eraseHashTable(HashTable ** h);//!<freeing the heap

void addInTable(HashTable * h, const char * native_word, const char * foreign_word);//!<add in the hash table, storing the word in native and foreign language

void removeFromTable(HashTable * h, const char * foreign_word);//!<searching, seek and destroy

char * getsInTable(HashTable * h, const char * foreign_word);//!<returns the native word based on the foreign



#endif
