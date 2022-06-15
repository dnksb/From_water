#include "classes.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
//конструктор класса кнопки
bt::Button::Button(int x, int y, int w, int h){
	//задаем позицию кнопки
	pos.x = x;
	pos.y = y;
	//задаем размер кнопки
	size.x = w;
	size.y = h;
}
//функция проверки нажатия кнопки
bool bt::Button::is_clicked(sf::Vector2i mouse_pos){
	//если курсор находится в пределах кнопки
	if(mouse_pos.x > pos.x && mouse_pos.x < pos.x + size.x && mouse_pos.y > pos.y && mouse_pos.y < pos.y + size.y){
		//возвращаем true
		return true;
	}
	//иначе false
	return false;
}
//конструктор класса игрока
pl::Player::Player(int Iwidth, int Iheight, std::string height_map_path) {
	//задаем размер игрока
	sf::Image height_map;
	//загружаем картинку
	height_map.loadFromFile(height_map_path);
	//задаем размер картинки
	image_height = Iheight;
	//получаем размер картинки
	image_width = Iwidth;
	//задаем размер карты
	height_array = new int*[image_width];
	//задаем количество строк в массиве
	for (int i = 0; i < image_width; i++) {
		//задаем длину массива
		height_array[i] = new int[image_height];
		//заполняем массив высот
		for (int j = 0; j < image_height; j++) {
			//заполняем массив высот
			height_array[i][j] = height_map.getPixel(i, j).r;
		}
	}
}

//функция обновления игрока
void pl::Player::action(sf::Event &event) {
	//если нажата клавиша
	if (event.type == sf::Event::KeyPressed) {
		//если клавиша вверх
		if (event.key.code == sf::Keyboard::Up)
			//взгляд игрока вверх
			up_arrow = true;
		//если клавиша вниз
		if (event.key.code == sf::Keyboard::Down)
			//вгляд игрока вниз
			down_arrow = true;
		//если клавиша влево
		if (event.key.code == sf::Keyboard::Left)
			//поворачиваем игрока влево
			left_arrow = true;
		//если клавиша вправо
		if (event.key.code == sf::Keyboard::Right)
			//поворачиваем игрока вправо
			right_arrow = true;
		//если клавиша Q
		if (event.key.code == sf::Keyboard::Q)
			//всплываем вверх
			up = true;
		//если клавиша E
		if (event.key.code == sf::Keyboard::E)
			//погружаемся вниз
			down = true;
		//если клавиша W
		if (event.key.code == sf::Keyboard::W) {
			//вперед
			forward = true;
		}
		//если клавиша S
		if (event.key.code == sf::Keyboard::S) {
			//назад
			back = true;
		}
		//если клавиша A
		if (event.key.code == sf::Keyboard::A) {
			//лево
			left = true;
		}
		//если клавиша D
		if (event.key.code == sf::Keyboard::D) {
			//право
			right = true;
		}
		return;
	}
	//если клавиша отпущена
	else if(event.type == sf::Event::KeyReleased) {
		//если клавиша вверх
		if (event.key.code == sf::Keyboard::Up)
			//взгляд игрока вверх
			up_arrow = false;
		//если клавиша вниз
		if (event.key.code == sf::Keyboard::Down)
			//вгляд игрока вниз
			down_arrow = false;
		//если клавиша влево
		if (event.key.code == sf::Keyboard::Left)
			//поворачиваем игрока влево
			left_arrow = false;
		//если клавиша вправо
		if (event.key.code == sf::Keyboard::Right)
			//поворачиваем игрока вправо
			right_arrow = false;
		//если клавиша Q
		if (event.key.code == sf::Keyboard::Q)
			//всплываем вверх
			up = false;
		//если клавиша E
		if (event.key.code == sf::Keyboard::E)
			//погружаемся вниз
			down = false;
		//если клавиша W
		if (event.key.code == sf::Keyboard::W) {
			//вперед
			forward = false;
		}
		//если клавиша S
		if (event.key.code == sf::Keyboard::S) {
			//назад
			back = false;
		}
		//если клавиша A
		if (event.key.code == sf::Keyboard::A) {
			//лево
			left = false;
		}
		//если клавиша D
		if (event.key.code == sf::Keyboard::D) {
			//право
			right = false;
		}
		return;
	}
}


