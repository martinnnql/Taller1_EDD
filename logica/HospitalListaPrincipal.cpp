#include "HospitalListaPrincipal.h"

HospitalListaPrincipal::HospitalListaPrincipal() {
    this->inicioServicios = new NodoServicio("Urgencias");
    NodoServicio* medGen = new NodoServicio("Medicina General");
    NodoServicio* cardio = new NodoServicio("Cardiologia");
    NodoServicio* neuro = new NodoServicio("Neurologia");
    NodoServicio* trauma = new NodoServicio("Traumatologia");
    NodoServicio* cirugia = new NodoServicio("Cirugia");
    NodoServicio* pedia = new NodoServicio("Pediatria");
    NodoServicio* hosp = new NodoServicio("Hospitalizacion");

    // Conectar los servicios para formar la lista principal
    this->inicioServicios->setSiguienteServicio(medGen);
    medGen->setSiguienteServicio(cardio);
    cardio->setSiguienteServicio(neuro);
    neuro->setSiguienteServicio(trauma);
    trauma->setSiguienteServicio(cirugia);
    cirugia->setSiguienteServicio(pedia);
    pedia->setSiguienteServicio(hosp);
}

HospitalListaPrincipal::~HospitalListaPrincipal() {
    NodoServicio* cursor = this->inicioServicios;
    while (cursor != nullptr) {
        NodoServicio* aBorrar = cursor;
        cursor = cursor->getSiguienteServicio();
        // Al eliminar el servicio se invoca automáticamente su destructor
        delete aBorrar; 
    }
}

void HospitalListaPrincipal::derivarPaciente(string nombreServicio, Paciente* paciente) {
    NodoServicio* cursor = this->inicioServicios;
    while (cursor != nullptr) {
        if (cursor->getNombre() == nombreServicio) {
            cursor->agregarPaciente(paciente);
            return;
        }
        cursor = cursor->getSiguienteServicio();
    }
    cout << "Error: El servicio '" << nombreServicio << "' no existe.\n";
}

void HospitalListaPrincipal::mostrarPacientesDeUnServicio(string nombreServicio) const {
    NodoServicio* cursor = this->inicioServicios;
    while (cursor != nullptr) {
        if (cursor->getNombre() == nombreServicio) {
            cursor->mostrarPacientes();
            return;
        }
        cursor = cursor->getSiguienteServicio();
    }
    cout << "Error: El servicio '" << nombreServicio << "' no existe en el hospital.\n";
}