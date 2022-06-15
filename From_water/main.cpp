#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>
#include "classes.hpp"
#include "tinyxml2.h"

int main() {
	//�������� ����
	sf::RenderWindow window(sf::VideoMode(800, 600), "GAME");
	//�������� ������������ ��� ����
	enum MenuPoint{MENU, CHOICE_LEVEL, LEVEL_1, LEVEL_2, LEVEL_3, SETTINGS, TRAINIG_LEVEL, PAUSE};
	//�������� ������������ ��� ESC
	enum LastLevel{FIRST, SECOND, THIRD, TRAIN};
	//������������� 2-�� ������������
	LastLevel last_level;
	//������������� 1-�� ������������
	MenuPoint menu_point = MENU;
	//�������� ������� ��� ��������� ������
	sf::Sprite screen_level;
	//�������� �������� ��� ��������� ������
	sf::Texture texture_level;
	//�������� ��������
	texture_level.loadFromFile("Subnarine.png");
	//��������� ��������
	screen_level.setTexture(texture_level);
	//���������� �����
	int amount_money = 0;
	//�����
	sf::Font font;
	//����� ���������� ���������� ��������
	sf::Text text_amount_box;
	//�������� ������
	font.loadFromFile("arial.ttf");
	//��������� ������
	text_amount_box.setFont(font);
	//��������� ������� ������
	text_amount_box.setCharacterSize(40);
	//��������� ������� ������
	text_amount_box.setPosition(90, 480);
	//����� �������
	sf::Text timer;
	//��������� ������
	timer.setFont(font);
	//��������� ������� ������
	timer.setCharacterSize(40);
	//��������� ������� ������
	timer.setPosition(625, 480);
	//����� ���������� �����
	sf::Text text_amount_money;
	//��������� ������
	text_amount_money.setFont(font);
	//��������� ������� ������
	text_amount_money.setCharacterSize(40);
	//��������� ������� ������
	text_amount_money.setPosition(90, 90);
	/*===PAUSE===*/
	//�������� �����
	sf::Texture pause_img;
	//������ �����
	sf::Sprite pause_menu;
	//�������� ��������
	pause_img.loadFromFile("pause.png");
	//��������� ��������
	pause_menu.setTexture(pause_img);
	//�������� ������ �����
	bt::Button pause(72, 158, 241 - 72, 215 - 158);
	/*===MENU===*/
	//������ ����
	sf::Sprite menu_screen;
	//�������� ����
	sf::Texture menu_texture;
	//��������  �����������
	menu_texture.loadFromFile("Main_menu.png");
	//��������� ��������
	menu_screen.setTexture(menu_texture);
	//�������� ������
	bt::Button play(65, 230, 323-65, 302-230);
	//�������� ������
	bt::Button settings(63, 320, 323-63, 394-320);
	//�������� ������
	bt::Button exit(59, 418, 328-59, 494-418);
	/*===SETTINGS_MENU===*/
	sf::Text text_speed;
	//��������� ������
	text_speed.setFont(font);
	//��������� ������� ������
	text_speed.setCharacterSize(40);
	//��������� ������� ������
	text_speed.setPosition(120, 375);
	sf::Text text_swim;
	//��������� ������
	text_swim.setFont(font);
	//��������� ������� ������
	text_swim.setCharacterSize(40);
	//��������� ������� ������
	text_swim.setPosition(320, 375);
	sf::Text text_capacity;
	//��������� ������
	text_capacity.setFont(font);
	//��������� ������� ������
	text_capacity.setCharacterSize(40);
	//��������� ������� ������
	text_capacity.setPosition(520, 375);
	//������ ��������
	sf::Sprite settings_screen;
	//�������� ��������
	sf::Texture settings_texture;
	//�������� �����������
	settings_texture.loadFromFile("settings_menu.jpg");
	//��������� �������
	settings_screen.setTexture(settings_texture);
	//�������� ������
	bt::Button improve_speed(50, 200, 170, 160);
	//�������� ������
	bt::Button improve_swim(250, 200, 170, 160);
	//�������� ������
	bt::Button improve_capacity(450, 200, 170, 160);
	//�������� ������
	bt::Button training_level(650, 200, 120, 160);
	/*===CHOICE_LEVEL===*/
	//������ ������ ������
	sf::Sprite choice_level_screen;
	//�������� ������ ������
	sf::Texture choice_level_texture;
	//�������� �����������
	choice_level_texture.loadFromFile("choice_level.png");
	//��������� ��������
	choice_level_screen.setTexture(choice_level_texture);
	//�������� ������
	bt::Button play_level_1(65, 230, 323-65, 302-230);
	//�������� ������
	bt::Button play_level_2(63, 320, 323-63, 394-320);
	//�������� ������
	bt::Button play_level_3(59, 418, 328-59, 494-418);
	/*===LEVEL_1===*/
	//�������� ��������� ��� ������� ������
	pl::Player player_level_1(2048, 2048, "height_map_1.jpg");
	//������������� �������
	vx::VoxelRender voxelrender_level_1(2048, 2048, "height_map_1.jpg", "color_map_1.jpg");
	//�������� �������� ��� ���������
	sf::Texture minmap_level_1;
	//�������� �����������
	minmap_level_1.loadFromFile("height_map_1.jpg");
	//������ ���� �����
	sf::Sprite min_map_level_1;
	//��������� ��������
	min_map_level_1.setTexture(minmap_level_1);
	//��������� �������
	min_map_level_1.setPosition(204, 506);
	//��������� �������
	min_map_level_1.setScale(0.04, 0.04);
	/*===LEVEL_2===*/
	//���������� ��� � LEVEL_1
	pl::Player player_level_2(1024, 1024, "height_map_2.jpg");
	vx::VoxelRender voxelrender_level_2(1024, 1024, "height_map_2.jpg", "color_map_2.jpg");
	sf::Texture minmap_level_2;
	minmap_level_2.loadFromFile("height_map_2.jpg");
	sf::Sprite min_map_level_2;
	min_map_level_2.setTexture(minmap_level_2);
	min_map_level_2.setPosition(204, 506);
	min_map_level_2.setScale(0.08, 0.08);
	/*===LEVEL_3===*/
	//���������� ��� � LEVEL_1
	pl::Player player_level_3(1706, 1692, "height_map_3.jpg");
	vx::VoxelRender voxelrender_level_3(1706, 1692, "height_map_3.jpg", "color_map_3.jpg");
	sf::Texture minmap_level_3;
	minmap_level_3.loadFromFile("height_map_3.jpg");
	sf::Sprite min_map_level_3;
	min_map_level_3.setTexture(minmap_level_3);
	min_map_level_3.setPosition(204, 506);
	min_map_level_3.setScale(0.05, 0.05);
	/*===TRAINING_LEVEL===*/
	//�������� ������
	bt::Button show_text(100, 500, 700, 565);
	//������ ������
	sf::Sprite text_rools;
	//�������� ������
	sf::Texture texture_rools;
	//�������� �����������
	texture_rools.loadFromFile("text.png");
	//��������� ��������
	text_rools.setTexture(texture_rools);
	//����� ����������
	bool is_training;
	//����� ��� ����������
	pl::Player player_level_train(800, 400, "train_map_height.jpg");
	//������ ����������
	vx::VoxelRender voxelrender_level_train(800, 400, "train_map_height.jpg", "train_map_color.jpg");
	//�����-�� ����������
	int a = 0, b = 0;
	//���������� ��� ����������� ������� ������
	clock_t start, end;
	/*===LOAD_SAVE===*/
	//�������� �����
	tinyxml2::XMLDocument save_file("save.xml");
	//�������� ���� ���� ������
	if(save_file.LoadFile("save.xml") == tinyxml2::XML_SUCCESS) {
		//��������
		try{
			//������� ��������
			tinyxml2::XMLElement *speed = save_file.FirstChildElement("speed");
		//��������� �������� �������
			player_level_1.set_speed(speed->DoubleAttribute("value"));
			player_level_2.set_speed(speed->DoubleAttribute("value"));
			player_level_3.set_speed(speed->DoubleAttribute("value"));
			//������� �������� ��������
			tinyxml2::XMLElement *swim = save_file.FirstChildElement("swim");
		//��������� �������� ��������
			player_level_1.set_swim(swim->DoubleAttribute("value"));
			player_level_2.set_swim(swim->DoubleAttribute("value"));
			player_level_3.set_swim(swim->DoubleAttribute("value"));
			//������� �����������
			tinyxml2::XMLElement *capacity = save_file.FirstChildElement("capacity");
		//��������� �����������
			player_level_1.set_capacity(capacity->DoubleAttribute("value"));
			player_level_2.set_capacity(capacity->DoubleAttribute("value"));
			player_level_3.set_capacity(capacity->DoubleAttribute("value"));
			//������� ���������� �����
			tinyxml2::XMLElement *money = save_file.FirstChildElement("money");
		//��������� ���������� �����
			money->QueryIntAttribute("value", &amount_money);
		//���� ���� ������
		}catch(...){
			//����� �������� ������
			std::cout << "0xc000007b" << std::endl;	
		}
	}
	//������� ����
	while (window.isOpen()) {
		//�������� ������� �������
		sf::Event event;
		//���� ������� � ������� ����
		while (window.pollEvent(event)) {
			//����� �������� menu point
			switch (menu_point) {
			// ���� ������ ����
			case MENU:
				//��������� �������
				if(event.type == sf::Event::MouseButtonPressed) {
					//���� ������ ������ ����
					if(play.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
                	//����� ��������
						menu_point = CHOICE_LEVEL;
					}
					//���� ������ ������ ��������
					else if(settings.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
					//������������� �������
						is_training = true;
						//����� ��������    
						menu_point = SETTINGS;
					}
					//���� ������ ������ ������
					else if(exit.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
                	//�������� ����
						window.close();
					}
            	}	
				//�������
				break;
				//���� ������ ������
			case CHOICE_LEVEL:
				//���� ���� ESC ����� � ������� ����
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape)
						menu_point = MENU;
				//���� ������� ����
				if(event.type == sf::Event::MouseButtonPressed) {
					//���� ������ 1 �������
					if(play_level_1.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
						//����� ��������
						menu_point = LEVEL_1;
						//��������� ���������� ��������
						player_level_1.amount_box = 0;
						//��������� �������
						player_level_1.pos = {0,0};
						//��������� ������
						player_level_1.height = 255;
						//��������� �������
						voxelrender_level_1.RestartLevel();
						//��������� ���������� �������
						start = clock();
					}
					//���������� ��� � 1
					else if(play_level_2.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
						menu_point = LEVEL_2;
						player_level_2.amount_box = 0;
						player_level_2.pos = {0,0};
						player_level_2.height = 255;
						voxelrender_level_2.RestartLevel();
						start = clock();
					}
					//���������� ��� � 1
					else if(play_level_3.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
						menu_point = LEVEL_3;
						player_level_3.amount_box = 0;
						player_level_3.pos = {0,0};
						player_level_3.height = 255;
						voxelrender_level_3.RestartLevel();
						start = clock();
					}
				}
				//�������
				break;
				//���� ������� 1 �������
			case LEVEL_1:
				//�������� ������� ������
				player_level_1.action(event);
				//���� ������ ESC
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape){
						//������ ���������� ������
						last_level = FIRST;
						//��������� �����
						menu_point = PAUSE;
					}
				break;
				//���������� � 1 �������
			case LEVEL_2:
				player_level_2.action(event);
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape){
						last_level = SECOND;
						menu_point = PAUSE;
					}
				break;
				//���������� � 1 �������
			case LEVEL_3:
				player_level_3.action(event);
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape){
						last_level = THIRD;
						menu_point = PAUSE;
					}
				break;
				//���� ��������
			case SETTINGS:
				//������� � ������� ����
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape)
						menu_point = MENU;
				//��������� ����
				if(event.type == sf::Event::MouseButtonPressed) {
					//��������� �������� ��������
					if(improve_speed.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y}) && amount_money >= 20 && player_level_1.can_improve_speed()) {
					//�������� ������, ��� � 90
						amount_money -= 20;
						//��������� ��������
						player_level_1.improve_speed();if (event.type == sf::Event::KeyPressed)
							//������� � ������� ����
							if(event.key.code == sf::Keyboard::Escape)
								menu_point = MENU;
						player_level_2.improve_speed();
						player_level_3.improve_speed();
					}
					//���������� �� ���������
					else if(improve_swim.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y}) && amount_money >= 20 && player_level_1.can_improve_swim()) {
						amount_money -= 20;
						player_level_1.improve_swim();
						player_level_2.improve_swim();
						player_level_3.improve_swim();
					}
					//���������� �� ���������
					else if(improve_capacity.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y}) && amount_money >= 40 && player_level_1.can_improve_capacity()) {
						amount_money -= 40;
						player_level_1.improve_capacity();
						player_level_2.improve_capacity();
						player_level_3.improve_capacity();
					}
					//������ ����������
					else if(training_level.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
						//���� ����
						menu_point = TRAINIG_LEVEL;
					}
				}	
				//������
				break;
			//������������� �������
			case TRAINIG_LEVEL:
			//����� ��� � ����� �������
				player_level_train.action(event);
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape){
						last_level = TRAIN;
						menu_point = PAUSE;
					}
				if(event.type == sf::Event::MouseButtonPressed)
					if(show_text.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
						is_training = false;
					}
				break;
				//�����
			case PAUSE:
				//������ ������
				if(event.type == sf::Event::MouseButtonPressed)
					if(pause.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y}))
						menu_point = MENU;
				//������� � ����
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape)
						switch (last_level){
						case FIRST:
							menu_point = LEVEL_1;
							break;
						case SECOND:
							menu_point = LEVEL_2;
							break;
						case THIRD:
							menu_point = LEVEL_3;
							break;
						case TRAIN:
							menu_point = TRAINIG_LEVEL;
							break;
						}
			}
		}
		//������� ����
		window.clear();
		//��� ������������
		switch (menu_point) {
		//��������� ����
		case MENU:
		//��������� �������� ����
			window.draw(menu_screen);
			text_amount_money.setString("$" + std::to_string(amount_money));
			//��������� ���������� �����
			window.draw(text_amount_money);
			break;
		//����� ������
		case CHOICE_LEVEL:
			//��������� ���� ������
			window.draw(choice_level_screen);
			break;
		//��������� 1-�� ����
		case LEVEL_1:{
		//���������� ������
			player_level_1.update();
			//��������� �������
			window.draw(voxelrender_level_1.show(player_level_1));
			//��������� ������
			window.draw(screen_level);
			//��������� ���������
			window.draw(min_map_level_1);
			text_amount_box.setString(std::to_string(player_level_1.amount_box));
			//��������� ���������� ��������
			window.draw(text_amount_box);
			//������� �����
			end = clock();
			//������������ ������
			int level_time = (end - start)/1000;
			timer.setString(std::to_string((300 - level_time)/60) + ":" +std::to_string((300 - level_time)%60));
			//��������� ����������� �������
			window.draw(timer);
			//�������� ����������� �������
			if(level_time > 300) {
			//������ ����� � ������
				amount_money += player_level_1.amount_box * 10;
				//������� � ������� ����
				menu_point = MENU;
			}
			//���� ��������� ���������
			if(player_level_1.amount_box >= player_level_1.max_box) {
			//���������� ��� � �������� ����������� �������
				amount_money += player_level_1.amount_box * 10;
				menu_point = MENU;
			}
			break;
		}
		//���������� ��� � 1 ������
		case LEVEL_2:{
			player_level_2.update();
			window.draw(voxelrender_level_2.show(player_level_2));
			window.draw(screen_level);
			window.draw(min_map_level_2);
			text_amount_box.setString(std::to_string(player_level_2.amount_box));
			window.draw(text_amount_box);
			end = clock();
			int level_time = (end - start)/1000;
			timer.setString(std::to_string((300 - level_time)/60) + ":" +std::to_string((300 - level_time)%60));
			window.draw(timer);
			if(level_time > 300) {
				amount_money += player_level_2.amount_box * 10;
				menu_point = MENU;
			}
			if(player_level_2.amount_box >= player_level_2.max_box) {
				amount_money += player_level_2.amount_box * 10;
				menu_point = MENU;
			}
			break;
		}
		case LEVEL_3:{
			player_level_3.update();
			window.draw(voxelrender_level_3.show(player_level_3));
			window.draw(screen_level);
			window.draw(min_map_level_3);
			text_amount_box.setString(std::to_string(player_level_3.amount_box));
			window.draw(text_amount_box);
			end = clock();
			int level_time = (end - start)/1000;
			timer.setString(std::to_string((300 - level_time)/60) + ":" +std::to_string((300 - level_time)%60));
			window.draw(timer);
			if(level_time > 300) {
				amount_money += player_level_3.amount_box * 10;
				menu_point = MENU;
			}
			if(player_level_3.amount_box >= player_level_3.max_box) {
				amount_money += player_level_3.amount_box * 10;
				menu_point = MENU;
			}
			break;
		}
				//��������� ��������
		case SETTINGS:
			//���� ���������
			window.draw(settings_screen);
			text_amount_money.setString("$" + std::to_string(amount_money));
			text_speed.setString(std::to_string((int)player_level_1.get_speed()));
			text_swim.setString(std::to_string((int)player_level_1.get_swim()));
			text_capacity.setString(std::to_string((int)player_level_1.get_capacity()));
			//��������� ���������� �����
			window.draw(text_amount_money);
			window.draw(text_speed);
			window.draw(text_swim);
			window.draw(text_capacity);
			break;
		//������������� �������
		case TRAINIG_LEVEL:
			//��������� �������
			window.draw(voxelrender_level_train.show(player_level_train));
			//��������� ������
			window.draw(screen_level);
			//���� �� ��������� �������
			if(is_training){
			//����� ������ ������
				window.draw(text_rools);
			}
			else{
			//���������� ������
				player_level_train.update();
			}
			break;
		//��������� �����
		case PAUSE:
		//��������� �����, ��� �����������
			window.draw(pause_menu);
			break;
		}
		//����� �� �����
		window.display();
	}
	//���������� ����������� � ����
	try{
		//������� ��������
		tinyxml2::XMLElement *speed = save_file.FirstChildElement("speed");
		//���������� ��������
		speed->SetAttribute("value", player_level_1.get_speed());
		//������� �������� ��������
		tinyxml2::XMLElement *swim = save_file.FirstChildElement("swim");
		//���������� �������� ��������
		swim->SetAttribute("value", player_level_1.get_swim());
		//������� �����������
		tinyxml2::XMLElement *capacity = save_file.FirstChildElement("capacity");
		//���������� �����������
		capacity->SetAttribute("value", player_level_1.get_capacity());
		//������� ���������� �����
		tinyxml2::XMLElement *money = save_file.FirstChildElement("money");
		//���������� �����
		money->SetAttribute("value", amount_money);
		//������ ����� � ����
		save_file.SaveFile("save.xml");
	}catch(...){
	//���� ���� ���� ���� ����� ���� ������
		std::cout << "0xc000007b" << std::endl;
	}
	return 0;
}