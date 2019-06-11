#include "view-menu.h"
#include <iostream>

/**
 * Constructor
 * @param _controller Application controller 
 */
ViewMenu::ViewMenu(Controller& _controller)
	: View("Menu"), controller(_controller)
{
	controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewMenu::notify() 
{
	if(controller.getCurrentScreen() == 0)
		display();
}

/**
 * Displays the view
 */
void ViewMenu::display()
{
	clear();
	View::display();

	std::cout << "\t1. Filtre Median" << std::endl;
	std::cout << "\t2. Filtre Gaussien" << std::endl;
	std::cout << "\t3. Gradient (Sobel)" << std::endl;
	std::cout << "\t4. Dilatation" << std::endl;
	std::cout << "\t5. Erosion" << std::endl;
	std::cout << "\t6. Contours (Canny)" << std::endl;
	std::cout << "\t7. Seuillages" << std::endl;
	std::cout << "\t8. Segmentation par croissance de region (!)" << std::endl;

	std::cout << "\t--------------------------------------------" << std::endl;
	std::cout << "\t9. Quitter" << std::endl;
	std::cout << std::endl;

	int res;
	std::cin.clear();
	std::cin >> res;

	controller.setScreen(res);
}
