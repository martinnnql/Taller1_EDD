#include "NodoPacienteServicio.h"

NodoPacienteServicio::NodoPacienteServicio(Paciente* paciente) {
    this->paciente = paciente;
    this->siguiente = nullptr;
}
NodoPacienteServicio::~NodoPacienteServicio() {}
Paciente* NodoPacienteServicio::getPaciente() const { return this->paciente; }
NodoPacienteServicio* NodoPacienteServicio::getSiguiente() const { return this->siguiente; }
void NodoPacienteServicio::setSiguiente(NodoPacienteServicio* siguiente) { this->siguiente = siguiente; }