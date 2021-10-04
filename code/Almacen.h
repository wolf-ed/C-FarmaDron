/***************************************
* NOMBRE: #Ed Wolf#
* EMAIL: #wolf7ed@gmail.com#
* DATE: 12/2020
***************************************/


#pragma once

typedef char tipocadena48[48];
typedef char tipocadena16[16];




typedef struct almacen {
  int ref,Global, ContadorGlobal;
  tipocadena48 calle,municipio,descripcion;
  tipocadena16 provincia;
  TipoKaciente kaciente; // kaciente
  punteroPaciente primero;
  conjuntoPedido PedidosTotales;
};

typedef almacen ConjuntoAlmacen10[10];

void IniciarGestion(ConjuntoAlmacen10 almacenes,int& indice);
void CrearAlmacen(ConjuntoAlmacen10 almacenes,int& indice);   //incluye BORRAR ALMACEN
void CrearAlmacenAuto(ConjuntoAlmacen10 almacenes,int& indice, tipocadena48  descrip,tipocadena48 dire,tipocadena48 muni,tipocadena16 pro);
void escanearAlmacen(ConjuntoAlmacen10 almacenes,int& indice);
void AltaPacienteAlmacen(ConjuntoAlmacen10 almacenes,int indice);
void escanearPacienteAlmacen(ConjuntoAlmacen10 almacenes,int indice,int codAl);
void UbicarPacienteAlmacen(ConjuntoAlmacen10 almacenes,int indice);
void ImprimirPacienteAlmacen(ConjuntoAlmacen10 almacenes,int indice,int codAl);
void AnadirPedidosAlmacen(ConjuntoAlmacen10 almacenes,int indice);
void EscanearPedidoAlmacen(ConjuntoAlmacen10 almacenes,int indice,int codAl);
void ImprimirPedidoAlmacen(ConjuntoAlmacen10 almacenes,int indice);
void UbicarPedidoAlmacen(ConjuntoAlmacen10 almacenes,int indice,int codAl); //ubicar pedido almacen
void ProgramarRutas(ConjuntoAlmacen10  almacenes,int indiceAlmacen);
void CalcularRuta(almacen actual,conjuntoPedido PedidosActivo,int unidades);

float AnguloVectorTriangulo(float x1, float y1, float x2, float y2);
float AnguloEje( float x1, float y1, float x2, float y2 );

void UbicarPedidoAlmacenAUTOMATICO(ConjuntoAlmacen10 almacenes,int indice,int codAl);
void imprimirAlmacenAUTOMATICO(ConjuntoAlmacen10 almacenes,int codAl);
void imprimirInicio(ConjuntoAlmacen10 almacenes,int indice);


void ProgramarImprimirRutas(ConjuntoAlmacen10  almacenes,int indiceAlmacen);
void ImprimirRutas(almacen actual,conjuntoPedido PedidosActivo,int unidades);

int xaVentana(float x);
int yaVentana(float y);


