#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#define MAX_USERS 13
#define IMAGES_PER_USERS 5

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

// int x = 0, y = 0;
float x = 0, y = 0, xA = 0, yA = 0, xB = 0, yB = 0;
cv::Mat image, descriptorA, descriptorB, mask, outputImage;
std::fstream file, fileA, fileB;
vector<string> Strings;
vector<cv::Point> pointsA, pointsB;
std::map<int, vector<cv::Point2f> > allPoints; /* Armazena pontos separados por classe (cada um dos 35 pontos é uma classe) */
// vector<vector<Point> > contours;

RNG rng(12345);

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

void loadPoints() {

    for (int user = 1; user <= MAX_USERS; user++) {
        for (int imageNumber = 1; imageNumber <= IMAGES_PER_USERS; imageNumber++) {
            std::stringstream imageName, fileNameA, fileNameB;
            imageName << "gtruth_images/" << user << "_" << imageNumber << ".jpg";

            // std::cout << imageName.str() << std::endl;

            image = imread(imageName.str(), 1);
            Strings = split(imageName.str(), '.');
            string nameA, nameB;
            nameA = nameB = Strings[0];
            nameA += "_a.txt";
            nameB += "_b.txt";

            fileA.open(nameA.c_str(), std::fstream::in);
            fileB.open(nameB.c_str(), std::fstream::in);

            int classe = 0;
            while ((fileA >> xA >> yA) && (fileB >> xB >> yB)) {
                // cout << "setando classe " << classe << endl;
                pointsA.push_back(cv::Point2f(xA, yA));
                pointsB.push_back(cv::Point2f(xB, yB));
                // allPoints[classe].push_back(cv::Point2f(xA, yA));
                // allPoints[classe].push_back(cv::Point2f(xB, yB));
                classe++;
            }
            // pointsA.clear();
            // pointsB.clear();
            fileA.close();
            fileB.close();
            Strings.clear();
        }
    }
    // contours.push_back(pointsA);
    // contours.push_back(pointsB);
}

int main(int argc, char const *argv[]) {

    // createMask();

    loadPoints();

    // cv::ml::KNearest knnClasifier = cv::ml::KNearest::create();

    int classe = 1;
    for (int user = 1; user <= MAX_USERS; user++) {
        for (int imageNumber = 1; imageNumber <= IMAGES_PER_USERS; imageNumber++) {

            std::stringstream imageName, fileNameA, fileNameB;
            imageName << "gtruth_images/" << user << "_" << imageNumber << ".jpg";

            std::cout << imageName.str() << std::endl;

            image = imread(imageName.str(), 0);

            int thresh = 25;
            Mat threshold_output;
            threshold( image, threshold_output, thresh, 255, THRESH_BINARY );

            vector< vector<Point> > contours;
            vector<Vec4i> hierarchy;
            findContours(threshold_output, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

            // vector<vector<Point> >hull( contours.size() );
            // for( size_t i = 0; i < contours.size(); i++ ) {
            //    convexHull( Mat(contours[i]), hull[i], false );
            // }

            Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
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

            // Procurar os pontos de A cada classe
            // for (int classe = 1; classe <= 35; classe++) {
            //     for (auto& point : pointsA) {
            //         cv::flann::Index linearFlann(cv::Mat(allPoints[classe]).reshape(1), cv::flann::LinearIndexParams());
            //         vector<float> dists;
            //         vector<float> query;
            //         vector<int> indices;
            //         // cout << "Procurando ponto da classe: " << classe << endl;
            //         query.push_back(point.x);
            //         query.push_back(point.y);
            //         linearFlann.knnSearch(query, indices, dists, 1, cv::flann::SearchParams(32));
            //         circle(image, pointsA[indices[indices.size() - 1]], 3, CV_RGB(255,0,0), -1);
            //     }
            // }
            // cv::imshow("157", image);
            cv::waitKey(0);
        }
    }

    return 0;
}
