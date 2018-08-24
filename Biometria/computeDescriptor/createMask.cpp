#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

// int x = 0, y = 0;
float x = 0, y = 0;
Mat image, descriptor, mask, outputImage;
std::fstream file;
vector<string> Strings;

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int createMask() {

    std::vector<cv::KeyPoint> keyPoints, keyPoints2;
    // std::vector<cv::Point> points;
    std::vector<cv::Point2f> points;
    cv::Ptr<SURF> detector = SURF::create();


    mask = cv::Mat::zeros(600, 800, CV_8U);
    for (int user = 1; user <= 13; user++) {
        for (int image = 1; image <= 5; image++) {

            std::stringstream fileName;
            fileName << "gtruth_images/" << user << "_" << image << ".jpg";

            std::cout << fileName.str() << std::endl;

            // image = cv::imread(fileName.str(), 1);
            string name;
            Strings = split(fileName.str(), '.');
            name = Strings[0];
            name += "_a.txt";

            file.open(name.c_str(), std::fstream::in);
            while (file >> x >> y) {
                // points.push_back(cv::KeyPoint(x, y, 8, -1, 0, 0, -1));
                // points.push_back(cv::Point2f(x, y));
                mask.at<uchar>(cv::Point(x, y)) = 255;
                mask.at<uchar>(cv::Point(x - 1, y)) = 255;
                mask.at<uchar>(cv::Point(x, y -1)) = 255;
                mask.at<uchar>(cv::Point(x -1, y -1)) = 255;
                mask.at<uchar>(cv::Point(x, y + 1)) = 255;
                mask.at<uchar>(cv::Point(x + 1, y)) = 255;
                mask.at<uchar>(cv::Point(x + 1, y + 1)) = 255;
                mask.at<uchar>(cv::Point(x + 1, y - 1)) = 255;
                mask.at<uchar>(cv::Point(x - 1, y + 1)) = 255;
            }
            // cv::imshow("Out", mask);
            // cv::waitKey(0);
        }
    }

    return 0;
}
