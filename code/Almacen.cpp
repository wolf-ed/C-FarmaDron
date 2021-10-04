/***************************************
* NOMBRE: #Ed Wolf#
* EMAIL: #wolf7ed@gmail.com#
* DATE: 12/2020
***************************************/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <winbgim.h>
#include <math.h>
#include "Paciente.h"
#include "Almacen.h"
#include <windows.h>


//  -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32    -> Configuracion -> Compilador y depurador ->Configuracion de montaje -> otras opciones de montaje


// ================================================= iniciar gestion ================================================================
void IniciarGestion(ConjuntoAlmacen10 almacenes,int& indice) {
  tipocadena48  descrip;
  tipocadena48 dire;
  tipocadena48 muni;
  tipocadena16 pro;
  TipoCadena pac; //paciente
  FarmacoPedido pp,Nulo;

//Pacientes almacen 1
  strcpy(pac,"Maria Moven");
  strcpy(descrip,"San Agustin");
  strcpy(dire,"Plaza del Carmen, 20");
  strcpy(muni,"San Fernando");
  strcpy(pro,"Cadiz");
  CrearAlmacenAuto(almacenes,indice,descrip,dire,muni,pro);
  almacenes[0].kaciente.AnadirPacienteAutomatica(almacenes[0].primero,almacenes[0].Global,pac,3500,300); //distancia, angulo 3500 y 300
  strcpy(pac,"Salvador Esten");
  almacenes[0].kaciente.AnadirPacienteAutomatica(almacenes[0].primero,almacenes[0].Global,pac,5808,450);   //5808 y 450
  strcpy(pac,"Paula Sanchez");
  almacenes[0].kaciente.AnadirPacienteAutomatica(almacenes[0].primero,almacenes[0].Global,pac,4000,650); //distancia, angulo // 4000 y 650
  strcpy(pac,"Fabiola Delgado");
  almacenes[0].kaciente.AnadirPacienteAutomatica(almacenes[0].primero,almacenes[0].Global,pac,3220,1200); //4020, 1700  //3200 y 1200
  fflush(stdin);

//Almacen 2
  strcpy(pac,"Jesus Porto");
  strcpy(descrip,"Tacon Chapen");
  strcpy(dire,"Calle Alegria, 4");
  strcpy(muni,"Alcobendas");
  strcpy(pro,"Madrid");
  CrearAlmacenAuto(almacenes,indice,descrip,dire,muni,pro);
  almacenes[1].kaciente.AnadirPacienteAutomatica(almacenes[1].primero,almacenes[1].Global,pac,550,320);
  strcpy(pac,"Manuel Abolan");
  almacenes[1].kaciente.AnadirPacienteAutomatica(almacenes[1].primero,almacenes[1].Global,pac,3320,1800);

  fflush(stdin);

//Almacen 3
  strcpy(pac,"Ana Lucia");
  strcpy(descrip,"Libertador Matias Delgado");
  strcpy(dire,"Calle Delcielo, 14");
  strcpy(muni,"Alcira");
  strcpy(pro,"Valencia");
  CrearAlmacenAuto(almacenes,indice,descrip,dire,muni,pro);
  almacenes[2].kaciente.AnadirPacienteAutomatica(almacenes[2].primero,almacenes[2].Global,pac,3280,1640);
  strcpy(pac,"Donal Alren");
  almacenes[2].kaciente.AnadirPacienteAutomatica(almacenes[2].primero,almacenes[2].Global,pac,1150,730);

  fflush(stdin);
//Almacen 4
  strcpy(pac,"Pedro Perez");
  strcpy(descrip,"Avenida Diagonal");
  strcpy(dire,"Plaza Fontanella, 22");
  strcpy(muni,"Almoster");
  strcpy(pro,"Tarragona");
  CrearAlmacenAuto(almacenes,indice,descrip,dire,muni,pro);
  almacenes[3].kaciente.AnadirPacienteAutomatica(almacenes[3].primero,almacenes[3].Global,pac,1990,1727);  //distancia, angulo
  strcpy(pac,"Rocio Mugia");
  almacenes[3].kaciente.AnadirPacienteAutomatica(almacenes[3].primero,almacenes[3].Global,pac,2730,250);


//Almacen 5
  strcpy(pac,"Manuel Diaz");
  strcpy(descrip,"Marineda Ciudad");
  strcpy(dire,"Carretera de Arteixo, 11");
  strcpy(muni,"Lugo");
  strcpy(pro,"Lugo");
  CrearAlmacenAuto(almacenes,indice,descrip,dire,muni,pro);
  almacenes[4].kaciente.AnadirPacienteAutomatica(almacenes[4].primero,almacenes[4].Global,pac,1500,750);
  strcpy(pac,"Victor Torres");
  almacenes[4].kaciente.AnadirPacienteAutomatica(almacenes[4].primero,almacenes[4].Global,pac,5000,1000);
  strcpy(pac,"Alonso Valiente");
  almacenes[4].kaciente.AnadirPacienteAutomatica(almacenes[4].primero,almacenes[4].Global,pac,3000,1300);


// ======================Pedidos almacen 1



  strcpy(pp.farmaco.Nombre,"SPARI vilazodona");
  pp.farmaco.peso =300;
  pp.unidades = 1;
  almacenes[0].kaciente.CrearPedidoAuto(almacenes[0].PedidosTotales,almacenes[0].ContadorGlobal,1,1,1,2021,10,14,pp,Nulo,Nulo,Nulo,Nulo); //paciente, dia, mes, a�o, n�envios, distancia entre envio

  strcpy(pp.farmaco.Nombre,"Clorhexidina");
  pp.farmaco.peso =300;
  pp.unidades = 3;
  almacenes[0].kaciente.CrearPedidoAuto(almacenes[0].PedidosTotales,almacenes[0].ContadorGlobal,2,1,1,2021,5,14,pp,Nulo,Nulo,Nulo,Nulo);

  strcpy(pp.farmaco.Nombre,"Quetiapina");
  pp.farmaco.peso =300;
  pp.unidades = 1;
  almacenes[0].kaciente.CrearPedidoAuto(almacenes[0].PedidosTotales,almacenes[0].ContadorGlobal,3,1,1,2021,4,7,pp,Nulo,Nulo,Nulo,Nulo);

  strcpy(pp.farmaco.Nombre,"Peroxido gel");
  pp.farmaco.peso =200;
  pp.unidades = 1;
  almacenes[0].kaciente.CrearPedidoAuto(almacenes[0].PedidosTotales,almacenes[0].ContadorGlobal,3,1,1,2022,4,7,pp,Nulo,Nulo,Nulo,Nulo);

  strcpy(pp.farmaco.Nombre,"Omeplazol");
  pp.farmaco.peso =150;
  pp.unidades = 2;
  almacenes[0].kaciente.CrearPedidoAuto(almacenes[0].PedidosTotales,almacenes[0].ContadorGlobal,4,1,1,2021,4,7,pp,Nulo,Nulo,Nulo,Nulo);

  strcpy(pp.farmaco.Nombre,"SPARI vilazodona");
  pp.farmaco.peso =300;
  pp.unidades = 1;
  almacenes[0].kaciente.CrearPedidoAuto(almacenes[0].PedidosTotales,almacenes[0].ContadorGlobal,1,1,1,2022,10,14,pp,Nulo,Nulo,Nulo,Nulo);




//=================pedidos almacen 2
  strcpy(pp.farmaco.Nombre,"Mascaras  FFP2");
  pp.farmaco.peso =150;
  pp.unidades = 4;
  almacenes[1].kaciente.CrearPedidoAuto(almacenes[1].PedidosTotales,almacenes[1].ContadorGlobal,1,1,2,2021,10,14,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio

  strcpy(pp.farmaco.Nombre,"Ebastina forte");
  pp.farmaco.peso =100;
  pp.unidades = 10;
  almacenes[1].kaciente.CrearPedidoAuto(almacenes[1].PedidosTotales,almacenes[1].ContadorGlobal,1,14,2,2021,20,14,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio

  strcpy(pp.farmaco.Nombre,"Suero");
  pp.farmaco.peso =1000;
  pp.unidades = 1;
  almacenes[1].kaciente.CrearPedidoAuto(almacenes[1].PedidosTotales,almacenes[1].ContadorGlobal,2,1,1,2021,4,7,pp,Nulo,Nulo,Nulo,Nulo);

//=================pedidos almacen 3
  strcpy(pp.farmaco.Nombre,"Avamys");
  pp.farmaco.peso =40;
  pp.unidades = 10;
  almacenes[2].kaciente.CrearPedidoAuto(almacenes[2].PedidosTotales,almacenes[2].ContadorGlobal,1,1,4,2021,5,14,pp,Nulo,Nulo,Nulo,Nulo);

  strcpy(pp.farmaco.Nombre,"Gabapentina");
  pp.farmaco.peso =600;
  pp.unidades = 1;
  almacenes[2].kaciente.CrearPedidoAuto(almacenes[2].PedidosTotales,almacenes[2].ContadorGlobal,2,1,4,2021,4,7,pp,Nulo,Nulo,Nulo,Nulo);

  strcpy(pp.farmaco.Nombre,"Montelukast");
  pp.farmaco.peso =200;
  pp.unidades = 1;
  almacenes[2].kaciente.CrearPedidoAuto(almacenes[2].PedidosTotales,almacenes[2].ContadorGlobal,1,1,6,2021,2,7,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio

  strcpy(pp.farmaco.Nombre,"Acetaminofeno");
  pp.farmaco.peso =200;
  pp.unidades = 1;
  almacenes[2].kaciente.CrearPedidoAuto(almacenes[2].PedidosTotales,almacenes[2].ContadorGlobal,2,1,12,2021,2,7,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio

  strcpy(pp.farmaco.Nombre,"Clomipramina");
  pp.farmaco.peso =200;
  pp.unidades = 1;
  almacenes[2].kaciente.CrearPedidoAuto(almacenes[2].PedidosTotales,almacenes[2].ContadorGlobal,2,7,12,2021,2,14,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio

  strcpy(pp.farmaco.Nombre,"Gabapentina");
  pp.farmaco.peso =600;
  pp.unidades = 1;
  almacenes[2].kaciente.CrearPedidoAuto(almacenes[2].PedidosTotales,almacenes[2].ContadorGlobal,2,1,4,2022,4,7,pp,Nulo,Nulo,Nulo,Nulo);

//====================pedidos almacen 4
  strcpy(pp.farmaco.Nombre,"Omeprazol");
  pp.farmaco.peso =200;
  pp.unidades = 1;
  almacenes[3].kaciente.CrearPedidoAuto(almacenes[3].PedidosTotales,almacenes[3].ContadorGlobal,1,7,3,2021,2,1,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio

  strcpy(pp.farmaco.Nombre,"Vendas");
  pp.farmaco.peso =100;
  pp.unidades = 1;
  almacenes[3].kaciente.CrearPedidoAuto(almacenes[3].PedidosTotales,almacenes[3].ContadorGlobal,2,7,3,2021,1,0,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio


//===================pedidos almacen 5
  strcpy(pp.farmaco.Nombre,"Modafinilo");
  pp.farmaco.peso =200;
  pp.unidades = 1;
  almacenes[4].kaciente.CrearPedidoAuto(almacenes[4].PedidosTotales,almacenes[4].ContadorGlobal,1,20,6,2021,2,14,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio

  strcpy(pp.farmaco.Nombre,"Termometro digital");
  pp.farmaco.peso =300;
  pp.unidades = 3;
  almacenes[4].kaciente.CrearPedidoAuto(almacenes[4].PedidosTotales,almacenes[4].ContadorGlobal,2,20,6,2021,1,0,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio

  strcpy(pp.farmaco.Nombre,"Iberogast");
  pp.farmaco.peso =300;
  pp.unidades = 1;
  almacenes[4].kaciente.CrearPedidoAuto(almacenes[4].PedidosTotales,almacenes[4].ContadorGlobal,3,20,6,2021,2,1,pp,Nulo,Nulo,Nulo,Nulo);//paciente, dia, mes, a�o, n�envios, distancia entre envio



return;
}
// ================================================= iniciar gestion ================================================================


// ================================================= CrearAlmacenAUTO ================================================================
void CrearAlmacenAuto(ConjuntoAlmacen10 almacenes,int& indice, tipocadena48  descrip,tipocadena48 dire,tipocadena48 muni,tipocadena16 pro) {
  if (indice >=10) {
    return;
  }
  strcpy(almacenes[indice].calle, dire);
  strcpy(almacenes[indice].municipio, muni);
  strcpy(almacenes[indice].provincia, pro);
  strcpy(almacenes[indice].descripcion, descrip);
  almacenes[indice].primero = NULL;
  almacenes[indice].Global = 1;
  almacenes[indice].ContadorGlobal = 1;
  almacenes[indice].ref = indice + 1;
  indice = indice + 1;

return;
}
// ================================================= crearAlmacenAUTO ================================================================


// ================================================= crearAlmacen ================================================================
void CrearAlmacen(ConjuntoAlmacen10 almacenes,int& indice) {
  int borrame;
  if (indice < 10) {

    escanearAlmacen(almacenes,indice);


  } else {
    printf("\nIntroduzca el almacen que quiere borrar");
    scanf("%d",&borrame);

    if (borrame < 1  ||  borrame > 10) {
      while (borrame < 1  ||  borrame > 10) {
        printf("\nDicha almacen no existe. Introduzca el almacen que quiere borrar ");
        scanf("%d",&borrame);
      }
    }
    borrame = borrame-1;

    strcpy(almacenes[borrame].calle, "\0");
    strcpy(almacenes[borrame].municipio, "\0");
    strcpy(almacenes[borrame].provincia, "\0");
    strcpy(almacenes[borrame].descripcion, "\0");
    almacenes[borrame].kaciente.liberarMemoria(almacenes[borrame].primero);
    almacenes[borrame].primero = NULL;
    almacenes[borrame].Global = 1;
    almacenes[borrame].ContadorGlobal = 1;
    fflush(stdin);
    escanearAlmacen(almacenes,borrame);


  }

  return;
}
// ================================================= crearAlmacen ================================================================


// ================================================= escanearAlmacen ================================================================
void escanearAlmacen(ConjuntoAlmacen10 almacenes,int& indice) {
  tipocadena48  descrip,dire,muni;
  tipocadena16 pro;
  char opcion;

  do {

    printf("\nDirreccion almacen? (entre 1 y 48 caracteres) ");
    scanf("%[^\n]",&dire);
    fflush(stdin);
    printf("\nMunicipio almacen? (entre 1 y 48 caracteres) ");
    scanf("%[^\n]",&muni);
    fflush(stdin);
    printf("\nProvincia almacen? (entre 1 y 16 caracteres) ");
    scanf("%[^\n]",&pro);
    fflush(stdin);
    printf("\ndescripcion almacen? (entre 1 y 48 caracteres)" );
    scanf("%[^\n]",&descrip);
    fflush(stdin);
    printf("\nDatos correctos (S/N)? ");
    scanf("%s",&opcion);
    fflush(stdin);
    opcion = toupper(opcion);

  } while (opcion != 'S');


  strcpy(almacenes[indice].calle, dire);
  strcpy(almacenes[indice].municipio, muni);
  strcpy(almacenes[indice].provincia, pro);
  strcpy(almacenes[indice].descripcion, descrip);
  almacenes[indice].primero = NULL;
  almacenes[indice].Global = 1;
  almacenes[indice].ContadorGlobal = 1;
  almacenes[indice].ref = indice + 1;
  indice = indice + 1;

  return;
}
// ================================================= escanearAlmacen ================================================================



// ================================================= AltaPacienteAlmacen ================================================================
void AltaPacienteAlmacen(ConjuntoAlmacen10 almacenes,int indice) {
  int codAl;
  printf("\nCodigo Almacen ");
  scanf("%d",&codAl);
  if (codAl < 1 || codAl >indice) {
    printf("\nAlmacen incorrecto");

  } else {

    codAl = codAl-1;
    escanearPacienteAlmacen(almacenes,indice,codAl);
  }
  return;
}
// ================================================= AltaPacienteAlmacen ================================================================

// ================================================= escanearPacienteAlmacen ================================================================
void escanearPacienteAlmacen(ConjuntoAlmacen10 almacenes,int indice,int codAl) {

  almacenes[codAl].kaciente.AnadirPaciente(almacenes[codAl].primero,almacenes[codAl].Global);
return;
}
// ================================================= escanearPacienteAlmacen ================================================================




void UbicarPacienteAlmacen(ConjuntoAlmacen10 almacenes,int indice) {//metodo para proteger
  int codAl;
  printf("\nCodigo Almacen ");
  scanf("%d",&codAl);
  if (codAl < 1 || codAl >indice) {
    printf("\nAlmacen incorrecto");

  } else {

    codAl = codAl-1;
    ImprimirPacienteAlmacen(almacenes,indice,codAl);
  }

  return;
}
// ================================================= UbicarPacienteAlmacen ================================================================

void ImprimirPacienteAlmacen(ConjuntoAlmacen10 almacenes,int indice,int codAl) {

  almacenes[codAl].kaciente.imprimirLista(almacenes[codAl].primero);
return;
}
// ================================================= ImprimirPacienteAlmacen ================================================================


void AnadirPedidosAlmacen(ConjuntoAlmacen10 almacenes,int indice) {//metodo para proteger
  int codAl;
  printf("\nCodigo Almacen ");
  scanf("%d",&codAl);
  if (codAl < 1 || codAl >indice) {
    printf("\nAlmacen incorrecto");

  } else {

    codAl = codAl-1;
    EscanearPedidoAlmacen(almacenes,indice,codAl);
  }
  return;
}
// ================================================= AnadirPedidosAlmacen ================================================================

void EscanearPedidoAlmacen(ConjuntoAlmacen10 almacenes,int indice,int codAl) {



  almacenes[codAl].kaciente.CrearPedido(almacenes[codAl].PedidosTotales,almacenes[codAl].ContadorGlobal,almacenes[codAl].primero);


return;
}


void ImprimirPedidoAlmacen(ConjuntoAlmacen10 almacenes,int indice) {//metodo para proteger
  int codAl;
  printf("\nCodigo Almacen? ");
  scanf("%d",&codAl);
  if (codAl < 1 || codAl >indice) {
    printf("\nAlmacen incorrecto");

  } else {

    codAl = codAl-1;


    UbicarPedidoAlmacen(almacenes,indice,codAl);
  }
  return;
}
// ================================================= ImprimirPedidoAlmacen ================================================================

void UbicarPedidoAlmacen(ConjuntoAlmacen10 almacenes,int indice,int codAl) {

  printf("\nPedido ALMACEN - %s\n",almacenes[codAl].descripcion);

  almacenes[codAl].kaciente.ListarPedidos(almacenes[codAl].PedidosTotales,almacenes[codAl].ContadorGlobal,almacenes[codAl].primero);

 return;
}
// ================================================= UbicarPedidoAlmacen ================================================================


void ProgramarRutas(ConjuntoAlmacen10 almacenes,int indiceAlmacen) {
  int codAl,Cdia,Cmes,Canno,unidades;
  bool hayPedido;
  conjuntoPedido PedidosActivos;

  unidades = 0;  //Indidce vector PedidosActivos
  hayPedido = false;
  printf("\nCodigo Almacen ");
  scanf("%d",&codAl);
  if (codAl < 1 || codAl >indiceAlmacen) {

    printf("\nAlmacen incorrecto");
  } else {
    codAl = codAl-1;



    printf("\nDia?");
    scanf("%d",&Cdia);

    printf("\nMes");
    scanf("%d",&Cmes);

    printf("\nAno");
    scanf("%d",&Canno);


    for (int i = 0; i <= almacenes[codAl].ContadorGlobal; i++) {

      if (Canno == almacenes[codAl].PedidosTotales[i].ano ) {
        if (Cmes == almacenes[codAl].PedidosTotales[i].mes) {
          if (Cdia == almacenes[codAl].PedidosTotales[i].dia) {
            PedidosActivos[unidades] = almacenes[codAl].PedidosTotales[i];
            unidades = unidades + 1;
            hayPedido = true;

          }

        }

      }

      if (almacenes[codAl].PedidosTotales[i].nEnvio > 1) {
        if (almacenes[codAl].kaciente.comprobarDias(almacenes[codAl].PedidosTotales[i],Cdia,Cmes,Canno)) {
          PedidosActivos[unidades] = almacenes[codAl].PedidosTotales[i];
          unidades = unidades + 1;
          hayPedido = true;

        }
      }

    }// ================================================FOR

    if (hayPedido) {
      //llamar a imprimr calcular rutas
      printf("\nNumero de pedidos que hay ese dia: %d \n",unidades);
      CalcularRuta(almacenes[codAl],PedidosActivos,unidades);
      // CalcularRuta(almacenes[codAl],PedidosActivos,unidades);
    }
    //si no hay pedido no es necesario

  }
 return;
}//fin fun
// ================================================= ProgramarRutas ================================================================


void CalcularRuta(almacen actual,conjuntoPedido PedidosActivo,int unidades) {
  float x,y,x1,y1,SumaDistancia,bateriaGastada;
  int a,b,c,d,PesoTotal,ruta,ultimopeso, protecciondistancia;
  Pedido auxiliar;

  PesoTotal = 0;
  bateriaGastada = 0;
  SumaDistancia = 0;
  ruta = 1;


  for (int i = 0 ;i < unidades;i++) { //ordena los pedidos segun el angulo
    for (int j = i+1; j < unidades;j++) {

      actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i].refPaciente,b,a);//b angulo, a distancia
      actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[j].refPaciente,c,d);//b angulo, a di

//if para ordenar segun peso:: if(PedidosActivo[i].pesoTotal<PedidosActivo[j].pesoTotal)
//para ordenar por angulo: (b > c)
      if (b > c) {
        auxiliar = PedidosActivo[i];
        PedidosActivo[i] =  PedidosActivo[j];
        PedidosActivo[j] = auxiliar;
      }

    }
  }  //fin del for para ORDENAR PEDIDOS SEGUN EL ANGULO



  for (int i = 0 ;i < unidades;i++) {
    if (PesoTotal + PedidosActivo[i].pesoTotal <= 3000) {
      PesoTotal = PesoTotal + PedidosActivo[i].pesoTotal;
      ultimopeso = i;
    } else {

      if ( i == 0) {
        ultimopeso  = 0;
      } else {
        ultimopeso  = i-1;
      }
      i = 999;
    }
  }


  printf("\n Ruta %d\n",ruta);
  actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[0].refPaciente,b,a);//b angulo, a distancia
  x = actual.kaciente.calcularX(b,a);
  y = actual.kaciente.calcularY(b,a);
  x1 = 0;
  y1= 0;

  printf("\nOrigen  a Cliente %d  - Distancia Recorrida %.2f  Angulo %d  Peso %d  gramos \n",PedidosActivo[0].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),b,PesoTotal);

  bateriaGastada = bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1));
  PesoTotal = PesoTotal - PedidosActivo[0].pesoTotal;
  SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);


  for (int i = 0 ;i < unidades-1;i++) {

    actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i].refPaciente,b,a);//b angulo, a distancia
    actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i+1].refPaciente,c,d);//b angulo, a di
    x = actual.kaciente.calcularX(b,a);
    y = actual.kaciente.calcularY(b,a);
    x1 = actual.kaciente.calcularX(c,d);
    y1= actual.kaciente.calcularY(c,d);

   protecciondistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1) + actual.kaciente.moduloVector(x1,y1,0,0);

 //if ((bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1)))>= 30000000 || (PesoTotal <= 0) || (SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1)> 20000) || (protecciondistancia > 20000) ) {


 if ((bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1)))>= 30000000 || (PesoTotal <= 0) || (SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1)> 25000)
    || (protecciondistancia > 25000)
     ||   (  (5000-(  ((bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1))  )*5000 )/ 30000000))  +20000)  < (SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1))
                 ) {

      actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i].refPaciente,b,a);//b angulo, a distancia
      x = actual.kaciente.calcularX(b,a);
      y = actual.kaciente.calcularY(b,a);
      x1 = 0;
      y1= 0;
      SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);
      printf("\nCliente %d a origen - Distancia Recorrida %.2f  Angulo %.0f  Peso %d  gramos \n",PedidosActivo[i].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),AnguloEje(x,y,x1,y1),PesoTotal);
      printf("\n  Distancia total de la ruta: %.2f\n",SumaDistancia);
      SumaDistancia = 0;
      bateriaGastada = 0;
      ruta = ruta +1;




      printf("\nRuta %d\n",ruta);

      actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i+1].refPaciente,b,a);//b angulo, a distancia
      x = actual.kaciente.calcularX(b,a);
      y = actual.kaciente.calcularY(b,a);
      x1 = 0;
      y1= 0;

      for (int j = ultimopeso+1 ;j < unidades;j++) {
        if (PesoTotal + PedidosActivo[j].pesoTotal <=3000) {
          PesoTotal = PesoTotal + PedidosActivo[j].pesoTotal;
          ultimopeso = j;
        } else {
          if (j == 0) {
            ultimopeso = 0;
          } else {
            ultimopeso = j-1;
          }

          j = 999;
        }
      }


      bateriaGastada = bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1));
      SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);
      printf("\nOrigen a Cliente %d  - Distancia Recorrida %.2f  Angulo %d  Peso %d  gramos \n",PedidosActivo[i+1].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),b,PesoTotal);
      PesoTotal = PesoTotal - PedidosActivo[i+1].pesoTotal;

    } else {

      bateriaGastada = bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1));
      SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);
      printf("\nCliente %d a Cliente %d  - Distancia Recorrida %.2f  Angulo %.0f  Peso %d  gramos \n",PedidosActivo[i].refPaciente,PedidosActivo[i+1].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),AnguloEje(x,y,x1,y1),PesoTotal);
      //if ( i == (unidades-2)){ PesoTotal = PesoTotal - PedidosActivo[i+1].pesoTotal;}else{PesoTotal = PesoTotal - PedidosActivo[i+1].pesoTotal;}

      PesoTotal = PesoTotal - PedidosActivo[i+1].pesoTotal;
    }
  }


  actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[unidades-1].refPaciente,b,a);//b angulo, a distancia
  x = actual.kaciente.calcularX(b,a);
  y = actual.kaciente.calcularY(b,a);
  x1 = 0;
  y1= 0;
  SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);
  printf("\nCliente %d a origen - Distancia Recorrida %.2f  Angulo %.0f  Peso %d  gramos \n",PedidosActivo[unidades-1].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),AnguloEje(x,y,x1,y1),PesoTotal);
  printf("\n  DISTACIA TOTAL DE LA RUTA -  %.2f\n",SumaDistancia);
  // printf("Bateria gastada: %.1f\n", bateriaGastada);
  return;
}
// ================================================= CalcularRuta ================================================================



