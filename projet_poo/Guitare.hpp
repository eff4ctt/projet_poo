#ifndef GUITARE
#define GUITARE

#include "Instrument.hpp"

class Guitare : public Instrument {
public:
    Guitare();
    void jouer_note(string note, string rythme) override;
};

#endif // GUITARE
