#ifndef CELLITEM_H
#define CELLITEM_H

#include <QGraphicsItem>

#include "FieldCell.h"

class CellItem : public QGraphicsItem
{
public:
    explicit CellItem(algo::FieldCell* ptr);
    virtual ~CellItem() = default;

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public:
	algo::FieldCell* pCell;

};

#endif // CELLITEM_H
