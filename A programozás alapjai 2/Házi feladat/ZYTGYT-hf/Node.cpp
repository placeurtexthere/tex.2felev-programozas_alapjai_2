//
// Created by Dave on 2023. 05. 17..
//

#include "iostream"
#include "string"
#include "Node.h"

using namespace std;

Node::Node() {}

Node::Node(char letter) {
    this->c = letter;
}

Node::~Node() {
    delete(this->left);
    delete(this->right);
}

bool Node::addWord(string word) {
    if (word.length() == 0) // ha elfogyott a szó akkor nem kell többet iterálni
            return true; // kilépünk
    bool ret = false;
    char chr = word[0]; // félretesszük a legelső karaktert összehasonlításhoz
    word.erase(0,1); // kitöröljük az előbb félretett karaktert
    if (this->left == nullptr) {
        this->left = new Node(chr); // a left szárnyhoz hozzá adunk egy új node-ot benne a karakterrel
        ret = this->left->addWord(word); // tovább adjuk a szó maradékát az addWord funkciónak
    } else if (this->left->getChar() == chr) {
        ret = this->left->addWord(word); // ha már létezik a betű akkor nem adjuk hozzá mégegyszer és tovább megyünk
    } else if (this->right == nullptr) {
        this->right = new Node(chr); // a left szárnyhoz hozzá adunk egy új node-ot benne a karakterrel
        ret = this->right->addWord(word); // tovább adjuk a szó maradékát az addWord funkciónak
    } else if (this->right->getChar() == chr) {
        ret = this->right->addWord(word); // ha már létezik a betű akkor nem adjuk hozzá mégegyszer és tovább megyünk
    } else {
        ret = false;
    }
    return ret;
}

int Node::search(string word) {
    int found = 0; // számláló a megtalált karaktereknek
    char chr = word[0]; // félretesszük a legelső karaktert összehasonlításhoz
    word.erase(0,1); // kitöröljük az előbb félretett karaktert
    if (this->left == nullptr) {
        found = 0;
    } else if (this->left->getChar() == chr) {
        found = 1 + this->left->search(word); // ha talál egyezést akkor hozzá ad 1 et és tovább adja a következő node-nak a search-öt
    } else if (this->right == nullptr) {
        found = 0;
    } else if (this->right->getChar() == chr) {
        found = 1 + this->right->search(word); // ha talál egyezést akkor hozzá ad 1 et és tovább adja a következő node-nak a search-öt
    }
    return found;
}

char Node::getChar() const {
    return this->c;
}