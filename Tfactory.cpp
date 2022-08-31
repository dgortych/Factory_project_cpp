#include "Tfactory.h"

Tfactory::Tfactory(const string &name,int cars_amount) : brand(name),vehicle_amount(cars_amount){
    vehicle_tab = new Tvehicle*[FACTORY_SIZE];
    for(int i = 0 ; i < FACTORY_SIZE ; ++i)
        vehicle_tab[i] = nullptr;
}
Tfactory::Tfactory() : brand("bezimienna"),vehicle_tab(nullptr),vehicle_amount(0){}

Tfactory::~Tfactory(){
    for(int i = 0; i < FACTORY_SIZE ; ++i)
        delete vehicle_tab[i];
     delete [] vehicle_tab;
}

void Tfactory::add_vehicle(Tvehicle* vehicle){
    if(vehicle_amount++ >= FACTORY_SIZE )
         throw user_action_warning("Zabraklo miejsca na pojazd. Nastepnym razem upewnij sie ze jeszcze je posiadasz");

    for(int i = 0 ; i < FACTORY_SIZE; ++i ){
        if(vehicle_tab[i] == nullptr) {
            vehicle_tab[i] = vehicle;
            break;
        }
    }
}

void Tfactory::print_vehicles() const {
    if(vehicle_amount == 0)
        throw user_action_warning("Nie zbudowano zadnego pojazdu");

    for (int i = 0; i < FACTORY_SIZE; ++i) {
        if (vehicle_tab[i] != nullptr) {
            cout << "Pojazd nr " << i + 1 << endl;
            vehicle_tab[i]->print_vehicle();
            cout << endl;
        }
    }
}
void Tfactory::print_vehicles_short() const{
    if(vehicle_amount == 0)
        throw user_action_warning("Nie zbudowano zadnego pojazdu");

    for (int i = 0; i < FACTORY_SIZE; ++i) {
        if (vehicle_tab[i] != nullptr) {
            cout << "Pojazd nr " << i + 1 << endl;
            vehicle_tab[i]->print_vehicle_short();
            cout << endl;
        }
    }
}

Tvehicle* Tfactory::sell_vehicle(int index, int length){
    vehicle_amount--;
    vehicle_tab[index]->drive(length);
    vehicle_tab[index]->set_owner("customer");
    Tvehicle* tmp = vehicle_tab[index];
    vehicle_tab[index] = nullptr;
    return tmp;
}

