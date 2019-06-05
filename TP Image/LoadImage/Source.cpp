#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main(int argc, char** argv)
{//MODIFICATION
	// Lecture de l’image avec la méthode imread ()
	Mat image = imread("Lena.jpg");
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	// Changement de luminosité dans l’image en utilisant la méthode convertTo();
	Mat imageModifiee;
	//medianBlur(image, image, 3);
	//Sobel(image, imageModifiee, 0, 2,2, 3, 1,0, BORDER_DEFAULT);
	//dilate(image, imageModifiee, imageModifiee);
	//threshold(image, imageModifiee, 130, 255, THRESH_BINARY);
	watershed(image, imageModifiee);
	String windowNameModifiee = "Modifiee";
	namedWindow(windowNameModifiee, WINDOW_NORMAL);


	/*
	Affichage de l’image de l’image originale et des deux nouvelles
	images dans trois fenêtres différentes avec la méthode imshow ()
	*/
	String windowNameOriginalImage = "Original Image";
	//String windowNameBrightnessHigh100 = "Brightness Increased by 100";

	// String windowNameBrightnessLow100 = "Brightness Decreased by 100";
	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	//namedWindow(windowNameMedianBlurred, WINDOW_NORMAL);

	imshow(windowNameOriginalImage, image);
	imshow(windowNameModifiee, imageModifiee);

	// Sauvegarde d’une image traitée à l'aide de la méthode imwrite ()
	imwrite("Q:/My_new_image.jpg", imageModifiee);
	waitKey(0);
	destroyAllWindows();
	return 0;
}