#pragma once
#include "../dominio/Paciente.h"

class NodoPacienteServicio {
private:
    Paciente* paciente;
    NodoPacienteServicio* siguiente;

public:
    NodoPacienteServicio(Paciente* paciente);
    ~NodoPacienteServicio();

    Paciente* getPaciente() const;
    NodoPacienteServicio* getSiguiente() const;
    void setSiguiente(NodoPacienteServicio* siguiente);
};