#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    double weight;
    double value;
    
    Item(double weight, double value) : weight(weight), value(value) {}
};

bool compare(const Item &a, const Item &b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(vector<double>& weights,vector<double>& values, double capacity) {

    double result = 0.0;
    vector<Item> items;
    for (size_t i = 0; i < weights.size(); i++) {
        items.push_back(weights[i], values[i]);
    }
    sort(items.begin(), items.end(), compare);

    for (const auto& item : items) {
        if (capacity <= 0) break;
        
        if (item.weight <= capacity) {
            result += item.value;
            capacity -= item.weight;
        } 
       
        else {
            result += capacity * (item.value / item.weight);
            capacity = 0;
        }
    }

    return result;
}

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<double> weights(numItems);
    cout << "Enter the weights (space-separated): ";
    for (int i = 0; i < numItems; i++) {
        cin >> weights[i];
    }

    vector<double> values(numItems);
    cout << "Enter the values (space-separated): ";
    for (int i = 0; i < numItems; i++) {
        cin >> values[i];
    }

    double capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(weights, values, capacity);
    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
