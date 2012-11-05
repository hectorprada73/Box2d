/*
 * personaje.cpp
 *
 *  Created on: Nov 4, 2012
 *      Author: hector
 */

#include "personaje.h"

#ifndef NULL
#define NULL 0
#endif
/* IMPLEMENTACION DE PERSONAJE */

/* Constructor*/
Personaje::Personaje():
tiempo_desde_ultima_animacion(0.f),
tiempo_entre_animaciones(0.125f),
animacion_actual(izquierda),
cuadro_actual(0)
{
  movimientos = new sf::IntRect*[NMOVIMIENTOS];
  numero_movimiento =  new int[NMOVIMIENTOS];
  numero_movimiento_almacenado =  new int[NMOVIMIENTOS];
  for (int i = 0; i< NMOVIMIENTOS; i++) {
    movimientos[i] = NULL;
    numero_movimiento[i] = 0;
    numero_movimiento_almacenado[i] = 0;

  }

}

/* Destructor */
Personaje::~Personaje() {
  for (int i = 0; i<NMOVIMIENTOS; i++) {
    borrar(static_cast<movimiento>(i));
  }
  delete [] movimientos;
  delete [] numero_movimiento;
  delete [] numero_movimiento_almacenado;
}

/* Toma el movimiento al que se le desean definir los movimientos y establece el numero de cuadros,
   toda la informacion que existiera antes se pierde */

int Personaje::establecer_numero_de_frames(const movimiento & mov, int nframes){
  if (mov >= NMOVIMIENTOS)
                return -1;
  borrar(mov);
  movimientos[mov] = new sf::IntRect[nframes];
  numero_movimiento[mov] = nframes-1;
  numero_movimiento_almacenado[mov] = 0;

}

/* Asigna los cuadros de la animacion en orden */

int Personaje::asignar_siguiente_frame(const movimiento & mov,const sf::IntRect & next) {
  if (mov >= NMOVIMIENTOS || numero_movimiento[mov]< numero_movimiento_almacenado[mov])
    return -1;
  if (movimientos[mov])
    movimientos[mov][numero_movimiento_almacenado[mov]++] = next;
}

/* Movimiento basado en entradas del usuario */

int Personaje::mover(sf::RenderWindow & App) {
       float ElapsedTime = App.GetFrameTime();
       if (App.GetInput().IsKeyDown(sf::Key::Left)){
        Move(-125 * ElapsedTime, 0);
        animar(izquierda, ElapsedTime);
       }
       else if (App.GetInput().IsKeyDown(sf::Key::Right)){
         Move( 125 * ElapsedTime, 0);
         animar(derecha, ElapsedTime);

       }
       /* Esta es una pequena maquina de estados de animacion */
       else {
         if (animacion_actual == izquierda || animacion_actual == quieto_izquierda)
           animar(quieto_izquierda, ElapsedTime);
         else
           animar(quieto_derecha,ElapsedTime);
       }
}

int Personaje::animar(const movimiento & mov, float ElapsedTime ){
  if (animacion_actual != mov) {
      animacion_actual = mov;
      tiempo_desde_ultima_animacion = 0;
      cuadro_actual = 0;
      if (movimientos[mov])
        this->SetSubRect(movimientos[mov][cuadro_actual++]);
      return 0;
  }
  tiempo_desde_ultima_animacion += ElapsedTime;
  if (tiempo_entre_animaciones < tiempo_desde_ultima_animacion){
      tiempo_desde_ultima_animacion = 0;
      if (cuadro_actual >= numero_movimiento[mov])
         cuadro_actual = 0;
      if (movimientos[mov])
        this->SetSubRect(movimientos[mov][cuadro_actual++]);
  }
    return 0;
}

/* Elimina la informacion relacionada con los movimientos */

int Personaje::borrar(const movimiento & mov){
    if (mov >= NMOVIMIENTOS)
                return -1;
    if (movimientos[mov])
      delete [] movimientos[mov];
    movimientos[mov] = 0;
    numero_movimiento[mov] = 0;
    numero_movimiento[mov] = 0;
    numero_movimiento_almacenado[mov] =0;
    return 0;
}



