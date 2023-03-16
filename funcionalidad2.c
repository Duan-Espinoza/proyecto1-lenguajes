#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SITIOS 50
#define MAX_SECTORES 10
#define MAX_ASIENTOS 100

struct Asiento {
    char nombre[MAX_ASIENTOS];
};

struct Sector {
    char nombre[MAX_SECTORES];
    int cantidad;
    char inicial;
    struct Asiento asientos[MAX_ASIENTOS];
};

struct Sitio {
    char nombre[MAX_SITIOS];
    int cantidad_sectores;
    struct Sector sectores[MAX_SECTORES];
};

void agregar_sector(struct Sitio *sitio) {
    if (sitio->cantidad_sectores >= MAX_SECTORES) {
        printf("El sitio ha alcanzado la cantidad máxima de sectores.\n");
        return;
    }

    struct Sector sector;
    printf("Ingrese el nombre del sector: ");
    scanf("%s", sector.nombre);
    printf("Ingrese la cantidad de espacios: ");
    scanf("%d", &sector.cantidad);
    printf("Ingrese la inicial (carácter alfabético) de los asientos: ");
    scanf(" %c", &sector.inicial);

    for (int i = 0; i < sector.cantidad; i++) {
        sprintf(sector.asientos[i].nombre, "%c%d", sector.inicial, i+1);
    }

    sitio->sectores[sitio->cantidad_sectores++] = sector;
    printf("El sector ha sido agregado con éxito.\n");
}

void reset_espacios(struct Sitio *sitio) {
    for (int i = 0; i < sitio->cantidad_sectores; i++) {
        for (int j = 0; j < sitio->sectores[i].cantidad; j++) {
            strcpy(sitio->sectores[i].asientos[j].nombre, "");
        }
    }
    printf("Los espacios del sitio han sido reseteados con éxito.\n");
}

void mostrar_sitios(struct Sitio *sitios, int cantidad_sitios) {
    for (int i = 0; i < cantidad_sitios; i++) {
        printf("Sitio: %s\n", sitios[i].nombre);
        for (int j = 0; j < sitios[i].cantidad_sectores; j++) {
            printf("\tSector: %s - Cantidad de espacios: %d\n", sitios[i].sectores[j].nombre, sitios[i].sectores[j].cantidad);
            printf("\t\tAsientos: ");
            for (int k = 0; k < sitios[i].sectores[j].cantidad; k++) {
                printf("%s ", sitios[i].sectores[j].asientos[k].nombre);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    struct Sitio sitios[MAX_SITIOS];
    int cantidad_sitios = 0;

    while (1) {
        printf("Bienvenido al sistema de gestión de espacios de sitios de eventos.\n");
        printf("1. Agregar sitio\n");
        printf("2. Agregar sector\n");
        printf("3. Resetear espacios de sitio\n");
        printf("4. Mostrar sitios\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");

        int opcion;
        scanf("%d", &opcion);

        /**switch (opcion) {
            case 1:
                if (

        */

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del sitio: ");
                scanf("%s", &sitios[cantidad_sitios].nombre);
                printf("Ingrese el nombre del sector: ");
                scanf("%s", &sitios[cantidad_sitios].sectores[cantidad_sitios].nombre);
                printf("Ingrese la cantidad de asientos: ");
                

        }

    }

    return 0;
}
