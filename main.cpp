#include "thread.h"

int main(int argc, char *argv[])
{
    Thread *thread = new Thread();
    thread->metricalThread("M12xPh2P1(Два захода)-6g6h-S(10)-LH");
    thread->metricalMjThread("MJ12x1-6g6h-LH");
    thread->trapezoidalMultiStartThread("Tr16x8(P2)LH-7e-120");
    thread->trapezoidalSingleStartThread("Tr16x8LH-7e-120");
    thread->buttressThread("S16x8P(10)LH-7e-120");
    thread->buttressThread("S16x8LH-7e-120");
    thread->buttress45Thread("S45°16x8P(10)LH-7e-120");
    thread->buttress45Thread("S45°16x8LH-7e-120");
    delete thread;
}
