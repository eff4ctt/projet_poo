#ifndef HARMONICA
#define HARMONICA

#include "Instrument.hpp"

class Harmonica : public Instrument {
public:
    Harmonica();
    void jouer_note(string note, string rythme) override;
};

#endif // HARMONICA
