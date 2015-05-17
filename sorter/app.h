#ifndef APP_H
#define APP_H
#include "SDL2/SDL.h"
#include "column.h"
#include "listener.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

/**
 * @class App
 * @author Dorka
 * @file app.h
 * @brief App class
 * responsible for proper SDL initing, closing and rendering
 * implements the ColumnListener interface 
 */

class App : public ColumnListener
{
private:
	
    SDL_Renderer* renderer; ///< SDL Renderer for rendering
    SDL_Window* window; ///< SDL window
	
	SDL_Rect textRect; ///< text area
	TTF_Font* font; ///< font for writing
	SDL_Texture* textTexture; ///< texture used to render text
	SDL_Surface* textSurface ; ///< used to write on it, and generate Texture from it

    Column* columns; ///< array of Columns
	size_t size; ///< size of the Column array
	int width; ///< screen width
	int height; ///< screen height
	int max; ///< max value of the array
	int delay; ///< delay
	
	/**
	 * @brief setting up SDL_TTF
	 * @param str name of the font file
	 */	
	bool setupTTF(std::string& str);
	/**
	 * @brief draw one Column
	 * @param i index of the Colmun
	 * @param c color of the Column
	 */
	void drawColumn(size_t i,SDL_Color c);
	/**
	 * @brief write text to the screen
	 * @param str text
	 */
	void writeText(std::string& str);

public:
	
	/**
	 * @brief Constructor
	 * @param w width
	 * @param h height
	 * inits text area, and delay
	 */
    App(int w, int h): width{w}, height{h} {
		textRect.x=0;
		textRect.y=0;
		textRect.w=width;
		textRect.h=height;
		delay=20;
	}

	/**
	 * @brief set Column array
	 * @param col array
	 * @param siz size
	 */	
    void setColumns(Column* col, size_t siz);
	/**
	 * @brief init SDL
	 */
	bool onInit();
	/**
	 * @brief close SDL
	 */
    void onExit();
	/**
	 * @brief Render "menu"
	 */
    void onStart();
	/**
	 * @brief called when the sorting algorithm compares or swaps 2 elements
	 * @param a Column index
	 * @param b Column index
	 * @param swap swap or compare
	 */
	void onCompare(int a, int b, bool swap) override;
	/**
	 * @brief Draw Columns
	 * @param swap true if there was a swap (def:false)
	 * @param a index of the compared/swapped Column (def:-1)
	 * @param b index of the compared/swapped Column (def:-1)
	 */	
	bool onRender(bool swap, int a, int b);
	/**
	 * @brief add param to delay
	 * @param d 
	 */
	void setDelay(int d);
	/**
	 * Destructor
	 */
    ~App();
};

#endif // APP_H
