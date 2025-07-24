#include "opAddRect.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddRect::opAddRect(controller* pCont) :operation(pCont)
{
}
opAddRect::~opAddRect()
{
}

//Execute the operation
void opAddRect::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Rectangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RectGfxInfo.isFilled = false;	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	Rect* R = new Rect(P1, P2, RectGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}

//Line....................................................
opAddLine::opAddLine(controller* pCont) : operation(pCont)
{
}
opAddLine::~opAddLine()
{
}

//Execute the operation
void opAddLine::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line: Click at first point");
	//Read 1st point and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First point is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second point";
	pUI->PrintMessage(msg);
	//Read 2nd point and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Prepare all line parameters
	GfxInfo LineGfxInfo;

	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pUI->getCrntDrawColor();
	LineGfxInfo.FillClr = pUI->getCrntFillColor();
	LineGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	LineGfxInfo.isFilled = false;	//default is not filled
	LineGfxInfo.isSelected = false;	//default is not selected

	//Create a line with the above parameters
	Line* L = new Line(P1, P2, LineGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the line to the list of shapes
	pGr->Addshape(L);
}

//Triangle...................................................
opAddTriangle::opAddTriangle(controller* pCont) : operation(pCont)
{
}
opAddTriangle::~opAddTriangle()
{
}

//Execute the operation
void opAddTriangle::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	pUI->PrintMessage("Click at second corner");
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);

	pUI->PrintMessage("Click at third corner");
	//Read 3rd corner and store in point P3
	pUI->GetPointClicked(P3.x, P3.y);

	pUI->ClearStatusBar();

	//Preapre all triangle parameters
	GfxInfo TriangleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pUI->getCrntFillColor();
	TriangleGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	TriangleGfxInfo.isFilled = false;	//default is not filled
	TriangleGfxInfo.isSelected = false;	//defualt is not selected

	//Create a triangle with the above parameters
	Triangle* T = new Triangle(P1, P2, P3, TriangleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the triangle to the list of shapes
	pGr->Addshape(T);
}

//Square......................................................
opAddSquare::opAddSquare(controller* pCont) : operation(pCont)
{
}

//Destructor
opAddSquare::~opAddSquare()
{
}

