#ifndef ELEMENT_H
#define ELEMENT_H

#include <QString>

class Element
{
public:
    Element();

    //! Фаска
    QString chamfer(const QString &designation);

    //! Линейный размер
    QString lineDimension(const QString &designation);

    //! Угловой размер
    QString angleDimension(const QString &designation);

    //! Любой размер
    QString anyDimension(const QString &designation);
};

#endif // ELEMENT_H
