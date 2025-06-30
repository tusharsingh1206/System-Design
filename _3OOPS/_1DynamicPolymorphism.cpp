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

    //Abstract method for dynamic polymorphism
    virtual void accelerate()=0;
    virtual void brake()=0;
    //Virtual destructor
    virtual ~Car() {}
};

class ManualCar : public Car {
private:
    int currentGear;
public:
    //constructor
    ManualCar(string b,string m):Car(b,m){
        currentGear=0;
    }
    //specialised method for the manual car
    void shiftGear(int gear)
    {
        currentGear=gear;
        cout<<brand<<" "<<model<<": Shifter to gear "<<currentGear<<endl;
    }
    //Now define the abstract method accelerate
    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Cannot accelerate! engine is of"<<endl;
            return ;
        }
        currentSpeed+=20;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<"KM/hr."<<endl;
    }
    //Overriding brake->Dynamic Polymorphism
    void brake(){
        currentSpeed-=20;
        if(currentSpeed<0) currentSpeed=0;
        cout<<brand<<" "<<model<<": Breaking! Speed is now "<<currentSpeed<<"KM/hr."<<endl;
    }
};

class ElectricCar : public Car {
private:
    int batterylevel;
public:
    //constructor
    ElectricCar(string b,string m):Car(b,m){
        batterylevel=100;
    }
    //specialised method for the manual car
    void chargeBattery()
    {
        batterylevel=100;
        cout<<brand<<" "<<model<<": Battery fully charged."<<endl;
    }
    //Overriding accelerate->Dynamic Polymorphism
    void accelerate(){
        if(!isEngineOn){
            cout<<brand<<" "<<model<<": Cannot accelerate! engine is of"<<endl;
            return ;
        }
        if(batterylevel<=0){
            cout<<brand<<" "<<model<<": Battery Dead,Cannot accelerate"<<endl;
            return ;
        }

        batterylevel-=10;
        currentSpeed+=15;
        cout<<brand<<" "<<model<<": Accelerating to "<<currentSpeed<<"KM/hr.Battery at "<<batterylevel<<"%"<<endl;
    }
    //Overriding brake->Dynamic Polymorphism
    void brake(){
        currentSpeed-=15;
        if(currentSpeed<0) currentSpeed=0;
        cout<<brand<<" "<<model<<": Breaking! Speed is now "<<currentSpeed<<"KM/hr.Battery at "<<batterylevel<<"%"<<endl;
    }
};
// Main Method
int main() {
    ManualCar* myManualCar = new ManualCar("Suzuki", "Wagnor");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);//specific to this car
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"-----------------------------------------"<<endl;
    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->chargeBattery();//specific to only this car
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myManualCar;

    return 0;
}
