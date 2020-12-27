#ifndef IMPRUMUT_H
#define IMPRUMUT_H

#include <iostream>

#include "Carte.h"

class Cititor; // 

using namespace std;

struct Data
{
    int zi = 0;
    int luna = 0;
    int an = 0;
};

class Imprumut
{
private:
    int carteId;
    int cititorId;

    // TODO ask oare le-ar placea asta profesorilor?
    Data ridicataLa, returnataLa;
    bool esteReturnata = false;

public:
    Imprumut();
    Imprumut(int, int);
    Imprumut(int, int, Data); // include si data
    Imprumut(const Carte &, const Cititor &);
    Imprumut(const Carte &, const Cititor &, Data); // include si data
    // TODO add constructor that also includes ridicataLa si returnataLa
    // constructor copiere
    Imprumut(const Imprumut &carte);
    // getters
    int getCarteId() const;
    int getCititorId() const;
    // setters
    void setCarteId(int);
    void setCititorId(int);
    // operatori =, >>, <<
    Imprumut operator=(const Imprumut &carte);
    // TODO you forgot to I/O the dates
    friend istream &operator>>(istream &, Imprumut &);
    friend ostream &operator<<(ostream &, const Imprumut &);
    /*
    Operatorul de indexare []
    Operatorul ++ sau -- (cele două forme)
    minim 2 operatori matematici (+,-,* sau /)
    operatorul cast explicit sau implicit
    un operator condițional (<, ><=, >=)
    Operatorul pentru egalitate (==)
    */
    int operator[](int i);
    Imprumut operator++();
    Imprumut operator++(int); // postfix
    Imprumut operator--();
    Imprumut operator--(int); // postfix
    bool operator<(Imprumut);
    bool operator==(Imprumut);
    // destructor
    ~Imprumut();
    // functionalitate
    // prelungim imprumutu-ul cu o saptamana
    void prelungesteImprumut(int);
};

#endif
