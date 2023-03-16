/**
 * Este código define dos estructuras, una para almacenar los 
 * detalles de un evento y otra para almacenar los detalles de un sitio. 
 * La función crear_evento() toma un puntero a una estruct
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los detalles de un evento
struct Evento {
    char nombre[50];
    char productora[50];
    char fecha[20];
    char sitio[50];
    int num_sectores;
    float* precios_sectores;
};

// Estructura para almacenar los detalles de un sitio
struct Sitio {
    char nombre[50];
    int num_sectores;
    char** nombres_sectores;
};

// Función para crear un nuevo evento
void crear_evento(struct Evento* evento, struct Sitio* sitio) {
    printf("Introduzca el nombre del evento: ");
    scanf("%s", evento->nombre);
    printf("Introduzca el nombre de la productora: ");
    scanf("%s", evento->productora);
    printf("Introduzca la fecha del evento: ");
    scanf("%s", evento->fecha);
    printf("Seleccione el sitio del evento:\n");
    printf("Sitio\t\t\t\tSectores\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < sitio->num_sectores; i++) {
        printf("%-30s\t%d\n", sitio->nombres_sectores[i], i+1);
    }
    printf("------------------------------------------------\n");
    printf("Introduzca el nombre del sitio seleccionado: ");
    scanf("%s", evento->sitio);
    printf("Introduzca el número de sectores para el sitio seleccionado: ");
    scanf("%d", &evento->num_sectores);
    evento->precios_sectores = (float*)malloc(evento->num_sectores * sizeof(float));
    for (int i = 0; i < evento->num_sectores; i++) {
        printf("Introduzca el precio para el sector %d: ", i+1);
        scanf("%f", &evento->precios_sectores[i]);
    }
}

// Función para imprimir los detalles de un evento
void imprimir_evento(struct Evento evento) {
    printf("Nombre del evento: %s\n", evento.nombre);
    printf("Productora: %s\n", evento.productora);
    printf("Fecha del evento: %s\n", evento.fecha);
    printf("Sitio seleccionado: %s\n", evento.sitio);
    printf("Precios por sector:\n");
    for (int i = 0; i < evento.num_sectores; i++) {
        printf("%d: $%.2f\n", i+1, evento.precios_sectores[i]);
    }
}

// Función principal
int main() {
    struct Sitio sitio = {
        "Estadio Nacional",
        5,
        (char*[]){"Galería Norte", "Galería Sur", "Tribuna Este", "Tribuna Oeste", "Cancha"}
    };
    struct Evento evento;
    crear_evento(&evento, &sitio);
    imprimir_evento(evento);
    free(evento.precios_sectores);
    return 0;
}
