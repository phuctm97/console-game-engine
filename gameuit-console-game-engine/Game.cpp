#include "Game.h"

Game* Game::_instance = nullptr;

Game::Game( const std::string& title,
            int width,
            int height )
{
	setTitle( title );
	setWidth( width );
	setHeight( height );

	_exiting = false;
	_recordedClock = clock();
	_delayPerFrame = 16;
}

Game::~Game()
{
	MessageBoxA( NULL, "Game terminated\nThanks for playing GameUIT's game!", _title.c_str(), MB_ICONINFORMATION );

	delete _runningScene;
}

Game* Game::getInstance() { return _instance; }

void Game::createInstance( const std::string& title, int width, int height )
{
	_instance = new Game( title, width, height );
}

void Game::setTitle( const std::string& value )
{
	_title = value;

	Console::setTitle( _title.c_str() );
}

const std::string& Game::getTitle() const { return _title; }

void Game::setWidth( int value )
{
	if ( value < MIN_GAME_WIDTH ) value = MIN_GAME_WIDTH;
	if ( value > MAX_GAME_WIDTH ) value = MAX_GAME_WIDTH;

	_width = value;

	Console::setScreenSize( _width, _height );
}

int Game::getWidth() const { return _width; }

void Game::setHeight( int value )
{
	if ( value > MIN_GAME_HEIGHT ) value = MIN_GAME_HEIGHT;
	if ( value < MAX_GAME_HEIGHT ) value = MAX_GAME_HEIGHT;

	_height = value;

	Console::setScreenSize( _width, _height );
}

int Game::getHeight() const
{
	return _height;
}

int Game::getDelayPerFrame() const { return _delayPerFrame; }

void Game::setDelayPerFrame( int value ) { _delayPerFrame = value; }

void Game::registerInputNotification( const std::function<void( int )>& handler )
{
	_notifications.push_back( handler );
}

void Game::runWithScene( Scene* scene )
{
	_runningScene = scene;

	// clear screen
	Console::clearScreen();

	// draw window
	initWindow();

	// begin game loop
	loop();
}

void Game::exit()
{
	_exiting = true;
}

void Game::loop()
{
	for ( ;; ) {

		int pressedKey;
		processInput( pressedKey );

		// user has hit the keyboard
		if ( pressedKey != 0 ) {
			for ( auto& notification: _notifications ) {
				notification( pressedKey );
			}
		}

		if ( _exiting )break; // exit game loop

		update();

		render();

		// calculate processing delay
		int processingDelay;
		clock_t currentClock = clock();
		processingDelay = 1000 * (currentClock - _recordedClock) / CLOCKS_PER_SEC;

		// update clock
		_recordedClock = currentClock;

		// delay for seeable game
		Sleep( processingDelay > _delayPerFrame ? 0 : _delayPerFrame - processingDelay );
	}
}

void Game::processInput( int& pressedKey )
{
	pressedKey = Console::getPressedKey();
}

void Game::update()
{
	_runningScene->update();
}

void Game::render()
{
	_runningScene->render();
}

void Game::initWindow() const
{
	Console::setTitle( _title.c_str() );

	Console::setDisplayMode( ConsoleDisplayMode::WINDOWED );

	Console::setScreenSize( _width, _height );

	Console::setCursorVisible( false );
}
