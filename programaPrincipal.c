//Instituto tecnológico de Costa Rica
//Profesor: Allan Rodríguez Dávila
//Estudiantes:
//Duan Antonio Espinoza - 2019079490
//Jordano Escalante
//Proyecto 1 lenguajes de programación
//Venta de boletos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


//Menu con opciones operativas y generales

int main(int argc, char const *argv[])
{
    /* code */
    int opcion;
    printf("1.Opciones Operativas");
    printf("2.Opciones Generales");
    printf("3.Salir");
    scanf("Digite la opción que desea:", &opcion);
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
            break;
        default:
            printf("Opcion no valida");

        
    }
    



    return 0;
}


