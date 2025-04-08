#include "lista_jednokierunkowa.h"
#include <iostream>

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

void SinglyLinkedList::addAtBeginning(int value) {
    Node* newNode = new Node(value, head);
    head = newNode;
    if (size == 0) tail = newNode;
    size++;
}

void SinglyLinkedList::addAtEnd(int value) {
    Node* newNode = new Node(value);
    if (tail) {
        tail->next = newNode;
        tail = newNode;
    }
    else {
        head = tail = newNode;
    }
    size++;
}

void SinglyLinkedList::addAtIndex(int index, int value) {
    if (index < 0 || index > size) return;
    if (index == 0) {
        addAtBeginning(value);
    }
    else if (index == size) {
        addAtEnd(value);
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* newNode = new Node(value, current->next);
        current->next = newNode;
        size++;
    }
}

void SinglyLinkedList::removeAtBeginning() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
    if (size == 0) tail = nullptr;
}

void SinglyLinkedList::removeAtEnd() {
    if (!head) return;
    if (size == 1) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        current->next = nullptr;
    }
    size--;
}

void SinglyLinkedList::removeAtIndex(int index) {
    if (index < 0 || index >= size) return;
    if (index == 0) {
        removeAtBeginning();
    }   
    else if (index == size - 1) {
        removeAtEnd();
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }
}

int SinglyLinkedList::search(int value) const {
    Node* current = head;
    int index = 0;
    while (current) {
        if (current->value == value) return index;
        current = current->next;
        index++;
    }
    return -1;
}

void SinglyLinkedList::display() const {
    Node* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void SinglyLinkedList::clear() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

int SinglyLinkedList::getSize() const {
    return size;
}