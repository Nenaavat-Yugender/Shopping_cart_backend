# Shopping Cart Backend

A **command-line based app** (not a UI) to learn interactions between different classes and objects.

## Concepts Used
- **Data Structures**
- **OOP (Object-Oriented Programming)**
- **Creating different entities**

### Cart Structure
- A **cart** contains multiple **items**.
- Each **item** has a **quantity** and is linked to a **product**.

## Features
1. **View Products** – Allows users to see available products.
2. **Add Products & Check Quantity** – Users can add products to the cart and verify quantity.
3. **Checkout & View Total** – Displays the total amount to be paid.

## Entities
### Product
Each product has:
- **ID**
- **Name**
- **Price**

### Item
Each item has:
- **Product**
- **Quantity**
- **Price**

### Cart
Each cart has:
- **Items**
- **Total Price**

## Entity Relationships
```
                             |--> ID            Cart = Collection of Items
   --|       -|--> Product-->|--> Name          Product = Things we buy from the shop (e.g., Apple, Banana, Watermelon...)
Cart |--> Items|--> Quantity |--> Price         Item = Represents a product and its quantity.
   --|       -|
```

## Compilation & Execution
### 1. Compilation Command
```sh
g++ cart_main.cpp -o main.exe
```
**Explanation:**
- `g++` → GNU C++ Compiler
- `cart_main.cpp` → C++ source file
- `-o main.exe` → Generates an executable file `main.exe`

### 2. Running the Executable
```sh
./main.exe
```
**Explanation:**
- `./` → Runs the program from the current directory
- `main.exe` → Executable file

---
# Shopping Cart Backend