#include "UserInput.h"
#include <iostream>


UserInput::UserInput(){

}
int UserInput::getInput() {
	SDL_StartTextInput();
	//poll for event
	if (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
		//if key is pressed
		case SDL_TEXTINPUT:
			//do text input
			m_scommand += event.text.text;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				m_ipressed = UP;
				break;
			case SDLK_RIGHT:
				m_ipressed = RIGHT;
				break;
			case SDLK_DOWN:
				m_ipressed = DOWN;
				break;
			case SDLK_LEFT:
				m_ipressed = LEFT;
				break;
			case SDLK_ESCAPE:
				m_ipressed = QUIT;
				break;
			case SDLK_RETURN:
				m_scommand = "";
				//send command to python
				SDL_StopTextInput();
				break;
			}
		//if key is released
		case SDL_KEYUP:
			m_ipressed = 0;
			break;
		//if pressed window close btn
		case SDL_QUIT:
			m_ipressed = QUIT;
			break;
		}
	}
	return m_ipressed;
}

std::string UserInput::getCommand() {
	return m_scommand;
}