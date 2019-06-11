#include "ViewContours.h"

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewContours::ViewContours(Controller& _controller)
	: View("Contours"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewContours::notify()
{
	if (controller.getCurrentScreen() == 7)
		display();
}
extern Mat image, img;
/**
 * Displays the view
 */
void ViewContours::display()
{
	clear();
	View::display();
	
	Canny(image, image, 5, 15, 3, false);

	std::string windowName = "Normale";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, img);

	std::string windowNameModifiee = "Modifiee";
	namedWindow(windowNameModifiee, WINDOW_NORMAL);
	imshow(windowNameModifiee, image);

	controller.setScreen(0);
}

