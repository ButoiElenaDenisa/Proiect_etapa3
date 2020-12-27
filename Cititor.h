#ifndef CITITOR_H
#define CITITOR_H

#include <iostream>

#include "Carte.h"

class Imprumut; // to stop include from looping
struct Data;

using namespace std;

class Cititor
{
private:
    static int lastId;
    int cititorId;
    char *nume;

    // TODO
    bool poateImprumuta;
    int numarCartiImprumutate;
    Carte listaCartiImprumutate[3];

public:
    Cititor();
    Cititor(const char *nume);
    Cititor(const char *nume, const int cititorId);
    // constructor copiere
    Cititor(const Cititor &a);
    // getters
    char *getNume() const;
    int getCititorId() const;
    // setters
    void setNume(char *nume);
    void setAutorId(int cititorId);
    // operatori =, >>, <<
    Cititor operator=(Cititor &a);
    friend istream &operator>>(istream &i, Cititor&);
    friend ostream &operator<<(ostream &o, const Cititor&);
    /*
    Operatorul de indexare []
    Operatorul ++ sau -- (cele două forme)
    minim 2 operatori matematici (+,-,* sau /)
    operatorul cast explicit sau implicit
    un operator condițional (<, ><=, >=)
    Operatorul pentru egalitate (==)
    */
    int operator[](int i);
    Cititor operator++();
    Cititor operator++(int); // postfix
    Cititor operator--();
    Cititor operator--(int); // postfix
    bool operator<(Cititor);
    bool operator==(Cititor);
    // destructor
    ~Cititor();
    // functionalitate
    Imprumut imprumutaCarte(const Carte&, Data);

};

#endif
