/***************************************
* NOMBRE: #Ed Wolf#
* EMAIL: #wolf7ed@gmail.com#
* DATE: 12/2020
***************************************/

/*
Realizacion Paciente, donde incluye todo lo relativo a Pacientes y Pedidos
*/


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "Paciente.h"



//esta funcion recorre el punteroPaciente y pone todo a 0, para eliminar la memoria d la RAM
// ================================================ LiberarMemoria    ================================================================
void TipoKaciente::liberarMemoria(punteroPaciente& grupo) {
  punteroPaciente nextPaciente;

  nextPaciente = grupo;

  while (grupo != NULL ) {
    nextPaciente = grupo;
    grupo =grupo->siguiente ;
    delete nextPaciente;
    nextPaciente = NULL;
  }

  return;
}
// ================================================  LiberarMemoria   ================================================================


//para no crear mas de 20 pacientes
// ================================================ ProteccionPaciente    ================================================================
bool TipoKaciente::ProteccionPaciente(int refGlobal) {
  if (refGlobal >=1000) {
    return true;
  } else {
    return false;
  }
}
// ================================================ ProteccionPaciente     ================================================================

//imprime un paciente
// ================================================ imprimirP    ================================================================
void TipoKaciente::imprimirP(punteroPaciente  paciente) {

  printf("     %2d    %s",paciente->ref, paciente->identificador );
  for (int i = 1; i <= (20-(strlen(paciente->identificador))); i++) {
    printf(" ");
  }
  printf("%8d %9d \n", paciente->distancia , paciente->angulo );

  return;
}
// ================================================  imprimirP   ================================================================



//escanea los datos del paciente, y va recorriendo el puntero
// ================================================  escanearPaciente   ================================================================
void TipoKaciente::escanearPaciente(punteroPaciente& grupo,int& refGlobal) {

  TipoCadena identificadorr;
  int distanciaa,aangulo;
  float xx, yy;
  punteroPaciente Ultimo;
  punteroPaciente nextPaciente;
  char opcion;


  if (ProteccionPaciente(refGlobal)) {
    printf("\nHa superado el numero maximo de paciente(20) \n");
    return;
  }


  do {
    printf("     Identificador (entre 1 y 20 caracteres)?");
    fflush(stdin);
    scanf("%[^\n]", &identificadorr);


    printf("     Distancia (hasta 10000 metros a plena carga)?");
    scanf("%d", &distanciaa);
    while (distanciaa > 10000 || distanciaa < 0) {
      printf("La distancia debe ser menor de 10000 metros y mayor de 0. ");
      scanf("%d", &distanciaa);
    }

    printf("     Angulo (entre 0 y 2000 pi/1000 radiantes)?");
    scanf("%d", &aangulo);
    while (aangulo > 2000  || aangulo < 0) {
      printf("El angulo debe estar entre 0 y 2000 pi/1000 radiantes. ");
      scanf("%d", &aangulo);
    }
    xx = calcularX(aangulo, distanciaa);
    yy = calcularY(aangulo, distanciaa);

    fflush(stdin);
    printf("\nDatos Correcto (S/N)?");
    scanf("%c",&opcion);
    opcion = toupper(opcion);
    while (opcion != 'S' && opcion != 'N') {
      printf("\nDebe introducir S o N. \nDatos Correcto (S/N)?\n");
      fflush(stdin);
      scanf("%c", &opcion);
      opcion = toupper(opcion);
    }
  } while ( opcion == 'N');


  if (grupo == NULL) {
    grupo = new TipoPaciente;

    grupo->ref = refGlobal;
    strcpy(grupo->identificador, identificadorr);
    grupo->distancia = distanciaa;
    grupo->angulo = aangulo;
    grupo->x = xx;
    grupo->y = yy;
    grupo->siguiente = NULL;
    refGlobal++;
  } else {
    nextPaciente = grupo;
    while (nextPaciente->siguiente != NULL) {
      nextPaciente = nextPaciente->siguiente;
    }
    Ultimo = new TipoPaciente;

    Ultimo->ref = refGlobal;
    strcpy(Ultimo->identificador, identificadorr);
    Ultimo->distancia = distanciaa;
    Ultimo->angulo = aangulo;
    Ultimo->x = xx;
    Ultimo->y = yy;
    Ultimo->siguiente = NULL;
    nextPaciente->siguiente = Ultimo;
    refGlobal++;
  }

  return;
}
// ================================================ escanearPaciente    ================================================================

//comprueba si ese paciente existe, si existe devuelve true y sus angulo y distancia, y si no devuelve falso
// ================================================ devolverPaciente    ================================================================
bool TipoKaciente::devolverPaciente(punteroPaciente grupo,int pacienteNum,int& an,int & dist) {
  int inicio;
  punteroPaciente nextPaciente =  grupo;
  inicio = 1;

  while (nextPaciente != NULL && inicio !=pacienteNum) {
    nextPaciente = nextPaciente->siguiente;
    inicio++;
  }

  if (nextPaciente != NULL ) {
    an = nextPaciente->angulo;
    dist = nextPaciente->distancia;
    return true;
  } else {

    return false;
  }

}
// ================================================  devolverPaciente   ================================================================


