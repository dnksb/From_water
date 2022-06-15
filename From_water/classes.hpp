#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

namespace bt{
	//класс кнопки
	class Button{
		//позиция кнопки
		sf::Vector2i pos;
		//размеры кнопки
		sf::Vector2i size;
	public:
		//конструктор
		Button(int x, int y, int w, int h);
		//проверка нажатия
		bool is_clicked(sf::Vector2i mouse_pos);
	};
}

namespace pl {
	//класс игрока
	class Player {
	private:
	//направление передвижения
		bool right = false, left = false, up = false, down = false, forward = false, back = false;
		//стрелки передвижения
		bool right_arrow = false, left_arrow = false, up_arrow = false, down_arrow = false, forward_arrow = false, back_arrow = false;
		//массив высот
		int** height_array;
		//угол поворота
		double angle_vel = 0.01;
		//на сколько изменить значение перемещения
		double vel = 2;
		//скорость
		double speed = 2;
		//всплытие
		double swim = 2;
		//размер изображения
		int image_width, image_height;
	public:
		//подобранные сундуки
		int amount_box = 0;
		//максимально количество сундуков
		int max_box = 3;
		//позиция игрока
		sf::Vector2f pos = {0, 0};
		//угол взгляда
		double angle = 3.14 / 4;
		//высота игрока
		double height = 290;
		//наклон взгляда
		double pitch = 40;
		//конструктор
		Player(int Iwidth, int Iheight, std::string height_map_path);
		//обработка событий
		void action(sf::Event &event);
		//обновление положения
		void update();
		//улучшить скорость
		void improve_speed();
		//улучшить всплытие
		void improve_swim();
		//улучшить вместимость
		void improve_capacity();
		//возможно улучшить скорость
		bool can_improve_speed();
		//возможно улучшить вспылтие
		bool can_improve_swim();
		//возможно улучшить вместимость
		bool can_improve_capacity();
		//установка скорости
		void set_speed(double s);
		//установка всплытия
		void set_swim(double s);
		//установка вместимости
		void set_capacity(int mb);
		//получение скорости
		double get_speed();
		//получение всплытия
		double get_swim();
		//получение вместимости
		double get_capacity();
		//диструктор
		~Player();
	};
}

namespace box{
	//класс сундука
	class Box{
		//позиция сундука
		sf::Vector2i pos;
		//размер сундука
		sf::Vector2i size = sf::Vector2i(50, 50);
	public:
		//показывать сундук
		bool show = true;
		//конструктор
		Box(sf::Vector2i pos, sf::Vector2i size);
		//конструктор
		Box();
		//установка позиции
		void SetPos(sf::Vector2i pos);
		//установка размера
		void SetSize(sf::Vector2i size);
		//провверка колизии
		bool CollisionPoint(sf::Vector2i dot);
		//скрыть сундук
		void Hide();
	};
}

namespace vx {
	//класс рендера
	class VoxelRender {
		//размеры изображения
		int Iheight, Iwidth;
		//угол поворота
		double fov = 3.14 / 6.0;
		//х фов
		double h_fov = fov / 2.0;
		//дельта угол
		double delta_angle;
		//дистанция луча
		int rays_distance = 1000;
		//массив сундуов
		box::Box kladman_mudak[7];
		//массив вывода на экран
		sf::Image screen_array;
		//высота полосок
		int** height_array;
		//массив цвета
		sf::Color** color_array;
		//спрайт для вывода картинки
		sf::Sprite sp;
		//текстура для вывода картинки
		sf::Texture a;
		//закладка
		bool klad = false;
	public:
		//конструктор
		VoxelRender(int Iw, int Ih, std::string height_map_path, std::string color_map_path);
		//перезапуск рендера
		void RestartLevel();
		//главная функция отрисовки графики
		sf::Sprite show(pl::Player& player);
		//диструктор
		~VoxelRender();
	};
}
