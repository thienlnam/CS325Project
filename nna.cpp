#include <iostream>
#include <fstream>
#include <stdio.h>      
#include <math.h>     
#include <vector> 

using namespace std;


class City {
    public:
    int name;
    int xcord;
    int ycord;
    bool visited;


    City(int n, int x, int y)
    {
        name = n;
        xcord = x;
        ycord = y;
        visited = false;
    }

    int getXcord(){
        return xcord;
    }

    int getYcord(){
        return ycord;
    }

    void setVisited(bool x){
        visited = x;
    }

    bool getVisited(){
        return visited;
    }

    int getName(){
        return name;
    }

};

int distanceBetweenCities(City x, City y){
    return round(sqrt(pow(x.xcord - y.xcord, 2) + pow(x.ycord - y.ycord, 2)));
}

void printCityArray(vector<City> cities){
    for (int i = 0; i < cities.size(); i++){
        cout << "NAME: " << cities[i].name << " XCORD: " << cities[i].xcord << " YCORD: " << cities[i].ycord << endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 2){
        printf("Incorrect number of arguments. Example: ./naa tsp_example_1.txt");
    }

    string fileName = argv[1];
    ifstream infile(argv[1]);

    vector<City> cities;
    int name, x, y;
    int index = 0;
    while (infile >> name >> x >> y){
        cities.push_back(City(name, x, y));
        index++;
    }
    printCityArray(cities);
    

}
