#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>      
#include <math.h>     
#include <vector> 
#include <limits.h>

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
        cout <<"INDEX: " << i << " NAME: " << cities[i].name << " XCORD: " << cities[i].xcord << " YCORD: " << cities[i].ycord << endl;
    }
}

int main(int argc, char** argv) {
    if (argc != 2){
        printf("Incorrect number of arguments. Example: ./naa tsp_example_1.txt");
    }

    string fileName = argv[1];
    ifstream infile(argv[1]);

    vector<City> cities;
    vector<int> visitedCities;
    int totalDistance = 0;
    int name, x, y;
    int totalVisited = 0;
    int index = 0;
    while (infile >> name >> x >> y){
        cities.push_back(City(name, x, y));
        index++;
    }
    /* initialize random seed: */
    srand (time(NULL));

    // Visit a random city at first
    int randomCity = rand() % cities.size();
    int currentCity = randomCity;

    // Enter the city into the array and set it as visited
    visitedCities.push_back(cities[randomCity].name);
    cities[randomCity].setVisited(true);
    totalVisited++;

    int totalCities = cities.size();

    int lowestDistance, lowestCity;
    int distanceDifference = 0;

    // Make sure we visit each city
    while (totalVisited < totalCities)
    {
        // Reset the lowest distance count
        lowestDistance = INT_MAX;
        for (int i = 0; i < totalCities; i++){
            // We don't want the city to be visited already or be the current city
            if (cities[i].visited == false && i != currentCity)
            {
                distanceDifference = distanceBetweenCities(cities[i], cities[currentCity]);
                // If the distance is lower than what it is currently, change the lowest
                if (distanceDifference < lowestDistance){
                    lowestDistance = distanceDifference;
                    lowestCity = i;
                }
            }
        }
        
        // Increment the distances
        totalDistance += lowestDistance;
        cities[lowestCity].setVisited(true);
        // Add to the visited array
        currentCity = lowestCity;
        visitedCities.push_back(currentCity);
        totalVisited++;
    }
    

    string resultsFile = fileName + ".tour";
    ofstream outputFile(resultsFile.c_str());
    
    // Add distance back to beginning city
    totalDistance += distanceBetweenCities(cities[randomCity], cities[currentCity]);
    
    // Write out to our file
    outputFile << totalDistance << "\n";
    for (int i = 0; i < visitedCities.size(); i++){
        outputFile << visitedCities[i] << "\n";
    }
   
    outputFile.close();
    return 0;

}
