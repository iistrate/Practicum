#include "UserInput.h"
#include <iostream>


UserInput::UserInput() : m_ipressed(0), m_imouseX(0), m_imouseY(0) {

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
				m_scommand += "/n";
				SDL_StopTextInput();
				break;
			}
		//if key is released
		case SDL_KEYUP:
			m_ipressed = 0;
			break;
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&m_imouseX, &m_imouseY);
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (SDL_BUTTON_LEFT) {
				m_ipressed = LEFT_MOUSE_BUTTON;
			}
			else if (SDL_BUTTON_RIGHT){
				m_ipressed = RIGHT_MOUSE_BUTTON;
			}
			break;
		case SDL_MOUSEBUTTONUP:
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
int UserInput::getMouseX() {
	return m_imouseX;
}
int UserInput::getMouseY() {
	return m_imouseY;
}