#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <windows.h>
#include <thread>
int nodeSize = 10;
int windowx = 800;
int windowy = 600;
bool stop = false;
SHORT keyState;
SHORT escState;
float mousex;
float mousey;
sf::RenderWindow window(sf::VideoMode(windowx, windowy), "My window");
sf::Vector2f rectSize = { 10,10 };

sf::RectangleShape srect({ 100,40 });


struct node {
	int xPos, yPos;
	bool change;
	sf::RectangleShape rect;
	node() {};
	node(int x, int y, sf::RectangleShape r) {
		xPos = x;
		yPos = y;
		rect = r;
	};
	node(int x, int y, sf::RectangleShape r, bool c) {
		xPos = x;
		yPos = y;
		rect = r;
		change = c;
	};

};
void changeColor();
void drawWindow();
void mainLoop();
void clear();
void save();
void load();
std::vector<std::vector<node>>;
int startLife(int x, int y);

int main();