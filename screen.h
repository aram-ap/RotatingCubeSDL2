//
// Created by Aram Aprahamian on 2/26/23.
//
#include <SDL2/SDL.h>
#include <vector>

struct FPoint
{
    double x;
    double y;

    FPoint(double a, double b)
            : x(a)
            , y(b)
    {}
};

class Screen{
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<FPoint> points;

public: Screen() {
        const int scale = 1;
        SDL_Init(SDL_INIT_VIDEO);
        SDL_CreateWindowAndRenderer(
                640*scale,480*scale,0,&window,&renderer);
        SDL_RenderSetScale(renderer,2,2);
    }

    void pixel(double x, double y) {
        points.emplace_back(x,y);
    }

    //This is the most "SDL" code
    void show() {
        SDL_SetRenderDrawColor(renderer,0,0,0,255); //Sets draw color to black
        SDL_RenderClear(renderer); //Clear screen

        //Set draw color to white so you can actually see the pixels
        SDL_SetRenderDrawColor(renderer, 255, 255,255,255);
        for(auto& point: points) {
            SDL_RenderDrawPointF(renderer,point.x,point.y);
        }

        SDL_RenderPresent(renderer);

    }

    void clear() {
        points.clear();
    }

    void input() {
        //Check if user clicked 'x' on window, if so, exit the program
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                SDL_Quit();
                exit(0);
            }
        }
    }
};

