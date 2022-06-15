#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

namespace bt{
	//����� ������
	class Button{
		//������� ������
		sf::Vector2i pos;
		//������� ������
		sf::Vector2i size;
	public:
		//�����������
		Button(int x, int y, int w, int h);
		//�������� �������
		bool is_clicked(sf::Vector2i mouse_pos);
	};
}

namespace pl {
	//����� ������
	class Player {
	private:
	//����������� ������������
		bool right = false, left = false, up = false, down = false, forward = false, back = false;
		//������� ������������
		bool right_arrow = false, left_arrow = false, up_arrow = false, down_arrow = false, forward_arrow = false, back_arrow = false;
		//������ �����
		int** height_array;
		//���� ��������
		double angle_vel = 0.01;
		//�� ������� �������� �������� �����������
		double vel = 2;
		//��������
		double speed = 2;
		//��������
		double swim = 2;
		//������ �����������
		int image_width, image_height;
	public:
		//����������� �������
		int amount_box = 0;
		//����������� ���������� ��������
		int max_box = 3;
		//������� ������
		sf::Vector2f pos = {0, 0};
		//���� �������
		double angle = 3.14 / 4;
		//������ ������
		double height = 290;
		//������ �������
		double pitch = 40;
		//�����������
		Player(int Iwidth, int Iheight, std::string height_map_path);
		//��������� �������
		void action(sf::Event &event);
		//���������� ���������
		void update();
		//�������� ��������
		void improve_speed();
		//�������� ��������
		void improve_swim();
		//�������� �����������
		void improve_capacity();
		//�������� �������� ��������
		bool can_improve_speed();
		//�������� �������� ��������
		bool can_improve_swim();
		//�������� �������� �����������
		bool can_improve_capacity();
		//��������� ��������
		void set_speed(double s);
		//��������� ��������
		void set_swim(double s);
		//��������� �����������
		void set_capacity(int mb);
		//��������� ��������
		double get_speed();
		//��������� ��������
		double get_swim();
		//��������� �����������
		double get_capacity();
		//����������
		~Player();
	};
}

namespace box{
	//����� �������
	class Box{
		//������� �������
		sf::Vector2i pos;
		//������ �������
		sf::Vector2i size = sf::Vector2i(50, 50);
	public:
		//���������� ������
		bool show = true;
		//�����������
		Box(sf::Vector2i pos, sf::Vector2i size);
		//�����������
		Box();
		//��������� �������
		void SetPos(sf::Vector2i pos);
		//��������� �������
		void SetSize(sf::Vector2i size);
		//��������� �������
		bool CollisionPoint(sf::Vector2i dot);
		//������ ������
		void Hide();
	};
}

namespace vx {
	//����� �������
	class VoxelRender {
		//������� �����������
		int Iheight, Iwidth;
		//���� ��������
		double fov = 3.14 / 6.0;
		//� ���
		double h_fov = fov / 2.0;
		//������ ����
		double delta_angle;
		//��������� ����
		int rays_distance = 1000;
		//������ �������
		box::Box kladman_mudak[7];
		//������ ������ �� �����
		sf::Image screen_array;
		//������ �������
		int** height_array;
		//������ �����
		sf::Color** color_array;
		//������ ��� ������ ��������
		sf::Sprite sp;
		//�������� ��� ������ ��������
		sf::Texture a;
		//��������
		bool klad = false;
	public:
		//�����������
		VoxelRender(int Iw, int Ih, std::string height_map_path, std::string color_map_path);
		//���������� �������
		void RestartLevel();
		//������� ������� ��������� �������
		sf::Sprite show(pl::Player& player);
		//����������
		~VoxelRender();
	};
}
