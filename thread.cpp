#include "thread.h"

#include <QRegularExpression>


Thread::Thread()
{

}

QString Thread::metricalThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                              // Текст до (1)
                "M\\s*"                                     // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"                       // Диаметр  (2)
                "("
                   "("
                      "[xX]\\s*"                                    // Знак умножения
                      "([Pp][Hh])\\s*"                              // Многозаходность (5)
                      "(\\d+\\,?\\d*)\\s*P\\s*"                     // Ход резьбы      (6)
                      "(\\d+\\,?\\d*)\\s*"                          // Шаг резьбы      (7)
                      "\\(\\s*([А-Яа-я]+\\s+[А-Яа-я]+)\\s*\\)\\s*"  // Кол-во заходов  (8)
                   ")|([xX]\\s*(\\d+\\,?\\d*)\\s*)"                 // Шаг резьбы      (10)
                ")?"

                "(\\-\\s*(\\d{1,1}\\w{1,1}\\d?\\w?))?\\s*"      // Допуск (12)
                "(\\-\\s*"
                   "([SsLl])?\\s*"                              // Группа свинчивания (14)
                   "(\\(\\s*(\\d+\\,?\\d*)\\s*\\))?\\s*"        // Длина  свинчивания (16)
                ")?"
                "(\\-\\s*([Ll][Hh]))?\\s*"                  // Левая резьба (18)
                "([\\s\\S]*)?"                              // Текст после  (19)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1);  // Текст до
        QString d = match.captured(2);       // Диаметр
        QString ph = match.captured(5);      // Многозаходность
        QString h = match.captured(6);       // Ход
        QString p = match.captured(7);       // Шаг
        QString z = match.captured(8);       // Заходы
        QString p1 = (p.isEmpty())
                ? match.captured(10) : p;    // Шаг
        QString t = match.captured(12);      // Допуск
        QString g = match.captured(14);      // Группа длины свинчивания
        QString l = match.captured(16);      // Длина свинчивания
        QString lh = match.captured(18);     // Левая резьба
        QString after = match.captured(19);  // Текст после

        result  = QString("        Тип резьбы: Метрическая резьба\n")
                + QString("          Текст до: %1\n").arg(before)
                + QString("           Диаметр: %1\n").arg(d)
                + QString("   Многозаходность: %1\n").arg(ph)
                + QString("               Ход: %1\n").arg(h)
                + QString("           Заходов: %1\n").arg(z)
                + QString("               Шаг: %1\n").arg(p1)
                + QString("            Допуск: %1\n").arg(t)
                + QString("Группа свинчивания: %1\n").arg(g)
                + QString(" Длина свинчивания: %1\n").arg(l)
                + QString("      Левая резьба: %1\n").arg(lh)
                + QString("       Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::metricalMjThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                             // Текст до       (1)
                "MJ\\s*"                                   // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"                      // Диаметр        (2)
                "("
                   "[xX]\\s*"                              // Знак умножения
                   "(\\d+\\,?\\d*)\\s*"                    // Шаг резьбы     (4)
                ")?"
                "(\\-\\s*(\\d{1,1}\\w{1,1}\\d?\\w?))?\\s*" // Допуск         (6)
                "(\\-\\s*([Ll][Hh]))?\\s*"                 // Левая резьба   (8)
                "([\\s\\S]*)?"                             // Текст после    (9)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString p = match.captured(4);      // Шаг
        QString t = match.captured(6);      // Допуск
        QString lh = match.captured(8);     // Левая резьба
        QString after = match.captured(9);  // Текст после

        result  = QString("  Тип резьбы: Метрическая резьба с профилем MJ\n")
                + QString("    Текст до: %1\n").arg(before)
                + QString("     Диаметр: %1\n").arg(d)
                + QString("         Шаг: %1\n").arg(p)
                + QString("      Допуск: %1\n").arg(t)
                + QString("Левая резьба: %1\n").arg(lh)
                + QString(" Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::trapezoidalMultiStartThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                             // Текст до           (1)
                "Tr\\s*"                                   // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"                      // Диаметр            (2)
                "[xX]\\s*"                                 // Знак умножения
                "(\\d+\\,?\\d*)"                           // Ход резьбы         (3)
                "\\(\\s*P\\s*"
                "(\\d+\\,?\\d*)\\s*"                       // Шаг резьбы         (4)
                "\\)\\s*"
                "([Ll][Hh])?\\s*"                          // Левая резьба       (5)
                "(\\-\\s*(\\d{1,1}\\w{1,1}\\d?\\w?))?\\s*" // Допуск             (7)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"             // Длина  свинчивания (9)
                "([\\s\\S]*)?"                             // Текст после        (10)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString h = match.captured(3);      // Ход
        QString p = match.captured(4);      // Шаг
        QString lh = match.captured(5);     // Левая резьба
        QString t = match.captured(7);      // Допуск
        QString l = match.captured(9);      // Длина свинчивания
        QString after = match.captured(10); // Текст после

        result =  QString("       Тип резьбы: Трапецеидальная многозаходная\n")
                + QString("         Текст до: %1\n").arg(before)
                + QString("          Диаметр: %1\n").arg(d)
                + QString("              Ход: %1\n").arg(h)
                + QString("              Шаг: %1\n").arg(p)
                + QString("     Левая резьба: %1\n").arg(lh)
                + QString("           Допуск: %1\n").arg(t)
                + QString("Длина свинчивания: %1\n").arg(l)
                + QString("      Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::trapezoidalSingleStartThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                             // Текст до           (1)
                "Tr\\s*"                                   // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"                      // Диаметр            (2)
                "[xX]\\s*"                                 // Знак умножения
                "(\\d+\\,?\\d*)\\s*"                       // Шаг резьбы         (4)
                "([Ll][Hh])?\\s*"                          // Левая резьба       (5)
                "(\\-\\s*(\\d{1,1}\\w{1,1}\\d?\\w?))?\\s*" // Допуск             (7)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"             // Длина  свинчивания (9)
                "([\\s\\S]*)?"                             // Текст после        (10)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString p = match.captured(3);      // Шаг
        QString lh = match.captured(4);     // Левая резьба
        QString t = match.captured(6);      // Допуск
        QString l = match.captured(8);      // Длина свинчивания
        QString after = match.captured(9);  // Текст после

        result  = QString("       Тип резьбы: Трапецеидальная однозаходная\n")
                + QString("         Текст до: %1\n").arg(before)
                + QString("          Диаметр: %1\n").arg(d)
                + QString("              Шаг: %1\n").arg(p)
                + QString("     Левая резьба: %1\n").arg(lh)
                + QString("           Допуск: %1\n").arg(t)
                + QString("Длина свинчивания: %1\n").arg(l)
                + QString("      Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::buttressThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                             // Текст до           (1)
                "S\\s*"                                    // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"                      // Диаметр            (2)
                "(("
                   "[xX]\\s*"
                   "(\\d+\\,?\\d*)"                        // Ход резьбы         (5)
                   "P\\s*\\(\\s*"
                      "(\\d+\\,?\\d*)\\s*"                 // Шаг резьбы         (6)
                   "\\)\\s*"
                ")|([xX]\\s*(\\d+\\,?\\d*)\\s*))"          // Шаг резьбы         (8)
                "([Ll][Hh])?\\s*"                          // Левая резьба       (9)
                "(\\-\\s*(\\d{1,1}\\w{1,1}\\d?\\w?))?\\s*" // Допуск             (11)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"             // Длина  свинчивания (13)
                "([\\s\\S]*)?"                             // Текст после        (14)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString h = match.captured(5);      // Ход
        QString p = match.captured(6);      // Шаг
        QString p1 = (p.isEmpty())
                ? match.captured(8):p;      // Шаг
        QString lh = match.captured(9);     // Левая резьба
        QString t = match.captured(11);     // Допуск
        QString l = match.captured(13);     // Длина свинчивания
        QString after = match.captured(14); // Текст после

        result  = QString("       Тип резьбы: Упорная\n")
                + QString("         Текст до: %1\n").arg(before)
                + QString("          Диаметр: %1\n").arg(d)
                + QString("              Ход: %1\n").arg(h)
                + QString("              Шаг: %1\n").arg(p1)
                + QString("     Левая резьба: %1\n").arg(lh)
                + QString("           Допуск: %1\n").arg(t)
                + QString("Длина свинчивания: %1\n").arg(l)
                + QString("      Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::buttress45Thread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                            // Текст до           (1)
                "S45°\\s*"                                // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"                     // Диаметр            (2)
                "(("
                   "[xX]\\s*"
                   "(\\d+\\,?\\d*)"                        // Ход резьбы         (5)
                   "P\\s*\\(\\s*"
                      "(\\d+\\,?\\d*)\\s*"                 // Шаг резьбы         (6)
                   "\\)\\s*"
                ")|([xX]\\s*(\\d+\\,?\\d*)\\s*))"          // Шаг резьбы         (8)
                "([Ll][Hh])?\\s*"                          // Левая резьба       (9)
                "(\\-\\s*(\\d{1,1}\\w{1,1}\\d?\\w?))?\\s*" // Допуск             (11)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"             // Длина  свинчивания (13)
                "([\\s\\S]*)?"                             // Текст после        (14)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString h = match.captured(5);      // Ход
        QString p = match.captured(6);      // Шаг
        QString p1 = (p.isEmpty())
                ? match.captured(8):p;      // Шаг
        QString lh = match.captured(9);     // Левая резьба
        QString t = match.captured(11);     // Допуск
        QString l = match.captured(13);     // Длина свинчивания
        QString after = match.captured(14); // Текст после

        result  = QString("       Тип резьбы: Упорная усиленная 45\n")
                + QString("         Текст до: %1\n").arg(before)
                + QString("          Диаметр: %1\n").arg(d)
                + QString("              Ход: %1\n").arg(h)
                + QString("              Шаг: %1\n").arg(p1)
                + QString("     Левая резьба: %1\n").arg(lh)
                + QString("           Допуск: %1\n").arg(t)
                + QString("Длина свинчивания: %1\n").arg(l)
                + QString("      Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::pipeCylindricalThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                         // Текст до           (1)
                "G\\s*"                                // Тип резьбы
                "(\\d*[\\,\\.]?\\s*\\d+\\/?\\d*)+\\s*" // Диаметр            (2)
                "([Ll][Hh])?\\s*"                      // Левая резьба       (3)
                "(\\-\\s*(\\w))?\\s*"                  // Допуск             (5)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"         // Длина  свинчивания (7)
                "([\\s\\S]*)?"                         // Текст после        (8)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString lh = match.captured(3);     // Левая резьба
        QString t = match.captured(5);      // Допуск
        QString l = match.captured(7);      // Длина свинчивания
        QString after = match.captured(8);  // Текст после

        result  = QString("       Тип резьбы: Трубная цилиндрическая\n")
                + QString("         Текст до: %1\n").arg(before)
                + QString("          Диаметр: %1\n").arg(d)
                + QString("     Левая резьба: %1\n").arg(lh)
                + QString("           Допуск: %1\n").arg(t)
                + QString("Длина свинчивания: %1\n").arg(l)
                + QString("      Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::pipeTaperThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                         // Текст до      (1)
                "R"                                    // Тип резьбы
                "([c\\s])\\s*"                         // Система       (2)
                "(\\d*[\\,\\.]?\\s*\\d+\\/?\\d*)+\\s*" // Диаметр       (3)
                "([Ll][Hh])?\\s*"                      // Левая резьба  (4)
                "([\\s\\S]*)?"                         // Текст после   (5)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString s = match.captured(2);      // Система
        QString d = match.captured(3);      // Диаметр
        QString lh = match.captured(4);     // Левая резьба
        QString after = match.captured(5);  // Текст после

        result  = QString("  Тип резьбы: Трубная коническая\n")
                + QString("    Текст до: %1\n").arg(before)
                + QString("     Система: %1\n").arg(s)
                + QString("     Диаметр: %1\n").arg(d)
                + QString("Левая резьба: %1\n").arg(lh)
                + QString(" Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::metricTaperThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                    // Текст до      (1)
                "МК\\s*"                          // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр       (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)\\s*"              // Шаг резьбы    (3)
                "([Ll][Hh])?\\s*"                 // Левая резьба  (4)
                "ГОСТ\\s*25229\\s*-\\s*82\\s*"
                "([\\s\\S]*)?"                    // Текст после   (5)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString p = match.captured(3);      // Шаг
        QString lh = match.captured(4);     // Левая резьба
        QString after = match.captured(5);  // Текст после

        result  = QString("  Тип резьбы: Метрическая коническая\n")
                + QString("    Текст до: %1\n").arg(before)
                + QString("     Диаметр: %1\n").arg(d)
                + QString("         Шаг: %1\n").arg(p)
                + QString("Левая резьба: %1\n").arg(lh)
                + QString(" Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::inchTaperThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                            // Текст до      (1)
                "К\\s*"                                   // Тип резьбы
                "(\\d*[\\,\\.]?\\s*\\d+\\/?\\d*)+\"?\\s*" // Диаметр       (2)
                "([Ll][Hh])?\\s*"                         // Левая резьба  (3)
                "ГОСТ\\s*6111\\s*-\\s*52\\s*"
                "([\\s\\S]*)?"                            // Текст после   (4)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString lh = match.captured(3);     // Левая резьба
        QString after = match.captured(4);  // Текст после

        result  = QString("  Тип резьбы: Коническая дюймовая\n")
                + QString("    Текст до: %1\n").arg(before)
                + QString("     Диаметр: %1\n").arg(d)
                + QString("Левая резьба: %1\n").arg(lh)
                + QString(" Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::roundTaperThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                    // Текст до      (1)
                "Кр\\s*"                          // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр       (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)\\s*"              // Шаг резьбы    (3)
                "ГОСТ\\s*13356\\s*-\\s*68\\s*"
                "([\\s\\S]*)?"                    // Текст после   (4)
                );

    QString result;
    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString p = match.captured(3);      // Шаг
        QString after = match.captured(4);  // Текст после

        result  = QString("  Тип резьбы: Круглая для санитарно-технической арматуры\n")
                + QString("    Текст до: %1\n").arg(before)
                + QString("     Диаметр: %1\n").arg(d )
                + QString("         Шаг: %1\n").arg(p )
                + QString(" Текст после: %1\n").arg(after);
    }
    return result;
}

QString Thread::anyThread(const QString &designation)
{
    QString result;

    result = this->metricalThread(designation);
    if (!result.isEmpty()) return result;

    result = this->metricalMjThread(designation);
    if (!result.isEmpty()) return result;

    result = this->trapezoidalMultiStartThread(designation);
    if (!result.isEmpty()) return result;

    result = this->trapezoidalSingleStartThread(designation);
    if (!result.isEmpty()) return result;

    result = this->buttressThread(designation);
    if (!result.isEmpty()) return result;

    result = this->buttressThread(designation);
    if (!result.isEmpty()) return result;

    result = this->buttress45Thread(designation);
    if (!result.isEmpty()) return result;

    result = this->buttress45Thread(designation);
    if (!result.isEmpty()) return result;

    result = this->pipeCylindricalThread(designation);
    if (!result.isEmpty()) return result;

    result = this->pipeTaperThread(designation);
    if (!result.isEmpty()) return result;

    result = this->pipeTaperThread(designation);
    if (!result.isEmpty()) return result;

    result = this->metricTaperThread(designation);
    if (!result.isEmpty()) return result;

    result = this->inchTaperThread(designation);
    if (!result.isEmpty()) return result;

    result = this->roundTaperThread(designation);
    if (!result.isEmpty()) return result;

    return "";
}
