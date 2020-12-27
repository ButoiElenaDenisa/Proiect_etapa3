#if !defined(APRECIERE_H)
#define APRECIERE_H

using namespace std;

class Apreciere
{
protected:
    // double valoareApreciere; am eliminat-o pentru a nu forta ca derivatele sa aiba un camp double
public:
    virtual void editeaza() = 0;
    virtual double getValoareApreciere() const = 0;
};


#endif // APRECIERE_H
