#include "view-gauss.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewGauss::ViewGauss(Controller& _controller)
	: View("Filtre Gaussien"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewGauss::notify()
{
	if (controller.getCurrentScreen() == 2)
		display();
}
extern Mat image, img;
/**
 * Displays the view
 */
void ViewGauss::display()
{
	clear();
	View::display();

	int taux1, taux2;
	std::cout << "Quels taux ?" << std::endl;
	std::cin >> taux1;
	std::cin >> taux2;
	if (taux1 % 2 == 0) { taux1++; }
	if (taux2 % 2 == 0) { taux1++; }

	GaussianBlur(image, image, Size(taux1, taux2), 0, 0, BORDER_DEFAULT);

	std::string windowName = "Normale";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, img);

	std::string windowNameModifiee = "Modifiee";
	namedWindow(windowNameModifiee, WINDOW_NORMAL);
	imshow(windowNameModifiee, image);
	
	controller.setScreen(0);
}