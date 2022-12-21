#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 10

typedef struct HashTableEntry
{
  char *                 key;
  int                    value;
  struct HashTableEntry *next;
} HashTableEntry;

typedef struct HashTable
{
  HashTableEntry *entries[HASH_TABLE_SIZE];
} HashTable;

// Hash function that maps keys to indices in the array
unsigned int hash(char *key)
{
  unsigned int hash = 5381;
  int          c;
  while ((c = *key++))
  {
    hash = ((hash << 5) + hash) + c;
  }
  return hash % HASH_TABLE_SIZE;
}

// Create a new hash table
HashTable *create_hash_table()
{
  HashTable *table = malloc(sizeof(HashTable));
  for (int i = 0; i < HASH_TABLE_SIZE; i++)
  {
    table->entries[i] = NULL;
  }
  return table;
}

// Insert a new key-value pair into the hash table
void hash_table_insert(HashTable *table, char *key, int value)
{
  unsigned int    index = hash(key);
  HashTableEntry *entry = table->entries[index];
  while (entry != NULL && entry->key != NULL && strcmp(entry->key, key) != 0)
  {
    entry = entry->next;
  }
  if (entry == NULL)
  {
    entry = malloc(sizeof(HashTableEntry));
    if (entry == NULL)
    {
      return;
    }
    entry->next           = table->entries[index];
    table->entries[index] = entry;
  }
  entry->key   = key;
  entry->value = value;
}

// Retrieve the value for a given key from the hash table
int hash_table_lookup(HashTable *table, char *key)
{
  unsigned int    index = hash(key);
  HashTableEntry *entry = table->entries[index];
  while (entry != NULL && entry->key != NULL && strcmp(entry->key, key) != 0)
  {
    entry = entry->next;
  }
  if (entry == NULL)
  {
    return -1;
  }
  return entry->value;
}

int main()
{
  HashTable *table = create_hash_table();
  hash_table_insert(table, "key1", 1);
  hash_table_insert(table, "key2", 2);
  hash_table_insert(table, "key3", 3);
  printf("Value for key 'key1': %d\n", hash_table_lookup(table, "key1"));
  printf("Value for key 'key2': %d\n", hash_table_lookup(table, "key2"));
  printf("Value for key 'key3': %d\n", hash_table_lookup(table, "key3"));
}