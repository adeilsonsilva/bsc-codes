#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace cv;
using namespace std;
Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);
void thresh_callback(int, void* );
int main( int, char** argv )
{
  src = imread( argv[1], 1 );
  cvtColor( src, src_gray, COLOR_BGR2GRAY );
  blur( src_gray, src_gray, Size(3,3) );
  const char* source_window = "Source";
  namedWindow( source_window, WINDOW_AUTOSIZE );
  imshow( source_window, src );
  createTrackbar( " Threshold:", "Source", &thresh, max_thresh, thresh_callback );
  thresh_callback( 0, 0 );
  waitKey(0);
  return(0);
}
void thresh_callback(int, void* )
{
  Mat src_copy = src.clone();
  Mat threshold_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  threshold( src_gray, threshold_output, thresh, 255, THRESH_BINARY );
  findContours( threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
  vector<vector<Point> >hull( contours.size() );
  for( size_t i = 0; i < contours.size(); i++ )
     {   convexHull( Mat(contours[i]), hull[i], false ); }
  Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  // for( size_t i = 0; i< contours.size(); i++ )
  //    {
  //      Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
  //      drawContours( drawing, contours, (int)i, color, 1, 8, vector<Vec4i>(), 0, Point() );
  //      drawContours( drawing, hull, (int)i, color, 1, 8, vector<Vec4i>(), 0, Point() );
  //    }

       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
     vector<double> areas(contours.size());
     for(int i = 0; i < contours.size(); i++)
         areas[i] = contourArea(Mat(contours[i]));
     double max;
     Point maxPosition;
     minMaxLoc(Mat(areas),0,&max,0,&maxPosition);
     drawContours(drawing, contours, maxPosition.y, color, 1, 8, vector<Vec4i>(), 0, Point());

  namedWindow( "Hull demo", WINDOW_AUTOSIZE );
  imshow( "Hull demo", drawing );
}
