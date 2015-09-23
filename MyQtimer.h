#ifndef MyQtimer_H
#define MyQtimer_H
#include "QThread"
#include "qmutex.h"
class MyQtimer : public QThread
{
Q_OBJECT
public:
    MyQtimer();
    virtual ~MyQtimer();
    
public slots:
	void setValue(int n);
	void run();
private:
	int value;
	struct intervalo{
	QMutex m;
	
	int interval;
	intervalo(){interval=1000;}
		void set(int v){
			QMutexLocker ml (&m);
			interval=v;
		
		}
		int get(){
			QMutexLocker ml(&m);
			return interval;
		}
		
	};
	intervalo i;
	
signals:
	void mytimeout();
	
};

#endif