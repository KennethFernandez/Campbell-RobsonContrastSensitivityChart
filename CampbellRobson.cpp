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
	
	imwrite(path,imageMatrix);
	
}


/******************************************************
 * 
 * Constructor of the class Campbell-Robson with default values
 * 
 * **********************************************
 * 
 * Inputs: 
 * 		Mat imageMatrix: The original image
 * 		int columns: The amount of columns to show
 * 		int rowShow: The row to show
 * 
 * Outputs:
 * 		Mat: the matrix with the points to show
 * 
 * Restrinctions:
 * 		-------
 *****/
Mat CampbellRobson::PlotGraph(Mat imageMatrix, int columns, int rowShow){
	
	return PlotGraphAux(imageMatrix, columns, rowShow);
		
}


/******************************************************
 * 
 * Constructor of the class Campbell-Robson with default values
 * 
 * **********************************************
 * 
 * Inputs: 
 * 		Mat image: the values of the row 
 * 		int YRange[2]: the range
 * 		double min: the minimum value
 * 		double max: the maximum value
 * 
 * Outputs:
 * 		-------
 * 
 * Restrinctions:
 * 		-------
 *****/
Mat CampbellRobson::PlotGraphAux(Mat imageIn, int columns, int row)
{

    int cols = imageIn.cols;
    
    int rows = columns + 1;
    cv::Mat image = Mat::zeros(rows, cols, CV_8UC3);
    image.setTo(0);
    
    for (int i = 0; i < cols-1; i++)
    {
		int y1 = 256 + 128 -((int)imageIn.at<uchar>(row,i));
		int y2 = 256 + 128 -((int)imageIn.at<uchar>(row,i+1));
		
		cout << "pixel: " << i << " value: " << ((int)imageIn.at<char>(row,i)) << endl;
		
        cv::line(image, Point(i, y1), Point(i+1, y2), Scalar(255, 0, 0), 1);
    }

    return image;
}
