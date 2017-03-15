#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
		Mat GenerateImage(int rows, int columns, bool linear, bool showSpecificRow = false, int specificRow = 0);
	private:
		bool CheckLimits(int condition);
};
