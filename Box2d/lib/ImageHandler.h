/*
 * ImageHandler.h
 *
 *  Created on: Oct 27, 2012
 *      Author: ndy
 */

#ifndef IMAGEHANDLER_H_
#define IMAGEHANDLER_H_

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class ImageHandler{

private :

    sf::Image  Image;
    sf::Sprite Sprite;

public:

	//virtual ~ImageHandler();


//	sf::Sprite LoadImage(string filename)
//	{
//		if (!image.LoadFromFile(filename))
//			cout << "no cargo imagen" << endl;
//
//			sprite.SetImage(image);
//
//			return sprite;
//	}


	    // This is the copy constructor
	ImageHandler(const ImageHandler& Copy) : Image(Copy.Image), Sprite(Copy.Sprite)
	    {
	        // This is the trick : we setup the sprite
	        // to use our image, instead of the one of Copy
	        Sprite.SetImage(Image);
	    }

	    // ... a lot of useful functions ...



};

#endif /* IMAGEHANDLER_H_ */
