//
// Created by stefan on 12/20/20.
//

#ifndef FINAL_BIBLIOTECA_H
#define FINAL_BIBLIOTECA_H

#include <vector>
#include <set>
#include <map>
#include <list>

#include "Carte.h"
#include "Autor.h"
#include "Apreciere.h"
#include "IClasificabil.h"
#include "Cititor.h"
#include "ApreciereScurta.h"
#include "ApreciereCompusa.h"

class Biblioteca {
private:
    string filename;
    set<Autor> autori;
    map<int, list<Carte>> cartileAutorului; // de la autorId la lista de carti

    vector<Cititor *> cititori;

    // am adaugat aprecieri bibliotecii:
    list<Apreciere *> aprecieri; // am rezolval limitarea IClasificabil, in care avem maxim 100 Aprecieri, prin a folosi o lista
public:
    friend class DBMS;
    // functii cititori:
    Cititor *getCititor(int index) {
        return cititori[index];
    }

    // am adaugat aprecieri bibliotecii:
    bool adaugaApreciere(const Apreciere *a) {
        const ApreciereScurta *castScurta;
        const ApreciereCompusa *castCompusa;
        if ((castScurta = dynamic_cast<const ApreciereScurta *>(a))) {
            ApreciereScurta *alocata = new ApreciereScurta(*castScurta);
            aprecieri.push_back(alocata);
        } else if ((castCompusa = dynamic_cast<const ApreciereCompusa *>(a))) {
            ApreciereCompusa *alocata = new ApreciereCompusa(*castCompusa);
            aprecieri.push_back(alocata);
        }
        return false;
    }

    Apreciere *getApreciere(int index) {
        int count = 0;
        for (auto a : aprecieri) {
            if (count == index) {
                return a;
            }
            count++;
        }
        return NULL;
    }


    double apreciereMedie() {
        double suma = 0;
        for (auto a : aprecieri) {
            suma += a->getValoareApreciere();
        }
        return suma / aprecieri.size();
    }

};


#endif //FINAL_BIBLIOTECA_H