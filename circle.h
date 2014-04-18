#ifndef CIRCLE_H
#define CIRCLE_H

#include "png.h"
#include "rgbapixel.h"
#include <math.h>


class Circle{

	public:
		int radius;
		RGBAPixel color;
		int x;
		int y;


		Circle();
		Circle(int r,int xc,int yc,RGBAPixel c);		
		
		Circle(Circle const &other);	
		Circle const & operator=(Circle const &other);

		void drawCircle(PNG &source);


		RGBAPixel* blendPixels(RGBAPixel c1,RGBAPixel c2);


};
#endif
