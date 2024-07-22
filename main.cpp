#include <iostream>
#include <cppm/Angle.hpp>
#include <cppm/Vector.hpp>

int main()
{
    using namespace cppm;

    auto angle1 = Math::Angle::degrees(90);
    std::cout << angle1.asRadians() << "\n";

    Math::Vec2f vec{0.f, 2.5f};
    std::cout << Math::x(vec) << ", " << Math::y(vec) << "\n";

    auto ivec = static_cast<Math::Vec2i>(vec);
    std::cout << Math::x(ivec) << ", " << Math::y(ivec) << "\n";
}