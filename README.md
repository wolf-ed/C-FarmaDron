# Farmadron

## Table of contents
* [Introduction](#Introduction)
* [Technologies](#Technologies)
* [Compiling](#Compiling)


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
