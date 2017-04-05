#include<iostream>
#include<unistd.h> // for usleep
#include"GPIO.h"

using namespace exploringBB;
using namespace std;

GPIO *outGPIO, *inGPIO; // global pointers

int activateLED(int var){ // the callback function
	printf("activeLEDpartworking?");
	usleep(100);
	if(outGPIO->getValue() == 1){
		outGPIO->streamWrite(GPIO::LOW); 
		usleep(100);
	}else
		outGPIO->streamWrite(GPIO::HIGH); 
		usleep(100);
return 0;
}

int main(){
	printf("main part of code")

	if(getuid()!=0){
	cout << "You must run this program as root. Exiting." << endl;
	return -1;
}

	outGPIO = new GPIO(49);
	inGPIO = new GPIO(115);
	
	inGPIO->setDirection(GPIO::INPUT);
	outGPIO->setDirection(GPIO::OUTPUT); 

	
	outGPIO->streamOpen(); 
	inGPIO->setEdgeType(GPIO::RISING); 
	inGPIO->waitForEdge(&activateLED);
	usleep(500000000);
	outGPIO->streamClose(); 
return 0;
}


