#include "Autor.h"

#include <iostream>
#include <string.h>

using namespace std;

int Autor::lastId = 0;

Autor::Autor()
{
    autorId = lastId + 1;
    lastId++;

    nume = NULL;

    nrCarti = 0;
}
Autor::Autor(const char *nume)
{
    autorId = lastId + 1;
    lastId++;

    this->nume = new char[strlen(nume)];
    strcpy(this->nume, nume);

    nrCarti = 0;
}
Autor::Autor(const char *nume, const int autorId)
{
    this->autorId = autorId;

    this->nume = new char[strlen(nume)];
    strcpy(this->nume, nume);

    nrCarti = 0;
}
// constructor copiere
Autor::Autor(const Autor &a)
{
    autorId = a.autorId;

    nume = new char[strlen(a.nume)];
    strcpy(nume, a.nume);

    nrCarti = a.nrCarti;
    for (int i = 0; i < nrCarti; i++)
    {
        carti[i] = a.carti[i];
    }
}
// getters
char *Autor::getNume()
{
    return nume;
}
int Autor::getAutorId()
{
    return autorId;
}
int Autor::getNrCarti()
{
    return nrCarti;
}
Carte Autor::getCarte(int i) const
{
    if (i < nrCarti && i >= 0)
        return carti[i];
    else
    {
        Carte c;
        return c;
    }
}
// setters
void Autor::setNume(char *nume)
{
    this->nume = new char[strlen(nume)];
    strcpy(this->nume, nume);
}
void Autor::setAutorId(int autorId)
{
    this->autorId = autorId;
}

// operatori =, >>, <<
Autor Autor::operator=(const Autor &a)
{
    autorId = a.autorId;

    nume = new char[strlen(a.nume)];
    strcpy(nume, a.nume);

    nrCarti = a.nrCarti;
    for (int i = 0; i < nrCarti; i++)
    {
        carti[i] = a.getCarte(i);
    }
}

istream &operator>>(istream &in, Autor &a)
{
    cout << "Introduceti autorul" << endl;

    cout << "Nume: ";
    a.nume = new char[100];
    in.getline(a.nume, 100);
    cout << "Numar carti (0 daca nu are): ";
    in >> a.nrCarti;
    for (int i = 0; i < a.nrCarti; i++)
        in >> a.carti[i];

    return in;
}

ostream &operator<<(ostream &out, const Autor &a)
{
    out << "Autorul:" << endl;

    out << "Id: " << a.autorId << endl;
    out << "Nume: " << a.nume << endl;

    if (a.nrCarti == 0) {
        cout << "Autorul nu are carti publicate.";
    } else {
        out << "Autorul a publicat urmatoarele " << a.nrCarti << " carti:\n";
        for (int i = 0; i < a.nrCarti; i++)
            out << a.carti[i] << endl;
    }

    return out;
}
/*
    Operatorul de indexare []
    Operatorul ++ sau -- (cele două forme)
    minim 2 operatori matematici (+,-,* sau /)
    operatorul cast explicit sau implicit
    un operator condițional (<, ><=, >=)
    Operatorul pentru egalitate
    */
int Autor::operator[](int index)
{
    return 0;
}
// ++carte
Autor Autor::operator++() // infix
{
    return *this;
}
// carte++
Autor Autor::operator++(int) // postfix
{
    return *this;
}
Autor Autor::operator--()
{
    return *this;
}
Autor Autor::operator--(int)
{
    return *this;
} // postfix
bool Autor::operator<(Autor a)
{
    return true;
}
bool Autor::operator==(Autor a)
{ // (*)
    return strcmp(nume, a.nume) == 0 && autorId == a.autorId;
}
// destructor
Autor::~Autor()
{
    if (nume)
        delete nume;
}

// functionalitate
void Autor::adaugaCarte(Carte &c)
{
    carti[nrCarti++] = c;
}
Carte Autor::eliminaCarte(int i)
{
    Carte c = carti[i];
    // cout << "CC merge [x]" << endl;
    for (int j = i; j < nrCarti - 1; j++)
    {
        cout << i;
        carti[j] = carti[j + 1];
        // cout << "operator= merge [x]" << endl;
    }
    nrCarti--;

    return c;
}