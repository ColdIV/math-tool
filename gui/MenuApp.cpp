#include <string>

#include "MenuApp.h"
#include "TextOutput.h"
#include "MenuInput.h"


MenuApp::MenuApp(SDL_Window *window, SDL_Renderer *renderer) : App(window, renderer) {
	// widget for the menu text
	std::string menuText = "Hauptmenue\n1) Geometrie\n2) Funktionsplotter\n3)"
		" Taschenrechner";
	Widget *menuWidget = new TextOutput{
		window, renderer, 30, 30, 600, 400, menuText, 50
	};

	// widget for the input prompt
	Widget *promptWidget = new TextOutput{
		window, renderer, 0, 450, 600, 500, "Eingabe: ", 24
	};

	// widget for the text input
	Widget *input = new MenuInput{
		window, renderer, 100, 450, 600, 500, "", 24
	};

	widgets.push_back(menuWidget);
	widgets.push_back(promptWidget);
	widgets.push_back(input);
}
