#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#define DNA_SIZE 200

#include "png.h"
#include "rgbapixel.h"	
#include "circle.h"
#include <vector>
#include <stdlib.h> 
#include <time.h>  


using namespace std;

class Individual{

	public:
		vector<Circle> chromosome;	
		double fitness;
		int width;
		int height;	
		
		Individual();
		Individual(int w,int h);
		Individual(vector<Circle> c,int w,int h);
		Individual(Individual const &other);	
		Individual const & operator=(Individual const &other);
		bool operator<(Individual const &other);

			
		void setDimensions(int w,int h);
		void generateRandomIndividual();
		PNG drawImage();
					
};
#endif

