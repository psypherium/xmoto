/*=============================================================================
XMOTO

This file is part of XMOTO.

XMOTO is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

XMOTO is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with XMOTO; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
=============================================================================*/

#ifndef __STATEPREPLAYING_H__
#define __STATEPREPLAYING_H__

#include "StateScene.h"

class StatePreplaying : public StateScene {
  public:
  StatePreplaying(GameApp* pGame, const std::string i_idlevel);
  virtual ~StatePreplaying();
  
  virtual void enter();
  virtual void leave();
  /* called when a new state is pushed or poped on top of the
     current one*/
  virtual void enterAfterPop();
  virtual void leaveAfterPush();
  
  virtual bool update();
  virtual bool render();
  /* input */
  virtual void keyDown(int nKey, SDLMod mod,int nChar);
  virtual void keyUp(int nKey,   SDLMod mod);
  virtual void mouseDown(int nButton);
  virtual void mouseDoubleClick(int nButton);
  virtual void mouseUp(int nButton);

  static void setPlayAnimation(bool i_value);

  private:
  void executeOneCommand(std::string cmd);
  bool needToDownloadGhost();

  void secondInitPhase();
  bool m_secondInitPhaseDone;
  bool m_ghostDownloaded;

  std::string m_idlevel;

  bool shouldBeAnimated() const; // return true wether the animation shoud be done

  static bool m_playAnimation; // must the animation be played ; must be rearmed each time you play a new level

  /* animation */
  float m_fPrePlayStartTime;
  float m_fPrePlayStartInitZoom;
  float m_fPrePlayStartCameraX;
  float m_fPrePlayStartCameraY;
  float m_fPrePlayCameraLastX;
  float m_fPrePlayCameraLastY;
  float m_fPreCameraStartX;
  float m_fPreCameraStartY;
  float m_fPreCameraFinalX;
  float m_fPreCameraFinalY;
  float m_zoomX;
  float m_zoomY;
  float m_zoomU;
  float static_time;

  void zoomAnimation1_init();
  bool zoomAnimation1_step();
  void zoomAnimation1_abort();
};

#endif