#include <chrono>
#include <thread>
#include <cstdint>

#ifndef __TIMER_HPP
#define __TIMER_HPP
class Timer
{
  private:
    uint32_t ticks = 0;
    uint32_t limit;
    bool running, triggered;
  public:
    Timer(uint32_t l) : limit(l) {}
    void init(uint32_t t) { ticks = t; }
    void start() { if (!triggered) running = true; }
    void stop() { running = false; }
    void step()
    {
        if (running)
        {
            ticks++;
            if (ticks == limit)
            {
                triggered = true;
                running = false;
            }
        }
    }
    uint32_t state() { return ticks; }
    void reset()
    {
        ticks = 0;
        triggered = false;
    }
    bool isRunning() { return running; }
    bool hasTriggered() { return triggered; }
};
#endif