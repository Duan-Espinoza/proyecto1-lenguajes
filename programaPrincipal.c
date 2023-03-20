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



/////////////////funciones de menú operativo////////////////////////
int gestionSitiosEventos(){
    printf("---------------------------------------------\n");
    printf("********Gestion de Sitios de eventos*********\n");
    return 0;
};
          
int gestionEspaciosSitiosEventos(){
    printf("---------------------------------------------\n");
    printf("*****Gestion de espacios sitio de eventos*****\n");
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


