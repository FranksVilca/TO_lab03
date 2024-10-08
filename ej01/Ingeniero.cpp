#include "Ingeniero.h"

Ingeniero::Ingeniero(string n, int anios) : nombre(n), aniosExperiencia(anios) {}

void Ingeniero::mostrarInfo()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Años de experiencia: " << aniosExperiencia << endl;
}
