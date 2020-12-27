#include "Imprumut.h"
#include "Cititor.h"

#include <iostream>
#include <cstring>

using namespace std;

Imprumut::Imprumut()
{
    carteId = -1;
    cititorId = -1;
}

Imprumut::Imprumut(int carteId, int cititorId)
{
    this->carteId = carteId;
    this->cititorId = cititorId;
}
void adaugaZile(Data &, int);
Imprumut::Imprumut(int carteId, int cititorId, Data data)
{
    this->carteId = carteId;
    this->cititorId = cititorId;
    ridicataLa = data;
    returnataLa = ridicataLa;
    cout << "Data returnatii: " << returnataLa.zi << '/' << returnataLa.luna << '/' << returnataLa.an << endl;

    adaugaZile(returnataLa, 14);
    cout << "Data returnatii: " << returnataLa.zi << '/' << returnataLa.luna << '/' << returnataLa.an << endl;
}
Imprumut::Imprumut(const Carte &carte, const Cititor &cititor)
{
    carteId = carte.getCarteId();
    cititorId = cititor.getCititorId();
}
Imprumut::Imprumut(const Carte &carte, const Cititor &cititor, Data data)
{
    carteId = carte.getCarteId();
    cititorId = cititor.getCititorId();
    ridicataLa = data;
    returnataLa = ridicataLa;
    adaugaZile(returnataLa, 14);
}
// constructor copiere
Imprumut::Imprumut(const Imprumut &i)
{
    carteId = i.carteId;
    cititorId = i.cititorId;
    ridicataLa = i.ridicataLa;
    returnataLa = i.returnataLa;
}
// getters
int Imprumut::getCarteId() const
{
    return carteId;
}
int Imprumut::getCititorId() const
{
    return cititorId;
}
// setters
void Imprumut::setCarteId(int carteId)
{
    this->carteId = carteId;
}
void Imprumut::setCititorId(int cititorId)
{
    this->cititorId = cititorId;
}
// operatori =, >>, <<
Imprumut Imprumut::operator=(const Imprumut &imprumut)
{
    carteId = imprumut.carteId;
    cititorId = imprumut.cititorId;
    ridicataLa = imprumut.ridicataLa;
    returnataLa = imprumut.returnataLa;

    return *this;
}
istream &operator>>(istream &in, Imprumut &i)
{
    cout << "Introduceti imprumutul\n";

    cout << "Id carte: ";
    in >> i.carteId;
    cout << "Id cititor: ";
    in >> i.carteId;

    return in;
}
ostream &operator<<(ostream &out, const Imprumut &i)
{
    out << "Imprumutul:\n";

    out << "Id carte: " << i.carteId << endl;
    out << "Id cititor: " << i.cititorId << endl;
    out << "Data ridicarii: " << i.ridicataLa.zi << '/' << i.ridicataLa.luna << '/' << i.ridicataLa.an << endl;
    out << "Data returnatii: " << i.returnataLa.zi << '/' << i.returnataLa.luna << '/' << i.returnataLa.an << endl;
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
int Imprumut::operator[](int i)
{
    return 0;
}
Imprumut Imprumut::operator++()
{
    return *this;
}
Imprumut Imprumut::operator++(int) // postfix
{
    return *this;
}
Imprumut Imprumut::operator--()
{
    return *this;
}
Imprumut Imprumut::operator--(int) // postfix
{
    return *this;
}
bool Imprumut::operator<(Imprumut i)
{
    return true;
}
bool Imprumut::operator==(Imprumut i)
{ // (*)
    return carteId == i.carteId && cititorId == i.cititorId;
}
// destructor
Imprumut::~Imprumut()
{
}

// functionalitate
int lungimeLuna(int luna, int an)
{
    if (luna == 2)
        return an % 4 == 0 ? 29 : 28;
    if (luna <= 7)
        return 30 + luna % 2;
    // avem luna != 2 si luna >= 8
    //  deci regula
    return 31 - luna % 2;
}
void adaugaZile(Data &d, int zile)
{
    d.zi += zile;
    int zileLuna = lungimeLuna(d.luna, d.an);
    while (d.zi > zileLuna)
    {
        d.zi -= zileLuna;

        if (++d.luna > 12)
        {
            d.luna %= 12;
            d.an++;
        }
        zileLuna = lungimeLuna(d.luna, d.an);
    }
}
void Imprumut::prelungesteImprumut(int zile = 7)
{
    cout << "(" << returnataLa.zi << '/' << returnataLa.luna << '/' << returnataLa.an << endl;
    adaugaZile(returnataLa, zile);
    cout << " -> " << returnataLa.zi << '/' << returnataLa.luna << '/' << returnataLa.an << ")" << endl;
}
