﻿#pragma once

//loji

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
};




class GUI
{
	enum MenuIcon //The icons of the menu (you should add more icons)
	{
		///Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_TRI,		//Triangle icon in menu
		ICON_LINE,//────
		ICON_CIRC,
		ICON_SQUARE,
		ICON_OVAL,
		ICON_REGULAR_POLY,
		ICON_IRREGULAR_POLYGON,


		//TODO: Add more icons names here

		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};




	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle

	///Make similar functions for drawing all other shapes.

	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const;  //Draw a line
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo) const;
	void DrawCircle(Point Center, Point Edge, GfxInfo CircleGfxInfo) const;
	void DrawSquare(Point Center, Point Corner, GfxInfo SquareGfxInfo) const;
	void DrawOval(Point Center, Point Corner, GfxInfo OvalGfxInfo) const;
	void DrawRegularPolygon(Point center, int radius, int vertices, GfxInfo PolyGfxInfo) const;
	void DrawIrregularPolygon(Point* Points, int VerticesCount, GfxInfo IrregularPolygonGfxInfo) const;




	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~GUI();
};

