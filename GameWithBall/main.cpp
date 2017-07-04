#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;

const int width = 800;
const int height = 500;

float horizontally = width / 2;
float vertically = height / 2;

float currentFrame1 = 0;
float currentFrame2 = 0;
float currentFrame3 = 0;

Sprite ball;
Sprite block1, block2, block3;

class BLOCK1 {
public:
	BLOCK1(Texture &image) {
		block1.setTexture(image);
		block1.setTextureRect(IntRect(26, 33, 55 - 26, 42 - 33));
	}
	void move(float currentFrame1, int leftP1) {
		block1.setPosition(currentFrame1, leftP1);
	}
};

class BLOCK2 {
public:
	BLOCK2(Texture &image) {
		block2.setTexture(image);
		block2.setTextureRect(IntRect(26, 33, 55 - 26, 42 - 33));
	}
	void move(float currentFrame2, int leftP2) {
		block2.setPosition(currentFrame2, leftP2);
	}
};

class BLOCK3 {
public:
	BLOCK3(Texture &image) {
		block3.setTexture(image);
		block3.setTextureRect(IntRect(26, 33, 55 - 26, 42 - 33));
	}
	void move(float currentFrame3, int leftP3) {
		block3.setPosition(currentFrame3, leftP3);
	}
};

class BALL {
public:
	BALL(Texture &image) {
		ball.setTexture(image);
		ball.setTextureRect(IntRect(0, 0, 25, 25));
		ball.setPosition(width / 2 - 25, height / 2 - 25);
	}

	void impact(float horizontally, float vertically, int leftP1, int leftP2, int leftP3) {
		if (((horizontally > currentFrame1) && (horizontally < currentFrame1 + 55)) && ((vertically > leftP1) && (vertically < leftP1 + 35))) {
			system("pause");
		}
		if (((horizontally > currentFrame2) && (horizontally < currentFrame2 + 55)) && ((vertically > leftP2) && (vertically < leftP2 + 35))) {
			system("pause");
		}
		if (((horizontally > currentFrame3) && (horizontally < currentFrame3 + 55)) && ((vertically > leftP3) && (vertically < leftP3 + 35))) {
			system("pause");
		}
	}
};

int main() {

	RenderWindow window(VideoMode(width, height), "Window Game");

	Texture sprite;
	sprite.loadFromFile("Sprite.png");

	BALL CBall(sprite);
	BLOCK1 CBlock1(sprite);
	BLOCK2 CBlock2(sprite);
	BLOCK3 CBlock3(sprite);

	Clock clock;

	int leftP1 = 300;
	int leftP2 = 40;
	int leftP3 = 180;

	srand(time(NULL));
	Event event;
	while (window.isOpen()) {

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 250;

		currentFrame1 += 0.05*time;
		currentFrame2 += 0.04*time;
		currentFrame3 += 0.07*time;

		if (currentFrame1 < -25) leftP1 = 0 + rand() % height;
		if (currentFrame1 > width) currentFrame1 = -30;

		if (currentFrame2 < -25) leftP2 = 0 + rand() % height;
		if (currentFrame2 > width) currentFrame2 = -30;

		if (currentFrame3 < -25) leftP3 = 0 + rand() % height;
		if (currentFrame3 > width) currentFrame3 = -30;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		CBall.impact(horizontally, vertically, leftP1, leftP2, leftP3);

		CBlock1.move(currentFrame1, leftP1);
		CBlock2.move(currentFrame2, leftP2);
		CBlock3.move(currentFrame3, leftP3);

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (horizontally > 25) {
				ball.move(-0.1*time, 0);
				horizontally -= 0.1*time;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (horizontally < width) {
				ball.move(0.1*time, 0);
				horizontally += 0.1*time;
			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (vertically > 25) {
				ball.move(0, -0.1*time);
				vertically -= 0.1*time;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (vertically < height) {
				ball.move(0, 0.1*time);
				vertically += 0.1*time;
			}
		}

		window.clear();
		window.draw(ball);

		window.draw(block1);
		window.draw(block2);
		window.draw(block3);

		window.display();
	}


	return 0;
}
