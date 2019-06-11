#include "viewGradient.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewGradient::ViewGradient(Controller& _controller)
	: View("Gradient"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewGradient::notify()
{
	if (controller.getCurrentScreen() == 3)
		display();
}
extern Mat image, img;
/**
 * Displays the view
 */
void ViewGradient::display()
{
	clear();
	View::display();

	Sobel(image, image, 0, 2, 2, 3, 1, 0, BORDER_DEFAULT);
	
	std::string windowName = "Normale";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, img);

	std::string windowNameModifiee = "Modifiee";
	namedWindow(windowNameModifiee, WINDOW_NORMAL);
	imshow(windowNameModifiee, image);

	
	controller.setScreen(0);
}