#if !defined(APRECIERE_SCURTA_H)
#define APRECIERE_SCURTA_H

#include "Apreciere.h"
#include <iostream>

using namespace std;

class ApreciereScurta : public Apreciere
{
private:
    char mesaj[251];
    double valoareApreciere;
public:
    ApreciereScurta();
    ApreciereScurta(const char*, const double);
    ApreciereScurta(const ApreciereScurta& a);
    // metodele abstracte din baza:
    friend ostream& operator<<(ostream&, const ApreciereScurta&);
    virtual void editeaza();
    virtual double getValoareApreciere() const;
};

#endif // APRECIERE_SCURTA_H
