/*
 * imagemanager.h
 *
 *  Created on: Nov 1, 2012
 *      Author: hector
 */

#ifndef IMAGE_MANAGER_H_
#define IMAGE_MANAGER_H_

#include <SFML/Graphics.hpp>

using namespace std;

class image_manager

{

public:
	image_manager();
	~image_manager();

private:
	image_manager( const image_manager& );
	image_manager& operator =( const image_manager& );

public:
	const sf::Image&	get_image( const std::string& filename );
	void				delete_image( const sf::Image& image );
	void				delete_image( const std::string& filename );

private:
	std::map< std::string, sf::Image > images_;
	std::vector< std::string > resource_directories_;
};

#endif /* IMAGEMANAGER_H_ */
