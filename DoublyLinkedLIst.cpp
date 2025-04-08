#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::addAtBeginning(int value) {
    Node* newNode = new Node(value, nullptr, head);
    if (head) 
        head->prev = newNode;
    
   head = newNode;
    if (size == 0) 
        tail = newNode;
    size++;
}

void DoublyLinkedList::addAtEnd(int value) {
    Node* newNode = new Node(value, tail, nullptr);
    if (tail) 
        tail->next = newNode;
    else 
        head = newNode;
    tail = newNode;
    size++;
}

void DoublyLinkedList::addAtIndex(int index, int value) {
    if (index < 0 || index > size) return;
    if (index == 0) {
        addAtBeginning(value);
    }
    else if (index == size) {
        addAtEnd(value);
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        Node* newNode = new Node(value, current->prev, current);
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
    }
}

void DoublyLinkedList::removeAtBeginning() {
    if (!head) 
        return;
    Node* temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else 
        tail = nullptr;
    delete temp;
    size--;
}

void DoublyLinkedList::removeAtEnd() {
    if (!tail)
        return;
    Node* temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp;
    size--;
}


void DoublyLinkedList::removeAtIndex(int index) {
    if (index < 0 || index >= size) return;
    if (index == 0) {
        removeAtBeginning();
    }
    else if (index == size - 1) {
        removeAtEnd();
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
}

int DoublyLinkedList::search(int value) const {
    Node* current = head;
    int index = 0;
    while (current) {
        if (current->value == value) return index;
        current = current->next;
        index++;
    }
    return -1;
}

void DoublyLinkedList::display() const {
    Node* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

int DoublyLinkedList::getSize() const {
    return size;
}