// =====================================================aGrados ===============================================
float TipoKaciente::aGrados(int radianes) {
  float grados, radianesFloat;
  radianesFloat = radianes;
  grados = (radianesFloat * 360) /2000;
  return grados;
}

// =====================================================AnguloTriangulo =======================================
float TipoKaciente::AnguloTriangulo(float grados) {
  float angulo;
  if (grados == 0 || grados == 360) {
    angulo = 0;
  } else if (grados > 90 && grados < 180) {
    angulo = grados -  90;
  } else if ( grados > 180 && grados < 270) {
    angulo = grados - 180;
  } else if (grados > 270 && grados < 360) {
    angulo = grados - 270;
  } else {
    angulo = grados;
  }
  return angulo;
}

// =====================================================CalcularX =======================================
float TipoKaciente::calcularX(int radianes, int longitud) {
  float grados, angulo, x, aradianes;

  grados = aGrados(radianes);
  angulo = AnguloTriangulo(grados);
  aradianes = angulo * 0.01745329252;

  if ( radianes == 0 || radianes == 2000) {
    x = longitud;
    return x;
  } else if (radianes == 500 || radianes == 1500) {
    x = 0;
    return x;
  } else if (radianes == 1000) {
    x = longitud * (-1);
    return x;
  } else if (radianes > 0 && radianes < 500 || radianes > 1000 && radianes < 1500) {
    x = cos(aradianes)*longitud;
  } else if (radianes > 500 && radianes < 1000 || radianes > 1500 && radianes < 2000) {
    x = sin(aradianes)*longitud;
  }
  if (radianes > 500 && radianes < 1500) {
    x = x* (-1);
  }
  return x;
}



// =====================================================CalcularY ======================================
float TipoKaciente::calcularY(int radianes, int longitud) {

  float grados, angulo, y, aradianes;

  grados = aGrados(radianes);
  angulo = AnguloTriangulo(grados);
  aradianes = angulo * 0.01745329252;

  if ( radianes == 0 || radianes == 2000) { // o y 360
    y = 0;
    return y;
  } else if (radianes == 500) { // 90 y 270
    y = longitud;
    return y;
  } else if ( radianes == 1500) {
    y = longitud * (-1);
    return y;
  } else if (radianes == 1000) { // 180
    y = 0;
    return y;
  } else if (radianes > 0 && radianes < 500 || radianes > 1000 && radianes < 1500) {
    y = sin(aradianes)*longitud;
  } else if (radianes > 500 && radianes < 1000 || radianes > 1500 && radianes < 2000) {
    y = cos(aradianes)*longitud;
  }
  if ( radianes >1000 && radianes < 2000) {
    y = y * (-1);
  }
  return y;
}


// ========================================================moduloVector =========================================
float TipoKaciente::moduloVector(float x1, float y1, float x2, float y2) {
  float moduloVector;
  moduloVector = sqrt( pow((x2-x1),2) + pow((y2-y1),2));
  return  moduloVector;
}







//va recorriendo la funcion imprimirP y va imprimiendo todos los pacientes
// ================================================  imprimirLista   ================================================================
void TipoKaciente::imprimirLista(punteroPaciente grupo) {
  punteroPaciente nextPaciente = grupo; //variable  nextPaciente del tipo punteroPaciente

  printf("Lista de pacientes y su ubicacion: \n\n");
  printf("      Ref.  Identificador       Distancia    Angulo \n\n");

  while (nextPaciente != NULL) {
    imprimirP(nextPaciente);
    nextPaciente = nextPaciente->siguiente;
  }
  printf("\n");
  printf("\n");
  return;
}
// ================================================  imprimirLista   ================================================================


//llama a comprobar si hay mas de 20 pacientes, si pasa esa proteccion, llama a escanear paciente de forma recursiva
// ================================================  AnadirPaciente   ================================================================
void TipoKaciente::AnadirPaciente(punteroPaciente& grupo,int& refGlobal) { // A�ADIR PACIENTEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
  char opcion;

  //if (ProteccionPaciente(refGlobal)) {
  // printf("\nHa superado el numero maximo de paciente(20) \n");
  // return;
// }


  printf("Alta nuevo paciente: \n \n");
  escanearPaciente(grupo,refGlobal);

  do {
    fflush(stdin);
    printf("Otro paciente (S/N)? ");  // OPCION OTRO PACIENTE?? =======================================================
    scanf("%c",&opcion);
    opcion = toupper(opcion);
    while (opcion != 'S' && opcion != 'N') {
      printf("\nDebe introducir S o N. \nOtro paciente (S/N)? \n");
      fflush(stdin);
      scanf("%c", &opcion);
      opcion = toupper(opcion);
    }


    switch (opcion) {
    case 'S' : escanearPaciente(grupo,refGlobal);break;
    case 'N' : break;
    default : printf(" ");
    }

  } while ( opcion == 'S');
  printf("\n");
  printf("\n");

  return;
}// =========================================== A�ADIR PACIENTEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE



