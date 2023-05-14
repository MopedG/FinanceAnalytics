#include "pieslice.h"

PieSlice::PieSlice(const QString &label, qreal value, QObject *parent)
    : QPieSlice(label, value, parent)
{
    setLabelVisible();
}

void PieSlice::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit sliceClicked(this);
}
