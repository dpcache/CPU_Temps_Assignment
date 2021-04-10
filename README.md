# CPU_Temps_Assignment
A program that take the temperature readings from a file and generate for each core:
   A piecewise linear interpolation.
   A global linear least squares approximation.


## Installation For Unix

Make sure everything is installed to run the makefile and compile C++ codes.

Extract the zip file, and navigate to extracted folder. 

To create the executable use the following command in BASH (Command Prompt).

	make

Once the make is complete run the following command to generate the output files.

       PATH/parseTemps input_file_name

Example: ./parseTemps test.text

Result: 4 files should be generated. 
Example: 
	{basename}-core-0.{txt}
	{basename}-core-1.{txt}
	{basename}-core-2.{txt}
	{basename}-core-3.{txt}
	
Sample Output:
	The following is an example of output for a single core.
	    0 <= x <    30   ; y_0 =              61.0000 +     0.6333x; interpolation
	    
	   30 <= x <    60   ; y_1 =              98.0000 +    -0.6000x; interpolation
	   
	   60 <= x <    90   ; y_2 =              20.0000 +     0.7000x; interpolation
	   
	   90 <= x <   120   ; y_3 =             128.0000 +    -0.5000x; interpolation
	   
	   ...
	   
	   ...
	   
	   ...
	   
	    0 <= x < 35610   ; y_1187 =              77.1459 +    -0.0001x; least-squares
