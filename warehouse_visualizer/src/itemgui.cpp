#include "itemgui.h"
#include "debug.h"

ItemGui::ItemGui(float _x_coord, float _y_coord, float _width, float _height, QColor _color, vector<QString> _data_to_show) : x_coord(_x_coord), y_coord(_y_coord), width(_width), height(_height), color(_color), data_to_show(_data_to_show)
{
    // set the value to make the item be in the front
    setZValue(10);

    // accept mouse hover
    // TODO
    setAcceptHoverEvents(true);

    this->setPos(0, 0);
}

ItemGui::~ItemGui()
{
}

QRectF ItemGui::boundingRect() const
{
    return QRectF(this->x_coord, this->y_coord, this->width, this->height);
}

void ItemGui::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (this->is_focused)
    {
        // item is focused
        painter->fillRect(this->boundingRect(), this->color2);
    }
    else
    {
        // item isn't focused
        painter->fillRect(this->boundingRect(), this->color);
    }

    // this->drawData(painter);
}

void ItemGui::setColor2(QColor color)
{
    this->color2 = color;
}

void ItemGui::focus()
{
    this->is_focused = true;
    this->sc->update();
}

void ItemGui::unfocus()
{
    this->is_focused = false;
    this->sc->update();
}

void ItemGui::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_DEBUG_PRINTOUT("mousePressEvent")

    // update the canvas
    this->sc->update();
    // change the state of display marking variable
    // this->data_displayed = !this->data_displayed;

    // write the data to the textbox

    // let continue the mouse press event
    QGraphicsItem::mousePressEvent(event);
}

void ItemGui::drawData(QPainter *painter)
{
    if (this->data_displayed)
    {
        QFont font("arial", 10); //-> for text length measure
        QFontMetrics fontMetrics(font);
        painter->setFont(font);

        int i = 0; // helper variable for moving line by line
        for (auto data_t : this->data_to_show)
        {
            painter->drawText(this->x_coord + this->width + 1, this->y_coord + i, data_t);
            i += 11; // move the text line by line
        }
    }
}
