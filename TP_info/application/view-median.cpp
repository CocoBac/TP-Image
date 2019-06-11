#include "view-median.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewMedian::ViewMedian(Controller& _controller)
	: View("Filtre Median"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewMedian::notify()
{
	if (controller.getCurrentScreen() == 1)//si l'utilisateur entre le chiffre 1
		display();
}
extern Mat image, img;
/**
 * Displays the view
 */
void ViewMedian::display()
{
	clear();
	View::display();

	int taux;
	std::cout << "Quel taux ?" << std::endl;
	std::cin >> taux;

	medianBlur(image, image, taux);

	std::string windowName = "Normale";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, img);

	std::string windowNameModifiee = "Modifiee";
	namedWindow(windowNameModifiee, WINDOW_NORMAL);
	imshow(windowNameModifiee, image);

	controller.setScreen(0);
}