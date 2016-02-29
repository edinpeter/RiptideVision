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
#include </home/peter/riptideVision/RiptideVision.h>

using namespace cv;
using namespace std;

  cv::Mat RiptideVision::seperateColors(Mat src, vector<int> colors){
      Mat image_raw_hsv;
          Mat blacknwhite(src, Rect(0,0,src.cols-1,src.rows-1));
          blacknwhite = Mat::zeros(blacknwhite.rows,blacknwhite.cols,CV_8UC1);
          cvtColor(src,image_raw_hsv,COLOR_BGR2HSV);

          //BGR
          int pointx = 0;
          int pointy = 0;
          for(double cols = src.cols; pointx < cols; pointx+=1){
              pointy=0;
              for(double rows = src.rows; pointy < rows; pointy+=1){
                  if(image_raw_hsv.at<Vec3b>(Point(pointx,pointy))[0] > colors[0]  &&
                     image_raw_hsv.at<Vec3b>(Point(pointx,pointy))[0] < colors[1] &&
                     image_raw_hsv.at<Vec3b>(Point(pointx,pointy))[1] > colors[2]  &&
                     image_raw_hsv.at<Vec3b>(Point(pointx,pointy))[1] < colors[3] &&
                     image_raw_hsv.at<Vec3b>(Point(pointx,pointy))[2] > colors[4] &&
                     image_raw_hsv.at<Vec3b>(Point(pointx,pointy))[2] < colors[5]){
                     blacknwhite.at<Vec3b>(Point(pointx,pointy))[0] = 255;
                     blacknwhite.at<Vec3b>(Point(pointx,pointy))[1] = 255;
                     blacknwhite.at<Vec3b>(Point(pointx,pointy))[2] = 255;  
                  }
              }
          }

          return blacknwhite;
    }


int main(){
		
}