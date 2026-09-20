#pragma once
#include "../dominio/Paciente.h"

class Nodo {
private:
    Paciente* paciente;
    Nodo* siguiente;

public:
    Nodo(Paciente* paciente);
    ~Nodo(); // Destructor

    Paciente* getPaciente() const;
    Nodo* getSiguiente() const;
    void setSiguiente(Nodo* siguiente);
};