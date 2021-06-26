#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea y retorna un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL; //declaro puntero a LL

    this = (LinkedList*) malloc(sizeof(LinkedList)); //pido espacio en memoria para el nuevo LL

    if(this != NULL) //valido espacio en memoria
	{
		this->size=0;
		this->pFirstNode = NULL;
	}

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL) //valido parametros
	{
		returnAux = this->size;
	}

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL; //declaro auxiliar puntero a nodo (con el nombre que solicita el Doxygen)

	if( this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this) ) //valido parametros
	{
		pNode = this->pFirstNode; //le asigno la direccion del primer nodo, arranco del indice 0

		while(nodeIndex > 0) //para cualquier otro caso donde el indice del nodo no sea el primero
		{
			pNode = pNode->pNextNode; 	//"me muevo" al siguiente nodo, asignandole al auxiliar la direccion del siguiente
			nodeIndex--;				//la cantidad de veces segun el indice
		}
	}

	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	int returnAux = -1;

	Node* newNode = NULL;		//declaro puntero a nuevo nodo
	Node* previousNode = NULL; 	//declaro puntero a nodo anterior

	if( this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this) )	//valido parametros
	{
		newNode = (Node*) malloc(sizeof(Node)); //reservo espacio en memoria para el nuevo nodo

		if(newNode != NULL) //valido espacio en memoria
		{
			newNode->pElement = pElement; //le asigno al puntero al elemento del nuevo nodo, el puntero al elemento pasado por referencia

			if(nodeIndex == 0) //si el indice es el primero de la lista
			{
				newNode->pNextNode = this->pFirstNode; 	//le asigno al puntero al siguiente nodo, la direccion del primer indice, para desplazarlo un "espacio"
				this->pFirstNode = newNode; 			//y guardo el puntero al indice, con la direccion de memoria que resevé
			}
			else
			{
				previousNode = getNode(this, nodeIndex-1); //le asigno al puntero nodo anterio, la direccion de memoria del (indice menos uno)

				if(previousNode != NULL) //valido direccion de memoria
				{
					newNode->pNextNode = previousNode->pNextNode;	//le asigno al puntero al siguiente nodo, la direccion homónima del nodo anterior, para alojar el nuevo "entre" ambos
					previousNode->pNextNode = newNode;				//y reasigo la 'direccion al siguiente nodo' del elemento anterior, al nuevo nodo
				}
			}

			this->size++;
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if( this != NULL && !addNode(this, ll_len(this), pElement) ) //valido parametros, incluyendo el retorno al crear nuevo nodo con el nuevo elemento
    {
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el indice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* pElement = NULL; //delcaro auxiliar retorno sin tipo (con el nombre que solicita el Doxygen)

    Node* auxNode = NULL; //declaro auxiliar puntero a nodo

    if( this != NULL && index >= 0 && index < ll_len(this) ) //valido parametros
    {
    	auxNode = getNode(this, index); //guardo en auxNode el puntero al nodo encontrado segun el indice

    	if(auxNode != NULL) //valido nodo encontrado
    	{
    		pElement = auxNode->pElement; //asigo al retorno, el puntero pElement del nodo encontrado
    	}
    }

    return pElement;
}


/** \brief Inserta un elemento en la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    Node* auxNode = NULL; //declaro auxiliar puntero a nodo

    if( this != NULL && index >= 0 && index < ll_len(this) ) //valido parametros
    {
    	auxNode = getNode(this, index); //obtengo el nodo segun el indice

    	if(auxNode != NULL) //valido retorno de getNode
    	{
    		auxNode->pElement = pElement; //reemplazo el elemento en el nodo segun el indice
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina un elemento del LinkedList, en el índice especificado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* auxNode = NULL; //declaro auxiliar puntero a nodo
    Node* previousNode = NULL; //declaro puntero al nodo siguiente

    if( this != NULL && index >= 0 && index < ll_len(this) ) //valido parametros
    {
    	auxNode = getNode(this, index); //obtengo el nodo segun el indice

    	if(auxNode != NULL) //valido retorno de getNode
    	{
    		if(index == 0) //si es el primero de la lista
    		{
    			this->pFirstNode = auxNode->pNextNode; //le asigno a la direccion del primer elemento de la linkedlist, la direccion del siguiente nodo (transformando a este en el primero)
    		}
    		else //si no es el primero de la lista
    		{
    			previousNode = getNode(this, index-1);

    			if(previousNode != NULL)
    			{
    				previousNode->pNextNode = auxNode->pNextNode; //le asigno al elemento anterior, la direccion del elemento siguiente
    			}
    		}
    	}

    	free(auxNode); //libero espacio en memoria del nodo removido
    	this->size--;	//resto 1 al tamaño del LL
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL) //valido parametros
    {
    	for(int i=0; i<ll_len(this); i++) //iteracion para recorrer la totalidad de la lista
    	{
    		if( !ll_remove(this, i) ) //valido retorno de la funcion ll_remove
    		{
    			returnAux = 0;
    		}
    		else
    		{
    			returnAux = -1;
				break;
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if( this != NULL && !ll_clear(this) ) //valido parametros y retorno de funcion clear
    {
    	free(this); //libero memoria reservada que alojaba a la lista

    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    void* auxpElement = NULL; //declaro auxiliar puntero a elemento sin tipo

    if(this != NULL) //valido parametros
    {
		for(int i=0; i<ll_len(this); i++) //recorro lista de elementos
		{
			auxpElement = ll_get(this, i); //asigno el puntero de cada elemento de la iteracion, al puntero auxiliar

			if(auxpElement == pElement) //valido el puntero retornado por ll_get y lo comparo con el puntero al elemento pasado por referencia
			{
				returnAux = i;  //si coinciden retorno el indice en la lista
				break;			//y rompo interacion
			}
		}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL) //valido parametros
    {
    	returnAux = 1;

    	if(ll_len(this) > 0) //si el tamaño de la lista es mayor a 0 entonces no esta vacía
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if( this != NULL && index >= 0 && index <= ll_len(this) ) //valido parametros
    {
    	if( !addNode(this, index, pElement) ) //valido retorno de la funcion addNode
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index)
{
    void* pElement = NULL; //delcaro auxiliar retorno sin tipo (con el nombre que solicita el Doxygen)

    if( this != NULL && index >= 0 && index < ll_len(this) ) //valido parametros
    {
    	pElement = ll_get(this, index); //asigno al puntero el elemento a remover (segun el indice) para poder retornarlo

    	ll_remove(this, index); //remuevo el elemento segun el indice
    }

    return pElement;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
	{
    	if( ll_indexOf(this, pElement) >= 0 )
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
	}

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    void* auxpElement = NULL; //delcaro auxiliar puntero a elemento sin tipo

    if(this != NULL && this2 != NULL) //valido parametros
	{
    	returnAux = 1;

    	for(int i=0; i<ll_len(this2); i++) //recorro la 2da lista
    	{
    		auxpElement = ll_get(this2, i); //asigno al auxiliar cada puntero a elemento de la 2da lista

    		if( auxpElement != NULL && !ll_contains(this, auxpElement) ) //valido el retorno de ll_get, y busco el mismo elemento en la 1era lista
    		{
    			returnAux = 0;
    			break;
    		}
    	}
	}

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL; //declaro retorno puntero a lista

    if( this != NULL && from >= 0  && to > from && to <= ll_len(this) ) //valido parametros
    {
    	cloneArray = ll_newLinkedList(); //asigno al puntero a lista, el puntero de la lista creada por funcion;

    	for(int i=from; i<to; i++) //recorro el tramo (desde-hasta)
    	{
    		ll_add( cloneArray, ll_get(this, i) ); //añado a la nueva lista cada elemento del tramo
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL; //declaro retorno puntero a lista

    if(this != NULL) //valido parametros
    {
    	cloneArray = ll_subList(this, 0, ll_len(this)); //le asigno al puntero a lista, el retorno de la funcion ll_sublist (crea y copia donde el tramo es el total)
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    void* auxpElement1 = NULL; //delcaro auxiliar puntero a elemento A sin tipo
    void* auxpElement2 = NULL; //delcaro auxiliar puntero a elemento B sin tipo

    if( this != NULL && pFunc != NULL && (order == 0 || order == 1) ) //valido parametros
    {
    	for(int i=0; i<ll_len(this)-1; i++)
    	{											//burbujeo
    		for(int j=i+1; j<ll_len(this); j++)
    		{
    			auxpElement1 = ll_get(this, i); //asigno los punteros a dos elementos
    			auxpElement2 = ll_get(this, j);	//   siguiendo el burbujeo

    			if( (pFunc(auxpElement1, auxpElement2) < 0 && !order) || //si la funcion retorna -1 y el orden es descendente o
					(pFunc(auxpElement1, auxpElement2) > 0 && order)	)  //si la funcion retorna 1 y el orden es ascendente
    			{
    				ll_set(this, i, auxpElement2);
    				ll_set(this, j, auxpElement1);
    			}
    		}
    	}

    	returnAux = 0;
    }

    return returnAux;
}

//Desarrollar la funcion ll_map en la bilbioteca linkedlist, la cual recibirla la lista y una funcion. 
//La funcion ejecutara la funcion recibida como parametro por cada item de la liusta, 
//de este modo se realizara un aumento de sueldo del 10% a aquellos empleados que ganan mas de $20000

/** \brief Ejecuta una funcion pasada por referencia a cada elemento de la lista de elementos
 *
 * \param this LinkedList* Puntero a la lista de elmentos
 * \param (*pFunc)(void*)* int Puntero a la función a ejecutar
 *
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) si No hubo problemas
 *
 */
int ll_map(LinkedList* this,int (*pFunc)(void*))
{
	int error = -1;
	
	void* aux = NULL;
	
	if(this != NULL && pFunc != NULL)
	{
		error = 0;
		for(int i=0; i<ll_len(this); i++)
		{
			aux = ll_get(this, i);
			pFunc(aux);
		}
	}	
	
    return error;
}


