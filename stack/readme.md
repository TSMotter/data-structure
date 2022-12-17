# Stack

- A sequence of items in linear order which are stacked upon each other
- Allow for sequential access of elements only, in a LIFO (last in first out) format
  - Time to access different elements in the stack vary, depending of it's position
- The insertion and deletion of elements happen only at one endpoint
- Common methods are: push, pop, peek, isEmpty, isFull
- Useful for expression evaluation and other algorithms like depth-first search and undo/redo functionality
- Is generally built upon an array, thus it's maximum size is defined at creation time (be it using static or dinamic allocation)