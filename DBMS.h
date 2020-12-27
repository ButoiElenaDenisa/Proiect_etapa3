#include <fstream>
#include <iostream>


#include "Carte.h"
#include "Autor.h"
#include "Cititor.h"
#include "Apreciere.h"
#include "Biblioteca.h"
#include "Imprumut.h"

using namespace std;

class DBMS {
private:
    const string entityNames[4] = {
            "Carte",
            "Autor",
            "Cititor",
            "Imprumut"
    };
    const int numEntities = 4;

    Biblioteca entities;

public:
    void showMenu() {
        cout.clear();
        for (int i = 0; i < numEntities; ++i) {
            cout << (i + 1) << ". Interogari " << entityNames[i];
        }
    }

    void showCrud(int entityIndex) {
        cout << "1. Creeaza o noua " << entityNames[entityIndex] << endl;
        cout << "2. Citeste o " << entityNames[entityIndex] << " din BD" << endl;
        cout << "3. Schimba o " << entityNames[entityIndex] << " din BD" << endl;
        cout << "4. Sterge o " << entityNames[entityIndex] << " din BD" << endl;
        cout << "5. Afiseaza toate obiectele " << entityNames[entityIndex] << endl;
        cout << "6. Sterge toate obiectele " << entityNames[entityIndex] << endl;
    }

    void crud(int entityIndex) {
        do {
            showCrud(entityIndex);
            int option;
            do {
                cin >> option;
            } while (option < 1 || option > 6);

            switch (option) {
                case 1:
                    if (entityIndex == 0) {
                        applyCreate(Carte{});
                    } else if (entityIndex == 1) {
                        applyCreate(Autor{});
                    } else if (entityIndex == 2) {
                        applyCreate(Cititor{});
                    } else if (entityIndex == 3) {
                        applyCreate(Imprumut{});
                    }
                    break;
                case 2:
                    if (entityIndex == 0) {
                        applyRead(Carte{});
                    } else if (entityIndex == 1) {
                        applyRead(Autor{});
                    } else if (entityIndex == 2) {
                        applyRead(Cititor{});
                    } else if (entityIndex == 3) {
                        applyRead(Imprumut{});
                    }
                    break;
                case 3:
                    if (entityIndex == 0) {
                        applyUpdate(Carte{});
                    } else if (entityIndex == 1) {
                        applyUpdate(Autor{});
                    } else if (entityIndex == 2) {
                        applyUpdate(Cititor{});
                    } else if (entityIndex == 3) {
                        applyUpdate(Imprumut{});
                    }
                    break;
                case 4:
                    if (entityIndex == 0) {
                        applyDelete(Carte{});
                    } else if (entityIndex == 1) {
                        applyDelete(Autor{});
                    } else if (entityIndex == 2) {
                        applyDelete(Cititor{});
                    } else if (entityIndex == 3) {
                        applyDelete(Imprumut{});
                    }
                    break;
                case 5:
                    if (entityIndex == 0) {
                        readAll(Carte{});
                    } else if (entityIndex == 1) {
                        readAll(Autor{});
                    } else if (entityIndex == 2) {
                        readAll(Cititor{});
                    } else if (entityIndex == 3) {
                        readAll(Imprumut{});
                    }
                    break;
                case 6:
                    if (entityIndex == 0) {
                        deleteAll(Carte{});
                    } else if (entityIndex == 1) {
                        deleteAll(Autor{});
                    } else if (entityIndex == 2) {
                        deleteAll(Cititor{});
                    } else if (entityIndex == 3) {
                        deleteAll(Imprumut{});
                    }
                    break;
            }
            cout << "Efectuati o alta operati pe " << entityNames[entityIndex] << "? (y/n)";
            char stopRunning;
            do {
                cin >> stopRunning;
            } while (stopRunning != 'y' && stopRunning != 'n');
            if (stopRunning == 'y') {
                break;
            }
        } while (true);
    }

    void run() {
        while (true) {
            showMenu();
            bool isRightChoice = false;
            int choice;
            while (!isRightChoice) {
                cin >> choice;
                if (choice >= 1 && choice <= numEntities) {
                    isRightChoice = true;
                }
            }
            crud(choice - 1);
            cout << "Continue with other operation? (y/n)";
            char stopRunning;
            do {
                cin >> stopRunning;
            } while (stopRunning != 'y' && stopRunning != 'n');
            if (stopRunning == 'y') {
                break;
            }
        }
    }

    /*
     * toate functii applyCreate creaza un obiect de tipul din argument, sau tipuri care il mostenesc
     */
    void applyCreate(const Carte &) {
        cout << "Ce tip de carte doriti?" << endl;
        cout << "1. Carte simpla" << endl;
        cout << "2. Carte Ebook" << endl;
        int tip;
        cin >> tip;
        if (tip == 1) {
            Carte c;
            cin >> c;
            auto cautaAutorul = entities.cartileAutorului.find(c.getAutorId());
            if (cautaAutorul != entities.cartileAutorului.end()) {
                cautaAutorul->second.push_back(c);
            } else {
                entities.cartileAutorului.insert(pair<int, list<Carte>>(c.getAutorId(), list<Carte>{c}));
            }
        } else if (tip == 2) {

        }
    }

    void applyCreate(const Autor &a) {

    }

    // va fi apelat doar la crearea unui Jurnalist sau unui EBook
    void applyCreate(const Apreciere &a) {

    }

    void applyCreate(const Cititor &c) {

    }

    void applyCreate(const Imprumut &i) {

    }


    /*
     * toate functii applyRead afiseaza un obiect de tipul din argument, care contin acelasi sau tipuri care il mostenesc
     */
    void applyRead(const Carte &c) {

    }

    void applyRead(const Autor &a) {

    }

    // va fi apelat doar la crearea unui Jurnalist sau unui EBook
    void applyRead(const Apreciere &a) {

    }

    void applyRead(const Cititor &c) {

    }

    void applyRead(const Imprumut &i) {

    }

    /*
     * toate functii applyUpdate afiseaza editeaza un obiect de tipul argumentului, sau de un tip care mosteneste clasa
     */
    void applyUpdate(const Carte &c) {

    }

    void applyUpdate(const Autor &a) {

    }

    // va fi apelat doar la crearea unui Jurnalist sau unui EBook
    void applyUpdate(const Apreciere &a) {

    }

    void applyUpdate(const Cititor &c) {

    }

    void applyUpdate(const Imprumut &i) {

    }


    /*
     * toate functii applyUpdate afiseaza editeaza un obiect de tipul argumentului, sau de un tip care mosteneste clasa
     */
    void applyDelete(const Carte &c) {

    }

    void applyDelete(const Autor &a) {

    }

    // va fi apelat doar la crearea unui Jurnalist sau unui EBook
    void applyDelete(const Apreciere &a) {

    }

    void applyDelete(const Cititor &c) {

    }

    void applyDelete(const Imprumut &i) {

    }


    /*
     * Functii deleteAll afiseaza toate entitatile de acel tip
     */
    void readAll(const Carte &c) {

    }

    void readAll(const Autor &a) {

    }

    void readAll(const Cititor &c) {

    }

    void readAll(const Imprumut &i) {

    }

    /*
     * Functii deleteAll sterg toate entitatile de acel tip
     */
    void deleteAll(const Carte &c) {

    }

    void deleteAll(const Autor &a) {

    }

    void deleteAll(const Cititor &c) {

    }

    void deleteAll(const Imprumut &i) {

    }
};