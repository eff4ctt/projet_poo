#include "Instrument.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <map>

using namespace std;

Instrument::Instrument(string n) {
    nom = n;
}

string Instrument::get_nom() {
    return nom;
}

void Instrument::jouer_note(string note, string rythme) {
    cout << "[" << nom << "] Note: " << note << ", Rythme: " << rythme << endl;
}

void Instrument::jouer_part(string part, string rythme) {
    map<string, float> ryth_l = {
    { "lent", 2.0 },
    { "normal", 1.0 },
    { "rapide", 0.5 }
    };

    ifstream fichier(part);
    cout << "Essai d'ouvrir le fichier : " << part << endl;

    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << part << endl;
        return;
    }

    string ligne;
    while (getline(fichier, ligne)) {
        istringstream stream(ligne);
        string note;
        double duree;

        if (stream >> note >> duree) {
            if (note != "0") {
                cout << "[" << nom << "] Note: " << note << ", Duree: " << duree * ryth_l[rythme] << " secondes" << endl;
            }
            else {
                cout << "[" << nom << "] Silence, Duree: " << duree * ryth_l[rythme] << " secondes" << endl;
            }

            this_thread::sleep_for(chrono::duration<double>(duree * ryth_l[rythme]));
        }
        else {
            cerr << "Erreur de format dans la ligne : " << ligne << endl;
        }
    }
}
