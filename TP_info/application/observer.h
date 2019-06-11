#pragma once
#include <opencv2/opencv.hpp>
using namespace cv;
class Observer
{
public:
	virtual void notify() = 0;
};

