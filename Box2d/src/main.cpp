#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <Box2D.h>


#define sDown 0
#define sLeft 48
#define sRight 96
#define sUp 144


int main() {

	sf::RenderWindow Game(sf::VideoMode(1161,700,32), "Ventana Negra");
	sf::Event Event;
	//sf::Shape box = sf::Shape::Rectangle(0,0,50,50,sf::Color(127,52,100,255));
	//sf::Sprite sprite;
	sf::Sprite player, background;
	sf::Image tempImage;
	sf::Image temp2;

	float velx = 0, vely = 0;
	float x=10, y=10, moveSpeed=5;
	int sourceX=0, sourceY=sDown;


	if (!temp2.LoadFromFile("/home/hector/workspace/Box2d/imagenes/map.jpg"))
		return EXIT_FAILURE;
		background.SetImage(temp2);

	if (!tempImage.LoadFromFile("/home/hector/workspace/Box2d/imagenes/Player.png"))
		return EXIT_FAILURE;
		player.SetImage(tempImage);

	Game.SetFramerateLimit(20);
	//box.SetPosition(100,100);

//	sf::Image image;
//	if (!image.LoadFromFile("/home/hector/workspace/Box2d/imagenes/box.png"))
//			return EXIT_FAILURE;
//	image.CreateMaskFromColor(sf::Color(255,25,110,255));


	//sprite.SetImage(image);
	//sprite.SetPosition(200,200);



//	bool doSleep = true;
//	b2Vec2 gravity(0, 9.8f);
//	int it =10;
//	float scale = 30;
//	float timestep = 1 / 60;
//
//	b2AABB worldAABB;
//	worldAABB.lowerBound.Set(-1000 / scale, 1000 / scale);
//	worldAABB.upperBound.Set(1000 / scale, 1000 / scale);
//
//	b2World* world;
//	world = new b2World(worldAABB, gravity, doSleep);


	while(Game.IsOpened())
		{
			while(Game.GetEvent(Event))
			{
				if(Event.Type == sf::Event::Closed || Event.Key.Code == sf::Key::Escape)
					Game.Close();
			}

//			if(Game.GetInput().IsKeyDown(sf::Key::A))
//				box.Move(-1,0);
//
//			else if(Game.GetInput().IsKeyDown(sf::Key::D))
//				box.Move(1,0);
//
//			else if(Game.GetInput().IsKeyDown(sf::Key::W))
//				box.Move(0,-1);
//
//			else if(Game.GetInput().IsKeyDown(sf::Key::S))
//				box.Move(0,1);


			if(Game.GetInput().IsKeyDown(sf::Key::Left))
			{
				//sprite.Move(-1,0);
				sourceY = sLeft;
				velx = -moveSpeed;
				//player.Move(-10,0);
			}
			else if(Game.GetInput().IsKeyDown(sf::Key::Right))
			{
				//sprite.Move(-1,0);
				sourceY = sRight;
				velx = moveSpeed;
				//player.Move(10,0);

			}
			else
				velx = 0;

			if(Game.GetInput().IsKeyDown(sf::Key::Up))
			{
				//sprite.Move(-1,0);
				sourceY = sUp;
				vely = -moveSpeed;
				//player.Move(10,-1);

			}
			else if(Game.GetInput().IsKeyDown(sf::Key::Down))
			{
				//sprite.Move(-1,0);
				sourceY = sDown;
				vely = moveSpeed;
				//player.Move(0,10);

			}
			else
				vely = 0;

			x+= velx;
			y+= vely;

			if(velx !=0 || vely !=0)
				sourceX += tempImage.GetWidth() /4;
			else
				sourceX= 0;

			if (sourceX == tempImage.GetWidth())
				sourceX =0;

			player.SetSubRect(sf::IntRect(sourceX,sourceY,sourceX + tempImage.GetWidth() /4, sourceY + tempImage.GetHeight() /4));
			player.SetPosition(x,y);
//			else if(Game.GetInput().IsKeyDown(sf::Key::Right))
//			{
//				//sprite.Move(1,0);
//
//				sourceY = sRight;
//				velx = moveSpeed;
//			}
//
//			else if(Game.GetInput().IsKeyDown(sf::Key::Up))
//							//sprite.Move(0,-1);
//
//			else if(Game.GetInput().IsKeyDown(sf::Key::Down))
//							sprite.Move(0,1);
//			Game.Draw(box);
			Game.Clear();
			Game.Draw(background);
			Game.Draw(player);
			//Game.Draw(sprite);
			Game.Display();

	}

	return EXIT_SUCCESS;
}
