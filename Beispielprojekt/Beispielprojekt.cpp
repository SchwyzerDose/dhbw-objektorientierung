#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Planet.h"
#include "Vektor2d.h"



class GameWindow : public Gosu::Window
{
public:
	Gosu::Image Bild;
	GameWindow()
		: Window(800, 600), Bild("planet3.png")
		
	{
		set_caption("Gosu Tutorial Game mit Git");


	}

	double x=0;
	double y;
	double z;
	
	void draw() override
	{
		graphics().draw_line(
			x, 20, Gosu:: Color :: RED, 200, 100, Gosu::Color :: GREEN, 0.0
		);
		graphics().draw_triangle(x, y, Gosu::Color::RED, 150+x, 150, Gosu::Color::GREEN, 600, 400, Gosu::Color::BLUE, 0.0,Gosu::AlphaMode::AM_INTERPOLATE);
		Bild.draw_rot(x, y, 0.0,
			100*x/y, // Rotationswinkel in Grad
			0.5, 0.5, // Position der "Mitte" relativ zu x, y
		0.2,0.2,Gosu::Color::AQUA
		);
	}


	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		x = input().mouse_x();
		y = input().mouse_y();
		
		//x = (x + 1) % 300;
		if (input().down(Gosu::ButtonName::KB_ESCAPE)) {
			close();
		}
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}