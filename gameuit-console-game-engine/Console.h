#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <windows.h>
#include <conio.h>

enum ConsoleDisplayMode
{
	FULLSCREEN = CONSOLE_FULLSCREEN_MODE,
	WINDOWED = CONSOLE_WINDOWED_MODE
};

enum ConsoleTextColor
{
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_CYAN,
	DARK_RED,
	DARK_MAGENTA,
	DARK_YELLOW,
	GRAY,
	DRAK_GRAY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE
};

// Helper class to access Console properties
class Console
{
public:
	static int getCursorX();

	static int getCursorY();

	static COORD getCursor();

	static int getPressedKey();

	static void setCursorX( int x );

	static void setCursorY( int y );

	static void setCursor( int x, int y );

	static void setCursorVisible( bool visible );

	static void setTitle( const char* title );

	static void setDisplayMode( int mode );

	static void setScreenSize( int width, int height );

	static void setTextColor( SHORT color );

	static void clearScreen();
};

#endif //!__CONSOLE_H__
