#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <ctime>

// funkcija
double sixhump(double *x)
{
    double f = (4- 2.1 * x[0] * x[0] + (pow(x[0],4))/3) * x[0] * x[0] + x[0] * x[1] + (-4+4*x[1]*x[1])*(pow(x[1],2));
    return f;
}

using namespace std;

int main()
{
    cout << "Monte Carlo realizacijos pradzia" << endl;
    cout << "(RANDOM SEARCH METHOD)" << endl;
    // Kintamuju apsirasymas
    double f, x; // Funkcijos reiksmes ir argumentas x
    int n, // Uzedavinio dimensija
        k; // Iteraciju skaicius
    double xSprendinys; // Argumento reiksme
    int fSprendinys; // Uzdavinio sprendinys

    // Vektoriu kurimas, kuriu elementai yra atitiktiniai realus skaiciai

    double virsutinis_rezis, apatinis_rezis, virsutinis_rezis2, apatinis_rezis2; // apsirasome intervalo rezius

/*
    cout << "Iveskite inervalo rerzius x1: ";
    cin >> apatinis_rezis >> virsutinis_rezis;
    cout << "Iveskite inervalo rerzius x2: ";
    cin >> apatinis_rezis2 >> virsutinis_rezis2;
    cout << "Iveskite vektoriaus ilgi: ";
    cin >> n;
*/
    cout << "Inervalo rerzius x1: [-1.9 : 1.9]"<<endl;  apatinis_rezis = -1.9; virsutinis_rezis = 1.9;
    cout << "Inervalo rerzius x1: [-1.1 : 1.1] "<<endl; apatinis_rezis2 = -1.1; virsutinis_rezis2 = 1.1;
    cout << "Vektoriaus ilgis: 2"<<endl;                n=2;
    cout << "Iveskite kiek skaiciavimu atlikti: ";      cin >> k;
    cout <<"======================================================"<<endl;
    double vektorius[n], funkcija[2*k];

//--------------------------------------------------------------------
// Neteisingas sprendimas

/*        for(int i=0; i<n; i++)
        {
        if (i == 0)
        {
           vektorius[i] = rand() * (virsutinis_rezis - apatinis_rezis) / RAND_MAX + apatinis_rezis;
//           cout << "Skaicius1 = " << vektorius[i] << endl; // pakeiciau
        }
        else
        {
           vektorius[i] = rand() * (virsutinis_rezis2 - apatinis_rezis2) / RAND_MAX + apatinis_rezis2;
//           cout << "Skaicius2 = " << vektorius[i] << endl; // pakeiciau
        }
        }
        double Fmin = sixhump(&vektorius[0]);
         cout << "Funkcijos min reiksme atsitiktiniuose taskuose = " << Fmin << endl;

*/
// -------------------------------------------------------------------
//    srand(time(0)); // randomas priklausantis nuo laiko
    srand(5322);
    for (int j=0; j<k; j++)
    {

    for(int i=0; i<n; i++)
    {
        if (i == 0)
        {
           vektorius[i] = rand() * (virsutinis_rezis - apatinis_rezis) / RAND_MAX + apatinis_rezis;
//           cout << "Skaicius = " << vektorius[i] << endl; // pakeiciau
        }
        else
        {
           vektorius[i] = rand() * (virsutinis_rezis2 - apatinis_rezis2) / RAND_MAX + apatinis_rezis2;
//           cout << "Skaicius = " << vektorius[i] << endl; // pakeiciau
        }

    }

//    cout << "Funkcija = " << sixhump(&vektorius[0]) << endl; // pakeiciau
//    cout << "===================================" << endl;
    funkcija[j] = sixhump(&vektorius[0]);
    }

//==================================================================
    double Fmin = funkcija[0];
    for (int i=0; i<k; i++)
    {
        if (funkcija[i] < Fmin) Fmin = funkcija[i];
    }

    cout << "MIN: " << Fmin<<endl;
    cout <<"======================================================"<<endl;

//===========suranda 1-aja reiksme mazesne uz E =============================
    double E=1, E_const = 0.01;

    //----------
    int kiek=0;
    for (int i=0; i<(2*k); i++)
    {
        E = abs(abs(Fmin) - abs(funkcija[i]));
        if (E < E_const)
        {
            kiek++;
            cout <<i<<".  "<< Fmin <<" - "<<funkcija[i]<<" = "<< E <<endl;
        }
    }
    cout<< "Paklaida < "<<E_const<<" gaunama "<<kiek<<" kartu"<<endl;
    cout <<"======================================================"<<endl;

    //----------
/*    int i=0;
    while (E > E_const)
    {
        cout <<i<<".  ";
        E = abs(abs(Fmin) - abs(funkcija[i]));
        i++;
        cout << Fmin <<" - "<<funkcija[i]<<" = "<< E <<endl;
    }
//    cout << Fmin <<" - "<<funkcija[i]<<" = "<< E <<endl;
    cout << "Pirmoji paklaida < "<<E_const<<" ties " << i-1 << " bandymu. "<<endl ;

*/
//===========================================================================
    return 0;
}
