#include "thread.h"

#include <QRegularExpression>
#include <QDebug>

Thread::Thread()
{

}

void Thread::metricalThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                               // Текст до (1)
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

                "(\\-\\s*(\\w{2,4}))?\\s*"                  // Допуск (12)
                "(\\-\\s*"
                   "([SsLl])?\\s*"                              // Группа свинчивания (14)
                   "(\\(\\s*(\\d+\\,?\\d*)\\s*\\))?\\s*"        // Длина  свинчивания (16)
                ")?"
                "(\\-\\s*([Ll][Hh]))?\\s*"                  // Левая резьба (18)
                "([\\s\\S]*)?"                              // Текст после  (19)
                );

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

        qDebug() << "\n"
                 << "        Тип резьбы:" << "Метрическая резьба" << "\n"
                 << "          Текст до:" << before << "\n"
                 << "           Диаметр:" << d  << "\n"
                 << "   Многозаходность:" << ph << "\n"
                 << "               Ход:" << h  << "\n"
                 << "           Заходов:" << z  << "\n"
                 << "               Шаг:" << p1 << "\n"
                 << "            Допуск:" << t  << "\n"
                 << "Группа свинчивания:" << g  << "\n"
                 << " Длина свинчивания:" << l  << "\n"
                 << "      Левая резьба:" << lh << "\n"
                 << "       Текст после:" << after << "\n";
    }
}

void Thread::metricalMjThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"               // Текст до       (1)
                "MJ\\s*"                    // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"       // Диаметр        (2)
                "("
                   "[xX]\\s*"               // Знак умножения
                   "(\\d+\\,?\\d*)\\s*"     // Шаг резьбы     (4)
                ")?"
                "(\\-\\s*(\\w{2,4}))?\\s*"  // Допуск         (6)
                "(\\-\\s*([Ll][Hh]))?\\s*"  // Левая резьба   (8)
                "([\\s\\S]*)?"              // Текст после    (9)
                );

    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString p = match.captured(4);      // Шаг
        QString t = match.captured(6);      // Допуск
        QString lh = match.captured(8);     // Левая резьба
        QString after = match.captured(9);  // Текст после

        qDebug() << "\n"
                 << "  Тип резьбы:" << "Метрическая резьба с профилем MJ" << "\n"
                 << "    Текст до:" << before << "\n"
                 << "     Диаметр:" << d      << "\n"
                 << "         Шаг:" << p      << "\n"
                 << "      Допуск:" << t      << "\n"
                 << "Левая резьба:" << lh     << "\n"
                 << " Текст после:" << after  << "\n";
    }
}

void Thread::trapezoidalMultiStartThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                     // Текст до           (1)
                "Tr\\s*"                          // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр            (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)"                  // Ход резьбы         (3)
                "\\(\\s*P\\s*"
                "(\\d+\\,?\\d*)\\s*"              // Шаг резьбы         (4)
                "\\)\\s*"
                "([Ll][Hh])?\\s*"                 // Левая резьба       (5)
                "(\\-\\s*(\\w{2,4}))?\\s*"        // Допуск             (7)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"    // Длина  свинчивания (9)
                "([\\s\\S]*)?"                    // Текст после        (10)
                );

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

        qDebug() << "\n"
                 << "       Тип резьбы:" << "Трапецеидальная многозаходная" << "\n"
                 << "         Текст до:" << before << "\n"
                 << "          Диаметр:" << d  << "\n"
                 << "              Ход:" << h  << "\n"
                 << "              Шаг:" << p  << "\n"
                 << "     Левая резьба:" << lh << "\n"
                 << "           Допуск:" << t  << "\n"
                 << "Длина свинчивания:" << l  << "\n"
                 << "      Текст после:" << after << "\n";
    }
}

