---
sidebar_position: 3
---

# Quater

## Code Example

```cpp
::STAR::Quater a( 0, 1, 0, 0 );

::STAR::Quater b(); // will be initialised to( 0, 0, 0, 0 )

::STAR::Quater c = a + b;
```

## Constructor

```cpp
Quater quater(Scalar x, Scalar y, Scalar z)

Quater quater(Quater q)
```

- x - the x value of this quater. Default is __0__
- y - the y value of this quater. Default is __0__
- z - the z value of this quater. Default is __0__
- w - the w value of this quater. Default is __0__

## Methods

### Basic Properties Methods

__Basic Operations__

| Properties | Description |
| ---------- | ----------- |
| `.[0]: Scalar` | Returns a the value `x` of this quater. |
| `.[1]: Scalar` | Returns a the value `y` of this quater. |
| `.[2]: Scalar` | Returns a the value `z` of this quater. |
| `.[3]: Scalar` | Returns a the value `w` of this quater. |


__Basic Getter Methods__

| Properties | Description |
| ---------- | ----------- |
| `.x(): Scalar` | Returns a the value `x` of this quater. |
| `.y(): Scalar` | Returns a the value `x` of this quater. |
| `.z(): Scalar` | Returns a the value `x` of this quater. |
| `.w(): Scalar` | Returns a the value `w` of this quater. |
| `.print(): void` | |

__Basic Setter Methods__

| Properties | Description |
| ---------- | ----------- |
| `.set(Scalar s): this` | Copies the value to this Quater `x, y, z, w`. |
| `.set(Quater q): this` | Copies the values of `x, y, z, w` to this Quater. |
| `.setX(Scalar s): this` | Copies the value of `x` to this Quater. |
| `.setY(Scalar s): this` | Copies the value of `y` to this Quater. |
| `.setZ(Scalar s): this` | Copies the value of `z` to this Quater. |
| `.setW(Scalar s): this` | Copies the value of `w` to this Quater. |

### Basic Math Methods

__Basic Operations__

| Properties | Description |
| ---------- | ----------- |
| `+(): Quater` | |
| `-(): Quater` | |
| `+(Scalar s): Quater` | |
| `-(Scalar s): Quater` | |
| `*(Scalar s): Quater` | |
| `/(Scalar s): Quater` | |
| `+(Quater q): Quater` | Calculates the add product of this quater and q. |
| `-(Quater q): Quater` | Calculates the sub product of this quater and q. |

__Basic Calculations__

| Properties | Description |
| ---------- | ----------- |
| `.dot(Quater q): Scalar` | Calculates the dot product of this quater and q.|
| `.length(): Scalar` | Calculates the Euclidean length from(0, 0) to(x, y, z). |
