#include <iostream>
using namespace std;

class InflationCalculator{
    private:
    int p;
    double r;
    int y;

    double exponential(double r, int y) {
        if (y == 0) return 1;

        double ans = exponential(r, y / 2);
        ans *= ans;
        if (y % 2 != 0) {
            ans *= r;
        }
        return ans;
    }

    public:
    InflationCalculator(int p, double r, int y){
        this->p = p;
        this->r = r;
        this->y = y;
    }

    int calculateInflation(){
        double factor = exponential((1+r), y);
        double inflatedPrice = p * factor;
        return inflatedPrice;
    }
};

int main() {
    InflationCalculator a(5000, 0.5, 2);
    cout << a.calculateInflation();
    
    return 0;
}
