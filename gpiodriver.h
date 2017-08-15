#ifndef GPIODRIVER_H
#define GPIODRIVER_H


class GpioDriver
{
public:
    GpioDriver();
   ~GpioDriver();
    virtual void funct()=0;
};

#endif // GPIODRIVER_H
