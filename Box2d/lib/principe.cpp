/*
 * principe.cpp
 *
 *  Created on: Nov 4, 2012
 *      Author: hector
 */

#include "principe.h"
#include <SFML/Graphics.hpp>

Principe::Principe( image_manager & adm): administrador_de_imagenes(adm)
{
   Principe & jugador = *this;
   jugador.SetImage(administrador_de_imagenes.get_image("/home/hector/git/Box2d/Box2d/imagenes/prince.jpg"));
   jugador.SetPosition(700.0,300.0);
   jugador.SetSubRect(sf::IntRect(727, 100, 780, 184));
   /* Adicionar cuadros de la animacion */
   jugador.establecer_numero_de_frames(Personaje::izquierda, 11);
   jugador.establecer_numero_de_frames(Personaje::derecha, 11);
   jugador.establecer_numero_de_frames(Personaje::quieto_izquierda, 1);
   jugador.establecer_numero_de_frames(Personaje::quieto_derecha, 1);
   /* Movimientos cuando este quieto mirando a la izquierda */
   jugador.asignar_siguiente_frame(Personaje::quieto_izquierda,sf::IntRect(15, 0, 45, 100));
   /* Movimientos a la izquierda */
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(1230, 100, 1286, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(1160, 100, 1230, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(1095, 100, 1157, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(1030, 100, 1090, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(980, 100, 1030, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(910, 100, 980, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(840, 100, 910, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(780, 100, 840, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(727, 100, 780, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(670, 100, 727, 185));
   jugador.asignar_siguiente_frame(Personaje::izquierda,sf::IntRect(620, 100, 670, 185));
   /* Movimientos cuando este quieto mirando a la derecha */
   jugador.asignar_siguiente_frame(Personaje::quieto_derecha,sf::IntRect(1027, 0, 1060, 100));
   /* Movimientos a la izquierda */
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(50, 1220, 100, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(100, 1220, 170, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(170, 1220, 240, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(240, 1220, 300, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(300, 1220, 350, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(350, 1220, 420, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(420, 1220, 490, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(490, 1220, 550, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(550, 1220, 605, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(660, 1220, 720, 1305));
   jugador.asignar_siguiente_frame(Personaje::derecha,sf::IntRect(720, 1220, 770, 1305));
}



