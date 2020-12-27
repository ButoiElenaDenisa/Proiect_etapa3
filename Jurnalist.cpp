#include "Jurnalist.h"
#include "Autor.h"

using namespace std;

Jurnalist::Jurnalist() // vector
{
}
Jurnalist::Jurnalist(const char *nume) : Autor(nume)
{
}
Jurnalist::Jurnalist(const char *nume, const int autorId) : Autor(nume, autorId)
{
}
void Jurnalist::adaugaApreciere(const Apreciere *a)
{
    aprecieri[nrAprecieri++] = a;
}
double Jurnalist::apreciereMedie()
{
    double suma = 0;
    for (int i = 0; i < nrAprecieri; i++)
    {
        suma += aprecieri[i]->getValoareApreciere();
    }
    return suma / nrAprecieri;
}
