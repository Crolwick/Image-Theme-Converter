#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

/* FEEL FREE TO CHANGE THE COLOR VALUES TO YOUR CHOICE */
// Use BGR Values
const Scalar color[] = { Scalar(192, 213, 218), // Lightest Color
						 Scalar(174, 195, 200), // Second Lightest Color
						 Scalar(154, 175, 180), // Third Lightest Color
						 Scalar(135, 156, 161), // Third Darkest Color
						 Scalar(96, 117, 122), // Second Darkest Color
						 Scalar(60, 81, 86) }; // Darkest Color

// Remaining Colors (These Use HSV Values)
const Scalar lowerBlack(0, 0, 0);
const Scalar upperBlack(180, 255, 30);

const Scalar lowerWhite(0, 0, 100);
const Scalar upperWhite(180, 19, 255);

// Purple Color
const Scalar lowerPurple(136, 20, 30);
const Scalar upperPurple(155, 255, 255);

// Blue Color
const Scalar lowerBlue(76, 20, 30);
const Scalar upperBlue(135, 255, 255);

// Green Color
const Scalar lowerGreen(36, 20, 30);
const Scalar upperGreen(75, 255, 255);

// Yellow Color
const Scalar lowerYellow(26, 20, 30);
const Scalar upperYellow(35, 255, 255);

// Orange Color
const Scalar lowerOrange(11, 20, 30);
const Scalar upperOrange(25, 255, 255);

// Red Color
const Scalar lowerRed1(0, 20, 30); // First Half Red Lower Bound
const Scalar upperRed1(10, 255, 255); // First Half Red Upper Bound
const Scalar lowerRed2(156, 20, 30); // Second Half Red Lower Bound
const Scalar upperRed2(180, 255, 255); // Second Half Red Upper Bound

Mat editPixels(Mat orgiImg, Mat imgSrc, Mat imgMask);