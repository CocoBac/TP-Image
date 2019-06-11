#pragma once
#include "observer.h"
#include "view.h"
#include "controller.h"
using namespace cv;
class ViewMenu: public View
{
private:
	// Controller of the application
	Controller& controller;
public:
	/**
	 * Constructor
	 * @param _controller Application controller
	 */
	ViewMenu(Controller& _controller);

	/**
	 * Notification function of the view
	 */
	virtual void notify();

	/**
	 * Displays the view
	 */
	virtual void display();
};

