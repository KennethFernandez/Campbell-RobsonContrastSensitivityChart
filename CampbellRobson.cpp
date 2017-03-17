#include "CampbellRobson.h"


// The nameSpaces
using namespace cv;
using namespace std;

/***************************************
 * Constants
 * 
 ***************************************/



/***************************************
 * Attributes
 * 
 ***************************************/



/******************************************************
 * 
 * Constructor of the class Campbell-Robson with default values
 * 
 * **********************************************
 * 
 * Inputs: 
 * 		-------
 * 
 * Outputs:
 * 		-------
 * 
 * Restrinctions:
 * 		-------
 *****/
CampbellRobson::CampbellRobson(void) {
	
	
}

/******************************************************
 * 
 * Aux function to check the limits of the function
 * 
 * **********************************************
 * 
 * Inputs: 
 * 		int condition: the value to check	
 * 
 * Outputs:
 * 		bool if it is in the range
 * 
 * Restrinctions:
 * 			
 *****/
bool CampbellRobson::CheckLimits(int condition){ 
	return (condition < 0 || condition > 512);
}


/******************************************************
 * 
 * Function to generate the image
 * 
 * **********************************************
 * 
 * Inputs: 
 * 			
 * 
 * Outputs:
 * 		-------
 * 
 * Restrinctions:
 * 			
 *****/
Mat CampbellRobson::GenerateImage(int rows, int columns, bool linear, bool showSpecificRow, int specificRow){
	
	Mat newCRChart = Mat::zeros(rows,columns, CV_8UC1);
	
	if( CheckLimits(rows) && CheckLimits(columns) && CheckLimits(specificRow) ){ /// calcular con crecimiento lineal
		
		for(int y=0; y < rows; y++) {
			for(int x=0; x <columns; x++){
				newCRChart[j][i] = (127/(rows -1))*y*cos(pow(x,2)) + 128;
			}
		}
		
		
	}

	if( CheckLimits(rows) && CheckLimits(columns) && CheckLimits(specificRow) ){ // calcular con crecimiento exponencial
		
		for(int y=0; y < rows; y++) {
			for(int x=0; x <columns; x++){
				newCRChart[j][i] = exp(log(127)*y/(rows-1))*cos(exp(x)*x) + 127;
			}
		}
		
		
	}
	
	return newCRChart;
}