void imprimirAlmacenAUTOMATICO(ConjuntoAlmacen10 almacenes,int codAl) {

  printf("\n\nAlmacen %d - %s - %s - %s \n    Descripcion: %s\n\n", almacenes[codAl].ref, almacenes[codAl].calle, almacenes[codAl].municipio, almacenes[codAl].provincia, almacenes[codAl].descripcion);

return;
}


void UbicarPedidoAlmacenAUTOMATICO(ConjuntoAlmacen10 almacenes,int indice,int codAl) {

  almacenes[codAl].kaciente.ListarPedidosAUTOMATICO(almacenes[codAl].PedidosTotales,almacenes[codAl].ContadorGlobal,almacenes[codAl].primero);
  //almacenes[codAl].kaciente.CrearPedido(

}
// ================================================= UbicarPedidoAlmacen ================================================================




void imprimirInicio(ConjuntoAlmacen10 almacenes,int indice) {


  for (int i = 0; i < 10; i++) {


    if (almacenes[i].provincia[0] != '\0') {


      imprimirAlmacenAUTOMATICO(almacenes, i);
      ImprimirPacienteAlmacen(almacenes,almacenes[i].Global, i);
      UbicarPedidoAlmacenAUTOMATICO(almacenes,almacenes[i].ContadorGlobal, i);

    }




  }
  return;
}// ================================================= imprimirInicio ================================================================


