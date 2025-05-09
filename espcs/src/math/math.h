#pragma once

// #define LOWRES

#if LOWRES
inline int screen_width = 1920;
inline int screen_height = 1080;
#else
inline int screen_width = 3840; // Changed from 1920
inline int screen_height = 2160; // Changed from 1080
#endif

struct view_matrix_t
{
    float* operator[](int index)
    {
        return matrix[index];
    }

    float matrix[4][4];
};

struct Vector3
{
    constexpr Vector3(
        const float x = 0.f,
        const float y = 0.f,
        const float z = 0.f) noexcept :
        x(x), y(y), z(z) {
    }

    constexpr Vector3 operator-(const Vector3& other) const noexcept
    {
        return Vector3{ x - other.x, y - other.y, z - other.z };
    }

    constexpr Vector3 operator+(const Vector3& other) const noexcept
    {
        return Vector3{ x + other.x, y + other.y, z + other.z };
    }

    constexpr Vector3 operator*(const float other) const noexcept
    {
        return Vector3{ x * other, y * other, z * other };
    }

    constexpr Vector3 operator/(const float other) const noexcept
    {
        return Vector3{ x / other, y / other, z / other };
    }

    Vector3 WorldToScreen(const view_matrix_t& matrix) const
    {
        
        float _x = matrix.matrix[0][0] * x + matrix.matrix[0][1] * y + matrix.matrix[0][2] * z + matrix.matrix[0][3];
        float _y = matrix.matrix[1][0] * x + matrix.matrix[1][1] * y + matrix.matrix[1][2] * z + matrix.matrix[1][3];
        float _w = matrix.matrix[3][0] * x + matrix.matrix[3][1] * y + matrix.matrix[3][2] * z + matrix.matrix[3][3];

        if (_w < 0.01f)
            return false;

        float invw = 1.0f / _w;
        _x *= invw;
        _y *= invw;

        float x = screen_width * 0.5f;
        float y = screen_height * 0.5f;

        x += 0.5f * _x * screen_width + 0.5f;
        y -= 0.5f * _y * screen_height + 0.5f;

        return Vector3{ x, y, _w};
    }

    float x, y, z;
};

struct Vector2
{
    float x, y;

    constexpr Vector2(
        const float x = 0.f,
        const float y = 0.f) noexcept :
        x(x), y(y) {
    }

    constexpr Vector2 operator-(const Vector2& other) const noexcept
    {
        return Vector2{ x - other.x, y - other.y };
    }

    constexpr Vector2 operator+(const Vector2& other) const noexcept
    {
        return Vector2{ x + other.x, y + other.y };
    }

    constexpr Vector2 operator*(const float other) const noexcept
    {
        return Vector2{ x * other, y * other };
    }

    constexpr Vector2 operator/(const float other) const noexcept
    {
        return Vector2{ x / other, y / other };
    }
};
