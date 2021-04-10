#include <iomanip>
#include <vector>

#include "llsAnalysis.h"

using namespace std;

void llsAnalysisDriver(vector<double> x, vector<double> y, string fileName){

    //Generate the file with name according to this format {basename}-core-0.{txt}.
    ofstream oFile(fileName+".txt");

    int time0 = 0;
    int coreTemp0 = 0;
    int coreSize = y.size()-1;
    double totalX = x.at(coreSize);
    double totalY = y.at(coreSize);
    double totalX2 = x.at(coreSize) * x.at(coreSize);
    double totalXY = x.at(coreSize) * y.at(coreSize);

    //Loop through (x,y) coordinate pairs to generate piecewise linear interpolation equations
    // and a global linear least squares approximation.
    for(int counter = 0; counter < coreSize ; counter ++){

        //Using 2 pairs of (x,y) coordinates to generate a single piecewise linear interpolation equation.
        double sumX0X1 = x.at(time0) + x.at(time0+1);
        double sumY0Y1 = y.at(coreTemp0) + y.at(coreTemp0+1);
        double X2 = x.at(time0) * x.at(time0) + x.at(time0+1) * x.at(time0+1);
        double XY = x.at(time0) * y.at(coreTemp0) + x.at(time0+1) *  y.at(coreTemp0+1);

        //Output a single piecewise linear interpolation equation to the file.
        oFile << setw(5) << x.at(time0)
            << " <= x < "
            << setw(5) << x.at(time0+1)
            << setw(7) << "; y_" << counter << " = "
            <<  getLinearLeastSquares(2, sumX0X1, sumY0Y1, X2, XY)
            <<"; interpolation" << endl;

        //Store sum of all X, Y, X^2, X * Y coordinates to generate the slope to variables.
        totalX += x.at(time0);
        totalY += y.at(coreTemp0);
        totalX2 += x.at(time0) * x.at(time0);
        totalXY +=  x.at(time0) * y.at(coreTemp0);

        time0++;
        coreTemp0++;
    }

    //Output a single global linear least squares approximation equation to the file.
    oFile << setw(5) <<  x.at(0)  << " <= x < "
        << setw(5) << x.at(coreSize)
        << setw(7) << "; y_" << coreSize
        << " = " << getLinearLeastSquares(y.size(), totalX, totalY, totalX2, totalXY)
        <<"; least-squares" << endl;

    oFile.close();
}

//--------------------------------------------------------------------------------------------------
string getLinearLeastSquares(int n, double totalX, double totalY, double totalX2, double totalXY){
    stringstream result;

    //get the slope and y-intercept.
    double slope = getSlope(n, totalX, totalY, totalX2, totalXY);
    double yIntercept = getYintercept(n, totalY, slope, totalX);

    //Combine the slope and y-intercept into a string.
    result << setw(20) << fixed << setprecision(4) << yIntercept << " + " << setw(10) << setprecision(4) << slope << "x" ;

    return result.str();

}

//--------------------------------------------------------------------------------------------------
double getSlope(int n, double totalX, double totalY, double totalX2, double totalXY){
    //Using total pairs of (x,y) coordinates and sum of all X, Y, X^2, X * Y coordinates to generate the slope.
    return ((n * totalXY) -  (totalX * totalY)) / ((n * totalX2) - (totalX * totalX ));

}

//--------------------------------------------------------------------------------------------------
double getYintercept(int n, double totalY, double slope ,double totalX){
    //Using total pairs of (x,y) coordinates and sum of all X, Y, and a slope to generate the y-intercept.
    return (totalY - (slope * totalX) ) / n;
}


