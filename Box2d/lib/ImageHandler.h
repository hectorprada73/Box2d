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

class ImageHandler {
	sf::Image image;
	sf::Sprite sprite;

public:

	//virtual ~ImageHandler();


	sf::Sprite LoadImage(string filename)
	{
		if (!image.LoadFromFile(filename))
			cout << "no cargo imagen" << endl;

			sprite.SetImage(image);

			return sprite;
	}

};

#endif /* IMAGEHANDLER_H_ */
