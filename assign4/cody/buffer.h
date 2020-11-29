#include <iostream>


typedef int buffer_item;
// size of buffer
#define BUFFER_SIZE 5

// PURPOSE: inserts an item and updates the pointer
// PARAMETER: item pointer
// returns 0 if successful or -1 if insert unsucessful
int insert_item(buffer_item item);

// PURPOSE: removes item by updating the pointer
// PARAMETER: item pointer
// returns 0 if was successful or -1 if was unsuccessful
int remove_item(buffer_item *item);

// PURPOSE: produces an item in the buffer.
// PARAMETER: param is passed by a pthread
void *producer(void *param);


// PURPOSE: consumes an item in the buffer.
// PARAMETER: param is passed by a  pthread
void *consumer(void *param);


