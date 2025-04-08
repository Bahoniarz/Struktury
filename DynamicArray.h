#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// Klasa DynamicArray implementuje dynamiczn¹ tablicê z mo¿liwoœci¹ automatycznego rozszerzania rozmiaru.
class DynamicArray {
private:
    int* data;       // WskaŸnik na dynamicznie alokowan¹ tablicê
    int size;        // Aktualna liczba elementów w tablicy
    int capacity;    // Ca³kowita pojemnoœæ tablicy

    // Metoda prywatna do dwukrotnego zwiêkszenia pojemnoœci tablicy
    void resize();

public:
    // Konstruktor z mo¿liwoœci¹ okreœlenia pocz¹tkowego rozmiaru (domyœlnie 10)
    DynamicArray(int initialCapacity = 10);

    // Destruktor zwalniaj¹cy pamiêæ
    ~DynamicArray();

    // Dodaje element na pocz¹tek tablicy
    void addAtBeginning(int value);

    // Dodaje element na koniec tablicy
    void addAtEnd(int value);

    // Dodaje element na konkretny indeks
    void addAtIndex(int index, int value);

    // Usuwa pierwszy element tablicy
    void removeAtBeginning();

    // Usuwa ostatni element tablicy
    void removeAtEnd();

    // Usuwa element z podanego indeksu
    void removeAtIndex(int index);

    // Wyszukuje element w tablicy, zwraca jego indeks lub -1, jeœli nie znaleziono
    int search(int value);

    // Wypisuje zawartoœæ tablicy
    void print();
};

#endif

