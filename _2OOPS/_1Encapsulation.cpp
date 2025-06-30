//Encapsulation
#include <iostream>
#include <string>
using namespace std;
// Real life car
class SportsCar 
{
    // public:
    private:
    //characters
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre="MRF";
    public:
    SportsCar(string b, string m) 
    {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0; // neutral
    }
    
    //Getter is used for the  private variables to get its value
    int getCurrentSpeed()
    {
        return this->currentSpeed;
    }
    string getTyre()
    {
        return this->tyre;
    }

    //setter is used to set the value of the private variables
    void setTyre(string tyre)
    {
        this->tyre=tyre;
    }

    //Methods
    void startEngine() 
    {
        isEngineOn = true;
        cout << brand << " " << model << ": Engine starts with a roar!" << endl;
    }
    void shiftGear(int gear) 
    {
        if (!isEngineOn) 
        {
            cout << brand << " " << model << ": Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << ": Shifted to gear " << currentGear << endl;
    }
    void accelerate() 
    {
        if (!isEngineOn) 
        {
            cout << brand << " " << model << ": Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << ": Accelerating to " << currentSpeed << " km/h" << endl;
    }
    void brake() 
    {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << ": Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }
    void stopEngine() 
    {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << ": Engine turned off." << endl;
    }
    ~SportsCar() {}
};

// Main Method
int main() {
    SportsCar* myCar= new SportsCar("Ford", "Mustang");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    //Now i set the speed of the car
    // myCar->currentSpeed=500;
    // cout<<"Current speed of my car is set to: "<<myCar->currentSpeed<<endl;
    cout<<"Current speed of the car is: "<<myCar->getCurrentSpeed();
    delete myCar;

    return 0;
}
