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
void moverDeLista(Nodo** pendiente, Nodo** realizado, int idMover);
void buscarId(Nodo** pendiente, Nodo** realizado, int idMover);


int main()
{
    Nodo* listo=crearLista();
    Nodo* pendiente=crearLista();
    Nodo* nuevo;


    int opcion=20,agregar=1,mover=1,idMover=0,idBuscar=0,buscar=1;
    while (opcion!=0)
    {
        printf("\nElija que accion desea realizar:\n 1-Agregar una tarea a lista de tareas pendiente\n 2-Mover una/s tarea/s de la lista de pendiente a realizada\n 3-Mostrar lista de taras pendienes y lisa de tarea realizadas\n 4-Buscar tarea por numero\n 0-Salir");
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            agregar=1;
            while(agregar==1)
            {   
                nuevo=crearNodo(pendiente);

                agregarPendiente(&pendiente,nuevo);
                printf("\nDesea agragar otro elemento?\n 1-Si\n 0-No");
                scanf("%i",&agregar);
            }
            break;
        case 2: //Ver como hacer lo de mover
            mover=1;
            while(mover==1)
            {
                printf("\n-----Lista de tareas pendientes-----\n");
                mostrarLista(pendiente);

                printf("\nSeleccione el numero de la tarea que desea mover a realizada:");
                scanf("%d",&idMover);

                if (pendiente!=NULL)
                {
                    moverDeLista(&pendiente,&listo,idMover+1000);

                    printf("\nDesea mover otro elemento?\n 1-Si\n 0-No");
                    scanf("%i",&mover);      
                }else
                {
                    printf("La lista de pendientes esta vacia :)");
                    mover=0;
                }
                 
            }

            break;
        
        case 3: // Verificar si funciona 
            printf("\n\n-----Lista de tareas pendientes-----\n");
            mostrarLista(pendiente);
            
            printf("\n\n-----Lista de tareas listas-----\n");
            mostrarLista(listo);

            break;
        case 4:
            buscar=1;
            while(buscar==1)
            {   
                printf("\nIngrese el numero de la tarea que desea buscar:");
                scanf("%d",&idBuscar);

                buscarId(&pendiente,&listo,idBuscar+1000);

                printf("\nDesea buscar otro elemento?\n 1-Si\n 0-No");
                scanf("%i",&buscar);
            }
            break;
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
    printf("\nEsta es la tarea n %d",elemento.T.TareaID-1000);
    printf("\nDescripcion de la tarea: %s",elemento.T.Descripcion);
    printf("\nDuracion de la tarea: %i\n",elemento.T.Duracion);
}

void moverDeLista(Nodo **pendiente, Nodo **realizado, int idMover)
{
    Nodo* aux=*pendiente;
    Nodo* anterior=NULL;
    int encontrado=0;

    while (aux!=NULL || encontrado==0)
    {
        if (aux->T.TareaID==idMover)
        {
            if(anterior==NULL)
            {
                *pendiente=aux->Siguiente;
                aux->Siguiente=*realizado;
                *realizado=aux;

                encontrado=1;
            }else
            {
                anterior->Siguiente=aux->Siguiente;
                aux->Siguiente=*realizado;
                *realizado=aux;

                encontrado=1;
            }
        }
        
        anterior=aux;
        aux=aux->Siguiente;
    }
    
}

void buscarId(Nodo **pendiente, Nodo **realizado, int idBuscar)
{
    Nodo* aux=*pendiente;
    int encontrado=0;

    while (aux!=NULL && encontrado==0)
    {
        if (aux->T.TareaID==idBuscar)
        {
            printf("\nLa tarea fue encontrada en pendiente y es la siguiente:");
            mostraNodo(*aux);
            encontrado=1;
        }
        aux=aux->Siguiente;
    }
    if (encontrado==0)
    {
        aux=*realizado;
        while (aux!=NULL && encontrado==0)
        {
            if (aux->T.TareaID==idBuscar)
            {
                printf("\nLa tarea fue encontrada en listo y es la siguiente:");
                mostraNodo(*aux);
                encontrado=1;
            }
            aux=aux->Siguiente;
        }
    }
    if (encontrado==0)
    {
        printf("\nNo se encontro la tarea");
    }
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