#include "IngenieroSistemas.h"
#include "IngenieroSoftware.h"
#include <iostream>

int main()
{
    IngenieroSistemas ingeniero1("Carlos", 5);
    ingeniero1.mostrarInfo();
    ingeniero1.desarrollarSoftware();

    cout << ""
         << endl;
    IngenieroSoftware ingeniero2("Ana", 3);
    ingeniero2.mostrarInfo();
    ingeniero2.realizarPruebas();

    return 0;
}
