#include "element.h"

#include <QRegularExpression>

Element::Element()
{

}

QString Element::chamfer(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"             // Текст до      (1)
                "(\\d+\\,?\\d*)\\s*"              // Значение      (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)°\\s*"             // Угол          (3)
                "([\\s\\S]*)?"                    // Текст после   (4)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString f = match.captured(2);      // Диаметр
        QString a = match.captured(3);      // Шаг
        QString after = match.captured(4);  // Текст после

        result = QString("     Элемент: Фаска\n")
                + QString("    Текст до: %1\n").arg(before)
                + QString("    Значение: %1\n").arg(f)
                + QString("        Угол: %1\n").arg(a)
                + QString(" Текст после: %1\n").arg(after);
    }
    return result;
}

QString Element::lineDimension(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                             // Текст до      (1)
                "(\\d+\\,?\\d*)\\s*"                       // Значение      (2)
                "([a-zA-z]{1,2}\\d{1,2})?\\s*"             // Класс допуска (3)
                "("
                   "(\\(?"
                      "([\\+\\-]?\\d+\\,?\\d*)\\s*"             // Верхнее отклонение (6)
                      "(\\;\\s*([\\+\\-]?\\d+\\,?\\d*)\\s*)?"   // Нижнее отклонение  (8)
                   "\\)?\\s*)"
                   "|(\\(?"
                      "((±)|(\\+\\-))"
                      "(\\d+\\,?\\d*)"                     // Верх./нижн. отклонение (13)
                   "\\)?\\s*)"
                ")?"
                "([\\s\\S]*)?"                             // Текст после   (14)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1);    // Текст до
        QString nominal = match.captured(2);   // Значение
        QString tolClass = match.captured(3);  // Класс допуска
        QString es = match.captured(6);        // Верхнее отклонение
        QString ei = match.captured(8);        // Нижнее отклонение
        QString es_ei = match.captured(13);    // Верх./нижн. отклонение
        QString after = match.captured(14);    // Текст после

        result  = QString("               Элемент: Линейный размер\n")
                + QString("              Текст до: %1\n").arg(before)
                + QString("              Значение: %1\n").arg(nominal)
                + QString("         Класс допуска: %1\n").arg(tolClass)
                + QString("    Верхнее отклонение: %1\n").arg(es)
                + QString("     Нижнее отклонение: %1\n").arg(ei)
                + QString("Верх./нижн. отклонение: %1\n").arg(es_ei)
                + QString("           Текст после: %1\n").arg(after);
    }
    return result;
}

QString Element::angleDimension(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                      // Текст до      (1)
                "(\\d+\\,?\\d*[°'\"]"              // Значение      (2)
                "(\\d+\\,?\\d*[°'\"])?"
                "(\\d+\\,?\\d*[°'\"])?)\\s*"
                "("
                   "(\\(?"
                      "([\\+\\-]?\\d+\\,?\\d*[°'\"]"           // Верхнее отклонение (7)
                      "(\\d+\\,?\\d*[°'\"])?"
                      "(\\d+\\,?\\d*[°'\"])?)\\s*"
                      "(\\;\\s*([\\+\\-]?\\d+\\,?\\d*[°'\"]"   // Нижнее отклонение  (11)
                      "(\\d+\\,?\\d*[°'\"])?"
                      "(\\d+\\,?\\d*[°'\"])?)\\s*)?"
                   "\\)?\\s*)"
                   "|(\\(?"
                      "((±)|(\\+\\-))"
                      "(\\d+\\,?\\d*[°'\"]"        // Верх./нижн. отклонение (18)
                      "(\\d+\\,?\\d*[°'\"])?"
                      "(\\d+\\,?\\d*[°'\"])?)"
                   "\\)?\\s*)"
                ")?"
                "([\\s\\S]*)?"                      // Текст после   (21)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1);    // Текст до
        QString nominal = match.captured(2);   // Значение
        QString es = match.captured(7);        // Верхнее отклонение
        QString ei = match.captured(11);       // Нижнее отклонение
        QString es_ei = match.captured(18);    // Верх./нижн. отклонение
        QString after = match.captured(21);    // Текст после

        result  = QString("               Элемент: Угловой размер\n")
                + QString("              Текст до: %1\n").arg(before)
                + QString("              Значение: %1\n").arg(nominal)
                + QString("    Верхнее отклонение: %1\n").arg(es)
                + QString("     Нижнее отклонение: %1\n").arg(ei)
                + QString("Верх./нижн. отклонение: %1\n").arg(es_ei)
                + QString("           Текст после: %1\n").arg(after);
    }
    return result;
}

QString Element::anyDimension(const QString &designation)
{
    QString result;

    result = this->chamfer(designation);
    if (!result.isEmpty()) return result;

    result = this->angleDimension(designation);
    if (!result.isEmpty()) return result;

    result = this->lineDimension(designation);
    if (!result.isEmpty()) return result;



    return "";
}
