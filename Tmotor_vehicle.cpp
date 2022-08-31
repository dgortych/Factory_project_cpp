#include "Tmotor_vehicle.h"

Tmotor_vehicle::Tmotor_vehicle() : Tvehicle(),mileage(0),fuel_amount(0){}

Tmotor_vehicle::Tmotor_vehicle(const string &color,const string &brand,const string &model,const string &owner ,
int capacity ,int mileage , int fuel_amount ) : Tvehicle(color,brand,model,owner,capacity), mileage(mileage), fuel_amount(fuel_amount){}

void Tmotor_vehicle::change_mileage() {
    if(brand.length() % 3 == 0 )
        mileage /= 2;
}










