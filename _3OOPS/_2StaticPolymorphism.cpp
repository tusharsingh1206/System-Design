//Method overloading 
//Same mothod but with the different parameters
//Showcase of the same method in different-2 way like in animal->run
//PolyMorphism->many+form
//Abstrction 
#include <iostream>
#include <string>
using namespace std;
// Real life car
class Car {
protected:
    string model;
    string brand;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
public:
    Car(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    //Common methods for all the cars
    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << ": Engine starts." << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << ": Engine turned off." << endl;
    }

    //Overloading accelerate->Static polymorphism
    //Without parametr
    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Cannot accelerate! engine is of"<<endl;
            return ;
        }
        currentSpeed+=20;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<" KM/hr."<<endl;
    }
    //with parameter
    void accelerate(int speed){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Cannot accelerate! engine is of"<<endl;
            return ;
        }
        currentSpeed+=speed;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<" KM/hr."<<endl;
    }

    void brake(){
        currentSpeed-=20;
        if(currentSpeed<0) currentSpeed=0;
        cout<<brand<<" "<<model<<": Breaking! Speed is now "<<currentSpeed<<" KM/hr."<<endl;
    }
    
    void shiftGear(int gear){
        currentGear=gear;
        cout<<brand<<" "<<model<<": Shifted to geat "<<currentGear<<endl;
    }
};

// Main Method
int main() {
    Car* myManualCar = new Car("Suzuki", "Wagnor");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->shiftGear(1);
    myManualCar->accelerate(40);
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;
    return 0;
}
