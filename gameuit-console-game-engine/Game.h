#ifndef __GAME_H__
#define __GAME_H__

#include <string>
#include <sstream>
#include <functional>
#include <ctime>
#include "Scene.h"

#define MIN_GAME_WIDTH 50
#define MAX_GAME_WIDTH 100
#define MIN_GAME_HEIGHT 20
#define MAX_GAME_HEIGHT 50

#define CC_CALLBACK_1(func, target) std::bind( &func, target, std::placeholders::_1 )

class Game
{
private:
	clock_t _recordedClock;

	// Properties
	Scene *_runningScene;

	std::string _title;

	int _width;

	int _height;

	int _delayPerFrame;

	bool _exiting;

	std::vector<std::function<void( int )>> _notifications;

	static Game* _instance;

public:
	// Constructor
	Game( const std::string& title = "GameUIT",
	      int width = 50,
	      int height = 20 );

	// Destructor
	~Game();

	static Game* getInstance();

	static void createInstance( const std::string& title,
	                            int width,
	                            int height );

	// Getters, Setters
	void setTitle( const std::string& value );

	const std::string& getTitle() const;

	void setWidth( int value );

	int getWidth() const;

	void setHeight( int value );

	int getHeight() const;

	int getDelayPerFrame() const;

	void setDelayPerFrame( int value );

	void registerInputNotification( const std::function<void( int )>& handler );

	// Run function
	void runWithScene( Scene* scene );

	void exit();

private:
	// Game loop
	void loop();

	void processInput( int& pressedKey );

	void update();

	void render();

private:
	// Helper functions
	void initWindow() const;
};

#endif
