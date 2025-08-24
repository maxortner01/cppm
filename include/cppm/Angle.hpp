#pragma once

#ifdef USE_NUMBERS
#   include <numbers>
#endif

namespace cppm
{
    struct Angle
    {
        template<typename T>
        constexpr static Angle radians(const T& r)
        {
            return Angle(r);
        }

        template<typename T>
        constexpr static Angle degrees(const T& d)
        {
            return Angle(toRadians(d));
        }

        constexpr double asRadians() const { return rads; }
        constexpr double asDegrees() const { return toDegrees(rads); }

        constexpr Angle operator+(const Angle& b) const
        {
            return Angle(rads + b.rads);
        }

        Angle& operator+=(const Angle& b) 
        {
            rads += b.rads;
            return *this;
        }

        Angle& operator-=(const Angle& b) 
        {
            rads -= b.rads;
            return *this;
        }

        constexpr Angle operator-(const Angle& b) const
        {
            return Angle(rads + b.rads);
        }

        constexpr Angle operator*(const Angle& b) const
        {
            return Angle(rads * b.rads);
        }

        constexpr Angle operator/(const Angle& b) const
        {
            return Angle(rads / b.rads);
        }

        template<typename T>
        constexpr Angle operator*(const T& b) const
        {
            return Angle(rads * b);
        }

        template<typename T>
        constexpr Angle operator/(const T& b) const
        {
            return Angle(rads / b);
        }

        static Angle PI;

        constexpr Angle() : rads{0}
        {   }

    private:
        constexpr Angle(double radians) : rads(radians) 
        {   }

        constexpr static double toRadians(const double& d)
        {
            return d * _PI / 180.0;
        }

        constexpr static double toDegrees(const double& r)
        {
            return r * 180.0 / _PI;
        }

#   ifdef USE_NUMBERS
        inline static constexpr double _PI = std::numbers::pi;
#   else
        inline static constexpr double _PI = 3.14159;
#   endif

        double rads;
    };
}