#pragma once
#include "../dominio/Paciente.h"

class NodoHistorial {
private:
    Paciente* paciente;
    NodoHistorial* siguiente;

public:
    NodoHistorial(Paciente* paciente);
    ~NodoHistorial();

    Paciente* getPaciente() const;
    NodoHistorial* getSiguiente() const;
    void setSiguiente(NodoHistorial* siguiente);
};