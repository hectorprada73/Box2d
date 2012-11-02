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

	sf::Sprite sprite;

public:
	//virtual ~ImageHandler();
	virtual sf::Sprite LoadImage(const string &filename, sf::Image &image)
	{

		image.LoadFromFile(filename);
		sprite.SetImage(image);

		return sprite;

	}
};

#endif /* IMAGEHANDLER_H_ */
