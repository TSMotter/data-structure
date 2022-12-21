# Hash table

- Used to store keys, values pairs
  - Duplicate keys are not allowed
- Allow for sequential and random access of elements (itens are indexed)
  - Time to access any element is the same
  - Elements are stored in an unordered manner
- In a hash table, it is possible for two different keys to be mapped to the same bucket. This is known as a collision. Hash tables use various techniques to handle collisions
- Fast lookup when searching for the value correspondent to a specific key
  - The efficiency of the lookup in a hash table depends on the quality of the hash function used. A good hash function will distribute the keys evenly across the array of buckets, minimizing collisions and ensuring that lookups are fast
- Can grow or shrink in size as needed
- Python "dictionaries" are hash tables