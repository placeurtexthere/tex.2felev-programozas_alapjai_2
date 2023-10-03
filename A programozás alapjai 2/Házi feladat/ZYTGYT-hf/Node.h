//
// Created by Dave on 2023. 05. 28..
//

#ifndef PROG2_NAGY_HAZI_2ND_TRY_NODE_H
#define PROG2_NAGY_HAZI_2ND_TRY_NODE_H

#include "string"
using namespace std;

class Node {
private:
    Node *right = nullptr;
    Node *left = nullptr; // lehet, hogy pointernek kell lenni, ha valami sz@r van a levesben, akkor ez lehetséges hiba pont
    char c = '\0';
public:
    Node(); // paraméter mentes konstruktor
    Node(char letter); // osztály konstruktor
    ~Node(); // destruktor
    bool addWord(string word); // új szó hozzáadása függvény
    char getChar() const; // a node char adattagját adja vissza
    int search(string word); // megpróbál keresni egy szavat (magyar nyelv not included) a trie-ben és vissza adja hogy hanyadik karakterig találta meg
};

#endif //PROG2_NAGY_HAZI_2ND_TRY_NODE_H
