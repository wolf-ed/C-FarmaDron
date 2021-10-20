# Farmadron

## Table of contents
* [Introduction](#Introduction)
* [Technologies](#Technologies)
* [Compiling](#Compiling)
* [Examples](#Examples)


## Introduction
This software emulates a company that can perform these behaviours:
* Create new stores
* Create new clients per store, with name and adress
* Create shipments per clients
* Print shipments per client, or per date
* Draw the route a Drone would follow to deliver the shipments of a given day, having into consideration the weight of each shipments, their addresses(distance from the shop) and the batery and power of the drone.

In this Repository you have available an executable file where you can try all the functionalities, as well as the source code.

## Technologies

This project uses the following technologies:
* C language
* Code::Blocks IDE
* WinBGIm_Library6_0_Nov2005

## Compiling

To compile this project the IDE used was Code::Blocks IDE, and these changes are necesary to add the graphic library:

Go to configuration ->
compile and debug ->
assembly configuration -> 
another assembly options -> paste: 


-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 


#### In Spanish:
pegar en -> Configuracion -> Compilador y depurador ->Configuracion de montaje -> otras opciones de montaje:   -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 

## Examples

First thing when you open the program, is to press i to initialize the default data with default clients, stores and shipments. After that you can try the different funtionalities without having to introduce new data, but you can introduce new data nontheless.

[0](https://user-images.githubusercontent.com/91706719/138182268-d25e23d1-5bc2-43d9-a6e2-9b5703093385.png)
!![2](https://user-images.githubusercontent.com/91706719/138182288-68077f08-a6f3-4b3a-94c7-4e679cfecaba.png)
![3](https://user-images.githubusercontent.com/91706719/138182309-119bb09c-3729-4557-9399-2c4886c45656.png)

