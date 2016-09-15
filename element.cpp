#include "element.h"

#include <QRegularExpression>
#include <QDebug>

Element::Element()
{

}

void Element::chamfer(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"             // Текст до      (1)
                "(\\d+\\,?\\d*)\\s*"              // Значение      (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)°\\s*"             // Угол          (3)
                "([\\s\\S]*)?"                    // Текст после   (4)
                );

    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString f = match.captured(2);      // Диаметр
        QString a = match.captured(3);      // Шаг
        QString after = match.captured(4);  // Текст после

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
    QRegularExpression regex(
                "([\\s\\S]*?)"                             // Текст до      (1)
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

    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1);    // Текст до
        QString nominal = match.captured(2);   // Значение
        QString tolClass = match.captured(3);  // Класс допуска
        QString es = match.captured(6);        // Верхнее отклонение
        QString ei = match.captured(8);        // Нижнее отклонение
        QString es_ei = match.captured(13);    // Верх./нижн. отклонение
        QString after = match.captured(14);    // Текст после

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
