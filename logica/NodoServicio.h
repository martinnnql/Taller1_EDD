#pragma once
#include <string>
#include <iostream>
#include "NodoPacienteServicio.h"
using namespace std;

class NodoServicio {
private:
    string nombreServicio;
    NodoPacienteServicio* primerPaciente;
    NodoServicio* siguienteServicio;

public:
    NodoServicio(string nombre);
    ~NodoServicio();

    string getNombre() const;
    NodoServicio* getSiguienteServicio() const;
    void setSiguienteServicio(NodoServicio* siguiente);

    void agregarPaciente(Paciente* nuevoPaciente);
    void mostrarPacientes() const;
};