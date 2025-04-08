#include "DynamicArray.h"
#include <iostream>

DynamicArray::DynamicArray(int initialCapacity)
    : capacity(initialCapacity), size(0) {
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
}

void DynamicArray::addAtBeginning(int value) {
    if (size == capacity) resize();
    for (int i = size; i > 0; --i)
        data[i] = data[i - 1];
    data[0] = value;
    ++size;
}


void DynamicArray::addAtEnd(int value) {
    if (size == capacity) resize();
    data[size++] = value;
}

void DynamicArray::addAtIndex(int index, int value) {
    if (index < 0 || index > size) return; 
    if (size == capacity) resize();
    for (int i = size; i > index; --i)
        data[i] = data[i - 1];
    data[index] = value;
    ++size;
}


void DynamicArray::removeAtBeginning() {
    if (size == 0) return; 
    for (int i = 0; i < size - 1; ++i)
        data[i] = data[i + 1];
    --size;
}


void DynamicArray::removeAtEnd() {
    if (size == 0) return;
    --size;
}


void DynamicArray::removeAtIndex(int index) {
    if (index < 0 || index >= size) return;
    for (int i = index; i < size - 1; ++i)
        data[i] = data[i + 1];
    --size;
}

int DynamicArray::search(int value) {
    for (int i = 0; i < size; ++i)
        if (data[i] == value)
            return i;
    return -1;
}

void DynamicArray::print() {
    for (int i = 0; i < size; ++i)
        std::cout << data[i] << " ";
    std::cout << "\n";
}

