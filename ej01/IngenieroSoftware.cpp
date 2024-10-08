#include "IngenieroSoftware.h"

IngenieroSoftware::IngenieroSoftware(string n, int anios) : Ingeniero(n, anios) {}

void IngenieroSoftware::realizarPruebas()
{
    cout << nombre << " está realizando pruebas de software." << endl;
}
