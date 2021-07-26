#include <iostream>

const size_t SIZE_Q = 10;

typedef struct {
    size_t data;
    size_t priority;
} nodeType;

nodeType* arr[SIZE_Q];
size_t head;
size_t tail;
size_t items;

void initStruct() {
    for (size_t i = 0; i < SIZE_Q; i++) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}



int main()
{

    return 0;
}
