#include "address.h"

Address::Address() {
    latitude = 0.0f;
    longitude = 0.0f;
    houseNumber = 0;
    streetName = "";
}

Address::Address(float lati, float longi, int housenum, const string& street) {
    latitude = lati;
    longitude = longi;
    houseNumber = housenum;
    streetName = street;
}

Address::Address(const Address& other) {
    latitude = other.latitude;
    longitude = other.longitude;
    houseNumber = other.houseNumber;
    streetName = other.streetName;
}

Address::~Address() {
    
}

float Address::getLatitude() const {
    return latitude;
}

float Address::getLongitude() const {
    return longitude;
}

int Address::getHouseNumber() const {
    return houseNumber;
}

std::string Address::getStreetName() const {
    return streetName;
}

void Address::setLatitude(float lati) {
    latitude = lati;
}

void Address::setLongitude(float longi) {
    longitude = longi;
}

void Address::setHouseNumber(int housenum) {
    houseNumber = housenum;
}

void Address::setStreetName(const string& street) {
    streetName = street;
}

void Address::print() const {
    cout << "Latitude: " << latitude << endl;
    cout << "Longitude: " << longitude << endl;
    cout << "House Number: " << houseNumber << endl;
    cout << "Street Name: " << streetName << endl;
}

//new methods for binary search tree
string Address::key() const {
    return to_string(houseNumber) + " " + streetName;
}

//compares search keys
int Address::compare(const Address& other) const {
    string thisKey = key();
    string otherKey = other.key();

    if (thisKey < otherKey) {
        return -1;
    } else if (thisKey == otherKey) {
        return 0;
    } else {
        return 1;
    }
}