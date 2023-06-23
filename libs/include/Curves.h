#pragma once
#ifdef CURVES_EXPORTS
#define CURVES_API __declspec(dllexport)
#else
#define CURVES_API __declspec(dllimport)
#endif

#include <compare>
#include <math.h>
#include <memory>

class CURVES_API Point3D {
public:
    constexpr Point3D(double x, double y, double z) noexcept;

    constexpr Point3D() noexcept = default;

    constexpr Point3D(const Point3D& lhs) noexcept = default;

    constexpr Point3D(Point3D&& rhs) noexcept = default;

    constexpr Point3D& operator=(const Point3D& lhs) noexcept = default;
     
    constexpr Point3D& operator=(Point3D&& rhs) noexcept = default;

    constexpr auto operator<=>(const Point3D& lhs) const noexcept = default;

    constexpr double getX() const noexcept;

    constexpr double getY() const noexcept;

    constexpr double getZ() const noexcept;

private:
    double X = 0;
    double Y = 0;
    double Z = 0;
};

class CURVES_API Vector3D {
public:

    constexpr Vector3D(double x, double y, double z) noexcept;

    constexpr Vector3D(const Vector3D& lhs) noexcept = default;

    constexpr Vector3D(Vector3D&& rhs) noexcept = default;

    constexpr Vector3D& operator=(const Vector3D& lhs) noexcept = default;

    constexpr Vector3D& operator=(Vector3D&& rhs) noexcept = default;

    constexpr auto operator<=>(const Vector3D& lhs) const noexcept = default;

    constexpr double getX() const noexcept;

    constexpr double getY() const noexcept;

    constexpr double getZ() const noexcept;

private:
    double X = 0;
    double Y = 0;
    double Z = 0;
};

class CURVES_API ICurve {
public:
    virtual Point3D getPoint(double t) const noexcept = 0;
    virtual Vector3D getDerivative(double t) const noexcept = 0;
    virtual double getRadiusX() const noexcept = 0;
    virtual double getRadiusY() const noexcept = 0;
    virtual ~ICurve() = default;
};

class CURVES_API Circle final : public ICurve{
public:

    explicit Circle(double _radius) noexcept;

    Circle(const Circle& lhs) noexcept = default;

    Circle(Circle&& rhs) noexcept = default;

    Circle& operator=(const Circle& lhs) noexcept = default;

    Circle& operator=(Circle&& rhs) noexcept = default;

    Point3D getPoint(double t) const noexcept override final;

    Vector3D getDerivative(double t) const noexcept override final;

    double getRadiusX() const noexcept override final;

    double getRadiusY() const noexcept override final;

    ~Circle() override = default;

private:
    double radius = 0;
};

class CURVES_API Ellipse final : public ICurve{
public:

    explicit Ellipse(double radius_x, double radius_y) noexcept;

    Ellipse(const Ellipse& lhs) noexcept = default;

    Ellipse(Ellipse&& rhs) noexcept = default;

    Ellipse& operator=(const Ellipse& lhs) noexcept = default;

    Ellipse& operator=(Ellipse&& rhs) noexcept = default;

    Point3D getPoint(double t) const noexcept override final;

    Vector3D getDerivative(double t) const noexcept override final;

    double getRadiusX() const noexcept override final;

    double getRadiusY() const noexcept override final;

    ~Ellipse() override = default;

private:
    double x_radius = 0;
    double y_radius = 0;

};

class CURVES_API Helix final : public ICurve{
public:

    explicit Helix(double _radius, double _step) noexcept;

    Helix(const Helix& lhs) noexcept = default;

    Helix(Helix&& rhs) noexcept = default;

    Helix& operator=(const Helix& lhs) noexcept = default;

    Helix& operator=(Helix&& rhs) noexcept = default;

    Point3D getPoint(double t) const noexcept override final;

    Vector3D getDerivative(double t) const noexcept override final;

    double getRadiusX() const noexcept override final;

    double getRadiusY() const noexcept override final;

    ~Helix() override = default;

private:
    double radius = 0;
    double step = 0;
};