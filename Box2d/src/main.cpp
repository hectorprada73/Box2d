
#include <SFML/Graphics.hpp>

#define sDown 0
#define sLeft 48
#define sRight 96
#define sUp 144

int main()
{
    sf::RenderWindow App(sf::VideoMode(1161, 700), "SFML Views");

    //cargo mi sprite
    sf::Image BackgroundImage;
    if (!BackgroundImage.LoadFromFile("/home/hector/git/Box2d/Box2d/imagenes/map.jpg"))
        return EXIT_FAILURE;
    sf::Sprite Background(BackgroundImage);

	sf::Sprite player;
	sf::Image temp;

	float velx = 0, vely = 0;
	float x=500, y=300, moveSpeed=11;
	int sourceX=0, sourceY=sDown;


	if (!temp.LoadFromFile("/home/hector/git/Box2d/Box2d/imagenes/Player.png"))
		return EXIT_FAILURE;
		player.SetImage(temp);

	App.SetFramerateLimit(27);

    // Create another sprite for the cursor
    sf::Image CursorImage;
    if (!CursorImage.LoadFromFile("/home/hector/git/Box2d/Box2d/imagenes/cursor.png"))
        return EXIT_FAILURE;
    sf::Sprite Cursor(CursorImage);

    // Resize the background, so that it's much bigger than the window
    Background.Resize(1161*2, 700*2);

    // Define a text for displaying some instructions
    sf::String Text("presione las flechas para mover mapa\npresione + y - para zoom y unzoom");
    Text.Move(10, 500);
    Text.SetColor(sf::Color::White);

    //creo el view centrado en center
    sf::Vector2f Center(500, 300);
    sf::Vector2f HalfSize(400, 300);
    sf::View View(Center, HalfSize);

    Cursor.SetCenter(32, 32);
    Cursor.SetPosition(Center);

    while (App.IsOpened())
    {
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                App.Close();

            if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape))
                App.Close();
        }
        //definicion del view

        float Offset = 200.f * App.GetFrameTime();
        if (App.GetInput().IsKeyDown(sf::Key::Up))    View.Move( 0,      -Offset);
        if (App.GetInput().IsKeyDown(sf::Key::Down))  View.Move( 0,       Offset);
        if (App.GetInput().IsKeyDown(sf::Key::Left))  View.Move(-Offset,  0);
        if (App.GetInput().IsKeyDown(sf::Key::Right)) View.Move( Offset,  0);

        //zoom y unzoom

        if (App.GetInput().IsKeyDown(sf::Key::Add))      View.Zoom(1.101f);
        if (App.GetInput().IsKeyDown(sf::Key::Subtract)) View.Zoom(0.899f);


        if(App.GetInput().IsKeyDown(sf::Key::A))
		{
			//sprite.Move(-1,0);
			sourceY = sLeft;
			velx = -moveSpeed;
			//player.Move(-10,0);
		}
		else if(App.GetInput().IsKeyDown(sf::Key::D))
		{
			//sprite.Move(-1,0);
			sourceY = sRight;
			velx = moveSpeed;
			//player.Move(10,0);

		}
		else
			velx = 0;

		if(App.GetInput().IsKeyDown(sf::Key::W))
		{
			//sprite.Move(-1,0);
			sourceY = sUp;
			vely = -moveSpeed;
			//player.Move(10,-1);

		}
		else if(App.GetInput().IsKeyDown(sf::Key::S))
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
			sourceX += temp.GetWidth() /4;
		else
			sourceX= 0;

		if (sourceX == temp.GetWidth())
			sourceX =0;

		player.SetSubRect(sf::IntRect(sourceX,sourceY,sourceX + temp.GetWidth() /4, sourceY + temp.GetHeight() /4));
		player.SetPosition(x,y);

		// instancio el view
        App.SetView(View);

        App.Clear();

        App.Draw(Background);

        App.Draw(player);

        sf::Vector2f CursorPos = App.ConvertCoords(App.GetInput().GetMouseX(), App.GetInput().GetMouseY());
        Cursor.SetPosition(CursorPos);
        App.Draw(Cursor);

        App.SetView(App.GetDefaultView());

        App.Draw(Text);

        App.Display();
    }

    return EXIT_SUCCESS;
}
