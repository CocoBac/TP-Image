#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "application.h"
using namespace cv;
using namespace std;


Mat image, img;

int main(int argc, char** argv)
{
	
	Mat test;
	test = imread("lena.jpg");
	if (test.empty()) //s'il n'y a pas d'image
	{
		cout << "Could not open or find the image" << endl;
		cin.get();
		return -1;
	}
	else cout << "ok" << endl;
	namedWindow("test", WINDOW_NORMAL);
	imshow("test", test);




	cout << "Quel est le nom de votre image ? (jpg)" << endl;
	string nom = "F:\\final\\TP_info\\";
	string nomB;
	cin >> nomB;
	nom += nomB;
	nom += ".jpg";
	cout << nom << endl;

	img = imread("Lena.jpg");
	//cvtColor(img, img, COLOR_BGR2GRAY); //pour convertir l'image en noir et blanc
	//image = imread(nom);
	//cvtColor(image, image, COLOR_BGR2GRAY); //pour convertir l'image en noir et blanc

	string windowName = "Normale";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, img);
	
	/*if (image.empty()) //s'il n'y a pas d'image
	{
		std::cout << "Could not open or find the image" << endl;
		std::cin.get(); 
		return -1;
	}*/

	Application application;
	application.run();
	return 0;
}