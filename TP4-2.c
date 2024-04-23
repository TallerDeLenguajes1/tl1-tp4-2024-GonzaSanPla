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
void mostrarLista(Nodo** lista);


int main()
{
    Nodo* listo=crearLista();
    Nodo* pendiente=crearLista();
    Nodo* nuevo;


    int agregar=1;

    while (agregar==1)
    {   
        nuevo=crearNodo(pendiente);

        agregarPendiente(&pendiente,nuevo);
        printf("\nDesea agragar otro elemento?\n 1-Si\n 0-No");
        scanf("%i",&agregar);
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
