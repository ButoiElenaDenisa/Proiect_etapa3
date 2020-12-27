#include "EBook.h"

using namespace std;

EBook::EBook()
{
    strcpy(format, "");
}
EBook::EBook(char *format)
{
    if (format)
        strcpy(this->format, format);
}
EBook::~EBook()
{
}