int xaVentana(float x) {
  int xV;


  if ( x == 0 ) {
    xV = 400;
    return xV;
  } else if (x < 0) { // x NEGATIVAS
    x = x * (-1) ;
    xV = (((x*380)/10000)) - 400;
    if (xV < 0) {
      xV = xV * (-1);
    }
    return xV;
  } else if ( x > 0) {  //X POSITIVAS
    xV = (x*380)/10000 + 400;
    return xV;
  }


}

int yaVentana(float y) {
  int xV;


  if ( y == 0 ) {
    xV = 400;
    return xV;
  } else if (y < 0) {   //Y POSITIVAS
    y = y * (-1) ;
    xV = (((y*380)/10000)) + 400;
    if (xV < 0) {
      xV = xV * (-1);
    }
    return xV;
  } else if ( y > 0) {  // Y NEGATIVAS
    xV = (y*380)/10000 - 400;
    if (xV < 0) {
      xV = xV * (-1);
    }
    return xV;
  }
}



void ProgramarImprimirRutas(ConjuntoAlmacen10  almacenes,int indiceAlmacen) {
  int codAl,Cdia,Cmes,Canno,unidades;
  bool hayPedido;
  conjuntoPedido PedidosActivos;

  unidades = 0;  //Indidce vector PedidosActivos
  hayPedido = false;
  printf("\nCodigo Almacen ");
  scanf("%d",&codAl);
  if (codAl < 1 || codAl >indiceAlmacen) {

    printf("\nAlmacen incorrecto");
  } else {
    codAl = codAl-1;



    printf("\nDia?");
    scanf("%d",&Cdia);

    printf("\nMes");
    scanf("%d",&Cmes);

    printf("\nAno");
    scanf("%d",&Canno);


    for (int i = 0; i <= almacenes[codAl].ContadorGlobal; i++) {

      if (Canno == almacenes[codAl].PedidosTotales[i].ano ) {
        if (Cmes == almacenes[codAl].PedidosTotales[i].mes) {
          if (Cdia == almacenes[codAl].PedidosTotales[i].dia) {
            PedidosActivos[unidades] = almacenes[codAl].PedidosTotales[i];
            unidades = unidades + 1;
            hayPedido = true;

          }

        }

      }

      if (almacenes[codAl].PedidosTotales[i].nEnvio > 1) {
        if (almacenes[codAl].kaciente.comprobarDias(almacenes[codAl].PedidosTotales[i],Cdia,Cmes,Canno)) {
          PedidosActivos[unidades] = almacenes[codAl].PedidosTotales[i];
          unidades = unidades + 1;
          hayPedido = true;

        }
      }

    }// ================================================FOR

    if (hayPedido) {
      //lamar a imprimr calcular rutas
      printf("\nNumero de pedidos que hay ese dia: %d \n",unidades);
      ImprimirRutas(almacenes[codAl],PedidosActivos,unidades);
      //  CalcularRuta(almacenes[codAl],PedidosActivos,unidades);
    }
    //si no hay pedido no es necesario

  }
 return;
}//fin fun
// ================================================= ProgramarRutas ================================================================



