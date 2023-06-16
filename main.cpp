/* 
 * Para correr en terminal 
 * te colocas en el archivo con "cd link"
 * "g++ main.cpp"
 * "a.exe"
 */ 

#include <iostream> //para imprimir
#include <string>
using namespace std;

#include "Recetario.h" //bibliotecas con clases de mi proyecto
#include "Receta.h" //bibliotecas con clases de mi proyecto


int main(){
    //Introducción al usuario y explicación del programa
    cout<<"\nBienvenido a tu RECETARIO"<<endl;
    cout<<"\nAquí podrás guardar tus recetas de tipo: \n -Plato fuerte\n -Postre\n -Snack"<<endl;
    cout<<"También podras buscar tus recetas por:\n - Nombre\n - Tipo\n - Tiempo de preparación"<<endl;
    cout<<"------------------------------------------------------\n"<<endl;
    
    //Crear recetario del usuario
    Recetario recetario;

    //Preguntar al usuario si quiere recetas de ejemplo
    int rejem;
    cout<<"¿Desea agregar a su recetario algunas recetas de ejemplo? \n 1:Sí \n 2:No \n(Ingresa 1/2): ";
    cin>>rejem;
    if (rejem==1){
        //Guardar recetas predeterminadas
        recetario.creaRecetasPredeterminadas();
        //Mostrar las recetas
        recetario.mostrarRecetario();
    }
    else{
        cout<<"No se agregaron recetas de ejemplo \nContinuar..."<<endl;
    }
    //Da al usuario opción de continuar o salir
    int contSalir;
    cout<<"\n1. Continuar \n2. Salir \n  Ingresa 1/2: ";
    cin>>contSalir;

    while (contSalir==1){
        //Desplegar un menu de opciones
        int respuesta1;
        cout<<"\n MENÚ \n 1. Agregar receta \n 2. Mostrar recetario \n 3. Buscar receta \n\n(Ingresa 1/2/3): ";
        cin>>respuesta1;

        //Si la respuesta es Agregar receta (1)
        if (respuesta1==1){
            //Pregunta al usuario para que ingrese los datos de la receta
            string nomb;
            cout<<"\n Ingresa el nombre de la receta: "<<endl;
            cin.ignore();
            getline(cin, nomb); //para que pueda recibir varias palabras
                               
            string ingred;
            cout<<"\n Agrega los ingredientes separados por espacios: "<<endl;
            cin.ignore();
            getline(cin, ingred); //para que pueda recibir una linea de texto(palabras separadas por espacios)
                    
            string instr;
            cout<<"\n Instrucciones: "<<endl;
            cin.ignore();
            getline(cin, instr); //para que pueda recibir una linea de texto(palabras separadas por espacios)
            
            float durPrep;
            cout<<"\n Duración de preparación (en minutos): "<<endl;
            cin>>durPrep;

            cout<<"\n   1.Postre \n   2.Plato fuerte \n   3.Snack";
            int res2;
            cout<<"\nTipo de receta (Ingresa 1/2/3): ";
            cin>>res2;
            //Dependiendo del tipo de receta se pregunta al usuario datos específicos y crea el objeto
            if (res2==1){
                int calPorcion;
                cout<<"\n Calorías por porción: ";
                cin>>calPorcion;
                recetario.agregaPostre(nomb, ingred, instr, durPrep, calPorcion);
            }
            
            else if (res2==2){
                string tipCarne;
                cout<<"\n Tipo de carne: ";
                cin>>tipCarne;
                recetario.agregaPlatoFuerte(nomb, ingred, instr, durPrep, tipCarne);
            }
            
            else if (res2==3){
                string tipSnack;
                cout<<"\n Tipo de snack: ";
                cin>>tipSnack;   
                recetario.agregaSnack(nomb, ingred, instr, durPrep, tipSnack);        
            }
            
            else{
                cout<<"respuesta no válida"<<endl;
                
            }
            
        }
        
        //Si la respuesta es mostrar recetario (2)
        else if (respuesta1==2){
            recetario.mostrarRecetario();
        }

        //Si la respuesta es buscar receta (3)
        else if (respuesta1==3){
            int busquedaRecetas;
            cout<<"Deseas buscar recetas...\n1)...Ingresando el nombre de la receta\n2)...Ingresando el tipo de receta(Plato Fuerte/Postre/Snack)\n3)...Por duración de preparación \n\nIngresa (1/2/3): ";
            cin>>busquedaRecetas;

            if (busquedaRecetas==1){ //1)...Ingresando el nombre de la receta
                
                string nomb;
                cout<<"Nombre de la receta: ";
                cin.ignore();
                getline(cin, nomb); //Puede recibir más de una palabra
                
                recetario.busqueda_nombre(nomb);                
            }

            else if (busquedaRecetas==2){ //2)...Ingresando el tipo de receta(Plato Fuerte/Postre/Snack)
                string tip;
                cout<<"¿Deseas buscar las recetas de\n -Postre\n -PlatoFuerte\n -Snack \n(Escribe tu respuesta como se muestra escrito considerando mayúsculas): ";
                cin>>tip;
                if (tip=="Postre"||tip=="PlatoFuerte"||tip=="Snack"){
                    recetario.mostrarRecetario(tip);
                }
                else{
                    cout<<"Respuesta no válida";
                }
            }

            else if (busquedaRecetas==3){ //3)...Por duración de preparación 
                recetario.busqueda_duracionPreparacion();
            }

            else{
                    cout<<"Respuesta no válida";
                }
            
        }

        else{
                    cout<<"Respuesta no válida";
                }

        //Da al usuario opción de continuar o salir
        int contSalir;
        cout<<"\n1. Continuar \n2. Salir \n  Ingresa 1/2: ";
        cin>>contSalir;
        if (contSalir==2){
            break; //Salir del while
        }
    }
    
    cout<<"Usted salió del programa"<<endl;

    return 0;
}
