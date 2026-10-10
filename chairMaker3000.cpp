//COMSC-210 | Lab 20 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
const int SIZE = 3, MIN = 10000, MAX = 99999;

class Chair
{
    //Private variables
    private:
        int legs;
        double *prices;
    //Public variables
    public:
        // constructors
        Chair() {
            prices = new double[SIZE];
            legs = (rand() % 2) + 3;
            for (int i = 0; i < SIZE; i++)
                prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double)100;
        }
        Chair(int l, double p[]) {
            prices = new double[SIZE];
            legs = l;
            for (int i = 0; i < SIZE; i++)
                prices[i] = p[i];
        }

        // setters and getters
        void setLegs(int l)      { legs = l; }
        int getLegs()            { return legs; }

        void setPrices(double p1, double p2, double p3) { 
            prices[0] = p1; prices[1] = p2; prices[2] = p3; 
        }

        double getAveragePrices() {
            double sum = 0;
            for (int i = 0; i < SIZE; i++)
                sum += prices[i];
            return sum / SIZE;
        }

        void print() {
            cout << "CHAIR DATA - legs: " << legs << endl;
            cout << "Price history: " ;
            for (int i = 0; i < SIZE; i++)
                cout << prices[i] << " ";
            cout << endl << "Historical avg price: " << getAveragePrices();
            cout << endl << endl;
        }
};

//Start of main()
int main()
{
    //Set up a random seed generator just in case
    srand(time(0));
    //Set the precision to show only two decimals
    cout << fixed << setprecision(2);

    //Creating a blank chair pointer (automatically fills itself up)
    Chair *blankPtr = new Chair;
    blankPtr->print();

    //Creating a chair object with legs and prices filled up
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    double prices[3] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    collection[0].setLegs(4);
    collection[0].setPrices(441.41, 552.52, 663.63);
    collection[1].setLegs(4);
    collection[1].setPrices(484.84, 959.59, 868.68);
    collection[2].setLegs(4);
    collection[2].setPrices(626.26, 515.15, 757.57);
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}