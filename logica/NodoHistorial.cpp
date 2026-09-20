#include "NodoHistorial.h"

NodoHistorial::NodoHistorial(Paciente* paciente) {
    this->paciente = paciente;
    this->siguiente = nullptr;
}

NodoHistorial::~NodoHistorial() {}

Paciente* NodoHistorial::getPaciente() const { return this->paciente; }
NodoHistorial* NodoHistorial::getSiguiente() const { return this->siguiente; }
void NodoHistorial::setSiguiente(NodoHistorial* siguiente) { this->siguiente = siguiente; }