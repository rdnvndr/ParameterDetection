#ifndef THREAD_H
#define THREAD_H

#include <QString>

class Thread
{
public:
    Thread();

    //! Метрическая резьба
    void metricalThread(const QString &designation);

    //! Метрическая резьба с профилем MJ
    void metricalMjThread(const QString &designation);

    //! Трапецеидальная многозаходная
    void trapezoidalMultiStartThread(const QString &designation);

    //! Трапецеидальная однозаходная
    void trapezoidalSingleStartThread(const QString &designation);

    //! Упорная
    void buttressThread(const QString &designation);

    //! Упорная усиленная 45
    void buttress45Thread(const QString &designation);

    //! Трубная цилиндрическая
    void pipeCylindricalThread(const QString &designation);

    //! Трубная коническая
    void pipeTaperThread(const QString &designation);

    //! Метрическая коническая
    void metricTaperThread(const QString &designation);

    //! Коническая дюймовая
    void inchTaperThread(const QString &designation);

    //! Круглая для санитарно-технической арматуры
    void roundTaperThread(const QString &designation);

};

#endif // THREAD_H
