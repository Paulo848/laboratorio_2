#include <iostream>

using namespace std;

void obtenerCombinacionMinima();
void convertirAMayusculas();

int main()
{
    int selec;
    cout << "Ingrese el ejercicio a hacer : " << endl
         << "1 Calculadora de cambio minimo con billetes y monedas" << endl
         << "6 Convertidor de minusculas a mayusculas en cadenas de texto"<< endl;
    cin >> selec;

    switch (selec)
    {
        case 1: obtenerCombinacionMinima(); break;
        case 6: convertirAMayusculas(); break;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }
    return 0;
}

void obtenerCombinacionMinima()
{
    int num;
    cout << "Ingrese la cantidad a calcular el minimo cambio : " << endl;
    cin >> num;

    for (int i=10000;i>=100;i/=10)
    {
        cout << 5*i << " : " << num/(5*i) << endl;
        num%=(5*i);
        cout << 2*i << " : " << num/(3*i) << endl;
        num%=(2*i);
        cout << i << " : " << num/i << endl;
        num%=i;
    }
    cout << 50 << " : " << num/50 << endl << "Faltante: " << num%50 << endl;
}
void convertirAMayusculas()
{
    int tam;
    cout << "Ingrese el tamano maximo de la cadena: ";
    cin >> tam;
    cin.ignore();

    char* cadena = new char[tam + 1];
    char* cadena_result = new char[tam + 1];

    cout << "Ingrese la cadena: " << endl;
    cin.getline(cadena, tam + 1);

    char* carct = cadena;
    char* resul = cadena_result;


    while (*carct != '\0')
    {
        if(*carct >= 'a' && *carct <= 'z')*resul = *carct-('a'-'A');
        else *resul = *carct;
        carct++;
        resul++;
    }
    *resul = '\0';

    cout << endl << "Original: " << cadena << endl;
    cout << "En mayuscula: " << cadena_result << endl;

    delete[] cadena;
    delete[] cadena_result;
}
