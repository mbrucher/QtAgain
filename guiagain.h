/**
 * \file guiagain.h
 */

#include <qwinwidget.h>
#include "aeffeditor.h"

class QVstPanel;

class QtAGain : public QObject, public AEffEditor
{
  Q_OBJECT
  
  QWinWidget* widget;
  AudioEffectX* effect;

public:
  QtAGain(AudioEffectX* effect)
    :widget(NULL), effect(effect)
  {
  }

  ~QtAGain()
  {
  }

  virtual bool open(void* ptr);
  virtual bool getRect (ERect** rect);
  virtual void close();

signals:
  void update(float value);

protected:
  ERect rectangle;
};

void clientResize(HWND h_parent, int width, int height);
