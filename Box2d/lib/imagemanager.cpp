/*
 * imagemanager.cpp
 *
 *  Created on: Nov 1, 2012
 *      Author: hector
 */
#include "imagemanager.h"
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "imagemanager.h"

image_manager::image_manager() : images_(){}

image_manager::~image_manager()
{
	images_.clear();
}

const sf::Image& image_manager::get_image( const std::string& filename )
{
	// Check, whether the image already exists
	for( std::map<std::string, sf::Image>::const_iterator it = images_.begin();
		 it != images_.end();
		 ++it)
	{
		if( filename == it->first )
		{
			std::cout << "DEBUG_MESSAGE: " << filename << " using existing image.\n";
			return it->second;
		}
	}

	// The image doesen't exists. Create it and save it.
	sf::Image image;

	if( image.LoadFromFile( filename ) )
	{
		images_[filename] = image;
		std::cout << "DEBUG_MESSAGE: " << filename << " loading image.\n";
		return images_[filename];
	}

	std::cout << "GAME_ERROR: Image was not found. It is filled with an empty image.\n";
	images_[filename] = image;
	return images_[filename];
}

void image_manager::delete_image( const sf::Image& image )
{
	for( std::map<std::string, sf::Image>::iterator it = images_.begin();
		 it != images_.end();
		 ++it)
	{
		// compare the adresses
		if( &image == &it->second )
		{
			images_.erase( it );
                        return;
		}
	}
}

void image_manager::delete_image( const std::string& filename )
{
	std::map<std::string, sf::Image>::iterator it = images_.find( filename );
	if( it != images_.end() )
		images_.erase( it );
}
