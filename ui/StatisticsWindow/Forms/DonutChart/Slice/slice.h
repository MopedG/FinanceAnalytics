#pragma once

#include "qgraphicsitem.h"
#include <QObject>
#include <QPieSlice>
#include <QWidget>

class Slice : public QPieSlice
{
    Q_OBJECT

public:
    Slice(const QString &label, qreal value, QObject *parent = nullptr);

signals:
    void sliceClicked(Slice *slice);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setStyle();
};




