#ifndef INGENIERO_SOFTWARE_H
#define INGENIERO_SOFTWARE_H

#include "Ingeniero.h"

// Clase derivada IngenieroSoftware
class IngenieroSoftware : public Ingeniero
{
public:
    IngenieroSoftware(string n, int anios);
    void realizarPruebas();
};

#endif // INGENIERO_SOFTWARE_H
