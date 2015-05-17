#include <iostream>
#include "basesorter.hpp"
#include "column.h"
#include "app.h"
#include <cstdlib>
#include <ctime>
#include <fstream>


/**
 * @brief main function
 * @param argc
 * @param argv
 * @return 
 * 
 * inits the App, 
 * contains the main Loop with event handling
 * starts the selected sorting
 */

int main(int argc, char **argv)
{
	App app(600,600);
	if(!app.onInit()){
		return -1;
	}
/*	int a[10];
	int b[10];
	for(int i=0;i<10;i++){
		a[i]=10-i;
		b[i]=i+1;
	}*/
	
	bool quit=false;
	SDL_Event e;
	bool greater=false;
	bool random=false;
	int size=15;
	while(!quit){
		app.onStart();
		BaseSorter<Column>* sorter;
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			if (e.type == SDL_KEYDOWN){
				SDL_KeyboardEvent kEvent = e.key;
				switch(kEvent.keysym.scancode){
					case SDL_SCANCODE_1:
						sorter= new QuickSorter<Column>;
						break;
					case SDL_SCANCODE_2:
						sorter= new BubbleSorter<Column>;
						break;
					case SDL_SCANCODE_3:
						sorter= new GnomeSorter<Column>;
						break;						
					case SDL_SCANCODE_4:
						sorter= new SelectionSorter<Column>;
						break;
					case SDL_SCANCODE_5:
						sorter= new Bubble2Sorter<Column>;
						break;
					case SDL_SCANCODE_6:
						sorter=new MergeSorter<Column>;
						break;						
					case SDL_SCANCODE_G:
						greater=true;
						break;
					case SDL_SCANCODE_L:
						greater=false;
						break;
					case SDL_SCANCODE_R:
						random=!random;
						break;
					case SDL_SCANCODE_Q:
						app.setDelay(10);
						break;
					case SDL_SCANCODE_E:
						app.setDelay(-10);
						break;
					case SDL_SCANCODE_C:
						if(size-1>2)
							size--;
						break;
					case SDL_SCANCODE_X:
						size++;
						break;
					case SDL_SCANCODE_ESCAPE:
						quit=true;
						break;
					default:
						//quit=true;
						break;
				}				
			}
		}
		
		if(sorter!=nullptr){				
			Column c[size];
			if(random){
				srand(time(NULL));
			}else{
				srand(3);				
			}
			Column::setCompares(0);
			Column::setSwaps(0);
			for(int i=0;i<size;i++){
				c[i]=Column{rand() % 100,i};
			}
			app.setColumns(c, size);
			if(greater){
				(*sorter)(c,size, [](Column a, Column b){return a>=b;});	
			}else{
				(*sorter)(c,size, [](Column a, Column b){return a<=b;});	
			}

			delete sorter;
			sorter=nullptr;
			for(int i=0;i<size;i++){
				std::cout<<c[i].getVaule()<<" ";
			}
			std::cout<<"\n";
		}
	//	BubbleSorter<int> bs;
	//	bs(a, 10, [](int a, int b){return a<b;});
	//	GnomeSorter<int> ss;
	//	ss(b,10, [](int a, int b){return a>=b;});
	
	}
	app.onExit();
	return 0;
}
