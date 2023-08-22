#include <stdio.h>
#include <stdlib.h>


/// An enumeration for the different nodes
typedef enum TypeTag {
    CONSTANT,
    ADD,    /// Add operation
    SUB,    /// Subtract operation
    MUL,    /// Multiplication operation
    DIV,    /// Division operation
    FIBO    /// Fibbonaci operation
} TypeTag;

typedef struct Node {
    TypeTag type;
    union {
        int constant;
        struct Node *left;
        struct {
            struct Node *left;
            struct Node *right;
        } binary_op;
    } data;
} Node;



Node *makeConstant(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = CONSTANT;
    node->data.constant = value;
    return node;
}

Node *makeBinaryOp(TypeTag type, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node)); /// Memory allocation
    node->type = type;
    node->data.binary_op.left = left;
    node->data.binary_op.right = right;
    return node;
}
/// A function used to calculate the result of the expression represented by the given node
int calc(Node *node) {
    if (node->type == CONSTANT) {
             /// If the node represents a constant, return its value
        return node->data.constant;
    } else if (node->type == ADD) {
        /// If the node represents an addition operation,
        /// recursively calculate the left and right operands
        return calc(node->data.binary_op.left) + calc(node->data.binary_op.right);
    } else if (node->type == SUB) {
       /// If the node represents a subtraction operation,
        /// recursively calculate the left and right operands
        return calc(node->data.binary_op.left) - calc(node->data.binary_op.right);
    } else if (node->type == MUL) {
        /// If the node represents a multiplication operation,
        /// recursively calculate the left and right operands
        return calc(node->data.binary_op.left) * calc(node->data.binary_op.right);
    } else if (node->type == DIV) {
        /// If the node represents a division operation,
        /// recursively calculate the left and right operands
        return calc(node->data.binary_op.left) / calc(node->data.binary_op.right);
    } else if (node->type == FIBO) {
        /// If the node represents a Fibonacci calculation operation,
        /// calculate the nth Fibonacci number using dynamic programming
        int n = calc(node->data.binary_op.left);
        int fib[n + 1];
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib[n]; /// Return the fibo final answer
    }
    return 0; // Handle other cases or errors here
}

int main() {
    Node *add = makeBinaryOp(ADD, makeConstant(10), makeConstant(6));
    Node *mul = makeBinaryOp(MUL, makeConstant(5), makeConstant(4));
    Node *sub = makeBinaryOp(SUB, add, mul);
    Node *fibo = makeBinaryOp(FIBO, makeConstant(3), makeConstant(0)); /// FIBO takes a number, not NULL

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    /// Memory de allocation
    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
