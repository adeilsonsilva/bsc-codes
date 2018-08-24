/* C++ include files */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

/* OpenCV include files */
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#define MAX_USERS           50
#define IMAGES_PER_USERS    5
#define IMAGE_THRESH        25
#define HAND_DIMENSIONS     6 // Área do contorno e as 5 maiores distâncias do convex hull
#define USER_THRESHOLD      3500 // Limite empírico da distância entre dois vetores de características da geometria das mãos

/* Média e desvio-padrão das distâncias dos pontos encontrados
 * automaticamente para o baricentro do triângulo das marcações manuais
 */
#define AUTO_DISTANCE_MEAN      3.3898236989
#define AUTO_DISTANCE_STD_DEV   3.28159635068

using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;

RNG rng(12345);
