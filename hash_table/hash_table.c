#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 3

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

void print_item(int index, struct HashTableEntry *item, const char *terminator)
{
  const char *pattern =
      "table[%d] = (key: %s, value: %d, next: 0x%x) (@0x%x)%s";

  if (item == NULL)
  {
    printf(pattern, index, "NULL", 0, 0, 0, terminator);
  }
  else
  {
    printf(pattern, index, item->key, item->value,
           (item->next == NULL ? 0 : item->next), item, terminator);
  }
}

// Insert a new key-value pair into the hash table
void print_first_level_items(HashTable *table)
{
  for (int i = 0; i < HASH_TABLE_SIZE; i++)
  {
    print_item(i, table->entries[i], "\n");
  }
  printf("\n");
}

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
void insert_item(HashTable *table, char *key, int value)
{
  unsigned int    index = hash(key);
  HashTableEntry *entry = table->entries[index];
  while (entry != NULL && entry->key != NULL && strcmp(entry->key, key) != 0)
  {
    printf("[WARN] Collision happened while trying to add item [key: %s, "
           "value: %d]. The "
           "position (%d) already contains the following item: [key: %s, "
           "value: %d]. Will "
           "make item [key: %s, value: %d] point to item [key: %s, value: %d] "
           "on the field 'next'.\n",
           key, value, index, entry->key, entry->value, key, value, entry->key,
           entry->value);
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
int lookup_item(HashTable *table, char *key)
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
  insert_item(table, "key10", 10);
  insert_item(table, "key1", 1);
  insert_item(table, "key2", 2);
  insert_item(table, "key3", 3);
  printf("Value for key 'key1': %d\n", lookup_item(table, "key1"));
  printf("Value for key 'key2': %d\n", lookup_item(table, "key2"));
  printf("Value for key 'key3': %d\n", lookup_item(table, "key3"));
  printf("Value for key 'key10': %d\n", lookup_item(table, "key10"));

  printf("Value for key 'invalid': %d\n", lookup_item(table, "invalid"));

  // printf("This is address : 0x%x\n", table->entries[7]->next);
  print_first_level_items(table);
}