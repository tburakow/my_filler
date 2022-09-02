/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:44:09 by tburakow          #+#    #+#             */
/*   Updated: 2022/09/02 14:28:29 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

#define WINDOW_WIDTH (1920)
#define WINDOW_HEIGHT (1280)

/* int play(t_map *map) */
int play_visual(void)
{
	//initializing the SDL systems
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return (1);
    }
	
	//initializing the window.    
	SDL_Window *win = SDL_CreateWindow("Street Masters", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1280,0);
    if (!win)
    {
        printf("error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
	
	//creating a renderer
	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);
	if (!rend)
	{
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		return (1);
	}
	
	// Loading image to memory using SDL_image library function
	SDL_Surface *board = IMG_Load("resources/the_board.png");
	if (!board)
	{
		printf("error creating surface\n");
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return (1);
	}

	// Loading image to memory using SDL_image library function
	SDL_Surface *start_key = IMG_Load("resources/start.png");
	if (!start_key)
	{
		printf("error creating surface\n");
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return (1);
	}

	// loading the image data for the board into the graphics hardware's memory
	SDL_Texture *tex = SDL_CreateTextureFromSurface(rend, board);
	SDL_FreeSurface(board);
	if (!tex)
	{
		printf("error creating texture: %s\n",SDL_GetError());
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();
		return (1);
	}

	// loading the image data for the start button into the graphics hardware's memory
	SDL_Texture *key = SDL_CreateTextureFromSurface(rend, start_key);
	SDL_FreeSurface(start_key);
	if (!key)
	{
	printf("error creating texture: %s\n",SDL_GetError());
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (1);
	}

	// creating struct to hold the startkey sprite
	SDL_Rect dest;

	//Getingt dimensions of the startkey sprite
	SDL_QueryTexture(key, NULL, NULL, &dest.w, &dest.h);

	//position startkey sprite to middle on x-axis
	dest.x = (WINDOW_WIDTH - dest.w) / 2;
	dest.y = (WINDOW_HEIGHT - dest.y) / 2 - 100;

	// close the window when window close is pressed i.e. set to 1
	int close_requested = 0;
	// keep the original y coordinate for startkey
	int orig_y = dest.y;
	//setup the counter for startkey blink
	int counter = 0;
	//setup the switch for exiting startup screen
	int key_pressed = 0;

	//animation loops until x in the corner of the window pressed, or startkey (any key for now) is pressed.
	while (!close_requested && !key_pressed)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type) 
			{
				case SDL_QUIT:
					close_requested = 1;
					break;
				case SDL_KEYDOWN:
					key_pressed = 1;
					close_requested = 1;
					break;
			}           
		}
		//first, keep the anykey sprite out of screen for a second.
		if (counter < 60)
		{   
			// clear the window
			SDL_RenderClear(rend);
			// kick anykey out of the screen
			dest.y = orig_y + 200;
			//render the vista (or whatever it should be called)
			SDL_RenderCopy(rend, tex, NULL, NULL);
			SDL_RenderCopy(rend, key, NULL, &dest);
			SDL_RenderPresent(rend);
			counter++;
			//printf("counter: %i\n", counter);
		}

		//then, keep it in for a second.
		else if (counter > 59)
		{
			// clear the window
			SDL_RenderClear(rend);
			// bring anykey back to the screen
			dest.y = orig_y;
			//render the vista
			SDL_RenderCopy(rend, tex, NULL, NULL);
			SDL_RenderCopy(rend, key, &dest, &dest);
			SDL_RenderPresent(rend);
			//increment the counter
			counter++;
			//printf("counter: %i\n", counter);
			// if two seconds are up, reset counter
			if (counter == 120)
				counter = 0;
		}
		SDL_Delay(1000 / 60);
		//printf("counter: %i\n", counter);
	}
	
	//cleaning up resources
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    //Quit SDL
    SDL_Quit();
	return (1);
}

int	main(void)
{
/* 	t_map *map;
	
	if (!get_map(&map))
		error_out("visualizer : map creation failed."); */
	while (1)
	{
		if (!play_visual())
			break ;
	}
		
	return (0);
}