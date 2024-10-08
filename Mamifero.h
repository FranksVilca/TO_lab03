#ifndef MAMIFERO_H
#define MAMIFERO_H

#include <iostream>
using namespace std;

class Mamifero
{
public:
    Mamifero() { cout << "mamifero constructor...\n"; }
    ~Mamifero() { cout << "mamifero destructor...\n"; }
    void Move() const { cout << "mamifero move one step\n"; }
    virtual void Speak() const { cout << "mamifero speak!\n"; }
};

class Dog : public Mamifero
{
public:
    Dog() { cout << "Dog Constructor...\n"; }
    ~Dog() { cout << "Dog destructor...\n"; }
    void WagTail() { cout << "Wagging Tail...\n"; }
    void Speak() const { cout << "Woof!\n"; }
    void Move() const { cout << "Dog moves 5 steps...\n"; }
};

// Declaración de la variable global
extern int edad;

#endif // MAMIFERO_H
