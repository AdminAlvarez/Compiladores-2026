#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

enum class Estado{INICIO, Q1, Q2, ENTERO, REAL, ERROR}; // estados del automata

Estado reconNum(const string& entradaUser); // paso por referencia

int main() {
    cout << "RECONOCER NUMERO ENTERO O REAL" << endl;
    string entradaUser;
    cin >> entradaUser;
    Estado ultimo = reconNum(entradaUser);
    if (ultimo == Estado::ENTERO)
    {
        cout << "Cadena ingresada es numero entero" << endl;
    }
    else if (ultimo == Estado::REAL)
    {
        cout << "Cadena ingresada es numero real" << endl;
    }
    else
    {
        cout << "Cadena ingresada no es numero entero ni real" << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
    main();
    return 0;
}

Estado reconNum(const string& entradaUser)
{
    unsigned int pos = 0; // posicion de validacion de los caracteres
    Estado actual = Estado::INICIO;
    bool cadenaRechazada = false;
    while (not cadenaRechazada and pos < entradaUser.length())
    {
        char simbolo = entradaUser[pos];
        switch (actual)
        {
        case Estado::INICIO:
            if (isdigit(simbolo)) // SI ES DIGITO PASAMOS A ENTERO
            {
                actual = Estado::ENTERO;
            }
            else if (simbolo == '+' or simbolo == '-') // SI ES SÍMBOLO PASAMOS A Q1
            {
                actual = Estado::Q1;
            }
            else
            {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q1:
            if (isdigit(simbolo)) // SI ES DIGITO PASAMOS A ENTERO
            {
                actual = Estado::ENTERO;
            }
            else if (simbolo == '.') // SI ES . PASAMOS A Q2
            {
                actual = Estado::Q2;
            }
            else
            {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q2:
            if (isdigit(simbolo)) // SI ES DIGITO PASAMOS A ENTERO
            {
                actual = Estado::REAL;
            }
            else
            {
                cadenaRechazada = true;
            }
            break;
        case Estado::ENTERO:
            if (isdigit(simbolo)) // SI ES DIGITO PASAMOS A ENTERO
            {
                actual = Estado::ENTERO;
            }
            else if (simbolo == '.') // SI ES . PASAMOS A Q2
            {
                actual = Estado::Q2;
            }
            else
            {
                cadenaRechazada = true;
            }
            break;
        case Estado::REAL:
            if (isdigit(simbolo))
            {
                actual = Estado::REAL;
            }
            else
            {
                cadenaRechazada = true;
            }
            break;
        }
        pos++;
    }
    if (cadenaRechazada)
    {
        return Estado::ERROR;
    }
    return actual;
}

