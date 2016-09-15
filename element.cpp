#include "element.h"

#include <QRegExp>
#include <QDebug>

Element::Element()
{

}

void Element::chamfer(const QString &designation)
{
    QRegExp chamferRx(
                "([\\s\\S]*[^\\d,])?"             // Текст до      (1)
                "(\\d+\\,?\\d*)\\s*"              // Значение      (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)°\\s*"             // Угол          (3)
                "([\\s\\S]*)?"                    // Текст после   (4)
                );

    int pos = chamferRx.indexIn(designation);
    if (pos > -1) {
        QString before = chamferRx.cap(1); // Текст до
        QString f = chamferRx.cap(2);      // Диаметр
        QString a = chamferRx.cap(3);      // Шаг
        QString after = chamferRx.cap(4);  // Текст после

        qDebug() << "\n"
                 << "     Элемент:" << "Фаска" << "\n"
                 << "    Текст до:" << before << "\n"
                 << "    Значение:" << f  << "\n"
                 << "        Угол:" << a  << "\n"
                 << " Текст после:" << after << "\n";
    }
}

void Element::lineDimension(const QString &designation)
{
    QRegExp lineDimensionRx(
                "([^\\,\\d]*)"                             // Текст до      (1)
                "(\\d+\\,?\\d*)\\s*"                       // Значение      (2)
                "([a-zA-z]{1,2}\\d{1,2})?\\s*"             // Класс допуска (3)
                "("
                   "(\\("
                      "([\\+\\-]?[\\+\\-]?\\d+\\,?\\d*)\\s*"   // Верхнее отклонение (6)
                      "(\\;\\s*([\\+\\-]?\\d+\\,?\\d*)\\s*)?"  // Нижнее отклонение  (8)
                   "\\)\\s*)"
                   "|(\\(?"
                      "((±)|(\\+\\-))"
                      "(\\d+\\,?\\d*)"                     // Верх./нижн. отклонение (13)
                   "\\)?\\s*)"
                ")?"
                "([\\s\\S]*)?"                             // Текст после   (14)
                );
    int pos = lineDimensionRx.indexIn(designation);
    if (pos > -1) {
        QString before = lineDimensionRx.cap(1);    // Текст до
        QString nominal = lineDimensionRx.cap(2);   // Значение
        QString tolClass = lineDimensionRx.cap(3);  // Класс допуска
        QString es = lineDimensionRx.cap(6);        // Верхнее отклонение
        QString ei = lineDimensionRx.cap(8);        // Нижнее отклонение
        QString es_ei = lineDimensionRx.cap(13);    // Верх./нижн. отклонение
        QString after = lineDimensionRx.cap(14);    // Текст после

        qDebug() << "\n"
                 << "               Элемент:" << "Линейный размер:" << "\n"
                 << "              Текст до:" << before << "\n"
                 << "              Значение:" << nominal  << "\n"
                 << "         Класс допуска:" << tolClass  << "\n"
                 << "    Верхнее отклонение:" << es << "\n"
                 << "     Нижнее отклонение:" << ei << "\n"
                 << "Верх./нижн. отклонение:" << es_ei << "\n"
                 << "           Текст после:" << after << "\n";
    }
}

void Element::angleDimension(const QString &designation)
{

}
