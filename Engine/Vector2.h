#pragma once
class Vector2
{
public:
    float x, y;

    Vector2(float x = 0, float y = 0) : x(x), y(y) {}

    float Distance(const Vector2& other) const
    {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    Vector2 operator-(const Vector2& other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator+(const Vector2& other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2 Normalized() const
    {
        float length = Distance(Vector2(0, 0));
        return Vector2(x / length, y / length);
    }
};