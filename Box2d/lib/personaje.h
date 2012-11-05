/*
 * personaje.h
 *
 *  Created on: Nov 4, 2012
 *      Author: hector
 */

#ifndef __PERSONAJE__
#define __PERSONAJE__
#include <SFML/Graphics.hpp>

/* Clase personaje, sirve para manejar la animacion de los Sprites */
class Personaje: public sf::Sprite {
public:
  Personaje();

  ~Personaje();
  enum movimiento{derecha, izquierda, saltar, agacharse, quieto_izquierda, quieto_derecha, NMOVIMIENTOS};
  int borrar(const movimiento &);
  int establecer_numero_de_frames(const movimiento &, int nframes);
  int asignar_siguiente_frame(const movimiento &,const sf::IntRect &);
  int mover(sf::RenderWindow & App);
private:
  int animar(const movimiento &, float ElapsedTime);
private:
  sf::IntRect ** movimientos;
  int * numero_movimiento;
  int * numero_movimiento_almacenado;
  float tiempo_desde_ultima_animacion;
  float tiempo_entre_animaciones;
  movimiento animacion_actual;
  int cuadro_actual;
};
#endif

