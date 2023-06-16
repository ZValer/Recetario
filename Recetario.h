/* 
 * Proyecto Recetario "Recetario.h"
 * Valeria Zúñiga Mendoza
 * A01705435
 * 15/06/2023
 * 
 * Esta clase define al objeto de tipo Recetario el cual contiene las 
 * instrucciones para agregar los diferentes tipos de recetas: snack, 
 * plato fuerte y postre. Así como las indicaciones para mostrar el 
 * recetario y hacer búsquedas de recetas a partir de su nombre, tipo
 * o duración de preparación.
 * Aquí se contienen las funciones principales del programa y es parte 
 * del proyecto Recetario.
 * 
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
        Receta *recetas[tamMaximo]; //arreglo de apuntadores a objetos de tipo Receta
        int numReceta;

    public:
        //contructores
        Recetario(): numReceta(0) {}; //contructor default
       
        //métodos publicos

        //agregar recetas de diferentes tipos
        void agregaPostre(string, string, string, float, int);
        void agregaPlatoFuerte(string, string, string, float, string);
        void agregaSnack(string, string, string, float, string);


        void mostrarRecetario();
        void mostrarRecetario(string); //sobrecarga ->método que despliega las recetas de un solo tipo
        void busqueda_nombre(string);
        void busqueda_duracionPreparacion();

        // Método que crea Recetas de ejemplo
        void creaRecetasPredeterminadas();
};

/**
 * mostrarRecetario despliega todas las recetas guardadas
 * 
 * Utiliza el arreglo recetas[] y el número de Receta para recorrer el
 * arreglo e ir imprimiendo cada receta con el método imprime().
 * 
 * @param 
 * @return
 */
void Recetario::mostrarRecetario(){
    cout<<"\n";
    cout<<"\n Recetario\n"<<endl;
    for (int i=0;i<numReceta;i++){
        cout<< recetas[i]->imprime();
    }       
}

/**
 * mostrarRecetario(string tip) imprime recetas de un solo tipo
 * 
 * Utiliza el arreglo recetas[] y el número de Receta para recorrer 
 * el arreglo e ir imprimiendo cada receta que coincida con el tipo 
 * especificado ("Postre, PlatoFuerte, Snack").
 *  
 * @param string tip debe ser: "Postre", "PlatoFuerte" o "Snack"
 * @return
 */
void Recetario::mostrarRecetario(string tip){
    cout<<"\n";
    cout<<"Recetas tipo: "<<tip<<endl;
    cout<<"\n";
    for (int i=0;i<numReceta;i++){
        if (recetas[i]->get_tipo()==tip)
            cout<< recetas[i]->imprime();
    } 
}

/**
 * busqueda_nombre(string nomb) imprime la receta que coincida con el 
 * nombre dado
 * 
 * Utiliza el arreglo recetas[] y el número de Receta para recorrer 
 * el arreglo e imprimir la receta que coincida con el nombre 
 * especificado.
 *  
 * @param string nomb debe ser el nombre de una receta previamente guardada
 * @return
 */
void Recetario::busqueda_nombre(string nomb){
    for (int i=0;i<numReceta;i++){
        if (recetas[i]->get_nombre()==nomb)
            cout<<recetas[i]->imprime();
    } 
}

/**
 * busqueda_duracionPreparacion imprime las recetas que coincida con el
 * tiempo definido
 * 
 * Pregunta al usuario el rango de tiempo y utiliza el arreglo recetas[] 
 * y el número de Receta para recorrer el arreglo e imprimir la receta 
 * que coincida con el tiempo especificado.
 *  
 * @param 
 * @return
 */
void Recetario::busqueda_duracionPreparacion(){
    float min;
    float max;
    cout<<"Ingresa el rango de tiempo en minutos \nMayor que: ";
    cin>>min;
    cout<<"Menor que: ";
    cin>>max;
    cout<<"\n";
    for (int i=0;i<numReceta;i++){
        if (recetas[i]->get_duracionPreparacion()>min && recetas[i]->get_duracionPreparacion()<max)
        cout<< recetas[i]->imprime();
    } 
}

/**
 * agregaPostre crea un objeto Postre y lo agrega al arreglo de recetas
 *
 * crea un objeto Postre y lo agrega a arreglo de recetas usando como 
 * indice el número de receta, el que posteriormente aumenta en 1.
 *
 * @param string nombre de la receta, string ingredientes, 
 * string instrucciones, float duración de la preparación en minutos 
 * y int las calorías por porción
 * @return
 */
void Recetario::agregaPostre(string nomb, string ingred, string instr, float durPrep, int calPorcion){
    //crea un objeto en tiempo de ejecución utilizando polimorfismo
    recetas[numReceta]= new Postre(nomb, ingred, instr, durPrep, calPorcion);
    numReceta++;
}

/**
 * agregaPlatoFuerte crea un objeto PlatoFuerte y lo agrega al arreglo 
 * de recetas
 *
 * crea un objeto PlatoFuerte y lo agrega a arreglo de recetas usando 
 * como indice el número de receta, el que posteriormente aumenta en 1.
 *
 * @param string nombre de la receta, string ingredientes, 
 * string instrucciones, float duración de la preparación en minutos 
 * y string el tipo de carne
 * @return
 */
void Recetario::agregaPlatoFuerte(string nomb, string ingred, string instr, float durPrep, string tipCarne){
    //crea un objeto en tiempo de ejecución utilizando polimorfismo
    recetas[numReceta]= new PlatoFuerte(nomb, ingred, instr, durPrep, tipCarne);
    numReceta++;
}

/**
 * agregaSnack crea un objeto Snack y lo agrega al arreglo de recetas
 *
 * Crea un objeto Snack y lo agrega a arreglo de recetas usando como
 * indice el número de receta, el que posteriormente aumenta en 1.
 *
 * @param string nombre de la receta, string ingredientes, 
 * string instrucciones, float duración de la preparación en minutos 
 * y string el tipo de snack
 * @return
 */
void Recetario::agregaSnack(string nomb, string ingred, string instr, float durPrep, string tipSnack){
    //crea un objeto en tiempo de ejecución utilizando polimorfismo
    recetas[numReceta]= new Snack(nomb, ingred, instr, durPrep, tipSnack);
    numReceta++;
}

/**
 * creaRecetasPredeterminadas genera objetos en recetas[]
 * 
 * crea objetos de tipo Postre, PlatoFuerte y Snack y los guarda en el
 * arreglo recetas[] para agregar recetas de ejemplo al crear tu recetario
 *  
 * @param 
 * @return
 */
void Recetario::creaRecetasPredeterminadas(){
    recetas[numReceta] = new Postre("Helado", "Fresas, hielos, azucar, leche", "Mezcla y congela", 120, 200);
    numReceta++;
    recetas[numReceta] = new PlatoFuerte("Carne asada", "Arrachera, sal, limón", "Sazonar y cocinar en el asador", 350, "res");
    numReceta++;
    recetas[numReceta] = new Snack("Sandwich", "2 rebanas de pan, jamón, lechuga, mayonesa", "Pon todos los ingredientes dentro del pan", 10, "salado");
    numReceta++;

}


#endif // RECETARIO_H_
