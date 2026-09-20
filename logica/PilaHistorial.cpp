#include "PilaHistorial.h"

PilaHistorial::PilaHistorial() {
    this->cima = nullptr;
}

PilaHistorial::~PilaHistorial() {
    NodoHistorial* cursor = this->cima;
    while (cursor != nullptr) {
        NodoHistorial* aBorrar = cursor;
        cursor = cursor->getSiguiente();
        delete aBorrar; 
    }
}

void PilaHistorial::agregarAtencion(Paciente* paciente) {
    NodoHistorial* nuevoRegistro = new NodoHistorial(paciente);
    nuevoRegistro->setSiguiente(this->cima);
    this->cima = nuevoRegistro;
}

void PilaHistorial::mostrarHistorial() const {
    if (this->cima == nullptr) {
        cout << "Aun no hay atenciones registradas en el hospital.\n";
        return;
    }

    NodoHistorial* cursor = this->cima;
    cout << "=== HISTORIAL DE ULTIMAS ATENCIONES DEL HOSPITAL ===\n";
    while (cursor != nullptr) {
        cout << "Nombre: " << cursor->getPaciente()->getNombre() 
             << " | Edad: " << cursor->getPaciente()->getEdad() 
             << " | Departamento: " << cursor->getPaciente()->getServicio() << "\n---\n";
        cursor = cursor->getSiguiente();
    }
}