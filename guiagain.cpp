/**
 * \file guiagain.cpp
 */

#include <windows.h>

#include <qwinwidget.h>

#include "guiagain.h"
#include "QVstPanel.h"

bool QtAGain::open(void* ptr)
{
  AEffEditor::open (ptr);
  widget = new QVstPanel(effect, static_cast<HWND>(ptr));
  widget->move( 0, 0 );
  widget->adjustSize();
  rectangle.top = 0;
  rectangle.left = 0;
  rectangle.bottom = widget->height();
  rectangle.right = widget->width();
  widget->setMinimumSize(widget->size());
  widget->show();
  clientResize(static_cast<HWND>(ptr), widget->width(), widget->height());

  connect(this, SIGNAL(update(float)), widget, SLOT(update(float)));
  return true;
}

void QtAGain::close()
{
  disconnect(this, SIGNAL(update(float)), widget, SLOT(update(float)));
  delete widget;
}

bool QtAGain::getRect (ERect** rect)
{
  *rect = &rectangle;
  return true;
}

void clientResize(HWND h_parent, int width, int height)
{
  RECT rcClient, rcWindow;
  POINT ptDiff;
  GetClientRect(h_parent, &rcClient);
  GetWindowRect(h_parent, &rcWindow);
  ptDiff.x = (rcWindow.right - rcWindow.left) - rcClient.right;
  ptDiff.y = (rcWindow.bottom - rcWindow.top) - rcClient.bottom;
  MoveWindow(h_parent, rcWindow.left, rcWindow.top, width + ptDiff.x, height + ptDiff.y, TRUE);
}