// =============================== CrearPedido ================================================================
/* Para esta opcion, al ser muchas preguntas seguidas, he decidido pooner un salto de linea con cada pregunta,
para que la respuesta salga en una linea diferente y asi sea mas facil de leer y de encontrar los datos en la consola,
sin esos saltos de linea la opcion de nuevo pedido crea un texto enorme y dificil de leer
*/
void TipoKaciente::CrearPedido(conjuntoPedido PedidosTotales,int& contadorGlobal,punteroPaciente grupo) {
  int an,dist;
  char opcion;

//
  do {

    if (contadorGlobal < 100) {

      printf("     Ref. Paciente (entre 1 y 20): \n");
      scanf("%d",&PedidosTotales[contadorGlobal].refPaciente);


      if (devolverPaciente(grupo,PedidosTotales[contadorGlobal].refPaciente ,an,dist)) { //= if REFERENCIA DE PACIENTE EXISTE ================


        // si el numero de envios es superior a 1, preguntar Numero de dias entre cada envio? =============
        printf("     Numero de envios \n");
        scanf("%d",&PedidosTotales[contadorGlobal].nEnvio);

        if (PedidosTotales[contadorGlobal].nEnvio > 1) {
          printf("     Numero de dias entre cada envio \n");
          scanf("%d",&PedidosTotales[contadorGlobal].frecuencia);

        } else {
          PedidosTotales[contadorGlobal].frecuencia =  0;
        }

        printf("     Introduzca el dia\n");
        scanf("%d",&PedidosTotales[contadorGlobal].dia);

        while (PedidosTotales[contadorGlobal].dia < 0 || PedidosTotales[contadorGlobal].dia>31  ) {
          printf("dia no permitido introduzca de nuevo\n");
          scanf("%d",&PedidosTotales[contadorGlobal].dia);
        }

        printf("     Introduzca el mes\n");
        scanf("%d",&PedidosTotales[contadorGlobal].mes);

        while (PedidosTotales[contadorGlobal].mes < 0 || PedidosTotales[contadorGlobal].mes >12  ) {
          printf("mes no permitido introduzca de nuevo\n");
          scanf("%d",&PedidosTotales[contadorGlobal].mes);
        }


        printf("     Introduzca el ano\n");
        scanf("%d",&PedidosTotales[contadorGlobal].ano);

        while (PedidosTotales[contadorGlobal].ano <1900 || PedidosTotales[contadorGlobal].ano >2300  ) {
          printf("Ano no permitido \n introduzcalo de nuevo\n",FinalizaMes2(PedidosTotales[contadorGlobal].mes,PedidosTotales[contadorGlobal].ano));
          scanf("%d",&PedidosTotales[contadorGlobal].ano);
        }

        while ( PedidosTotales[contadorGlobal].dia > FinalizaMes2(PedidosTotales[contadorGlobal].mes,PedidosTotales[contadorGlobal].ano)) {
          printf("Dia no permitido. Vuelva a introducir el dia: \n");
          scanf("%d",&PedidosTotales[contadorGlobal].dia);
        }

        do {
          printf("     Introduzca el Nombre del farmaco\n");
          scanf("%s",&PedidosTotales[contadorGlobal].A.farmaco.Nombre);
          printf("     Introduzca el Peso del farmaco\n");
          scanf("%d",&PedidosTotales[contadorGlobal].A.farmaco.peso); //PESO
          printf("     Introduzca las Ud del farmaco\n");
          scanf("%d",&PedidosTotales[contadorGlobal].A.unidades); //UNIDADES
          if (PedidosTotales[contadorGlobal].A.farmaco.peso > 3000 || PedidosTotales[contadorGlobal].A.farmaco.peso
              * PedidosTotales[contadorGlobal].A.unidades > 3000) {
            printf("\nEl peso del pedido debe ser menor a 3000gramos, \nvuelva a introducir las unidades: \n");
          }
        } while (PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades > 3000);

        PedidosTotales[contadorGlobal].farmacosDisponibles = 4;

        fflush(stdin);

        // if para preguntar �Otro farmaco? si las unidades del primero suman menos de 3000   =======================
        if (PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades < 3000) {

          printf("     Otro farmaco(S/N)?\n");
          scanf("%s",&opcion);
          opcion = toupper(opcion);

// =========================================================================================otro farmaco? ===========================================================================


          while (PedidosTotales[contadorGlobal].farmacosDisponibles > 0 && opcion == 'S') {
            fflush(stdin);


            // ==========================farmaco 2 de 5 ========================================================================================
            if (PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades <3000) {
              do {
                if (PedidosTotales[contadorGlobal].farmacosDisponibles == 4) {
                  printf("     Nombre farmaco(Entre 1 y 20 caracteres)? \n");
                  scanf("%s",&PedidosTotales[contadorGlobal].B.farmaco.Nombre);
                  printf("     Peso farmaco (Menor de 3000 gramos)? \n");
                  scanf("%d",&PedidosTotales[contadorGlobal].B.farmaco.peso);
                  printf("     Unidades de farmaco? \n");
                  scanf("%d",&PedidosTotales[contadorGlobal].B.unidades);
                  if ( (PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                        + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades) > 3000) {
                    printf("\nEl peso del pedido debe ser menor a 3000gramos, \nvuelva a introducir las unidades: \n");
                  }
                }
              } while ( PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                        + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades > 3000);
            }


            // ==========================farmaco 3 de 5 ==============================================================================
            if ( PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                 + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades
                 < 3000) {
              do {
                if (PedidosTotales[contadorGlobal].farmacosDisponibles == 3) { // PEDIDO 3 DE 5
                  printf("     Nombre farmaco(Entre 1 y 20 caracteres)? \n");
                  scanf("%s",&PedidosTotales[contadorGlobal].C.farmaco.Nombre);
                  printf("     Peso farmaco (Menor de 3000 gramos)? \n");
                  scanf("%d",&PedidosTotales[contadorGlobal].C.farmaco.peso);
                  printf("     Unidades de farmaco? \n");
                  scanf("%d",&PedidosTotales[contadorGlobal].C.unidades);
                  if ( PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                       + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades
                       + PedidosTotales[contadorGlobal].C.farmaco.peso * PedidosTotales[contadorGlobal].C.unidades > 3000) {
                    printf("\nEl peso del pedido debe ser menor a 3000gramos, \nvuelva a introducir las unidades: \n");
                  }
                }
              } while ( PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                        + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades
                        + PedidosTotales[contadorGlobal].C.farmaco.peso * PedidosTotales[contadorGlobal].C.unidades
                        > 3000);
            }


            // ==========================farmaco 4 de 5 ==============================================================================
            if (PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades
                + PedidosTotales[contadorGlobal].C.farmaco.peso * PedidosTotales[contadorGlobal].C.unidades
                < 3000) {
              do {
                if (PedidosTotales[contadorGlobal].farmacosDisponibles == 2) {  //PEDIDO 4 DE 5
                  printf("     Nombre farmaco(Entre 1 y 20 caracteres)? \n");
                  scanf("%s",&PedidosTotales[contadorGlobal].D.farmaco.Nombre);
                  printf("     Peso farmaco (Menor de 3000 gramos)? \n");
                  scanf("%d",&PedidosTotales[contadorGlobal].D.farmaco.peso);
                  printf("     Unidades de farmaco? \n");
                  scanf("%d",&PedidosTotales[contadorGlobal].D.unidades);
                }
                if (        PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                            + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades
                            + PedidosTotales[contadorGlobal].C.farmaco.peso * PedidosTotales[contadorGlobal].C.unidades
                            + PedidosTotales[contadorGlobal].D.farmaco.peso * PedidosTotales[contadorGlobal].D.unidades > 3000) {
                  printf("\nEl peso del pedido debe ser menor a 3000gramos, \nvuelva a introducir las unidades: \n");
                }
              } while (     PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                            + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades
                            + PedidosTotales[contadorGlobal].C.farmaco.peso * PedidosTotales[contadorGlobal].C.unidades
                            + PedidosTotales[contadorGlobal].D.farmaco.peso * PedidosTotales[contadorGlobal].D.unidades
                            > 3000);
            }




            // ==========================farmaco 5 de 5 ==============================================================================
            if (PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades
                + PedidosTotales[contadorGlobal].C.farmaco.peso * PedidosTotales[contadorGlobal].C.unidades
                + PedidosTotales[contadorGlobal].D.farmaco.peso * PedidosTotales[contadorGlobal].D.unidades
                < 3000) {
              do {
                if (PedidosTotales[contadorGlobal].farmacosDisponibles == 1) {
                  printf("     Nombre farmaco(Entre 1 y 20 caracteres)? \n");
                  scanf("%s",&PedidosTotales[contadorGlobal].E.farmaco.Nombre);
                  printf("     Peso farmaco (Menor de 3000 gramos)? \n");
                  scanf("%d",&PedidosTotales[contadorGlobal].E.farmaco.peso);
                  printf("     Unidades de farmaco? \n");
                  scanf("%d",&PedidosTotales[contadorGlobal].E.unidades);
                }
                if ( PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                     + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades
                     + PedidosTotales[contadorGlobal].C.farmaco.peso * PedidosTotales[contadorGlobal].C.unidades
                     + PedidosTotales[contadorGlobal].D.farmaco.peso * PedidosTotales[contadorGlobal].D.unidades
                     + PedidosTotales[contadorGlobal].E.farmaco.peso * PedidosTotales[contadorGlobal].E.unidades > 3000) {
                  printf("\nEl peso del pedido debe ser menor a 3000gramos, \nvuelva a introducir las unidades: \n");
                }
              } while (PedidosTotales[contadorGlobal].A.farmaco.peso * PedidosTotales[contadorGlobal].A.unidades
                       + PedidosTotales[contadorGlobal].B.farmaco.peso * PedidosTotales[contadorGlobal].B.unidades
                       + PedidosTotales[contadorGlobal].C.farmaco.peso * PedidosTotales[contadorGlobal].C.unidades
                       + PedidosTotales[contadorGlobal].D.farmaco.peso * PedidosTotales[contadorGlobal].D.unidades
                       + PedidosTotales[contadorGlobal].E.farmaco.peso * PedidosTotales[contadorGlobal].E.unidades > 3000);
            }   // ==========================FIN farmaco 5 de 5 ==============================================================================

            PedidosTotales[contadorGlobal].farmacosDisponibles--;
            fflush(stdin);
            if (PedidosTotales[contadorGlobal].farmacosDisponibles > 0) {
              printf("     Otro farmaco(S/N)? \n");
              scanf("%s",&opcion);
              opcion = toupper(opcion);
            } else {
              opcion = 'N';
            }
          }  // ============= fin del while para �Otro f�rmaco? ==========================
        } //fin del if para introducir otro farmaco si el primer farmaco y sus unidades no suman 3000
        PedidosTotales[contadorGlobal].pesoTotal = PesoFarmaco(PedidosTotales[contadorGlobal]);
        contadorGlobal++;
//================FIN DE if REFERENCIA DE PACIENTE EXISTE =================================================
      } else {
        PedidosTotales[contadorGlobal].refPaciente = 0;
        printf("\n No existe un paciente con esa referencia\n");
      }

    } else {
      printf("Numero de pedidos maximo: 100. No se pueden introducir mas pedidos. \n");
    }



    // pregunta: �otro pedido?
    printf("     Otro pedido (S/N)? \n");  // OPCION OTRO PACIENTE?? =======================================================
    scanf("%c",&opcion);
    opcion = toupper(opcion);
    while (opcion != 'S' && opcion != 'N') {
      printf("Pulse una letra valida (S/N)");
      scanf("%s", &opcion);
      opcion = toupper(opcion);
    }
    // AQUI FINALIZA EL DO WHILE
  } while (opcion != 'N');

return;
}
// =============================== CrearPedido ================================================================


