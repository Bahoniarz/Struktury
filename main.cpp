#include "DynamicArray.h"
#include "lista_jednokierunkowa.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <fstream>
#include <algorithm>
#include <random> 
using namespace std;
using namespace chrono;

const int iterations = 10;
const int initialSize = 10;
// Zmienna do losowania
random_device rd;
mt19937 gen(rd());  
uniform_int_distribution<> disValue(1, initialSize);  
uniform_int_distribution<> disIndex(0, initialSize-1);  


// Funkcja do zapisu do pliku CSV
void zapiszDoPlikuCSV(const string& opis, long long sredniCzas) {
    ofstream plik("czasy.csv", ios::app);
    if (plik.is_open()) {
        plik << opis << "," << sredniCzas << "\n";
        plik.close();
    }
    else {
        cout << "Nie mozna otworzyc pliku.\n";
    }
}

// === DYNAMIC ARRAY ===
void testDynamicArray() {
    vector<long long> czasy;

    cout << "\n==== DynamicArray ====\n";

    // Dodawanie na koniec
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DynamicArray arr(initialSize);
        for (int j = 0; j < initialSize; ++j) 
            arr.addAtEnd(j);
        auto start = high_resolution_clock::now();
        arr.addAtEnd(disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    long long sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Dodawanie na koniec: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Dodawanie na koniec", sredniCzas);

    // Dodawanie na poczatek
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DynamicArray arr(initialSize);
        for (int j = 0; j < initialSize; ++j)
            arr.addAtEnd(j);
        auto start = high_resolution_clock::now();
        arr.addAtBeginning(disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Dodawanie na poczatek: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Dodawanie na poczatek", sredniCzas);

    // Dodawanie na indeks
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DynamicArray arr(initialSize);
        for (int j = 0; j < initialSize; ++j) 
            arr.addAtEnd(j);
        int losowyIndeks = disIndex(gen);  
        auto start = high_resolution_clock::now();
        arr.addAtIndex(losowyIndeks, disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Dodawanie na indeks: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Dodawanie na indeks", sredniCzas);

    // Usuwanie z konca
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DynamicArray arr(initialSize);
        for (int j = 0; j < initialSize; ++j) 
            arr.addAtEnd(j);
        auto start = high_resolution_clock::now();
        arr.removeAtEnd();
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Usuwanie z konca: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Usuwanie z konca", sredniCzas);

    // Usuwanie z poczatku
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DynamicArray arr(initialSize);
        for (int j = 0; j < initialSize; ++j)
            arr.addAtEnd(j);
        auto start = high_resolution_clock::now();
        arr.removeAtBeginning();
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Usuwanie z poczatku: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Usuwanie z poczatku", sredniCzas);

    // Usuwanie z indeksu
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DynamicArray arr(initialSize);
        for (int j = 0; j < initialSize; ++j)
            arr.addAtEnd(j);
        int losowyIndeks = disIndex(gen);  
        auto start = high_resolution_clock::now();
        arr.removeAtIndex(losowyIndeks);
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Usuwanie z indeksu: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Usuwanie z indeksu", sredniCzas);

    // Wyszukiwanie
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DynamicArray arr(initialSize);
        for (int j = 0; j < initialSize; ++j) 
            arr.addAtEnd(j);
        auto start = high_resolution_clock::now();
        arr.search(disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Wyszukiwanie: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Wyszukiwanie", sredniCzas);
}

// === SINGLY LINKED LIST ===
void testSinglyLinkedList() {
    vector<long long> czasy;

    cout << "\n==== SinglyLinkedList ====\n";

    // Dodawanie na koniec
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        SinglyLinkedList list;
        for (int j = 0; j < initialSize; ++j)
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.addAtEnd(disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    long long sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Dodawanie na koniec: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Dodawanie na koniec", sredniCzas);

    // Dodawanie na poczatek
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        SinglyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.addAtBeginning(disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Dodawanie na poczatek: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Dodawanie na poczatek", sredniCzas);

    // Dodawanie na indeks
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        SinglyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        int losowyIndeks = disIndex(gen); 
        auto start = high_resolution_clock::now();
        list.addAtIndex(losowyIndeks, disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Dodawanie na indeks: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Dodawanie na indeks", sredniCzas);

    // Usuwanie z konca
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        SinglyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.removeAtEnd();
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Usuwanie z konca: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Usuwanie z konca", sredniCzas);

    // Usuwanie z poczatku
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        SinglyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.removeAtBeginning();
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Usuwanie z poczatku: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Usuwanie z poczatku", sredniCzas);

    // Usuwanie z indeksu
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        SinglyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        int losowyIndeks = disIndex(gen);  
        auto start = high_resolution_clock::now();
        list.removeAtIndex(losowyIndeks);
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Usuwanie z indeksu: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Usuwanie z indeksu", sredniCzas);

    // Wyszukiwanie
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        SinglyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.search(disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Wyszukiwanie: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Wyszukiwanie", sredniCzas);
}

// === DOUBLY LINKED LIST ===
void testDoublyLinkedList() {
    vector<long long> czasy;

    cout << "\n==== DoublyLinkedList ====\n";

    // Dodawanie na koniec
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DoublyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.addAtEnd(disValue(gen)); 
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    long long sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Dodawanie na koniec: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Dodawanie na koniec", sredniCzas);

    // Dodawanie na poczatek
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DoublyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.addAtBeginning(disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Dodawanie na poczatek: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Dodawanie na poczatek", sredniCzas);

    // Dodawanie na indeks
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DoublyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        int losowyIndeks = disIndex(gen);  
        auto start = high_resolution_clock::now();
        list.addAtIndex(losowyIndeks, disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Dodawanie na indeks: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Dodawanie na indeks", sredniCzas);

    // Usuwanie z konca
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DoublyLinkedList list;
        for (int j = 0; j < initialSize; ++j)
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.removeAtEnd();
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Usuwanie z konca: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Usuwanie z konca", sredniCzas);

    // Usuwanie z poczatku
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DoublyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.removeAtBeginning();
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Usuwanie z poczatku: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Usuwanie z poczatku", sredniCzas);

    // Usuwanie z indeksu
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DoublyLinkedList list;
        for (int j = 0; j < initialSize; ++j) 
            list.addAtEnd(j);
        int losowyIndeks = disIndex(gen);  
        auto start = high_resolution_clock::now();
        list.removeAtIndex(losowyIndeks);
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Usuwanie z indeksu: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Usuwanie z indeksu", sredniCzas);

    // Wyszukiwanie
    czasy.clear();
    for (int i = 0; i < iterations; ++i) {
        DoublyLinkedList list;
        for (int j = 0; j < initialSize; ++j)
            list.addAtEnd(j);
        auto start = high_resolution_clock::now();
        list.search(disValue(gen));  
        auto stop = high_resolution_clock::now();
        czasy.push_back(duration_cast<nanoseconds>(stop - start).count());
    }
    sredniCzas = accumulate(czasy.begin(), czasy.end(), 0LL) / czasy.size();
    cout << "Wyszukiwanie: " << sredniCzas << " ns (srednio)\n";
    zapiszDoPlikuCSV("Wyszukiwanie", sredniCzas);
}

int main() {
    // Zapisanie nagłówka do pliku CSV
    ofstream plik("czasy.csv", ios::out);
    if (plik.is_open()) {
        plik << "Operacja,Czas (ns)\n";
        plik.close();
    }

    cout << "=== POMIARY CZASU OPERACJI NA STRUKTURACH ===\n";

    testDynamicArray();
    testSinglyLinkedList();
    testDoublyLinkedList();

    return 0;
}
