# CollatzConjecture

This repository contains a couple of tools to help prove the Collatz conjecture.

Algorithms in this repository were used to obtain results in:

Schwob M.R., Shiue P., Venkat R., (2021). "Novel Theorems and Algorithms Relating to the Collatz Conjecture." _International Journal of Mathematics and Mathematical Science_, 5754439.

## Description of Each File

### visualize.cpp

This file generates an inverse binary tree for the Collatz conjecture in the console. This customizable, interactive interface can be used to efficiently navigate through Collatz sequences.

### iterations.cpp

This file obtains the number of iterations until each positive, odd integer reaches 1, reaches a value less than itself, and its representation in bases 2-4.

### peaks.cpp

This file obtains the highest integer in the Collatz sequence for every odd integer up to some given number. It also provides each odd integer's number of iterations until 1 is reached.

### base4.cpp

This file returns the Collatz sequence starting with a given natural number, iteration by iteration in bases 4 and 10.

## Licensing

This repository is licensed under GNU GPLv3.