// =============================== imprimirFarmaco ================================================================
void TipoKaciente::imprimirFarmaco(Pedido ped) {
  int peso;
  peso = 0;

  if (ped.A.farmaco.Nombre[0] != '\0') {
    printf("%2d Unidades   %s ", ped.A.unidades, ped.A.farmaco.Nombre);
    for (int i = 1; i <= (20-(strlen(ped.A.farmaco.Nombre))); i++) {
      printf(" ");
    }
    printf("Peso : %4d gramos\n", ped.A.farmaco.peso);
    peso = peso + ped.A.unidades * ped.A.farmaco.peso;
  }

  if (ped.B.farmaco.Nombre[0] != '\0') {
    printf("%2d Unidades   %s ", ped.B.unidades, ped.B.farmaco.Nombre);
    for (int i = 1; i <= (20-(strlen(ped.B.farmaco.Nombre))); i++) {
      printf(" ");
    }
    printf("Peso : %4d gramos\n", ped.B.farmaco.peso);
    peso = peso + ped.B.unidades * ped.B.farmaco.peso;
  }

  if (ped.C.farmaco.Nombre[0] != '\0') {
    printf("%2d Unidades   %s ", ped.C.unidades, ped.C.farmaco.Nombre);
    for (int i = 1; i <= (20-(strlen(ped.C.farmaco.Nombre))); i++) {
      printf(" ");
    }
    printf("Peso : %4d gramos\n", ped.C.farmaco.peso);
    peso = peso + ped.C.unidades * ped.C.farmaco.peso;
  }

  if (ped.D.farmaco.Nombre[0] != '\0') {
    printf("%2d Unidades   %s ", ped.D.unidades, ped.D.farmaco.Nombre);
    for (int i = 1; i <= (20-(strlen(ped.D.farmaco.Nombre))); i++) {
      printf(" ");
    }
    printf("Peso : %4d gramos\n", ped.D.farmaco.peso);
    peso = peso + ped.D.unidades * ped.D.farmaco.peso;
  }

  if (ped.E.farmaco.Nombre[0] != '\0') {
    printf("%2d Unidades   %s ", ped.E.unidades, ped.E.farmaco.Nombre);
    for (int i = 1; i <= (20-(strlen(ped.E.farmaco.Nombre))); i++) {
      printf(" ");
    }
    printf("Peso : %4d gramos\n", ped.E.farmaco.peso);
    peso = peso + ped.E.unidades * ped.E.farmaco.peso;
  }
  printf("              Peso Total del Envio:       %4d gramos\n",peso);


  return;
} // =============================== imprimirFarmaco ================================================================


