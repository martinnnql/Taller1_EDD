#include "Cola.h"

Cola::Cola() {
    this->frente = nullptr;
    this->final = nullptr;
}

Cola::~Cola() {
    while (!this->estaVacia()) {
        Paciente* p = this->desencolar();
        delete p;
    }
}

bool Cola::estaVacia() const {
    return this->frente == nullptr;
}

void Cola::encolar(Paciente* paciente) {
    Nodo* nuevoVagon = new Nodo(paciente);
    if (this->estaVacia()) {
        this->frente = nuevoVagon;
        this->final = nuevoVagon;
    } else {
        this->final->setSiguiente(nuevoVagon);
        this->final = nuevoVagon;
    }
}

Paciente* Cola::desencolar() {
    if (this->estaVacia()) return nullptr;

    Nodo* vagonAAtender = this->frente;
    Paciente* pacienteAtendido = vagonAAtender->getPaciente();

    this->frente = this->frente->getSiguiente();
    if (this->frente == nullptr) {
        this->final = nullptr;
    }

    delete vagonAAtender; 
    return pacienteAtendido;
}

void Cola::mostrarCola() const {
    if (this->estaVacia()) {
        cout << "No hay pacientes en espera.\n";
        return;
    }
    Nodo* cursor = this->frente;
    int i = 1;
    cout << "=== PACIENTES EN ESPERA ===\n";
    while (cursor != nullptr) {
        cout << i << ". " << cursor->getPaciente()->getId() << " " 
             << cursor->getPaciente()->getNombre() << "\n";
        cursor = cursor->getSiguiente();
        i++;
    }
}