#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "functions.h"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{

	Mat imgHSV, finalImg; // overall Imgs

	/*
		Array Order
		0 -> Red
		1 -> Orange
		2 -> Yellow
		3 -> Green
		4 -> Blue
		5 -> Purple
		6 -> White
		7 -> Black
	*/

	Mat redMask1, redMask2; // Temp Red Masks

	Mat masks[8], maskedImgs[8]; // Masks Array, MaskedImgs Array

	/* REPLACE YOUR FILE PATH HERE */
	// RECOMMENDED TO USE A FULL PATH
	// Example: C:/Users/yourName/Desktop/fileName.png
	string path = "C:/Users/Crolw/OneDrive/Desktop/pokerCards.jpg"; // Img to Convert

	Mat img = imread(path);

	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	inRange(imgHSV, lowerBlack, upperBlack, masks[7]);

	inRange(imgHSV, lowerWhite, upperWhite, masks[6]);

	inRange(imgHSV, lowerPurple, upperPurple, masks[5]);

	inRange(imgHSV, lowerBlue, upperBlue, masks[4]);

	inRange(imgHSV, lowerGreen, upperGreen, masks[3]);

	inRange(imgHSV, lowerYellow, upperYellow, masks[2]);

	inRange(imgHSV, lowerOrange, upperOrange, masks[1]);

	inRange(imgHSV, lowerRed1, upperRed1, redMask1); // Creates First Half Red Mask
	inRange(imgHSV, lowerRed2, upperRed2, redMask2); // Creates Second Half Red Mask
	masks[0] = redMask1 | redMask2; // Combine Both Halfs to one final Red Mask

	// Converts each mask into its specified color
	for (int i = 0; i < 8; i++)
	{
		maskedImgs[i] = editPixels(img, maskedImgs[i], masks[i]);
	}

	Mat tempImg;

	// Puts all the maskedImgs together into one final Img
	add(maskedImgs[0], maskedImgs[1], tempImg);
	for (int j = 2; j < 8; j++)
	{
		add(tempImg, maskedImgs[j], tempImg);
	}

	finalImg = tempImg;

	// Display
	imshow("Defualt Img", img);
	imshow("Final Img 1", finalImg);
	waitKey(0);
}