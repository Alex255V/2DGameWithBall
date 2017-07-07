#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace sf;

const int width = 800;
const int height = 500;

float horizontally = width / 2;
float vertically = height / 2;

bool game = true;

float currentFrame1 = 0;
float currentFrame2 = 0;
float currentFrame3 = 0;

float currentFrameR1 = 800;
float currentFrameR2 = 800;
float currentFrameR3 = 800;

float currentFrameU1 = 0;
float currentFrameU2 = 0;
float currentFrameU3 = 0;
float currentFrameU4 = 0;

Sprite ball;
Sprite block1, block2, block3;
Sprite blockR1, blockR2, blockR3;
Sprite blockU1, blockU2, blockU3, blockU4;
int timer = 0;

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

class BLOCKR1 {
public:
	BLOCKR1(Texture &image) {
		blockR1.setTexture(image);
		blockR1.setTextureRect(IntRect(26, 33, 55 - 26, 42 - 33));
	}
	void move(float currentFrameR1, int leftR1) {
		blockR1.setPosition(currentFrameR1, leftR1);
	}
};

class BLOCKR2 {
public:
	BLOCKR2(Texture &image) {
		blockR2.setTexture(image);
		blockR2.setTextureRect(IntRect(26, 33, 55 - 26, 42 - 33));
	}
	void move(float currentFrameR2, int leftR2) {
		blockR2.setPosition(currentFrameR2, leftR2);
	}
};

class BLOCKR3 {
public:
	BLOCKR3(Texture &image) {
		blockR3.setTexture(image);
		blockR3.setTextureRect(IntRect(26, 33, 55 - 26, 42 - 33));
	}
	void move(float currentFrameR3, int leftR3) {
		blockR3.setPosition(currentFrameR3, leftR3);
	}
};

class BLOCKUP1 {
public:
	BLOCKUP1(Texture &image) {
		blockU1.setTexture(image);
		blockU1.setTextureRect(IntRect(60, 0, 10, 30));
	}
	void move(int UP1, float currentFrameU1) {
		blockU1.setPosition(UP1, currentFrameU1);
	}
};

class BLOCKUP2 {
public:
	BLOCKUP2(Texture &image) {
		blockU2.setTexture(image);
		blockU2.setTextureRect(IntRect(60, 0, 10, 30));
	}
	void move(int UP2, float currentFrameU2) {
		blockU2.setPosition(UP2, currentFrameU2);
	}
};

class BLOCKUP3 {
public:
	BLOCKUP3(Texture &image) {
		blockU3.setTexture(image);
		blockU3.setTextureRect(IntRect(60, 0, 10, 30));
	}
	void move(int UP3, float currentFrameU3) {
		blockU3.setPosition(UP3, currentFrameU3);
	}
};

class BLOCKUP4 {
public:
	BLOCKUP4(Texture &image) {
		blockU4.setTexture(image);
		blockU4.setTextureRect(IntRect(60, 0, 10, 30));
	}
	void move(int UP4, float currentFrameU4) {
		blockU4.setPosition(UP4, currentFrameU4);
	}
};

class BALL {
public:

	BALL(Texture &image) {
		ball.setTexture(image);
		ball.setTextureRect(IntRect(0, 0, 25, 25));
		ball.setPosition(width / 2 - 25, height / 2 - 25);
	}
	int i = 0;
	void impact(float horizontally, float vertically, int leftP1, int leftP2, int leftP3, int leftR1, int leftR2, int leftR3, int UP1, int UP2, int UP3, int UP4) {
		if (((horizontally > currentFrame1) && (horizontally < currentFrame1 + 55)) && ((vertically > leftP1) && (vertically < leftP1 + 35))) {
			game = false;
		}
		if (((horizontally > currentFrame2) && (horizontally < currentFrame2 + 55)) && ((vertically > leftP2) && (vertically < leftP2 + 35))) {
			game = false;
		}
		if (((horizontally > currentFrame3) && (horizontally < currentFrame3 + 55)) && ((vertically > leftP3) && (vertically < leftP3 + 35))) {
			game = false;
		}
		//-> right
		if (((horizontally > currentFrameR1) && (horizontally < currentFrameR1 + 55)) && ((vertically > leftR1) && (vertically < leftR1 + 35))) {
			game = false;
		}
		if (((horizontally > currentFrameR2) && (horizontally < currentFrameR2 + 55)) && ((vertically > leftR2) && (vertically < leftR2 + 35))) {
			game = false;
		}
		if (((horizontally > currentFrameR3) && (horizontally < currentFrameR3 + 55)) && ((vertically > leftR3) && (vertically < leftR3 + 35))) {
			game = false;
		}
		//-> UP
		if (((horizontally > UP1) && (horizontally <UP1 + 35)) && ((vertically > currentFrameU1) && (vertically < currentFrameU1 + 55))) {
			game = false;
		}
		if (((horizontally > UP2) && (horizontally < UP2 + 35)) && ((vertically > currentFrameU2) && (vertically < currentFrameU2 + 55))) {
			game = false;
		}
		if (((horizontally > UP3) && (horizontally < UP3 + 35)) && ((vertically > currentFrameU3) && (vertically < currentFrameU3 + 55))) {
			game = false;
		}
		if (((horizontally > UP4) && (horizontally < UP4 + 35)) && ((vertically > currentFrameU4) && (vertically < currentFrameU4 + 55))) {
			game = false;
		}
	}
};

