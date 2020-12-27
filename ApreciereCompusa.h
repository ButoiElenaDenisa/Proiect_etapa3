#if !defined(APRECIERE_COMPUSA_H)
#define APRECIERE_COMPUSA_H

#include "Apreciere.h"
#include <cstring>
#include <iostream>

using namespace std;

class ApreciereCompusa : public Apreciere
{
private:
char descriere[500];
double apreciereTon, apreciereImportanta, apreciereNoutate;
public:
    ApreciereCompusa();
    ApreciereCompusa(double, double, double);
    ApreciereCompusa(char*, double, double, double);

    friend ostream& operator<<(ostream&, const ApreciereCompusa&);
    virtual void editeaza();
    virtual double getValoareApreciere() const;
};

#endif // APRECIERE_COMPUSA_H
