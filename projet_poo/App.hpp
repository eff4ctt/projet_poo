#ifndef APP
#define APP

#include <memory>
#include "Instrument.hpp"

class App {
private:
    unique_ptr<Instrument> instrument;

public:
    App();

    void afficher_menu();        
    void choisir_instrument();            
    void jouer_note();                    
    void jouer_part();               
    void run();                          
};

#endif // APP
