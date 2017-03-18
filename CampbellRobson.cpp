#include "CampbellRobson.h"


// The nameSpaces
using namespace cv;
using namespace std;

/***************************************
 * Constants
 * 
 ***************************************/
#define PI 3.14159265


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
 * 		bool: if it is in the range (true = is out of bound)
 * 
 * Restrinctions:
 * 			
 *****/
bool CampbellRobson::CheckLimits(int condition){ 
	return (condition < 0 || condition > 3000);
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
Mat CampbellRobson::GenerateMatrix(float rows, float columns, bool linear){
	
	Mat imageMatrix = Mat::zeros(rows,columns, CV_8UC1);
	
	// Calculate with linear increase
	if(!CheckLimits(rows) && !CheckLimits(columns)){ 
		if(linear){
			for(float y=0; y < rows; y++) {
				for(float x=0; x <columns; x++){
					imageMatrix.at<uchar>(y, x, 0) = (int)((127/(rows -1))*y*cos(pow(x,2)* PI / 180.0)) + 128;
				}
			}
		}else{
			for(float y=0; y < rows; y++) {
				for(float x=0; x <columns; x++){
					imageMatrix.at<uchar>(y, x, 0) = (int)(exp(log(127)*y/(rows-1))*cos(exp(x)*x)) + 127;
				}
			}
		}
	}
	
	return imageMatrix;
}

void CampbellRobson::GenerateImage(Mat imageMatrix, string path){
	
	
	
}

void CampbellRobson::PlotGraphic(Mat imageMatrix){
	
	
	
}
