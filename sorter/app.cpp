#include "app.h"

bool App::onInit()
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
    }

	window = SDL_CreateWindow("Sorter", 100, 100, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr) {
		SDL_DestroyWindow(window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
    }
	std::string str="DejaVuSansMono.ttf";
	if(!setupTTF(str)){
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		std::cout << "SDL_TTF Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}
	
    return true;
}

void App::onStart()
{
	std::string str="Hello\n1:QuickSort\n2:BubbleSort\n"
			"3:GnomeSort\n4:SelectionSort\n5:Bubble2Sort"
			"\n6:MergeSort"
			"\nG:greater than\nL:less than\nR:real/unreal random"
			"\nQ/E:delay +/-\nX/C: array size +/-";

	SDL_SetRenderDrawColor( renderer, 0, 255, 255, 255 );
	SDL_RenderClear( renderer );
	writeText(str);
	SDL_RenderPresent( renderer);

}

void App::writeText(std::string& str){
	SDL_Color textColor = { 0, 0, 0, 255 };
	textSurface= TTF_RenderText_Blended_Wrapped( font,str.c_str() , textColor,width );
  
	textTexture = SDL_CreateTextureFromSurface( renderer, textSurface );
 
	SDL_FreeSurface( textSurface );
 
	SDL_QueryTexture( textTexture, NULL, NULL, &textRect.w, &textRect.h );
	textRect.x = 0;
	textRect.y = 0;
	
	SDL_RenderCopy( renderer, textTexture, nullptr, &textRect ); 
	
}

void App::onExit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont( font );
	SDL_Quit();
}

void App::drawColumn(size_t i, SDL_Color c)
{
	SDL_Rect rect;
	rect.x=width/size*i+5;
	rect.y=height-(height/(max+1))*(columns[i].getVaule()+1);
	rect.w=width/size-10;
	rect.h=(height/(1+max))*(columns[i].getVaule()+1);
	SDL_SetRenderDrawColor( renderer, c.r, c.g, c.b, c.a );
	SDL_RenderFillRect(renderer,&rect);
}

bool App::onRender(bool swap=false,int a=-1, int b=-1)
{
	if(a!=-1){
		//std::cout<<a<<" : "<<columns[a].getVaule()<<"; "<<b<<" : "<<columns[b].getVaule()<<std::endl;
	}
	SDL_SetRenderDrawColor( renderer, 0, 255, 255, 255 );
	SDL_RenderClear( renderer );
	for(size_t i=0;i<size;i++){
		SDL_Color c;
		if(a==i || b==i){
			if(swap){
				c.a=255;
				c.r=0;
				c.g=255;
				c.b=0;			
			}else{
				c.a=255;
				c.r=255;
				c.g=0;
				c.b=0;
			}
		}else{
			c.a=255;
			c.r=0;
			c.g=0;
			c.b=255;
		}
		drawColumn(i, c);
	}
	int comp=Column::getCompares();
	int swaps=Column::getSwaps();
	//std::string result = "compares" + std::to_string(comp); //koszi mingw
	std::stringstream ss;
	ss << "compares:"<<std::setw(4)<<comp<<" swaps:"<<std::setw(4)<<swaps;
	std::string str=ss.str();
	writeText(str);
	SDL_RenderPresent(renderer);
	SDL_Delay(delay);
	return true;
}


App::~App()
{
}


void App::setColumns(Column* col, size_t siz)
{
	columns = col;
	size=siz;
	max=columns[0].getVaule();
	for(size_t i=1;i<size;i++){
		//std::cout<<columns[i].getVaule();
		if(max<columns[i].getVaule()){
			max=columns[i].getVaule();
		}
		columns[i].addListener(this);		

	}
	//std::cout<<"MAXXX "<<max<<std::endl;
}


void App::onCompare(int a, int b, bool swap){
	onRender(swap,a,b);

}

bool App::setupTTF(std::string& str)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if ( TTF_Init() == -1 )
	{
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;
		return false;
	}
 
	// Load our fonts, with a huge size
	font = TTF_OpenFont( str.c_str(), 20 );
	// Error check
	if ( font == nullptr )
	{
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;
		return false;
	}
 
	return true;
}

void App::setDelay(int d){
	if(delay+d>0)
		delay+=d;
}