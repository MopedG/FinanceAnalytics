#pragma once

#include "qgraphicsitem.h"
#include <QObject>
#include <QPieSlice>
#include <QWidget>

class PieSlice : public QPieSlice
{
    Q_OBJECT

public:
    PieSlice(const QString &label, qreal value, QObject *parent = nullptr);

signals:
    void sliceClicked(PieSlice *slice);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};




