//Martin Alonso Arancibia Alzamora | 22.273.853-9 | ICCI
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../dominio/Paciente.h"
#include "../logica/Cola.h"
#include "../logica/PilaHistorial.h"
#include "../logica/HospitalListaPrincipal.h"

using namespace std;



void cargarPacientesDesdeArchivo(string nombreArchivo, Cola& colaEspera) {
    ifstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cout << "Error no se pudo abrir el archivo";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue; 

        stringstream tijera(linea);
        string id, nombre, edadTexto, servicio;

        getline(tijera, id, ';');
        getline(tijera, nombre, ';');
        getline(tijera, edadTexto, ';');
        getline(tijera, servicio, ';');

        if (!nombre.empty() && nombre[0] == ' ') nombre = nombre.substr(1);
        if (!edadTexto.empty() && edadTexto[0] == ' ') edadTexto = edadTexto.substr(1);
        if (!servicio.empty() && servicio[0] == ' ') servicio = servicio.substr(1);
        if (!servicio.empty() && servicio.back() == '\r') servicio.pop_back();

        int edadEntera = 0;
        try {
            edadEntera = stoi(edadTexto);
        } catch (exception& e) {
            continue; 
        }

        Paciente* nuevoPaciente = new Paciente(id, nombre, edadEntera, servicio);
        colaEspera.encolar(nuevoPaciente);
    }
    
    archivo.close();
    cout << "Archivo cargado con exito.";
}

int main() {
    Cola colaEspera;
    PilaHistorial historial;
    HospitalListaPrincipal hospital; 

    cargarPacientesDesdeArchivo("Pacientes.txt", colaEspera);

    int opcion = 0;

    do {
        cout << "=== HOSPITAL MARMAJA ===\n";
        cout << "1. Atender pacientes\n";
        cout << "2. Ver departamento\n";
        cout << "3. Revisar historial de atencion\n";
        cout << "4. Salir\n";
        cout << "Seleccionar opcion: ";
        cin >> opcion;
        cout << "\n";

        if (cin.fail()) {
            cin.clear(); 

            string basura;
            cin >> basura;

            cout << "\nError: Entrada invalida. Por favor, ingrese un numero.\n\n";
            opcion = 0; // Reiniciamos la opción
            continue; 
        }

        switch (opcion) {
            case 1: {
                if (colaEspera.estaVacia()) {
                    cout << "No hay pacientes en espera.\n\n";
                    break;
                }

                colaEspera.mostrarCola();
                
                int cantidad;
                cout << "Indique la cantidad de pacientes a atender: ";
                cin >> cantidad;
                cout << "=== ATENDIENDO PACIENTES ===\n";

                for (int i = 0; i < cantidad; i++) {
                    if (colaEspera.estaVacia()) {
                        cout << "Ya no quedan mas pacientes en la cola.\n";
                        break; 
                    }

                    Paciente* pacienteActual = colaEspera.desencolar();

                    cout << "ID: " << pacienteActual->getId() << "\n";
                    cout << "Nombre: " << pacienteActual->getNombre() << "\n";
                    cout << "Edad: " << pacienteActual->getEdad() << "\n";
                    cout << "Servicio: " << pacienteActual->getServicio() << "\n";

                    hospital.derivarPaciente(pacienteActual->getServicio(), pacienteActual);
                    
                    cout << "Paciente enviado a " << pacienteActual->getServicio() << ".\n\n";

                    historial.agregarAtencion(pacienteActual);
                }
                break;
            }
            case 2: {
                cout << "=== DEPARTAMENTOS/SERVICIOS ===\n";
                cout << "1. Urgencias\n2. Medicina General\n3. Cardiologia\n4. Neurologia\n";
                cout << "5. Traumatologia\n6. Cirugia\n7. Pediatria\n8. Hospitalizacion\n";
                
                int dep;
                cout << "Seleccionar opcion: ";
                cin >> dep;
                
                string nombreServicioBuscado = "";
                if (dep == 1) nombreServicioBuscado = "Urgencias";
                else if (dep == 2) nombreServicioBuscado = "Medicina General";
                else if (dep == 3) nombreServicioBuscado = "Cardiologia";
                else if (dep == 4) nombreServicioBuscado = "Neurologia";
                else if (dep == 5) nombreServicioBuscado = "Traumatologia";
                else if (dep == 6) nombreServicioBuscado = "Cirugia";
                else if (dep == 7) nombreServicioBuscado = "Pediatria";
                else if (dep == 8) nombreServicioBuscado = "Hospitalizacion";

                cout << "\n=== ESTADO " << nombreServicioBuscado << " ===\n";
                hospital.mostrarPacientesDeUnServicio(nombreServicioBuscado);
                cout << "\n";
                break;
            }
            case 3: {
                historial.mostrarHistorial();
                break;
            }
            case 4: {
                cout << "Hasta luego :D.\n";
                break;
            }
            default: {
                cout << "Opcion invalida, intente nuevamente.\n\n";
                break;
            }
        }

    } while (opcion != 4);

    return 0;
}