//suma para fechas de los envio,evita resultados raros al crear pedidos y envios que sumen fechas (en meses segun terminen en 28,29,30,31, a�os bisiestos etc)
// =============================== FechaNueva ================================================================
void TipoKaciente::FechaNueva(int dias,int& diaa,int& mess,int& anno) {
  int aux=diaa+dias;
  int aux2=mess;
  int aux3=anno;
  do {
    if (aux>31 && aux2==1) {
      aux=aux-31 ;aux2=aux2+1;
    }
    if (aux>29 && aux2==2 &&  ((aux3 % 4 == 0) && (aux3 % 400 == 0 || aux3 % 100 != 0) )) {
      aux=aux-29;aux2=aux2+1;
    }
    if (aux>28 && aux2==2 &&  !((aux3 % 4 == 0) && (aux3 % 400 == 0 || aux3 % 100 != 0))) {
      aux=aux-28;aux2=aux2+1;
    }
    if (aux>31 && aux2==3) {
      aux=aux-31;aux2=aux2+1;
    }
    if (aux>30 && aux2==4) {
      aux=aux-30;aux2=aux2+1;
    }
    if (aux>31 && aux2==5) {
      aux=aux-31;aux2=aux2+1;
    }
    if (aux>30 && aux2==6) {
      aux=aux-30;aux2=aux2+1;
    }
    if (aux>31 && aux2==7) {
      aux=aux-31;aux2=aux2+1;
    }
    if (aux>31 && aux2==8) {
      aux=aux-31;aux2=aux2+1;
    }
    if (aux>30 && aux2==9) {
      aux=aux-30;aux2=aux2+1;
    }
    if (aux>31 && aux2==10) {
      aux=aux-31;aux2=aux2+1;
    }
    if (aux>30 && aux2==11) {
      aux=aux-30;aux2=aux2+1;
    }
    if (aux>31 && aux2==12) {
      aux=aux-31;aux2=1;aux3=aux3+1;
    }
  }   while (31 < aux);
  diaa= aux;
  mess= aux2;
  anno = aux3;

  return;
}  // =============================== FechaNueva ================================================================

