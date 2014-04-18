#include "circle.h"

Circle::Circle(){
	radius=0;
	x=0;
	y=0;
}
Circle::Circle(int r,int xc,int yc,RGBAPixel c){
	
	radius=r;
	x=xc;
	y=yc;

	color.red=c.red;
	color.green=c.green;
	color.blue=c.blue;
	color.alpha=c.alpha;

}
Circle::Circle(Circle const &other){
	
	radius=other.radius;
	color.red=other.color.red;
	color.green=other.color.green;
	color.blue=other.color.blue;
	color.alpha=other.color.alpha;	
	x=other.x;
	y=other.y;
}	
Circle const & Circle::operator=(Circle const &other){

	if(this!=&other){
		radius=other.radius;
		color.red=other.color.red;
		color.green=other.color.green;
		color.blue=other.color.blue;
		color.alpha=other.color.alpha;	
 		x=other.x;
		y=other.y;
	}
	return  *this;
}		
void Circle::drawCircle(PNG &source){

	for (int xc = -radius; xc < radius ; xc++)	
	{
    	int height = (int)sqrt((radius * radius) - (xc * xc));

    	for (int yc = -height; yc < height; yc++){

    		 if((xc+x)>0 && (xc+x)<360){
				if((yc+y)>0 && (yc+y)<397){
		
					double a1 = ((int)color.alpha) / 255.0;
    				double a2 = ((int)source(xc + x, yc + y)->alpha) / 255.0;

   				    source(xc + x, yc + y)->red = (int) (a1 * ((int)color.red) + a2 * (1 - a1) * ((int)source(xc + x, yc + y)->red));
   					source(xc + x, yc + y)->green = (int) (a1 * ((int)color.green) + a2 * (1 - a1) * ((int)source(xc + x, yc + y)->green));
   				    source(xc + x, yc + y)->blue = (int) (a1 * ((int)color.blue) + a2 * (1 - a1) * ((int)source(xc + x, yc + y)->blue));
  					source(xc + x, yc + y)->alpha = (int) (255 * (a1 + a2 * (1 - a1)));
				}		
			}	
		}
	}

}

RGBAPixel* Circle::blendPixels(RGBAPixel c1,RGBAPixel c2)
{
	RGBAPixel *c;
  	return c;
}		

