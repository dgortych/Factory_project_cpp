#ifndef GORTYCHDAMIAN_ETAP1_VEHICLES_H
#define GORTYCHDAMIAN_ETAP1_VEHICLES_H
#include "Tmotor_vehicle.h"
#include "Tvehicle.h"
#include "Template.h"
#include <cmath>
#include <ctime>


class Tcar: public Tmotor_vehicle{
    int door_amount;
public:
    explicit Tcar(const string &color,const string &brand,const string &model,int door_amount = 5,const string &owner = "factory",
         int capacity = 500,int mileage = 0, int fuel_amount = 200);
    Tcar();
    ~Tcar() override = default;

    string get_vehicle_type() const override{ return "Samochod";}
    void drive(int distance) override;
    Tcar* make_vehicle(const string &color,const string &brand,const string &model, int addition) override;
    void print_vehicle() const override;
    float calculate_price() const override;
};

class Tbasket{
    int capacity;
    Conteiner<int> serial_number;
public:
    explicit Tbasket(int capacity);
    void set_capacity(int cap){capacity = cap;}
    int get_capacity() const { return capacity;}
    int is_basket() const {return capacity ;}
    void get_serial_number() { cout<<serial_number<<endl;}
    ~Tbasket(){serial_number.remove();}
};

class Tbike: public Tvehicle{
    Tbasket* basket;
public:
    Tbike();
    explicit Tbike(const string &color,const string &brand,const string &model,int capacity = 0,const string &owner = "factory");
    ~Tbike() override { delete basket;}
    Tbike* make_vehicle(const string &color,const string &brand,const string &model,int addition) override;
    string get_vehicle_type() const override{ return "Rower";}
    void print_vehicle() const override;
    float calculate_price() const override;
    void drive(int distance) override{};
    void change_mileage() final {};
    Tbasket* get_basket() const{ return basket;}
    void set_capacity(int cap){trunk_capacity = cap;}

};

class Tmotor_bike: public Tmotor_vehicle{
public:
    Tmotor_bike();
    explicit  Tmotor_bike(const string &color,const string &brand,const string &model,const string &owner = "factory",int capacity = 200,
                                                                                                  int mileage = 0,int fuel_amount = 200);
    ~Tmotor_bike() override = default;
    string get_vehicle_type() const override { return "Motocykl";}
    void drive(int distance) override;
    Tmotor_bike* make_vehicle(const string &color,const string &brand,const string &model, int addition ) override;
    void print_vehicle() const override;
    float calculate_price() const override;

};

#endif //GORTYCHDAMIAN_ETAP1_VEHICLES_H
