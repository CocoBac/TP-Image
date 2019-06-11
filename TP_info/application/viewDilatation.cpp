#include "ViewDilatation.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewDilatation::ViewDilatation(Controller& _controller)
	: View("Dilatation"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewDilatation::notify()
{
	if (controller.getCurrentScreen() == 5)
		display();
}
extern Mat image, img;
/**
 * Displays the view
 */
void ViewDilatation::display()
{
	clear();
	View::display();

	dilate(image, image, image);

	std::string windowName = "Normale";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, img);

	std::string windowNameModifiee = "Modifiee";
	namedWindow(windowNameModifiee, WINDOW_NORMAL);
	imshow(windowNameModifiee, image);


	controller.setScreen(0);
}