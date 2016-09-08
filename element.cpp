#include "element.h"

#include <QRegExp>
#include <QDebug>

Element::Element()
{

}

void Element::chamfer(const QString &designation)
{
    QRegExp chamferRx(
                "([\\s\\S]*[^\\d],)?"             // Текст до      (1)
                "(\\d+\\,?\\d*)\\s*"              // Значение      (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)°\\s*"              // Угол          (3)
                "([\\s\\S]*)?"                    // Текст после   (4)
                );

    int pos = chamferRx.indexIn(designation);
    if (pos > -1) {
        QString Before = chamferRx.cap(1); // Текст до
        QString F = chamferRx.cap(2);      // Диаметр
        QString A = chamferRx.cap(3);      // Шаг
        QString After = chamferRx.cap(4);  // Текст после

        qDebug() << "\n"
                 << "     Элемент:" << "Фаска" << "\n"
                 << "    Текст до:" << Before << "\n"
                 << "    Значение:" << F  << "\n"
                 << "        Угол:" << A  << "\n"
                 << " Текст после:" << After << "\n";
    }
}

void Element::lineDimension(const QString &designation)
{

}

void Element::angleDimension(const QString &designation)
{

}
