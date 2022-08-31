#ifndef GORTYCHDAMIAN_ETAP1_TVEHICLE_H
#define GORTYCHDAMIAN_ETAP1_TVEHICLE_H
#include <string>
#include <iostream>

using namespace std;

class Tvehicle{
protected:
    string owner;
    string color;
    string brand;
    string model;
    int trunk_capacity;
public:
    explicit Tvehicle(const string &color,const string &brand,const string &model,const string &owner = "factory",int capacity = 0);
    Tvehicle();
    virtual ~Tvehicle() = default;  //destruktor nic nie wykonuje bo nie ma takiej potrzeby ale w przyszlosc latwiej bedzie dodac do niego cialo


    void set_owner(const string &newOwner){ owner = newOwner;};
    void change_color(const string& new_color){color = new_color;};
    virtual string get_vehicle_type() const = 0;
    virtual Tvehicle* make_vehicle(const string &color,const string &brand,const string &model,int addition = 0) = 0;
    // addition to specjalny element dodawany do danego rodzaju pojazdu np liczba drzwi dla samochodu lub koszyk dla roweru
    virtual void print_vehicle() const = 0;
    void print_vehicle_short() const;
    virtual void drive(int distance) = 0;          // zwieksza przebieg i zmienia ilosc paliwa w zaleznosci od pojazdu
    virtual void change_mileage() = 0;
    virtual float calculate_price() const = 0;     // oblicza cena na podstawie wzoru bioracego marke i przebieg
};


#endif //GORTYCHDAMIAN_ETAP1_TVEHICLE_H
