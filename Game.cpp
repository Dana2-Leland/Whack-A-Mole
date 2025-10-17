
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	/*
	character = new sf::Sprite;
	passport = new sf::Texture;
	background = new sf::Sprite;
*/

	if (!character_texture.loadFromFile("../Data/Images/kenney_animalpackredux/PNG/Square/bear.png")) {
		std::cout << "character texture did not load \n";
	}
	character.setTexture(character_texture);
	character.setPosition(100, 100);

	if (!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png")) {
		std::cout << "background texture did not load \n";
	}
	background.setTexture(background_texture);
	
	if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf")) {
		std::cout << "font did not load \n";
	}
	title_text.setString("Whack-a-mole");
	title_text.setFont(font);
	title_text.setCharacterSize(200);
	title_text.setFillColor(sf::Color(255, 255, 255, 128));
	title_text.setPosition(
		window.getSize().x / 2 - title_text.getLocalBounds().width / 2, 
		window.getSize().y / 2 - title_text.getLocalBounds().height / 2);

	menu_text.setString("Welcome to whack-a-mole. Please select an option");
	menu_text.setFont(font);
	menu_text.setCharacterSize(18);
	menu_text.setFillColor(sf::Color(0, 255, 255));
	menu_text.setPosition(
		(window.getSize().x / 2  - menu_text.getLocalBounds().width/2),
		(window.getSize().y / 6 - menu_text.getLocalBounds().height / 2));

	play_option.setString("Play");
	play_option.setFont(font);
	play_option.setCharacterSize(18);
	play_option.setFillColor(sf::Color(0, 255, 255));
	play_option.setPosition(
		(window.getSize().x / 3 - play_option.getLocalBounds().width / 2),
		(window.getSize().y / 4 - play_option.getLocalBounds().height / 2));


	quit_option.setString("Quit");
	quit_option.setFont(font);
	quit_option.setCharacterSize(18);
	quit_option.setFillColor(sf::Color(0, 255, 255));
	quit_option.setPosition(
		(window.getSize().x / 1.5 - quit_option.getLocalBounds().width / 2),
		(window.getSize().y / 4 - quit_option.getLocalBounds().height / 2));

	score_text.setString(std::to_string(score));
	score_text.setFont(font);
	score_text.setCharacterSize(24);
	score_text.setFillColor(sf::Color(255, 0, 0));
	score_text.setPosition((window.getSize().x - 40), (40));





  return true;
}

void Game::update(float dt)
{
	character.move(1.0f * speed * dt, 0);
}

void Game::render()
{
	if (in_menu) {
		window.draw(menu_text);
		window.draw(play_option);
		window.draw(quit_option);
	}
	else {
		
		window.draw(background); //later find way to make this scaleable
		window.draw(character);
		window.draw(title_text);
		window.draw(score_text);
	}
	
}

bool collisionCheck(sf::Vector2i click, sf::Sprite target) {
	//if click.x in position + width, position - width
	if (
		(click.x > (target.getPosition().x - target.getGlobalBounds().width) && //target left bound
			click.x < (target.getPosition().x + target.getGlobalBounds().width)) //target right bound
		&& (click.y > (target.getPosition().y - target.getGlobalBounds().height) && //target top bound
			(click.y < (target.getPosition().y + target.getGlobalBounds().height) //target bottom bound
	))){
		return true;
	}
	return false;
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  if (collisionCheck(click, character)) {
	  character.setScale(0, 0);
	  score++;
	  score_text.setString(std::to_string(score));
  }

}

void Game::keyPressed(sf::Event event) 
{
	if (
		(event.key.code == sf::Keyboard::
			Left) ||
		(event.key.code == sf::Keyboard::
			Right)) 
	{
		play_selected = !play_selected;
		if (play_selected)
		{
			play_option.setString("> Play <");
			quit_option.setString("Quit");
		}
		else
		{
			play_option.setString("Play");
			quit_option.setString("> Quit <");
		}
	}

	if (event.key.code == sf::Keyboard::Enter) {
		if (play_selected)
		{
			in_menu = false;
		}
		else
		{
			window.close();
		}
	}
}


