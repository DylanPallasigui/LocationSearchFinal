#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

using namespace std;

class Address {
private:
    float latitude;
    float longitude;
    int houseNumber;
    string streetName;

public:
    Address();
    Address(float lati, float longi, int houseNum, const string& street);
    Address(const Address& other);
    ~Address();

    float getLatitude() const;
    float getLongitude() const;
    int getHouseNumber() const;
    string getStreetName() const;

    void setLatitude(float lat);
    void setLongitude(float lon);
    void setHouseNumber(int house);
    void setStreetName(const string& street);

    void print() const;

    //New methods for BST
    string key() const;
    int compare(const Address& other) const;
};

#endif