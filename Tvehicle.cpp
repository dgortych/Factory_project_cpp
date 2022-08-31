#include "Tvehicle.h"

Tvehicle::Tvehicle(const string &color,const string &brand,const string &model,const string &owner ,int capacity) : owner(owner), color(color), brand(brand), model(model),
                                                                                                                    trunk_capacity(capacity){}
Tvehicle::Tvehicle() : brand("nieznany"), color("nieznany"), owner("nieznany"), model("nieznany"), trunk_capacity(0){}

void Tvehicle::print_vehicle_short() const{
    cout<<"Typ Pojazdu: "<<get_vehicle_type()<<endl;
    cout<<"Marka: "<<brand<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Kolor: "<<color<<endl;
}








