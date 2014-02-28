#include <iostream>
#include "Character.h"

struct Position
{
	Position(int _x, int _y, int _id)
	{
		x = _x;
		y = _y;
		id = _id;
	}
	int x;
	int y;
	int id;
};

enum {UP, DOWN, LEFT, RIGHT};

class Grid
{
public:
	int width;
	int height;
	static const int numberHoles = 8;
	bool hasKey;
	int enemyDirection;
	
	Character player;
	//Position player;
	Position treasure;
	Position enemy;
	Position* holes;

	int** map;

	Grid()
	{
		srand(time(NULL));
		hasKey = false;
		
		height = 8;
		width = 8;
				
		treasure.x = 0;
		treasure.y = 7;
		treasure.id = 4;

		enemy.x = 4;
		enemy.y = 4;
		enemy.id = 2;

		holes = new Position[numberHoles];

		for(int i = 0; i < numberHoles; i++)
		{
			int xx;
			int yy;
			bool flag = true;
			while(flag)
			{
				xx = rand()%8;
				yy = rand()%8;
				if((xx != player.x)&&(xx != enemy.y)&&(xx != treasure.x))
				{
					if((yy != player.y)&&(yy != enemy.y)&&(yy != treasure.y))
						flag = false;
				}
			}
			holes[i].x = xx;
			holes[i].y = yy;
			holes[i].id = 3;
			//std::cout<<holes[i].x<<" "<<holes[i].y<<std::endl;
		}
		
		map = new int* [height];
		for(int i = 0; i < height; i++)
		{
			map[i] = new int[width];
		}
		
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				map[i][j] = 0;
			}
		}
		
		map[player.x][player.y] = player.id;
		map[enemy.x][enemy.y] = enemy.id;
		map[treasure.x][treasure.y] = treasure.id;
		for(int i = 0; i < numberHoles; i++)
		{
			map[holes[i].x][holes[i].y] = holes[i].id;
		}
		
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				std::cout<<map[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}

	void replaceHoles()
	{
		for(int i = 0; i < numberHoles; i++)
		{
			int xx = rand()%8;
			int yy = rand()%8;
			bool flag = true;
			while(flag)
			{
				xx = rand()%8;
				yy = rand()%8;
				if((xx != player.x)&&(xx != enemy.y)&&(xx != treasure.x))
				{
					if((yy != player.y)&&(yy != enemy.y)&&(yy != treasure.y))
						flag = false;
				}
			}
			holes[i].x = xx;
			holes[i].y = yy;
			//std::cout<<"replace holes"<<std::endl;
		}
	}

	void moveEnemy()
	{
		//int randKey = rand()%4;
		enemyDirection = rand()%4;

		if(enemyDirection == UP)
		{
			if((enemy.x == 0)||(map[enemy.x-1][enemy.y] == 3)||(map[enemy.x-1][enemy.y] == 4))
			{
				moveEnemy();
			}
			else 
			{
				int temp = enemy.x;
				map[enemy.x][enemy.y] = 0;
				temp -= 1;
				enemy.x = temp;
				map[enemy.x][enemy.y] = enemy.id;
			}
		}
		else if(enemyDirection == DOWN)
		{
			if((enemy.x == 7)||(map[enemy.x+1][enemy.y] == 3)||(map[enemy.x+1][enemy.y] == 4))
			{
				moveEnemy();
			}
			else 
			{
				int temp = enemy.x;
				map[enemy.x][enemy.y] = 0;
				temp += 1;
				enemy.x = temp;
				map[enemy.x][enemy.y] = enemy.id;
			}
		}
		else if(enemyDirection == LEFT)
		{
			if((enemy.y == 0)||(map[enemy.x][enemy.y-1] == 3)||(map[enemy.x][enemy.y-1] == 4))
			{
				moveEnemy();
			}
			else 
			{
				int temp = enemy.y;
				map[enemy.x][enemy.y] = 0;
				temp -= 1;
				enemy.y = temp;
				map[enemy.x][enemy.y] = enemy.id;
			}
		}
		else if(enemyDirection == RIGHT)
		{
			if((enemy.y == 7)||(map[enemy.x][enemy.y+1] == 3)||(map[enemy.x][enemy.y+1] == 4))
			{
				moveEnemy();
			}
			else 
			{
				int temp = enemy.y;
				map[enemy.x][enemy.y] = 0;
				temp += 1;
				enemy.y = temp;
				map[enemy.x][enemy.y] = enemy.id;
			}
		}

		if(enemy.x == player.x)
			if(enemy.y == player.y)
				std::cout<<"Die"<<std::endl;
		std::cout<<"Enemy "<<enemy.x<<" "<<enemy.y<<std::endl;
		
	}

	void print()
	{
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				std::cout<<map[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		std::cout<<"Enemy "<<enemy.x<<" "<<enemy.y<<std::endl;
		std::cout<<"Player "<<player.x<<" "<<player.y<<std::endl;
		std::cout<<"Key "<<hasKey<<std::endl;
	}


};