#include <iostream>
#include <cstdlib>
#include <cmath>
double sixhump (double * x)
{
    double f = (4-2.1*pow(x[0],3.0)+pow(x[0],4.0)/3)*pow(x[0],2.0)+x[0]*x[1]+(-4+4*pow(x[1],2.0))*pow(x[1],2.0); //pow - kelimas laipsniu. pvz x kvadratu = pow (x , 2.0)
    return f;
}


using namespace std;

int main()
{
    cout << "Monte Carlo realizacijos pradzia" << endl;
    cout << "(RANDOM SEARCH METHOD)" << endl;
    // Kintamuju apsirasymas
    double f, x; // Funkcijos reiksmes ir argumentas x
    int n; // Uzedavinio dimensija
    double xSprendinys; // Argumento reiksme
    int fSprendinys; // Uzdavinio sprendinys

    // Vektoriu kurimas, kuriu elementai yra atitiktiniai realus skaiciai

    double virsutinis_rezis, apatinis_rezis; // apsirasome intervalo rezius

    cout << "Iveskite inervalo rezius:" << endl;
    cin >> apatinis_rezis >> virsutinis_rezis;
    cout << "Iveskite vektoriaus ilgi:" << endl;
    cin >> n;

    double vektorius[n];
    cout << "x = ( ";

    for(int i=0; i<n; i++)
    {
        vektorius[i] = rand() * (virsutinis_rezis - apatinis_rezis) / RAND_MAX + apatinis_rezis;
        cout << vektorius[i] << "  "; // Vektoriaus isvedimas i ekrana
    }
     cout << ")" <<endl;
     cout <<"Six hump funkcijos reiksme "<< sixhump(&vektorius[0]) <<endl;

    return 0;
}
