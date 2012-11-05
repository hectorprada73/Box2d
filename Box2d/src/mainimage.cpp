#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../lib/imagemanager.h"
#include "../lib/principe.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode( 1161, 700 ), "prueba" );


	image_manager img_mgr;
	window.SetFramerateLimit(30);
	Principe jugador(img_mgr);
	Principe juga(img_mgr);

	//sf::Sprite test_sprite[20];
	sf::Sprite background, agente1, agente2;
	//sf::Sprite other_sprite[20];
	// initialise all sprites
//	for( int i = 0; i < 20; ++i )
//	{
//		test_sprite[i].SetImage( img_mgr.get_image( "/home/hector/git/Box2d/Box2d/imagenes/cursor.png" ) );
//		//other_sprite[i].SetImage( img_mgr.get_image( "/home/hector/git/Box2d/Box2d/imagenes/Player.png" ) );
//
//		test_sprite[i].SetPosition( i*40, 0 );
//		//other_sprite[i].SetPosition( i*50, 100 );
//	}

	background.SetImage(img_mgr.get_image("/home/hector/git/Box2d/Box2d/imagenes/map.png"));
	agente1.SetImage(img_mgr.get_image("/home/hector/git/Box2d/Box2d/imagenes/Player.png"));
	agente2.SetImage(img_mgr.get_image("/home/hector/git/Box2d/Box2d/imagenes/Player2.png"));
    agente1.SetPosition(50,50);
    agente2.SetPosition(150,150);
    bool isVisible = true;

    //creo el view centrado en center
    sf::Vector2f Center(500, 300);
    sf::Vector2f HalfSize(400, 300);
    sf::View View(Center, HalfSize);

    while (window.IsOpened())
    {
        sf::Event Event;
        window.Clear();
        window.Draw( background);
        while (window.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                window.Close();
			// You should not do this, but we will; just to verify that it works correctly ;
            if (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Space )
            {
            	isVisible = false;
            	img_mgr.delete_image( img_mgr.get_image( "/home/hector/git/Box2d/Box2d/imagenes/Player2.png" ) );
           	}
            	//agente2.SetPosition(900,620);
            float Offset = 200.f * window.GetFrameTime();
			if (window.GetInput().IsKeyDown(sf::Key::Up))    View.Move( 0,      -Offset);
			if (window.GetInput().IsKeyDown(sf::Key::Down))  View.Move( 0,       Offset);
			if (window.GetInput().IsKeyDown(sf::Key::Left))  View.Move(-Offset,  0);
			if (window.GetInput().IsKeyDown(sf::Key::Right)) View.Move( Offset,  0);

			//zoom y unzoom

			if (window.GetInput().IsKeyDown(sf::Key::Add))      View.Zoom(1.101f);
			if (window.GetInput().IsKeyDown(sf::Key::Subtract)) View.Zoom(0.899f);


			//if (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::LControl )
			//	img_mgr.delete_image( img_mgr.get_image( "other.png" ) );
        }
        if (isVisible == true)
        	window.Draw(agente2);

		// Draw sprites
//		for( int i = 0; i < 20; ++i )
//		{
//			window.Draw( test_sprite[i] );
//			//window.Draw( other_sprite[i] );
//		}
        jugador.mover(window);
        window.SetView(View);
        window.Draw(jugador);
        window.Draw(juga);
        window.Draw(agente1);
        //window.Draw(agente2);
        window.Display();
    }

    return EXIT_SUCCESS;
}
