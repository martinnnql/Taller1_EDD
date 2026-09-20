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
