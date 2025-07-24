#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Rect(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
};

//....................................................................
// class line 

class Line : public shape
{
private:
	Point Point1;	//First point of the line
	Point Point2;	//Second point of the line
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
};
//............................................................
//Triangle class
class Triangle : public shape
{
private:
	Point Corner1;	//1st corner of the triangle
	Point Corner2;	//2nd corner of the triangle
	Point Corner3;	//3rd corner of the triangle

public:
	Triangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	// Draw function
	virtual void Draw(GUI* pUI) const;
};

//..........................................................
//class Square
class Square : public shape
{
private:
	Point Center;	//Center of the square
	Point Corner;	//A corner point to determine size

public:
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	// Draw function
	virtual void Draw(GUI* pUI) const;
};

//........................................
//Circle class
class Circle : public shape
{
private:
	Point Center;	//Center point of the circle
	Point Edge;	    //A point on the circle edge to define the radius

public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	// Draw function
	virtual void Draw(GUI* pUI) const;
};

//........................................................
//class Oval
class Oval : public shape
{
private:
	Point Center;
	Point Corner;

public:

	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	// Draw function
	virtual void Draw(GUI* pUI) const;
};

//......................................................
//class RegularPolygon

class RegularPolygon : public shape
{
private:
	Point Center;
	int Radius;
	int VerticesCount;

public:
	RegularPolygon(Point center, int radius, int count, GfxInfo shapeGfxInfo);
	virtual ~RegularPolygon();
	// Draw function
	virtual void Draw(GUI* pUI) const;
};

//..............................................
//class IrregularPolygon 
class IrregularPolygon : public shape
{
private:
	Point* Vertices;      // Array of vertices
	int VerticesCount;    // Number of vertices

public:
	IrregularPolygon(Point* Points, int Count, GfxInfo shapeGfxInfo);
	virtual ~IrregularPolygon();
	virtual void Draw(GUI* pUI) const;
};

