#include "thread.h"
#include "element.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    Thread *thread = new Thread();
    qDebug().noquote() << thread->metricalThread("M12xPh2P1(Два захода)-6g6h-S(10)-LH");
    qDebug().noquote() << thread->metricalMjThread("MJ12x1-6g6h-LH");
    qDebug().noquote() << thread->trapezoidalMultiStartThread("Tr16x8(P2)LH-7e-120");
    qDebug().noquote() << thread->trapezoidalSingleStartThread("Tr16x8LH-7e-120");
    qDebug().noquote() << thread->buttressThread("S16x8P(10)LH-7e-120");
    qDebug().noquote() << thread->buttressThread("S16x8LH-7e-120");
    qDebug().noquote() << thread->buttress45Thread("S45°16x8P(10)LH-7e-120");
    qDebug().noquote() << thread->buttress45Thread("S45°16x8LH-7e-120");
    qDebug().noquote() << thread->pipeCylindricalThread("G1/16LH-A-150");
    qDebug().noquote() << thread->pipeTaperThread("R1/16LH");
    qDebug().noquote() << thread->pipeTaperThread("Rc1/16LH");
    qDebug().noquote() << thread->metricTaperThread("МК6x1LH ГОСТ 25229-82");
    qDebug().noquote() << thread->inchTaperThread("К1/16\"LH ГОСТ 6111-52");
    qDebug().noquote() << thread->roundTaperThread("Кр12x2,54 ГОСТ 13356-68");
    delete thread;

    Element *element = new Element();
    qDebug().noquote() << element->chamfer("Текст до2x45°");
    qDebug().noquote() << element->lineDimension("Текст до10,2±10,3Текст после");
    qDebug().noquote() << element->lineDimension("Текст до10,2JS7(±10)Текст после");
    qDebug().noquote() << element->lineDimension("Текст до10,2H7(+0,02; -0,03)Текст после");
    qDebug().noquote() << element->lineDimension("Текст до10,1+0,02; -0,03Текст после");
    qDebug().noquote() << element->angleDimension("Текст до10,2±10,3Текст после");
    qDebug().noquote() << element->angleDimension("Текст до10,1°+0,02°; -0,03°Текст после");
    qDebug().noquote() << element->angleDimension("Текст до10,1(+0,02; -0,03)Текст после");
    qDebug().noquote() << element->angleDimension("Текст до10°11'12\"+10°11'12\";-10°11'12\"Текст после");
    qDebug().noquote() << element->angleDimension("Текст до10°11'12\"±10°11'12\"Текст после");
    delete element;
}
