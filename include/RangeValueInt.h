#ifndef RANGE_VALUE_INT_H_
#define RANGE_VALUE_INT_H_

#include "PlatformConfig.h"
#include "Logging.h"

class RangeValueInt
{
private:
    int _value = 0;
    int _minValue = 0;
    int _maxValue = 0;

public:
    RangeValueInt(int value_ = 0, int minValue_ = 0, int maxValue_ = 0)
        : _value(value_), _minValue(minValue_), _maxValue(maxValue_)
    {
        setValue(value_);
    }

    int getValue() { return _value; }
    void setValue(int newValue)
    {
        if (_maxValue != -1)
        {
            _value = MAX(_minValue, MIN(newValue, _maxValue));
        }
    }

    int getMaxValue() { return _maxValue; }
    void setMaxValue(int newValue)
    {
        if (newValue < _minValue)
        {
            THROW_EXCEPTION("RangeValueInt::_maxValue cant be lower than RangeValueInt::_minValue!");
        }
        _maxValue = newValue;
        setValue(_value);
    }

    int getMinValue() { return _minValue; }
    void setMinValue(int newValue)
    {
        if (newValue > _maxValue)
        {
            THROW_EXCEPTION("RangeValueInt::_minValue cant be higher than RangeValueInt::_maxValue!");
        }
        _minValue = newValue;
        setValue(_value);
    }

    void increase() { setValue(_value + 1); }
    void decrease() { setValue(_value - 1); }

    void add(int value) { setValue(_value + value); }
    void substract(int value) { setValue(_value - value); }

    void setToMin() { setValue(_minValue); }
    void setToMax() { setValue(_maxValue); }
};

#endif