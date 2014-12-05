//##########################################################################
//#                                                                        #
//#                            CLOUDCOMPARE                                #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: EDF R&D / TELECOM ParisTech (ENST-TSI)             #
//#                                                                        #
//##########################################################################

#include "ccOrthoSectionGenerationDlg.h"

//system
#include <math.h>

ccOrthoSectionGenerationDlg::ccOrthoSectionGenerationDlg(QWidget* parent/*=0*/)
	: QDialog(parent)
	, Ui::OrthoSectionGenerationDlg()
	, m_pathLength(0)
{
	setupUi(this);
	setWindowFlags(Qt::Tool);

	connect(stepDoubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(onStepChanged(double)));
}

void ccOrthoSectionGenerationDlg::setPathLength(double l)
{
	m_pathLength = l;
	pathLengthLineEdit->setText(QString::number(l));
	stepDoubleSpinBox->setValue(l/9);
	widthDoubleSpinBox->setValue(l/5);
}

double ccOrthoSectionGenerationDlg::getGenerationStep() const
{
	return stepDoubleSpinBox->value();
}

double ccOrthoSectionGenerationDlg::getSectionsWidth() const
{
	return widthDoubleSpinBox->value();
}

void ccOrthoSectionGenerationDlg::onStepChanged(double step)
{
	if (step < 0)
		return;

	unsigned count = step < 1.0e-6 ? 1 : 1+static_cast<unsigned>(floor(m_pathLength / step));
	sectionCountLineEdit->setText(QString::number(count));
}