---
sidebar_position: 1
---

# Vector

## Code Example

```cpp
::STAR::Vector a( 0, 1, 0 );

::STAR::Vector b(); // will be initialised to( 0, 0, 0 )

::STAR::Vector c = a + b;
```

## Constructor

```cpp
Vector vector(Scalar x, Scalar y, Scalar z)

Vector vector(Vector v)
```

- x - the x value of this vector. Default is __0__
- y - the y value of this vector. Default is __0__
- z - the z value of this vector. Default is __0__

## Methods

### Basic Properties Methods

__Basic Operations__

| Properties | Description |
| ---------- | ----------- |
| `.[0]: Scalar` | Returns a the value `x` of this vector. |
| `.[1]: Scalar` | Returns a the value `y` of this vector. |
| `.[2]: Scalar` | Returns a the value `z` of this vector. |


__Basic Getter Methods__

| Properties | Description |
| ---------- | ----------- |
| `.x(): Scalar` | Returns a the value `x` of this vector. |
| `.y(): Scalar` | Returns a the value `x` of this vector. |
| `.z(): Scalar` | Returns a the value `x` of this vector. |
| `.print(): void` | |

__Basic Setter Methods__

| Properties | Description |
| ---------- | ----------- |
| `.set(Scalar s): this` | Copies the value to this Vector `x, y, z`. |
| `.set(Vector v): this` | Copies the values of `x, y, z` to this Vector. |
| `.setX(Scalar s): this` | Copies the value of `x` to this Vector. |
| `.setY(Scalar s): this` | Copies the value of `y` to this Vector. |
| `.setZ(Scalar s): this` | Copies the value of `z` to this Vector. |

### Basic Math Methods

__Basic Operations__

| Properties | Description |
| ---------- | ----------- |
| `+(): Vector` | |
| `-(): Vector` | |
| `+(Scalar s): Vector` | |
| `-(Scalar s): Vector` | |
| `*(Scalar s): Vector` | |
| `/(Scalar s): Vector` | |
| `+(Vector v): Vector` | Calculates the add product of this vector and v. |
| `-(Vector v): Vector` | Calculates the sub product of this vector and v. |
| `*(Vector v): Vector` | Calculates the cross product of this vector and v. |

__Basic Calculations__

| Properties | Description |
| ---------- | ----------- |
| `.dot(Vector v): Scalar` | Calculates the dot product of this vector and v.|
| `.length(): Scalar` | Calculates the Euclidean length from(0, 0) to(x, y, z). |
| `.triple(): Scalar` | Calculates the triple product of this vector and v. |
| `.cross(Vector v1, Vector v2): Vector` | Calculates the cross product of this vector, v1 and v2. |
| `.clone(): Vector` | Returns a new Vector with the same x and y values as this one.|

<!--
| `.size(): Scalar` | |
| `.max( Vector v ): this` | Replace that value with the corresponding max value.|
| `.min( Vector v ): this` | Replace that value with the corresponding min value.|
| `.angle( Vector v ): Scalar` | Returns the angle between this vector and vector v in radians.|
| `.project( v : Vector ) : this` | Projects this vector onto v.|
| `.reflect( v : Vector ) : this` |normal - the normal to the reflecting plane|
| `.distance( Vector v ): Scalar`| Computes the distance from this vector to v.|
| `.ceil(): this` | The x and y components of this vector are rounded up to the nearest integer value.|
| `.floor(): this` | The components of this vector are rounded down to the nearest integer value.|
| `.normalize(): this` | Converts this vector to a unit vector.|
| `.round(): this` | The components of this vector are rounded to the nearest integer value.|
| `.random(): this` | Sets each component of this vector to a pseudo-random value between 0 and 1, excluding 1.
-->
