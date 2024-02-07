---
sidebar_position: 0
---

# Introduction

## Installation​

To install the entire @tsei/star lib:

```bash
npm i @tsei/star
```

or

```bash
yarn add @tsei/star
```

## Getting Started

Run the development server:

```
git clone https://github.com/tseijp/star
cd star
yarn start
```

Your site starts at [http://localhost:3000](http://localhost:3000).

## Simple Example

```js
import STAR from '@tsei/star'

const vector = new STAR.Vector(0, 1, 0)
const lenght = vector.dot(vector)
```
