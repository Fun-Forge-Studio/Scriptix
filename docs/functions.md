# Functions Documentation

This documentation provides a detailed description of the various functions used in the project.

## Function: `filter_even_numbers`

### Description
`filter_even_numbers` takes a list of integers and returns a new list containing only the even numbers from the original list.

### Parameters
- `numbers` (list of `int`): A list of integers to be filtered.

### Returns
- `list of int`: A new list containing only the even numbers from the input list.

### Raises
- `TypeError`: If the input is not a list or if the list contains non-integer values.

### Examples

#### Example 1: Filter even numbers from a mixed list
```python
result = filter_even_numbers([1, 2, 3, 4, 5, 6])
print(result)  # Output: [2, 4, 6]


