#ifndef TFACTORY_H
#define TFACTORY_H
#include "Vehicles.h"

constexpr int FACTORY_SIZE = 5;

class Tfactory{
protected:
    string brand;
    Tvehicle** vehicle_tab;
    int vehicle_amount;

public:
    static int factory_amount;       // liczy ilosc stworzonych fabryk
    explicit Tfactory(const string &name,int cars_amount=0);
    Tfactory();
    ~Tfactory();

    void print_vehicles() const;
    void print_vehicles_short() const;
    string get_brand() const{ return brand; };
    void add_vehicle(Tvehicle* vehicle);
    Tvehicle* sell_vehicle(int index, int length = 0);
    Tvehicle* get_vehicle(int index) const{ return vehicle_tab[index];}
    int get_vehicle_amount() const {return vehicle_amount;};
};

#endif //TFACTORY_H

