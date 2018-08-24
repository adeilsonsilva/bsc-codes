#include "base.hpp"

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

Point barycenter(Point a, Point b, Point c)
{
    return Point( ( (a.x + b.x + c.x) / 3 ), ( (a.y + b.y + c.y) / 3 ) );
}

double distance(Point a, Point b)
{
    return sqrt( pow((b.x - a.x), 2) + pow((b.y - a.y), 2) );
}

double euclideanDistance (vector<double> handOne, vector<double> handTwo)
{
    double sumOfDistances = 0;
    for (int dimension = 0; dimension < HAND_DIMENSIONS; dimension++) {
        sumOfDistances += pow((handTwo[dimension] - handOne[dimension]), 2);
    }

    return sqrt(sumOfDistances);
}

void saveContour(vector<Point>& userContour, string path)
{
    stringstream fileName;
    fileName << path << ".yml";
    cv::FileStorage file(fileName.str(), cv::FileStorage::WRITE);
    file << "Contour" << userContour;
}

bool login(vector<Point>& queryContour)
{
    for (int user = 1; user <= MAX_USERS; user++) {
        for (int image = 1; image <= IMAGES_PER_USERS; image++) {
            std::vector<Point> userContour;
            stringstream fileName;
            fileName << "database/" << user << "/" << user << "_" << image << ".yml";

            cv::FileStorage file(fileName.str(), cv::FileStorage::READ);
            file["Contour"] >> userContour;

            std::cout << matchShapes(queryContour, userContour, CV_CONTOURS_MATCH_I1, 0) << std::endl;
        }
    }
}

void measureDistance()
{
    // for (int user = 1; user <= 13; user++) {
    //     for (int image = 1; image <= IMAGES_PER_USERS; image++) {
    //         double x1, y1, x2, y2, x3, y3;
    //         std::vector<Point> contour;
    //         std::fstream fileA, fileB, fileC, resultFile;
    //         std::stringstream fileName;
    //
    //         fileName << "database/" << user << "/" << user << "_" << image << ".jpg";
    //         Mat imageA = cv::imread(fileName.str(), 0);
    //
    //         string nameA, nameB, nameC, result;
    //         vector<string> Strings = split(fileName.str(), '.');
    //         nameA = nameB = nameC = result = Strings[0];
    //         nameA += "_a1.txt";
    //         nameB += "_a2.txt";
    //         nameC += "_a3.txt";
    //         result += "_result.txt";
    //
    //         vector< vector<Point> > contours;
    //         Mat threshold_output;
    //         threshold( imageA, threshold_output, IMAGE_THRESH, 255, THRESH_BINARY );
    //         Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
    //         Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
    //
    //         // vector<Point> detectedContour = getHandContour(imageA);
    //
    //         std::cout << result.c_str() << std::endl;
    //         resultFile.open(result.c_str(), std::fstream::out);
    //         fileA.open(nameA.c_str(), std::fstream::in);
    //         fileB.open(nameB.c_str(), std::fstream::in);
    //         fileC.open(nameC.c_str(), std::fstream::in);
    //         while ((fileA >> x1 >> y1) && (fileB >> x2 >> y2) && (fileC >> x3 >> y3)) {
    //             Point bary = barycenter(Point(x1, y1), Point(x2, y2), Point(x3, y3));
    //             double dist1 = distance(Point(x1, y1), bary);
    //             double dist2 = distance(Point(x2, y2), bary);
    //             double dist3 = distance(Point(x3, y3), bary);
    //             double result = pointPolygonTest(detectedContour, Point2f(bary.x, bary.y), true);
    //             resultFile << dist1 << " " << dist2 << " " << dist3 << " " << result << std::endl;
    //             // contour.push_back(Point(x, y));
    //             // std::cout << result << std::endl;
    //         }
    //         // std::cout << "size: " << contour.size() << std::endl;
    //         // login(contour);
    //         // contours.push_back(contour);
    //         // drawContours(drawing, contours, 0, color, 1, 8, vector<Vec4i>(), 0, Point());
    //         // cv::imshow("Contours", drawing);
    //         // cv::waitKey(0);
    //         fileA.close();
    //         fileB.close();
    //         fileC.close();
    //         resultFile.close();
    //     }
    // }
}

void buildDatabase ()
{
    // for (int user = 1; user <= MAX_USERS; user++) {
    //     std::fstream areaUser;
    //     std::stringstream areasFile;
    //
    //     areasFile << "database/" << user << "/" << user << "_areas";
    //     areaUser.open(areasFile.str(), std::fstream::out);
    //
    //     for (int image = 1; image <= IMAGES_PER_USERS; image++) {
    //         std::stringstream fileName;
    //
    //         fileName << "database/" << user << "/" << user << "_" << image << ".jpg";
    //         Mat imageA = cv::imread(fileName.str(), 0);
    //
    //         // vector<Point> detectedContour = getHandContour(imageA);
    //         contourArea(detectedContour);
    //         areaUser << contourArea(detectedContour) << std::endl;
    //     }
    //
    //     areaUser.close();
    // }
}
