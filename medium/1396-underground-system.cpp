#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

class UndergroundSystem {
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        pending[id] = pair<string, int>(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        pair<string, int> passanger = pending[id];
        pair<int, int> *v = &(times[passanger.first + stationName]);
        v->first += (t - passanger.second);
        v->second++;
        pending.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        pair<int, int> *v = &(times[startStation + endStation]);
        if (v->second > 0) {
            return double(v->first) / v->second;
        }
        else { return 0.0; }
    }
private:
    unordered_map<string, pair<int, int>> times;
    unordered_map<int, pair<string, int>> pending;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main(int argc, char *argv[])
{

    UndergroundSystem* obj = new UndergroundSystem();
    obj->checkIn(5,"Liverpool",233);
    obj->checkOut(5,"Birmingham",250);
    double d = obj->getAverageTime("Liverpool","Birmingham");
    printf("%f\n", d);
    return 0;
}
