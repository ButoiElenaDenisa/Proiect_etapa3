#if !defined(JURNALIST_H)
#define JURNALIST_H

#include "IClasificabil.h"
#include "Autor.h"

class Jurnalist : public Autor, public IClasificabil
{
private:
public:
    Jurnalist(); // vector
    Jurnalist(const char *);
    Jurnalist(const char *, const int);
    virtual void adaugaApreciere(const Apreciere*);
    virtual double apreciereMedie();
};

#endif // JURNALIST_H
