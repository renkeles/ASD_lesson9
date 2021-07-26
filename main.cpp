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

void insert(size_t _priority, size_t _data) {
    nodeType* node = new nodeType;
    node->data = _data;
    node->priority = _priority;
    size_t flag;

    if (items == 0) {
        arr[tail++] = node;
        items++;
    }
    else if (items == SIZE_Q) {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    else {
        size_t i = 0;
        size_t id = 0;
        nodeType* temp;
        for (i = 0; i < tail; i++) {
            id = i % SIZE_Q;
            if (arr[id]->priority > _priority) {
                break;
            }
            else {
                id++;
            }
        }
        flag = id % SIZE_Q;
        i++;
        while (i <= tail) {
            id = i % SIZE_Q;
            temp = arr[id];
            arr[id] = arr[flag];
            arr[flag] = temp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }
}



int main()
{

    return 0;
}
