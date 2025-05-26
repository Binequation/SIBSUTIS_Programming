#ifndef HASH_TABLE_H
#include HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>

#define INIT_TABLE_SIZE 2056

/*
    @brief: Bucket for hash table

    @param: key - string
    @param: value - frequency
    @param: next - pointer to next bucket
*/
struct Entry {
    char *key;
    int value;
    struct Entry *next;
};

/*
    @brief: Hash table

    @param: size - size of hash table
    @param: table - array of buckets
*/
struct HashTable {
    int size;
    struct Entry **table;
};

/*
    @brief: K&R hash func for index

    @param: key - string for hash

    @return: index of hashed string
*/
unsigned int KRhash(const char *key);

/*
    @brief: Init hash table

    @param: size - size of hash table

    @return: initialized hash table
*/
struct HashTable *init_hash(void);

/*
    @brief: Add element to hash table

    @param: table - hash table to add element
    @param: key - string
    @param: value - frequency

    @return: void
*/
void add_hash(struct HashTable *table, const char *key, int value);

/*
    @brief: Find element in hash table

    @param: table - hash table to find element
    @param: hash_index - index of element

    @return: void
*/
void find_hash(struct HashTable *table, const int hash_index);

/*
    @brief: Free hash table

    @param: table - hash table to free
*/
void free_hash(struct HashTable *table);

/*
    @brief: Resize table if initial size isn't enough

    @param: table - hash table to resize

    @return: resized hash table
*/
struct HashTable *resize_table(struct HashTable *table);

#endif
