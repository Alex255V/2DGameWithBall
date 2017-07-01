#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;


/*
class PLAYER {
public:
	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float  currentFrame;

	PLAYER(Texture &image) {
		sprite.setTexture(image);
		rect = FloatRect(0, 0, 80, 80);

		dx = dy = 0;
		currentFrame = 0;
	}
	*/
/*
	void update(float time) {
		rect.left += dx*time;
		if (!onGround) dy = dy + 0.0005*time;
		rect.top += dy*time;
		onGround = false;
		if (rect.top > ground) { rect.top = ground; dy = 0; onGround = true; }

		currentFrame += 0.005*time;
		if (currentFrame > 4) currentFrame -= 4;

		if (dx > 0) sprite.setTextureRect(IntRect(80 * int(currentFrame), 0, 80, 80));
		if (dx<0) sprite.setTextureRect(IntRect(80 * int(currentFrame) + 80, 0, -80, 80));

		sprite.setPosition(rect.left, rect.top);

		dx = 0;
	}
*/

//};


int main()
{
	float horizontally = 600/2;
	float vertically = 400/2;

	RenderWindow window(VideoMode(600, 400), "Whindow Game");


	Texture te;
	te.loadFromFile("Sprite.png");

	

	float currentFrame1 = 0;
	float currentFrame2 = 0;
	float currentFrame3 = 0;

	
	Sprite l1,l2,l3;//, r, t, b;
	Sprite s;
	s.setTexture(te);
	s.setTextureRect(IntRect(0, 0, 25, 25));
	s.setPosition(600/2, 400/2);

	l1.setTexture(te);
	l1.setTextureRect(IntRect(26, 0, 30, 9));

	l2.setTexture(te);
	l2.setTextureRect(IntRect(26, 22, 30, 9));

	l3.setTexture(te);
	l3.setTextureRect(IntRect(26, 33, 30, 9));
	/*/
	r.setTexture(te);
	r.setTextureRect(IntRect(26, 0, 30, 9));

	t.setTexture(te);
	t.setTextureRect(IntRect(26, 0, 30, 9));

	b.setTexture(te);
	b.setTextureRect(IntRect(26, 0, 30, 9));
	//b.setPosition(10,20);
	*/
	Clock clock;


	int left1 = 0;
	int left2 = 0;
	int left3 = 0;



	while (window.isOpen())
	{ 
		srand(time(NULL));

		float timef = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		timef = timef / 250;

		currentFrame1 += 0.05*timef; 
		currentFrame2 += 0.09*timef; 
		currentFrame3 += 0.07*timef; 

		int rnd = 1 + rand() % 4;


		if (currentFrame1 < 10) left1 = 5 + rand() % 390; 
		if (currentFrame1 > 595) currentFrame1 = 0;

		if (currentFrame2 < 10) left2 = 5 + rand() % 390;
		if (currentFrame2 > 595) currentFrame2 = 0;

		if (currentFrame3 < 10) left3 = 5 + rand() % 390;
		if (currentFrame3 > 595) currentFrame3 = 0;

		
		

		/*
		l.setPosition(currentFrame, 10 + rand() % 550);
		r.setPosition(currentFrame+=0.03, 10 + rand() % 550);
		t.setPosition(currentFrame+=0.01, 10 + rand() % 550);
		b.setPosition(currentFrame+=0.02, 10 + rand() % 550);
		*/
		/*
		int left = 1 + rand() % 10;
		int right = 1 + rand() % 10;
		int top = 1 + rand() % 10;
		int bot = 1 + rand() % 10;
		*/

		//system("pause");
		

		
		l1.setPosition(currentFrame1, left1);
		l2.setPosition(currentFrame2, left2);
		l3.setPosition(currentFrame3, left3);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) 
				window.close();	
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (horizontally > 0) {
				s.move(-0.1*timef, 0); 
				horizontally -= 0.1*timef;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (horizontally < 575) {
				s.move(0.1*timef, 0);
				horizontally += 0.1*timef;
			}
			
		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (vertically > 0) {
				s.move(0, -0.1*timef);
				vertically -= 0.1*timef;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (vertically < 375) {
				s.move(0, 0.1*timef);
				vertically += 0.1*timef;
			}
		}

		


		
		//l.move(0.15*timef, 0);

		window.clear();

		window.draw(s);

		window.draw(l1);
		window.draw(l2);
		window.draw(l3);
		
		window.display();
	}

	return 0;
}