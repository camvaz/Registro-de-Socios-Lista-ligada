#include "socio.h"

class ListaDoble;

class nodo
{
    nodo *right;
    nodo *left;
    socioClub data;
public:
    nodo():right(NULL), left(NULL){data;}
    friend class ListaDoble;
};

class ListaDoble
{
    nodo *head;
    nodo *tail;
    int cardinalidad;
public:
    ListaDoble(): head(NULL), tail(NULL), cardinalidad(0){}
    void insertaInicio(socioClub);
    void insertaFinal(socioClub);
    void insertaSocio(socioClub);
    int eliminaSocio(socioClub);
    void reporteAntiguedad(int);
    void cambiaDomicilio(socioClub&);
    void imprimeSocios();
    int totalDeSocios();
};

void ListaDoble::insertaInicio(socioClub Inf)
{
    nodo *p = new nodo();
    p->data = Inf;
    p->right = head;
    if(head)
        head->left = p;
    else
        tail = p;
    head = p;
}

void ListaDoble::insertaFinal(socioClub Dato)
{
    nodo *temp;
    temp = new nodo;
    temp->data = Dato;
    temp->left = tail;
    if(tail)
        tail->right = temp;
    else
        head=temp;
    tail = temp;
}

void ListaDoble::insertaSocio(socioClub Dato)
{

    nodo *check, *nuevo, *temp1, *temp2;
    check = head;
    int flag = 1;

    while(check!=NULL)
    {
        if(check->data.getNumSocio()==Dato.getNumSocio())
            flag = 0;
        check = check->right;
    }

    if(flag==0)
        cout<<"ID Repetido! Favor de intentar con un ID diferente :^)"<<endl;
    else
    {
        if(!head||Dato<head->data)
            insertaInicio(Dato);
        else
            if(Dato>tail->data)
            insertaFinal(Dato);
        else
        {
            nuevo = new nodo();
            nuevo->data=Dato;
            temp1 = head;
            while(temp1->data < nuevo->data)
                temp1 = temp1->right;
            temp2 = temp1->left;
            temp2->right=nuevo;
            nuevo->right=temp1;
            nuevo->left=temp2;
            temp1->left= nuevo;
        }
        cout<<"Socio registrado. En seguida se imprimen los datos registrados."<<endl<<endl;
        cout<<'\t'<<"NUMERO:"<<'\t'<<"NOMBRE:"<<'\t'<<'\t'<<"ANIO DE INGRESO:"<<'\t'<<"DOMICILIO:"<<'\t'<<endl<<endl;
        Dato.print4list();
        cardinalidad++;
    }
}

int ListaDoble::eliminaSocio(socioClub Dato)
{
    nodo *temp1, *temp2, *temp3;
    int Resp = 1;

    if(head)
    {
        temp1=head;
        while((temp1!=NULL)&&(temp1->data!=Dato))
            temp1=temp1->right;
        if(temp1==NULL)
            Resp=0;
        else
        {
            if(head==tail)
            {
                head==NULL;
                tail==NULL;
            }
            else
                if(temp1 == head)
                {
                    head = temp1->right;
                    head->left = NULL;
                }
                else
                    if(temp1 == tail)
                    {
                        tail = temp1->left;
                        tail->right=NULL;
                    }
                    else
                    {
                        temp2=temp1->left;
                        temp3=temp1->right;
                        temp2->right=temp3;
                        temp3->left=temp2;
                    }
                delete(temp1);
        }
    }
    else
        Resp = -1;
    cardinalidad--;
    return Resp;
}

void ListaDoble::reporteAntiguedad(int Dato)
{
    nodo* r = new nodo();
    r= head;
    cout<<'\t'<<"NUMERO:"<<'\t'<<"NOMBRE:"<<'\t'<<'\t'<<"ANTIGUEDAD"<<endl;
    while(r!=NULL)
    {
        if(r->data.getAntiguedad()<=Dato){
            r->data.print4antiguedad();
            r=r->right;
        }
        else
            r=r->right;
    }
}

void ListaDoble::cambiaDomicilio(socioClub &a)
{
    nodo *p = new nodo();
    p = head;
    while(p!=NULL && p->data!=a)
    {
        p=p->right;
    }
    if(p)
    {
        cout<<"Socio a modificar:"<<endl;
        cout<<'\t'<<"NUMERO:"<<'\t'<<"NOMBRE:"<<'\t'<<'\t'<<"ANIO DE INGRESO:"<<'\t'<<"DOMICILIO:"<<'\t'<<endl<<endl;
        p->data.print4list();
        cout<<endl;
        p->data.setDomicilio();
    }
    else
        cout<<"No se encontro un cliente con los datos ingresados";
}

void ListaDoble::imprimeSocios()
{
    if(cardinalidad!=0)
    {
        nodo *p = new nodo();
        p = head;
        cout<<"Imprimiendo lista..."<<endl<<endl;
        cout<<'\t'<<"NUMERO:"<<'\t'<<"NOMBRE"<<'\t'<<'\t'<<"ANIO DE INGRESO:"<<'\t'<<"DOMICILIO:"<<'\t'<<endl<<endl;
        while(p!=NULL)
        {
            p->data.print4list();
            p=p->right;
        }
    }
    else
    {
        cout<<"No hay socios en la lista"<<endl;
    }
}

int ListaDoble::totalDeSocios()
{
    return cardinalidad;
}
