/**
 * Este programa define una estructura llamada Evento que contiene toda la información del evento, 
 * incluyendo los precios por asiento, los asientos vendidos y la recaudación por sector. 
 * La función mostrar_sector muestra la información de un sector en particular, incluyendo el estado de cada asiento. 
 * La función main define un evento de ejemplo y 
 * luego muestra su información y la información de cada uno de sus sectores usando la función mostrar_sector.
*/


#include <stdio.h>
#include <string.h>

// Definición de la estructura Evento
struct Evento {
    char nombre[50];
    char productora[50];
    char sitio[50];
    char fecha[20];
    int num_sectores;
    float precios[10];
    int asientos[10];
    float recaudacion[10];
};

// Función para mostrar el estado de un sector
void mostrar_sector(int sector, float precio, int asientos[], float recaudacion[]) {
    printf("Sector %d\n", sector);
    printf("Monto por asiento: %.2f\n", precio);
    printf("Monto recaudado: %.2f\n", recaudacion[sector]);
    printf("Estado de asientos:\n");
    for (int i = 0; i < 10; i++) {
        printf("Asiento %d: %s\n", i+1, asientos[i] ? "vendido" : "disponible");
    }
}

int main() {
    // Definición de un evento de ejemplo
    struct Evento evento;
    strcpy(evento.nombre, "Concierto de rock");
    strcpy(evento.productora, "Rock Company");
    strcpy(evento.sitio, "Estadio Nacional");
    strcpy(evento.fecha, "15/04/2023");
    evento.num_sectores = 2;
    evento.precios[0] = 25.0;
    evento.precios[1] = 20.0;
    for (int i = 0; i < 10; i++) {
        evento.asientos[i] = 0;
        evento.recaudacion[0] = 0.0;
        evento.recaudacion[1] = 0.0;
    }

    // Mostrar la información del evento
    printf("Nombre del evento: %s\n", evento.nombre);
    printf("Productora: %s\n", evento.productora);
    printf("Sitio de evento: %s\n", evento.sitio);
    printf("Fecha: %s\n", evento.fecha);

    // Mostrar la información de los sectores
    for (int i = 0; i < evento.num_sectores; i++) {
        mostrar_sector(i, evento.precios[i], evento.asientos, evento.recaudacion);
    }

    return 0;
}
