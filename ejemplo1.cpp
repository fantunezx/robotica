#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()));
	connect (&timer, SIGNAL(mytimeout()), this, SLOT(doIncreaseNumber()));
	connect (Slider, SIGNAL(sliderMoved(int)),this, SLOT(decreaseTime()));
	Slider->setValue(100);
	timer.start();
	
}

ejemplo1::~ejemplo1()
{
	
}

void ejemplo1::doButton()
{
	qDebug() << "click on button";	
	timer.terminate();
}
void ejemplo1::doIncreaseNumber()
{
	static int n=0;
	lcdNumber->display(n++);
}
void ejemplo1::decreaseTime(){
	
	timer.setValue(Slider->value()*10 );
}





