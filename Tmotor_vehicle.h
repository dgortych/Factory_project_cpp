#ifndef GORTYCHDAMIAN_ETAP1_TMOTOR_VEHICLE_H
#define GORTYCHDAMIAN_ETAP1_TMOTOR_VEHICLE_H
#include "Tvehicle.h"

class Tmotor_vehicle: public Tvehicle{
protected:
  int mileage;
  int fuel_amount;
public:
    Tmotor_vehicle();
    Tmotor_vehicle(const string &color,const string &brand,const string &model,const string &owner = "factory",
                                                         int capacity = 500,int mileage = 0, int fuel_amount = 200);
    ~Tmotor_vehicle() override = default;
    void change_mileage() final;
};

#endif //GORTYCHDAMIAN_ETAP1_TMOTOR_VEHICLE_H