void Thread::trapezoidalSingleStartThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                     // Текст до           (1)
                "Tr\\s*"                          // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр            (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)\\s*"              // Шаг резьбы         (4)
                "([Ll][Hh])?\\s*"                 // Левая резьба       (5)
                "(\\-\\s*(\\w{2,4}))?\\s*"        // Допуск             (7)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"    // Длина  свинчивания (9)
                "([\\s\\S]*)?"                    // Текст после        (10)
                );

    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString p = match.captured(3);      // Шаг
        QString lh = match.captured(4);     // Левая резьба
        QString t = match.captured(6);      // Допуск
        QString l = match.captured(8);      // Длина свинчивания
        QString after = match.captured(9); // Текст после

        qDebug() << "\n"
                 << "       Тип резьбы:" << "Трапецеидальная однозаходная" << "\n"
                 << "         Текст до:" << before << "\n"
                 << "          Диаметр:" << d  << "\n"
                 << "              Шаг:" << p      << "\n"
                 << "     Левая резьба:" << lh << "\n"
                 << "           Допуск:" << t  << "\n"
                 << "Длина свинчивания:" << l  << "\n"
                 << "      Текст после:" << after << "\n";
    }
}

void Thread::buttressThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                     // Текст до           (1)
                "S\\s*"                           // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр            (2)
                "(("
                   "[xX]\\s*"
                   "(\\d+\\,?\\d*)"               // Ход резьбы         (5)
                   "P\\s*\\(\\s*"
                      "(\\d+\\,?\\d*)\\s*"        // Шаг резьбы         (6)
                   "\\)\\s*"
                ")|([xX]\\s*(\\d+\\,?\\d*)\\s*))" // Шаг резьбы         (8)
                "([Ll][Hh])?\\s*"                 // Левая резьба       (9)
                "(\\-\\s*(\\w{2,4}))?\\s*"        // Допуск             (11)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"    // Длина  свинчивания (13)
                "([\\s\\S]*)?"                    // Текст после        (14)
                );

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

        qDebug() << "\n"
                 << "       Тип резьбы:" << "Упорная" << "\n"
                 << "         Текст до:" << before << "\n"
                 << "          Диаметр:" << d  << "\n"
                 << "              Ход:" << h  << "\n"
                 << "              Шаг:" << p1 << "\n"
                 << "     Левая резьба:" << lh << "\n"
                 << "           Допуск:" << t  << "\n"
                 << "Длина свинчивания:" << l  << "\n"
                 << "      Текст после:" << after << "\n";
    }
}

void Thread::buttress45Thread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                     // Текст до           (1)
                "S45°\\s*"                        // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр            (2)
                "(("
                   "[xX]\\s*"
                   "(\\d+\\,?\\d*)"               // Ход резьбы         (5)
                   "P\\s*\\(\\s*"
                      "(\\d+\\,?\\d*)\\s*"        // Шаг резьбы         (6)
                   "\\)\\s*"
                ")|([xX]\\s*(\\d+\\,?\\d*)\\s*))" // Шаг резьбы         (8)
                "([Ll][Hh])?\\s*"                 // Левая резьба       (9)
                "(\\-\\s*(\\w{2,4}))?\\s*"        // Допуск             (11)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"    // Длина  свинчивания (13)
                "([\\s\\S]*)?"                    // Текст после        (14)
                );

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

        qDebug() << "\n"
                 << "       Тип резьбы:" << "Упорная усиленная 45" << "\n"
                 << "         Текст до:" << before << "\n"
                 << "          Диаметр:" << d  << "\n"
                 << "              Ход:" << h  << "\n"
                 << "              Шаг:" << p1 << "\n"
                 << "     Левая резьба:" << lh << "\n"
                 << "           Допуск:" << t  << "\n"
                 << "Длина свинчивания:" << l  << "\n"
                 << "      Текст после:" << after << "\n";
    }
}

void Thread::pipeCylindricalThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                     // Текст до           (1)
                "G\\s*"                           // Тип резьбы
                "(\\d+\\/?\\d*)+\\s*"             // Диаметр            (2)
                "([Ll][Hh])?\\s*"                 // Левая резьба       (3)
                "(\\-\\s*(\\w))?\\s*"             // Допуск             (5)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"    // Длина  свинчивания (7)
                "([\\s\\S]*)?"                    // Текст после        (8)
                );

    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString lh = match.captured(3);     // Левая резьба
        QString t = match.captured(5);      // Допуск
        QString l = match.captured(7);      // Длина свинчивания
        QString after = match.captured(8);  // Текст после

        qDebug() << "\n"
                 << "       Тип резьбы:" << "Трубная цилиндрическая" << "\n"
                 << "         Текст до:" << before << "\n"
                 << "          Диаметр:" << d  << "\n"
                 << "     Левая резьба:" << lh << "\n"
                 << "           Допуск:" << t  << "\n"
                 << "Длина свинчивания:" << l  << "\n"
                 << "      Текст после:" << after << "\n";
    }
}

