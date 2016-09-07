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
        QString Before = threadRx.cap(1);  // Текст до
        QString D = threadRx.cap(2);       // Диаметр
        QString Ph = threadRx.cap(5);      // Многозаходность
        QString H = threadRx.cap(6);       // Ход
        QString P = threadRx.cap(7);       // Шаг
        QString Z = threadRx.cap(8);       // Заходы
        QString P1 = (P.isEmpty())
                ? threadRx.cap(10) : P;    // Шаг
        QString T = threadRx.cap(12);      // Допуск
        QString G = threadRx.cap(14);      // Группа длины свинчивания
        QString L = threadRx.cap(16);      // Длина свинчивания
        QString LH = threadRx.cap(18);     // Левая резьба
        QString After = threadRx.cap(19);  // Текст после

        qDebug() << "\n"
                 << "        Тип резьбы:" << "Метрическая резьба" << "\n"
                 << "          Текст до:" << Before << "\n"
                 << "           Диаметр:" << D  << "\n"
                 << "   Многозаходность:" << Ph << "\n"
                 << "               Ход:" << H  << "\n"
                 << "           Заходов:" << Z  << "\n"
                 << "               Шаг:" << P1 << "\n"
                 << "            Допуск:" << T  << "\n"
                 << "Группа свинчивания:" << G  << "\n"
                 << " Длина свинчивания:" << L  << "\n"
                 << "      Левая резьба:" << LH << "\n"
                 << "       Текст после:" << After << "\n";
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
        QString Before = threadRx.cap(1); // Текст до
        QString D = threadRx.cap(2);      // Диаметр
        QString P = threadRx.cap(4);      // Шаг
        QString T = threadRx.cap(6);      // Допуск
        QString LH = threadRx.cap(8);     // Левая резьба
        QString After = threadRx.cap(9);  // Текст после

        qDebug() << "\n"
                 << "  Тип резьбы:" << "Метрическая резьба с профилем MJ" << "\n"
                 << "    Текст до:" << Before << "\n"
                 << "     Диаметр:" << D      << "\n"
                 << "         Шаг:" << P      << "\n"
                 << "      Допуск:" << T      << "\n"
                 << "Левая резьба:" << LH     << "\n"
                 << " Текст после:" << After  << "\n";
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
        QString Before = threadRx.cap(1); // Текст до
        QString D = threadRx.cap(2);      // Диаметр
        QString H = threadRx.cap(3);      // Ход
        QString P = threadRx.cap(4);      // Шаг
        QString LH = threadRx.cap(5);     // Левая резьба
        QString T = threadRx.cap(7);      // Допуск
        QString L = threadRx.cap(9);      // Длина свинчивания
        QString After = threadRx.cap(10); // Текст после

        qDebug() << "\n"
                 << "        Тип резьбы:" << "Трапецеидальная многозаходная" << "\n"
                 << "          Текст до:" << Before << "\n"
                 << "           Диаметр:" << D  << "\n"
                 << "               Ход:" << H  << "\n"
                 << "               Шаг:" << P  << "\n"
                 << "      Левая резьба:" << LH << "\n"
                 << "            Допуск:" << T  << "\n"
                 << " Длина свинчивания:" << L  << "\n"
                 << "       Текст после:" << After << "\n";
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
        QString Before = threadRx.cap(1); // Текст до
        QString D = threadRx.cap(2);      // Диаметр
        QString P = threadRx.cap(3);      // Шаг
        QString LH = threadRx.cap(4);     // Левая резьба
        QString T = threadRx.cap(6);      // Допуск
        QString L = threadRx.cap(8);      // Длина свинчивания
        QString After = threadRx.cap(9); // Текст после

        qDebug() << "\n"
                 << "        Тип резьбы:" << "Трапецеидальная однозаходная" << "\n"
                 << "          Текст до:" << Before << "\n"
                 << "           Диаметр:" << D  << "\n"
                 << "               Шаг:" << P      << "\n"
                 << "      Левая резьба:" << LH << "\n"
                 << "            Допуск:" << T  << "\n"
                 << " Длина свинчивания:" << L  << "\n"
                 << "       Текст после:" << After << "\n";
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
        QString Before = threadRx.cap(1); // Текст до
        QString D = threadRx.cap(2);      // Диаметр
        QString H = threadRx.cap(5);      // Ход
        QString P = threadRx.cap(6);      // Шаг
        QString P1 = (P.isEmpty())
                ? threadRx.cap(8):P;      // Шаг
        QString LH = threadRx.cap(9);     // Левая резьба
        QString T = threadRx.cap(11);     // Допуск
        QString L = threadRx.cap(13);     // Длина свинчивания
        QString After = threadRx.cap(14); // Текст после

        qDebug() << "\n"
                 << "        Тип резьбы:" << "Упорная" << "\n"
                 << "          Текст до:" << Before << "\n"
                 << "           Диаметр:" << D  << "\n"
                 << "               Ход:" << H  << "\n"
                 << "               Шаг:" << P1 << "\n"
                 << "      Левая резьба:" << LH << "\n"
                 << "            Допуск:" << T  << "\n"
                 << " Длина свинчивания:" << L  << "\n"
                 << "       Текст после:" << After << "\n";
    }
}

void Thread::buttress45Thread(const QString &designation)
{
    QRegExp threadRx(
                "([\\s\\S]*)"                     // Текст до           (1)
                "S45°\\s*"                      // Тип резьбы
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
        QString Before = threadRx.cap(1); // Текст до
        QString D = threadRx.cap(2);      // Диаметр
        QString H = threadRx.cap(5);      // Ход
        QString P = threadRx.cap(6);      // Шаг
        QString P1 = (P.isEmpty())
                ? threadRx.cap(8):P;      // Шаг
        QString LH = threadRx.cap(9);     // Левая резьба
        QString T = threadRx.cap(11);     // Допуск
        QString L = threadRx.cap(13);     // Длина свинчивания
        QString After = threadRx.cap(14); // Текст после

        qDebug() << "\n"
                 << "        Тип резьбы:" << "Упорная усиленная 45" << "\n"
                 << "          Текст до:" << Before << "\n"
                 << "           Диаметр:" << D  << "\n"
                 << "               Ход:" << H  << "\n"
                 << "               Шаг:" << P1 << "\n"
                 << "      Левая резьба:" << LH << "\n"
                 << "            Допуск:" << T  << "\n"
                 << " Длина свинчивания:" << L  << "\n"
                 << "       Текст после:" << After << "\n";
    }
}
