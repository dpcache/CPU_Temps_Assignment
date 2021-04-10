#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//#include <list>
#include <sstream>
//#include <memory>
//#include <iterator>
//#include <algorithm>
//#include <utility>

#include "parseTemps.h"
#include "llsAnalysis.h"


using namespace std;

int main(int argc, char** argv)
{
    vector<double> sec;
    vector<double> core0;
    vector<double> core1;
    vector<double> core2;
    vector<double> core3;

    // Input validation
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " input_file_name" << "\n";
        return 1;
    }

    ifstream input_temps(argv[1]);
    if (!input_temps) {
        cout << "ERROR: " << argv[1] << " could not be opened" << "\n";
        return 2;
    }
    // End Input Validation

    // vector
    auto readings = parse_raw_temps<std::vector<CoreTempReading>>(input_temps);

    for (const CoreTempReading& theReading : readings) {

        sec.push_back(theReading.first);
        const vector<double>& coreTemps = theReading.second;

        //Store all the data from the input file for each core into the vectors.
        core0.push_back(coreTemps[0]);
        core1.push_back(coreTemps[1]);
        core2.push_back(coreTemps[2]);
        core3.push_back(coreTemps[3]);
    }

    //Generate the filename for the output file.
    string baseName = argv[1];
    baseName =  baseName.substr(0, baseName.find("."));

    //Generate file for each core with piecewise linear interpolation equations and
    // a global linear least squares approximation.
    llsAnalysisDriver(sec, core0, baseName + "-core-0");
    llsAnalysisDriver(sec, core1, baseName + "-core-1");
    llsAnalysisDriver(sec, core2, baseName + "-core-2");
    llsAnalysisDriver(sec, core3, baseName + "-core-3");

    return 0;
}