void END(int timerInt) {
	char buff[16];
	game = true;
	_itoa_s(timerInt, buff, 10);
	MessageBox(NULL, (LPCTSTR)buff, "Your Time:", MB_OK);
}

int main() {

	RenderWindow window(VideoMode(width, height), "Window of Game");

	Texture sprite;
	sprite.loadFromFile("Sprite.png");

	BALL CBall(sprite);
	BLOCK1 CBlock1(sprite);
	BLOCK2 CBlock2(sprite);
	BLOCK3 CBlock3(sprite);

	BLOCKR1 CBlockR1(sprite);
	BLOCKR2 CBlockR2(sprite);
	BLOCKR3 CBlockR3(sprite);

	BLOCKUP1 CBlockUP1(sprite);
	BLOCKUP2 CBlockUP2(sprite);
	BLOCKUP3 CBlockUP3(sprite);
	BLOCKUP4 CBlockUP4(sprite);

	Clock clock;
	Clock timer;

	int leftP1 = 300;
	int leftP2 = 40;
	int leftP3 = 180;

	int leftR1 = 100;
	int leftR2 = 400;
	int leftR3 = 150;

	int UP1 = 150;
	int UP2 = 400;
	int UP3 = 350;
	int UP4 = 625;

	srand(time(NULL));
	Event event;

	while (window.isOpen()) {

		int timerInt = timer.getElapsedTime().asSeconds();

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 250;

		currentFrame1 += 0.06*time;
		currentFrame2 += 0.05*time;
		currentFrame3 += 0.08*time;

		currentFrameR1 -= 0.06*time;
		currentFrameR2 -= 0.05*time;
		currentFrameR3 -= 0.08*time;

		currentFrameU1 += 0.05*time;
		currentFrameU2 += 0.04*time;
		currentFrameU3 += 0.07*time;
		currentFrameU4 += 0.06*time;

		if (currentFrame1 < -25) leftP1 = 0 + rand() % height;
		if (currentFrame1 > width) currentFrame1 = -30;
		if (currentFrame2 < -25) leftP2 = 0 + rand() % height;
		if (currentFrame2 > width) currentFrame2 = -30;
		if (currentFrame3 < -25) leftP3 = 0 + rand() % height;
		if (currentFrame3 > width) currentFrame3 = -30;

		if (currentFrameR1 > width) leftR1 = 0 + rand() % height;
		if (currentFrameR1 < -25) currentFrameR1 = width + 30;
		if (currentFrameR2 > width) leftR2 = 0 + rand() % height;
		if (currentFrameR2 < -25) currentFrameR2 = width + 30;
		if (currentFrameR3 > width) leftR3 = 0 + rand() % height;
		if (currentFrameR3 < -25) currentFrameR3 = width + 30;

		if (currentFrameU1 < -25) UP1 = 0 + rand() % width;
		if (currentFrameU1 > height) currentFrameU1 = -30;
		if (currentFrameU2 < -25) UP2 = 0 + rand() % width;
		if (currentFrameU2 > height) currentFrameU2 = -30;
		if (currentFrameU3 < -25) UP3 = 0 + rand() % width;
		if (currentFrameU3 > height) currentFrameU3 = -30;
		if (currentFrameU4 < -25) UP4 = 0 + rand() % width;
		if (currentFrameU4 > height) currentFrameU4 = -30;

		if (game == false) {
			END(timerInt);
			timer.restart();
		}

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		CBall.impact(horizontally, vertically, leftP1, leftP2, leftP3, leftR1, leftR2, leftR3, UP1, UP2, UP3, UP4);

		CBlock1.move(currentFrame1, leftP1);
		CBlock2.move(currentFrame2, leftP2);
		CBlock3.move(currentFrame3, leftP3);

		CBlockR1.move(currentFrameR1, leftR1);
		CBlockR2.move(currentFrameR2, leftR2);
		CBlockR3.move(currentFrameR3, leftR3);

		CBlockUP1.move(UP1, currentFrameU1);
		CBlockUP2.move(UP2, currentFrameU2);
		CBlockUP3.move(UP3, currentFrameU3);
		CBlockUP4.move(UP4, currentFrameU4);

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

		window.draw(blockR1);
		window.draw(blockR2);
		window.draw(blockR3);

		window.draw(blockU1);
		window.draw(blockU2);
		window.draw(blockU3);
		window.draw(blockU4);

		window.display();
	}

	return 0;
}
