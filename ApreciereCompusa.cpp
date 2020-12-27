
#include "ApreciereCompusa.h"
#include <iostream>
using namespace std;

ApreciereCompusa::ApreciereCompusa() : apreciereTon(-1), apreciereImportanta(-1), apreciereNoutate(-1)
{
    strcpy(descriere, "");
}

ApreciereCompusa::ApreciereCompusa(double ton, double importanta, double noutate)
    : apreciereTon(ton), apreciereImportanta(importanta), apreciereNoutate(noutate)
{
    strcpy(descriere, "");
}

ApreciereCompusa::ApreciereCompusa(char* d, double ton, double importanta, double noutate)
    : ApreciereCompusa(ton, importanta, noutate)
{
    if (d != NULL)
        strcpy(descriere, d);
}

ostream& operator<<(ostream& out, const ApreciereCompusa& a)
{
    if (a.descriere)
        out << "Descrierea: " << a.descriere << endl;
    out << "Apreciere ton: " << a.apreciereTon << endl;
    out << "Apreciere importanta: " << a.apreciereImportanta << endl;
    out << "Apreciere noutate: " << a.apreciereNoutate << endl;

    return out;
}
void ApreciereCompusa::editeaza()
{
    cout << "Aprecierea in prezent:" << endl;
    cout << *this << endl;

    cout << endl;
    cout << "Pe o scara de la 0 la 10, unde situati tonul? ";
    cin >> apreciereTon;
    cout << "Pe o scara de la 0 la 10, unde situati importanta? ";
    cin >> apreciereImportanta;
    cout << "Pe o scara de la 0 la 10, unde situati noutatea? ";
    cin >> apreciereNoutate;
}
double ApreciereCompusa::getValoareApreciere() const
{
    return (apreciereImportanta + apreciereNoutate + apreciereTon) / 3;
}

//ofstream& operator<<(ofstream&, const ApreciereCompuse& ac) {
//
//}
//ifstream& operator>>(ifstream&, ApreciereCompuse& ac) {
//
//}