#include <iostream>
#include <random>

using namespace std;

void ejerc_1_1();
void fun_a(int *px, int *py);
void fun_b(int a[], int tam);

void prbl_2_1();
void prbl_2_2();
bool prbl_2_3();
void prbl_2_4();
void prbl_2_5();
void prbl_2_6();
void prbl_2_7();
void prbl_2_8();
void prbl_2_9();
void prbl_210();
void prbl_211();
void prbl_212();
void prbl_213();
void prbl_214();
void prbl_215();
void prbl_216();
void prbl_217();
void prbl_218();

int main()
{
    int selec;
    cout << "Ingrese el ejercicio a hacer : " << endl;
    cin >> selec;
    switch (selec)
    {/*
    case 101: ejerc_1_1(); break;*/
    case 201: prbl_2_1(); break;
    case 202: prbl_2_2(); break;
    case 203: if (prbl_2_3())cout << "true" << endl;else cout << "false" << endl; break;/*
    case 204: prbl_2_4(); break;
    case 205: prbl_2_5(); break;*/
    case 206: prbl_2_6(); break;/*
    case 207: prbl_2_7(); break;
    case 208: prbl_2_8(); break;
    case 209: prbl_2_9(); break;
    case 210: prbl_210(); break;
    case 211: prbl_211(); break;
    case 212: prbl_212(); break;
    case 213: prbl_213(); break;
    case 214: prbl_214(); break;
    case 215: prbl_215(); break;
    case 216: prbl_216(); break;
    case 217: prbl_217(); break;
    case 218: prbl_218(); break;*/
    default:
        cout << "Opción no válida." << endl;
        break;
    }
    return 0;
}


void fun_a(int *px,int*py)
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
void fun_b(int a[], int tam)
{
    int f, l;
    int *b = a;
    for (f = 0, l = tam -1; f < l; f++, l--)
    {
        fun_a(&b[f], &b[l]);
    }
}
void ejerc_1_1()
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fun_b(array, 10);
}

void prbl_2_1()
{
    int num;
    cout << "Ingrese la cantidad a verificar : " << endl;
    cin >> num;

    for (int i=10000;i>=100;i/=10)
    {
        cout << 5*i << " : " << num/(5*i) << endl;
        num%=(5*i);
        cout << 3*i << " : " << num/(3*i) << endl;
        num%=(3*i);
        cout << i << " : " << num/i << endl;
        num%=i;
    }
    cout << 50 << " : " << num/50 << endl << "Faltante: " << num%50 << endl;
}

void prbl_2_2()
{
    int conNu = 0;
    char letArray[200];
    char letArray2 [200];

    while (conNu<200)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(65, 90);

        int ranNu = dist(gen);

        char letMayu = char (ranNu);
        letArray [conNu] = letMayu;
        conNu++;
    }

    for (int i = 0; i < conNu ; i++)
    {
        cout << letArray[i];
    }
    cout << endl;

    int posic = 0;
    int ciclos = 200;
    int cont = 0;
    for (int i = 0 ; i <= 25 ; i++)
    {
        char letra = char (65+i);

        if (i%2)
        {
            for (int j = 0; j < ciclos; j++)
            {
                if (letArray2[j] == letra) cont += 1;
                else
                {
                    letArray [posic] = letArray2[j];
                    posic++;
                }
            }
        }
        else
        {
            for (int j = 0; j < ciclos; j++)
            {
                if (letArray[j] == letra) cont += 1;
                else
                {
                    letArray2 [posic] = letArray[j];
                    posic++;
                }
            }
        }
        ciclos = posic;
        posic = 0;
        if (cont )cout << letra << ":" << cont << endl;
        cont = 0;
    }
}
bool prbl_2_3()
{
    int tam;
    cout << "Ingrese el tamaño máximo de las cadenas: ";
    cin >> tam;
    cin.ignore();

    char* cadena_1 = new char[tam];
    char* cadena_2 = new char[tam];

    cout << "Ingrese la primera cadena: ";
    cin.getline(cadena_1, tam);

    cout << "Ingrese la segunda cadena: ";
    cin.getline(cadena_2, tam);

    for (int i = 0; i < tam ; i++)
    {
        if (*(cadena_1+i) != *(cadena_2+i))
        {

            delete[] cadena_1;
            delete[] cadena_2;
            return false;

        }
        if (*(cadena_1+i) == '\0' && *(cadena_2+i) == '\0') return true;
    }
    delete[] cadena_1;
    delete[] cadena_2;
    return true;
}
/*
void prbl_2_4()
{
    int tam;
    cout << "Ingrese el tamaño de la cadena" << endl;
    cin >> tam;
    char cadena[tam];
    cout << "Ingrese la cadena" << endl;
    cin >> cadena;
}
*/
void prbl_2_6()
{
    int tam;
    cout << "Ingrese el tamaño maximo de las cadenas: ";
    cin >> tam;
    cin.ignore();

    char* cadena = new char[tam + 1];
    char* cadena_result = new char[tam + 1];

    cout << "Ingrese la primera cadena: ";
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
    cout << cadena_result << endl;

    delete[] cadena;
    delete[] cadena_result;
}
