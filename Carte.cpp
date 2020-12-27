#include "Carte.h"

#include <iostream>
#include <fstream>

using namespace std;

int Carte::lastId = 0;

Carte::Carte()
{
    carteId = lastId + 1;
    lastId++;

    autorId = 0;
    titlu = NULL;
    editura = NULL;
}
Carte::Carte(const char *titlu, const char *editura, const int autorId)
{
    carteId = lastId + 1;
    lastId++;

    this->titlu = new char[strlen(titlu)];
    strcpy(this->titlu, titlu);
    this->editura = new char[strlen(editura)];
    strcpy(this->editura, editura);
    this->autorId = autorId;
}
Carte::Carte(const char *titlu, const char *editura)
{
    carteId = lastId + 1;
    lastId++;

    this->titlu = new char[strlen(titlu)];
    strcpy(this->titlu, titlu);
    this->editura = new char[strlen(editura)];
    strcpy(this->editura, editura);
    this->autorId = 0;
}
// constructor copiere
Carte::Carte(const Carte &carte)
{
    this->carteId = carte.carteId;
    this->titlu = new char[strlen(carte.titlu)];
    strcpy(this->titlu, carte.titlu);
    this->editura = new char[strlen(carte.editura)];
    strcpy(this->editura, carte.editura);
    this->autorId = carte.autorId;
}
// getters
char *Carte::getTitlu() const
{
    return titlu;
}
char *Carte::getEditura() const
{
    return editura;
}
int Carte::getCarteId() const
{
    return carteId;
}
bool Carte::getEsteImprumutata() const
{
    return esteImprumutata;
}

// operatori =, >>, <<
Carte Carte::operator=(const Carte &carte)
{
    this->carteId = carte.carteId;
    this->titlu = new char[strlen(carte.titlu)];
    strcpy(this->titlu, carte.titlu);
    this->editura = new char[strlen(carte.editura)];
    strcpy(this->editura, carte.editura);
    this->autorId = carte.autorId;

    return *this;
}
istream &operator>>(istream &i, Carte &c)
{
    cout << "Introduceti cartea\n";

    cout << "Titlu: ";
    c.titlu = new char[100];
    i.getline(c.titlu, 100);
    cout << "Editura: ";
    c.editura = new char[100];
    i.getline(c.editura, 100);

    cout << "Id autor:";
    i >> c.autorId;

    return i;
}
ostream &operator<<(ostream &o, const Carte &c)
{
    o << "Cartea:" << endl;

    o << "Id: " << c.carteId << endl;
    o << "Titlu: " << c.titlu << endl;
    o << "Editura: " << c.editura << endl;

    o << "Id autor:" << c.autorId << endl;

    return o;
}

/*
    Operatorul de indexare []
    Operatorul ++ sau -- (cele două forme)
    minim 2 operatori matematici (+,-,* sau /)
    operatorul cast explicit sau implicit
    un operator condițional (<, ><=, >=)
    Operatorul pentru egalitate
    */
int Carte::operator[](int i)
{
    return 0;
}
Carte Carte::operator++()
{
    return *this;
}
Carte Carte::operator++(int)
{
    return *this;
} // postfix
Carte Carte::operator--()
{
    return *this;
}
Carte Carte::operator--(int)
{
    return *this;
} // postfix
bool Carte::operator<(Carte c)
{
    return true;
}
bool Carte::operator==(Carte c)
{ // (*)
    return strcmp(this->titlu, c.titlu) == 0 &&
           strcmp(this->editura, c.editura);
}
// destructor
Carte::~Carte()
{
    if (titlu)
        delete titlu;
    if (editura)
        delete editura;
}
// functionalitate

bool Carte::aFostImprumutata()
{
    if (esteImprumutata)
    {
        cout << "Cartea " << titlu << " este deja imprumutata." << endl;
        return false;
    }
    else
    {
        esteImprumutata = true;
        return true;
    }
}
