#pragma once
#include <string>
#include <iostream>
#include "NodoServicio.h"
using namespace std;

class HospitalListaPrincipal {
private:
    NodoServicio* inicioServicios;

public:
    HospitalListaPrincipal();
    ~HospitalListaPrincipal();

    void derivarPaciente(string nombreServicio, Paciente* paciente);
    void mostrarPacientesDeUnServicio(string nombreServicio) const;
};