//Funcion para determinar en que dia termina el mes, e impedir q se usen dias q no existen(como el 30 de febrero)
// ====================================    fINALIZA MES 2 **************************************************
int TipoKaciente::FinalizaMes2(int Mes,int Anno2) {
  int auxFinalMes;

  if (Mes == 1 || Mes == 3 || Mes == 5 || Mes == 7 || Mes == 8 || Mes == 10 || Mes == 12) {
    auxFinalMes = 31 ;
  } else if (Mes == 2 && Anno2 %4==0 && Anno2%100==0 && Anno2%400!=0) {
    auxFinalMes = 28;
  } else if (Mes == 2 && Anno2 %4!= 0) {
    auxFinalMes = 28;
  } else if (Mes == 2 && Anno2%4==0) {
    auxFinalMes = 29;
  } else if (Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11) {
    auxFinalMes = 30;
  }
  return auxFinalMes;
}
/* **********************************FINALIZA MES2 *********************************************************************/


//comprueba si ese dia hay pedido
// =============================== comprobarDias ================================================================
bool TipoKaciente::comprobarDias(Pedido compruebame,int diaa,int mess,int anno) {
  int diaI,mesI,anoI;
  diaI = compruebame.dia;
  mesI = compruebame.mes;
  anoI = compruebame.ano;

  for (int i = 1; i < compruebame.nEnvio ; i++) {
    FechaNueva(compruebame.frecuencia,diaI,mesI,anoI); //POR REFRENCIA SE ACUMULA LAS SUMAS EN LA FECHAS

    if (anoI == anno ) {
      if (mesI == mess) {
        if ( diaI == diaa) {
          return true;
        }
      }
    }

  }

  return false;
}  // =============================== comprobarDias ====================================================================



// =============================== ListarPedidos ===========================================================================
void TipoKaciente::ListarPedidos(conjuntoPedido PedidosTotales,int contadorGlobal,punteroPaciente primero) { //IMPRIMIR PEDIDOS

  int diaa,mess,aano,pedidoNum,angu,dista;
  bool hayPedido;

  pedidoNum = 1;
  printf("\n");
  printf("Introduzca el dia\n");
  scanf("%d",&diaa);
  printf("Introduzca el mes\n");
  scanf("%d",&mess);
  printf("Introduzca el anno\n");
  scanf("%d",&aano);
  hayPedido = false;
  fflush(stdin);
  for (int i = 0; i <= contadorGlobal; i++) {

    if (aano == PedidosTotales[i].ano ) {
      if (mess == PedidosTotales[i].mes) {
        if (diaa == PedidosTotales[i].dia) {

          printf("PEDIDO %d\n",pedidoNum);
          pedidoNum++;
          if (devolverPaciente(primero,PedidosTotales[i].refPaciente,angu,dista)) { //devolverPaciente(primero,PedidosTotales[i].refPaciente,angu,dista)
            printf("Ubicacion destino: Distancia: %4d y Angulo: %4d \n",dista, angu);
            hayPedido = true;
            imprimirFarmaco(PedidosTotales[i]);
            printf("\n\n");
          } else {
            // printf("No hay pedidos para esa fecha. \n");
          }


        }

      }

    }

    if (PedidosTotales[i].nEnvio > 1) {
      if (comprobarDias(PedidosTotales[i],diaa,mess,aano)) {

        printf("PEDIDO %d\n",pedidoNum);
        pedidoNum++;
        if (devolverPaciente(primero,PedidosTotales[i].refPaciente,angu,dista)) {
          printf("Ubicacion destino: Distancia: %4d y Angulo: %4d \n",dista, angu);
          hayPedido = true;
          imprimirFarmaco(PedidosTotales[i]);
        }

      }
    }

  }// ================================================FOR
  if (!hayPedido) {
    printf("No hay Pedido para esa fecha \n");
  }
  printf("\n");

  return;

}// =============================== ListarPedidos ===========================================================================




