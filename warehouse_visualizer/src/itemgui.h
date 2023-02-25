#ifndef _ITEM_GUI_H
#define _ITEM_GUI_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>
#include <vector>
#include "overtaken/objects.h"

using namespace std;

class ItemGui : public QGraphicsItem
{
public:
    ItemGui(float _x_coord, float _y_coord, float _width, float _height, QColor _color, vector<QString> _data_to_show);
    ~ItemGui();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // for updating the whole scene after clicking on the object, nothing more
    QGraphicsScene *sc;

    /// @brief change color of the item for yellow by default
    void setColor2(QColor color = Qt::yellow);

    /// @brief focus the item
    void focus();

    /// @brief unfocus the item, return the items default color
    void unfocus();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    // description data
    float x_coord;
    float y_coord;
    float width;
    float height;
    QColor color;

    // set up color (primarily for focus)
    QColor color2 = Qt::yellow;

    // whether the item is focused
    bool is_focused = false;

    // data about the warehouse item to be shown while clicked
    vector<QString> data_to_show;

    // whether data are shown already or not
    bool data_displayed = false;
};

#endif
