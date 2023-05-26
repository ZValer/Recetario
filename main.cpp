/* para correr en terminal 
te colocas en el archivo con
cd link
g++ main.cpp
*/ 

/* 
Proyecto Recetario "main.cpp"
Valeria Zúñiga Mendoza
A01705435
*/ 

#include <iostream> //para imprimir
using namespace std;

//bibliotecas con clases de mi proyecto
#include "Recetario.h" 
#include "Receta.h"


int main(){
    cout<<"Recetario"<<endl;
    
    //Crea mi recetario
    Recetario recetario;

    //Guardo mis recetas predeterminadas
    recetario.creaRecetasPredeterminadas();
    //Muestro las recetas
    recetario.mostrarRecetario();

    return 0;
}