void ImprimirRutas(almacen actual,conjuntoPedido PedidosActivo,int unidades) {

  int xV, xV1, yV, yV1;
  float x,y,x1,y1,SumaDistancia,bateriaGastada, protecciondistancia;
  int a,b,c,d,PesoTotal,ruta,ultimopeso;
  Pedido auxiliar;
  tipocadena16 imprimible;

  PesoTotal = 0;
  bateriaGastada = 0;
  SumaDistancia = 0;
  ruta = 1;

  initwindow(800,800,"REPRESENTACION RUTAS DRON 800x800pixeles");
  // -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32    -> Configuracion -> Compilador y depurador ->Configuracion de montaje -> otras opciones de montaje



//EJES DE COORDENADAS  0 0
  setcolor (WHITE);
  line ( 0,400, 800, 400);
  line ( 400, 0, 400, 800);

  setcolor (WHITE);
  circle(400, 400, 380);

  outtextxy( 230,3, "este es el Limite del Radio del Dron: 10.000 metros.");
  outtextxy( 625,3, "Para Cerrar ESTA ventana:");
  outtextxy( 660,17, "pinche esta ventana");
  outtextxy( 660,32, "y pulse una letra");

  setcolor (YELLOW);


  for (int i = 0 ;i < unidades;i++) { //ordena los pedidos segun el angulo
    for (int j = i+1; j < unidades;j++) {

      actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i].refPaciente,b,a);//b angulo, a distancia
      actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[j].refPaciente,c,d);//b angulo, a di

