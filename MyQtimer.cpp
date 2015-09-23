#include "MyQtimer.h"

MyQtimer::MyQtimer(): QThread()
{	
	value=1000;
}
	void MyQtimer::setValue(int n){
		i.set(n);
	}
	
void MyQtimer::run(){
	while(1){		
		msleep(i.get());
		emit mytimeout();
	}
	}

MyQtimer::~MyQtimer()
{
	
}

