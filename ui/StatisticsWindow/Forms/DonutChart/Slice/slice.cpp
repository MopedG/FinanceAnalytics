#include "slice.h"

Slice::Slice(const QString &label, qreal value, QObject *parent)
    : QPieSlice(label, value, parent)
{
    setLabelVisible();
}

void Slice::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit sliceClicked(this);
}
