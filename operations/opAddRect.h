#pragma once

#include "operation.h"

//Add Rectangle operation class
class opAddRect : public operation
{
public:
	opAddRect(controller* pCont);
	virtual ~opAddRect();

	//Add rectangle to the controller
	virtual void Execute();

};

//Add Line operation class
class opAddLine : public operation
{
public:
	opAddLine(controller* pCont);
	virtual ~opAddLine();

	//Add Line to the controller
	virtual void Execute();

};


//Add Triangle operation class
class opAddTriangle : public operation
{
public:
	opAddTriangle(controller* pCont);
	virtual ~opAddTriangle();
	virtual void Execute();
};


//Add Square operation class........................................
class opAddSquare : public operation
{
public:
	opAddSquare(controller* pCont);
	virtual ~opAddSquare();
	//Add Square to the controller
	virtual void Execute();
};


//Add Circle operation class........................
class opAddCircle : public operation
{
public:
	opAddCircle(controller* pCont);
	virtual ~opAddCircle();
	//Add Circle to the controller
	virtual void Execute();
};

//Add oval operation class............................
class opAddOval : public operation
{
public:
	opAddOval(controller* pCont);
	virtual ~opAddOval();
	//Add Oval to the controller
	virtual void Execute();
};

//Add RegularPolygon operation class............................
class opAddRegularPolygon : public operation
{
public:
	opAddRegularPolygon(controller* pCont);
	virtual ~opAddRegularPolygon();
	virtual void Execute();
};

//Add IrregularPolygonoperation class................................

class opAddIrregularPolygon : public operation
{
public:
	opAddIrregularPolygon(controller* pCont);
	virtual ~opAddIrregularPolygon();
	virtual void Execute();
};

