#include "GUI.h"
#include "../operations/operation.h"
#include "..//controller.h"


GUI::GUI()
{

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 80;

	DrawColor = DARKGREEN;	//default Drawing color
	FillColor = YELLOW;	//default Filling color
	MsgColor = BLUE;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use it for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	//[1] If user clicks on the Toolbar
	if (y >= 0 && y < ToolBarHeight)
	{
		//Check whick Menu icon was clicked
		//==> This assumes that menu icons are lined up horizontally <==
		int ClickedIconOrder = (x / MenuIconWidth);
		//Divide x coord of the point clicked by the menu icon width (int division)
		//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

		switch (ClickedIconOrder)
		{
		case ICON_RECT: return DRAW_RECT;
		case ICON_LINE: return DRAW_LINE;
		case ICON_TRI: return DRAW_TRI;
		case ICON_CIRC: return DRAW_CIRC;
		case ICON_SQUARE: return DRAW_SQUARE;
		case ICON_OVAL: return DRAW_OVAL;
		case ICON_REGULAR_POLY: return DRAW_REGULAR_POLY;
		case ICON_IRREGULAR_POLYGON: return DRAW_IRREGULAR_POLYGON;
		case ICON_EXIT: return EXIT;

		default: return EMPTY;	//A click on empty place in desgin toolbar
		}
	}
	if (x >= 1000 && x <= 1050 && y >= 0 && y <= 25) {
		cpalette::chooseDrawColor();
		return STATUS;

	}

	if (x >= 1000 && x <= 1050 && y >= 26 && y <= 50) {
		cpalette::chooseFillColor();
		return STATUS;
	}

	//[2] User clicks on the drawing area
	if (y >= ToolBarHeight && y < height - StatusBarHeight)
	{
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;


}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar()
{

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line2.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\Menu_Tri.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_SQUARE] = "images\\MenuIcons\\Menu_Square.jpg";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\Menu_Oval.jpg";
	MenuIconImages[ICON_REGULAR_POLY] = "images\\MenuIcons\\Menu_RegularPolygon.jpg";
	MenuIconImages[ICON_IRREGULAR_POLYGON] = "images\\MenuIcons\\Menu_IrregularPolygon.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////



void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

//Drow rectangle function  ████████████████
void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

// Drow line function  _______________________________________________________

void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const
{
	color DrawingClr;
	if (LineGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width
	//الخط مالوش drawstyle (في CMU graphics)
	// Draw the line using CMU graphics library
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
}

// Draw Triangle function ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo) const
{
	color DrawingClr;
	if (TriangleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	//Draw the triangle using CMU graphics library
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

// Draw circle function 🟢🟢🟢🟢🟢🟢🟢🟢

void GUI::DrawCircle(Point Center, Point Edge, GfxInfo CircleGfxInfo) const
{
	color DrawingClr;
	if (CircleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);	//Set Drawing color & width

	//Calculate radius
	int radius = int(sqrt(pow(Edge.x - Center.x, 2) + pow(Edge.y - Center.y, 2)));

	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	//Draw the circle using CMU graphics library
	pWind->DrawCircle(Center.x, Center.y, radius, style);
}

// Draw Square function ☐☐☐☐☐☐☐☐☐

void GUI::DrawSquare(Point Center, Point Corner, GfxInfo SquareGfxInfo) const
{
	color DrawingClr;
	if (SquareGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);	//Set Drawing color & width

	//Calculate half length of the square (distance from center to corner)
	int halfLength = abs(Corner.x - Center.x);

	//Calculate square boundaries (left, right, top, bottom)
	int Left = Center.x - halfLength;
	int Right = Center.x + halfLength;
	int Top = Center.y - halfLength;
	int Bottom = Center.y + halfLength;

	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	//Draw the square using CMU graphics library
	pWind->DrawRectangle(Left, Top, Right, Bottom, style);
}

// Draw Oval function 0️0️0️0️0️0️

void GUI::DrawOval(Point Center, Point Corner, GfxInfo OvalGfxInfo) const
{
	color DrawingClr;
	if (OvalGfxInfo.isSelected)
		DrawingClr = HighlightColor;
	else
		DrawingClr = OvalGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OvalGfxInfo.BorderWdth);


	int horRadius = abs(Corner.x - Center.x);
	int verRadius = abs(Corner.y - Center.y);

	drawstyle style;
	if (OvalGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OvalGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(Center.x - horRadius, Center.y - verRadius,
		Center.x + horRadius, Center.y + verRadius, style);
}

// Draw RegularPolygon function
void GUI::DrawRegularPolygon(Point center, int radius, int vertices, GfxInfo PolyGfxInfo) const
{
	color DrawingClr;
	if (PolyGfxInfo.isSelected)
		DrawingClr = HighlightColor;
	else
		DrawingClr = PolyGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, PolyGfxInfo.BorderWdth);

	drawstyle style;
	if (PolyGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(PolyGfxInfo.FillClr);
	}
	else
		style = FRAME;

	// حساب إحداثيات الرؤوس
	int* xPoints = new int[vertices];
	int* yPoints = new int[vertices];

	double angleStep = 2 * 3.14159265 / vertices;

	for (int i = 0; i < vertices; ++i)
	{
		xPoints[i] = center.x + radius * cos(i * angleStep);
		yPoints[i] = center.y + radius * sin(i * angleStep);
	}

	pWind->DrawPolygon(xPoints, yPoints, vertices, style);

	delete[] xPoints;
	delete[] yPoints;
}

//Draw IrregularPolygon function

void GUI::DrawIrregularPolygon(Point* Points, int VerticesCount, GfxInfo IrregularPolygonGfxInfo) const
{
	color DrawingClr;
	if (IrregularPolygonGfxInfo.isSelected)
		DrawingClr = HighlightColor;
	else
		DrawingClr = IrregularPolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, IrregularPolygonGfxInfo.BorderWdth);

	drawstyle style;
	if (IrregularPolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(IrregularPolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;

	
	int* xPoints = new int[VerticesCount];
	int* yPoints = new int[VerticesCount];

	for (int i = 0; i < VerticesCount; i++)
	{
		xPoints[i] = Points[i].x;
		yPoints[i] = Points[i].y;
	}

	pWind->DrawPolygon(xPoints, yPoints, VerticesCount, style);

	delete[] xPoints;
	delete[] yPoints;
}

void GUI::DrawColorPalette()
{
	// bucket shape

	// pen shape 
	pWind->SetPen(BLACK, 5);
	pWind->DrawLine(1010, 3, 1040, 20);
	// Column 1: WHITE (top), BLACK (bottom)
	pWind->SetBrush(WHITE);  pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1050, 0, 1100, 25);

	pWind->SetBrush(BLACK);  pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1050, 25, 1100, 50);

	// Column 2: RED (top), BLUE (bottom)
	pWind->SetBrush(RED);    pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1100, 0, 1150, 25);

	pWind->SetBrush(BLUE);   pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1100, 25, 1150, 50);

	// Column 3: YELLOW (top), GREEN (bottom)
	pWind->SetBrush(YELLOW); pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1150, 0, 1200, 25);

	pWind->SetBrush(GREEN);  pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1150, 25, 1200, 50);

	// Column 4: CYAN (top), ORANGE (bottom)
	pWind->SetBrush(CYAN);   pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1200, 0, 1250, 25);

	pWind->SetBrush(ORANGE); pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1200, 25, 1250, 50);

	// Column 5: VIOLET (top), PINK (bottom)
	pWind->SetBrush(VIOLET); pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1250, 0, 1300, 25);

	pWind->SetBrush(PINK);   pWind->SetPen(BLACK, 1);
	pWind->DrawRectangle(1250, 25, 1300, 50);
}

void GUI::SetDrawColor(color c)
{
	DrawColor = c;
}

void GUI::SetFillColor(color c)
{
	FillColor = c;
}



//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

