#include "thread.h"
#include "element.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    Thread *thread = new Thread();
    thread->metricalThread("M12xPh2P1(Два захода)-6g6h-S(10)-LH");
    thread->metricalMjThread("MJ12x1-6g6h-LH");
    thread->trapezoidalMultiStartThread("Tr16x8(P2)LH-7e-120");
    thread->trapezoidalSingleStartThread("Tr16x8LH-7e-120");
    thread->buttressThread("S16x8P(10)LH-7e-120");
    thread->buttressThread("S16x8LH-7e-120");
    thread->buttress45Thread("S45°16x8P(10)LH-7e-120");
    thread->buttress45Thread("S45°16x8LH-7e-120");
    thread->pipeCylindricalThread("G1/16LH-A-150");
    thread->pipeTaperThread("R1/16LH");
    thread->pipeTaperThread("Rc1/16LH");
    thread->metricTaperThread("МК6x1LH ГОСТ 25229-82");
    thread->inchTaperThread("К1/16\"LH ГОСТ 6111-52");
    thread->roundTaperThread("Кр12x2,54 ГОСТ 13356-68");
    delete thread;

    Element *element = new Element();
    element->chamfer("Текст до2x45°");
    element->lineDimension("Текст до10,2±10,3Текст после");
    element->lineDimension("Текст до10,2JS7(±10)Текст после");
    element->lineDimension("Текст до10,2H7(+0,02; -0,03)Текст после");
    element->lineDimension("Текст до10,1+0,02; -0,03Текст после");
    element->angleDimension("Текст до10,2±10,3Текст после");
    element->angleDimension("Текст до10,1°+0,02°; -0,03°Текст после");
    element->angleDimension("Текст до10,1(+0,02; -0,03)Текст после");
    element->angleDimension("Текст до10°11'12\"+10°11'12\";-10°11'12\"Текст после");
    element->angleDimension("Текст до10°11'12\"±10°11'12\"Текст после");
    delete element;
}
