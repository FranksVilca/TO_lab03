#include "IngenieroSistemas.h"

IngenieroSistemas::IngenieroSistemas(string n, int anios) : Ingeniero(n, anios) {}

void IngenieroSistemas::desarrollarSoftware()
{
    cout << nombre << " está desarrollando software." << endl;
}
