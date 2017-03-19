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
	
	float Al = (127/(columns -1))/2;
	float Bl = 127/(rows -1);
	
	float Ae = log(columns-1)/(2*(columns-1));
	float Be = log(128)/(rows-1);
	
	// Calculate with linear increase
	if(!CheckLimits(rows) && !CheckLimits(columns)){
		if(linear){
			for(float y=0; y < rows; y++) {
				for(float x=0; x <columns; x++){
					imageMatrix.at<uchar>(y, x, 0) = (int)(Bl*y*cos((Al*pow(x,2)*PI)/180)) + 128;
				}
			}
		}else{
			for(float y=0; y < rows; y++) {
				for(float x=0; x <columns; x++){
					imageMatrix.at<uchar>(y, x, 0) = (int)(exp(Be*y)*cos(exp(Ae*x)*x*PI/180)) + 127;
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
