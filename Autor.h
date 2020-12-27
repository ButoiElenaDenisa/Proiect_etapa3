#ifndef AUTOR_H
#define AUTOR_H

#include <iostream>
#include "Carte.h"

using namespace std;

class Autor
{
private:
    static int lastId;
    int autorId;
    char *nume;
    Carte carti[100];
    int nrCarti;
public:
    Autor();
    Autor(const char *);
    Autor(const char *, const int);
    // constructor copiere
    Autor(const Autor &a);
    // getters
    char *getNume();
    int getAutorId();
    int getNrCarti();
    Carte getCarte(int) const;
    // setters
    void setNume(char *nume);
    void setAutorId(int autorId);
    // operatori =, >>, <<
    Autor operator=(const Autor &a);
    friend istream &operator>>(istream &, Autor &);
    friend ostream &operator<<(ostream &, const Autor &);
    /*
    Operatorul de indexare []
    Operatorul ++ sau -- (cele două forme)
    minim 2 operatori matematici (+,-,* sau /)
    operatorul cast explicit sau implicit
    un operator condițional (<, ><=, >=)
    Operatorul pentru egalitate (==)
    */
    // TODO delete it
    /*
    
     int *a; // ce face? retine o adressa pt a variabila de tip int
     
     a + 10, a - 3; // Scaderea si adunarea cu intregi, inseamna sarit-ul pe urmatoarele/precedentele int-uri din memorie 
     
     a - b; // peste cate casute trebuie sarit in memorie pentru a ajunge de la a la b
     
     *a == *(a + 0); // daca a este vector, ar fi <=> cu a[0]
     *(a + 2) == a[2]

    */
    int operator[](int i);
    Autor operator++();
    Autor operator++(int); // postfix
    Autor operator--();
    Autor operator--(int); // postfix
    bool operator<(Autor);
    bool operator==(Autor);
    // destructor
    ~Autor();
    // functionalitate
    void adaugaCarte(Carte&);
    Carte eliminaCarte(int);
};

#endif