int TipoKaciente::pesoPedido(Pedido ped) {
  int peso;
  peso = 0;
  if (ped.A.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.A.unidades * ped.A.farmaco.peso;
  }

  if (ped.B.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.B.unidades * ped.B.farmaco.peso;
  }

  if (ped.C.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.C.unidades * ped.C.farmaco.peso;
  }

  if (ped.D.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.D.unidades * ped.D.farmaco.peso;
  }

  if (ped.E.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.E.unidades * ped.E.farmaco.peso;
  }
  return peso;
}
//==========================================PESO PEDIDO ================================================




void TipoKaciente::AnadirPacienteAutomatica(punteroPaciente& grupo,int& refGlobal,TipoCadena identificadorr, int distanciaa,int aangulo) { // A�ADIR PACIENTEEEEEEEEEE AUTOOOOOOOOOOOOOOO

  if (ProteccionPaciente(refGlobal)) {
    printf("\nHa superado el numero maximo de paciente(20) \n");
    return;
  }

  escanearPacienteAuto(grupo,refGlobal,identificadorr,distanciaa,aangulo);
  fflush(stdin);

  printf("\n");
  printf("\n");

  return;
}// =========================================== A�ADIR PACIENTEEEEEEE AUTOOOOOOOOOOOOO
//==========================================  AnadirPaciente Auto ================================================

void TipoKaciente::escanearPacienteAuto(punteroPaciente& grupo,int& refGlobal,TipoCadena identificadorr, int distanciaa,int aangulo) {

  punteroPaciente Ultimo;
  punteroPaciente nextPaciente;


  if (ProteccionPaciente(refGlobal)) {
    printf("\nHa superado el numero maximo de paciente(20) \n");
    return;
  }

  fflush(stdin);



  if (grupo == NULL) {
    grupo = new TipoPaciente;

    grupo->ref = refGlobal;
    strcpy(grupo->identificador, identificadorr);
    grupo->distancia = distanciaa;
    grupo->angulo = aangulo;
    grupo->siguiente = NULL;
    grupo->x =  calcularX(aangulo,distanciaa);

    grupo->y  = calcularY(aangulo,distanciaa);


    refGlobal++;
  } else {
    nextPaciente = grupo;
    while (nextPaciente->siguiente != NULL) {
      nextPaciente = nextPaciente->siguiente;
    }
    Ultimo = new TipoPaciente;

    Ultimo->ref = refGlobal;
    strcpy(Ultimo->identificador, identificadorr);
    Ultimo->distancia = distanciaa;
    Ultimo->angulo = aangulo;
    Ultimo->siguiente = NULL;
    nextPaciente->siguiente = Ultimo;
    grupo->x =  calcularX(aangulo,distanciaa);

    grupo->y  = calcularY(aangulo,distanciaa);

    refGlobal++;
  }

  return;
}
//========================================== EscanearPacienteAuto ================================================

void TipoKaciente::CrearPedidoAuto(conjuntoPedido PedidosTotales,int& contadorGlobal,int pa,int di,int me,int an,int nEn,int fre,FarmacoPedido AA,FarmacoPedido BB,FarmacoPedido CC,FarmacoPedido DD,FarmacoPedido EE) {
  PedidosTotales[contadorGlobal].refPaciente = pa;
  PedidosTotales[contadorGlobal].dia = di;
  PedidosTotales[contadorGlobal].mes = me;
  PedidosTotales[contadorGlobal].ano = an;
  PedidosTotales[contadorGlobal].nEnvio = nEn;
  PedidosTotales[contadorGlobal].frecuencia = fre;
  PedidosTotales[contadorGlobal].farmacosDisponibles = 5;


  if ( AA.farmaco.Nombre[0] != '\0') {
    PedidosTotales[contadorGlobal].A = AA;
    PedidosTotales[contadorGlobal].farmacosDisponibles--;
  } /*
  if ( BB.farmaco.Nombre[0]  !='\0') {
    PedidosTotales[contadorGlobal].B = BB;
    PedidosTotales[contadorGlobal].farmacosDisponibles--;
  }
  if ( CC.farmaco.Nombre[0]  != '\0') {
    PedidosTotales[contadorGlobal].C = CC;
    PedidosTotales[contadorGlobal].farmacosDisponibles--;
  }
  if ( DD.farmaco.Nombre[0]  != '\0') {
    PedidosTotales[contadorGlobal].D = DD;
    PedidosTotales[contadorGlobal].farmacosDisponibles--;
  }
  if ( EE.farmaco.Nombre[0]  != '\0') {
    PedidosTotales[contadorGlobal].E = EE;
    PedidosTotales[contadorGlobal].farmacosDisponibles--;
  } */
  PedidosTotales[contadorGlobal].pesoTotal = PesoFarmaco(PedidosTotales[contadorGlobal]);

  contadorGlobal =  contadorGlobal +1;

return;
}


