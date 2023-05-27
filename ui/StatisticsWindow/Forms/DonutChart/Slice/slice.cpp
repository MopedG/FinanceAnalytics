#include "slice.h"



Slice::Slice(const QString &label, qreal value, QObject *parent)
    : QPieSlice(label, value, parent)
{
    setLabelVisible();
    setStyle();
}

void Slice::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit sliceClicked(this);
}

void Slice::setStyle(){
    setLabelFont(QFont("Verdana", 14));
    setLabelColor(QColorConstants::White);

    setBorderColor(QColorConstants::Transparent);
    setBorderWidth(0);
}
