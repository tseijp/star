---
sidebar_position: 2
---

# Matrix

## Code Example

```cpp
::STAR::Matrix a( 0, 1, 0 );

::STAR::Matrix b(); // will be initialised to( 0 )

::STAR::Matrix c = a + b;
```

## Constructor

```cpp
Matix matrix(
 Scalar xx, Scalar xy, Scalar xz,
 Scalar yx, Scalar yy, Scalar yz,
 Scalar zx, Scalar zy, Scalar zz
)

Matrix matrix(Vector x, Vector y, Vector z)

Matrix matrix(Matrix m)
```

- x - the x vector of this matrix. Default is __Vector(0, 0, 0)__
- y - the y vector of this matrix. Default is __Vector(0, 0, 0)__
- z - the z vector of this matrix. Default is __Vector(0, 0, 0)__

## Methods

### Basic Properties Methods

__Basic Operations__

| Properties | Description |
| ---------- | ----------- |
| `.[0]: Vector` | Returns the vector `x` of this matrix. |
| `.[1]: Vector` | Returns the vector `y` of this matrix. |
| `.[2]: Vector` | Returns the vector `z` of this matrix. |

__Basic Getter Methods__

| Properties | Description |
| ---------- | ----------- |
| `.x(): Scalar` | Returns the value `x` of this matrix. |
| `.y(): Scalar` | Returns the value `y` of this matrix. |
| `.z(): Scalar` | Returns the value `z` of this matrix. |
| `.print(): void` | |

__Basic Setter Methods__

| Properties | Description |
| ---------- | ----------- |
| `.set(Scalar s): this` | Copies the value to this Matrix `x, y, z`. |
| `.set(Matrix m): this` | Copies the values `x, y, z` of to this Matrix. |
| `.set_rotation_x(Scalar s): this` | Copies $\begin{bmatrix} 1 & 0 & 0 \\ 0 & \cos \theta & -\sin \theta \\ 0 & \sin \theta & \cos \theta \end{bmatrix}$ |
| `.set_rotation_y(Scalar s): this` | Copies $\begin{bmatrix} \cos \theta & 0 & \sin \theta \\ 0 & 1 & 0 \\ -\sin \theta & 0 & \cos \theta \end{bmatrix}$ |
| `.set_rotation_z(Scalar s): this` | Copies $\begin{bmatrix} \cos \theta & -\sin \theta & 0 \\ \sin \theta & \cos \theta & 0 \\ 0 & 0 & 1 \end{bmatrix}$ |

### Basic Math Methods

__Basic Operations__

| Properties | Description |
| ---------- | ----------- |
| `+(): Matrix` | |
| `-(): Matrix` | |
| `+(Scalar s): Matrix` | |
| `-(Scalar s): Matrix` | |
| `*(Scalar s): Matrix` | |
| `/(Scalar s): Matrix` | |
| `+(Matrix m): Matrix` | Calculates the dot add product of this matrix and v. |
| `-(Matrix m): Matrix` | Calculates the dot sub product of this matrix and v. |
| `*(Matrix m): Matrix` | Calculates the cross product of this matrix and v. |
| `*(Vector v): Vector` | Calculates the cross product of this matrix and v. |

__Basic Calculations__

| Properties | Description |
| ---------- | ----------- |
| `.tdotx( Vector v ): Vector` | Calculates the dot product of this matrix x and v.|
| `.tdoty( Vector v ): Vector` | Calculates the dot product of this matrix y and v.|
| `.tdotz( Vector v ): Vector` | Calculates the dot product of this matrix z and v.|
