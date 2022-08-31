#include "Vehicles.h"

Tcar::Tcar(const string &color,const string &brand,const string &model,int door_amount,const string &owner,int capacity,
int mileage, int fuel_amount) : Tmotor_vehicle(color,brand,model,owner,capacity,mileage,fuel_amount),door_amount(door_amount){
    this->trunk_capacity = static_cast<int>(brand.length() % 10 + 1 ) * 100;
}

Tcar::Tcar() : Tmotor_vehicle(),door_amount(0){}

void Tcar::drive(int distance){
    fuel_amount -= static_cast<int>( (5 + ( brand.length() + model.length() ) % 20 ) * distance *0.01 );
    mileage+=distance;
}

Tcar* Tcar::make_vehicle(const string &color,const string &brand,const string &model, int addition){
    Tcar* car = new Tcar(color,brand,model,addition);
    return car;
}
void Tcar::print_vehicle() const {
cout<<"Typ pojazdu: Samochod"<<endl;
cout<<"Marka: "<<brand<<endl;
cout<<"Model: "<<model<<endl;
cout<<"Wlasciciel: "<<owner<<endl;
cout<<"Kolor: "<<color<<endl;
cout<<"Liczba drzwi: "<<door_amount<<endl;
cout<<"Przebieg: "<<mileage<<endl;
cout << "Pojemnosc bagaznika: " << trunk_capacity << " litrow\n";
}

float Tcar::calculate_price() const {
    float price;
    price = static_cast<float>( brand.length() % 10 + 1 ) * 100000 / (float)sqrt(mileage) ;
    return price;
}

Tbasket::Tbasket(int capacity): capacity(capacity){
    srand(time(nullptr));
    serial_number.resize(12);
    for(int i = 0; i < serial_number.size(); ++i)
        serial_number.add(rand() % 10);
}

Tbike::Tbike() : Tvehicle(),basket(nullptr){}

Tbike::Tbike(const string &color,const string &brand,const string &model,int capacity,const string &owner ) : Tvehicle(color,brand,model,owner){
        auto *Basket = new Tbasket(capacity);
        basket = Basket;
        this->trunk_capacity = basket->get_capacity();
}

Tbike* Tbike::make_vehicle(const string &color,const string &brand,const string &model,int addition){
    auto* bike = new Tbike(color,brand,model,addition);
    return bike;
}

void Tbike::print_vehicle() const {
    cout<<"Typ pojazdu: Rower"<<endl;
    cout<<"Marka: "<<brand<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Wlasciciel: "<<owner<<endl;
    cout<<"Kolor: "<<color<<endl;
    cout << "Pojemnosc koszyka: " << trunk_capacity << " litrow\n";
}

float Tbike::calculate_price() const {
    float price;
    price = static_cast<float>( brand.length() % 10 + 1 ) * 150 + static_cast<float>(basket->get_capacity());
    return price;
}

Tmotor_bike::Tmotor_bike() : Tmotor_vehicle(){}

Tmotor_bike::Tmotor_bike(const string &color,const string &brand,const string &model,const string &owner,int capacity,int mileage,
int fuel_amount) : Tmotor_vehicle(color,brand,model,owner,capacity,mileage,fuel_amount){
    this->trunk_capacity = static_cast<int>(brand.length() % 10 + 1 ) * 5;
}

void Tmotor_bike::drive(int distance){
    fuel_amount -= static_cast<int>( (2 + ( brand.length() + model.length() ) % 8 ) * distance *0.01 );
    mileage+=distance;
}

Tmotor_bike* Tmotor_bike::make_vehicle(const string &color,const string &brand,const string &model,int addition){
    auto* motor_bike = new Tmotor_bike(color,brand,model);
    return motor_bike;
}

void Tmotor_bike::print_vehicle() const {
    cout<<"Typ pojazdu: Motocykl"<<endl;
    cout<<"Marka: "<<brand<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Wlasciciel: "<<owner<<endl;
    cout<<"Kolor: "<<color<<endl;
    cout<<"Przebieg: "<<mileage<<endl;
    cout << "Pojemnosc bagaznika: " << trunk_capacity << " litrow\n";
}

float Tmotor_bike::calculate_price() const {
    float price;
    price = static_cast<float>( brand.length() % 10 + 1 ) * 80000 / static_cast<float>(sqrt(mileage)) ;
    return price;
}


