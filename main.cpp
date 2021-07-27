#include <iostream>


//////////////////////////////////////////////////////////////////////////////////
const size_t SIZE_Q = 10;

typedef struct {
    size_t priority;
    size_t data;
} nodeType;

nodeType* arr[SIZE_Q];
size_t head;
size_t tail;
size_t items;

void initStruct() {
    for (size_t i = 0; i < SIZE_Q; i++) {
        arr[i] = nullptr;
    }
    head = 0;
    tail = 0;
    items = 0;
}
/*
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
        for (i = head; i < tail; ++i) {
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
*/
/*
nodeType* remove() {
    if (items == 0) {
        return nullptr;
    } else{
        size_t id = head++ % SIZE_Q;
        nodeType* temp = arr[id];
        arr[id] = nullptr;
        items--;
        return temp;
    }
}
*/

void insert(size_t _priority, size_t _data){
    nodeType* node = new nodeType;
    node->priority = _priority;
    node->data = _data;
    size_t id = 0;
    if(++items > SIZE_Q){
        std::cout << "Queue is full! Item " << "[" << node->priority << ", " << node->data << "] not included!" << std::endl;
        items = 10;
    } else{
        for(id = head; id < items; id++){
            if(arr[id] == nullptr){
                arr[id] = node;
                tail++;
                break;
            }
        }
    }
}

void remove(){
    nodeType* temp = arr[tail - 1];
    if(items == 0) {
        std::cout << "Queue is empty!" << std::endl;
    } else{
        for(size_t i = 0; i < tail; i++){
            if(arr[i] != nullptr) {
                if (arr[i]->priority < temp->priority) {
                    temp = arr[i];
                }
            }
        }
        size_t id = 0;
        while (id < tail){
            if(arr[id] != nullptr){
                if(arr[id]->priority == temp->priority && arr[id]->data == temp->data){
                    std::cout << "Item [" << arr[id]->priority << ", " << arr[id]->data << "] removed!" << std::endl;
                    arr[id] = nullptr;
                    items--;
                    break;
                } else{
                    id++;
                }
            } else{
                id++;
            }

        }

    }
}

void printQ(){
    std::cout << "[ ";
    for (size_t i = 0; i < SIZE_Q; i++) {
        if (arr[i] == nullptr) {
            std::cout << "[*, *] ";
        }
        else {
            std::cout << "[" << arr[i]->priority << ", " << arr[i]->data << "]";
        }
    }
    std::cout << " ]" << std::endl;
}

void lesson9_1(){
       initStruct();
    printQ();
    insert(1, 11);
    insert(1, 22);
    insert(4, 33);
    insert(2, 44);
    insert(3, 55);
    insert(4, 66);
    insert(5, 77);
    insert(1, 88);
    insert(2, 99);
    insert(6, 100);
    insert(7, 98);
    insert(3, 89);
    printQ();
    for(size_t i = 0; i < 7; i++){
        remove();
    }
    printQ();
    insert(1, 111);
    insert(2, 222);
    insert(2, 232);
    insert(1, 121);
    insert(4, 444);
    insert(2, 262);
    insert(5, 555);
    insert(8, 888);
    printQ();
}
//////////////////////////////////////////////////////////////////////////////////////////////////
const int SIZE_ST = 1000;

#define T int
T Stack[SIZE_ST];
int cursor = -1;

bool push(T data){
    if(cursor < SIZE_ST){
        Stack[++cursor] = data;
        return true;
    }else{
        std::cout << "(push) Stack overflow" << std::endl;
        return false;
    }
}

T pop(){
    if(cursor != -1){
        return Stack[cursor--];
    }else{
        std::cout << "(pop) Stack overflow" << std::endl;
        return false;
    }
}

void DecToBin(size_t n) {
    if (n > 1) {
        DecToBin(n / 2);
    }
    std::cout << n % 2;
}

void lesson9_2(){
    int pushToStack = 0;
    while(1){
        std::cout << "Enter number(-1 to exit): " << std::endl;
        std::cin >> pushToStack;
        if(pushToStack == -1) break;
        push(pushToStack);
    }

    while(cursor != -1){
        int temp = pop();
        std::cout << temp << " in dec = ";
        DecToBin(temp);
        std::cout << " in bin"<< std::endl;
    }
}


int main()
{
    lesson9_1();
    
    lesson9_2();

    return 0;
}
