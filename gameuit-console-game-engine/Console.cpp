#include "Console.h"

void Console::setCursorX( int x )
{
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ),
	                          {
		                          static_cast<SHORT>(x),
		                          static_cast<SHORT>(getCursorY())
	                          } );
}

int Console::getCursorX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if ( GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi ) ) {
		return csbi.dwCursorPosition.X;
	}

	return -1;
}

void Console::setCursorY( int y )
{
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ),
	                          {
		                          static_cast<SHORT>(getCursorX()),
		                          static_cast<SHORT>(y)
	                          } );
}

int Console::getCursorY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if ( GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi ) ) {
		return csbi.dwCursorPosition.Y;
	}

	return -1;
}

void Console::setCursor( int x, int y )
{
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ),
	                          {
		                          static_cast<SHORT>(x),
		                          static_cast<SHORT>(y)
	                          } );
}

COORD Console::getCursor()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if ( GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi ) ) {
		return csbi.dwCursorPosition;
	}

	return { -1,-1 };
}

void Console::setCursorVisible( bool visible )
{
	HANDLE out = GetStdHandle( STD_OUTPUT_HANDLE );

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo( out, &cursorInfo );

	cursorInfo.bVisible = visible;

	SetConsoleCursorInfo( out, &cursorInfo );
}

int Console::getPressedKey()
{
	int key = 0;
	while ( _kbhit() ) {
		key = _getch();
	}
	return key;
}

void Console::setTitle( const char* title )
{
	SetConsoleTitle( title );
}

void Console::setDisplayMode( int mode )
{
	SetConsoleDisplayMode( GetStdHandle( STD_OUTPUT_HANDLE ), mode, NULL );
}

void Console::setScreenSize( int width, int height )
{
	SMALL_RECT windowInfo = {
		0,
		0,
		static_cast<SHORT>(width - 1),
		static_cast<SHORT>(height - 1)
	};
	COORD windowSize = {
		static_cast<SHORT>(width),
		static_cast<SHORT>(height)
	};

	SetConsoleWindowInfo( GetStdHandle( STD_OUTPUT_HANDLE ), TRUE, &windowInfo );
	SetConsoleScreenBufferSize( GetStdHandle( STD_OUTPUT_HANDLE ), windowSize );
}

void Console::setTextColor( SHORT color )
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color );
}

void Console::clearScreen()
{
	system( "cls" );
}
