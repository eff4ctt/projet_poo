#ifndef XYLOPHONE
#define XYLOPHONE

#include "Instrument.hpp"

class Xylophone : public Instrument {
public:
    Xylophone();
    void jouer_note(string note, string rythme) override;

};

#endif // XYLOPHONE
