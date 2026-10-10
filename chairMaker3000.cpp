//COMSC-210 | Lab 20 | Eric-Giulio Hedes
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

//Global constants that will be used for the prize size & the random price values
const int SIZE = 3, MIN = 10000, MAX = 99999;

class Chair
{
    //Private variables
    private:
        int legs;
        double *prices;
    //Public variables
    public:
        //Empty constructor
        Chair() {
            //Create a dynamic price array
            prices = new double[SIZE];
            //Set the number of legs to a random value (either 3 or 4 legs)
            legs = (rand() % 2) + 3;
            //Use a ranged loop to set random price values (between 10000 and 99999)
            for (int i = 0; i < SIZE; i++)
                prices[i] = (rand() % (MAX - MIN + 1) + MIN) / (double)100;
        }
        //Full constructor
        Chair(int l, double p[]) {
            //Create a dynamic price array
            prices = new double[SIZE];
            //Set the amount of legs to l
            legs = l;
            //Use a ranged loop to set the price values to the elements of the p array
            for (int i = 0; i < SIZE; i++)
                prices[i] = p[i];
        }

        //Define setLegs() as a setter
        void setLegs(int l) { legs = l; }
        //Define getLegs() as a getter
        int getLegs() { return legs; }

        //Define setPrices, which sets all 3 price values to their corresponding parameter
        void setPrices(double p1, double p2, double p3) { 
            prices[0] = p1; prices[1] = p2; prices[2] = p3; 
        }

        //Define getAveragePrices()
        double getAveragePrices() {
            //Define sum, which will be used for returning
            double sum = 0;
            //Use a loop to add all of the price values
            for (int i = 0; i < SIZE; i++)
                sum += prices[i];
            //Then return the sum divided by SIZE
            return sum / SIZE;
        }

        //Define print()
        void print() {
            //Print out the legs
            cout << "CHAIR DATA - legs: " << legs << endl;
            //Print out the price history
            cout << "Price history: " ;
            //Use a loop to print out all of the prices
            for (int i = 0; i < SIZE; i++)
                cout << prices[i] << " ";
            //Then print out the average
            cout << endl << "Historical avg price: " << getAveragePrices();
            //Leave some space for the next entry
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

    //Create a blank chair pointer (automatically fills itself up)
    Chair *blankPtr = new Chair;
    blankPtr->print();

    //Create a chair object with legs and prices filled up
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //Create a dynamic chair object with the full constructor
    double prices[3] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, prices);
    livingChair->print();
    //Then delete the chair pointer for memory safety
    delete livingChair;
    livingChair = nullptr;

    //Create a dynamic array full of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++)
        collection[i].setLegs(4);
    //Then print all of them out at once
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}