#include <iostream>
#include <sstream>
#include <stack>
#include <cctype>

using namespace std;

// Clase base Nodo
class Nodo {
public:
    virtual int evaluar() = 0;  // Método virtual puro para evaluar la expresión
    virtual ~Nodo() {}
};

// Clase NodoValor, que representa un número
class NodoValor : public Nodo {
private:
    int valor;

public:
    NodoValor(int v) : valor(v) {}

    // Implementación del método evaluar para un nodo de valor
    int evaluar() override {
        return valor;
    }
};

// Clase NodoOperacion, que representa una operación (suma o multiplicación)
class NodoOperacion : public Nodo {
private:
    char operacion;  // Puede ser '+' o '*'
    Nodo* izquierda;
    Nodo* derecha;

public:
    NodoOperacion(char op, Nodo* izq, Nodo* der) 
        : operacion(op), izquierda(izq), derecha(der) {}

    // Implementación del método evaluar para un nodo de operación
    int evaluar() override {
        int valIzq = izquierda->evaluar();
        int valDer = derecha->evaluar();

        if (operacion == '+')
            return valIzq + valDer;
        else if (operacion == '*')
            return valIzq * valDer;
        else
            throw invalid_argument("Operación no soportada");
    }

    // Destructor para liberar memoria
    ~NodoOperacion() {
        delete izquierda;
        delete derecha;
    }
};

// Función para parsear y construir el árbol de expresión
Nodo* parsearExpresion(const string& expresion) {
    stack<Nodo*> valores; // Stack para los valores (nodos)
    stack<char> operadores; // Stack para los operadores

    for (size_t i = 0; i < expresion.size(); ++i) {
        char token = expresion[i];

        if (isdigit(token)) {
            // Convertir el dígito a un nodo de valor
            valores.push(new NodoValor(token - '0'));
        } 
        else if (token == '+' || token == '*') {
            // Manejo de precedencia
            while (!operadores.empty() && 
                  ((token == '+' && operadores.top() == '*') || operadores.top() == token)) {
                char op = operadores.top(); operadores.pop();
                Nodo* derecha = valores.top(); valores.pop();
                Nodo* izquierda = valores.top(); valores.pop();
                valores.push(new NodoOperacion(op, izquierda, derecha));
            }
            operadores.push(token);
        }
    }

    // Procesar cualquier operador restante
    while (!operadores.empty()) {
        char op = operadores.top(); operadores.pop();
        Nodo* derecha = valores.top(); valores.pop();
        Nodo* izquierda = valores.top(); valores.pop();
        valores.push(new NodoOperacion(op, izquierda, derecha));
    }

    return valores.top();
}

int main() {
    string expresion;
    cout << "Introduce una expresión matemática simple (solo + y *), por ejemplo: 3+5*2\n";
    getline(cin, expresion);  // Leer la expresión del usuario

    try {
        // Construir el árbol de expresión
        Nodo* arbol = parsearExpresion(expresion);

        // Evaluar la expresión
        cout << "El resultado de la expresión es: " << arbol->evaluar() << endl;

        // Liberar memoria
        delete arbol;
    } catch (const exception& e) {
        cerr << "Error al procesar la expresión: " << e.what() << endl;
    }

    return 0;
}

