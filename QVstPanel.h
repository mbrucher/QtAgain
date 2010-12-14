/**
 * \file QVstPanel.h
 */

#include <qwinwidget.h>
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QSlider>

class AudioEffectX;

class QVstPanel : public QWinWidget
{
  Q_OBJECT
  
  HWND h_parent;
  AudioEffectX *again;
  QLabel *valueLabel;
  QSlider *slider;

  void clientResize(int width, int height);
  
public slots:
  void update(int value);
  void update(float value);
  
public:
  QVstPanel(AudioEffectX *again, HWND h_parent = NULL);
};
