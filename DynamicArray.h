#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// Klasa DynamicArray implementuje dynamiczn� tablic� z mo�liwo�ci� automatycznego rozszerzania rozmiaru.
class DynamicArray {
private:
    int* data;       // Wska�nik na dynamicznie alokowan� tablic�
    int size;        // Aktualna liczba element�w w tablicy
    int capacity;    // Ca�kowita pojemno�� tablicy

    // Metoda prywatna do dwukrotnego zwi�kszenia pojemno�ci tablicy
    void resize();

public:
    // Konstruktor z mo�liwo�ci� okre�lenia pocz�tkowego rozmiaru (domy�lnie 10)
    DynamicArray(int initialCapacity = 10);

    // Destruktor zwalniaj�cy pami��
    ~DynamicArray();

    // Dodaje element na pocz�tek tablicy
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

    // Wyszukuje element w tablicy, zwraca jego indeks lub -1, je�li nie znaleziono
    int search(int value);

    // Wypisuje zawarto�� tablicy
    void print();
};

#endif

