#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <cstring>

using namespace std;

class Carte
{
private:
    static int lastId;
    int carteId;
    char *titlu;
    char *editura;
    int autorId;

    bool esteImprumutata = false; // TODO
public:
    Carte();
    Carte(const char *titlu, const char *editura);
    Carte(const char *titlu, const char *editura, const int autorId);
    // constructor copiere
    Carte(const Carte &carte);
    // getters
    char *getTitlu() const;
    char *getEditura() const;
    int getAutorId() const;
    int getCarteId() const;
    bool getEsteImprumutata() const;
    // operatori =, >>, <<
    Carte operator=(const Carte &carte);
    friend istream &operator>>(istream &i, Carte &);
    friend ostream &operator<<(ostream &o, const Carte &);
    /*
    Operatorul de indexare []
    Operatorul ++ sau -- (cele două forme)
    minim 2 operatori matematici (+,-,* sau /)
    operatorul cast explicit sau implicit
    un operator condițional (<, ><=, >=)
    Operatorul pentru egalitate (==)
    */
    int operator[](int i);
    Carte operator++();
    Carte operator++(int); // postfix
    Carte operator--();
    Carte operator--(int); // postfix
    bool operator<(Carte);
    bool operator==(Carte);
    // destructor
    virtual ~Carte();
    // functionalitate
    bool aFostImprumutata();
};

#endif
