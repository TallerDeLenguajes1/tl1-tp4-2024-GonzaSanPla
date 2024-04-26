#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100

}typedef Tarea;

typedef struct Nodo Nodo;


struct Nodo{
    Tarea T;
    Nodo* Siguiente;
};


Nodo* crearLista();
Nodo* crearNodo(Nodo* siguiente);
void agregarPendiente( Nodo** pendiente, Nodo* agregar);
void mostrarLista(Nodo* lista);
void mostraNodo(Nodo elemento);


int main()
{
    Nodo* listo=crearLista();
    Nodo* pendiente=crearLista();
    Nodo* nuevo;


    int opcion=20,agregar=1;
    while (opcion!=0)
    {
        printf("\nElija que accion desea realizar:\n 1-Agregar una tarea a lista de tareas pendiente\n 2-Mover una/s tarea/s de la lista de pendiente a realizada\n 3-Mostrar lista de taras pendienes y lisa de tarea realizadas\n 0-Salir");
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            while(agregar==1)
            {   
                nuevo=crearNodo(pendiente);

                agregarPendiente(&pendiente,nuevo);
                printf("\nDesea agragar otro elemento?\n 1-Si\n 0-No");
                scanf("%i",&agregar);
            }
            break;
        case 2: //Ver como hacer lo de mover

            break;
        
        case 3: // Verificar si funciona 
            printf("\n-----Lista de tareas pendientes-----\n");
            mostrarLista(pendiente);
            
            printf("\n-----Lista de tareas listas-----\n");
            mostrarLista(listo);

        }
        
        
    }
    


    return(0);
}

Nodo* crearLista()
{
    Nodo* nuevaLista;
    nuevaLista= NULL;
    return(nuevaLista);
}

Nodo* crearNodo(Nodo* siguiente)
{
    Nodo*  nuevo;
    char* buffer;

    nuevo =(Nodo* )malloc(sizeof(Nodo)) ; 
    buffer=(char* )malloc(sizeof(char)*1000);

    if (siguiente==NULL)
    {
        nuevo->T.TareaID=1000;
    }else
    {
        nuevo->T.TareaID=(siguiente->T.TareaID)+1;
    }
    
    printf("\nIngrese una descripcion de la nueva tarea:");
    fflush(stdin);
    gets(buffer);

    nuevo->T.Descripcion=(char * )malloc(sizeof(char)* (strlen(buffer)+1));
    strcpy(nuevo->T.Descripcion,buffer);

    free(buffer);

    printf("\nIngrese la duracion(entre 10 y 100):");
    scanf("%i",&nuevo->T.Duracion);

    nuevo->Siguiente=NULL;

    return(nuevo);
}


void agregarPendiente( Nodo** pendiente, Nodo* agregar)
{
    agregar->Siguiente=*pendiente;
    *pendiente=agregar;
}

void mostrarLista(Nodo* lista)
{
    Nodo * aux= lista;
    while (aux!=NULL)
    {
        mostraNodo(*aux);
        aux=aux->Siguiente;
    }
    
}

void mostraNodo(Nodo elemento)
{
    printf("\nDescripcion de la tarea: %s",elemento.T.Descripcion);
    printf("\nDuracion de la tarea: %i",elemento.T.Duracion);
}

/*
1) Desarrolle una interfaz de carga de tareas para solicitar tareas pendientes, en la cual se
solicite descripción y duración de la misma (el id debe ser generado automáticamente por
el sistema, de manera autoincremental comenzando desde el número 1000). Al cabo de
cada tarea consulte al usuario si desea ingresar una nueva tarea o finalizar la carga.
2) Implemente una interfaz para elegir qué tareas de la lista de pendientes deben ser
transferidas a la lista de tareas realizadas.
3) Implemente una funcionalidad que permita listar todas las tareas pendientes y realizadas.
4) Implemente una funcionalidad que permita consultar tareas por id o palabra clave y
mostrarlas por pantalla, indicando si corresponde a una tarea pendiente o realizada.
*/