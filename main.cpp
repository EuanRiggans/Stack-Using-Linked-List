#include <iostream>

struct Node { //Creating the node structure
    int data;
    Node *nextNode;
};

void init(struct Node *&head, int data);

bool isFull(int count, int maxSize);

bool isEmpty(struct Node *head);

void push(struct Node *&head, int &count, int data, int maxSize);

void pop(struct Node *&head, int &count);

void outputLinkedList(struct Node *head);

int main() {
    int maxSize = 20; //Initialising the stack data
    int count = 0;
    auto *head = new Node; //Creating the head of the linked list
    init(head, 0); //Initialising the head of the linked list
    std::cout << "-- Testing Stack --" << std::endl;
    outputLinkedList(head);
    for (int i = 1; i < maxSize; i++) {
        push(head, count, i,
             maxSize); //Pushing the values from 1-19 onto the stack, as 0 is already been initialised as the head of the stack
    }
    outputLinkedList(head);
    for (int i = 1; i < maxSize; i++) {
        pop(head,
            count); //Popping all of the data from 19-1 from the stack, not zero as it will be the head once all the data is popped
    }
    outputLinkedList(head);
    std::cin.get();
    std::cin.ignore();
    return 0;
}

void init(struct Node *&head, int data) { //Initialising the head of the stack
    head->data = data;
    head->nextNode = nullptr;
}

bool isFull(int count, int maxSize) {
    return count >= maxSize;
}

bool isEmpty(struct Node *head) {
    return head->nextNode == nullptr;
}

void push(struct Node *&head, int &count, int data, int maxSize) {
    if (!isFull(count, maxSize)) { //Checking that the stack is not currently full
        auto *nodeToAdd = new Node; //Creating a new temporary node
        nodeToAdd->data = data; //Adding the data to the node
        nodeToAdd->nextNode = head; //Setting the pointer in the new node to be that of the current head
        head = nodeToAdd; //Setting head to be the new node
        count++; //Incrementing the count of the stack
    }
}

void pop(struct Node *&head, int &count) {
    if (!isEmpty(head)) { //Checking that the stack is not currently empty
        struct Node *tempNode = head; //Creating a temporary node to hold the data from the current head
        head = head->nextNode; //Setting head to the node that the current head points to
        delete tempNode; //Deleting the temporary node
        count--; //Decrementing the current count of the stack
    } else {
        std::cout << "There is no data to pop!" << std::endl;
    }
}

void outputLinkedList(struct Node *head) { //Outputting all of the current data in the stack
    Node *currentNode = head; //Creating a temporary node
    std::cout << "Head => " << currentNode->data << " | " << currentNode->nextNode << " => ";
    if (currentNode->nextNode == nullptr) {
        std::cout << "NULL | ";
    }
    while (currentNode->nextNode != nullptr) {
        currentNode = currentNode->nextNode;
        std::cout << currentNode->data << " | " << currentNode->nextNode << " => ";
        if (currentNode->nextNode == nullptr) {
            std::cout << "NULL | ";
        }
    }
    std::cout << "Tail" << std::endl;
    std::cout << std::endl;
}
