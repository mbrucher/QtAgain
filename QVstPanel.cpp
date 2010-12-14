/**
 * \file QVstPanel.cpp
 */

#include <boost/lexical_cast.hpp>

#include <QtGui/QHBoxLayout>

#include "QVstPanel.h"
#include "again.h"

QVstPanel::QVstPanel(AudioEffectX *again, HWND h_parent)
:QWinWidget(h_parent, NULL), again(again), h_parent(h_parent)
{
  setAttribute(Qt::WA_DeleteOnClose);
  //setAttribute(Qt::WA_LayoutUsesWidgetRect);

  QLabel *label = new QLabel("Gain", this);
  valueLabel = new QLabel("0", this);
  slider = new QSlider(Qt::Horizontal, this);

  QHBoxLayout *layout = new QHBoxLayout(this);
  layout->addWidget(label);
  layout->addWidget(valueLabel);
  layout->addWidget(slider);

  setLayout(layout);
  
  connect(slider, SIGNAL(valueChanged(int)), this, SLOT(update(int)));
}

void QVstPanel::update(int value)
{
  valueLabel->setText(QString::number(value));
  again->setParameter(0, value / 100.);
}

void QVstPanel::update(float value)
{
  int intValue = value * 100;
  valueLabel->setText(QString::number(intValue));
  slider->setValue(intValue);  
}
