---
sidebar_position: 0
---

# Scalar

## Code Example

```cpp
::STAR::Scalar a( 1 );

::STAR::Scalar b(); // will be initialised to( 0 )

::STAR::Scalar c = a + b;
```

## Constructor

```cpp
Scalar scalar(double s)
```

## Methods

### Basic Properties Methods

__Basic Operations__

| Properties | Description |
| ---------- | ----------- |
| `.(): Scalar` | Returns a the value `x` of this scalar. |

__Basic Getter Methods__

| Properties | Description |
| ---------- | ----------- |
| `.print(): void` | |

__Basic Setter Methods__

| Properties | Description |
| ---------- | ----------- |
| `.set(Scalar s): this` | Copies the value to this Scalar. |

### Basic Math Methods

__Basic Operations__

| Properties | Description |
| ---------- | ----------- |
| `+()` | |
| `-()` | |
| `+(Scalar s)` | |
| `-(Scalar s)` | |
| `*(Scalar s)` | |
| `/(Scalar s)` | |

__Basic Calculations__

| Properties | Description |
| ---------- | ----------- |
| .sin(Scalar s): Scalar |  |
| .cos(Scalar s): Scalar |  |
| .one(Scalar s): Scalar |  |
| .zero(): Scalar |  |
