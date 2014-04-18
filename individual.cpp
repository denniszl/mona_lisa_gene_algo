#include "individual.h"


Individual::Individual(){

chromosome.resize(DNA_SIZE);
}

Individual::Individual(int w,int h){
	
	width=w;
	height=h;

	chromosome.resize(DNA_SIZE);
		
}
Individual::Individual(vector<Circle> c,int w,int h){
		

	width=w;
	height=h;
	chromosome=c;

}
Individual::Individual(Individual const &other){
	
	width=other.width;	
 	height=other.height;
	fitness=other.fitness;
	chromosome=other.chromosome;
}	
Individual const & Individual::operator=(Individual const &other){

	if(this!=&other){
		width=other.width;	
 		height=other.height;
		fitness=other.fitness;
		chromosome=other.chromosome;
	}
	return  *this;
}

bool Individual::operator<(Individual const &other)
{
	return (fitness < other.fitness);
}

void Individual::setDimensions(int w,int h){

	width = w;
	height = h;
}

void Individual::generateRandomIndividual(){

	for(int i=0; i<DNA_SIZE;i++){				

		int r=(rand()%(width/8))+5;

		int x=rand()%width;

		int y=rand()%height;

		RGBAPixel color;

		color.red   =  rand()%256;		
		color.blue  =  rand()%256;
		color.green =  rand()%256;	
		color.alpha =  128;		
		Circle c(r,x,y,color);			
		chromosome[i]=c;
	}
}		
PNG Individual::drawImage(){

	PNG image;
	image.resize(width,height);

	for(int i=0; i<chromosome.size();i++){
		chromosome[i].drawCircle(image);		
	}

	return image;
}










