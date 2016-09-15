#include "thread.h"

#include <QRegExp>
#include <QDebug>

Thread::Thread()
{

}

void Thread::metricalThread(const QString &designation)
{
    QRegExp threadRx(
                "([\\s\\S]*)"                               // Текст до (1)
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

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1);  // Текст до
        QString d = threadRx.cap(2);       // Диаметр
        QString ph = threadRx.cap(5);      // Многозаходность
        QString h = threadRx.cap(6);       // Ход
        QString p = threadRx.cap(7);       // Шаг
        QString z = threadRx.cap(8);       // Заходы
        QString p1 = (p.isEmpty())
                ? threadRx.cap(10) : p;    // Шаг
        QString t = threadRx.cap(12);      // Допуск
        QString g = threadRx.cap(14);      // Группа длины свинчивания
        QString l = threadRx.cap(16);      // Длина свинчивания
        QString lh = threadRx.cap(18);     // Левая резьба
        QString after = threadRx.cap(19);  // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"               // Текст до       (1)
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

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString d = threadRx.cap(2);      // Диаметр
        QString p = threadRx.cap(4);      // Шаг
        QString t = threadRx.cap(6);      // Допуск
        QString lh = threadRx.cap(8);     // Левая резьба
        QString after = threadRx.cap(9);  // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до           (1)
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

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString d = threadRx.cap(2);      // Диаметр
        QString h = threadRx.cap(3);      // Ход
        QString p = threadRx.cap(4);      // Шаг
        QString lh = threadRx.cap(5);     // Левая резьба
        QString t = threadRx.cap(7);      // Допуск
        QString l = threadRx.cap(9);      // Длина свинчивания
        QString after = threadRx.cap(10); // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до           (1)
                "Tr\\s*"                          // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр            (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)\\s*"              // Шаг резьбы         (4)
                "([Ll][Hh])?\\s*"                 // Левая резьба       (5)
                "(\\-\\s*(\\w{2,4}))?\\s*"        // Допуск             (7)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"    // Длина  свинчивания (9)
                "([\\s\\S]*)?"                    // Текст после        (10)
                );

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString d = threadRx.cap(2);      // Диаметр
        QString p = threadRx.cap(3);      // Шаг
        QString lh = threadRx.cap(4);     // Левая резьба
        QString t = threadRx.cap(6);      // Допуск
        QString l = threadRx.cap(8);      // Длина свинчивания
        QString after = threadRx.cap(9); // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до           (1)
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

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString d = threadRx.cap(2);      // Диаметр
        QString h = threadRx.cap(5);      // Ход
        QString p = threadRx.cap(6);      // Шаг
        QString p1 = (p.isEmpty())
                ? threadRx.cap(8):p;      // Шаг
        QString lh = threadRx.cap(9);     // Левая резьба
        QString t = threadRx.cap(11);     // Допуск
        QString l = threadRx.cap(13);     // Длина свинчивания
        QString after = threadRx.cap(14); // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до           (1)
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

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString d = threadRx.cap(2);      // Диаметр
        QString h = threadRx.cap(5);      // Ход
        QString p = threadRx.cap(6);      // Шаг
        QString p1 = (p.isEmpty())
                ? threadRx.cap(8):p;      // Шаг
        QString lh = threadRx.cap(9);     // Левая резьба
        QString t = threadRx.cap(11);     // Допуск
        QString l = threadRx.cap(13);     // Длина свинчивания
        QString after = threadRx.cap(14); // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до           (1)
                "G\\s*"                           // Тип резьбы
                "(\\d+\\/?\\d*)+\\s*"             // Диаметр            (2)
                "([Ll][Hh])?\\s*"                 // Левая резьба       (3)
                "(\\-\\s*(\\w))?\\s*"             // Допуск             (5)
                "(\\-\\s*(\\d+\\,?\\d*))?\\s*"    // Длина  свинчивания (7)
                "([\\s\\S]*)?"                    // Текст после        (8)
                );

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString d = threadRx.cap(2);      // Диаметр
        QString lh = threadRx.cap(3);     // Левая резьба
        QString t = threadRx.cap(5);      // Допуск
        QString l = threadRx.cap(7);      // Длина свинчивания
        QString after = threadRx.cap(8);  // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до      (1)
                "R"                               // Тип резьбы
                "(c)?\\s*"                        // Система       (2)
                "(\\d+\\/?\\d*)+\\s*"             // Диаметр       (3)
                "([Ll][Hh])?\\s*"                 // Левая резьба  (4)
                "([\\s\\S]*)?"                    // Текст после   (5)
                );

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString s = threadRx.cap(2);      // Система
        QString d = threadRx.cap(3);      // Диаметр
        QString lh = threadRx.cap(4);     // Левая резьба
        QString after = threadRx.cap(5);  // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до      (1)
                "МК\\s*"                          // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр       (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)\\s*"              // Шаг резьбы    (3)
                "([Ll][Hh])?\\s*"                 // Левая резьба  (4)
                "ГОСТ\\s*25229\\s*-\\s*82\\s*"
                "([\\s\\S]*)?"                    // Текст после   (5)
                );

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString d = threadRx.cap(2);      // Диаметр
        QString p = threadRx.cap(3);      // Шаг
        QString lh = threadRx.cap(4);     // Левая резьба
        QString after = threadRx.cap(5);  // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до      (1)
                "К\\s*"                           // Тип резьбы
                "(\\d+\\/?\\d*)+\"?\\s*"          // Диаметр       (1)
                "([Ll][Hh])?\\s*"                 // Левая резьба  (3)
                "ГОСТ\\s*6111\\s*-\\s*52\\s*"
                "([\\s\\S]*)?"                    // Текст после   (4)
                );

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString d = threadRx.cap(2);      // Диаметр
        QString lh = threadRx.cap(3);     // Левая резьба
        QString after = threadRx.cap(4);  // Текст после

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
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до      (1)
                "Кр\\s*"                          // Тип резьбы
                "(\\d+\\,?\\d*)+\\s*"             // Диаметр       (2)
                "[xX]\\s*"                        // Знак умножения
                "(\\d+\\,?\\d*)\\s*"              // Шаг резьбы    (3)
                "ГОСТ\\s*13356\\s*-\\s*68\\s*"
                "([\\s\\S]*)?"                    // Текст после   (4)
                );

    int pos = threadRx.indexIn(designation);
    if (pos > -1) {
        QString before = threadRx.cap(1); // Текст до
        QString d = threadRx.cap(2);      // Диаметр
        QString p = threadRx.cap(3);      // Шаг
        QString after = threadRx.cap(4);  // Текст после

        qDebug() << "\n"
                 << "  Тип резьбы:" << "Круглая для санитарно-технической арматуры" << "\n"
                 << "    Текст до:" << before << "\n"
                 << "     Диаметр:" << d  << "\n"
                 << "         Шаг:" << p  << "\n"
                 << " Текст после:" << after << "\n";
    }
}
