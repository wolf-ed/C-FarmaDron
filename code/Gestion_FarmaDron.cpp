/***************************************
* NOMBRE: #Ed Wolf#
* EMAIL: #wolf7ed@gmail.com#
* DATE: 12/2020
***************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Paciente.h"
#include "Almacen.h"



int main() {


  char action;
  int indiceAlmacen, inicio;
  ConjuntoAlmacen10 almacenes;

  indiceAlmacen  = 0;
  inicio = 1; //variable iniciar sistema




  while (action != 'S') {


    printf("\nGestion de FarmaDrones: Distribucion de Farmacos con Dron \n");
    printf("     Iniciar gestion                     (Pulsar I) \n");
    printf("     Alta almacen                        (Pulsar M) \n");
    printf("     Alta paciente almacen               (Pulsar A) \n");
    printf("     Ubicar paciente                     (Pulsar U) \n");
    printf("     Nuevo pedido                        (Pulsar N) \n");
    printf("     Lista diaria de pedidos             (Pulsar L) \n");
    printf("     Programar rutas diarias del dron    (Pulsar P) \n");
    printf("     Representar rutas diarias del dron  (Pulsar R) \n");
    printf("     Salir                               (Pulsar S) \n\n");
    printf("Teclear una opcion valida (A/U/N/L/C/S)?  \n\n");
    scanf("%s", &action);
    action = toupper(action);
    fflush(stdin);


    while (action != 'I' && action != 'M' && action != 'A' && action != 'U'  && action != 'N' && action != 'L' && action != 'P' && action != 'R' && action != 'S') {
      printf("\nDebe introducir una letra valida \n");
      printf("\nGestion de FarmaDrones: Distribucion de Farmacos con Dron \n");
      printf("     Iniciar gestion                     (Pulsar I) \n");
      printf("     Alta almacen                        (Pulsar M) \n");
      printf("     Alta paciente almacen               (Pulsar A) \n");
      printf("     Ubicar paciente                     (Pulsar U) \n");
      printf("     Nuevo pedido                        (Pulsar N) \n");
      printf("     Lista diaria de pedidos             (Pulsar L) \n");
      printf("     Programar rutas diarias del dron    (Pulsar P) \n");
      printf("     Representar rutas diarias del dron  (Pulsar R) \n");
      printf("     Salir                               (Pulsar S) \n\n");
      printf("Teclear una opcion valida ?  \n\n");
      fflush(stdin);
      scanf("%c", &action);
      action = toupper(action);
      fflush(stdin);
    }

    switch (action) {
    case 'I' ://puede llamar a esta opcion las veces que quiera, pero solo iniciara los datos la primera vez, el resto solo imprime TODO
      if (inicio == 1) {
        IniciarGestion(almacenes,indiceAlmacen);
        imprimirInicio(almacenes,indiceAlmacen);

      }      else {
       printf("\nYa ha iniciado el sistema anteriormente.\n");
       }
       inicio++;
        break;
    case 'M' :  CrearAlmacen(almacenes,indiceAlmacen);;break;
    case 'A' :  AltaPacienteAlmacen(almacenes,indiceAlmacen);break;
    case 'U' :  UbicarPacienteAlmacen(almacenes,indiceAlmacen);break;
    case 'N' :  AnadirPedidosAlmacen(almacenes,indiceAlmacen);;break;
    case 'L' :  ImprimirPedidoAlmacen(almacenes,indiceAlmacen);break;
    case 'P' :  ProgramarRutas(almacenes,indiceAlmacen); break;
    case 'R' :  ProgramarImprimirRutas(almacenes,indiceAlmacen); break;
    default : printf("");
    }

    if (action == 'S') {
      continue;
    }

  }
}
