# Polynomial Coefficient Generator (C with GMP)

This project computes the coefficients of a polynomial given its roots using the **GNU Multiple Precision Arithmetic Library (GMP)** for handling large numbers.

---

## Features
- Handles large integers using GMP.
- Supports roots provided in different bases (e.g., binary, decimal, base-4).
- Dynamically builds polynomial coefficients using iterative multiplication.

---

## Code Overview
- **`multiplyPoly`** – Updates polynomial coefficients when a new root is added.
- **`main`** – Initializes roots, converts them to decimal using their respective bases, and prints the resulting polynomial coefficients.

---

## Example Input
```c
int n = 4, k = 3;

char bases[4][4] = {"10", "2", "10", "4"};
char values[4][MAXLEN] = {"4", "111", "12", "213"};