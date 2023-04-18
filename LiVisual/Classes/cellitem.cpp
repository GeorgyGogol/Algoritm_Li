#include "cellitem.h"

#include <QPainter>

CellItem::CellItem(algo::FieldCell* ptr) :
    QGraphicsItem(nullptr),
	pCell(ptr)
{
}

QRectF CellItem::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void CellItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();

	int State = pCell->getStatus();

    QRectF dCell = boundingRect();
    painter->setPen(Qt::black);
    painter->drawRect(dCell);

    dCell.setX(dCell.x() + 2);
    dCell.setWidth(dCell.width() - dCell.x());
    dCell.setY(dCell.y() + 2);
    dCell.setHeight(dCell.height() - dCell.y());

    if (State == -2 || State == -3)
    {
        switch (State) {
        case -2:
            painter->setBrush(Qt::black);
            break;

        case -3:
            painter->setBrush(Qt::yellow);
            break;

        default:
            break;
        }

        painter->drawRect(dCell);
    }
    if (pCell->getMovePoints() >= 0)
    {
        painter->drawText(dCell, Qt::AlignCenter, QString::number(pCell->getMovePoints()));
    }

    painter->restore();
}
