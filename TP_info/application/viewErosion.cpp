#include "ViewErosion.h"
#include <iostream>

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewErosion::ViewErosion(Controller& _controller)
	: View("Erosion"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewErosion::notify()
{
	if (controller.getCurrentScreen() == 4)
		display();
}
extern Mat image, img;
/**
 * Displays the view
 */
void ViewErosion::display()
{
	
	clear();
	View::display();

	erode(image, image, image);

	std::string windowName = "Normale";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, img);

	std::string windowNameModifiee = "Modifiee";
	namedWindow(windowNameModifiee, WINDOW_NORMAL);
	imshow(windowNameModifiee, image);


	controller.setScreen(0);
}