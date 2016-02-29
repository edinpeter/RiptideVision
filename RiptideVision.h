#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <ctime>
#include "geometry_msgs/Vector3.h"
#include "std_msgs/Float32.h"
#include <math.h>
#include "imu_3dm_gx4/FilterOutput.h"
#include "sensor_msgs/Joy.h"
#include <std_msgs/Float32MultiArray.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

namespace RiptideVision{
	class visionFunctions
	{
	public:
		Mat seperateColors(Mat src, std::vector<int>& colors);
	};
}