//if para ordenar segun peso:: if(PedidosActivo[i].pesoTotal<PedidosActivo[j].pesoTotal)
//para ordenar por angulo: (b > c)
      if (b > c) {
        auxiliar = PedidosActivo[i];
        PedidosActivo[i] =  PedidosActivo[j];
        PedidosActivo[j] = auxiliar;
      }

    }
  }  //fin del for para ORDENAR PEDIDOS SEGUN EL ANGULO


  for (int i = 0 ;i < unidades;i++) {
    if (PesoTotal + PedidosActivo[i].pesoTotal <= 3000) {
      PesoTotal = PesoTotal + PedidosActivo[i].pesoTotal;
      ultimopeso = i;
    } else {

      if ( i == 0) {
        ultimopeso  = 0;
      } else {
        ultimopeso  = i-1;
      }
      i = 999;
    }
  }




  printf("\n Ruta %d\n",ruta);
  actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[0].refPaciente,b,a);//b angulo, a distancia
  x = actual.kaciente.calcularX(b,a);
  y = actual.kaciente.calcularY(b,a);
  x1 = 0;
  y1= 0;


  printf("\nOrigen  a Cliente %d  - Distancia Recorrida %.2f  Angulo %d  Peso %d  gramos \n",PedidosActivo[0].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),b,PesoTotal);
  xV = xaVentana(x);
  xV1 = xaVentana(x1);
  yV = yaVentana(y);
  yV1 = yaVentana(y1);
  setcolor (YELLOW);

   setcolor (WHITE);
  circle(400, 400, 10);

  sprintf(imprimible,"Almacen %s",actual.descripcion);
      outtextxy( 3, 775, imprimible);


  Sleep(1000);
  setcolor (YELLOW);
  line( xV, yV, xV1, yV1);
  setcolor (RED);
  circle(xV, yV, 10);
  setcolor (YELLOW);
  setcolor (CYAN);
  sprintf(imprimible,"cliente %d",PedidosActivo[0].refPaciente);
  outtextxy( xV-20, yV+5, imprimible);
  setcolor(YELLOW);
  bateriaGastada = bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1));
  PesoTotal = PesoTotal - PedidosActivo[0].pesoTotal;
  SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);


  for (int i = 0 ;i < unidades-1;i++) {
    actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i].refPaciente,b,a);//b angulo, a distancia
    actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i+1].refPaciente,c,d);//b angulo, a di
    x = actual.kaciente.calcularX(b,a);
    y = actual.kaciente.calcularY(b,a);
    x1 = actual.kaciente.calcularX(c,d);
    y1= actual.kaciente.calcularY(c,d);

   protecciondistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1) + actual.kaciente.moduloVector(x1,y1,0,0);

  //if ((bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1)))>= 30000000 || (PesoTotal <= 0) || (SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1)> 20000) || (protecciondistancia > 20000) ) {

 if ((bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1)))>= 30000000 || (PesoTotal <= 0) || (SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1)> 25000)
    || (protecciondistancia > 25000)
     ||   (  (5000-(  ((bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1))  )*5000 )/ 30000000))  +20000)  < (SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1))
                 ) {
 //printf("\nproteccion 4 es: %.0f\n", (  (5000- (  ((bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1))  )*5000 )/ 30000000)) +20000 )    );
  //printf("\nproteccion 4 es: %f \n", (  (5000- (  (20000000*5000.0 )/ 30000000)) +20000 )    );
      actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i].refPaciente,b,a);//b angulo, a distancia
      x = actual.kaciente.calcularX(b,a);
      y = actual.kaciente.calcularY(b,a);
      x1 = 0;
      y1= 0;
      SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);

      printf("\nCliente %d a origen - Distancia Recorrida %.2f  Angulo %.0f  Peso %d  gramos \n",PedidosActivo[i].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),AnguloEje(x,y,x1,y1),PesoTotal);
      xV = xaVentana(x);
      xV1 = xaVentana(x1);
      yV = yaVentana(y);
      yV1 = yaVentana(y1);
      setcolor (YELLOW);

      Sleep(1000);

      line( xV, yV, xV1, yV1);
      setcolor (RED);
      circle(xV, yV, 10);
      setcolor (YELLOW);
      setcolor (CYAN);
      sprintf(imprimible,"cliente %d",PedidosActivo[i].refPaciente);
      outtextxy( xV-20, yV+5, imprimible);
      setcolor(YELLOW);
      printf("\n  Distancia total de la ruta -  %.2f\n",SumaDistancia);
      //printf("Bateria gastada: %.1f\n", bateriaGastada);
      SumaDistancia = 0;
      bateriaGastada = 0;
      ruta = ruta +1;




      printf("\nRuta %d\n",ruta);
      actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[i+1].refPaciente,b,a);//b angulo, a distancia
      x = actual.kaciente.calcularX(b,a);
      y = actual.kaciente.calcularY(b,a);
      x1 = 0;
      y1= 0;

      for (int j = ultimopeso+1 ;j < unidades;j++) {
        if (PesoTotal + PedidosActivo[j].pesoTotal <=3000) {
          PesoTotal = PesoTotal + PedidosActivo[j].pesoTotal;
          ultimopeso = j;
        } else {
          if (j == 0) {
            ultimopeso = 0;
          } else {
            ultimopeso = j-1;
          }

          j = 999;
        }
      }


      bateriaGastada = bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1));
      SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);
      printf("\nOrigen a Cliente %d  - Distancia Recorrida %.2f  Angulo %d  Peso %d  gramos \n",PedidosActivo[i+1].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),b,PesoTotal);
      PesoTotal = PesoTotal - PedidosActivo[i+1].pesoTotal;
      xV = xaVentana(x);
      xV1 = xaVentana(x1);
      yV = yaVentana(y);
      yV1 = yaVentana(y1);
      setcolor (YELLOW);

      Sleep(1000);
      line( xV, yV, xV1, yV1);
      setcolor (RED);
      circle(xV, yV, 10);
      setcolor (YELLOW);
      setcolor (CYAN);
      sprintf(imprimible,"cliente %d",PedidosActivo[i+1].refPaciente);
      outtextxy( xV-20, yV+5, imprimible);
      setcolor(YELLOW);

    } else {

      bateriaGastada = bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1));
      SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);
      printf("\nCliente %d a Cliente %d  - Distancia Recorrida %.2f  Angulo %.0f  Peso %d  gramos \n",PedidosActivo[i].refPaciente,PedidosActivo[i+1].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),AnguloEje(x,y,x1,y1),PesoTotal);

      xV = xaVentana(x);
      xV1 = xaVentana(x1);
      yV = yaVentana(y);
      yV1 = yaVentana(y1);
      setcolor(YELLOW);

      Sleep(1000);
      line( xV, yV, xV1, yV1);
      setcolor (RED);
      circle(xV, yV, 10);
      setcolor (CYAN);
      sprintf(imprimible,"cliente %d",PedidosActivo[i].refPaciente);
      outtextxy( xV-20, yV+5, imprimible);
      setcolor(YELLOW);

      PesoTotal = PesoTotal - PedidosActivo[i+1].pesoTotal;
    }
  }

  actual.kaciente.devolverPaciente(actual.primero,PedidosActivo[unidades-1].refPaciente,b,a);//b angulo, a distancia
  x = actual.kaciente.calcularX(b,a);
  y = actual.kaciente.calcularY(b,a);
  x1 = 0;
  y1= 0;
  SumaDistancia = SumaDistancia + actual.kaciente.moduloVector(x,y,x1,y1);
  printf("\nCliente %d a origen - Distancia Recorrida %.2f  Angulo %.0f  Peso %d  gramos \n",PedidosActivo[unidades-1].refPaciente,actual.kaciente.moduloVector(x,y,x1,y1),AnguloEje(x,y,x1,y1),PesoTotal);
  printf("\n  Distancia total de la ruta: %.2f\n",SumaDistancia);
  //printf("\nproteccion 4 es: %.0f\n", (  (5000- (  ((bateriaGastada + (PesoTotal*actual.kaciente.moduloVector(x,y,x1,y1))  )*5000 )/ 30000000)) +20000 )    );
 //  printf("Bateria gastada: %.1f\n", bateriaGastada);
  xV = xaVentana(x);
  xV1 = xaVentana(x1);
  yV = yaVentana(y);
  yV1 = yaVentana(y1);
  setcolor(YELLOW);

  Sleep(1000);
  line( xV, yV, xV1, yV1);
  setcolor (RED);
  circle(xV, yV, 10);
  setcolor (CYAN);
  sprintf(imprimible,"cliente %d",PedidosActivo[unidades-1].refPaciente);
  outtextxy( xV-20, yV+5, imprimible);
  setcolor(YELLOW);
