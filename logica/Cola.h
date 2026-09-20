#pragma once
#include <iostream>
#include "Nodo.h"
using namespace std;

class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    Cola();
    ~Cola();

    bool estaVacia() const;
    void encolar(Paciente* paciente);
    Paciente* desencolar();
    void mostrarCola() const;
};