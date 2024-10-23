#include<bits/stdc++.h>
using namespace std;

class Car {
public:
    virtual void start() = 0;

    virtual void stop() = 0;
};

class Sedan : public Car {
public:
    void start() override {
        cout << "car is starting";
    }
    void stop() override {
        cout << "car is stopping";
    }
};

void pressfuel(Car& car) {
    car.start();
    cout << "car is moving";
    car.stop();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("../inputf.in", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("../outputf.out", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
    Sedan s;
    pressfuel(s);
}