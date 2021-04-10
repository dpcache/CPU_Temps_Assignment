#include <fstream>
#include <sstream>

using namespace std;

/**
 * Takes (x,y) coordinates and generates an output file with piecewise linear interpolation equations
 *  and a global linear least-squares approximation.
 *
 * @param x numeric vector representing x coordinates.
 * @param y numeric vector representing y coordinates.
 * @param fileName string representing the output file name.
 *
 */
void llsAnalysisDriver(vector<double> x, vector<double> y, string fileName);

/**
 * Generate a single linear least square equation.
 *
 * @param n numeric representing total pairs of (x,y) coordinates.
 * @param totalX numeric representing total sum of all x coordinates.
 * @param totalY numeric representing total sum of all y coordinates.
 * @param totalX2 numeric representing total sum of each x coordinates to the second power (x^2).
 * @param totalXY numeric representing total sum of each X * Y coordinates.
 *
 * @return a formatted linear least square equation.
 *
 */
string getLinearLeastSquares(int n, double totalX, double totalY, double totalX2, double totalXY);

/**
 * Retrieve the slope of (x,y) coordinates.
 *
 * @param n numeric representing total pairs of (x,y) coordinates.
 * @param totalX numeric representing total sum of all x coordinates.
 * @param totalY numeric representing total sum of all y coordinates.
 * @param totalX2 numeric representing total sum of each x coordinates to the second power (x^2).
 * @param totalXY numeric representing total sum of each X * Y coordinates.
 *
 * @return value of the slope
 *
 * @pre (cell1Id > 0 && cell1Id < 10) &&
 *      (cell2Id > 0 && cell2Id < 10) &&
 *      (cell3Id > 0 && cell3Id < 10)
 */
double getSlope(int n, double totalX, double totalY, double totalX2, double totalXY);

/**
 * Retrieve the y-intercept of (x,y) coordinates.
 *
 * @param n numeric representing total pairs of (x,y) coordinates.
 * @param totalY numeric representing total sum of all y coordinates.
 * @param slope numeric representing the slop of a equation.
 * @param totalX numeric representing total sum of all x coordinates.
 *
 * @return value of the y-intercept
 *
 */
double getYintercept(int n, double totalY, double slope ,double totalX);

