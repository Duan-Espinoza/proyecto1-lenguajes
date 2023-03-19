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

//funciones de menú operativo
int opciones_operativas(){
    printf("entro a opciones operativas");
    Sleep(5000);
    return 0;
}

//funciones de menu general
int opciones_generales(){
    printf("entro a opciones generales");
    Sleep(5000);
    return 0;
}

//Menu con opciones operativas y generales

int main(int argc, char const *argv[])
{   
    /* codigo del primer menu del programa */

    bool salir=false;
    int opcion;
    while (salir!=true){
    /* opciones del menu inicial */
    printf("1.Opciones Operativas\n");
    printf("2.Opciones Generales\n");
    printf("3.Salir\n");
    printf("Digite la opcion que desea: ");
    scanf("%d",&opcion);
    printf("Opcion es: %d",opcion);
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
            Sleep(3000);
            salir=true;
            break;
        default:
            printf("Opcion no valida\n");
            Sleep(5000);
   
    }
    }
    return 0;
}



