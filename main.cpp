///TAREA 3: PROGRAMA DE REGISTRO DE SOCIOS.
///CAMPOS VAZQUEZ VICTOR MANUEL
///PROGRAMACION ORIENTADA A OBJETOS II
///PROF: DR. ABRAHAM SANCHEZ
#include "ListaDoble.h"
#include <stdlib.h>

int main()
{
    bool flag = true;
    ListaDoble Club;
    socioClub aux;
    int numero;
    int opc;
    char dale;
    char a[40] = "Juan Perez", b[40] = "Higos 12, Exhacienda Huertos", c[40] = "Luis Sanchez", d[40] = "Pinos 90, Bosques de Aragon", e[40] = "Celinda Huerta", f[40] = "Robles 114, Andromeda";
    socioClub frst(1, a, b, 2015), scnd(2, c, d, 2009), thrd(3, e, f, 2012);
    Club.insertaSocio(frst); Club.insertaSocio(scnd); Club.insertaSocio(thrd);
    clear();

    while(flag)
    {
        //MENU
        cout<<'\t'<<'\t'<<'\t'<<"SISTEMA DE SOCIOS"<<endl<<endl;
        cout<<'\t'<<"Opciones: "<<endl<<endl;
        cout<<'\t'<<'\t'<<"Registrar nuevo socio: 1"<<endl;
        cout<<'\t'<<'\t'<<"Dar de baja a socio: 2"<<endl;
        cout<<'\t'<<'\t'<<"Generar reporte por antiguedad: 3"<<endl;
        cout<<'\t'<<'\t'<<"Cambiar domicilio de un miembro: 4"<<endl;
        cout<<'\t'<<'\t'<<"Generar reporte de todos los socios: 5"<<endl;
        cout<<'\t'<<'\t'<<"Calcular total de socios: 6"<<endl;
        cout<<'\t'<<'\t'<<"Salir: 7"<<endl<<endl;
        cout<<'\t'<<"Ingrese una opcion: ";

        cin>>opc;
        clear();
        cout<<endl;

        switch(opc)
        {
            case 1:

                aux.setFullData();

                Club.insertaSocio(aux);

                cout<<endl;
                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 2:

                cout<<"Introduce el numero del socio a eliminar: ";
                cin>>numero;

                aux.setData(numero);
                if(Club.eliminaSocio(aux) == 1)
                    cout<<"Socio eliminado con exito."<<endl;
                else
                    cout<<"No se encontro socio con el numero ingresado."<<endl;

                cout<<endl<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 3:

                cout<<"Introduce la antiguedad minima a desplegar: ";
                cin>>numero;
                cout<<endl;

                Club.reporteAntiguedad(numero);
                cout<<endl;

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 4:

                cout<<"Introduce el numero del socio a modificar: ";
                cin>>numero;

                aux.setData(numero);
                Club.cambiaDomicilio(aux);
                cout<<endl;

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 5:

                Club.imprimeSocios();
                cout<<endl;

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 6:

                cout<<"El total de socios en la lista es: "<<Club.totalDeSocios()<<endl;

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            case 7:

                flag = false;

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;

            default:

                cout<<"Opcion invalida, intentar de nuevo"<<endl;

                cout<<"Desea salir?(s/n): ";
                cin>>dale;
                if(dale == 's') flag = false;

                clear();
                break;
        }
    }

}
