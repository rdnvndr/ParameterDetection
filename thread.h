#ifndef THREAD_H
#define THREAD_H

#include <QString>

class Thread
{
public:
    Thread();

    //! Метрическая резьба
    QString metricalThread(const QString &designation);

    //! Метрическая резьба с профилем MJ
    QString metricalMjThread(const QString &designation);

    //! Трапецеидальная многозаходная
    QString trapezoidalMultiStartThread(const QString &designation);

    //! Трапецеидальная однозаходная
    QString trapezoidalSingleStartThread(const QString &designation);

    //! Упорная
    QString buttressThread(const QString &designation);

    //! Упорная усиленная 45
    QString buttress45Thread(const QString &designation);

    //! Трубная цилиндрическая
    QString pipeCylindricalThread(const QString &designation);

    //! Трубная коническая
    QString pipeTaperThread(const QString &designation);

    //! Метрическая коническая
    QString metricTaperThread(const QString &designation);

    //! Коническая дюймовая
    QString inchTaperThread(const QString &designation);

    //! Круглая для санитарно-технической арматуры
    QString roundTaperThread(const QString &designation);

    //! Любая резьба
    QString anyThread(const QString &designation);

};

#endif // THREAD_H
