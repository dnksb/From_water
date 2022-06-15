#include <SFML/Window.hpp>
#include <iostream>
#include <math.h>
#include "classes.hpp"
#include "tinyxml2.h"

int main() {
	//создание окна
	sf::RenderWindow window(sf::VideoMode(800, 600), "GAME");
	//создание перечесления для меню
	enum MenuPoint{MENU, CHOICE_LEVEL, LEVEL_1, LEVEL_2, LEVEL_3, SETTINGS, TRAINIG_LEVEL, PAUSE};
	//создание перечесления для ESC
	enum LastLevel{FIRST, SECOND, THIRD, TRAIN};
	//инициализация 2-го перечесления
	LastLevel last_level;
	//инициализация 1-го перечесления
	MenuPoint menu_point = MENU;
	//создание спрайта для отрисовки кабины
	sf::Sprite screen_level;
	//создание текстуры для отрисовки кабины
	sf::Texture texture_level;
	//загрузка текстуры
	texture_level.loadFromFile("Subnarine.png");
	//установка текстуры
	screen_level.setTexture(texture_level);
	//количество денег
	int amount_money = 0;
	//шрифт
	sf::Font font;
	//текст количества подобраных сундуков
	sf::Text text_amount_box;
	//загрузка шрифта
	font.loadFromFile("arial.ttf");
	//установка шрифта
	text_amount_box.setFont(font);
	//установка размера текста
	text_amount_box.setCharacterSize(40);
	//установка позиции текста
	text_amount_box.setPosition(90, 480);
	//текст таймера
	sf::Text timer;
	//установка шрифта
	timer.setFont(font);
	//установка размера текста
	timer.setCharacterSize(40);
	//установка позиции текста
	timer.setPosition(625, 480);
	//текст количество денег
	sf::Text text_amount_money;
	//установка шрифта
	text_amount_money.setFont(font);
	//установка размера текста
	text_amount_money.setCharacterSize(40);
	//установка позиции текста
	text_amount_money.setPosition(90, 90);
	/*===PAUSE===*/
	//текстура паузы
	sf::Texture pause_img;
	//спрайт паузы
	sf::Sprite pause_menu;
	//загрузка картинки
	pause_img.loadFromFile("pause.png");
	//установка текстуры
	pause_menu.setTexture(pause_img);
	//создание кнопки паузы
	bt::Button pause(72, 158, 241 - 72, 215 - 158);
	/*===MENU===*/
	//спрайт меню
	sf::Sprite menu_screen;
	//текстура меню
	sf::Texture menu_texture;
	//загразка  изображения
	menu_texture.loadFromFile("Main_menu.png");
	//установка текстуры
	menu_screen.setTexture(menu_texture);
	//создание кнопки
	bt::Button play(65, 230, 323-65, 302-230);
	//создание кнопки
	bt::Button settings(63, 320, 323-63, 394-320);
	//создание кнопки
	bt::Button exit(59, 418, 328-59, 494-418);
	/*===SETTINGS_MENU===*/
	sf::Text text_speed;
	//установка шрифта
	text_speed.setFont(font);
	//установка размера текста
	text_speed.setCharacterSize(40);
	//установка позиции текста
	text_speed.setPosition(120, 375);
	sf::Text text_swim;
	//установка шрифта
	text_swim.setFont(font);
	//установка размера текста
	text_swim.setCharacterSize(40);
	//установка позиции текста
	text_swim.setPosition(320, 375);
	sf::Text text_capacity;
	//установка шрифта
	text_capacity.setFont(font);
	//установка размера текста
	text_capacity.setCharacterSize(40);
	//установка позиции текста
	text_capacity.setPosition(520, 375);
	//спрайт настроек
	sf::Sprite settings_screen;
	//текстура настроек
	sf::Texture settings_texture;
	//загрузка изображения
	settings_texture.loadFromFile("settings_menu.jpg");
	//установка текстуы
	settings_screen.setTexture(settings_texture);
	//создание кнопки
	bt::Button improve_speed(50, 200, 170, 160);
	//создание кнопки
	bt::Button improve_swim(250, 200, 170, 160);
	//создание кнопки
	bt::Button improve_capacity(450, 200, 170, 160);
	//создание кнопки
	bt::Button training_level(650, 200, 120, 160);
	/*===CHOICE_LEVEL===*/
	//спрайт выбора уровня
	sf::Sprite choice_level_screen;
	//текстура выбора уровня
	sf::Texture choice_level_texture;
	//загрузка изображения
	choice_level_texture.loadFromFile("choice_level.png");
	//установка текстуры
	choice_level_screen.setTexture(choice_level_texture);
	//создание кнопки
	bt::Button play_level_1(65, 230, 323-65, 302-230);
	//создание кнопки
	bt::Button play_level_2(63, 320, 323-63, 394-320);
	//создание кнопки
	bt::Button play_level_3(59, 418, 328-59, 494-418);
	/*===LEVEL_1===*/
	//создание персонажа для первого уровня
	pl::Player player_level_1(2048, 2048, "height_map_1.jpg");
	//инициализация рендера
	vx::VoxelRender voxelrender_level_1(2048, 2048, "height_map_1.jpg", "color_map_1.jpg");
	//создание текстуры для миникарты
	sf::Texture minmap_level_1;
	//загрузка изображения
	minmap_level_1.loadFromFile("height_map_1.jpg");
	//спрайт мини карты
	sf::Sprite min_map_level_1;
	//установка текстуры
	min_map_level_1.setTexture(minmap_level_1);
	//установка позиции
	min_map_level_1.setPosition(204, 506);
	//установка размера
	min_map_level_1.setScale(0.04, 0.04);
	/*===LEVEL_2===*/
	//аналогично как в LEVEL_1
	pl::Player player_level_2(1024, 1024, "height_map_2.jpg");
	vx::VoxelRender voxelrender_level_2(1024, 1024, "height_map_2.jpg", "color_map_2.jpg");
	sf::Texture minmap_level_2;
	minmap_level_2.loadFromFile("height_map_2.jpg");
	sf::Sprite min_map_level_2;
	min_map_level_2.setTexture(minmap_level_2);
	min_map_level_2.setPosition(204, 506);
	min_map_level_2.setScale(0.08, 0.08);
	/*===LEVEL_3===*/
	//аналогично как в LEVEL_1
	pl::Player player_level_3(1706, 1692, "height_map_3.jpg");
	vx::VoxelRender voxelrender_level_3(1706, 1692, "height_map_3.jpg", "color_map_3.jpg");
	sf::Texture minmap_level_3;
	minmap_level_3.loadFromFile("height_map_3.jpg");
	sf::Sprite min_map_level_3;
	min_map_level_3.setTexture(minmap_level_3);
	min_map_level_3.setPosition(204, 506);
	min_map_level_3.setScale(0.05, 0.05);
	/*===TRAINING_LEVEL===*/
	//создание кнопки
	bt::Button show_text(100, 500, 700, 565);
	//спрайт текста
	sf::Sprite text_rools;
	//текстура правил
	sf::Texture texture_rools;
	//загрузка изображения
	texture_rools.loadFromFile("text.png");
	//установка текстуры
	text_rools.setTexture(texture_rools);
	//режим тренировки
	bool is_training;
	//игрок для транировки
	pl::Player player_level_train(800, 400, "train_map_height.jpg");
	//рендер тренировки
	vx::VoxelRender voxelrender_level_train(800, 400, "train_map_height.jpg", "train_map_color.jpg");
	//какие-то переменные
	int a = 0, b = 0;
	//переменные для ограничения времени уровня
	clock_t start, end;
	/*===LOAD_SAVE===*/
	//открытие файла
	tinyxml2::XMLDocument save_file("save.xml");
	//проверка если файл открыт
	if(save_file.LoadFile("save.xml") == tinyxml2::XML_SUCCESS) {
		//пытается
		try{
			//элемент скорости
			tinyxml2::XMLElement *speed = save_file.FirstChildElement("speed");
		//установка скорости игрокам
			player_level_1.set_speed(speed->DoubleAttribute("value"));
			player_level_2.set_speed(speed->DoubleAttribute("value"));
			player_level_3.set_speed(speed->DoubleAttribute("value"));
			//элемент скорости всплытия
			tinyxml2::XMLElement *swim = save_file.FirstChildElement("swim");
		//установка скорости всплытия
			player_level_1.set_swim(swim->DoubleAttribute("value"));
			player_level_2.set_swim(swim->DoubleAttribute("value"));
			player_level_3.set_swim(swim->DoubleAttribute("value"));
			//элемент вместимости
			tinyxml2::XMLElement *capacity = save_file.FirstChildElement("capacity");
		//установка вместимости
			player_level_1.set_capacity(capacity->DoubleAttribute("value"));
			player_level_2.set_capacity(capacity->DoubleAttribute("value"));
			player_level_3.set_capacity(capacity->DoubleAttribute("value"));
			//элемент количества денег
			tinyxml2::XMLElement *money = save_file.FirstChildElement("money");
		//установка количества денег
			money->QueryIntAttribute("value", &amount_money);
		//если была ошибка
		}catch(...){
			//самая страшная ошибка
			std::cout << "0xc000007b" << std::endl;	
		}
	}
	//главный цикл
	while (window.isOpen()) {
		//создание объекта события
		sf::Event event;
		//если событие в области окна
		while (window.pollEvent(event)) {
			//какое значение menu point
			switch (menu_point) {
			// если сейчас меню
			case MENU:
				//обработка события
				if(event.type == sf::Event::MouseButtonPressed) {
					//если нажата кнопка игры
					if(play.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
                	//смена значения
						menu_point = CHOICE_LEVEL;
					}
					//если нажата кнопка настроек
					else if(settings.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
					//тренировочный уровень
						is_training = true;
						//смена значения    
						menu_point = SETTINGS;
					}
					//если нажата кнопка выхода
					else if(exit.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
                	//закрытие окна
						window.close();
					}
            	}	
				//сломать
				break;
				//меню выбора уровня
			case CHOICE_LEVEL:
				//если нажа ESC выйти в главное меню
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape)
						menu_point = MENU;
				//если событие мыши
				if(event.type == sf::Event::MouseButtonPressed) {
					//если выбран 1 уровень
					if(play_level_1.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
						//смена значения
						menu_point = LEVEL_1;
						//обнуление количества сундуков
						player_level_1.amount_box = 0;
						//обнуление позиции
						player_level_1.pos = {0,0};
						//обнуление высоты
						player_level_1.height = 255;
						//обнуление рендера
						voxelrender_level_1.RestartLevel();
						//установка начального времени
						start = clock();
					}
					//аналогично как в 1
					else if(play_level_2.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
						menu_point = LEVEL_2;
						player_level_2.amount_box = 0;
						player_level_2.pos = {0,0};
						player_level_2.height = 255;
						voxelrender_level_2.RestartLevel();
						start = clock();
					}
					//аналогично как в 1
					else if(play_level_3.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
						menu_point = LEVEL_3;
						player_level_3.amount_box = 0;
						player_level_3.pos = {0,0};
						player_level_3.height = 255;
						voxelrender_level_3.RestartLevel();
						start = clock();
					}
				}
				//крошить
				break;
				//если запущен 1 уровень
			case LEVEL_1:
				//обрабока нажатий игрока
				player_level_1.action(event);
				//если нажата ESC
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape){
						//запись последнего уровня
						last_level = FIRST;
						//установки паузы
						menu_point = PAUSE;
					}
				break;
				//аналогично с 1 уровнем
			case LEVEL_2:
				player_level_2.action(event);
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape){
						last_level = SECOND;
						menu_point = PAUSE;
					}
				break;
				//аналогично с 1 уровнем
			case LEVEL_3:
				player_level_3.action(event);
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape){
						last_level = THIRD;
						menu_point = PAUSE;
					}
				break;
				//меню настроек
			case SETTINGS:
				//возврат в главное меню
				if (event.type == sf::Event::KeyPressed)
					if(event.key.code == sf::Keyboard::Escape)
						menu_point = MENU;
				//обработка мыши
				if(event.type == sf::Event::MouseButtonPressed) {
					//улучшение скорости плавания
					if(improve_speed.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y}) && amount_money >= 20 && player_level_1.can_improve_speed()) {
					//отнимаем деньги, как в 90
						amount_money -= 20;
						//улучшение скорости
						player_level_1.improve_speed();if (event.type == sf::Event::KeyPressed)
							//возврат в главное меню
							if(event.key.code == sf::Keyboard::Escape)
								menu_point = MENU;
						player_level_2.improve_speed();
						player_level_3.improve_speed();
					}
					//аналогично со скоростью
					else if(improve_swim.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y}) && amount_money >= 20 && player_level_1.can_improve_swim()) {
						amount_money -= 20;
						player_level_1.improve_swim();
						player_level_2.improve_swim();
						player_level_3.improve_swim();
					}
					//аналогично со скоростью
					else if(improve_capacity.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y}) && amount_money >= 40 && player_level_1.can_improve_capacity()) {
						amount_money -= 40;
						player_level_1.improve_capacity();
						player_level_2.improve_capacity();
						player_level_3.improve_capacity();
					}
					//запуск тренировки
					else if(training_level.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y})) {
						//хочу пива
						menu_point = TRAINIG_LEVEL;
					}
				}	
				//разлом
				break;
			//тренировочный уровень
			case TRAINIG_LEVEL:
			//также как с первм уровнем
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
				//пауза
			case PAUSE:
				//кнопка выхода
				if(event.type == sf::Event::MouseButtonPressed)
					if(pause.is_clicked(sf::Vector2i{event.mouseButton.x, event.mouseButton.y}))
						menu_point = MENU;
				//обратно к игре
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
		//очистка окна
		window.clear();
		//что отрисовывать
		switch (menu_point) {
		//отрисовка меню
		case MENU:
		//отрисовка главного меню
			window.draw(menu_screen);
			text_amount_money.setString("$" + std::to_string(amount_money));
			//отрисовка количества денег
			window.draw(text_amount_money);
			break;
		//выбор уровня
		case CHOICE_LEVEL:
			//отрисовка меню выбора
			window.draw(choice_level_screen);
			break;
		//отрисовка 1-го меню
		case LEVEL_1:{
		//обновление игрока
			player_level_1.update();
			//отрисовка рендера
			window.draw(voxelrender_level_1.show(player_level_1));
			//отрисовка кабины
			window.draw(screen_level);
			//отрисовка миникарты
			window.draw(min_map_level_1);
			text_amount_box.setString(std::to_string(player_level_1.amount_box));
			//отрисовка количества сундуков
			window.draw(text_amount_box);
			//текущее время
			end = clock();
			//длительность уровня
			int level_time = (end - start)/1000;
			timer.setString(std::to_string((300 - level_time)/60) + ":" +std::to_string((300 - level_time)%60));
			//отрисовка оставшегося времени
			window.draw(timer);
			//проверка оставшегося времени
			if(level_time > 300) {
			//расчет денег с уровня
				amount_money += player_level_1.amount_box * 10;
				//возврат в главное меню
				menu_point = MENU;
			}
			//если субмарина заполнена
			if(player_level_1.amount_box >= player_level_1.max_box) {
			//аналогично как в проверке оставшегося времени
				amount_money += player_level_1.amount_box * 10;
				menu_point = MENU;
			}
			break;
		}
		//аналогично как в 1 уровне
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
				//отрисовка настроек
		case SETTINGS:
			//меню настройки
			window.draw(settings_screen);
			text_amount_money.setString("$" + std::to_string(amount_money));
			text_speed.setString(std::to_string((int)player_level_1.get_speed()));
			text_swim.setString(std::to_string((int)player_level_1.get_swim()));
			text_capacity.setString(std::to_string((int)player_level_1.get_capacity()));
			//отрисовка количества денег
			window.draw(text_amount_money);
			window.draw(text_speed);
			window.draw(text_swim);
			window.draw(text_capacity);
			break;
		//тренировочный уровень
		case TRAINIG_LEVEL:
			//отрисовка рендера
			window.draw(voxelrender_level_train.show(player_level_train));
			//отрисовка кабины
			window.draw(screen_level);
			//пола не прочитали правила
			if(is_training){
			//вывод текста правил
				window.draw(text_rools);
			}
			else{
			//обновление игрока
				player_level_train.update();
			}
			break;
		//отрисовка паузы
		case PAUSE:
		//отрисовка паузы, как удивительно
			window.draw(pause_menu);
			break;
		}
		//вывод на экран
		window.display();
	}
	//сохранение результатов в файл
	try{
		//элемент скорости
		tinyxml2::XMLElement *speed = save_file.FirstChildElement("speed");
		//сохранение скорости
		speed->SetAttribute("value", player_level_1.get_speed());
		//элемент скорости всплытия
		tinyxml2::XMLElement *swim = save_file.FirstChildElement("swim");
		//сохранение скорости всплытия
		swim->SetAttribute("value", player_level_1.get_swim());
		//элемент вместимости
		tinyxml2::XMLElement *capacity = save_file.FirstChildElement("capacity");
		//сохранение вместимости
		capacity->SetAttribute("value", player_level_1.get_capacity());
		//элемент количества денег
		tinyxml2::XMLElement *money = save_file.FirstChildElement("money");
		//сохранение денег
		money->SetAttribute("value", amount_money);
		//запись всего в файл
		save_file.SaveFile("save.xml");
	}catch(...){
	//ноль холс соси пять нулей семь парней
		std::cout << "0xc000007b" << std::endl;
	}
	return 0;
}