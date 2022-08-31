#ifndef GORTYCHDAMIAN_ETAP1_SERVICES_H
#define GORTYCHDAMIAN_ETAP1_SERVICES_H
#include "Tmotor_vehicle.h"
#include "Vehicles.h"
#include "Tfactory.h"
#include "Template.h"

class Tcar_dealer : public Tfactory{
   float mark_up;                    // marża
public:
    Tcar_dealer();
    ~Tcar_dealer();
    void fill_with_vehicles();       // dodaje 5 gotowych pojazdow do dealera by ciekawiej obslugiwac jego interface
    float calculate_price(int index) const;
    void change_mark_up(float new_mark_up){mark_up = new_mark_up;};
};

class TCustomer: public Tfactory{
public:
    TCustomer();
    ~TCustomer();
};

class Tvehicle_painter{
public:
    static void change_color(Tvehicle* vehicle,const string& color) { vehicle->change_color(color);}
    static void paint_bike(Tvehicle* bike,const string& color){ bike->change_color(color);}
};

#endif //GORTYCHDAMIAN_ETAP1_SERVICES_H
