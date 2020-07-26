#pragma once
#define SIMPLEMATH_H
#ifdef SIMPLEMATH_H

/* C++ */
/* End */

namespace simplemath {

float constrain(float value, float max, float min) {
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

float wraprange(float value, float max, float min) {
    if (value < min)
        return simplemath::wraprange(value + (max - min), max, min);
    if (value > max)
        return simplemath::wraprange(value - (max - min), max, min);
    return value;
}

float convert(float value, float from_start, float from_end, float to_start, float to_end) {
    return (value - from_start) / (from_end - from_start) * (to_end - to_start) + to_start;
}

} // namespace simplemath


#endif