void Thread::pipeTaperThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                     // Текст до      (1)
                "R"                               // Тип резьбы
                "(c)?\\s*"                        // Система       (2)
                "(\\d+\\/?\\d*)+\\s*"             // Диаметр       (3)
                "([Ll][Hh])?\\s*"                 // Левая резьба  (4)
                "([\\s\\S]*)?"                    // Текст после   (5)
                );

    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString s = match.captured(2);      // Система
        QString d = match.captured(3);      // Диаметр
        QString lh = match.captured(4);     // Левая резьба
        QString after = match.captured(5);  // Текст после

        qDebug() << "\n"
                 << "  Тип резьбы:" << "Трубная коническая" << "\n"
                 << "    Текст до:" << before << "\n"
                 << "     Система:" << s  << "\n"
                 << "     Диаметр:" << d  << "\n"
                 << "Левая резьба:" << lh << "\n"
                 << " Текст после:" << after << "\n";
    }
}

void Thread::metricTaperThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                     // Текст до      (1)
                "МК\\s*"                          // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр       (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)\\s*"              // Шаг резьбы    (3)
                "([Ll][Hh])?\\s*"                 // Левая резьба  (4)
                "ГОСТ\\s*25229\\s*-\\s*82\\s*"
                "([\\s\\S]*)?"                    // Текст после   (5)
                );

    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString p = match.captured(3);      // Шаг
        QString lh = match.captured(4);     // Левая резьба
        QString after = match.captured(5);  // Текст после

        qDebug() << "\n"
                 << "  Тип резьбы:" << "Метрическая коническая" << "\n"
                 << "    Текст до:" << before << "\n"
                 << "     Диаметр:" << d  << "\n"
                 << "         Шаг:" << p  << "\n"
                 << "Левая резьба:" << lh << "\n"
                 << " Текст после:" << after << "\n";
    }
}

void Thread::inchTaperThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                     // Текст до      (1)
                "К\\s*"                           // Тип резьбы
                "(\\d+\\/?\\d*)+\"?\\s*"          // Диаметр       (1)
                "([Ll][Hh])?\\s*"                 // Левая резьба  (3)
                "ГОСТ\\s*6111\\s*-\\s*52\\s*"
                "([\\s\\S]*)?"                    // Текст после   (4)
                );

    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString lh = match.captured(3);     // Левая резьба
        QString after = match.captured(4);  // Текст после

        qDebug() << "\n"
                 << "  Тип резьбы:" << "Коническая дюймовая" << "\n"
                 << "    Текст до:" << before << "\n"
                 << "     Диаметр:" << d  << "\n"
                 << "Левая резьба:" << lh << "\n"
                 << " Текст после:" << after << "\n";
    }
}

void Thread::roundTaperThread(const QString &designation)
{
    QRegularExpression regex(
                "([\\s\\S]*?)"                     // Текст до      (1)
                "Кр\\s*"                          // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр       (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)\\s*"              // Шаг резьбы    (3)
                "ГОСТ\\s*13356\\s*-\\s*68\\s*"
                "([\\s\\S]*)?"                    // Текст после   (4)
                );

    QRegularExpressionMatch match = regex.match(designation);
    if (match.hasMatch()) {
        QString before = match.captured(1); // Текст до
        QString d = match.captured(2);      // Диаметр
        QString p = match.captured(3);      // Шаг
        QString after = match.captured(4);  // Текст после

        qDebug() << "\n"
                 << "  Тип резьбы:" << "Круглая для санитарно-технической арматуры" << "\n"
                 << "    Текст до:" << before << "\n"
                 << "     Диаметр:" << d  << "\n"
                 << "         Шаг:" << p  << "\n"
                 << " Текст после:" << after << "\n";
    }
}
