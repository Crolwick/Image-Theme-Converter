#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "functions.h"

using namespace cv;
using namespace std;

Mat editPixels(Mat orgiImg, Mat imgSrc, Mat imgMask)
{

	orgiImg.copyTo(imgSrc, imgMask);

	Mat coloredImg(orgiImg.rows, orgiImg.cols, orgiImg.type()), maskedColorImg;

	Mat tempHSV;
	cvtColor(imgSrc, tempHSV, COLOR_BGR2HSV);

	// This is the actual color conversion
	for (int i = 0; i < imgSrc.rows; i++)
	{
		for (int j = 0; j < imgSrc.cols; j++)
		{
			if (imgSrc.at<Vec3b>(i, j)[0] != 0 && imgSrc.at<Vec3b>(i, j)[1] != 0 && imgSrc.at<Vec3b>(i, j)[2] != 0)
			{
				// Check Red
				if ((tempHSV.at<Vec3b>(i, j)[0] >= lowerRed1[0] && tempHSV.at<Vec3b>(i, j)[0] <= upperRed1[0]) ||
					(tempHSV.at<Vec3b>(i, j)[0] >= lowerRed2[0] && tempHSV.at<Vec3b>(i, j)[0] <= upperRed2[0]))
				{
					coloredImg.setTo(color[0]);
					coloredImg.copyTo(maskedColorImg, imgMask);
					break;
				}
				// Check Orange
				else if (tempHSV.at<Vec3b>(i, j)[0] >= lowerOrange[0] && tempHSV.at<Vec3b>(i, j)[0] <= upperOrange[0])
				{
					coloredImg.setTo(color[1]);
					coloredImg.copyTo(maskedColorImg, imgMask);
					break;
				}
				// Check Yellow
				else if (tempHSV.at<Vec3b>(i, j)[0] >= lowerYellow[0] && tempHSV.at<Vec3b>(i, j)[0] <= upperYellow[0])
				{
					coloredImg.setTo(color[2]);
					coloredImg.copyTo(maskedColorImg, imgMask);
					break;
				}
				// Check Green
				else if (tempHSV.at<Vec3b>(i, j)[0] >= lowerGreen[0] && tempHSV.at<Vec3b>(i, j)[0] <= upperGreen[0])
				{
					coloredImg.setTo(color[3]);
					coloredImg.copyTo(maskedColorImg, imgMask);
					break;
				}
				// Check Blue
				else if (tempHSV.at<Vec3b>(i, j)[0] >= lowerBlue[0] && tempHSV.at<Vec3b>(i, j)[0] <= upperBlue[0])
				{
					coloredImg.setTo(color[4]);
					coloredImg.copyTo(maskedColorImg, imgMask);
					break;
				}
				// Check Purple
				else if (tempHSV.at<Vec3b>(i, j)[0] >= lowerPurple[0] && tempHSV.at<Vec3b>(i, j)[0] <= upperPurple[0])
				{
					coloredImg.setTo(color[5]);
					coloredImg.copyTo(maskedColorImg, imgMask);
					break;
				}

				// Check White Condition
				if ((tempHSV.at<Vec3b>(i, j)[1] >= lowerWhite[1] && tempHSV.at<Vec3b>(i, j)[1] < upperWhite[1]) ||
					(tempHSV.at<Vec3b>(i, j)[2] >= lowerWhite[2] && tempHSV.at<Vec3b>(i, j)[2] < upperWhite[2]))
				{
					coloredImg.setTo(color[2]);
					coloredImg.copyTo(maskedColorImg, imgMask);
					break;
				}
			}
		}
	}

	return maskedColorImg;
}