#include "application.h"

/**
 * Constructor
 */
Application::Application()
	: controller(), viewMenu(controller), viewGauss(controller), viewMedian(controller), viewGradient(controller), viewErosion(controller), viewDilatation(controller), viewSeuillage(controller), viewContours(controller)
{
}

/**
 * Runs the application
 */
void Application::run()
{
	controller.notify();
}
