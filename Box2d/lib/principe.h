/*
 * principe.h
 *
 *  Created on: Nov 4, 2012
 *      Author: hector
 */

#ifndef PRINCIPE_H_
#define PRINCIPE_H_
#include "imagemanager.h"
#include <SFML/Graphics.hpp>
#include "personaje.h"

class Principe: public Personaje {
public:


    Principe(image_manager &adm);
    image_manager  & administrador_de_imagenes;
private:




};


#endif /* PRINCIPE_H_ */
