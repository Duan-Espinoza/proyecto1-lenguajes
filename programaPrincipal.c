//Instituto tecnológico de Costa Rica
//Profesor: Allan Rodríguez Dávila
//Estudiantes:
//Duan Antonio Espinoza - 2019079490
//Jordano Escalante - 2018161994
//Proyecto 1 lenguajes de programación
//Venta de boletos

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

#define MAX_SITIOS 1000
#define MAX_NOMBRE 50
#define MAX_UBICACION 50
#define MAX_SITIO_WEB 50

#define MAX_SITIOS2 50
#define MAX_SECTORES 10
#define MAX_ASIENTOS 100

//Estructuras de datos a utilizar



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
    char nombre[MAX_NOMBRE];
    char ubicacion[MAX_UBICACION];
    char sitio_web[MAX_SITIO_WEB];
    int cantidad_sectores;
    struct Sector sectores[MAX_SECTORES];
};

//listas de elementos a utilizar

struct Sitio sitios[MAX_SITIOS];
int num_sitios = 0;

/**
 
struct Sitios sitios[MAX_SITIOS2];
    int cantidad_sitios = 0;



*/


//////////////////////////////////////////funcionalidades 1//////////////////////////////////////////////


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
    int retorno=0;
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
};

//////////////////////////////funcionalidades 2/////////////////////////////////

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


//////////////////////////////funcionalidades 3/////////////////////////////////

// Función para crear un nuevo evento

/**

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


*/





///////////Funcionalidades 4////////////////
/**
 * 
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

*/




/////////////////funciones de menú operativo////////////////////////
int agregarSitios(){
    char nombre [50];
    char ubicacion[50];
    char web[50];
    printf("---------------------------------------------\n");
    printf("Ingrese el nombre: ");
    scanf("%c",&nombre);

    printf("Ingrese la ubicacion: ");
    scanf("%c",&ubicacion);

    printf("Ingrese el sitio web");
    scanf("%c",&web);

    printf("\n");
    
    //funcionalidad1.h
    agregar_sitio(nombre,ubicacion,web);
    return 0;
};

int agregarSitiosLote(){
    char ruta[100];
    printf("---------------------------------------------\n");
    printf("Ingrese la ruta donde se ecneuntra el archivo: ");
    scanf("%c",&ruta);
    printf("\n");
    agregar_sitios_desde_archivo(ruta);
    return 0;
};

int gestionSitiosEventos(){
    bool volver=false;
    int opcion;
    while (volver!=true){
        printf("---------------------------------------------\n");
        printf("********Gestion de Sitios de eventos*********\n");
        printf("\n");
        printf("1. Agregar sitios de eventos\n");
        printf("2. Agregar sitios de eventos por lote\n");
        printf("3. Volver\n");
        printf("Seleccione una opción: ");
        scanf("%d",&opcion);
    
    //evaluando las opciones del usuario
    switch (opcion)
    {
        case 1:
            agregarSitios();
            break;
        case 2:
            agregarSitiosLote();            
            break;
        case 3:
            printf("Volviendo\n");
            Sleep(1000);
            volver=true;
            break;
        default:
            printf("Opcion no valida\n");
            Sleep(1000);
    }
    }
    opciones_operativas();
    return 0;
};
          
int gestionEspaciosSitiosEventos(){
    bool volver=false;
    int opcion;
    while (volver!=true){
        printf("---------------------------------------------\n");
        printf("***Gestion de espacios sitio de eventos*****\n");
        printf("\n");        
        printf("1. Agregar sector a un sitio de eventos\n");
        printf("2. Resetear Espacios\n");
        printf("3. Mostrar Sitios\n");
        printf("4. Volver\n");
        printf("Seleccione una opción: ");
        scanf("%d",&opcion);
    
    //evaluando las opciones del usuario
    switch (opcion)
    {
        case 1:
            agregarSitios();
            break;
        case 2:
            agregarSitiosLote();            
            break;
        case 3:
            agregarSitiosLote();            
            break;
        case 4:
            printf("Volviendo\n");
            Sleep(1000);
            volver=true;
            break;
        default:
            printf("Opcion no valida\n");
            Sleep(1000);
    }
    }
    opciones_operativas();
    return 0;
};
          
