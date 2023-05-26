/* 
Proyecto Recetario "Recetario.h"
Valeria Zúñiga Mendoza
A01705435
*/ 

#ifndef RECETARIO_H_
#define RECETARIO_H_

#include <iostream> 
#include <string>
#include <sstream>

#include "Receta.h" //biblioteca con objetos del proyecto

using namespace std;

const int tamMaximo=1000; //para el tamaño de arreglos

//Declaración de la clase Recetario
class Recetario {
    private:
        //variables privadas
        Receta *recetas[tamMaximo]; //utiliza un apuntador
        int numReceta;

    public:
        //contructores
        Recetario(): numReceta(0) {}; //contructor default
       
        //métodos publicos
        void agregaPostre(string, string, string, float, int);
        void agregaPlatoFuerte(string, string, string, float, string);
        void agregaSnack(string, string, string, float, string);


        void mostrarRecetario();
        // void mostrarRecetario(string tipo);
        // string busqueda_nombre();
        // string busqueda_ingredientes();
        // string busqueda_duracionPreparacion();

        // Método que crea Recetas de ejemplo
        void creaRecetasPredeterminadas();
};


//método que despliega todas las recetas
void Recetario::mostrarRecetario(){
    for (int i=0;i<numReceta;i++)
        cout<< recetas[i];
}

//método que agrega objeto de tipo Postre
void Recetario::agregaPostre(string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion, int _caloriasPorcion){
    //crea un objeto Postre, utilizando polimorfismo
    recetas[numReceta]= new Postre(_nombre, _ingredientes, _instrucciones, _duracionPreparacion, _caloriasPorcion);
    numReceta++;
}

//método que agrega objeto de tipo PlatoFuerte
void Recetario::agregaPlatoFuerte(string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion, string _tipoCarne){
    //crea un objeto PlatoFuerte, utilizando polimorfismo
    recetas[numReceta]= new PlatoFuerte(_nombre, _ingredientes, _instrucciones, _duracionPreparacion, _tipoCarne);
    numReceta++;
}

//método que agrega objeto de tipo Snack
void Recetario::agregaSnack(string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion, string _tipoSnack){
    //crea un objeto Snack, utilizando polimorfismo
    recetas[numReceta]= new Snack(_nombre, _ingredientes, _instrucciones, _duracionPreparacion, _tipoSnack);
    numReceta++;
}

// Método que crea Recetas de ejemplo
void Recetario::creaRecetasPredeterminadas(){
    recetas[numReceta] = new Postre("Helado", "Fresas, hielos, azucar, leche", "Mezcla y congela", 120, 200);
    numReceta;
    recetas[numReceta] = new PlatoFuerte("Carne asada", "Arrachera, sal, limón", "Sazonar y cocinar en el asador", 350, "res");
    numReceta;
    recetas[numReceta] = new Snack("Sandwich", "2 rebanas de pan, jamón, lechuga, mayonesa", "Pon todos los ingredientes dentro del pan", 10, "salado");
    numReceta;

}


#endif // RECETARIO_H_