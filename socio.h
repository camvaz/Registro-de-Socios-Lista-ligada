#include <iostream>
#include <windows.h>
const int MAX_NAMESIZE = 40;
using namespace std;

class socioClub
{
    int yrIngreso;
    char domicilio[MAX_NAMESIZE];
    char nombreSocio[MAX_NAMESIZE];
    int numeroSocio;
public:
    socioClub():
        yrIngreso(0),
        numeroSocio(0)
        {}
    socioClub(int a, char b[MAX_NAMESIZE], char c[MAX_NAMESIZE], int d):
        yrIngreso(d),
        numeroSocio(a)
        {
            for(int i = 0; i<MAX_NAMESIZE; i++)
            {
                domicilio[i] = c[i];
            }
            for(int i = 0; i<MAX_NAMESIZE; i++)
            {
                nombreSocio[i] = b[i];
            }
        }
    bool operator>(const socioClub&);
    bool operator<(const socioClub&);
    friend bool operator!=(const socioClub&, const socioClub&);
    void print4antiguedad();
    void print4list();
    void print();
    int getAntiguedad();
    int getNumSocio();
    void setDomicilio();
    void setData(int);
    void setFullData();
};

bool socioClub::operator>(const socioClub &e)
{
    return numeroSocio > e.numeroSocio;
}

bool socioClub::operator<(const socioClub &e)
{
    return numeroSocio < e.numeroSocio;
}

bool operator!=(const socioClub &l, const socioClub &e)
{
    return l.numeroSocio!=e.numeroSocio;
}

void socioClub::print4antiguedad()
{
    cout<<'\t'<<numeroSocio<<'\t'<<nombreSocio<<'\t'<<'\t'<<getAntiguedad()<<endl;
}

void socioClub::print4list()
{
    cout<<'\t'<<numeroSocio<<'\t'<<nombreSocio<<'\t'<<'\t'<<yrIngreso<<'\t'<<'\t'<<'\t'<<domicilio<<'\t'<<endl;
}

void socioClub::print()
{
    cout<<"Datos del miembro solicitado: "<< nombreSocio <<endl<<endl;
    cout<<'\t'<<"NUMERO:"<<'\t'<<"NOMBRE:"<<'\t'<<'\t'<<"ANIO DE INGRESO:"<<'\t'<<"DOMICILIO:"<<'\t'<<endl<<endl;
    cout<<'\t'<<numeroSocio<<'\t'<<nombreSocio<<'\t'<<yrIngreso<<'\t'<<'\t'<<'\t'<<domicilio<<'\t'<<endl;
}

int socioClub::getAntiguedad()
{
    return 2018-yrIngreso;
}

int socioClub::getNumSocio()
{
    return numeroSocio;
}

void socioClub::setDomicilio()
{
    cout<<"Introduzca nuevo domicilio: ";
    cin.ignore();
    cin.getline(domicilio, MAX_NAMESIZE);
    cout<<"Domicilio cambiado con exito, el domicilio es: "<<domicilio<<endl;
}

void socioClub::setData(int a)
{
    numeroSocio = a;
}

void socioClub::setFullData()
{
    cout<<"Ingresa nombre del socio: ";
    cin.ignore();
    cin.getline(nombreSocio, MAX_NAMESIZE);

    cout<<"Ingresa domicilio del socio: ";
    cin.getline(domicilio, MAX_NAMESIZE);

    cout<<"Ingresa el anio de entrada del socio: ";
    cin>>yrIngreso;
    cout<<endl;

    cout<<"Ingresa el numero (ID) del socio: ";
    cin>>numeroSocio;
    cout<<endl;
}

void clear() {
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

struct IDRepetido
{
    IDRepetido(){}
    void what(){cout<<"Excepcion disparada debido a que el ID que se trata de ingresar ya existe en la lista";}
};
