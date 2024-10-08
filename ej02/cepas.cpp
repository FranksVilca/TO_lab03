#include <iostream>
#include <string>

// Clase base que representa una cepa de coronavirus
class CepaCoronaria
{
protected:
    std::string nombre;
    std::string sintomas;
    double tasa_infeccion;

public:
    // Constructor de la clase base
    CepaCoronaria(const std::string &nom, const std::string &symp, double tasa)
        : nombre(nom), sintomas(symp), tasa_infeccion(tasa) {}

    // Método para mostrar información de la cepa
    void mostrarInformacion()
    {
        std::cout << "Nombre de la cepa: " << nombre << std::endl;
        std::cout << "Síntomas: " << sintomas << std::endl;
        std::cout << "Tasa de infección: " << tasa_infeccion * 100 << "%" << std::endl;
    }
};

// Clase derivada que representa la cepa Alpha
class CepaAlpha : public CepaCoronaria
{
public:
    CepaAlpha() : CepaCoronaria("Alpha", "Fiebre, tos seca, fatiga", 0.7) {}
};

// Clase derivada que representa la cepa Beta
class CepaBeta : public CepaCoronaria
{
public:
    CepaBeta() : CepaCoronaria("Beta", "Congestión nasal, tos, pérdida del gusto", 0.9) {}
};

// Clase derivada que representa la cepa Gamma
class CepaGamma : public CepaCoronaria
{
public:
    CepaGamma() : CepaCoronaria("Gamma", "Fiebre, dolores musculares, tos", 0.8) {}
};

// Clase que combina las cepas mediante herencia múltiple
class CepaCompleta : public CepaAlpha, public CepaBeta, public CepaGamma
{
public:
    void mostrarInformacionCompleta()
    {
        std::cout << "Información de las cepas combinadas:" << std::endl;
        CepaAlpha::mostrarInformacion();
        std::cout << std::endl;
        CepaBeta::mostrarInformacion();
        std::cout << std::endl;
        CepaGamma::mostrarInformacion();
    }
};

int main()
{
    // Crear un objeto de la clase CepaCompleta
    CepaCompleta cepa;

    // Mostrar información de todas las cepas
    cepa.mostrarInformacionCompleta();

    return 0;
}