//перемещение игрока
void pl::Player::update(){
	//синус и косинус поворота игрока
	double sin_a = sin(angle);
	double cos_a = cos(angle);
	//если клавиша вверх
	if (up_arrow && pitch < 550)
		//поворачиваем игрока вверх
		pitch += vel * 2;
	//если клавиша вниз
	if (down_arrow && pitch > -550)
		//поворачиваем игрока вниз
		pitch -= vel * 2;
	//если клавиша влево
	if (left_arrow)
		//поворачиваем игрока влево
		angle -= angle_vel;
	//если клавиша вправо
	if (right_arrow)
		//поворачиваем игрока вправо
		angle += angle_vel;
	//если клавиша Q
	if (up)
		//всплываем вверх
		height += swim / 4;
	//если клавиша E
	if (down && height > height_array[(int)pos.x][(int)pos.y] + 10)
		//погружаемся вниз
		height -= vel;
	//если клавиша W
	double dels = (double)speed * sin_a;
	double delc = (double)speed * cos_a;
	if (forward && height > height_array[(int)pos.x + (int)delc][(int)pos.y + (int)dels] + 10) {
		//вперед
		pos.x += delc;
		pos.y += dels;
	}
	//если клавиша S
	if (back && height > height_array[(int)pos.x - (int)delc][(int)pos.y - (int)dels] + 10) {
		//назад
		pos.x -= delc;
		pos.y -= dels;
	}
	//если клавиша A
	if (left) {
		//лево
		if(height > height_array[(int)pos.x + (int)dels][(int)pos.y - (int)delc] + 10)
			//поворачиваем игрока влево
			if(forward || back){
				//поворачиваем игрока влево
				pos.x += dels;
				pos.y -= delc;
			}
		else{
			//поворачиваем игрока влево
			angle -= angle_vel;
		}
	}
	//если клавиша D
	if (right) {
		//право
		if(height > height_array[(int)pos.x - (int)dels][(int)pos.y + (int)delc] + 10)
			//поворачиваем игрока вправо
			if(forward || back){
				//поворачиваем игрока вправо
				pos.x -= dels;
				pos.y += delc;
			}
		else{
			//поворачиваем игрока вправо
			angle += angle_vel;
		}
	}
	//если игрок за пределами массива перемещаем его в пределы
	if(pos.x < 10)
		pos.x = 10;
	if(pos.x > image_width - 10)
		pos.x = image_width - 10;
	if(pos.y < 10)
		pos.y = 10;
	if(pos.y > image_height - 10)
		pos.y = image_height - 10;
	return;
}
//улучшение игрока
void pl::Player::improve_speed(){
	//увеличиваем скорость игрока
	speed += 1;
}
//улучшение игрока
void pl::Player::improve_swim(){
	//увеличиваем скорость всплятия игрока
	swim += 1;
}
//улучшение игрока
void pl::Player::improve_capacity(){
	//увеличиваем вместимость игрока
	max_box += 1;
}
//возможно ли улучшение игрока
bool pl::Player::can_improve_speed(){
	//если скорость игрока меньше 5 то возможно улучшение
	if(speed < 5)
		return true;
	return false;
}
//возможно ли улучшение игрока
bool pl::Player::can_improve_swim(){
	//если скорость всплытия игрока меньше 5 то возможно улучшение
	if(swim < 5)
		return true;
	return false;
}
//возможно ли улучшение игрока
bool pl::Player::can_improve_capacity(){
	//если вместимость игрока меньше 7 то возможно улучшение
	if(max_box < 7)
		return true;
	return false;
}
//получить скорость игрока
void pl::Player::set_speed(double s){
	//устанавливаем скорость игрока
	speed = s;
}
//получить скорость всплытия игрока
void pl::Player::set_swim(double s){
	//устанавливаем скорость всплытия игрока
	swim = s;
}
//получить вместимость игрока
void pl::Player::set_capacity(int mb){
	//устанавливаем вместимость игрока
	max_box = mb;
}
//получить скорость игрока
double pl::Player::get_speed(){
	//получаем скорость игрока
	return speed;
}
//получить скорость всплытия игрока
double pl::Player::get_swim(){
	//получаем скорость всплытия игрока
	return swim;
}
//получить вместимость игрока
double pl::Player::get_capacity(){
	//получаем вместимость игрока
	return max_box;
}
//деструктор
pl::Player::~Player() {
	//удаляем массивы
	delete[] height_array;
}
//конструктор сундука
box::Box::Box(sf::Vector2i pos, sf::Vector2i size) : pos(pos), size(size) {}
//конструктор сундука
box::Box::Box() {
	//устанавливаем позицию и размер
	size = sf::Vector2i(10, 10);
}
//получить позицию сундука
void box::Box::SetPos(sf::Vector2i pos) {
	//устанавливаем позицию сундука
	this->pos = pos;
}
//получить размер сундука
void box::Box::SetSize(sf::Vector2i size) {
	//устанавливаем размер сундука
	this->size = size;
}
//получить позицию сундука
bool box::Box::CollisionPoint(sf::Vector2i dot) {
	//если позиция сундука больше или равна позиции игрока и меньше или равна позиции игрока + размера игрока
	if (dot.x >= pos.x && dot.x <= pos.x + size.x && dot.y >= pos.y && dot.y <= pos.y + size.y)
		return true;
	return false;
}
//скрыть сундук
void box::Box::Hide() {
	//скрываем сундук
	show = false;
}
//конструктор рендера
vx::VoxelRender::VoxelRender(int Iw, int Ih, std::string height_map_path, std::string color_map_path) {
	//заполняем массивы
	for(box::Box& v : kladman_mudak){
		//устанавливаем позицию сундука
		v.SetPos(sf::Vector2i(rand() % Iw, rand() % Ih));
	}	
	//загружаем карту высот
	sf::Image height_map;
	//загружаем карту цвета
	sf::Image color_map;
	//устанавливаем высоту карты
	Iheight = Ih;
	//устанавливаем ширину карты
	Iwidth = Iw;
	//устанавливаем угол игрока
	delta_angle = fov / 800.0;
	//создание черного
	screen_array.create(800, 600,sf::Color::Black);
	//загружаем карту высот
	a.loadFromImage(screen_array);
	//загружаем карту цвета
	sp.setTexture(a);
	//загружаем карту высот
	height_map.loadFromFile(height_map_path);
	//загружаем карту цвета
	color_map.loadFromFile(color_map_path);
	//создаем карту высот
	height_array = new int* [Iheight];
	//создаем карту цвета
	color_array = new sf::Color * [Iheight];
	//заполняем массивы
	for (int i = 0; i < Iheight; i++) {
		//создаем массив высот
		height_array[i] = new int[Iwidth];
		//создаем массив цвета
		color_array[i] = new sf::Color[Iwidth];
		//заполняем массивы
		for (int x = 0; x < Iwidth; x++) {
			//заполняем массив высот
			height_array[i][x] = height_map.getPixel(x, i).r;
			//заполняем массив цвета
			color_array[i][x] = color_map.getPixel(x, i);
		}
	}
}
//рестарт рендера
void vx::VoxelRender::RestartLevel() {
	//заполняем массивы
	for(box::Box& v : kladman_mudak){
		//устанавливаем позицию сундука
		v.SetPos(sf::Vector2i(rand() % Iwidth, rand() % Iheight));
		//показываем сундук
		v.show = true;
	}
}
//отрисовка рендера
sf::Sprite vx::VoxelRender::show(pl::Player& player) {
	//заполняем массивы
	screen_array.create(800, 600, sf::Color::Blue);
	//заполняем массивы
	int* y_buffer = new int[800];
	//заполняем массивы
	for (int i = 0; i < 800; i++) {
		//заполняем массивы
		y_buffer[i] = 599;
	}
	//угол луча
	double ray_angle = player.angle - h_fov;
	//луч 
	for (int num_ray = 0; num_ray < 800; num_ray++) {
		//первый контакт
		bool first_contact = false;
		//синус и косинус луча
		double sin_a = sin(ray_angle);
		double cos_a = cos(ray_angle);
		//координаты луча
		for (double depth = 1; depth < rays_distance; depth++) {
			//координаты пикселя
			int x = player.pos.x + depth * cos_a;
			int y = player.pos.y + depth * sin_a;
			//проверка на выход за границы
			if (0 < x && x < Iwidth && 0 < y && y < Iheight) {
				//проверка на пересечение с высотой
				int height_on_screen = (player.height - height_array[y][x]) / depth * 1000.0 + player.pitch;
				//проверка на пересечение с высотой
				if (height_on_screen > 599) {
					continue;
				}
				//проверка на пересечение с высотой
				else if (height_on_screen < 0) {
					height_on_screen = 0;
				}
				//проверка пересечения с высотой
				if (height_on_screen < y_buffer[num_ray]) {
					//проверка пересечения с снюсуком
					for (box::Box& v : kladman_mudak) {
						//проверка пересечения с сундуком
						if (v.CollisionPoint({x, y}) && v.show) {
							//проверка пересечения с сундуком
							if(depth < 30){
								//увеличиваем количество сундуков
								player.amount_box++;
								//скрываем сундук
								v.Hide();
							}
							//проверка веден ли луч в сундук
							for (int y = height_on_screen; y < y_buffer[num_ray]; y++) {
								//проверка веден ли луч в сундук
								screen_array.setPixel(num_ray, y, sf::Color::Yellow);
							}
							//проверка веден ли луч в сундук
							y_buffer[num_ray] = height_on_screen;
							//проверка веден ли луч в сундук
							klad = true;
						}
					}
					//хороший вопрос что это
					if(klad){
						klad = false;
						continue;
					}
					//получение цвета пикселя
					sf::Color color(color_array[y][x]);
					//проверка растояния до пикселя
					if(color.b + depth/4.0 >= 250){
						color.b = 249;
					}
					else{
						color.b += depth/4.0;
					}
					if(color.r - depth/4.0 <= 0){
						color.r = 1;
					}
					else{
						color.r -= depth/4.0;
					}
					if(color.g - depth/4.0 <= 0){
						color.g = 1;
					}
					else{
						color.g -= depth/4.0;
					}
					//отрисовка полоски
					for (int y = height_on_screen; y < y_buffer[num_ray]; y++) {
						//отрисовка полоски
						screen_array.setPixel(num_ray, y, color);
					}
					//установка высоты пикселя
					y_buffer[num_ray] = height_on_screen;
				}
			}
		}
		//один угол + другой угол
		ray_angle += delta_angle;

	}
	//удаление массива
	delete[] y_buffer;
	//загрузка изображения
	a.loadFromImage(screen_array);
	//установка изображения
	sp.setTexture(a);
	return sp;
}
//деструктор рендера
vx::VoxelRender::~VoxelRender() {
	//удаление массива
	for (int i = 0; i < Iheight; i++) {
		//удаление массива
		delete[] height_array[i];
		//удаление массива
		delete[] color_array[i];
	}
	//удаление массива
	delete[] height_array;
	//удаление массива
	delete[] color_array;
}