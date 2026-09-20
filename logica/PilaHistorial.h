#pragma once
#include <iostream>
#include "NodoHistorial.h"
using namespace std;

class PilaHistorial {
private:
    NodoHistorial* cima;

public:
    PilaHistorial();
    ~PilaHistorial();

    void agregarAtencion(Paciente* paciente);
    void mostrarHistorial() const;
};