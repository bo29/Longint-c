#ifndef POSITION_H
#define POSITION_H

class Position {

protected:
    int value;

public:
    Position(int);
	
	virtual ~Position() { }
	
    int getValue();
};

#endif