bool TipoKaciente::devolverXY(punteroPaciente grupo,int pacienteNum,float& xx,float& yy) {
  int inicio;
  punteroPaciente nextPaciente =  grupo;
  inicio = 1;

  while (nextPaciente != NULL && inicio !=pacienteNum) {
    nextPaciente = nextPaciente->siguiente;
    inicio++;
  }

  if (nextPaciente != NULL ) {
    xx = nextPaciente->x;
    yy = nextPaciente->y;
    return true;
  } else {
    return false;
  }

}

int TipoKaciente::PesoFarmaco(Pedido ped) {
  int peso;
  peso = 0;

  if (ped.A.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.A.unidades * ped.A.farmaco.peso;
  }

  if (ped.B.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.B.unidades * ped.B.farmaco.peso;
  }

  if (ped.C.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.C.unidades * ped.C.farmaco.peso;
  }

  if (ped.D.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.D.unidades * ped.D.farmaco.peso;
  }

  if (ped.E.farmaco.Nombre[0] != '\0') {
    peso = peso + ped.E.unidades * ped.E.farmaco.peso;
  }
  return peso;
}


// =============================== imprimirFarmaco ================================================================
void TipoKaciente::imprimirFarmacoAUTOMATICO(Pedido ped) {
  int peso;

  peso = 0;

  if (ped.A.farmaco.Nombre[0] != '\0') {
    printf("   %d       %2d/%2d/%d    %s",  ped.refPaciente,    ped.dia, ped.mes, ped.ano,    ped.A.farmaco.Nombre);

    for (int i = 1; i <= (20-(strlen(ped.A.farmaco.Nombre))); i++) {
      printf(" ");
    }
    printf("   %4d      %2d\n",ped.A.farmaco.peso, ped.A.unidades);
    peso = peso + ped.A.unidades * ped.A.farmaco.peso;
  }
  /*
   if (ped.B.farmaco.Nombre[0] != '\0') {
     printf("   %d          %2d Unidades      %20s      Peso : %4d \n",ped.B.unidades,ped.B.farmaco.Nombre,ped.B.farmaco.peso);
     peso = peso + ped.B.unidades * ped.B.farmaco.peso;
   }

   if (ped.C.farmaco.Nombre[0] != '\0') {
     printf("   %2d Unidades      %20s      Peso : %4d \n",ped.C.unidades,ped.C.farmaco.Nombre,ped.C.farmaco.peso);
     peso = peso + ped.C.unidades * ped.C.farmaco.peso;
   }

   if (ped.D.farmaco.Nombre[0] != '\0') {
     printf("   %2d Unidades      %20s      Peso : %4d \n",ped.D.unidades,ped.D.farmaco.Nombre,ped.D.farmaco.peso);
     peso = peso + ped.D.unidades * ped.D.farmaco.peso;
   }

   if (ped.E.farmaco.Nombre[0] != '\0') {
     printf("   %2d Unidades      %20s      Peso : %4d \n",ped.E.unidades,ped.E.farmaco.Nombre,ped.E.farmaco.peso);
     peso = peso + ped.E.unidades * ped.E.farmaco.peso;
   } */
  //printf(" %d",peso);

  return;
} // =============================== imprimirFarmaco ================================================================



// =============================== ListarPedidosAUTOMATICO ===========================================================================
void TipoKaciente::ListarPedidosAUTOMATICO(conjuntoPedido PedidosTotales,int contadorGlobal,punteroPaciente primero) { //IMPRIMIR PEDIDOS

  int pedidoNum,angu,dista;
  bool hayPedido;
  pedidoNum = 1;


  for (int i = 0; i <= 100; i++) {



    if (devolverPaciente(primero,PedidosTotales[i].refPaciente,angu,dista)) { //devolverPaciente(primero,PedidosTotales[i].refPaciente,angu,dista)
      if (i == 1) {
        printf("\n       Pedidos\n\n");
        printf("   Cliente  Fecha        Farmaco                Peso  Unidades\n\n");

      }
      hayPedido = true;


      imprimirFarmacoAUTOMATICO(PedidosTotales[i]);


      pedidoNum++;
    } else {
      printf(" ");
    }




  }

  return;
} // ======================================FIN listarpedidoAUTOMATICO =============================










