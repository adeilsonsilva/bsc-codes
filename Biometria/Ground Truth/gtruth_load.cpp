#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

int x = 0, y = 0;
Mat image;
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

int main(int argc, char **argv) {
	// Load image
	image = imread(argv[1], 1);

    string name;
    Strings = split(argv[1], '.');
    name = Strings[0];
    name += "_a.txt";

    cout << name << endl;

    file.open(name.c_str(), std::fstream::in);

    while (file >> x >> y) {
        cout << x << " " << y << endl;
        circle(image, Point(x,y), 3, CV_RGB(255,0,0), -1);
    }

    namedWindow("gtruth", 1);

    while(waitKey(10) < 0) {
        imshow("gtruth", image);
    }

    file.close();
}
