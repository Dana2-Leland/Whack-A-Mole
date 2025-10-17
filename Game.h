
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  


 private:
  bool in_menu = true;
  int speed = 5;
  bool play_selected = false;
  int score = 0;

  sf::RenderWindow& window;

  sf::Sprite background;
  sf::Texture background_texture;

  sf::Sprite character;
  sf::Texture character_texture;
  
  sf::Font font;
  sf::Text title_text;
  sf::Text menu_text;

  sf::Text play_option;
  sf::Text quit_option;
  
  sf::Text score_text;



  sf::Texture passport;



};

#endif // PLATFORMER_GAME_H
