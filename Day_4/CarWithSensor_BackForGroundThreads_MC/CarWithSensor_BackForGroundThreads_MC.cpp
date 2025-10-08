//
//  main.cpp
//  30_SI_packegedTask_Sensors_pro
//
//  Created by Sathya Babu on 30/05/24.
//
//
//  main.cpp
//  CarWithSensors_BackForegroundThreads_MC
//
//  Created by Sathya Babu on 24/02/24.
//


#include <iostream>
#include <thread>
#include <atomic>
#include <map>
#include <future>
#include <vector>
#include <algorithm>
#include <mutex>

class Sensor {
public:
    virtual ~Sensor() = default;
    virtual bool checkStatus() = 0;
    virtual std::string getName() const = 0;
};

//Oxygen Sensor
class OxygenSensor : public Sensor {
public:
    bool checkStatus() override {
        std::cout << "Checking oxygen sensor status..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return true;
    }

    std::string getName() const override {
        return "Oxygen";
    }
};

//Temp Sensor
class TempSensor : public Sensor {
public:
    bool checkStatus() override {
        std::cout << "Checking temperature sensor status..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        return true;
    }

    std::string getName() const override {
        return "Temperature";
    }
};

//OilPressure Sensor
class OilPressureSensor : public Sensor {
public:
    bool checkStatus() override {
        std::cout << "Checking oil pressure sensor status..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        //        return true;
        return false;
    }

    std::string getName() const override {
        return "OilPressure";
    }
};


//Dashboard (Display Sensor Status)
class Dashboard {
public:
    void update(const std::map<std::string, bool>& sensorStatus) {
        std::cout << "------ Dashboard to Display SensorStatus ------" << std::endl;
        for (const auto& [sensorName, status] : sensorStatus) {
            std::cout << sensorName << " sensor: " << (status ? "Normal" : "Faulty") << std::endl;
        }
    }
};


//Scheduler (Handles Task Scheduling)
class Scheduler {
public:
    Scheduler(std::vector<std::packaged_task<bool()>> AsyncTask)
        : tasks_(std::move(AsyncTask)) {}

    void execute() {
        for (auto& task : tasks_) {
            std::thread([&task]() {
                task();
                }).detach();
        }
    }

    void waitForCompletion() {
        for (auto& task : tasks_) {
            task.get_future().wait();
        }
    }

private:
    std::vector<std::packaged_task<bool()>> tasks_; // converts to Async task
};

//Gateway can also be a Sensor's Manager..
class SensorGateway {
public:
    SensorGateway(std::vector<std::unique_ptr<Sensor>>& sensors)
        : sensors_(std::move(sensors)) {}

    //Packaged Task for sensor Reading
    void startMonitoring() {  // stores  the sensors  in Async vector

        std::vector<std::packaged_task<bool()>> AsyncTasks;

        for (auto& sensor : sensors_) {
            std::cout << "------ startMonitoring()  ------" << std::endl;
            // template gets stored in a vector : will not be fired now
            AsyncTasks.emplace_back([sensor = sensor.get()]() { return sensor->checkStatus(); });
        }

        //Schedule BG and FG Thread
        Scheduler scheduler(std::move(AsyncTasks)); // All AsyncTask is movved to scheduler constructor then pass the ref  of &scheduler to template which executes sensors

        std::thread bgThread([&scheduler]() {
            std::cout << "------ scheduler.execute() All AsyncTask  ------" << std::endl;
            scheduler.execute();  // Executing Async task
            });

        scheduler.waitForCompletion();
        bgThread.join();

    } // startMonitoring ends here

    //Update Dashboard
    void updateDashboard(Dashboard& dashboard) {
        std::map<std::string, bool> sensorStatus;

        for (auto& sensor : sensors_) {
            sensorStatus[sensor->getName()] = sensor->checkStatus();
        }

        dashboard.update(sensorStatus);
    }

private:
    std::vector< std::unique_ptr< Sensor > > sensors_;
};  // SensorGateway


//Main
int main() {

    std::vector<std::unique_ptr<Sensor>> sensors;
    sensors.emplace_back(std::make_unique<OxygenSensor>());
    sensors.emplace_back(std::make_unique<TempSensor>());
    sensors.emplace_back(std::make_unique<OilPressureSensor>());

    //Sensors Initialisation
    SensorGateway sensorGateway(sensors);
    sensorGateway.startMonitoring();

    //Dashboard Initialisation
    Dashboard dashboard;
    sensorGateway.updateDashboard(dashboard);

    return 0;
}
/*
------ startMonitoring()  ------
------ startMonitoring()  ------
------ startMonitoring()  ------
------ scheduler.execute() All AsyncTask  ------
Checking oxygen sensor status...
Checking temperature sensor status...
Checking oil pressure sensor status...
Checking oxygen sensor status...
Checking temperature sensor status...
Checking oil pressure sensor status...
------ Dashboard to Display SensorStatus ------
OilPressure sensor: Faulty
Oxygen sensor: Normal
Temperature sensor: Normal
Program ended with exit code: 0
*/
has context menu