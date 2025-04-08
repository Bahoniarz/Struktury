#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

class DoublyLinkedList {
private:
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) : value(val), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addAtBeginning(int value);
    void addAtEnd(int value);
    void addAtIndex(int index, int value);

    void removeAtBeginning();
    void removeAtEnd();
    void removeAtIndex(int index);

    int search(int value) const;
    void display() const;
    void clear();
    int getSize() const;
};

#endif