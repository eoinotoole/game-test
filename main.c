#include <stdio.h>
#include <SDL2/SDL.h>

int main(void)
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("%s", "Error initialising SDL\n");

        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    SDL_Rect rectangle;

    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.w = 50;
    rectangle.h = 50;

    if (!win)
    {
        printf("%s", "Error creating window\n");
        return 1;
    }

    int quit = 0;

    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                printf("Quit Game\n");
                quit = 1;
            }
        }

        printf("LOOP");

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderFillRect(renderer, &rectangle);
        SDL_RenderDrawRect(renderer, &rectangle);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / 60);
    }

    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}