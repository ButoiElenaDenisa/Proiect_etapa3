#if !defined(EBOOK_H)
#define EBOOK_H

#include "Carte.h"
#include "IClasificabil.h"

class EBook : public Carte, public IClasificabil
{
private:
    char format[10];
public:
    EBook();
    EBook(char*);
    virtual ~EBook();
};

#endif // EBOOK_H