//Execute the operation
void opAddSquare::Execute()
{
	Point Center, Corner;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at center point");
	//Read center point and store in Center
	pUI->GetPointClicked(Center.x, Center.y);

	pUI->PrintMessage("Click at a corner point");
	//Read corner point and store in Corner
	pUI->GetPointClicked(Corner.x, Corner.y);

	pUI->ClearStatusBar();

	//Preapre all square parameters
	GfxInfo SquareGfxInfo;

	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SquareGfxInfo.FillClr = pUI->getCrntFillColor();
	SquareGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	SquareGfxInfo.isFilled = false;	//default is not filled
	SquareGfxInfo.isSelected = false;	//default is not selected

	//Create a square with the above parameters
	Square* S = new Square(Center, Corner, SquareGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the square to the list of shapes
	pGr->Addshape(S);
}

//Circle.....................................................
//Constructor
opAddCircle::opAddCircle(controller* pCont) : operation(pCont)
{
}

//Destructor
opAddCircle::~opAddCircle()
{
}

//Execute the operation
void opAddCircle::Execute()
{
	Point Center, Edge;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Circle: Click at center");
	//Read center point and store in Center
	pUI->GetPointClicked(Center.x, Center.y);

	pUI->PrintMessage("Click at a point on the edge");
	//Read edge point and store in Edge
	pUI->GetPointClicked(Edge.x, Edge.y);

	pUI->ClearStatusBar();

	//Preapre all circle parameters
	GfxInfo CircleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CircleGfxInfo.FillClr = pUI->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	CircleGfxInfo.isFilled = false;	//default is not filled
	CircleGfxInfo.isSelected = false;	//default is not selected

	//Create a circle with the above parameters
	Circle* C = new Circle(Center, Edge, CircleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the circle to the list of shapes
	pGr->Addshape(C);
}

//Ovallllllllllllllllll.....................................................

opAddOval::opAddOval(controller* pCont) : operation(pCont)
{
}
opAddOval::~opAddOval()
{
}

//Execute the operation
void opAddOval::Execute()
{
	Point P1, P2;

	//Get Input/Output interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Oval: Click at center point");
	pUI->GetPointClicked(P1.x, P1.y);

	pUI->PrintMessage("Click at a point on the oval border");
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Prepare all oval parameters
	GfxInfo OvalGfxInfo;

	OvalGfxInfo.DrawClr = pUI->getCrntDrawColor();
	OvalGfxInfo.FillClr = pUI->getCrntFillColor();
	OvalGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	OvalGfxInfo.isFilled = false;
	OvalGfxInfo.isSelected = false;

	//Create Oval and add it to the graph
	Oval* O = new Oval(P1, P2, OvalGfxInfo);
	pControl->getGraph()->Addshape(O);
}

opAddRegularPolygon::opAddRegularPolygon(controller* pCont) : operation(pCont) {}
opAddRegularPolygon::~opAddRegularPolygon() {}

void opAddRegularPolygon::Execute()
{
	Point Center, Vertex;
	int Radius;

	GUI* pUI = pControl->GetUI();

	
	pUI->PrintMessage("New Regular Polygon: Click at center");
	pUI->GetPointClicked(Center.x, Center.y);

	
	pUI->PrintMessage("Click at a vertex to determine radius");
	pUI->GetPointClicked(Vertex.x, Vertex.y);

	
	Radius = static_cast<int>(sqrt(pow(Vertex.x - Center.x, 2) + pow(Vertex.y - Center.y, 2)));

	
	pUI->PrintMessage("Enter number of sides (3 or more): ");
	string input = pUI->GetSrting();

	
	bool isNumber = true;
	for (char c : input)
	{
		if (!isdigit(c))
		{
			isNumber = false;
			break;
		}
	}

	if (!isNumber)
	{
		pUI->PrintMessage("Invalid input! Please enter a valid number.");
		return;
	}

	int VerticesCount = stoi(input);

	if (VerticesCount < 3)
	{
		pUI->PrintMessage("Error: Number of sides must be 3 or more.");
		return;
	}

	pUI->ClearStatusBar();

	
	GfxInfo PolyGfxInfo;
	PolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	PolyGfxInfo.FillClr = pUI->getCrntFillColor();
	PolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	PolyGfxInfo.isFilled = false;
	PolyGfxInfo.isSelected = false;

	
	RegularPolygon* P = new RegularPolygon(Center, Radius, VerticesCount, PolyGfxInfo);

	Graph* pGr = pControl->getGraph();
	pGr->Addshape(P);
}

//IrregularPolygon............................................

opAddIrregularPolygon::opAddIrregularPolygon(controller* pCont) : operation(pCont)
{
}
opAddIrregularPolygon::~opAddIrregularPolygon()
{
}

void opAddIrregularPolygon::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	pUI->PrintMessage("Enter number of vertices:");
	string input = pUI->GetSrting();
	int count = stoi(input);

	if (count < 3) {
		pUI->PrintMessage("Polygon must have at least 3 vertices.");
		return;
	}

	Point* points = new Point[count];

	for (int i = 0; i < count; i++)
	{
		string msg = "Click point " + to_string(i + 1);
		pUI->PrintMessage(msg);
		pUI->GetPointClicked(points[i].x, points[i].y);
	}

	pUI->ClearStatusBar();

	GfxInfo polyGfxInfo;
	polyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	polyGfxInfo.FillClr = pUI->getCrntFillColor();
	polyGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	polyGfxInfo.isFilled = false;
	polyGfxInfo.isSelected = false;

	IrregularPolygon* P = new IrregularPolygon(points, count, polyGfxInfo);
	pGr->Addshape(P);

	delete[] points;
}
