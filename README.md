# Shopping List Manager 🛒

This C++ project is a **Shopping List Manager**, designed to help users create, manage, and organize shopping lists. The system allows users to add items to the list, categorize them, track their quantity, and mark them as purchased.

## Features

### 1. **Item Management**
   - **Add Items**: Users can add items to their shopping list by specifying the name, category, and quantity. If the quantity provided is negative, an error is thrown.
   - **Edit Quantity**: Modify the quantity of an item in the list. If the new quantity is negative, an exception will be raised.
   - **Mark as Bought**: Items can be marked as "bought" to track which items have already been purchased.

### 2. **Categories**
   Each item is associated with a category (e.g., groceries, electronics). This helps in organizing the list and makes it easy to filter items based on their type.

### 3. **Error Handling**
   The system implements error handling to ensure that users cannot enter invalid data (e.g., negative quantities for items).
