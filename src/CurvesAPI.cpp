#include "../include/CurvesAPI.h"

//Point3D
constexpr Point3D::Point3D(double x, double y, double z)  noexcept : X{ x }, Y{ y }, Z{ z } {}

constexpr double Point3D::getX() const noexcept {
    return X;
}

constexpr double Point3D::getY() const noexcept {
    return Y;
}

constexpr double Point3D::getZ() const noexcept {
    return Z;
}

//Vector3D
constexpr Vector3D::Vector3D(double x, double y, double z)  noexcept : X{ x }, Y{ y }, Z{ z } {}

constexpr double Vector3D::getX() const noexcept {
    return X;
}

constexpr double Vector3D::getY() const noexcept {
    return Y;
}

constexpr double Vector3D::getZ() const noexcept {
    return Z;
}
//Circle
Circle::Circle(double _radius) noexcept : radius{ _radius } {}

Point3D Circle::getPoint(double t) const noexcept {
    return Point3D{ radius * std::cos(t), radius * std::sin(t), 0.0f };
}

Vector3D Circle::getDerivative(double t) const noexcept {
    return Vector3D{ -radius * std::sin(t), radius * std::cos(t), 0.0f };
}

double Circle::getRadius() const noexcept {
    return radius;
}

//Ellipse
Ellipse::Ellipse(double radius_x, double radius_y) noexcept : x_radius{ radius_x }, y_radius{ radius_y } {}

Point3D Ellipse::getPoint(double t) const noexcept {
    return Point3D{ x_radius * std::cos(t), y_radius * std::sin(t), 0.0f };
}

Vector3D Ellipse::getDerivative(double t) const noexcept {
    return Vector3D{ -x_radius * std::sin(t), y_radius * std::cos(t), 0.0f };
}

double Ellipse::getRadius() const noexcept {
    return x_radius;
}

double Ellipse::getRadiusY() const noexcept {
    return y_radius;
}

//Helix
Helix::Helix(double _radius, double _step) noexcept : radius{ _radius }, step{ _step } {}

Point3D Helix::getPoint(double t) const noexcept {
    return Point3D{ radius * std::cos(t), radius * std::sin(t), step * t };
}

Vector3D Helix::getDerivative(double t) const noexcept {
    return Vector3D{ -radius * std::sin(t), radius * std::cos(t), step };
}

double Helix::getRadius() const noexcept {
    return radius;
}
