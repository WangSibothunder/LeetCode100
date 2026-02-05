#include <iostream>
#include <queue>
using namespace std;

class RideSharingSystem {
   private:
    queue<int> Rider;
    queue<int> Driver;
    vector<int> match;

   public:
    RideSharingSystem() {
        Rider = {};
        Driver = {};
        match = {-1, -1};
    }

    void addRider(int riderId) { Rider.push(riderId); }

    void addDriver(int driverId) { Driver.push(driverId); }

    vector<int> matchDriverWithRider() {
        if (!Rider.empty() && !Driver.empty()) {
            int rider = Rider.front();
            int driver = Driver.front();
            match[0] = driver;
            match[1] = rider;
            Rider.pop();
            Driver.pop();
        }
        return
    }

    void cancelRider(int riderId) {}
};

/**
 * Your RideSharingSystem object will be instantiated and called as
 * such: RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */