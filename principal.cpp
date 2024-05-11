#include <iostream>
#include <string>
using namespace std;

// Función para agregar un recurso al sistema
int agregarRecurso(int recurso) {
    cout << "Ingresar número del recurso: ";
    cin >> recurso;
    cout << "Se agregó correctamente el recurso número " << recurso << endl;
    return recurso;
}

// Función para agregar un estudiante al sistema
int agregarEstudiante(int& id, string& estudiante) {
    cout << "Ingresar ID del estudiante: ";
    cin >> id;
    cout << "Ingresar código del estudiante: ";
    cin >> estudiante;
    cout << "Se agregó correctamente el estudiante con ID " << id << " y código " << estudiante << endl;
    return id;
}

// Función principal del programa
int main() {
    int op, recurso, id;
    string estudiante;

    cout << "Bienvenido a la central de préstamos de la Universidad" << endl;

    while (op != 7) {
        cout << "\nIngresa una opción:\n"
             << "1) Agregar un recurso\n"
             << "2) Agregar un estudiante\n"
             << "3) Prestar un recurso disponible\n"
             << "4) Consultar los préstamos de un estudiante\n"
             << "5) Consultar la información de un préstamo\n"
             << "6) Devolver un recurso prestado\n"
             << "7) Salir\n";
        cin >> op;

        if (op == 1) {
            recurso = agregarRecurso(recurso);
        } else if (op == 2) {
            id = agregarEstudiante(id, estudiante);
        } else if (op == 7) {
            cout << "Gracias por utilizar la Central de préstamos" << endl;
        } else {
            cout << "Ingresa una opción válida" << endl;
        }
    }

    return 0;
}
