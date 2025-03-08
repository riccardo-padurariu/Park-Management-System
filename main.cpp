#include <iostream>
#include <vector>

#define PARK_SLOTS_CARS 10
#define PARK_SLOTS_TRUCKS 5
#define PARK_SLOTS_MOTORBIKES 15

using namespace std;

class Vehicle{
    private:
        string NumberPlate;
        int VehicleType,EnterTime,ExitTime;
    public:
        Vehicle(string number_plate, int vehicle_type){
            NumberPlate = number_plate;
            VehicleType = vehicle_type;
        }

        void setNumberPlate(string number_plate){
            NumberPlate = number_plate;
        }

        string getNumberPlate(){
            return NumberPlate;
        }

        void setVehicleType(int vehicle_type){
            VehicleType = vehicle_type;
        }

        int getVehicleType(){
            return VehicleType;
        }
};

vector<Vehicle> Cars;
vector<Vehicle> Trucks;
vector<Vehicle> Motorbikes;

bool Check(int type){
    if(type == 1){
        if(Cars.size() >= PARK_SLOTS_CARS)
            return false;
        return true;
    } else if(type == 2){
        if(Trucks.size() >= PARK_SLOTS_TRUCKS)
            return false;
        return true;
    } else if(type == 3){
        if(Motorbikes.size() >=PARK_SLOTS_MOTORBIKES)
            return false;
        return true;
    }
}

void Add(int type,Vehicle v){
    if(type == 1)
        Cars.push_back(v);
    else if(type == 2)
        Trucks.push_back(v);
    else if(type == 3)
        Motorbikes.push_back(v);
    
    cout << "Vehicle added succesfully" << '\n';
}

void ScheduleVehicle(){
    string number_plate;
    int type;

    cout << "Enter vehicle number plate: " << '\n';
    cin >> number_plate;
    cout << "Enter vehicle type: " << '\n';
    cout << "1.Car" << '\n';
    cout << "2.Truck" << '\n';
    cout << "3.Motorbike" << '\n';
    cin >> type;

    while(type != 1 && type != 2 && type != 3)
        cout << "Enter a valid option";

    if(Check(type)){
        Vehicle v = Vehicle(number_plate,type);
        Add(type,v);
    }else{
        cout << "There aren't any slots avaible :(" << '\n';
    }
}

void DisplayVehicles(){
    if(Cars.size() == 0){
        cout << "There are no cars" << '\n';
    }else{
        cout << "Cars: " << '\n';
        for(int i=0;i<Cars.size();i++)
            cout << i+1 << " Number plate : " << Cars[i].getNumberPlate() << '\n';
    }

    if(Trucks.size() == 0){
        cout << "There are no trucks" << '\n';
    }else{
        cout << "Trucks: " << '\n';
        for(int i=0;i<Trucks.size();i++)
            cout << i+1 << " Number plate : " << Trucks[i].getNumberPlate() << '\n';
    }

    if(Motorbikes.size() == 0){
        cout << "There are no motorbikes" << '\n';
    }else{
        cout << "Motorbikes: " << '\n';
        for(int i=0;i<Motorbikes.size();i++)
            cout << i+1 << " Number plate : " << Motorbikes[i].getNumberPlate() << '\n';
    }
    
}

void CancelSchedule(){

}

int main()
{
    cout << "Park Management System" << '\n';
    while(true){
        cout << "Enter your choice: " << '\n';
        cout << "1.Schedule a vehicle" << '\n';
        cout << "2.Display vehicles on their slots" << '\n';
        cout << "3.Cancel schedule" << '\n';
        cout << "4.Exit" << '\n';
        int choice;
        cin >> choice;

        switch(choice){
            case 1:
                ScheduleVehicle();
                break;
            case 2:
                DisplayVehicles();
                break;
            case 3:
                CancelSchedule();
                break;
            case 4: 
                exit(0);
                break;
            default:
                cout << "Enter a valid choice" << '\n';
                break;
        }

    }    
    return 0;
}
