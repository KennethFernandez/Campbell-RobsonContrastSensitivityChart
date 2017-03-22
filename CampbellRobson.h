#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cctype>

#include <opencv/cv.h>
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;
class CampbellRobson
{
	public:
		CampbellRobson();
		Mat GenerateMatrix(float rows, float columns, bool linear);
		void GenerateImage(Mat imageMatrix, string path);
		void PlotGraphic(Mat imageMatrix, int columns, int rowShow);
	private:
		bool CheckLimits(int condition);
};
