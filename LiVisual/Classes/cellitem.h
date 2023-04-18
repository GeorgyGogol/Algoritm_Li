#ifndef CELLITEM_H
#define CELLITEM_H

#include <QGraphicsItem>

class CellItem : public QGraphicsItem
{
public:
    explicit CellItem();
    virtual ~CellItem() = default;

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

public:
    int State = -100;

};

#endif // CELLITEM_H
