/* 
Proyecto Recetario "Receta.h"
Valeria Zúñiga Mendoza
A01705435
*/ 

#ifndef RECETA_H_
#define RECETA_H_

#include <string>
#include <sstream>
using namespace std;


/*Declaración de la clase abstracta Receta 
que tiene relación de herencia con sus clases hijas:
- Postre
- Plato fuerte
- Snack
*/

class Receta{
    protected:
        /*variables protected: 
        actúan como variables públicas para sus clases hijas 
        y como privadas para las demás clases */
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

Receta::Receta(string _tipo, string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion){
            tipo=_tipo;
            nombre= _nombre;
            ingredientes=_ingredientes;
            instrucciones=_instrucciones; 
            duracionPreparacion=_duracionPreparacion;
        }

// Declaración de clase Postre que es clase hija de Receta
// Existe una relación de herencia

class Postre: public Receta{
    private: 
    int caloriasPorcion;

    public:
    Postre():Receta("","","","", 0){}; //constructor default
    //constructor que recibe parámetros
    Postre(string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion, int _caloriasPorcion):Receta("Postre", _nombre, _ingredientes, _instrucciones, _duracionPreparacion), 
    caloriasPorcion(_caloriasPorcion){}; 
    
    string imprime(); //método que utilizará sobre escritura
};

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
    PlatoFuerte(string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion, string _tipoCarne):Receta("PlatoFuerte", _nombre, _ingredientes, _instrucciones, _duracionPreparacion), 
    tipoCarne(_tipoCarne){};
    
    string imprime(); //método donde se utilizará sobre escritura
};

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
    Snack(string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion, string _tipoSnack):Receta("Snack", _nombre, _ingredientes, _instrucciones, _duracionPreparacion), 
    tipoSnack(_tipoSnack){};
    
    string imprime(); //método donde se utilizará sobre escritura
};

string Snack::imprime(){
    stringstream aux;
    aux << "Snack: " << nombre << "\n Ingredientes: " << ingredientes << "\n Instrucciones: " << instrucciones << "\n Duración de preparacion: " << duracionPreparacion <<
"\n El tipo de snack es: " << tipoSnack << "\n\n";
    return aux.str();
}

#endif // RECETA_H_
