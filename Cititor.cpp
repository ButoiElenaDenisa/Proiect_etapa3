#include "Cititor.h"

#include <iostream>
#include <string.h>

#include "Imprumut.h"
#include "Autor.h"

using namespace std;

int Cititor::lastId = 0;

Cititor::Cititor()
{
    cititorId = lastId + 1;
    lastId++;

    nume = NULL;
}
Cititor::Cititor(const char *nume)
{
    cititorId = lastId + 1;
    lastId++;

    this->nume = new char[strlen(nume)];
    strcpy(this->nume, nume);
}
Cititor::Cititor(const char *nume, const int cititorId)
{
    this->cititorId = cititorId;

    this->nume = new char[strlen(nume)];
    strcpy(this->nume, nume);
}
// constructor copiere
Cititor::Cititor(const Cititor &a)
{
    cititorId = a.cititorId;

    nume = new char[strlen(a.nume)];
    strcpy(nume, a.nume);
}
// getters
char *Cititor::getNume() const
{
    return nume;
}
int Cititor::getCititorId() const
{
    return cititorId;
}
// setters
void Cititor::setNume(char *nume)
{
    this->nume = new char[strlen(nume)];
    strcpy(this->nume, nume);
}
void Cititor::setAutorId(int cititorId)
{
    this->cititorId = cititorId;
}
// operatori =, >>, <<
Cititor Cititor::operator=(Cititor &c)
{
    this->cititorId = c.cititorId;

    nume = new char[strlen(c.nume)];
    strcpy(nume, c.nume);

    return *this;
}
istream &operator>>(istream &i, Cititor &a)
{
    cout << "Introduceti autorul";

    cout << "Nume: ";
    // if (a.nume)
    // {
    //     delete []a.nume;
    // }
    a.nume = new char[101];
    i.getline(a.nume, 100);

    return i;
}
ostream &operator<<(ostream &o, const Cititor &c)
{
    o << "Cititorul:" << endl;

    o << "Id: " << c.cititorId << endl;
    o << "Nume: " << c.nume << endl;

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
int Cititor::operator[](int i)
{
    return 0;
}
Cititor Cititor::operator++()
{
    return *this;
}
Cititor Cititor::operator++(int)
{
    return *this;
} // postfix
Cititor Cititor::operator--()
{
    return *this;
}
Cititor Cititor::operator--(int)
{
    return *this;
} // postfix
bool Cititor::operator<(Cititor a)
{
    return true;
}
bool Cititor::operator==(Cititor a)
{
    // (*)
    return strcmp(nume, a.nume) == 0 && cititorId == a.cititorId;
}
// destructor
Cititor::~Cititor()
{
    if (nume)
        delete nume;
}

// functionalitate
// TODO
Imprumut Cititor::imprumutaCarte(const Carte &c, Data d)
{
    // TODO adaugam carte in cartile sirul de carti imprumutate
    if (poateImprumuta)
    {
        listaCartiImprumutate[numarCartiImprumutate] = c;
        numarCartiImprumutate++;
        if (numarCartiImprumutate == 3)
            poateImprumuta = false;

        Imprumut i(c, *this, d);
        return i;
    }
    else
    {
        Imprumut i;
        cout << "Autorul a imprumutat deja 3 carti." << endl;
        return i;
    }
}
