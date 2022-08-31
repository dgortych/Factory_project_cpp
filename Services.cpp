#include "Services.h"


Tcar_dealer::Tcar_dealer() :  Tfactory() , mark_up(1.2){
   vehicle_tab = new Tvehicle*[FACTORY_SIZE ];
   for(int i = 0 ; i < FACTORY_SIZE ; ++i)
   vehicle_tab[i] = nullptr;
}

Tcar_dealer::~Tcar_dealer(){
    for(int i = 0; i < FACTORY_SIZE ; ++i)
        delete vehicle_tab[i];
    delete [] vehicle_tab;
}

void Tcar_dealer::fill_with_vehicles(){
    auto* car1 = new Tcar("czerwony","Mercedes","EQV",5,"Komis",450,120000,45);
    auto* car2 = new Tcar("bialy","Opel","Astra",5,"Komis",300,160000,53);
    auto* car3 = new Tcar("niebieski","Citroen","Berlingo",5,"Komis",600,45000,22);
    auto* motor_bike1 = new Tmotor_bike("czerwony","Honda","600RR","Komis",30,30000,10);
    auto* motor_bike2 = new Tmotor_bike("bialy","Ducati","Panigale","Komis",25,10000,15);

    vehicle_tab[0] = car1;
    vehicle_tab[1] = motor_bike1;
    vehicle_tab[2] = car2;
    vehicle_tab[3] = car3;
    vehicle_tab[4] = motor_bike2;
    vehicle_amount = 5;
}

float Tcar_dealer::calculate_price(int index) const{
    return static_cast<float>(vehicle_tab[index]->calculate_price() * mark_up);
}

TCustomer::TCustomer(): Tfactory(){
     vehicle_tab = new Tvehicle*[FACTORY_SIZE ];
     for(int i = 0 ; i < FACTORY_SIZE ; ++i)
         vehicle_tab[i] = nullptr;
}

TCustomer::~TCustomer() {
    for(int i = 0; i < FACTORY_SIZE ; ++i)
        delete vehicle_tab[i];
    delete [] vehicle_tab;
}







