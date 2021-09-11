#include "Header.h"

std::vector<std::vector<node>> grid;
std::vector<std::vector<node>> saveGrid;


int startLife(int x, int y) {
	int count = 0;
	//Middle
	if (x > 0 && y > 0 && x < windowx / nodeSize - 1 && y < (windowy - 200) / nodeSize - 1) {
		//Up Left
		if (grid[x - 1][y - 1].rect.getFillColor() == sf::Color::White) { count += 1;}
		//Left
		if (grid[x - 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
		//Down Left
		if (grid[x - 1][y + 1].rect.getFillColor() == sf::Color::White) { count += 1;}
		//Up
		if (grid[x][y - 1].rect.getFillColor() == sf::Color::White) { count += 1;}
		//Down
		if (grid[x][y + 1].rect.getFillColor() == sf::Color::White) { count += 1;}
		//Up Right
		if (grid[x + 1][y - 1].rect.getFillColor() == sf::Color::White) { count += 1;}
		//Right
		if (grid[x + 1][y].rect.getFillColor() == sf::Color::White) { count += 1;}
		//Down Right
		if (grid[x + 1][y + 1].rect.getFillColor() == sf::Color::White) { count += 1;}
	}
	//Top Line Excl. Corners
	if (x > 0 && y == 0 && x < windowx / nodeSize - 1) {
		if (grid[x - 1][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x + 1][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x - 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x + 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
	}
	//Bottom Line Excl. Corners
	if (x > 0 && x < windowx / nodeSize - 1 && y == (windowy - 200) / nodeSize - 1) {
		if (grid[x - 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x + 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x + 1][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x - 1][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
	}
	//Left Side Excl. Corners
	if (x == 0 && y > 0 && y < (windowy - 200) / nodeSize - 1) {
		if (grid[x][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x + 1][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x + 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x + 1][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
	}
	//Right Side Excl. Corners
	if (y > 0 && x == windowx / nodeSize - 1 && y < (windowy - 200) / nodeSize - 1) {
		if (grid[x - 1][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x - 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x - 1][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
	}
	//Top Left Corner
	if (x == 0 && y == 0) {
		if (grid[x + 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x + 1][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }


	}
	//Top Right Corner
	if (x == windowx / nodeSize - 1 && y == 0) {
		if (grid[x][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x - 1][y + 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x - 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }


	}
	//Bottom Left Corner
	if (x == 0 && y == (windowy - 200) / nodeSize - 1) {
		if (grid[x + 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x + 1][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
	}
	//Bottom Right Corner
	if (x == windowx / nodeSize - 1 && y == (windowy - 200) / 10 - 1) {
		if (grid[x - 1][y].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x - 1][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
		if (grid[x][y - 1].rect.getFillColor() == sf::Color::White) { count += 1; }
	}
	return count;

	



}
void drawWindow() {
	for (int i = 0; i < windowx/nodeSize; i++) {
		for (int j = 0; j < (windowy-200)/nodeSize; j++) {
			float x = (rectSize.x) * i;
			float y = (rectSize.y) * j;
			grid[i][j].rect.setPosition(x, y);
			window.draw(grid[i][j].rect);
		}
	}
}
void changeColor() {
	for (int i = 0; i < windowx / nodeSize; i++) {
		for (int j = 0; j < (windowy - 200) / nodeSize; j++) {
			if(grid[i][j].change){
				if (grid[i][j].rect.getFillColor()==sf::Color::White) {
					grid[i][j].rect.setFillColor(sf::Color::Blue);
					window.draw(grid[i][j].rect);
					//grid[i][j].change = false;
				}
				else {
					grid[i][j].rect.setFillColor(sf::Color::White);
					window.draw(grid[i][j].rect);
				}
				grid[i][j].change = false;
			}
		}
	}
	//drawWindow();
}
void clear() {
	for (int i = 0; i < windowx / nodeSize; i++) {
		for (int j = 0; j < (windowy - 200) / nodeSize; j++) {
			grid[i][j].rect.setFillColor(sf::Color::Blue);
			window.draw(grid[i][j].rect);
			grid[i][j].change = false;
		}
	}
}
void save() {
	saveGrid = grid;
}
void load() {
	std::cout << "Error Drawing Grid" << std::endl;
	for (int i = 0; i < windowx / nodeSize; i++) {
		for (int j = 0; j < (windowy - 200) / nodeSize; j++) {
			float x = (rectSize.x) * i;
			float y = (rectSize.y) * j;
			grid[i][j] = saveGrid[i][j];
			saveGrid[i][j].rect.setPosition(x, y);
			window.draw(saveGrid[i][j].rect);
		}
	}

}
void mainLoop() {
	sf::Vector2f rectSize = { 10,10 };

	sf::RectangleShape srect({ 100,40 });
	srect.setFillColor(sf::Color::Blue);
	srect.setOutlineColor(sf::Color::Cyan);
	srect.setOutlineThickness(1.0f);
	srect.setPosition(windowx / 2, windowy - 100);
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Font File Didn't Load" << std::endl;
	}
	sf::Text text, text2,text3,text4, text5;
	text.setFont(font);
	text.setString("Start");
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Red);

	text2.setFont(font);
	text2.setString("Stop");
	text2.setCharacterSize(20);
	text2.setFillColor(sf::Color::Red);

	text3.setFont(font);
	text3.setString("Load");
	text3.setCharacterSize(20);
	text3.setFillColor(sf::Color::Red);

	text4.setFont(font);
	text4.setString("Save");
	text4.setCharacterSize(20);
	text4.setFillColor(sf::Color::Red);

	text5.setFont(font);
	text5.setString("Clear");
	text5.setCharacterSize(20);
	text5.setFillColor(sf::Color::Red);

	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(windowx / 2 + 25, windowy - 140);
	text2.setPosition(windowx / 2 - 125, windowy - 140);
	text3.setPosition(windowx / 2 +25, windowy - 50);
	text4.setPosition(windowx / 2 - 125, windowy - 50);
	text5.setPosition(windowx / 2 +175, windowy - 140);





	node n1, n3;

	node n2 = node(windowx / 2 -200, windowy -150, srect);
	node n4 = node(windowx / 2, windowy - 100, srect);
	node n5 = node(windowx / 2, windowy - 100, srect);
	node n6 = node(windowx / 2, windowy - 100, srect);
	node n7 = node(windowx / 2, windowy - 100, srect);
	n2.rect.setPosition(windowx / 2, windowy - 150);
	n4.rect.setPosition(windowx / 2 - 150, windowy - 150);
	n5.rect.setPosition(windowx / 2, windowy - 60);
	n6.rect.setPosition(windowx / 2 - 150, windowy - 60);
	n7.rect.setPosition(windowx / 2 + 150, windowy - 150);
	std::vector<node> v1;
	for (int i = 0; i < windowx / nodeSize; i++) {
		std::vector<node> v1;

		for (int j = 0; j < (windowy - 200) / nodeSize; j++) {
			sf::RectangleShape rect(rectSize);
			rect.setFillColor(sf::Color::Blue);
			rect.setOutlineColor(sf::Color::Cyan);
			rect.setOutlineThickness(1.0f);
			n1.rect = rect;
			n1.xPos = i;
			n1.yPos = j;
			n1.change = false;
			v1.push_back(n1);
		}
		grid.push_back(v1);
	}
	//v1.push_back(n2);
	grid.push_back(v1);
	drawWindow();


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
				mousex = event.mouseButton.x;
				mousey = event.mouseButton.y;
				if (mousey < windowy - 200) {
					while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
						mousex = sf::Mouse::getPosition(window).x;
						mousey = sf::Mouse::getPosition(window).y;
						int gridx = (mousex / nodeSize);
						int gridy = (mousey / nodeSize);
						//std::cout << mousex << " " << mousey << std::endl;
						grid[gridx][gridy].rect.setFillColor(sf::Color::Blue);
						drawWindow();
						window.display();
					}
				}


			}
			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				mousex = event.mouseButton.x;
				mousey = event.mouseButton.y;
				//int mousedown = 0;
				//std::cout << mousex << "  " << mousey << std::endl;
				//if start button pressed
				if (mousey > windowy - 200&& mousey < windowy - 100&& mousex > windowx / 2 && mousex < windowx / 2 + 100) {
					int deadCells = 0;
					int repeatCount = 0;
					int oldDc = 0;

					while (deadCells < 3200 && repeatCount<500 ) {
						Sleep(20);
						for (int i = 0; i < windowx / nodeSize; i++) {

							for (int j = 0; j < (windowy - 200) / nodeSize; j++) {
								
									int count = startLife(i, j);
								
									if (grid[i][j].rect.getFillColor() == sf::Color::Blue) {
										if (count == 3) {
											//std::cout << "Change " << i << " " << j << " to White" << std::endl;
											grid[i][j].change = true;
											//window.draw(grid[i][j].rect);
										}
										else {
											deadCells += 1;
										}
									}
									if (grid[i][j].rect.getFillColor() == sf::Color::White) {
										if (count < 2 || count>3) {
											//std::cout << "Change " << i << " " << j << " to Blue" << std::endl;
											grid[i][j].change = true;
											//std::cout << i<<" "<<j << std::endl;
											//window.draw(grid[i][j].rect);
										}
										else {
											deadCells += 1;
										}
									}
								}
								
								//window.display();


							
						}

						//std::cout << keyState << std::endl;
						changeColor();
						
						if (deadCells < 3200) {
							if (oldDc == deadCells) {
								repeatCount += 5;
							}
							else {
								repeatCount = 0;
							}
							oldDc = deadCells;

							deadCells = 0;
						}
						window.display();
					}
					if (repeatCount > 50) {
						std::cout << "Pattern keeps repeating from this point." << std::endl;
					}
					else {
						std::cout << "0 live cells remaining" << std::endl;
					}
					stop = false;
				}
				//clear button pressed
				else if (mousey > windowy - 200 && mousey < windowy - 100 && mousex > windowx / 2 + 150 && mousex < windowx / 2 + 250) {
					clear();
				}
				//save button pressed
				else if (mousey > windowy - 110 && mousey < windowy - 10 && mousex > windowx / 2 -150 && mousex < windowx / 2 -50) {
					save();
				}
				//load button pressed
				else if (mousey > windowy - 110 && mousey < windowy - 10 && mousex > windowx / 2 && mousex < windowx / 2 + 100) {
					load();
				}
				//colouring in 
				else if (mousey < windowy - 200) {
					while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
						mousex = sf::Mouse::getPosition(window).x;
						mousey = sf::Mouse::getPosition(window).y;
						int gridx = (mousex / nodeSize);
						int gridy = (mousey / nodeSize);
						//std::cout << mousex << " " << mousey << std::endl;
						grid[gridx][gridy].rect.setFillColor(sf::Color::White);
						drawWindow();
						window.display();
					}

				}


			}

			window.draw(n2.rect);
			window.draw(n4.rect);
			window.draw(n5.rect);
			window.draw(n6.rect);
			window.draw(n7.rect);
			window.draw(text);
			window.draw(text2);
			window.draw(text3);
			window.draw(text4);
			window.draw(text5);
			window.display();
		}

	}
}
int main() {
	//sf::Thread th1(&mainLoop);
	//sf::Thread th2(&checkBool);

	//th1.launch();
	//th2.launch();
	mainLoop();
	//keyState = GetKeyState(VK_ESCAPE);

	return 0;
	
}
