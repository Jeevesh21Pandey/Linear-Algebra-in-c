# Linear-Algebra-in-c
This repository contains a collection of C functions and utilities for performing fundamental linear algebra operations. Designed for performance and simplicity, this library aims to provide a lightweight yet robust toolkit for applications in scientific computing, engineering, data analysis, and more.

## Contents

1. **Inverse of a Matrix**
2. **Solving a System of Equations**
3. **Finding the Root of a Polynomial**
4. **Gram-Schmidt Orthogonalization**

---

## 1. Inverse of a Matrix

**Description:**  
The inverse of a square matrix A is another matrix A⁻¹ such that AA⁻¹ = A⁻¹A = I, where I is the identity matrix. Not all matrices have inverses; a matrix must be square and have a non-zero determinant.

**Mathematics:**  
For a matrix A:

$A^{-1} = \frac{1}{\det(A)} \text{adj}(A)$

where adj(A) is the adjugate of A.

---

## 2. Solving a System of Equations

**Description:**  
A system of linear equations can be represented as AX = B, where A is a matrix of coefficients, X is a column vector of variables, and B is a column vector of constants. The solution involves finding X.

**Mathematics:**  
If A is invertible:

$X = A^{-1}B$

---

## 3. Finding the Root of a Polynomial

**Description:**  
Finding the root of a polynomial means determining the value(s) of x for which P(x) = 0, where P(x) is a polynomial function.

**Mathematics:**  
For a polynomial:

$P(x) = a_nx^n + a_{n-1}x^{n-1} + \cdots + a_0$

find x such that P(x) = 0.  
Numerical methods like the Newton-Raphson method are often used:

$x_{n+1} = x_n - \frac{P(x_n)}{P'(x_n)}$

---

## 4. Gram-Schmidt Orthogonalization

**Description:**  
The Gram-Schmidt process takes a set of linearly independent vectors and generates an orthogonal (or orthonormal) set spanning the same subspace.

**Mathematics:**  
Given vectors v₁, v₂, ..., vₙ, construct orthogonal vectors u₁, u₂, ..., uₙ:

$u_1 = v_1$

$u_k = v_k - \sum_{j=1}^{k-1} \frac{\langle v_k, u_j \rangle}{\langle u_j, u_j \rangle} u_j$

where ⟨·,·⟩ denotes the inner product.

---

## Usage

Each program is self-contained and can be compiled using a C compiler such as `gcc`. Refer to the individual source files for usage instructions and examples.
