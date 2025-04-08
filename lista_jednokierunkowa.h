 
#ifndef LISTA_JEDNOKIERUNKOWA_H
#define LISTA_JEDNOKIERUNKOWA_H

class SinglyLinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

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