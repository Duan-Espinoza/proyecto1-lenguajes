/**
 * Este programa tiene las siguientes características:

Se define una estructura Sitio con los campos nombre, ubicacion y sitio_web.
Se define un arreglo sitios de estructuras Sitio para almacenar los sitios de eventos.
Se define una variable num_sitios para llevar la cuenta de la cantidad de sitios almacenados en el arreglo.
La función agregar_sitio recibe como parámetros el nombre, la ubicacion y el sitio_web de un sitio de eventos y lo agrega al
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SITIOS 1000
#define MAX_NOMBRE 50
#define MAX_UBICACION 50
#define MAX_SITIO_WEB 50

//Estructuras de datos a utilizar

struct Sitio {
    char nombre[MAX_NOMBRE];
    char ubicacion[MAX_UBICACION];
    char sitio_web[MAX_SITIO_WEB];
};

struct Sitio sitios[MAX_SITIOS];
int num_sitios = 0;


/**
 * Agregar_sitio
 * @param nombre
 * @param ubicacion
 * @param sitio_web
 *Funcionalidad que agrega un sitio al arreglo de sitios.
 *Se recibe como parámetros el nombre, la ubicacion y el sitio_web de un sitio de eventos.
 *Se crea un nuevo sitio y se agrega al arreglo de sitios.
 * @return
*/

void agregar_sitio(char nombre[], char ubicacion[], char sitio_web[]) {
    if (num_sitios >= MAX_SITIOS) {
        printf("No se pueden agregar más sitios de eventos.\n");
        return;
    }

    for (int i = 0; i < num_sitios; i++) {
        if (strcmp(sitios[i].nombre, nombre) == 0) {
            printf("Ya existe un sitio con ese nombre.\n");
            return;
        }
    }

    strcpy(sitios[num_sitios].nombre, nombre);
    strcpy(sitios[num_sitios].ubicacion, ubicacion);
    strcpy(sitios[num_sitios].sitio_web, sitio_web);
    num_sitios++;

    printf("Sitio agregado correctamente.\n");
}

void agregar_sitios_desde_archivo(char ruta[]) {
    FILE* archivo = fopen(ruta, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s.\n", ruta);
        return;
    }

    char linea[150];
    char nombre[MAX_NOMBRE];
    char ubicacion[MAX_UBICACION];
    char sitio_web[MAX_SITIO_WEB];
    while (fgets(linea, 150, archivo)) {
        char* token = strtok(linea, ",");
        strcpy(nombre, token);

        token = strtok(NULL, ",");
        if (token != NULL) {
            strcpy(ubicacion, token);
        } else {
            strcpy(ubicacion, "");
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            strcpy(sitio_web, token);
            sitio_web[strlen(sitio_web) - 1] = '\0';  // Eliminar el salto de línea al final
        } else {
            strcpy(sitio_web, "");
        }

        agregar_sitio(nombre, ubicacion, sitio_web);
    }

    fclose(archivo);
}

/**
 * imprimir_sitios()
 * @param ruta
 * imprime los sitios que se encuentran en el archivo
 * @return
 * 
*/
void imprimir_sitios() {
    printf("Sitios de eventos:\n");
    for (int i = 0; i < num_sitios; i++) {
        printf(" - %s (%s) %s\n", sitios[i].nombre, sitios[i].ubicacion, sitios[i].sitio_web);
    }
}

//Prueba para visualizar el funcionamiento correcto de la función
int main() {
    agregar_sitios_desde_archivo("sitios.txt");

    imprimir_sitios();

    return 0;
}
