#ifndef INGENIERO_H
#define INGENIERO_H

#include <string>
#include <iostream>

using namespace std;

// Clase base
class Ingeniero
{
protected:
    string nombre;
    int aniosExperiencia;

public:
    Ingeniero(string n, int anios);
    void mostrarInfo();
};

#endif // INGENIERO_H
