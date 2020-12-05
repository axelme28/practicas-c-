/*
crear una lista doble que permita
insertar
eliminar
modificar repetidos
 
 a traves del uso del metodo de burbuja 
 para ordenar diferentes datos numericos
*/


#include<conio.h>
#include<iostream>


//estructura del nodo de la lista

struct nodo{
    int nro;
    struct nodo*sgte;
};

typedef struct nodo*TLista;

using namespace std;

//los metodos necesarios para el programa
void insertarAlInicio(TLista &, int);
void insertarAlFinal(TLista &, int);  //tarea

void pausa();
//insertarlo en una posicion en especifico
void insertarEnPosicion(TLista &, int, int);

void eliminarElemento(TLista &, int);

//para eliminar elementos repetidos
void eliminarRepetidos(TLista);  //tarea

void eliminarLista(TLista &);  //tarea

//metodo burbuja
void burbuja(TLista);

void imprimir(TLista);  //tarea :3

void modificar(TLista &, int, int);

//ahi lo hacen va ya me dio sueñito nwn

int main(){
	TLista lista = NULL;
	int opc,valor, pos;
	
	do{
	
	cout<<"Lista doblemente ligada con metodo burbuja"<<endl;
	cout<< "\t\tMenu\n"<<
	"\t1.Insertar elemento al inicio\n"<<
	"\t2.Insertar elemento al final\n"<<
	"\t3.insertar elemento en pocicion\n"<<
	"\t4.Eliminar elemnto\n"<<
	"\t5.Eleminar repetidos\n"<<
	"\t6.Eliminar lista\n"<<
	"\t7.Oedenar por metodo burbuja\n"<<
	"\t8.Imprimir la lista\n"<<
	"\t9.Modificar elemento\n"<<
	"\t10.Salir\n";
	cout<<"Eliga una opcion: ";
	cin>>opc;
	
	switch(opc){
		case 1:
			cout<<"Ingrese el valor a insertar al inicio: ";
			cin>>valor;
			insertarAlInicio(lista,valor);
			pausa();
			break;
		case 2:
			cout<<"Ingrese el valor a insertar al final: ";
			cin>>valor;
			insertarAlFinal(lista,valor);
			pausa();
			break;
		case 3:
			cout<<"Ingrese el valor a insertar: ";
			cin>>valor;
			cout<<"Ingrese la posicion en la que lo desea insertar";
			cin>>pos;
			insertarEnPosicion(lista,valor,pos);
			pausa();
			break;
		case 4: 
			cout<<"Ingrese el valor del elemento a eliminar";
			cin>>valor;
			eliminarElemento(lista,valor);
			pausa();
			break;
		case 5:
			eliminarRepetidos(lista);
			cout<<"Los elemetos repetidos han sido eliminados :v";
			pausa();
			break;
		case 6:
			eliminarLista(lista);
			cout<<"La lista se elimino exiitosamente";
			pausa();
			break;
		case 7:
			burbuja(lista);
			cout<<"La lista se ordeno exitosamente";
			pausa();
			break;
		case 8:
			cout<<"Lista doble: ";
			imprimir(lista);
			cout<<"Fin de la lista ";
			pausa();
			break;
		case 9:
			cout<<"Ingese la posicion a modificar: ";
			cin>>pos;
			cout<<"Ingrese el valor a ingresar; ";
			cin>>valor;
			modificar(lista,valor,pos);
			pausa();
			break;
		case 10:
			return 0;
		default:
			cout<<"Opcion incorrecta :(";
			break;
	}
}while(opc!=10);
}

void pausa(){
	
	cout<<"Presione cualquier tecla para continuar.....................";
	getch();
	system("clear");
}

void insertarAlInicio(TLista &lista, int valor){
    TLista q;
    q = new(struct nodo);
    //apuntamos al inicio de la lista
    q->nro=valor;
    q->sgte=lista;
    lista=q; 
}

void insertarAlFinal(TLista &lista, int valor){
	TLista t, q=new(struct nodo);
	q->nro=valor;
	q->sgte=NULL;
	if(lista==NULL)lista=q;
	else {t=lista;
	      while (t->sgte!=NULL) t=t->sgte;
	      t->sgte=q;
	      }
	} 

void insertarEnPosicion(TLista &lista, int valor, int pos){
    TLista q, t;

    int i;

    q = new (struct nodo);
    q->nro=valor;

    //necesito saber donde esta la posicion antes o despues
    if(pos==1){
        q->sgte=lista;
        lista=q;
    }else{
        //entonces necesito otro n odo
        t = lista;
        for(i=1; t!=NULL; i++){
            //donde estoy
            if(pos==1){
                q->sgte=t->sgte;
                t->sgte=q;
                return;
            }
            t = t->sgte;
        }
    }
    //si me diste una posicion afuera del rango
    cout<<"Error la posicion es incorrecta"<<endl;
}


void eliminarElemento(TLista & lista, int valor){
    TLista q, ant;

    q=lista;

    while(q!=NULL){
        //primero necesitamos el valor que vamos a eliminar
        if(q->nro == valor){
            //tengo otra desicion donde diablos esta
            if(q==lista){
                lista = lista->sgte;

            }else{
                ant->sgte = q->sgte;
                delete(q);
                return;
            }
            
        }
        ant=q;
        q=q->sgte;
        
    }
}
void eliminarRepetidos(TLista lista){
  TLista q,p,r,ant;
  int num;
  q=lista;
  while(q!=NULL)
  { num=q->nro;
    ant=q;
    r=q->sgte;
    while(r!=NULL)
    { if(num==r->nro)
      { ant->sgte=r->sgte;
      cout<<"Eliminando..."<<num<<endl;
      p=r;
      r=r->sgte;
      delete(p);
      }
    else { ant=r;
    r=r->sgte;
    }
    r=r->sgte;
    } 
    q=q->sgte;
    }  
}

void burbuja(TLista lista){
	TLista actual,siguiente,marca;
	int t;
	marca=NULL;
	while(marca!=lista->sgte)
	{ actual=lista;
	  siguiente=actual->sgte;
	  while(siguiente!=marca)
	  { if(actual->nro>siguiente->nro)
	     { t=siguiente->nro;
	       siguiente->nro=actual->nro;
	       actual->nro=t;
	       }
	     actual=actual->sgte;
	     siguiente=actual->sgte;
	     }
	     marca=actual;
	     }
  }

void eliminarLista(TLista & lista){
	lista = NULL;
}

void modificar(TLista &lista,int v,int ps)
{ TLista q,sgte;
  q=lista;
  int i;
  for(i=0;i<ps-1&&q->sgte!=NULL;i++)
     q=q->sgte;
     q->nro=v;
}

void imprimir(TLista lista){
TLista q=lista;

    while(q!=NULL){
        cout<<q->nro<<endl;
        q=q->sgte;
    }
}


