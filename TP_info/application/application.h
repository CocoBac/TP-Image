#pragma once
#include "controller.h"
#include "view-menu.h"
#include "view-gauss.h"
#include "view-median.h"
#include "viewGradient.h"
#include "ViewErosion.h"
#include "ViewDilatation.h"
#include "ViewSeuillage.h"
#include "ViewContours.h"
#include <opencv2/opencv.hpp>




class Application
{
private:
	Controller controller;
	ViewMenu viewMenu;
	ViewGauss viewGauss;
	ViewMedian viewMedian;
	ViewGradient viewGradient;
	ViewErosion viewErosion;
	ViewDilatation viewDilatation;
	ViewSeuillage viewSeuillage;
	ViewContours viewContours;

public:
	/**
	 * Constructor
	 */
	Application();

	/**
	 * Runs the application
	 */
	void run();
};

