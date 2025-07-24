#include "Rect.h"

// rec ................................................

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{
}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
// line .............................................................

Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}

Line::~Line()
{
}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a line on the screen
	pUI->DrawLine(Point1, Point2, ShpGfxInfo);
}

//Triangle................................................

Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}

//Destructor
Triangle::~Triangle()
{
}

//Draw the triangle
void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawTriangle to draw a triangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2, Corner3, ShpGfxInfo);
}

//Square.....................................
Square::Square(Point C, Point P, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Center = C;
	Corner = P;
}


Square::~Square()
{
}

//Draw the square
void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawSquare to draw a square on the screen	
	pUI->DrawSquare(Center, Corner, ShpGfxInfo);
}

//Circle...................................................................
Circle::Circle(Point C, Point E, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Center = C;
	Edge = E;
}

//Destructor
Circle::~Circle()
{
}

//Draw the circle
void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	pUI->DrawCircle(Center, Edge, ShpGfxInfo);
}


//Oval............................................
Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	Center = P1;
	Corner = P2;
}

Oval::~Oval()
{
}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawOval to draw an oval on the screen
	pUI->DrawOval(Center, Corner, ShpGfxInfo);
}


//RegularPolygon.....................................................

RegularPolygon::RegularPolygon(Point center, int radius, int count, GfxInfo shapeGfxInfo)
	: shape(shapeGfxInfo)
{
	Center = center;
	Radius = radius;
	VerticesCount = count;
}

RegularPolygon::~RegularPolygon()
{
}

void RegularPolygon::Draw(GUI* pUI) const
{
	pUI->DrawRegularPolygon(Center, Radius, VerticesCount, ShpGfxInfo);
}

//IrregularPolygon........................................

IrregularPolygon::IrregularPolygon(Point* Points, int Count, GfxInfo shapeGfxInfo)
	: shape(shapeGfxInfo)
{
	VerticesCount = Count;
	Vertices = new Point[Count];
	for (int i = 0; i < Count; i++)
		Vertices[i] = Points[i];
}

IrregularPolygon::~IrregularPolygon()
{
	delete[] Vertices;
}

void IrregularPolygon::Draw(GUI* pUI) const
{
	pUI->DrawIrregularPolygon(Vertices, VerticesCount, ShpGfxInfo);
}