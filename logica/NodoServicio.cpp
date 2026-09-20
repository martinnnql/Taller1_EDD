#include "NodoServicio.h"

NodoServicio::NodoServicio(string nombre) {
    this->nombreServicio = nombre;
    this->primerPaciente = nullptr;
    this->siguienteServicio = nullptr;
}

NodoServicio::~NodoServicio() {
    NodoPacienteServicio* cursor = this->primerPaciente;
    while (cursor != nullptr) {
        NodoPacienteServicio* aBorrar = cursor;
        cursor = cursor->getSiguiente();
        delete aBorrar->getPaciente(); 
        delete aBorrar;                
    }
}

string NodoServicio::getNombre() const { return this->nombreServicio; }
NodoServicio* NodoServicio::getSiguienteServicio() const { return this->siguienteServicio; }
void NodoServicio::setSiguienteServicio(NodoServicio* siguiente) { this->siguienteServicio = siguiente; }

void NodoServicio::agregarPaciente(Paciente* nuevoPaciente) {
    NodoPacienteServicio* nuevoNodo = new NodoPacienteServicio(nuevoPaciente);
    if (this->primerPaciente == nullptr) {
        this->primerPaciente = nuevoNodo;
    } else {
        NodoPacienteServicio* cursor = this->primerPaciente;
        while (cursor->getSiguiente() != nullptr) {
            cursor = cursor->getSiguiente();
        }
        cursor->setSiguiente(nuevoNodo);
    }
}

void NodoServicio::mostrarPacientes() const {
    if (this->primerPaciente == nullptr) {
        cout << "No hay pacientes en este departamento.\n";
        return;
    }
    NodoPacienteServicio* cursor = this->primerPaciente;
    int i = 1;
    while (cursor != nullptr) {
        cout << i << ". " << cursor->getPaciente()->getNombre() 
             << " (" << cursor->getPaciente()->getEdad() << ")\n";
        cursor = cursor->getSiguiente();
        i++;
    }
}