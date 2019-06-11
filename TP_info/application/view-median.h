#pragma once
#include "view.h"
#include "controller.h"
using namespace cv;
class ViewMedian: public View
{
private:
	// Controller of the application
	Controller& controller;
public:
	/**	
	 * Constructor
	 * @param _controller : Controller of the application
	 */
	ViewMedian(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();

};

