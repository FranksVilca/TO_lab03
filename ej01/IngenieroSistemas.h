#ifndef INGENIERO_SISTEMAS_H
#define INGENIERO_SISTEMAS_H

#include "Ingeniero.h"

// Clase derivada IngenieroSistemas
class IngenieroSistemas : public Ingeniero
{
public:
    IngenieroSistemas(string n, int anios);
    void desarrollarSoftware();
};

#endif // INGENIERO_SISTEMAS_H
