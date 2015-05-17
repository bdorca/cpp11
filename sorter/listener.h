#ifndef LISTENER_H
#define LISTENER_H

class ColumnListener
{
protected:
public:
	ColumnListener(){}
	virtual ~ColumnListener(){}
	virtual void onCompare(int a, int b, bool swap)=0;
	
};

#endif // LISTENER_H