int gestionEventos(){
    printf("---------------------------------------------\n");
    printf("*************Gestion de eventos*************\n");
    return 0;
};
           
int estadoEvento(){
    printf("---------------------------------------------\n");
    printf("**************Estado de evento***************\n");
    return 0;
};
           
int listaFacturas(){
    printf("---------------------------------------------\n");
    printf("**************Lista de Facturas**************\n");
    return 0;
};
            
int estadisticas(){
    printf("---------------------------------------------\n");
    printf("*****************Estadisticas***************\n");
    return 0;
};

//menu operativo
int opciones_operativas(){
    bool volver=false;
    int opcion;
    while (volver!=true){
        printf("---------------------------------------------\n");
        printf("*************Opciones operativas*************\n");
        printf("\n");
        printf("1.Gestion de sitios de eventos\n");
        printf("2.Gestion de espacios sitios de eventos\n");
        printf("3.Gestion de eventos\n");
        printf("4.Estado de evento\n");
        printf("5.Lista de Facturas\n");
        printf("6.Estadisticas\n");
        printf("7.Volver\n");
        printf("\n");
        printf("Digite la opcion que desea: ");
        scanf("%d",&opcion);
    
    //evaluando las opciones del usuario
    switch (opcion)
    {
        case 1:
            gestionSitiosEventos();
            break;
        case 2:
            gestionEspaciosSitiosEventos();
            break;
        case 3:
            gestionEventos();
            break;
        case 4:
            estadoEvento();
            break;
        case 5:
            listaFacturas();
            break;
        case 6:
            estadisticas();
            break;
        case 7:
            printf("Volviendo\n");
            Sleep(1000);
            volver=true;
            break;
        default:
            printf("Opcion no valida\n");
            Sleep(1000);
    }
    }
    menuInicial();
    return 0;
}

///////////////funciones de menu general//////////////
int consultaEvento(){
    printf("---------------------------------------------\n");
    printf("*************Consulta por evento*************\n");
    return 0;
};
int compraBoleto(){
    printf("---------------------------------------------\n");
    printf("*************Compra de boleto*************\n");
    return 0;
};

//menu general
int opciones_generales(){
    bool volver=false;
    int opcion;
    while (volver!=true){
    printf("---------------------------------------------\n");
    printf("*************Opciones generales*************\n");
    printf("\n");
    printf("1.Consulta por evento\n");
    printf("2.Compra de boleto\n");
    printf("3.Volver\n");
    printf("\n");
    printf("Digite la opcion que desea: ");
    scanf("%d",&opcion);
    
    //evaluando las opciones del usuario
    switch (opcion)
    {
        case 1:
            consultaEvento();
            break;
        case 2:
            compraBoleto();
            break;
        case 3:
            printf("Volviendo\n");
            Sleep(1000);
            volver=true;
            break;
        default:
            printf("Opcion no valida\n");
            Sleep(1000);
    }
    }
    menuInicial();
    return 0;
}

//Menu con opciones operativas y generales
int menuInicial(){   
    /* codigo del primer menu del programa */

    bool salir=false;
    int opcion;
    while (salir!=true){
    /* opciones del menu inicial */
    printf("-------------------------------\n");
    printf("*********Mneu inicial********\n");
    printf("\n");
    printf("1.Opciones Operativas\n");
    printf("2.Opciones Generales\n");
    printf("3.Salir\n");
    printf("\n");
    printf("Digite la opcion que desea: ");
    scanf("%d",&opcion);
    printf("\n");

    switch (opcion)
    {
        case 1:
            opciones_operativas();
            break;
        case 2:
            opciones_generales();
            break;
        case 3:
            printf("Hasta luego");
            Sleep(2000);
            salir=true;
            break;
        default:
            printf("Opcion no valida\n");
            Sleep(1000);
    }
    }
    return 0;
}
//iniciador
int main(int argc, char const *argv[]){
    menuInicial();
    return 0;
}


