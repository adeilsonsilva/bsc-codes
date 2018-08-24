#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using namespace cv;
using namespace std;

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

void mousefunc(int event, int x, int y, int flags, void* userdata) {
	if(event == EVENT_LBUTTONDOWN) {
		circle(image, Point(x,y), 3, CV_RGB(255,0,0), -1);
        file << x << " " << y << endl;
    }
}

int main(int argc, char **argv) {
	// Load image
	image = imread(argv[1], 1);

    string name;
    Strings = split(argv[1], '.');
    name = Strings[0];
    name += "_2.txt";

    cout << name << endl;

    file.open(name.c_str(), std::fstream::out | std::fstream::app);

    if (file.is_open()) {
        namedWindow("gtruth", 1);

        setMouseCallback("gtruth", mousefunc, NULL);

        while(waitKey(10) < 0) {
            imshow("gtruth", image);
        }
    }

    file.close();
}
