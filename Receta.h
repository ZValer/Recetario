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
        Receta(): tipo(""), nombre(""), ingredientes(""), instrucciones(""), duracionPreparacion(0){}; //constructor default
        Receta(string _tipo, string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion); //contructor que recibe parámetros

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
        int get_duracionPreparacion(){
            return duracionPreparacion;
        }
        
        // string imprimeDatos(); modificar método para que imprima

        string cocinar(){
            return "Cocinándose";
        }  //método donde se utilizará sobre escritura
};

// Declaración de clase Postre que es clase hija de Receta
// Existe una relación de herencia

class Postre: public Receta{
    private: 
    int caloriasPorcion;

    public:
    Postre():Receta("","","","", 0){}; //contructor default
    //constructor que recibe parámetros
    Postre(string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion, int _caloriasPorcion):Receta("Postre", _nombre, _ingredientes, _instrucciones, _duracionPreparacion), 
    caloriasPorcion(_caloriasPorcion){};
    
    string cocinar() {
        return "Mezclo ingredientes... Horneo... Listo!";
    }
};

// Declaración de clase PlatoFuerte que es clase hija de Receta
// Existe una relación de herencia
class PlatoFuerte: public Receta{
    private: 
    string tipoCarne;

    public:
    PlatoFuerte():Receta("","","","", 0){}; //contructor default
    //constructor que recibe parámetros
    PlatoFuerte(string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion, string _tipoCarne):Receta("Postre", _nombre, _ingredientes, _instrucciones, _duracionPreparacion), 
    tipoCarne(_tipoCarne){};
    
    string cocinar() {
        return "Cortar ingredientes... Incorporar... Al sartén... Sazonar... Listo!";
    }
};

// Declaración de clase Snack que es clase hija de Receta
// Existe una relación de herencia
class Snack: public Receta{
    private: 
    string tipoSnack;

    public:
    Snack():Receta("","","","", 0){}; //contructor default
    //constructor que recibe parámetros
    Snack(string _nombre, string _ingredientes, string _instrucciones, float _duracionPreparacion, string _tipoSnack):Receta("Postre", _nombre, _ingredientes, _instrucciones, _duracionPreparacion), 
    tipoSnack(_tipoSnack){};
    
    string cocinar() {
        return "Cortar ingredientes... Acomodar... Empaquetar... Listo!";
    }
};

#endif // RECETA_H_


