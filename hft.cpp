#include<iostream>
#include<vector>
using namespace std;

struct PricePoint {
    double price;
    long long timestamp;
};


PricePoint findClosestPrice(vector<PricePoint>& data, double target){

    if(data.empty()){
        return PricePoint{0.0, -1};
    }

    int i = 0;
    int j = data.size() - 1;
    int upperBoundIndex = j + 1; 
    while(i<=j){
        int midIndex = i + (j-i)/2;
        if(data[midIndex].price > target){
            upperBoundIndex =midIndex;
            j = midIndex-1;
            
        }else if(data[midIndex].price <= target){
            i = midIndex+1;
        }
    }

    return upperBoundIndex==0? PricePoint{0.0, -1}:data[upperBoundIndex-1];
}

int main(){
    vector<PricePoint> data = {
        {2100.50, 1622548800000},
        {5420.75, 1622548801000},
        {8900.00, 1622548802000},
        {12450.25, 1622548803000},
        {18700.60, 1622548804000},
        {22100.10, 1622548805000},
        {28500.00, 1622548806000},
        {1250.45, 1622548807000}
    };
    double targetPrice;

    sort(data.begin(), data.end(), [](const PricePoint& a, const PricePoint& b) {
        return a.price < b.price;
    });


    cout << "========================================" << endl;
    cout << "   HFT PRICE LOOKUP ENGINE (INR)        " << endl;
    cout << "========================================" << endl;
    cout << "Enter target price (INR): ";
    cin >> targetPrice;



    PricePoint closest = findClosestPrice(data, targetPrice);
    

     if (closest.timestamp != -1) {
        cout << "\n[RESULT FOUND]" << endl;
        cout << "● Nearest Price  : ₹ " << closest.price << endl;
        cout << "● Timestamp      : " << closest.timestamp << " ns" << endl;
    } else {
        cout << "\n[NO MATCH] No price available <= ₹ " << targetPrice << endl;
    }
    cout << "========================================" << endl;

    return 0;
}