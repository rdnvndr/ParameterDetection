#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>

class Element
{
public:
    Element();

    //! Фаска
    void chamfer(const QString &designation);

    //! Линейный размер
    void lineDimension(const QString &designation);

    //! Угловой размер
    void angleDimension(const QString &designation);
};

#endif // ELEMENT_H