//moveto(370,410);


  //outtextxy(370, 410, "ALMACEN");


  printf("\n    CUIDADO:  si pincha la X de la VENTANA DE RUTAS para cerrarla \n    saldra de Gestion-Farmadron\n");
  printf("\n    PARA VOLVER AL MENU DE GESTION-FARMAFRON: PINCHE LA VENTANA DE RUTAS \n    Y PULSE EN EL TECLADO CUALQUIER LETRA\n");



  getch();
  closegraph();
  return;
}


float AnguloVectorTriangulo(float x1, float y1, float x2, float y2){
 float angulo, divi, ox1, ox2, oy1, oy2;



 ox1 = x1 + (x1 * (-1))  ;
 oy1 = y1 + (y1 * (-1))  ;

 ox2 = x2 + (x1 * (-1))  ;
 oy2 = y2 + (y1 * (-1))  ;


 if (oy2 < 0){
   oy2 = oy2 * (-1);}
   if(ox2 < 0){
    ox2 = ox2 * (-1); }

 divi =  ( oy2 / ox2 );
    angulo = atan(divi) ;




  angulo = (angulo / 0.01745329252);


  return angulo;
}


float AnguloEje( float x1, float y1, float x2, float y2 ){
   float DevolverAngulo;


 x2 = x2 + (x1 * (-1))  ;
 y2 = y2 + (y1 * (-1))  ;


 x1 = x1 + (x1 * (-1))  ;
 y1 = y1 + (y1 * (-1))  ;



 //printf ("el angulo es: %.0f", DevolverAngulo);
   if ( y2 == 0 && x2 > 0){
     DevolverAngulo = 0;
   //printf ("el angulo es: %.0f", DevolverAngulo);
     return DevolverAngulo;


   } else if ( x2 > 0 && y2 > 0){                          //primer cuadrante
   DevolverAngulo = AnguloVectorTriangulo(x1, y1, x2, y2);
   DevolverAngulo = DevolverAngulo * 2000 / 360;
  // printf ("el angulo es: %.0f", DevolverAngulo);
   return DevolverAngulo;

   } else if ( x2 == 0 && y2 > 0){
     DevolverAngulo = 500;
    // printf ("el angulo es: %.0f", DevolverAngulo);
     return DevolverAngulo;

   } else if ( x2 < 0 && y2 > 0){                        //segundo cuadrante
     DevolverAngulo = AnguloVectorTriangulo(x1, y1, x2, y2);
     DevolverAngulo = (DevolverAngulo - 90) * (-1);
     DevolverAngulo = DevolverAngulo + 90;
   DevolverAngulo = DevolverAngulo * 2000 / 360;
 // printf ("el angulo es: %.0f", DevolverAngulo);
   return DevolverAngulo;
   } else if ( y2 == 0 && x2 < 0){
     DevolverAngulo = 1000;
    // printf ("el angulo es: %.0f", DevolverAngulo);

     return DevolverAngulo;

   } else if ( x2 < 0 && y2 < 0){                        //tercer cuadrante
     DevolverAngulo = AnguloVectorTriangulo(x1, y1, x2, y2);
     DevolverAngulo = DevolverAngulo + 180;
   DevolverAngulo = DevolverAngulo * 2000 / 360;
  // printf ("el angulo es: %.0f", DevolverAngulo);
   return DevolverAngulo;

   } else if ( x2 == 0 && y2 < 0){
    DevolverAngulo = 1500;
  //  printf ("el angulo es: %.0f", DevolverAngulo);
    return  DevolverAngulo;

   } else if ( x2 > 0 && y2 < 0){                         //cuarto cuadrante
     DevolverAngulo = AnguloVectorTriangulo(x1, y1, x2, y2);
     DevolverAngulo = (DevolverAngulo -90 ) *(-1);
     DevolverAngulo = DevolverAngulo + 270;
   DevolverAngulo = DevolverAngulo * 2000 / 360;
  // printf ("el angulo es: %.0f", DevolverAngulo);
   return DevolverAngulo;
   }


}




