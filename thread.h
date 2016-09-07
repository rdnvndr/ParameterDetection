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

};

#endif // THREAD_H
