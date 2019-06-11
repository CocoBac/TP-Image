#include "viewSeuillage.h"

/**
 * Constructor
 * @param _controller : Controller of the application
 */
ViewSeuillage::ViewSeuillage(Controller& _controller)
	: View("Seuillage"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewSeuillage::notify()
{
	if (controller.getCurrentScreen() == 6)
		display();
}
extern Mat image, img;
/**
 * Displays the view
 */
void ViewSeuillage::display()
{
	clear();
	View::display();

	threshold(image, image, 130, 255, THRESH_BINARY);

	std::string windowName = "Normale";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, img);

	std::string windowNameModifiee = "Modifiee";
	namedWindow(windowNameModifiee, WINDOW_NORMAL);
	imshow(windowNameModifiee, image);

	controller.setScreen(0);
}

