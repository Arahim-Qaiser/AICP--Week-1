
#include <iostream>
#include <string>

using namespace std;

const int numPupils = 30;

class WeightRecord {
public:
    string name;
    double weight;
    double weightDifference;
    WeightRecord() {
        name = "";
        weight = 0;
        weightDifference = 0;
    }
    WeightRecord(string n, double w)  {
        name = n;
        weight = w;
        weightDifference = 0;
    }
};

double validateWeight() {
    double weight;
    while (true) {
        cout << "Enter weight: ";
        cin >> weight;

        if (cin.fail() || weight < 30 || weight > 150) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid weight. Please enter a valid number between 30 and 150." << endl;
        }
        else {
            cin.ignore(1000, '\n');
            return weight;
        }
    }
}

int main() {
    WeightRecord pupils[numPupils];

    // Task 1
    cout << "Enter weights and names for 30 pupils." << endl;
    for (int i = 0; i < numPupils; ++i) {
        string name;
        double weight;

        cout << "Enter name for pupil " << i + 1 << ": ";
        getline(cin, name);

        weight = validateWeight();

        pupils[i] = WeightRecord(name, weight);
    }

    // Task 2
    cout << "\nCalculate and store the difference in weight." << endl;
    for (int i = 0; i < numPupils; ++i) {
        double lastDayWeight;
        cout << "Enter weight for pupil " << i + 1 << " on the last day of term: ";
        lastDayWeight = validateWeight();

        pupils[i].weightDifference = lastDayWeight - pupils[i].weight;
    }

    // Task 3
    cout << "\nTask 3: Output pupils with weight difference > 2.5 kg." << endl;
    for (int i = 0; i < numPupils; ++i) {
        if ((pupils[i].weightDifference) > 2.5) {
            cout << pupils[i].name << " has a weight difference of " << pupils[i].weightDifference
                << " kilograms. This is a " << (pupils[i].weightDifference > 0 ? "rise" : "fall") << "."
                << endl;
        }
    }

    return 0;
}
