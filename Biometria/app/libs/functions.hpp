#include "misc.hpp"

struct sortStruct {
    bool operator() (double i, double j) { return (i > j); } // ordem decrescente
} sortStruct;

struct sortStruct2 {
    bool operator() (Vec4i& i, Vec4i& j) {
        return ((i[3] / 256) > (j[3] / 256)); // ordem decrescente
    }
} sortStruct2;

vector<double> getHandContour(Mat& image)
{
    Mat threshold_output;
    threshold(image, threshold_output, IMAGE_THRESH, 255, THRESH_BINARY);

    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(threshold_output, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

    /* Contorno com a maior área e a menor quantidade de componentes conexas */
    double max;
    Point maxPosition;
    vector<double> areas(contours.size());
    for(int i = 0; i < contours.size(); i++){
        areas[i] = contourArea(Mat(contours[i]));
    }
    minMaxLoc(Mat(areas), 0, &max, 0, &maxPosition);
    int maxIdx = maxPosition.y;

    vector<double> hullDistances;
    vector< vector<Point> > hull (contours.size());
    vector< vector<int> > hullsIndex (contours.size());
    vector< vector<Vec4i> > defects (contours.size());
    convexHull(Mat(contours[maxIdx]), hull[maxIdx], true);
    convexHull(Mat(contours[maxIdx]), hullsIndex[maxIdx], true);

    if(hullsIndex[maxIdx].size() > 3 ) {
        convexityDefects(contours[maxIdx], hullsIndex[maxIdx], defects[maxIdx]);
    }

    /* Drawing stuff */
    Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );

    vector<double> handDistances (10);
    handDistances[0] = contourArea(Mat(contours[maxIdx]));

    std::sort (defects[maxIdx].begin(), defects[maxIdx].end(), sortStruct2); // ordena os defeitos encontrados em ordem decrescente da distância

    for(int j = 0; j < 5; j++) { // as cinco maiores distâncias
        const Vec4i& v = defects[maxIdx][j];
        double depth = v[3] / 256;

        handDistances[j+1] = depth;
        // hullDistances.push_back(depth);

        int startidx = v[0]; Point ptStart(contours[maxIdx][startidx]);
        int endidx = v[1]; Point ptEnd(contours[maxIdx][endidx]);
        int faridx = v[2]; Point ptFar(contours[maxIdx][faridx]);

        line(drawing, ptStart, ptEnd, Scalar(0, 255, 0), 1);
        line(drawing, ptStart, ptFar, Scalar(0, 255, 255), 1);
        // line(drawing, ptEnd, ptFar, Scalar(0, 255, 0), 1);
        circle(drawing, ptFar, 4, Scalar(255, 255, 0), 2);
        circle(drawing, ptStart, 4, Scalar(0, 255, 0), 2);
        // circle(drawing, ptEnd, 4, Scalar(0, 255, 0), 2);
    }
    // std::cout << hullDistances.size() << std::endl;

    // std::sort (hullDistances.begin(), hullDistances.end(), sortStruct);

    hullDistances.clear();

    Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    drawContours(drawing, contours, maxIdx, color, 1, 8, hierarchy, 0, Point());
    drawContours(drawing, hull, maxIdx, color, 1, 8, hierarchy, 0, Point());
    // cv::imshow("Contours", drawing);
    // cv::waitKey(0);

    return handDistances;
}

void doStuff ()
{
    for (int userOne = 1; userOne <= MAX_USERS; userOne++) {
        for (int imageOneNumber = 1; imageOneNumber <= IMAGES_PER_USERS; imageOneNumber++) {
            std::stringstream fileOneName;
            fileOneName << "database/" << userOne << "/" << userOne << "_" << imageOneNumber << ".jpg";
            Mat imageOne = cv::imread(fileOneName.str(), 0);

            vector<double> handOne = getHandContour(imageOne);

            for (int userTwo = 1; userTwo <= MAX_USERS; userTwo++) {
                for (int imageTwoNumber = 1; imageTwoNumber <= IMAGES_PER_USERS; imageTwoNumber++) {
                    std::stringstream fileTwoName;
                    fileTwoName << "database/" << userTwo << "/" << userTwo << "_" << imageTwoNumber << ".jpg";
                    Mat imageTwo = cv::imread(fileTwoName.str(), 0);

                    vector<double> handTwo = getHandContour(imageTwo);

                    double score = euclideanDistance(handOne, handTwo);
                    bool result = score <= USER_THRESHOLD;

                    std::cout
                    <<
                        userOne << "_" << imageOneNumber <<
                        " " <<
                        userTwo << "_" << imageTwoNumber <<
                        " " <<
                        score <<
                        " " <<
                        result
                    << std::endl;
                }
            }

        }
    }
}
