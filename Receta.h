/* 
 * Proyecto Recetario "Receta.h"
 * Valeria Zúñiga Mendoza
 * A01705435
 * 15/06/2023
 * 
 * Esta clase define al objeto de tipo Receta que contiene las clases
 * heredadas PlatoFuerte, Snack y Postre.
 * 
 */ 


#ifndef RECETA_H_
#define RECETA_H_

#include <string>
#include <sstream>
using namespace std;


/*
 * Declaración de la clase abstracta Receta 
 * que tiene relación de herencia con sus clases hijas:
 * - Postre
 * - Plato fuerte
 * - Snack
 */

class Receta{
    protected:
        /*
         * Variables protected: 
         * actúan como variables públicas para sus clases hijas 
         * y como privadas para las demás clases 
         */
        string tipo;
        string nombre;
        string ingredientes;
        string instrucciones;
        float duracionPreparacion;
    public:
        //contructores y métodos públicos
        Receta(): tipo(""), nombre(""), ingredientes(""), instrucciones(""), duracionPreparacion(0.0){}; //constructor default
        Receta(string, string, string, string, float); //contructor que recibe parámetros

        //getters:
        string get_tipo(){
            return tipo;
        }
        string get_nombre(){
            return nombre;
        }
        string get_ingredientes(){
            return ingredientes;
        }
        string get_instrucciones(){
            return instrucciones;
        }
        float get_duracionPreparacion(){
            return duracionPreparacion;
        }
        
        virtual string imprime()=0; //Clase abstracta
                                    //método donde se utilizará sobre escritura

};

//Constructor de Receta
Receta::Receta(string tip, string nomb, string ingred, string instr, float durPrep){
            tipo=tip;
            nombre= nomb;
            ingredientes=ingred;
            instrucciones=instr; 
            duracionPreparacion=durPrep;
        }

// Declaración de clase Postre que es clase hija de Receta
// Existe una relación de herencia

class Postre: public Receta{
    private: 
    int caloriasPorcion;

    public:
    Postre():Receta("","","","", 0){}; //constructor default
    //constructor que recibe parámetros
    Postre(string nomb, string ingred, string instr, float durPrep, int calPorcion):Receta("Postre", nomb, ingred, instr, durPrep), 
    caloriasPorcion(calPorcion){}; 
    
    string imprime(); //método que utilizará sobre escritura
};

/**
 * imprime convierte los atributos a string.
 *
 * Realiza una concatenación de todos los valores de los atributos en un 
 * string para ser impreso
 *
 * @param
 * @return string con texto concatenado de la información de la receta
 */

string Postre::imprime(){
    stringstream aux;
    aux << "Postre: " << nombre << "\n Ingredientes: " << ingredientes << "\n Instrucciones: " << instrucciones << "\n Duración de preparacion: " << duracionPreparacion <<
    "\n Las calorias por porcion son: " << caloriasPorcion << "\n\n";
    return aux.str();
}

// Declaración de clase PlatoFuerte que es clase hija de Receta
// Existe una relación de herencia
class PlatoFuerte: public Receta{
    private: 
    string tipoCarne;

    public:
    PlatoFuerte():Receta("","","","", 0){}; //contructor default
    //constructor que recibe parámetros
    PlatoFuerte(string nomb, string ingred, string instr, float durPrep, string tipCarne):Receta("PlatoFuerte", nomb, ingred, instr, durPrep), 
    tipoCarne(tipCarne){};
    
    string imprime(); //método donde se utilizará sobre escritura
};

/**
 * imprime convierte los atributos a string.
 *
 * Realiza una concatenación de todos los valores de los atributos en un 
 * string para ser impreso
 *
 * @param
 * @return string con texto concatenado de la información de la receta
 */
string PlatoFuerte::imprime(){
    stringstream aux;
    aux << "Plato fuerte: " << nombre << "\n Ingredientes: " << ingredientes << "\n Instrucciones: " << instrucciones << "\n Duración de preparacion: " << duracionPreparacion <<
    "\n El tipo de carne es: " << tipoCarne << "\n\n";
    return aux.str();
}

// Declaración de clase Snack que es clase hija de Receta
// Existe una relación de herencia
class Snack: public Receta{
    private: 
    string tipoSnack;

    public:
    Snack():Receta("","","","", 0){}; //contructor default
    //constructor que recibe parámetros
    Snack(string nomb, string ingred, string instr, float durPrep, string tipSnack):Receta("Snack", nomb, ingred, instr, durPrep), 
    tipoSnack(tipSnack){};
    
    string imprime(); //método donde se utilizará sobre escritura
};

/**
 * imprime convierte los atributos a string.
 *
 * Realiza una concatenación de todos los valores de los atributos en un 
 * string para ser impreso
 *
 * @param
 * @return string con texto concatenado de la información de la receta
 */
string Snack::imprime(){
    stringstream aux;
    aux << "Snack: " << nombre << "\n Ingredientes: " << ingredientes << "\n Instrucciones: " << instrucciones << "\n Duración de preparacion: " << duracionPreparacion <<
"\n El tipo de snack es: " << tipoSnack << "\n\n";
    return aux.str();
}

#endif // RECETA_H_
