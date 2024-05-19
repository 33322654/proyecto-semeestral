#include <iostream>
#include <string>
using namespace std;

const int MAX_RECURSOS = 100;
const int MAX_ESTUDIANTES = 100;

struct Recurso {
    int numero;
    bool disponible;
};

struct Estudiante {
    int id;
    string codigo;
};

struct Prestamo {
    int recurso;
    int estudianteId;
};

Recurso recursos[MAX_RECURSOS];
Estudiante estudiantes[MAX_ESTUDIANTES];
Prestamo prestamos[MAX_RECURSOS];
int numRecursos = 0;
int numEstudiantes = 0;
int numPrestamos = 0;

void agregarRecurso() {
    if (numRecursos >= MAX_RECURSOS) {
        cout << "No se pueden agregar más recursos. Capacidad máxima alcanzada." << endl;
        return;
    }
    Recurso nuevoRecurso;
    cout << "Ingresar número del recurso: ";
    cin >> nuevoRecurso.numero;
    nuevoRecurso.disponible = true;
    recursos[numRecursos++] = nuevoRecurso;
    cout << "Se agregó correctamente el recurso número " << nuevoRecurso.numero << endl;
}

void agregarEstudiante() {
    if (numEstudiantes >= MAX_ESTUDIANTES) {
        cout << "No se pueden agregar más estudiantes. Capacidad máxima alcanzada." << endl;
        return;
    }
    Estudiante nuevoEstudiante;
    cout << "Ingresar ID del estudiante: ";
    cin >> nuevoEstudiante.id;
    cout << "Ingresar código del estudiante: ";
    cin >> nuevoEstudiante.codigo;
    estudiantes[numEstudiantes++] = nuevoEstudiante;
    cout << "Se agregó correctamente el estudiante con ID " << nuevoEstudiante.id << " y código " << nuevoEstudiante.codigo << endl;
}

void prestarRecurso() {
    int numeroRecurso, idEstudiante;
    cout << "Ingresar número del recurso: ";
    cin >> numeroRecurso;
    cout << "Ingresar ID del estudiante: ";
    cin >> idEstudiante;

    bool recursoEncontrado = false;
    bool estudianteEncontrado = false;

    for (int i = 0; i < numRecursos; i++) {
        if (recursos[i].numero == numeroRecurso) {
            recursoEncontrado = true;
            if (recursos[i].disponible) {
                recursos[i].disponible = false;
                prestamos[numPrestamos++] = {numeroRecurso, idEstudiante};
                cout << "Recurso prestado correctamente al estudiante." << endl;
                return;
            } else {
                cout << "El recurso solicitado ya está prestado." << endl;
                return;
            }
        }
    }

    if (!recursoEncontrado) {
        cout << "No se encontró el recurso solicitado." << endl;
    }
}

void consultarPrestamosEstudiante() {
    int idEstudiante;
    cout << "Ingresar ID del estudiante: ";
    cin >> idEstudiante;

    bool estudianteEncontrado = false;
    for (int i = 0; i < numEstudiantes; i++) {
        if (estudiantes[i].id == idEstudiante) {
            estudianteEncontrado = true;
            cout << "Préstamos del estudiante con ID " << idEstudiante << ":" << endl;
            for (int j = 0; j < numPrestamos; j++) {
                if (prestamos[j].estudianteId == idEstudiante) {
                    cout << " - Recurso número " << prestamos[j].recurso << endl;
                }
            }
            break;
        }
    }

    if (!estudianteEncontrado) {
        cout << "No se encontró al estudiante solicitado." << endl;
    }
}

void consultarInformacionPrestamo() {
    int numeroRecurso;
    cout << "Ingresar número del recurso: ";
    cin >> numeroRecurso;

    bool prestamoEncontrado = false;
    for (int i = 0; i < numPrestamos; i++) {
        if (prestamos[i].recurso == numeroRecurso) {
            prestamoEncontrado = true;
            cout << "El recurso número " << numeroRecurso << " está prestado al estudiante con ID " << prestamos[i].estudianteId << endl;
            break;
        }
    }

    if (!prestamoEncontrado) {
        cout << "No se encontró ningún préstamo para el recurso solicitado." << endl;
    }
}

void devolverRecurso() {
    int numeroRecurso;
    cout << "Ingresar número del recurso: ";
    cin >> numeroRecurso;

    bool recursoEncontrado = false;
    for (int i = 0; i < numRecursos; i++) {
        if (recursos[i].numero == numeroRecurso) {
            recursoEncontrado = true;
            if (!recursos[i].disponible) {
                recursos[i].disponible = true;

                for (int j = 0; j < numPrestamos; j++) {
                    if (prestamos[j].recurso == numeroRecurso) {
                        for (int k = j; k < numPrestamos - 1; k++) {
                            prestamos[k] = prestamos[k + 1];
                        }
                        numPrestamos--;
                        break;
                    }
                }

                cout << "Recurso devuelto correctamente." << endl;
                return;
            } else {
                cout << "El recurso ya estaba disponible." << endl;
                return;
            }
        }
    }

    if (!recursoEncontrado) {
        cout << "No se encontró el recurso solicitado." << endl;
    }
}

int main() {
    cout << "Bienvenido a la central de préstamos de la Universidad" << endl;

    int opcion = 0;
    do {
        cout << "\nIngresa una opción:\n"
             << "1) Agregar un recurso\n"
             << "2) Agregar un estudiante\n"
             << "3) Prestar un recurso disponible\n"
             << "4) Consultar los préstamos de un estudiante\n"
             << "5) Consultar la información de un préstamo\n"
             << "6) Devolver un recurso prestado\n"
             << "7) Salir\n";
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarRecurso();
                break;
            case 2:
                agregarEstudiante();
                break;
            case 3:
                prestarRecurso();
                break;
            case 4:
                consultarPrestamosEstudiante();
                break;
            case 5:
                consultarInformacionPrestamo();
                break;
            case 6:
                devolverRecurso();
                break;
            case 7:
                cout << "Gracias por utilizar la Central de préstamos" << endl;
                break;
            default:
                cout << "Ingresa una opción válida" << endl;
        }
    } while (opcion != 7);

    return 0;
}
