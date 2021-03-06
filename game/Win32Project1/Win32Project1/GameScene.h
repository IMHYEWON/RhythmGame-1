#pragma once

//#include "sdl_image.h"
#include "Scene.h"
#include "Array.h"
class Sprite;
class Track;
class Font;

class GameScene : public Scene
{
private:
	//Sprite* _backgroundSprite;

	//Track* _track;
	Array<Track*>* _trackArray;
	int _gameDuration;
	int _finalScore;
	int _maxCombo;

	Font* _text;
	Font* _combo;


public:
	GameScene();
	~GameScene();

	void Init();
	void Update(int deltaTime);
	void Render();
	void Deinit();

	// Input
public:
	void KeyDown(unsigned int keyCode);
	void KeyUp(unsigned int keyCode);
};
