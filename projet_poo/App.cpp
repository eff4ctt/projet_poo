#include "App.hpp"
#include "Piano.hpp"
#include "Xylophone.hpp"
#include "Guitare.hpp"
#include <iostream>
#include <memory>

App::App() : instrument(nullptr) {}

void App::afficher_menu() {
    cout << "=== Bienvenue dans l'application musicale ===\n";
    cout << "1. Choisir un instrument\n";
    cout << "2. Jouer une note\n";
    cout << "3. Jouer une partition\n";
    cout << "4. Quitter\n";
    cout << "Entrez votre choix : ";
}

void App::choisir_instrument() {
    cout << "=== Choisissez un instrument ===\n";
    cout << "1. Piano\n";
    cout << "2. Xylophone\n";
    cout << "3. Guitare\n";
    cout << "Entrez votre choix : ";

    int choix;
    cin >> choix;

    switch (choix) {
    case 1:
        instrument = make_unique<Piano>();
        cout << "Instrument choisi : Piano\n";
        break;
    case 2:
        instrument = make_unique<Xylophone>();
        cout << "Instrument choisi : Xylophone\n";
        break;
    case 3:
        instrument = make_unique<Guitare>();
        cout << "Instrument choisi : Guitare\n";
        break;
    default:
        cout << "Choix invalide. Aucun instrument sélectionné.\n";
        instrument.reset();
        break;
    }
}

void App::jouer_note() {
    if (!instrument) {
        cout << "Veuillez d'abord choisir un instrument.\n";
        return;
    }
    string rythme;
    cout << "Entrez le rythme (lent, normal, rapide) : ";
    cin >> rythme;
    bool arret = false;
    while (!arret) {
        string note;
        cout << "Entrez la note a jouer (ex: C4, D#, F#) : ";
        cin >> note;
        if (note == "q") {
            return;
        }
        instrument->jouer_note(note, rythme);
    }
}

void App::jouer_part() {
    if (!instrument) {
        cout << "Veuillez d'abord choisir un instrument.\n";
        return;
    }

    string cheminFichier;
    cout << "Entrez le chemin du fichier de partition (ex: partition.txt) : ";
    cin >> cheminFichier;

    string rythme;
    cout << "Entrez le rythme (lent, normal, rapide) : ";
    cin >> rythme;

    instrument->jouer_part(cheminFichier, rythme);
}

void App::run() {
    bool arret = false;

    while (!arret) {
        afficher_menu();

        int choix;
        cin >> choix;

        switch (choix) {
        case 1:
            choisir_instrument();
            break;
        case 2:
            jouer_note();
            break;
        case 3:
            jouer_part();
            break;
        case 4:
            arret = true;
            cout << "Merci d'avoir utilise l'application musicale !\n";
            break;
        default:
            cout << "Choix invalide. Veuillez reessayer.\n";
            break;
        }
    }
}
