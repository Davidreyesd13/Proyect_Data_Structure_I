#include <iostream>
#include "Alumno.h"
#include "Object.h"
#include "Simbolo.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h";
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "ArrayQueue.h"
using namespace std;
int main()
{
    ArrayList* arraylist = new ArrayList;
    ArrayStack* arraystack = new ArrayStack;
    ArrayQueue* arrayqueue = new ArrayQueue;
    LinkedList* linkedlist = new LinkedList;
    LinkedStack* linkedstack = new LinkedStack;
    LinkedQueue* linkedqueue = new LinkedQueue;

    bool flag = true;
    int num;
    while (flag) {
        cout << "=================================================\n";
        cout << "Menu Principal \n 1. Trabajar con Listas \n 2. Trabajar con Pilas \n 3. Trabajar con Colas \n 4. Salir \n";
        cin >> num;
        switch (num) {
            //Listas
        case 1: {
            //Fin de Listas
            bool flag2 = true;
            while (flag2) {
                cout << "=================================================\n";
                cout << "Menu Tipo de Lista \n 1. Trabajar con ArrayList \n 2. Trabajar con Linked List \n 3. Regresar al Menu Principal \n";
                int num2;
                cin >> num2;
                //Switch Case de las Opciones del Submenu de Listas
                switch (num2) {
                //ArrayList
                case 1: {
                    cout << "=================================================\n";
                    bool flag3 = true;
                    while (flag3) {
                        cout << "Operaciones de Listas \n  1. Insertar Elemento \n  2. Imprimir Elemento \n  3. Buscar Elemento \n  4. Borrar Elemento \n  5. Ver si esta vacia \n";
                        cout << "  6. Obtener Elemento por Posicion \n  7. Obtener Siguiente \n  8. Obtener Anterior \n  9. Borrar Todos los Elementos (Anula) \n";
                        cout << "  10. Regresar al Menu Anterior \n";
                        int num3;
                        cin >> num3;
                        //Switch case del Submenu de ArrayList
                        switch (num3) {
                            // Insertar Elemento
                            case 1: {
                                char respuesta = 'S';
                                string nombre;
                                int cuenta, posicion;
                                while (respuesta == 'S' || respuesta == 's') {
                                    cout << "Nombre: ";
                                    cin >> nombre;
                                    cout << "Numero de Cuenta: ";
                                    cin >> cuenta;
                                    cout << "Posicion a insertar: ";
                                    cin >> posicion;
                                    Alumno* alumno = new Alumno(nombre, cuenta);
                                    bool execution = arraylist->inserta(alumno, posicion);
                                    if (execution) {
                                        cout << "Se pudo insertar el estudiante en el arraylist en posicion: ";
                                        cout << posicion;
                                        cout << endl;
                                    }
                                    else {
                                        cout << "No se pudo insertar el estudiante \n";
                                        delete alumno;
                                    }
                                    cout << "Desea insertar otro alumno [S/N]: ";
                                    cin >> respuesta;
                                }
                                break;
                            }
                            // Imprimir Elemento
                            case 2: {
                                cout << "Lista de Estudiantes \n";
                                arraylist->imprimir_lista();
                                break;
                            }
                            // Buscar Elemento
                            case 3: {
                                int cuenta;
                                cout << "Ingrese el numero de cuenta a buscar: ";
                                cin >> cuenta;
                                arraylist->localiza(cuenta);
                                break;
                            }
                            // Borrar Elemento
                            case 4: {
                                int posicion;
                                cout << "Ingrese la posicion a borrar: ";
                                cin >> posicion;
                                arraylist->suprime(posicion);
                                break;
                            }
                            // Ver si esta vacia
                            case 5: {
                                bool isEmpty = arraylist->vacia();
                                if (isEmpty) {
                                    cout << "No hay elementos dentro del ArrayList\n";
                                }
                                break;
                            }
                            // Obtener Elemento por Posicion
                            case 6: {
                                int posicion;
                                cout << "Ingrese una posicion en la lista: ";
                                cin >> posicion;
                                Object* elemento = arraylist->obtenerElementoEnPosicion(posicion);
                                if (elemento != nullptr) {
                                    cout << "Alumno en posicion " << posicion << ": \n" << elemento->toString() << endl;
                                }
                                else {
                                    cout << "No hay ningun alumno en esa posicion." << endl;
                                }
                                break;
                            }
                            // Obtener Siguiente
                            case 7: {
                                int posicion;
                                cout << "Ingrese la posicion base: ";
                                cin >> posicion;
                                Object* siguienteElemento = arraylist->siguiente(posicion);
                                if (siguienteElemento != nullptr) {
                                    cout << "Se encontro un estudiante despues de la posicion:\n" << siguienteElemento->toString() << endl;
                                }
                                else {
                                    cout << "No hay un estudiante despues de la posicion." << endl;
                                }
                                break;
                            }
                            // Obtener Anterior
                            case 8: {
                                int posicion;
                                cout << "Ingrese la posicion base: ";
                                cin >> posicion;
                                Object* ElementoAnterior = arraylist->anterior(posicion);
                                if (ElementoAnterior != nullptr) {
                                    cout << "Se encontro un estudiante antes de la posicion:\n" << ElementoAnterior->toString() << endl;
                                }
                                else {
                                    cout << "No hay un estudiante antes de la posicion." << endl;
                                }
                                break;
                            }
                            // Anular Lista
                            case 9: {
                                arraylist->anula();
                                cout << "Se han borrado todos los elementos de la arraylist \n";
                                break;
                            }
                            // Regresar a Submenu General de Listas
                            case 10: {
                                flag3 = false;
                                break;
                            }
                            default: {
                                cout << "Valor Ingresado Invalido \n";
                                break;
                            }
                            // Fin de Switch Case de Submenu de ArrayLists    
                        }
                    }
                    //Fin de ArrayList Submenu
                    break;
                }
                // Linked Lists
                case 2: {
                    cout << "=================================================\n";
                    bool flag3 = true;
                    while (flag3) {
                        cout << "Operaciones de Listas \n  1. Insertar Elemento \n  2. Imprimir Elemento \n  3. Buscar Elemento \n  4. Borrar Elemento \n  5. Ver si esta vacia \n";
                        cout << "  6. Obtener Elemento por Posicion \n  7. Obtener Siguiente \n  8. Obtener Anterior \n  9. Borrar Todos los Elementos (Anula) \n";
                        cout << "  10. Regresar al Menu Anterior \n";
                        int num3;
                        cin >> num3;
                        //Switch case del Submenu de Linked List
                        switch (num3) {
                            // Insertar Elemento
                            case 1: {
                                char respuesta = 'S';
                                string nombre;
                                int cuenta, posicion;
                                while (respuesta == 'S' || respuesta == 's') {
                                    cout << "Nombre: ";
                                    cin >> nombre;
                                    cout << "Numero de Cuenta: ";
                                    cin >> cuenta;
                                    cout << "Posicion a insertar: ";
                                    cin >> posicion;
                                    Alumno* alumno = new Alumno(nombre, cuenta);
                                    bool execution = linkedlist->inserta(alumno, posicion);
                                    if (execution) {
                                        cout << "Se pudo insertar el estudiante en el linkedlist en posicion: ";
                                        cout << posicion;
                                        cout << endl;
                                    }
                                    else {
                                        cout << "No se pudo insertar el estudiante \n";
                                        delete alumno;
                                    }
                                    cout << "Desea insertar otro alumno [S/N]: ";
                                    cin >> respuesta;
                                }
                                break;
                            }
                            // Imprimir Elemento
                            case 2: {
                                linkedlist->imprimir_lista();
                                break;
                            }
                            // Buscar Elemento
                            case 3: {
                                int cuenta;
                                cout << "Numero de cuenta a buscar: ";
                                cin >> cuenta;
                                linkedlist->localiza(cuenta);
                                break;
                            }
                            // Borrar Elemento
                            case 4: {
                                int posicion;
                                cout << "Posicion a borrar: ";
                                cin >> posicion;
                                linkedlist->suprime(posicion);
                                break;
                            }
                            // Ver si esta vacia
                            case 5: {
                                bool isEmpty = linkedlist->vacia();
                                if (isEmpty) {
                                    cout << "Esta vacio el arbol\n";
                                }
                                break;
                            }
                            // Obtener Elemento por Posicion
                            case 6: {
                                int cuenta;
                                cout << "Numero de cuenta a buscar: ";
                                cin >> cuenta;
                                linkedlist->localiza(cuenta);
                                break;
                            }
                            // Obtener Siguiente
                            case 7: {
                                int pos;
                                cout << "Posicion a evaluar: ";
                                cin >> pos;
                                cout << linkedlist->siguiente(pos)->toString() << "\n";
                                break;
                            }
                            // Obtener Anterior
                            case 8: {
                                int pos;
                                cout << "Posicion a evaluar: ";
                                cin >> pos;
                                cout << linkedlist->anterior(pos)->toString() << "\n";
                                break;
                            }
                            // Anular Lista
                            case 9: {
                                linkedlist->anula();
                                break;
                            }
                            // Regresar a Submenu General de Listas
                            case 10: {
                                flag3 = false;
                                break;
                            }
                            default: {
                                cout << "Valor Ingresado Invalido \n";
                                break;
                            }
                               // Fin de Switch Case de Submenu de Linked Lists    
                        }
                        //Fin del Submenu de Linked Lists
                    }
                    break;
                    //Fin de Linked List Submenu
                }
                //Regresar al Menu Principal
                case 3: {
                    cout << "=================================================\n";
                    flag2 = false;
                    break;
                }
                default: {
                    cout << "Opcion Invalida \n";
                    break;
                }
                // Fin del Switch Case del Submenu de Listas
                }
                // Fin del Submenu de Listas/Flag 2
            }
            break;
        }
        //Pilas
        case 2: {
            bool flag2 = true;
            while (flag2) {
                cout << "Menu Tipo de Pila \n 1. Trabajar con ArrayStack \n 2. Trabajar con Linked Stack \n 3. Regresar al Menu Principal \n";
                int num2;
                cin >> num2;
                //Switch Case de Submenu de Pilas
                switch (num2) {
                    //ArrayStack
                    case 1: {
                        bool flag3 = true;
                        while (flag3) {
                            cout << "=================================================\n";
                            cout << "Operaciones de Pilas \n  1. Empujar(push)\n  2. Sacar(pop) \n  3. Ver Tope (top) \n  4. Ver si esta Vacia \n  5. Imprimir Elementos \n";
                            cout << "  6. Borrar todos los elementos \n  7. Regresar al Menu Anterior \n";
                            int num3;
                            cin >> num3;
                            switch (num3) {
                                //Empujar
                                case 1: {
                                    char simb;
                                    cout << "Ingrese un simbolo: ";
                                    cin >> simb;
                                    Simbolo* simbolo = new Simbolo(simb);
                                    arraystack->mete(simbolo);
                                    break;
                                }
                                // Sacar
                                case 2: {
                                    if (arraystack->vacia()) {
                                        cout << "No hay elementos en la pila." << std::endl;
                                    }
                                    // Sacar el elemento superior de la pila
                                    Object* elemento = arraystack->saca();
                                    // Mostrar el resultado 
                                    if (elemento) {
                                        cout << "Elemento sacado de la pila: " << elemento->toString() << endl;
                                        delete elemento; // Liberar la memoria del objeto
                                    }
                                    else {
                                        cout << "No se pudo sacar un elemento de la pila." << endl;
                                    }
                                    break;
                                }
                                // Ver Tope
                                case 3: {
                                    cout << "Elemento en tope: " << arraystack->tope()->toString() << "\n";
                                    break;
                                }
                                // Ver si esta vacia
                                case 4: {
                                    bool isEmpty = arraystack->vacia();
                                    if (isEmpty) {
                                        cout << "Esta vacia el arraystack \n";
                                    }
                                    break;
                                }
                                // Imprimir Elementos
                                case 5: {
                                    arraystack->imprime_pila();
                                    break;
                                }
                                // Borrar todos los elementos
                                case 6: {
                                    arraystack->anula();
                                    break;
                                }
                                // Regresar al Menu Anterior
                                case 7: {
                                    flag3 = false;
                                    break;
                                }
                                default: {
                                    cout << "Opcion Ingresada Invalida\n";
                                    break;
                                }
                            //Fin de Switch Case de Num3
                            }
                        //Fin de Flag3
                        }
                    //Fin de ArrayStack/Case 1
                    break;
                    }
                    //Linked Stack
                    case 2: {
                        bool flag3 = true;
                        while (flag3) {
                            cout << "=================================================\n";
                            cout << "Operaciones de Pilas \n  1. Empujar(push)\n  2. Sacar(pop) \n  3. Ver Tope (top) \n  4. Ver si esta Vacia \n  5. Imprimir Elemenos \n";
                            cout << "  6. Borrar todos los elementos \n  7. Regresar al Menu Anterior \n";
                            int num3;
                            cin >> num3;
                            switch (num3) {
                                //Empujar
                                case 1: {
                                    char symbol;
                                    cout << "Ponga un simbolo: ";
                                    cin >> symbol;
                                    Simbolo* simbolo = new Simbolo(symbol);
                                    linkedstack->mete(simbolo);
                                    break;
                                }
                                // Sacar
                                case 2: {
                                    linkedstack->saca();
                                    break;
                                }
                                // Ver Tope
                                case 3: {
                                    cout << linkedstack->tope()->toString();
                                    cout << "\n";
                                    break;
                                }
                                // Ver si esta vacia
                                case 4: {
                                    bool isEmpty = linkedstack->vacia();
                                    if (isEmpty) {
                                        cout << "Esta vacia el linkedstack\n";
                                    }
                                    break;
                                }
                                // Imprimir Elementos
                                case 5: {
                                    linkedstack->imprime_pila();
                                    break;
                                }
                                // Borrar todos los elementos
                                case 6: {
                                    linkedstack->anula();
                                    break;
                                }
                                // Regresar al Menu Anterior
                                case 7: {
                                    flag3 = false;
                                    break;
                                }
                                default: {
                                    cout << "Opcion Ingresada Invalida\n";
                                    break;
                                }
                                //Fin de Switch Case de Num3
                            }
                            //Fin de Flag3
                        }
                    //Fin de Linked Stack
                    break;
                    }
                    // Regresar al menu principal
                    case 3: {
                        cout << "=================================================\n";
                        flag2 = false;
                        break;
                    }
                    default: {
                        cout << "Valor Ingresado Invalido \n";
                        break;
                    }
                 //Fin de Switch Case de Submenu de Pilas
                }
            //Fin de Flag 2
            }
        //Fin de Pilas
            break;
        }
        case 3: {
            bool flag2 = true;
            while (flag2) {
                cout << "Menu Tipo de Colas \n 1. Trabajar con ArrayQueue \n 2. Trabajar con LinkedQueue \n 3. Regresar al Menu Principal\n";
                int num2;
                cin >> num2;
                switch (num2) {
                    // ArrayQueue
                    case 1: {
                        bool flag3 = true;
                        while (flag3) {
                            cout << "=================================================\n";
                            cout << "Operaciones de Colas\n  1. Encolar (queue) \n  2. Desencolar (deque)\n  3. Ver Frente (peek)\n  4. Verificar si esta vacia\n";
                            cout << "  5. Imprimir Elementos\n  6. Borrar los Elementos \n  7. Regresar al Menu Anterior \n";
                            int num3;
                            cin >> num3;
                            //Submenu de ArrayQueue
                                switch (num3) {
                                //Encolar
                                case 1: {
                                    string nombre;
                                    int cuenta;
                                    cout << "Ingresar nombre: ";
                                    cin >> nombre;
                                    cout << "Ingresar numero de cuenta: ";
                                    cin >> cuenta;
                                    Alumno* alumno = new Alumno(nombre, cuenta);
                                    arrayqueue->pone_en_cola(alumno);
                                    break;
                                }
                                //Desencolar
                                case 2: {
                                    arrayqueue->saca_de_cola();
                                    break;
                                }
                                // Ver Frente
                                case 3: {
                                    cout << arrayqueue->frente()->toString() << "\n";
                                    break;
                                }
                                // Verificar si esta vacia
                                case 4: {
                                    bool isEmpty = arrayqueue->vacia();
                                    if (isEmpty) {
                                        cout << "No hay elementos en la cola\n";
                                    }
                                    break;
                                }
                                // Imprimir Elementos
                                case 5: {
                                    arrayqueue->imprime_cola();
                                    break;
                                }
                                // Borrar los Elementos
                                case 6: {
                                    arrayqueue->anula();
                                    break;
                                }
                                      // Regresar al Menu previo
                                case 7: {
                                    flag3 = false;
                                    break;
                                }
                                default: {
                                    cout << "Opcion Ingresada Invalida\n";
                                    break;
                                }
                                   //Fin de Switch Case de Num3
                            }
                            //Fin de Flag3
                        }
                        //Fin de ArrayQueue
                        break;
                    }
                    // Linked Queue
                    case 2: {
                        bool flag3 = true;
                        while (flag3) {
                            cout << "=================================================\n";
                            cout << "Operaciones de Colas\n  1. Encolar (queue) \n  2. Desencolar (deque)\n  3. Ver Frente (peek)\n  4. Verificar si esta vacia\n";
                            cout << "  5. Imprimir Elementos\n  6. Borrar los Elementos \n  7. Regresar al Menu Anterior \n";
                            int num3;
                            cin >> num3;
                            //Submenu de ArrayQueue
                            switch (num3) {
                                //Encolar
                                case 1: {
                                    string nombre;
                                    int cuenta;
                                    cout << "Ingresar nombre: ";
                                    cin >> nombre;
                                    cout << "Ingresar numero de cuenta: ";
                                    cin >> cuenta;
                                    Alumno* alumno = new Alumno(nombre, cuenta);
                                    linkedqueue->pone_en_cola(alumno);
                                    break;
                                }
                                //Desencolar
                                case 2: {
                                    linkedqueue->saca_de_cola();
                                    break;
                                }
                                // Ver Frente
                                case 3: {
                                    cout << linkedqueue->frente()->toString() << "\n";
                                    break;
                                }
                                // Verificar si esta vacia
                                case 4: {
                                    bool isEmpty = linkedqueue->vacia();
                                    if (isEmpty) {
                                        cout << "Esta vacio el linkedqueue\n";
                                    }
                                    break;
                                }
                                // Imprimir Elementos
                                case 5: {
                                    linkedqueue->imprime_cola();
                                    break;
                                }
                                // Borrar los Elementos
                                case 6: {
                                    linkedqueue->anula();
                                    break;
                                }
                                // Regresar al Menu previo
                                case 7: {
                                    flag3 = false;
                                    break;
                                }
                                default: {
                                    cout << "Opcion Ingresada Invalida\n";
                                    break;
                                }
                                //Fin de Switch Case de Num3
                            }
                            //Fin de Flag3
                        }
                        //Fin de LinkedQueue
                        break;
                    }
                    case 3: {
                        cout << "=================================================\n";
                        flag2 = false;
                        break;
                    }
                    default: {
                        cout << "Opcion Ingresada Invalida \n";
                        break;
                    }
                    //Fin de Switch Case Num2
                }
                //Fin de Flag2
            }
            //Fin de Colas
            break;
        }
            case 4: {
                flag = false;
                break;
            }
            default: {
                cout << "Opcion Invalida \n";
                break;
            }
        }
    }
}