/***************************************
* NOMBRE: #Ed Wolf#
* EMAIL: #wolf7ed@gmail.com#
* DATE: 12/2020
***************************************/

/*
Interfaz Paciente
*/


#pragma once




typedef char TipoCadena[20];
typedef int GuardaDias[31];


typedef struct TipoPaciente {
  int ref, distancia, angulo, grados;
  float x, y;
  TipoCadena identificador;
  TipoPaciente* siguiente;
};

typedef TipoPaciente* punteroPaciente;

typedef char cadena[20];


typedef struct TipoFarmaco {
  cadena Nombre;
  int peso;
};


typedef struct FarmacoPedido {
  TipoFarmaco farmaco;
  int unidades;
};


typedef struct Pedido {
  int refPaciente,dia,mes,ano,nEnvio,frecuencia,farmacosDisponibles,pesoTotal;
  FarmacoPedido A,B,C,D,E;
};


typedef Pedido conjuntoPedido[100];


typedef struct TipoKaciente {



  void imprimirP(punteroPaciente  paciente);
  void imprimirLista(punteroPaciente grupo);
  bool devolverPaciente(punteroPaciente grupo,int pacienteNum,int& an,int & dist);
  void escanearPaciente(punteroPaciente& grupo,int& refGlobal);
  void imprimirFarmaco(Pedido ped);
  void AnadirPaciente(punteroPaciente& grupo,int& refGlobal);
  void liberarMemoria(punteroPaciente& grupo);



  float aGrados(int radianes); //linea 171 paciente.cpp
  float AnguloTriangulo(float grados);
  float calcularX(int radianes, int longitud);
  float calcularY(int radianes, int longitud);
  float moduloVector(float x1, float y1, float x2, float y2);
  bool devolverXY(punteroPaciente grupo,int pacienteNum,float& xx,float& yy);



  void CrearPedido(conjuntoPedido PedidosTotales,int& contadorGlobal,punteroPaciente grupo);
  void ListarPedidos(conjuntoPedido PedidosTotales,int contadorGlobal,punteroPaciente primero);
  bool comprobarDias(Pedido compruebame,int diaa,int mess,int anno);
  void FechaNueva(int dias,int& diaa,int& mess,int& anno);
  int FinalizaMes2(int Mes,int Anno2);

  //void comprobarDiasCalendario(Pedido compruebame,int diaa,int mess,int anno);
  bool ProteccionPaciente(int refGlobal);
  int pesoPedido(Pedido ped);
  void AnadirPacienteAutomatica(punteroPaciente& grupo,int& refGlobal,TipoCadena identificadorr, int distanciaa,int aangulo); //anadirPacienteAuto
  void escanearPacienteAuto(punteroPaciente& grupo,int& refGlobal,TipoCadena identificadorr, int distanciaa,int aangulo);
  void CrearPedidoAuto(conjuntoPedido PedidosTotales,int& contadorGlobal,int pa,int di,int me,int an,int nEn,int fre,FarmacoPedido AA,FarmacoPedido BB,FarmacoPedido CC,FarmacoPedido DD,FarmacoPedido EE);
  int PesoFarmaco(Pedido ped);


  void imprimirFarmacoAUTOMATICO(Pedido ped);
  void ListarPedidosAUTOMATICO(conjuntoPedido PedidosTotales,int contadorGlobal,punteroPaciente primero);

};
